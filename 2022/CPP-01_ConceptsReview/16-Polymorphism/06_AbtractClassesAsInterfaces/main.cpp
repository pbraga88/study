#include <iostream>

/* Using Abstract Class to create an Interface which overrides the operator '<<' */
class I_Printable { // Interface <-> Abstract Class
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
};
std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

class Account : public I_Printable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os<<"Account display";
    }

    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os<<"Checking display";
    }

    virtual ~Checking() {  }
};

class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os<<"Savings display";
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os<<"Trust display";
    }
    virtual ~Trust() {  }
};

int main() {
    Account *p1 = new Account();
    std::cout << *p1 << std::endl;

    Account *p2 = new Checking();
    std::cout << *p2 << std::endl;
   
    Account *p3 = new Savings();
    std::cout << *p3 << std::endl;

    Account *p4 = new Trust();
    std::cout << *p4 <<std::endl;

    delete p1;  
    delete p2;
    return 0;
}