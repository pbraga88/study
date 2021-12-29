//#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num = 10;
	int *pNum = &num;
	
    cout << pNum << endl; // Print the address location
    cout << *pNum << endl; // Print the value
    
    //Different way to ascribe a var to a pointer
    int num2 = 11;
    int *pNum2;
    *pNum2 = num2;
    
    
    //*pNum = 4;
    cout << *pNum2 << endl; // Change the var (num) value
    cout << num2 << endl; // The var value after the change
    
    return 0;
}