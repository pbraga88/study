#include <iostream>
#include <string>
#include <bits/stdc++.h>
// Create a string to hold the inverse value (reversed_string)
// Implement a loop which will:
//      point to the last element from the imput - i, where i start in 0
//      insert the value pointed in the reversed_string[i]
//      keep repeating the above until i < string.size

std::string reverse(std::string str) {
    if (str.size() < 2) {
        return NULL;
    }
    
    std::string reversed_string;
    
    // std::cout<<*(str.begin()+1)<<std::endl;
    // std::cout<<*(str.end()-1)<<std::endl;
    
    // First approach - O(n)
    for (int i = 0; i < str.size(); i++) {
        reversed_string.push_back(*( (str.end()-1) - i));
    }

    // Second approach - O(n)
    // for (int i = str.size()-1; i >= 0; i--) {
    //     reversed_string.push_back(str[i]);
    // }
    
    return reversed_string;
}

std::string reverseInternalMethod(std::string str) {
    return std::string(str.rbegin(), str.rend());
}

int main() {
    std::string str = "Hello there!!!";
    // std::cout<<str<<std::endl;
    // std::cout<<reverse(str)<<std::endl;
    std::cout<<reverseInternalMethod(str)<<std::endl;

    return 0;
}