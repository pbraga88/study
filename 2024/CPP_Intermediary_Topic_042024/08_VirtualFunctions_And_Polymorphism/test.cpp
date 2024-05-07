#include <iostream>
#include <typeinfo>
#include <bit>


int main() {
    float rounding_error = 3.14;//0.002/10;
    std::cout<<rounding_error<<std::endl;
    int absolut_value = std::bit_cast<int>(rounding_error); 
    std::cout<<absolut_value<<std::endl;
    return 0;
}