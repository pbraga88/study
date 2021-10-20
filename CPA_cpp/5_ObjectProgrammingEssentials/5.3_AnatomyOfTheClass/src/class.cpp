#include <iostream>
#include "class.h"

using namespace std;

Classe::Classe(void){
  value = -1;
}

Classe::Classe(int value){
  this->value = value;
}

// A keyword const é uma garantia de que os valores da função sendo copiada não
// serão alterados
Classe::Classe(Classe const& source){ // Aqui o construtor é copiado e a nova instancia
  value = source.value + 100;         // desse objeto diz que os seus valores das variáveis
  x = source.x + 1;                   // membro 'value' e 'x' são iguais aos valores da instância
}                                     // que está sendo copiada mais as adições específicas deste
                                      // construtor.

Classe::~Classe(void){
  if(mem){
    cout<<"deletion of allocated memory"<<endl;
    delete []mem;
  }
}

int Classe::getValue(void){
  return value;
}
void Classe::setValue(int value){
  this->value= value;
}

void Classe::mem_alloc(int memory){
  cout<<"mem_alloc("<<memory<<")"<<endl;
  mem = new int[memory];
}
