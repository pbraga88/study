#pragma once

#include <string>

using namespace std;

class BankAccount{
	protected:
		double balance;

	public:
		BankAccount(double initialBalance);
		virtual ~BankAccount();		

		double getBalance()	const;

		virtual void deposit(double amount);
		virtual void withdraw(double amount);

		virtual string getTermsAndConditions() = 0;
		virtual double getGuaranteedLimit() = 0;
};