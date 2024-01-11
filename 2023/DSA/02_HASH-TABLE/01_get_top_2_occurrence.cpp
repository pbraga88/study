/* Given a string of words, get the top 2 occurrence */
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<std::pair<std::string, int>> top_occurrence(std::string s) {
    // std::vector<std::pair<std::string, int>> sorted_vector;
    std::vector<std::pair<std::string, int>> top_two {{"", 0}, {"", 0}};
    std::unordered_map<std::string, int> words_counter;
    std::stringstream ss(s);
    std::string word;

    while (ss>>word) {
        std::string clean_word;
        // std::cout<<word<<" "<<std::endl;
        for (char c: word) {
            if (std::isalpha(c)){
                clean_word += c;
            }
        }
        if (!clean_word.empty()) {
            ++words_counter[clean_word];
        }

        /* No need to use find, since it's just a metter of adding to the hash-table */
        // words_counter.find(clean_word)!=words_counter.end() ? 
        //     words_counter[clean_word]+=1: words_counter[clean_word]=1;
    }

    // for (auto word:words_counter) {
    //     sorted_vector.push_back(std::make_pair(word.first, word.second));
    // }

    for (const auto& entry:words_counter) {
        if (entry.second>top_two[0].second) {
            if(top_two[0].second > top_two[1].second) {
                top_two[1] = top_two[0];
            }
            top_two[0] = entry;
        }
        else if(entry.second>top_two[1].second) {
            top_two[1] = entry;
        }
    }

    // No need to sort, since I'm getting top two values in the loop above.
    // std::sort(sorted_vector.begin(), sorted_vector.end(),[](std::pair<std::string, int> x, std::pair<std::string, int> y) {return x.second>y.second;});

    return top_two;
}


int main(/*int argc, char** argv*/) {
    // if (argc < 2) {
    //     std::cout<<"Please, provide n"<<std::endl;
    //     return 1;
    // }
    // std::string str = "string de teste teste sim teste de string de teste ok";
    std::string str = "sort() takes a third parameter that is used to specify the order in which elements are to be sorted.\
                       We can pass the “greater()” function to sort in descending order. This function does a comparison in\
                        a way that puts greater elements before. to";
    std::vector<std::pair<std::string, int>> top_two = top_occurrence(str);
    for (const auto &word:top_two) {
        std::cout<<word.first<<": "<<word.second<<std::endl; 
    }



    return 0;
}