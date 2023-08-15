// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

template <typename T>
void display(T word) {
    std::cout<<"[ ";
    for (auto &letter:word) {
        std::cout<<letter;
    }
    std::cout<<" ]"<<std::endl;
}

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> word;

    std::copy_if(s.begin(), s.end(), std::back_inserter(word), [](unsigned char c){return std::isalpha(c);});
    // display(word);

    for (int i = 0; i < word.size()/2; i++) {
        if (std::tolower(word.back()) != std::tolower(word.front())) {
            return false;
        }
        word.pop_back();
        word.pop_front();
    }

    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;

    return 0;
}