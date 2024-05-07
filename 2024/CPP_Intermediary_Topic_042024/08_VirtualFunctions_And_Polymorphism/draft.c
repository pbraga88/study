#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list {
    char* word;
    struct list* next;
    struct list* previous;
} lista_linkada;

static lista_linkada *head = NULL;
static lista_linkada *tail = NULL;

lista_linkada *create_node(char* data) {
    lista_linkada *node = (lista_linkada*)malloc(sizeof(lista_linkada));
    node->word = data; 
    node->next = NULL;
    node->previous = NULL;

    return node;
}

void push(char* word) {
    printf("%s\n", word);
    lista_linkada *auxiliar = create_node(word); 
    if (head == NULL) {
        head = auxiliar;
        tail = head;
    }
    else {
        auxiliar->previous = head;
        auxiliar->next = NULL;
        head->next = auxiliar;
        head = auxiliar;
    }
}

void parse_list() {
    lista_linkada *aux = head;
    while (aux!=NULL) {
        printf("%s ", aux->word);
        aux = aux->previous;
    }
}

char* pop() {
    char *word;
    lista_linkada* aux = head;

    if(aux == NULL) {
        return NULL;
    }
    word = aux->word;

    head = head->previous;
    free(aux);

    return word;
}

int main() {
    char string[128] = "This is an example of string even longer than before";
    const char delim[2] = " ";
    char *token;

    struct list *d_linked_list;

    /* get the first token */
    token = strtok(string, delim);

    int counter = 0;
    while( token != NULL ) {
        // push into the doubly linked list
        push(token);

        // next calls to strtok will be with NULL as *str argument
        token = strtok(NULL, delim);
    }
    printf("\n");

    char* reversed;
    while ((reversed = pop()) != NULL) {
        printf("%s ", reversed);
    }
    
    printf("\n");
    
    return 0;
}