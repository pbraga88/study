/* Ordered Linked-List
The scheduler in the application manages a doubly linked list of numerical (integer) element priorities that is dynamically created during the applications execution 
(Note; at initialization, the list is considered to be "empty" - there must be no pre-allocated entries...). 
The order of element priorities when being added to the linked list must start with the highest numerical priority first, working down to the lowest 
(at the end of the linked list).

• You must decide how element priorities being added in to the list are created and linked (remember, its a double-linked list we're after!)
To allow the scheduler to perform its job, an API is provided that allows a lower and upper priority to be extracted for any given "nominal priority"
(these are the values held either side of the "nominal priority"). A value of -1 will be returned for the upper / lower priority if there is no entry in the linked list.

Upon application termination, the linked list must be tidied up - all entries must be unlinked and destroyed with the list reverting back to an "empty" state.

An example of element priorities held in the doubly linked list is given as: 50-40-30-20-10
• The highest priority is 50.
• The lowest priority is 10.
• For a given "nominal priority" of 40, the lower/upper priorities are 30 and 50 respectively.
• For a given "nominal priority" of 10, the lower/upper priorities are -1 and 20 respectively (10 is already the lowest priority).

Input format
The input format that you must use to provide custom input (available above the Compile and Test buttons) is as follows:
• A line containing a single unsigned integer value defining the number of entries [N] in the linked list
• A line of [N] space-separated values, representing the element priority values
For example:
5
10 40 20 30 50

Output format
[N] lines, one for each priority in the linked list containing space separated values for the "nominal" priority, lower and upper priority limits
For example:
10 -1 20
40 30 50
20 10 30
30 20 40
50 40 -1

Sample input
5
10 40 20 30 50
Sample output
10 -1 20
40 30 50
20 10 30
30 20 40
50 40 -1
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

typedef struct Node {
    int priority;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

void add_to_list(int prio) {
    pthread_mutex_lock(&lock);
    Node* current = (Node*)malloc(sizeof(Node));
    if (current == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    current->next = NULL;
    current->prev = NULL;
    current->priority = prio;

    if (head == NULL || prio > head->priority ) {
        current->next = head;
        if (head != NULL) {
            head->prev = current;
        }        
        head = current;
    }
    else {
        Node *aux = head;
        while (aux->next != NULL && current->priority <= aux->next->priority ){
            aux = aux->next;
        }
        current->next = aux->next;
        if (aux->next != NULL) {
            aux->next->prev = current;
        }
        aux->next = current;
        current->prev = aux;
    }
    pthread_mutex_unlock(&lock);
}

void get_range_from_list(int nominal_priority, int* lower, int* upper) {
    pthread_mutex_lock(&lock);
    // Find the priority in the linked-list with support for same value priorities

    Node* current = head;
    
    while (nominal_priority != current->priority ||
        ((current->next != NULL) ? (current->next->priority == current->priority) : false)) {
        current = current->next;
    }

    Node* aux = current;
    while (aux->prev != NULL ? aux->prev->priority == aux->priority : false) {
        aux = aux->prev;
    }

    if (current != NULL && aux != NULL) {
        *lower = current->next == NULL ? -1 : current->next->priority;
        *upper = aux->prev == NULL ? -1 : aux->prev->priority;
    }
    else {
        *upper = -1;
        *lower = -1;
    }
    pthread_mutex_unlock(&lock);
}

void reset_list() {
    pthread_mutex_lock(&lock);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
        temp = NULL;
    }
    head = NULL;
    pthread_mutex_unlock(&lock);
}


/* for test only */
void parse_linked_list( ) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    int* Array = (int *)malloc(sizeof(int) * N);
    assert(Array);

    for (int i = 0; i < N; i++) {
        scanf("%d", &Array[i]);
        add_to_list(Array[i]);
    }

    /* For test only */
    parse_linked_list();

    int lower_prio = -1;
    int upper_prio = -1;
    for (int i = 0; i < N; i++) {
        get_range_from_list(Array[i], &lower_prio, &upper_prio);
        printf("%d %d %d\n", Array[i], lower_prio, upper_prio);
    }

    reset_list();
    free(Array);
    pthread_mutex_destroy(&lock);
    return 0;
}