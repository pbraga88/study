#include <iostream>
#include <string>
#include <cstring>
// Given 2 arrays, create a function that 
// let's a user know (true/false) whether
// these two arrays contain any common items.
// For Example:
// consta array1 = {'a', 'b', 'c', 'd'}
// consta array2 = {'x', 'y', 'i'}
// should return false
// -------------------
// consta array1 = {'a', 'b', 'c', 'x'}
// consta array2 = {'x', 'y', 'i'}
// should return true

// 2 parameters - arrays - no size limit
// return true/false

/* 1st approach - Nested loops
    - Time Complexity: O(n * m)
    - Space Complexity: O(1)
*/
// bool checkArrayForDuplication(const char array1[],const char array2[]) {
//     for(int i = 0; array1[i]; i++) {
//         for (int j = 0; array2[j]; j++) {
//             std::cout<<array1[i]<<" "<<array2[j]<<std::endl;
//             if(array1[i] == array2[j]) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

/* 2nd approach - Two separated loops
    - Time Complexity: O(n + m)
    - Space Complexity: O(n)
*/
bool checkArrayForDuplication(const char arr1[],const char arr2[]) {
    
    // Loop through arr1 and store the values indexes into 
    // controlArray
    char controlArray[256] = {0};
    for (int i = 0; arr1[i]; i++) {
        if(!controlArray[arr1[i]]) {
            controlArray[arr1[i]] = true;
        }
    }

    // Loop through arr2 and check whether its indexes match 
    // those stored in controlArray. If yes, return true
    for (int j = 0; arr2[j]; j++) {
        if(controlArray[arr2[j]]) {
            return true;
        }
    }

    return false;
}

int main(){
    char array1[5] = {'a', 'b', 'c', 'd', '\0'};
    char array2[4] = {'x', 'y', 'b', '\0'};

    std::cout<<checkArrayForDuplication(array1, array2)<<std::endl;

    return 0;
}