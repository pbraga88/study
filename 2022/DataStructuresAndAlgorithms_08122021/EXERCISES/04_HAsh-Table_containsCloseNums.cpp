/*
Given an array of integers nums and an integer k, determine whether there are two distinct indices i and j in the array where nums[i] = nums[j] and the absolute difference
 between i and j is less than or equal to k.

Example

For nums = [0, 1, 2, 3, 5, 2] and k = 3, the output should be
solution(nums, k) = true.

There are two 2s in nums, and the absolute difference between their positions is exactly 3.

For nums = [0, 1, 2, 3, 5, 2] and k = 2, the output should be
solution(nums, k) = false.

The absolute difference between the positions of the two 2s is 3, which is more than k.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool solution(vector<int> nums, int k) {
    unordered_map<int, int> u_map;

    for (int i = 0; i < nums.size(); i++) {
        if (u_map.find(nums[i]) == u_map.end()) {
            u_map[nums[i]] = i;
        }
        else {
            if((i - u_map[nums[i]]) <= k) {
                return true;
            }
            u_map[nums[i]] = i;
        }
    }

    return false;
}


int main () {
    vector<int> nums {1, 0, 1, 2, 1, 1, 2};

    cout<<solution(nums, 2)<<endl;

    return 0;
}