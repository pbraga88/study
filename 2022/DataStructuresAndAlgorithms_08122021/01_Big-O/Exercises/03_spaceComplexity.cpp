#include <iostream>

using namespace std;

// This function has space complexity of O(n)
void arrayOfN(int num){
    string *array;
    array = new string[num];
    for(int i =0; i < num; i++) {
        array[i] = "hi";
    }
    
    for(int i =0; i < num; i++) {
        cout<<array[i]<<endl;
    }

}
int main() {

    arrayOfN(5);

    return 0;
}