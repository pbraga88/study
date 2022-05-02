/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
    public:
        void reverseString(std::vector<char>& s){
            std::reverse(s.begin(), s.end());
        }
};

int main() {
    // std::vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> str {'H', 'a', 'n', 'n', 'a', 'h'};
    Solution s;

    std::cout<<"input: ";
    for(auto val:str){
        std::cout<<val;
    }
    std::cout<<std::endl;

    s.reverseString(str);

    std::cout<<"output: ";
    for(auto val:str){
        std::cout<<val;
    }
    std::cout<<std::endl;

    return 0;
}