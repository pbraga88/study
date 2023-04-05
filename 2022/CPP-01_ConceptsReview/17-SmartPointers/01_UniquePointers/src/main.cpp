// Section 17
// Unique Pointers 
#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main() {

    // std::unique_ptr<int> i1 {new int(10)};
    // std::cout<<*i1<<std::endl;

    // std::unique_ptr<Test> t1 {new Test(1000)};
    // std::unique_ptr<Test> t2 {new Test(10000)};

    // std::unique_ptr<Test> t3;
    // // t3 = t2; // This strikes a compilation error because an unique pointer can't be 
    //             // copied nor assigned. 
    
    // t3 = std::move(t2); // This will work and cause t3 to point to the value of t2 and t2
    //                     // will become a NULL pointer
    // if (!t2) {
    //     std::cout<<"t2 is null"<<std::endl;
    // }


    /* Creating unique_ptr for Account objects */
    // Since Account is the base class, for Polymorphism, one can instantiate classes deriving from it 
    std::unique_ptr<Account> a1{make_unique<Checking_Account>("Moe", 5000)};
    std::cout<<*a1<<std::endl;
    a1->deposit(5000);
    std::cout<<*a1<<std::endl;

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::move(a1));
    accounts.push_back(make_unique<Savings_Account>("James", 11000));
    accounts.push_back(make_unique<Trust_Account>("Billy", 13000));

    // Reference must be used, since unique pointers can't be copied
    for (const auto &account:accounts) {
        std::cout<<*account<<std::endl;
    }

    return 0;
}

