/* Given a string of words, get the top 2 occurrence */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <sstream>

// Parse string to vector
std::vector<std::string> parse_string(std::string str) {
    std::vector<std::string> words_vec;
    std::string word;
    std::stringstream str_s(str);

    while (str_s >> word) {
        words_vec.push_back(word);
    }

    return words_vec;
}

// Add strings from vector to hash table counting occurrence
std::unordered_map<std::string, int> add_to_table(std::vector<std::string> words_vec) {
    std::unordered_map<std::string, int> umap;
    std::unordered_map<std::string, int>::iterator it;
    
    for (auto word: words_vec) {
        if ((it = umap.find(word)) != umap.end()) {
            // umap[word] += 1;
            it->second += 1; 

        }
        else {
            // umap[word] = 1;
            umap.insert(std::make_pair(word, 1));
        }
    }
    
    return umap;
}

// Sort: Read hash table (key, value) into a vector<pair<string,value>>
//       Sort the vector and return it sorted
std::vector<std::pair<std::string, int>> sort_table(std::unordered_map<std::string, int> umap) {
    std::vector<std::pair<std::string, int>> sorted_vec(umap.begin(), umap.end());

    // std::sort(sorted_vec.begin(), sorted_vec.end(), [](auto a, auto b){return a.second < b.second;}); // SORT ASCENDING
    std::sort(sorted_vec.begin(), sorted_vec.end(), [](auto a, auto b){return a.second > b.second;}); // SORT DESCENDING

    return sorted_vec;
}

// Get top 2 occurence into vector<pair>
std::vector<std::pair<std::string, int>> getTopN(std::vector<std::pair<std::string, int>> s_vec, int n) {
    std::vector<std::pair<std::string, int>> top_values;
    std::vector<std::pair<std::string, int>>::iterator it = s_vec.begin();
    
    for (int i = 0; i < n; i++) {
        top_values.push_back(*it);
        it++;
    }

    return top_values;

}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout<<"Please, provide n"<<std::endl;
        return 1;
    }
    // std::string str = "string de teste teste sim teste de string de teste ok";
    std::string str = "sort() takes a third parameter that is used to specify the order in which elements are to be sorted.\
                       We can pass the “greater()” function to sort in descending order. This function does a comparison in\
                        a way that puts greater elements before. to";

    std::vector<std::string> parsed_string = parse_string(str);

    std::unordered_map<std::string, int> u_map = add_to_table(parsed_string);
    // Print hash table elements
    // for (auto pair: u_map) {
    //     std::cout<<pair.first<<": "<<pair.second<<std::endl;
    // }

    std::vector<std::pair<std::string, int>> sorted_vec = sort_table(u_map);
    // for(auto val: sorted_vec) {
    //     std::cout<<val.first<<": "<<val.second<<std::endl;
    // }

    std::vector<std::pair<std::string, int>> top_ocurrence = getTopN(sorted_vec, atoi(argv[1]));
    for (auto val: top_ocurrence) {
        std::cout<<val.first<<": "<<val.second<<std::endl;
    }

    return 0;
}