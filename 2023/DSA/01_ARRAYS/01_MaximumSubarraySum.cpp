/*
Given an array of integers, find the contiguous subarray (at least one number) which has the largest sum and return its sum.

Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: The contiguous subarray [4, -1, 2, 1] has the largest sum = 6.

Constraints:

The array will have at least one number.
The array can contain both positive and negative integers.
Hint: Consider using the "Sliding Window" or "Prefix Sum" pattern. Another approach is the "Kadane's Algorithm", which is a dynamic programming method to solve this problem efficiently.
*/

#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
#include <algorithm>
#include <numeric>

// Function to find the maximum subarray sum

// int maxSubArraySum(const std::vector<int>& nums) {
//     int arr_size = nums.size();
//     int max_sum = INT_MIN;
//     int window_size = 0;
//     int end = 0;
//     while(window_size <= arr_size) {
//         for (int i = 0, end=window_size; end < arr_size; i++, end++) {
//             int sum = std::accumulate(nums.begin()+i, nums.begin()+end, 0);
//             if (sum>max_sum) {
//                 max_sum = sum;
//             }
//         }
//         window_size+=1;
//     }
//     return max_sum; // Placeholder return
// }

int maxSubArraySum(const std::vector<int>& nums) {
    int n = nums.size();
    if (n==0) {
        return 0;
    }

    if (n==1) {
        return nums[0];
    }

    int max_sum = INT_MIN; // Initialize to the smallest integer value
    int window_sum = 0; // This will store the sum of current window

    // First, calculate the sum of first window
    for (int i = 0; i<n; i++) {
        window_sum += nums[i];

        // Update the max_sum if the current window_sum is greater
        max_sum = std::max(max_sum, window_sum);

        // If window_sum becomes negative, reset it to 0. This is because
        // a negative sum will not contribute positively to future sums
        if (window_sum < 0) {
            window_sum = 0;
        }
    }
    
    return max_sum;;
}


int main() {
    // Test the function with the given example
    std::vector<int> nums = {-5, 1, -3, 8, -1, 2, 1, -5, 4};
    int result = maxSubArraySum(nums);
    std::cout << "Maximum Subarray Sum: " << result << std::endl;

    return 0;
}
