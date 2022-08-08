#include <iostream>

class Test_Class {
    public:
        Test_Class() {
            std::cout<<"class created"<<std::endl;
        }
};

int main() {
    Test_Class tc;
    
    return 0;
}