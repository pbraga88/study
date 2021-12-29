#include <iostream>
using namespace std;

void PassByValue(int);
void PassByRef(int &num);

int main()
{
	int num1;
	
	int num2;
	int *pNum = &num2;
	
	num1 = 3;
	*pNum = 5;
	
	double *pDouble = new double;
	*pDouble = 5.0;
	
	PassByValue(num1);
	cout << "Back to main(), the value of num1 is: " << num1  << endl;
	
	PassByRef(*pNum);
	cout << "Back to main(), the value of pNum is: " << *pNum  << endl;
	
	PassByValue(*pNum);
	
	cout << "The value of pDouble is: " << *pDouble << endl;
	delete pDouble;
	cout << "The value of pDouble is: " << *pDouble << endl;
	
}

void PassByValue(int num)
{
	   cout << "You are in PassByValue" << endl;
	   num++;
	   cout << "num1 is now: " << num << endl;
		
}

void PassByRef(int &num)
{
	cout << "You are in PassByRef" << endl;
	num = 50;
	cout << "The modified value of pNum is: " << num << endl;
		
}