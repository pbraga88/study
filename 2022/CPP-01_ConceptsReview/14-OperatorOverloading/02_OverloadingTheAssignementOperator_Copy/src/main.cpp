#include <iostream>
#include <vector>
#include "my_string.h"

int main(int argc, char **argv) {
    // (void)argc;
    // const char *input_string = argc==2 ? argv[1] : "default";
    // Mystring str_a = input_string; // Overloaded constructor
    // Mystring b;                    // no-args constructor
    // b = str_a;                     // copy assignment: b.operator=(a)
    // b = "This is a test";          //b.operator=("This is a test")
    
    /********************************/
    // Mystring empty;             // no-args constructor
    // Mystring larry("Larry");    // overloaded constructor
    // Mystring stooge(larry);     // copy constructor
    // Mystring stooges;           // no-args constructor
    // empty = stooge;             // copy assignment operator

    // empty.display();    // Larry 5
    // larry.display();    // Larry 5
    // stooge.display();   // Larry 5
    // empty.display();    // Larry 5

    // stooges = "Larry, Moe and Curly";
    // stooges.display();  // Larry, Moe and Curly : 20
    
    /********************************/
    std::vector<Mystring> stooges_vec;
    stooges_vec.push_back("Larry");
    stooges_vec.push_back("Moe");
    stooges_vec.push_back("Curly");
    std::cout<<"===== Loop 1 ====="<<std::endl;
    for (const Mystring &s:stooges_vec) { 
        s.display(); // Larry : 7
                     // Moe : 3
                     // Curly : 5
    }
    std::cout<<"===== Loop 2 ====="<<std::endl;
    for (Mystring &s:stooges_vec) {
        s = "Changed";
    }
    std::cout<<"===== Loop 3 ====="<<std::endl;
    for (const Mystring &s:stooges_vec) {
        s.display(); // Changed : 7
                     // Changed : 7
                     // Changed : 7
    }
    return 0;
}