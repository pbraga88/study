#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include "factorization.c"

#define MAX_CLIENTS 10
#define MAX_BUFFER 256
#define MAX_FACTORS 16

void *handle_client(void *arg) {
    int client_sock = *(int*)arg;
    // int32_t number;
    int bytes_received;

    char buffer[MAX_BUFFER];
    while ((bytes_received = read(client_sock, buffer, MAX_BUFFER-1)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Received: %s\n", buffer);
        // TODO: call the factorize function from the shared library and send the result back
        int number;
        sscanf(buffer, "%d", &number);

        int factors[100];
        int count = 0;
        factorize(number, factors, &count);
        printf("[DEBUG] count: %d\n", count);
        for (int i = 0; i < count; i++) {
            printf("[DEBUG] factor[%d]: %d\n",i+1, factors[i]);
        }

        // Write the factors to the buffer
        int offset = 0;
        for (int i = 0; i < count; i++) {
            int n = snprintf(buffer + offset, MAX_BUFFER - offset, "%d ", factors[i]);
            offset += n;
        }

        int size = (count * sizeof(int))+1;
        printf("[DEBUG] send to client: %s\n", buffer);
        send(client_sock, buffer, size, 0);
    }

    close(client_sock);
    return NULL;
}

int main(int argc, char* argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    socklen_t client_len = sizeof(client_addr);
    // TODO: parse command line arguments to get the port number

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234); // TODO: Replace with the port number from the command line arguments

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Error on accept");
            exit(1);
        }
        printf("Connection received\n");

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client_sock);
        pthread_join(thread, NULL);
    }

    return 0;
}