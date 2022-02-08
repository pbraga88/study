#include <iostream>

using namespace std;

void someFunc(int numbers[], int size){
    for(int i = 0; i < size; i++){
        cout<<numbers[i]<<endl;
    }

    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout<<numbers[i]<<" "<<numbers[j]<<endl;
        }
    }
}

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
    // int numbers[5] = {1,2,3,4,5};
    // someFunc(numbers, (sizeof(numbers)/sizeof(numbers[0])) );

    arrayOfN(5);

    return 0;
}