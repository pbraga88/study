#include <iostream>

using namespace std;
int main() {
    /* BASIC CAST */
    // float f = 3.14;
    // cout<<f<<endl;
    // int a = f; // C-style cast will conver float to int
    // cout<<a<<endl;
    // int b = static_cast<int>(f); // C++ static cast
    // cout<<b<<endl;

    /* ILEGAL CAST*/    
    // int a = 10;
    // char c = 'a';
    // int *q = (int*)&c;
    // int *p = static_cast<int*>(&c); // This will cause a compilation error: invalid static_cast from type ‘char’ to type ‘int*’
    
    return 0;
}