#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* What is the Big O of funChallenge() function? (Hint, you may want to go line by line)
Minha resposta: O(n)
Solução: O(n)
*/

void anotherFunction() {
    printf("fake function\n");
}

int funChallenge(char *input) {
  int a = 10; // O(1)
  a = 50 + 3; // O(1)

  for (int i = 0; i < strlen(input); i++) { // O(n)
    anotherFunction(); // O(n)
    bool stranger = true; // O(n)
    a++; // O(n)
  }
  return a; // O(1)
}

int main() {
    char *string = "123456789";
    int a = 0;
    a = funChallenge(string);

    printf("a=%d\n", a);

    return 0;
}