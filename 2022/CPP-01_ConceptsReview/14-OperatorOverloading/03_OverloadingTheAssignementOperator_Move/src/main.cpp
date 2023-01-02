#include <iostream>
#include <vector>
#include "my_string.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    
    Mystring a("Hello");
    a = Mystring("Hola");
    a = "Bonjour";

    return 0;
}