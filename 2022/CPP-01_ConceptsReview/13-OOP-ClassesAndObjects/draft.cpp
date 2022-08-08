#include <iostream>
#include <string>

void some_func(int &val){
    val += 1;
}

int main() {
    int value {10};
    some_func(value);
    std::cout<<value<<std::endl;

    return 0;
}