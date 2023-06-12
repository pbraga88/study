#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <stdatomic.h>

#define MAX_NUMBERS 10
#define MAX_BUFFER 256

// Define a node in the queue
typedef struct Node {
    char *value;
    struct Node *next;
} Node;

// Define the queue
typedef struct Queue {
    Node *front;
    Node *rear;
    pthread_mutex_t lock;
} Queue;

static Queue* queue;
// static volatile int stop_printing = 0;  // Global variable to stop the printing thread
atomic_int stop_printing = 0; // Single, unbreakable unit with respect to other threads. Prevent race conditions

// Function to create a new node
Node *newNode(char *value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

// Function to create and empty queue
Queue *createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    pthread_mutex_init(&queue->lock, NULL);
    return queue;
}

// Function to add a value to the rear of the queue
void enqueue(Queue *queue, char *value) {
    Node *node = newNode(value);
    pthread_mutex_lock(&queue->lock);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    pthread_mutex_unlock(&queue->lock);
}

// Function to remove a value from the front of the queue
char * dequeue(Queue *queue) {
    pthread_mutex_lock(&queue->lock);
    if (queue->front == NULL) {
        pthread_mutex_unlock(&queue->lock);
        return NULL;
    }
    Node *node = queue->front;
    char *value = strdup(node->value);
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    pthread_mutex_unlock(&queue->lock);
    free(node->value);
    free(node);
    return value;
}

// TODO: Define a thread-safe queue and implement functions to push and pop elements
void *request_factorization(void *arg) {
    printf("request factorization\n");
    char* server_ip = "127.0.0.1"; //TODO: get from command line or use a default value
    int server_port =  1234; //TODO: get from command line or use a default value
    int num = *(int*)arg;

    struct sockaddr_in server_addr;
    // struct hostent* server;
    
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Create the network socket

    // server = gethostbyname(server_ip);
    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // Adress type
    // bcopy((char*)server->h_addr_list, (char*)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(server_port);
	server_addr.sin_addr.s_addr = INADDR_ANY; // Ip Address. INADDR_ANY connects to local network
											  // It will resolve any IP address on the local machine

    int connection_status = connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
	// Check for errors
	if (connection_status == -1) {
		printf("connection_status = %d\n", connection_status);
		printf("Fail to connect\n");
	}
    printf("Connection stablished\n");

    char buffer[MAX_BUFFER];
    sprintf(buffer, "%d", num);
    write(sock, buffer, strlen(buffer));

    bzero(buffer, MAX_BUFFER);
    recv(sock, &buffer, MAX_BUFFER-1, 0);

    // printf("%s\n", buffer);
    // TODO: push the result into the queue
    enqueue(queue, buffer);

    close(sock);
    return NULL;
}

void *print_results(/*void *arg*/) {
    while (!atomic_load(&stop_printing)) {
        // TODO: pop a result from the queue and print it
        char* result = dequeue(queue);
        if (result != NULL) {
            printf("[DEBUG] print result\n");
            printf("%s\n", result);
            free(result);  // Don't forget to free the duplicated string
        }
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    char* server_ip = "127.0.0.1";  // default values
    int server_port = 1234;
    int nums[MAX_NUMBERS];
    int num_count = 0;

    // Initialize the queue
    queue = createQueue();

    int opt;
    while ((opt = getopt(argc, argv, "i:p:n:")) != -1) {
        switch (opt) {
        case 'i':
            server_ip = optarg;
            break;
        case 'p':
            server_port = atoi(optarg);
            break;
        case 'n': {
                // Assuming numbers are separated by commas with no spaces
                char* token = strtok(optarg, ",");
                while (token != NULL && num_count < MAX_NUMBERS) {
                    nums[num_count++] = atoi(token);
                    token = strtok(NULL, ",");
                }
                break;
            }
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-i ip] [-p port] [-n numbers]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    pthread_t threads[MAX_NUMBERS+1];
    
    // printf("Create thread\n");
    // Create a thread for each number to factorize 
    for (int i = 0; i < num_count; i++) {
        pthread_create(&threads[i], NULL, request_factorization, &nums[i]);
    }
    
    // Create a thread to print the results
    pthread_create(&threads[num_count], NULL, print_results, NULL);

    // printf("Join thread\n");
    for (int i = 0; i < num_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Indicate that the print_results thread should stop
    // stop_printing = 1;
    atomic_store(&stop_printing, 1);

    
    pthread_join(threads[num_count], NULL);

    return 0;
}