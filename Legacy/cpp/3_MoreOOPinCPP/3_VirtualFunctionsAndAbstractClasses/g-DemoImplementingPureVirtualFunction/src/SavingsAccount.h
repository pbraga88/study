#pragma once
#include "BankAccount.h"
#include "Freezable.h"
#include "Loggable.h"

#include <list>

using namespace std;

class SavingsAccount : public BankAccount, public Freezable, public Loggable
{
	private:
		double interestRate;
		bool frozen;

	public:
		SavingsAccount(double IniitualBalance, double interestRate = 0.0);
		virtual ~SavingsAccount();

		void earnInterest();

		virtual void deposit(double amount);
		virtual void withdraw(double amount);

		// Implement pure virtual functions from BanckAccount class
		virtual string getTermsAndConditions();
		virtual double getGuaranteedLimit();

		// Implement pure virtual functions from Freezable class
		virtual void freeze();
		virtual void unfreeze();

		// Implement pure virtual function from Loggable class
		virtual void log(const string &message) const;
};
