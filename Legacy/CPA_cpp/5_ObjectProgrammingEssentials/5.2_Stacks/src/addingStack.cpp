#include <iostream>
#include "addingStack.h"

AddingStack::AddingStack():Stack(){ // Aqui também inicializamos a 'parent class' Stack()
  sum = 0;
}
AddingStack::~AddingStack(){ // Apenas construtures utilizam inicialização de membros
}

void AddingStack::push(int val){
  sum += val;
  Stack::push(val);
}

int AddingStack::pop(){
  int val = Stack::pop();
  sum -= val;
  return val;
}

int AddingStack::getSum(){
  return sum;
}
