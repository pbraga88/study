/*
Given a 2D Array, A:

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

An hourglass in A is a subset of values with indices falling in this pattern in 
A's graphical representation:

a b c
  d
e f g

There are 16 hourglasses in A. An hourglass sum is the sum of an hourglass' 
values. Calculate the hourglass sum for every hourglass in A, then print the 
maximum hourglass sum. The array will always be 6x6.

Example:

-9 -9 -9  1 1 1
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0

The 16 hourglass sums are:

-63, -34, -9, 12, 
-10,   0, 28, 23, 
-27, -11, -2, 10, 
  9,  17, 25, 18

The highest hourglass sum is 28 from the hourglass beginning at row 3, column 2:

0 4 3
  1
8 6 6
*/
#include <iostream>
#include <vector>
#include <climits> // FOR INT_MIN
#include <numeric>

int hourglassSum(std::vector<std::vector<int>> arr) {
    std::vector<std::vector<int>> arr_mask = {{1, 1, 1},
                                              {0, 1, 0},
                                              {1, 1, 1}};
    int max_sum = INT_MIN;

    for (int row = 0; row < 4; row++){
      for (int column = 0; column < 4; column++) {
        int current_sum = 0;
        for (int i = 0; i<3; i++) {
          for (int j = 0; j<3; j++) {
            current_sum += arr[row+i][column+j] * arr_mask[i][j];
          }
        }
        // Returns the maximum value from the comparison
        max_sum = std::max(max_sum, current_sum);
      }
    }

    return max_sum;
}

int main() {
// -9 -9 -9  1 1 1
//  0 -9  0  4 3 2
// -9 -9 -9  1 2 3
//  0  0  8  6 6 0
//  0  0  0 -2 0 0
//  0  0  1  2 4 0
    std::vector<std::vector<int>> input_arr ={{-9, -9, -9, 1, 1, 1},
                                              { 0, -9,  0, 4, 3, 2},
                                              {-9, -9, -9, 1, 2, 3},
                                              { 0,  0,  8, 6, 6, 0},
                                              { 0,  0,  0,-2, 0, 0},
                                              { 0,  0,  1, 2, 4, 0}};

    int result = hourglassSum(input_arr);    
    std::cout<<"Max = "<<result<<std::endl;


    return 0;
}