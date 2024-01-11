/*
Given an array of integers nums and an integer k, determine whether there are two distinct indices i and j in the array where nums[i] = nums[j] and the absolute 
difference between i and j is less than or equal to k.

Example

For nums = [0, 1, 2, 3, 5, 2] and k = 3, the output should be
solution(nums, k) = true.

There are two 2s in nums, and the absolute difference between their positions is exactly 3.

For nums = [0, 1, 2, 3, 5, 2] and k = 2, the output should be
solution(nums, k) = false.

The absolute difference between the positions of the two 2s is 3, which is more than k.
*/


#include <iostream>
#include <unordered_map>
#include <vector>

bool solution(std::vector<int> nums, int diff) {
    std::unordered_map<int, int> last_occurence;
    for (int i = 0; i<nums.size(); i++) {
        if (last_occurence.find(nums[i]) != last_occurence.end()) {
            if (i - last_occurence[nums[i]] <= diff) {
                return true;
            }
        }
        last_occurence[nums[i]] = i;
    }

    return false;
}


int main () {
    std::vector<int> nums {0, 1, 2, 3, 5, 2};

    std::cout<<solution(nums, 2)<<std::endl;

    return 0;
}