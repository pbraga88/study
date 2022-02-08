#include <iostream>
#include <tuple>
using namespace std;

void assignment_operator() {
    
    //----WRITE YOUR CODE BELOW THIS LINE----
    // Declare num1 as an integer and initialize it to 13.
    int num1 {13};
    
    // Declare num2 as an integer and initialize it to 0.
    int num2 {0};
    
    // Assign the value 5 to num1
    num1 = 5;
    
    // Assign the value of num1 to num2
    num2 = num1; 
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
   
   cout << num1 << " " << num2;
}

int main() {
    assignment_operator();

    return 0;
}