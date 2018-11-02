#include <iostream>
using namespace std;

int main()
{
	    // declare a pointer to int and allocate space for it
    // with the keyword new
    int *pInt = new int; 

    // declare a pointer to double and allocate space for it
    // with the keyword new
    double * pDouble = new double;

    // store the value 3 in the memory location
    // pointed to by pInt
    *pInt = 3; 

    // store the value 5.0 in the memory location
    // pointed to by pDouble
    *pDouble = 5.0;
    
    // outout the values and memory addresses
    cout << "value at pInt = " << *pInt << ": memory address = " << pInt << endl;
    cout << "value stored at pDouble = " << *pDouble << ": location = " << pDouble << endl;
	
	cout << "size of pInt = " << sizeof(pInt) << endl;
	cout << "size of *pInt = " << sizeof(*pInt) << endl;
	
	cout << "size of pDouble = " << sizeof(pDouble) << endl;
	cout << "size of *pDouble = " << sizeof(*pDouble) << endl;	    
    

	// Release memory by ddeleting the bellow pointers
    delete pInt;
    delete pDouble;
	
	
	return 0;
}