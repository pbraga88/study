#include <iostream>
#include <vector>
#include "Money.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    Money qty1(2,50);
    Money qty2(5,75);

    Money sum = qty1 + qty2;

    std::cout<<sum.get_dollars()<<std::endl;
    std::cout<<sum.get_cents()<<std::endl;

    return 0;
}