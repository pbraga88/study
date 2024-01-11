/*
Given an array strings, determine whether it follows the sequence given in the patterns array. 
In other words, there should be no i and j for which strings[i] = strings[j] and patterns[i] ≠ patterns[j] or for which strings[i] ≠ strings[j] 
and patterns[i] = patterns[j].

Example:
For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
solution(strings, patterns) = true;
For strings = ["cat", "dog", "doggy"] and patterns = ["a", "b", "b"], the output should be
solution(strings, patterns) = false.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


bool solution(std::vector<std::string> strings, std::vector<std::string> pattern) {
    std::unordered_map<std::string, std::string> strings_to_pattern;
    std::unordered_map<std::string, std::string> pattern_to_string;
    for(int i = 0; i<strings.size(); i++) {
        if (strings_to_pattern.find(strings[i]) != strings_to_pattern.end()) {
            if (strings_to_pattern[strings[i]] != pattern[i]) {
                return false;
            }
        }
        if (pattern_to_string.find(pattern[i]) != pattern_to_string.end()) {
            if (pattern_to_string[pattern[i]] != strings[i]) {
                return false;
            }
        }
        strings_to_pattern[strings[i]] = pattern[i];
        pattern_to_string[pattern[i]] = strings[i];
    }
    
    return true;
}

int main() {
    std::vector<std::string> strings {"cat", "dog", "doggy"};
    std::vector<std::string> pattern {"a", "b", "b"};

    std::cout<<solution(strings, pattern)<<std::endl;

    return 0;
}