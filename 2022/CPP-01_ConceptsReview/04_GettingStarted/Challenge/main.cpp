#include <iostream>

using namespace std;

int main(){
    int number = 0;
    cout<<"Enter your favorite number between 1 and 100: ";
    cin>>number;
    if(number > 0 && number <= 100) {
        cout<<"Amazing!! That's my fvorite number too!"<<endl;
        cout<<"No really!!, "<<number<<" is my favorite number!"<<endl;
    }
    return 0;
}