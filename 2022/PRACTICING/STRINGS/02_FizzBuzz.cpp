/*Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str;

        for (int i = 1; i <= n; i++) {
            if (!(i%3) && !(i%5)) {
                str.push_back("FizzBuzz");
            }
            else if(!(i%3) || !(i%5)) {
                str.push_back(i%5?"Fizz":"Buzz");
            }
            else {
                str.push_back(to_string(i));
            }
        }
        return str;
    }
};

int main() {
    int n = 15;
    Solution s;

    vector<string> str = s.fizzBuzz(n);

    for (auto val:str) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}