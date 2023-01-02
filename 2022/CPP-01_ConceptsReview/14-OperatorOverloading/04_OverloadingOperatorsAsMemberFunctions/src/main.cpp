#include <iostream>
#include <vector>
#include "my_string.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};

    Mystring stooge = larry;
    larry.display();
    moe.display();

    std::cout << std::boolalpha << std::endl; // Print true/false instead of 1/0
    std::cout<<(larry==moe)<<std::endl;       // true
    std::cout<<(larry==stooge)<<std::endl;    // false

    larry.display();                          // Larry
    Mystring lower_case = -larry;
    lower_case.display();                     // larry

    Mystring stooges = larry + " " + "Moe";
    stooges.display();                        // LarryMoe
    
    // Mystring two_stooges = "Moes"+larry;      // Compilatio error

    Mystring three_stooges = larry + " " + moe + " " + "Curly";
    three_stooges.display();

    return 0;
}