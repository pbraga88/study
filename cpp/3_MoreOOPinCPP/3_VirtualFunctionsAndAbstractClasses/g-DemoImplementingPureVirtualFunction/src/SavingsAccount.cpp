#include "SavingsAccount.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount(double initialBalance, double interestRate)
	: BankAccount(initialBalance), interestRate(interestRate), frozen(false)
{}

SavingsAccount::~SavingsAccount()
{}

void SavingsAccount::earnInterest()
{
	if (!frozen)
	{
		double interest = balance * (interestRate / 100);
		deposit(interest);
	}
}

void SavingsAccount::deposit(double amount)
{
	if(!frozen)
	{
		BankAccount::deposit(amount);
		log("Deposit: " + to_string(amount));
	}
}

void SavingsAccount::withdraw(double amount)
{
	if(!frozen && amount <= balance)
	{
		BankAccount::withdraw(amount);
		log("Withdraw: " + to_string(amount));
	}
}

string SavingsAccount::getTermsAndConditions()
{
	return "This is a savings account. You cannot go overdrawn. You earn interest.";
}

double SavingsAccount::getGuaranteedLimit()
{
	return 75000;
}

void SavingsAccount::freeze()
{
	frozen = true;
}

void SavingsAccount::unfreeze()
{
	frozen = false;
}

void SavingsAccount::log(const string &message) const
{
	cout << message << endl; 
}