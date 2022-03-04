/* Given and array, find the first recurring character
example: 
Given an array = [2,5,1,2,3,5,1,2,4]:
It should return 2

Given an array = [2,1,1,2,3,5,1,2,4]:
It should return 1

Given an array = [2,3,4,5]:
It should return undefined

Bonus... What if we had this:
[2,5,5,2,3,5,1,2,4]
return 5 because the pairs are before 2,2
*/

#include <iostream>
#include <vector>
#include <unordered_set>

/*time complexity O(n)
  space complexity O(n)
*/
int findFirstRecurring_hashTable(std::vector<int> int_array) {
    int fr = -1;
    std::unordered_set<int> int_set;

    for (auto val:int_array) {
        if(int_set.find(val) != int_set.end()){
            std::cout<<"found recurring!"<<std::endl;
            return val;
        }
        int_set.insert(val);
    }

    return fr;
}

/* Considering numbers ranging from 0 to 9 */
/*time complexity O(n)
  space complexity O(n)
*/
int findFirstRecurring_flip(std::vector<int> int_array) {
    int arr[10] {0};
    for(auto val:int_array) {
        if (arr[val] == -1) {
            return val;
        }
        arr[val] = -1;
    }

    return -1;
}

int main() {
    std::vector<int> int_array {2,5,1,2,3,5,1,2,4};  // must return 2
    // std::vector<int> int_array {2,5,1,3}; // must return -1 (not found)
    // std::vector<int> int_array {2,1,1,2,3,5,1,2,4};  // must return 1
    // std::vector<int> int_array {2,5,5,2,3,5,1,2,4};  // must return 5
    std::cout<<findFirstRecurring_hashTable(int_array)<<std::endl;
    std::cout<<findFirstRecurring_flip(int_array)<<std::endl;

    return 0;
}