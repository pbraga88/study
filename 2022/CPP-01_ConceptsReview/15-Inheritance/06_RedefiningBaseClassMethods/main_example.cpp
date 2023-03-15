#include <iostream>

class Base {
public:
    virtual void print() {
        std::cout << "Printing from Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Printing from Derived class" << std::endl;
    }
};

int main() {
    Base *bClass = new Derived;
    bClass->print();
    delete bClass;

    return 0;
}