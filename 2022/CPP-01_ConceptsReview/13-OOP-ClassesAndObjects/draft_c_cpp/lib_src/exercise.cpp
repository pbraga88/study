#include <iostream>
#include <string>
#include <cstring>

#include "Dog.h"
#include "exercise.h"

Dog test_dog() {
//---- WRITE YOUR CODE BELOW THIS LINE----


    Dog spot;
    spot.name = "Spot";
    spot.age = 5;

//---- WRITE YOUR CODE ABOVE THIS LINE----
//---- DO NOT CHANGE THE CODE BELOW----
    return spot;
}

char *return_string() {
    Dog dog = test_dog();    
    
    char dog_name[dog.name.length() + 1];
    strcpy(dog_name, dog.name.c_str());

    return &dog.name[0];
 
}