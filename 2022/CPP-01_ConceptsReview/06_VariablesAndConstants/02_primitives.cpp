#include <iostream>
#include <climits>

using namespace std;

void printPrimitiveSizes() {
    // Char
    cout<<"size of char: "<<sizeof(char)<<" Byte"<<endl;

    // Integers
    cout<<"size of short: "<<sizeof(short)<<" Bytes"<<endl;
    cout<<"size of int: "<<sizeof(int)<<" Bytes"<<endl;
    cout<<"size of long: "<<sizeof(long)<<" Bytes"<<endl;
    cout<<"size of long long: "<<sizeof(long long)<<" Bytes"<<endl;

    // Floating-point
    cout<<"size of float: "<<sizeof(float)<<" Bytes"<<endl;
    cout<<"size of double: "<<sizeof(double)<<" Bytes"<<endl;
    cout<<"size of long double: "<<sizeof(long double)<<" Bytes"<<endl;

    // bool
    cout<<"size of bool: "<<sizeof(bool)<<" Byte"<<endl;
}

void playingWithVariables() {
    long people_on_earth {7'600'000'000}; // Á partir do C++14 é possível utilizar apóstrofo para 
                                          // tornar mais fácil a leitura de números grandes
    cout<<people_on_earth<<endl;

    long long distance {9'461'000'000'000};
    cout<<distance<<endl;

    float payment {401.23};
    cout<<payment<<endl;
    
    double pi {3.14159};
    cout<<pi<<endl;

    long double bigNumber {2.7e120};
    cout<<bigNumber<<endl;

    bool game_over {false};
    cout<<game_over<<endl;

    short value1 {30000};
    short value2 {30000};
    short product {value1*value2}; // This will cause an overflow
    cout<<product<<endl;
}
int main(){
    // printPrimitiveSizes();
    playingWithVariables();
    
    return 0;
}