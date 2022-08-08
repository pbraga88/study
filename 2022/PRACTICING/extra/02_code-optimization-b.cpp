#include <iostream>
#include <chrono>
#include <math.h>

void func1() {
    int y = 0;
    double x[4] {1.0, 2.0, 3.0, 4.0};
    for (int j = 0; j < sizeof(x)/sizeof(x[0]); j++)
        x[j] *= M_PI * cos(y);
}

void func2() {
    int y = 0;
    double const_value = M_PI * cos(y);
    double x[4] {1.0, 2.0, 3.0, 4.0};

    for (int j = 0; j < sizeof(x)/sizeof(x[0]); j++)
        x[j] *= const_value;

}

int main() {

    auto start = std::chrono::high_resolution_clock::now();
    func2();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<duration.count()<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    func1();
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<duration.count()<<std::endl;

    return 0;
}