#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "Account.h"


class Savings_Account: public Account {
public:
    Savings_Account();
    ~Savings_Account();

    double int_rate;

    void deposit(double amount);
    void withdraw(double amount);
};

#endif