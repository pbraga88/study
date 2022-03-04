/*
Given a corpus of text and a number k, write some code to find the top k terms in that text.
Example
text: b a b a a c
k: 2

Result: ["a", "b"] since a occurs 3 times, b 2 times.

contar as strings/char de entrada

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct array {
    int index;
    int soma;
    char string;
} array;

char* solution(char* a, int k) {
        int tam = strlen(a);
        int last = -1;
        char aux;
        array myArrayStruct[tam];
        for (int i = 0; i < sizeof(myArrayStruct); i++) {
            myArrayStruct[i].index = 0;
            myArrayStruct[i].soma = 0;
            myArrayStruct[i].string = 0;
        }
        
        /*for (int i = 0; i < tam; i++) {
            myArrayStruct[i].string = a[i]; // b3 b3 a2 a2 c1 b3
        }*/
        
        for (int i = 0; i < tam; i ++) {
            if(a[i] == ' ') {
                continue;
            }
            aux = a[i];
            bool achei = false;
            for(int j = 0; j < last; j++) {
                if(myArrayStruct[j].string == aux) {
                    achei = true;
                    myArrayStruct[j].soma += 1;
                }
            }
            
            if (!achei) {
                
            }
        }
        
        
        
        return a;
}


int main(void) {
//   printf("Hello, World!\n");
    char *palavra = "a b c";
    char *funcret = solution(palavra, 1);
  return 0;
  
}