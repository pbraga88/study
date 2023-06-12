// #include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A function which returns greater value
// template <typename T>
// T get_max(T a, T b) {
//     return a>b ? a : b;
// }

// sentence = "reverse this sentence";
// void inverse_phrase(char *sentence, char *buffer) {
//     char reversed_sentence [strlen(sentence)];
//     size_t size = strlen(sentence);

//     printf("debug: inverse_phrase\n");

//     for(int i = size; i >= 0; i--) {
//         printf("debug: for loop\n");
//         if (sentence[i-1] == ' ' || i == 0) {
//             printf("debug: if condition\n size - i = %d\n", size-i);
//             strncpy(reversed_sentence + strlen(reversed_sentence) , sentence + i, size-i);
//             reversed_sentence[(size-i) + 1] = ' ';
//             reversed_sentence[(size-i) + 2] = '\0';
//             printf("%s\n", reversed_sentence);
//             // break;
//         }
//     }

//     printf("debug: copy to buffer\n");
//     strncpy(buffer, reversed_sentence, strlen(reversed_sentence));
// }


// int main() {
//     char *sentence = "reverse this sentence";
//     char *buffer = (char*)malloc(strlen(sentence));
//     inverse_phrase(sentence, buffer);
//     printf("%s\n", buffer);

//     free(buffer);
//     return 0;
// }
/***********************************************************************/

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *list_top = NULL;

Node* create_node(char *word) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->word = word;
    node->next = NULL;
    return node;
}

void push_to_list(char *word /*Node* node, Node* list_top*/) {
    Node *node = create_node(word);
    node->next = list_top;
    list_top = node;
}

void pop_from_list(char* buffer) {
    if (list_top == NULL) {
        buffer[0] = '\0';
    }
    else {
        Node* aux = list_top;
        memcpy(buffer, list_top->word, strlen(list_top->word));
        list_top = list_top->next;
        free(aux);
        aux = NULL;
    }
}

void traverse_list() {
    Node* aux = list_top;
    while (aux != NULL)
    {
        printf("%s ", aux->word);
        aux = aux->next;
    }
    printf("\n");
}

void reverse_sentence(char* sentence) {
    // printf("debug: inverse_phrase\n");
    char* copied_sentence = strdup(sentence);
    char* token = strtok(copied_sentence, " ");
    // printf("debug: tokenized\n");
    while(token != NULL) {
        // printf("debug: while loop\n");
        printf("%s\n", token);
        push_to_list(token);
        token = strtok(NULL, " ");
    }
    
    char buffer[64];
    do {
        memset(buffer, 0, 64);
        pop_from_list(buffer);
        printf("%s ", buffer);
    } while (buffer[0] != '\0');
    printf("\n");
}


int main() {
    char *sentence = "string to be reversed";
    reverse_sentence(sentence);
    // traverse_list();

    return 0;
}