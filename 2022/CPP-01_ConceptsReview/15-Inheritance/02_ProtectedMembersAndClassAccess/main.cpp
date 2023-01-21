// Protected Members and Class Access

#include <iostream>

class Base {
public:
    int a{0};
    void display(){
        std::cout<<a<<", "<<b<<", "<<c<<std::endl;
    }
protected:
    int b{0};
private:
    int c{0};
};

class Derived: public Base {
    // Note friend of Derived class has the same level of access Derived has

    // a will be public
    // b will be protected (accessible from the Derived class)
    // c will be private (NOT accessible from the Derived class)
public:
    void access_base_members() {
        a = 100;    // OK
        b = 1000;   // OK
        // c = 200;    // Compilation error
    }

};

int main() {
    Base b;
    b.a = 10;   // OK
    // b.b = 100;  // Compilation error
    // b.c = 200;  // Compilation error
    b.display();

    Derived d;
    d.a = 100;  // OK
    // d.b = 1000; // Compilation error
    // d.c = 300;  // Compilation error

    return 0;
}