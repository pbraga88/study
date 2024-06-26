// Contructors and Destructors
#include <iostream>

class Base {
private:
    int value;
public:
    Base():value{0} {
        std::cout<<"Base no-args contructor"<<std::endl;
    }
    Base(int x) : value{x} {
        std::cout<<"Overloaded Base 1-arg contructor"<<std::endl;
    }
    ~Base() {
        std::cout<<"Base destructor"<<std::endl;
    }
    
    // For test only
    void print_value() {
        std::cout<<value<<std::endl;
    }
};

class Derived: public Base{
private:
    int doubled_value;
public:
    Derived(): Base{}, doubled_value{0} {
        std::cout<<"Dervived no-args contructor"<<std::endl;
    }
    Derived(int x): Base{x}, doubled_value{2*x} {
        std::cout<<"Derived 1-arg contructor"<<std::endl;
    }
    ~Derived() {
        std::cout<<"Derived destructor"<<std::endl;
    }

};


int main() {
    // Base base;
    // base.print_value();

    // Derived d;
    Derived derived{10};

    return 0;
}