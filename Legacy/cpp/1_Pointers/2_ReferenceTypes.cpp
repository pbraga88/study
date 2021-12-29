#include <iostream>
using namespace std;

void passByValue(int);

int main()
{

    int num = 3;
    cout << "In main()" << endl;
    cout << "Value of num is " << num << endl;

    passByValue(num);

    cout << "Back in main and the value of num is  " << num << endl;


    return 0;
}

void passByValue(int num1)
{
    cout << "In passByValue()" << endl;
    cout << "Value of num1 is " << num1 << endl;

    // modify num1, won't impact num
    num1++;

    cout << "num1 is now " << num1 << endl;
}