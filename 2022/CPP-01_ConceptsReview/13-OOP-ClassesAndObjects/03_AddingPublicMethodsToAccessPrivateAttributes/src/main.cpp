#include <iostream>
#include <string>

#include "Dog.h"

int main() {
    Dog dog; 
    
    dog.set_name("Sport");
    std::cout<<dog.get_name()<<std::endl;

    std::cout<<dog.get_human_years()<<std::endl;
    std::cout<<dog.speak()<<std::endl;
    
    return 0;
}