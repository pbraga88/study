#include <iostream>

using namespace std;

int main(){
    int num1{10}, num2{20};
    double result {0.0};

    // result will be 0 because it's two integer types beind divided
    result = num1/num2;
    cout<<result<<endl;

    // casting only one of the variables will turn the division result into double, hence resul = 0.5
    result = static_cast<double>(num1) / num2;
    cout<<result<<endl;

    return 0;
}