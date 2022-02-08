// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
#include <iostream>
#include <string>

using namespace std;

/* What is the Big O of the below function? (Hint, you may want to go line by line)
Minha resposta: O(n)
Solução: O(n)
*/
void anotherFunChallenge(int input) {
  int a = 5; // O(1)
  int b = 10; // O(1)
  int c = 50; // O(1)
  for (int i = 0; i < input; i++) { // O(n)
    int x = i + 1; // O(n)
    int y = i + 2; // O(n)
    int z = i + 3; // O(n)
  }
  for (int j = 0; j < input; j++) { // O(n)
    int p = j * 2; // O(n)
    int q = j * 2; // O(n)
  }
  string whoAmI = "I don't know"; // O(1)
}

int main() {
    // char *string = "123456789";
    int input = 10;
    anotherFunChallenge(input);


    return 0;
}