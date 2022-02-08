/* Given a array, find a matching pair which sums up to a given value
E.g:
Array1 = [1, 3, 5, 7]
sum = 8
return true if found and false if not

Is there a pair in the Array1 which sums up to 8?
*/

#include <iostream>
#include <vector>
#include <unordered_set>

/* First Approach: Nested loops
    - Time Complexity: O(n²)
    - Space Complexity: O(1)
*/
bool checkPairs(std::vector<int> intArr, int sumValue) {
    // Go through array item by item and check the sum
    // with every item in list
    // If there's is a pait which sums up to sumValue,
    // return true, otherwise, return false

    for (int i = 0; i < intArr.size(); i++){
        for (int j = i+1; j < intArr.size(); j++) {
            if ( (intArr[i]+intArr[j]) == sumValue) {
                return true;
            }
        }
    }
    return false;
}

/* Second Approach: 
    - Time Complexity: O(n)
    - Space Complexity: O(n)
*/
bool checkPairs2nd(std::vector<int> intArr, int sumValue){
    // Create an empty hash map
    // add the complements to reach the sum in there
    // loop the array and return true in case of array value find its complement in the map
    std::unordered_set<int> myCompl;

    for (int value:intArr) {
        if (myCompl.find(value) != myCompl.end()) {
            return true;
        }
        myCompl.insert(sumValue - value);
    }

    return false;
}

int main() {
    std::vector<int> array1({1,3,4,4});
                         // {1,3,5,9}
    std::cout<<checkPairs(array1, 8)<<std::endl;

    //debug
    // for (int i: array1){
    //     std::cout<<i<<std::endl;
    // }

    return 0;
}
