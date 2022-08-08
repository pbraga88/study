#include <iostream>
#include "my_string.h"

int main(int argc, char **argv) {
    // (void)argc;
    Mystring str_a = argc==2 ? argv[1] : "default";
    str_a.display();
    std::cout<<"string: "<<str_a.get_str()<<std::endl;
    std::cout<<"length: "<<str_a.get_length()<<std::endl;


    return 0;
}