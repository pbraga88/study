// Section 16
// Using Base class pointers

#include <iostream>
#include <vector>

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account { // The use of final specifier will prevent this class to derived, hence
                     // causing an compilation error in case other classes try to derive it
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
    virtual void withdraw(double amount) const override{ // Note that here, the signature is different and 'override' specifier is not used.
                                           // This will cause a function redefinition instead, which will lead to a base calss
                                           // call of funtcion, when an Account object is created as pointer to Savings:
                                           // Account *p2 = new Savings();
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) const override { // The usage of final specifier in a virtual function will generate a compilation
                                                               // error if a derived class (from Trust) tries to override the withdraw function
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

class Payment:public Account {
public:
    virtual void withdraw(double amount) const override { // A compilation error wil be triggered, since withdraw function was declared final in
                                                         // Trust class
        std::cout << "In payment::withdraw" << std::endl;
    }
    virtual ~Payment() {  }
};
/****************************************************************************/

void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);
}

int main() {
    Account a; 
    Account &ref = a;
    ref.withdraw(1000); // In Account:withdraw

    /* Note that we're using dinamyc polymorphism, hence class is pick in runtime, 
    depending on what time of object is being implemented */

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(1000); // In Trust::withdraw

    /* More examples, now using the 'do_withdraw' function, which expects a reference to Account object.
       Again, not that, once we're using Dynamic Polymorphism, the class being used is picked at runtime */
    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;
    Payment a5;

    do_withdraw(a1, 1000);
    do_withdraw(a2, 1000);
    do_withdraw(a3, 1000);
    do_withdraw(a4, 1000);
    do_withdraw(a5, 1000);

    return 0;
}