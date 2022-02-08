#include <iostream>

using namespace std;

int main(){
    int num1 {8};
    int num2 {20};

    // The remainder is num1
    cout<<num1%num2<<endl;

    // result = 170
    int result = 10 + num1 * num2;
    cout<<result<<endl;
    // result = 170
    result = num1 * num2 + 10;
    cout<<result<<endl;

    return 0;
}