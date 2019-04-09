#include "SavingsAccount.h"
#include <iostream>

using namespace std;

void freezeMe(Freezable &f)
{
	// We don't know what type of object 'f' refers to. All we know is that it implements "Freezable"
	f.freeze();
}

int main()
{
	/* Initialize with a 1000 deposit and a interest rate of 2,5%*/
	SavingsAccount acc(1000, 2.5);

	cout << "Terms and Conditions: " << acc.getTermsAndConditions() << endl;
	cout << "Guarantee limit: " << acc.getGuaranteedLimit() << endl;

	acc.deposit(100);
	acc.deposit(200);
	acc.withdraw(50);
	acc.earnInterest();

	/* A movimentação á seguir não é feita, pois a função 'freezeMe()' é chamada
		e o objeto 'acc' é passado.*/
	freezeMe(acc);

	acc.deposit(1000);
	acc.deposit(2000);
	acc.withdraw(500);
	acc.earnInterest();

	/* Aqui, a função 'unfreeze()' é utilizada, portanto a movimentação á seguir
		pode ser feita.*/
	acc.unfreeze();

	acc.deposit(10000);
	acc.deposit(20000);
	acc.withdraw(5000);
	acc.earnInterest();

	return 0;

}