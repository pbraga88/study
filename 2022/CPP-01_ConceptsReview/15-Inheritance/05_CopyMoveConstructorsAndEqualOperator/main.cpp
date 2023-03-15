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
        std::cout<<"int Base contructor"<<std::endl;
    }
    Base(const Base &other) : value{other.value}{
        std::cout<<"Base copy constructor"<<std::endl;
    }
    Base &operator=(const Base &rhs) {
        std::cout<<"Base operator="<<std::endl;
        if(this == &rhs) {
            return *this;
        }
        value = rhs.value;
        return *this;
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
        std::cout<<"int Derived constructor"<<std::endl;
    }
    Derived(const Derived &other) 
        : Base(other), doubled_value {other.doubled_value}  {
        std::cout<<"Derived copy constructor"<<std::endl;
    }
    Derived &operator=(const Derived &rhs) {
        std::cout<<"Derived operator="<<std::endl;
        if(this == &rhs) {
            return *this;
        }
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }

    ~Derived() {
        std::cout<<"Derived destructor"<<std::endl;
    }

};


int main() {
    // Base b{100};
    // Base b1(b);
    // b = b1;

    Derived d {100};
    Derived d1(d);
    d=d1;

    return 0;
}