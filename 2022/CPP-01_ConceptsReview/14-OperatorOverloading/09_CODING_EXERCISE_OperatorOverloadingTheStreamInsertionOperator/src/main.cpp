#include <iostream>
#include <vector>
#include "Money.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Money amount(1,70);
    std::cout<<amount;

    return 0;
}