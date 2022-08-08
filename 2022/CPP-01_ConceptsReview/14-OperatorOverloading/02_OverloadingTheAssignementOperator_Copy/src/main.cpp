#include <iostream>
#include "my_string.h"

int main(int argc, char **argv) {
    // (void)argc;
    const char *input_string = argc==2 ? argv[1] : "default";
    Mystring str_a = input_string; // Overloaded constructor
    Mystring b;                    // no-args constructor
    b = str_a;                     // copy assignment: b.operator=(a)
    
    b = "This is a test";          //b.operator=("This is a test")
    
    
    
    str_a.display();
    // std::cout<<"string: "<<str_a.get_str()<<std::endl;
    // std::cout<<"length: "<<str_a.get_length()<<std::endl;


    return 0;
}