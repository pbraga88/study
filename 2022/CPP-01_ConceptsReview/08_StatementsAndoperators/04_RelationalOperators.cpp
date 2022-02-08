// Section 8
// Relational Operators
#include <iostream>

using namespace std;

void relational1() {
    int num1{}, num2{};
    
    cout << boolalpha;
//    cout << "Enter 2 integers separated by a space: ";
//    cin >> num1 >> num2;
    
//    cout << num1 << " > "   << num2  << " : " << (num1 > num2) << endl;
//    cout << num1 << " >= " << num2  << " : " << (num1 >= num2) << endl;
//    cout << num1 << " < "  << num2  << " : " << (num1 < num2) << endl;
//    cout << num1 << " <= " << num2  << " : " << (num1 <= num2) << endl;
   
    const int lower {10};
    const int upper {20};
    
    cout << "\nEnter an integer that is greater than " << lower << " : " ;
    cin >> num1;
    cout << num1 << " > " << lower << " is " << (num1 > lower) << endl;
    
    cout << "\nEnter an integer that is less than or equal to " << upper << " : " ;
    cin >> num1;
    cout << num1 << " <= " << upper << " is " << (num1 <=  upper) << endl;
    
    cout  << endl;
}

int main() {
    // relational1();

    int num1 {10};
    int num2 {20};

    cout<<boolalpha; // will display true/false instead of 1/0 for booleans
    
    cout<<(num1<=num2)<<endl; // prints true
    cout<<(num1==num2)<<endl; // prints false
    cout<<(num1>=num2)<<endl; // prints false

    return 0;
}