#include <iostream>
#include <chrono>

void print_01(){
    double d = 2, limit = 3, maximum = 4, sx = 5, sy = 10;
    double x = d * (limit / maximum) * sx;
    double y = d * (limit / maximum) * sy;
}
void print_02() {
    double d = 2, limit = 3, maximum = 4, sx = 5, sy = 10;
    double z = d * (limit / maximum);
    double x = z * sx;
    double y = z * sy;
}

int main() {
    
    
    auto start = std::chrono::high_resolution_clock::now();
    print_01();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout<<duration.count()<<std::endl;
    // std::cout<<x<<std::endl;
    // std::cout<<y<<std::endl;
    

    auto start_2 = std::chrono::high_resolution_clock::now();
    print_02();
    auto stop_2 = std::chrono::high_resolution_clock::now();
    auto duration_2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_2 - start_2);
    std::cout<<duration_2.count()<<std::endl;

    // std::cout<<x<<std::endl;
    // std::cout<<y<<std::endl;


    return 0;
}