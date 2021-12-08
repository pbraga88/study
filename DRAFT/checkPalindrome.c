#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkPalindrome(char * inputString) {
   //  size_t stringSize = sizeof(inputString)/sizeof(inputString[0]);
   size_t stringSize = strlen(inputString);

    printf("%s\n", inputString);
    printf("string size: %ld\n", stringSize);
    int j = 0;
    char inverseString[stringSize];
    for (int i = stringSize; i>=0; i--) {
        inverseString[j] = inputString[i-1];
        j++;
    }
    printf("input String: %s\n", inputString);
    printf("inverse String: %s\n", inverseString);
    
    printf("strcmp: %d\n", strcmp(inputString, inverseString));
    return (strcmp(inputString, inverseString) != 0) ? false : true;
   // return true;
}


int main() {
   char *word = "aaba";
   printf("%d\n", checkPalindrome(word));

   return 0;
}