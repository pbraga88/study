#include <iostream>

int factorial_recursive(int nb) {
    return (nb-1 > 0) ? (nb * factorial_recursive(nb-1)) : 1;
}

int factorial_iterative(int nb) {
    for (int i = nb-1; i; i--) {
        nb *= i;
    }
    return nb;
}

int main() {
    std::cout<<factorial_recursive(10)<<std::endl;
    std::cout<<factorial_iterative(10)<<std::endl;

    return 0;
}