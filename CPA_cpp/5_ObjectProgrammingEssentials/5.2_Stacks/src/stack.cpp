#include <iostream>
#include "stack.h"

Stack::Stack(void){
  SP = 0;
}

Stack::~Stack(){
}

void Stack::push(int val){
  stackstore[SP++] = val;
}

int Stack::pop(void){
  return stackstore[--SP];
}
