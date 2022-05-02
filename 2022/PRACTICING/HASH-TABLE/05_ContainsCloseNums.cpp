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

// 1 - Insert the integer into hash-table as key and the index as value
// 2 - If the integer already exist in the hash-table, calculate: hash-table[i] - i
//		*	if <= k return true
// 3 - return false
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> numeros;

bool solution(std::vector<int> nums, int k) {
		std::unordered_map<int, int> ind_umap;
		
		for (int i = 0; i < nums.size(); i++) {
			if (ind_umap.find(nums[i]) != ind_umap.end()) { // FOUND
				if ((i - ind_umap[nums[i]]) <= k) {
					return true;
				}
				ind_umap[nums[i]] = i;
			}
			else { // NOT FOUND
				ind_umap[nums[i]] = i;
			}
		}
		
		return false;
}

int main () {
    std::vector<int> nums {0, 1, 2, 3, 5, 2};

    std::cout<<solution(nums, 3)<<std::endl;

    return 0;
}