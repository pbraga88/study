#include <iostream>

void test_func() {
    static int var = 0;
    std::cout<<var<<std::endl;
    var ++;
    std::cout<<var<<std::endl;
}

int main() {
    for (int i = 0; i < 10; i++) {
        test_func();
    }
    return 0;
}