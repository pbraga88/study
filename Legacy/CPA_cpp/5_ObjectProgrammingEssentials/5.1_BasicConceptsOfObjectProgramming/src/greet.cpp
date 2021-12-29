#include <iostream>
#include "greet.h"

Greeting::Greeting(){
}

Greeting::Greeting(std::string nome){
  name = nome;
}

void Greeting::SetName(std::string nome){
  name = nome;
}

void Greeting::Greet(){
  std::cout<<"Hello again, "<<name<<"!"<<std::endl;
}

Greeting::~Greeting(){
}
