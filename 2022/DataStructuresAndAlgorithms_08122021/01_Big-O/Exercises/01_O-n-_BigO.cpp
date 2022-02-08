#include <iostream>
#include <string>

using namespace std;

/* What is the Big O of funChallenge() function? (Hint, you may want to go line by line)
Minha resposta: O(n)
Solução: O(n)
*/

void anotherFunction() {
    cout<<"fake function"<<endl;
}

int funChallenge(string input) {
  int a = 10; // O(1)
  a = 50 + 3; // O(1)
  

  for (int i = 0; i < input.length(); i++) { // O(n)
    anotherFunction(); // O(n)
    bool stranger = true; // O(n)
    a++; // O(n)
  }
  return a; // O(1)
}

int main() {
    string texto = "123456789";
    int a = 0;
    a = funChallenge(texto);

    printf("a=%d\n", a);

    return 0;
}