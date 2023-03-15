// Section 16
// Using Base class pointers

#include <iostream>
#include <vector>

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account {
public:
    virtual void withdraw(double amount) const{
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) const override{ // Override specifier is used to make sure function signature is
                                                         // the same as the base class virtual function. In case it's 
                                                         // different, a compilation error will occur.
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) { // Note that here, the signature is different and 'override' specifier is not used.
                                           // This will cause a function redefinition instead, which will lead to a base calss
                                           // call of funtcion, when an Account object is created as pointer to Savings:
                                           // Account *p2 = new Savings();
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) const override{
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

int main() {
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    // std::cout<<"<<<<<<ARRAY>>>>>>"<<std::endl;
    // Account *array[] = {p1, p2, p3, p4};
    // for (auto i=0; i<4; i++) {
    //     (*(array+i))->withdraw(1000);
    // }

    std::cout<<"\n<<<<<<VECTOR>>>>>>"<<std::endl;
    std::vector<Account*> accounts{p1, p2, p3, p4};
    for (auto acc_ptr:accounts){
        acc_ptr->withdraw(1000);
    }

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}