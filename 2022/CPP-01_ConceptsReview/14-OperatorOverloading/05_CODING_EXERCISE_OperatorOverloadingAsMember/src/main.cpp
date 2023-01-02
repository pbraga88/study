#include <iostream>
#include <vector>
#include "Money.h"

int main(int argc, char **argv) {
    (void)argc;
    // (void)argv;
    std::cout << std::boolalpha << std::endl; // Print true/false instead of 1/0
    
    Money my_money (std::stoi(argv[1]), 50);
    Money your_money (std::stoi(argv[2]), 50);
    std::cout<<(my_money==your_money)<<std::endl;
    std::cout<<(my_money!=your_money)<<std::endl;

    return 0;
}