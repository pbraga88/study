#include <stdio.h>
#include <stdlib.h>

#include "Dog.h"
#include "exercise.h"

int main(void) {
    Dog spot = test_dog();
    std::cout<<"Dog name: "<<spot.name<<std::endl;
    std::cout<<"Dog age: "<<spot.age<<std::endl;

    return 0;
}