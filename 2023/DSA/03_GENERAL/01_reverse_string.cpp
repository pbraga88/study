/* Reverse string */
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

void solution(std::string str) {
    std::stack<std::string> reverse_string;
    std::stringstream ss(str);
    std::string word;
    while(ss>>word) {
        reverse_string.push(word);
    }
    
    while(!reverse_string.empty()) {
        std::cout<<reverse_string.top()<<" ";
        reverse_string.pop();
    }
    std::cout<<std::endl;
}

int main() {
    std::string regular_string {"This is a string which needs to be reserved by your solution. Good luck with that"};
    
    solution(regular_string);

    return 0;
}