/* Given a string of words, get the top 2 occurrence */
// input: "this is an example of input. as you can see this this is repeated of unknown magnitude is not this?"
// output: is
//		   this


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

std::unordered_map<std::string, int> readToUMap(std::string file_path) {
	std::unordered_map<std::string, int> uMap;
	std::string line, word;
	
	std::fstream in_file;
	in_file.open(file_path, std::ios::in);
	while(in_file) {
		std::getline(in_file, line);
        std::cout<<line<<std::endl;
		std::stringstream str_s(line);
		while(str_s>>word) {
			if (uMap.find(word) == uMap.end()) {
				uMap[word] = 1;
			}
			else{
				uMap[word] += 1;
			}
		}
	}
	return uMap;	
}

// 2. sort the hash-table in descending order
std::vector<std::pair<std::string, int>> sortUMap(std::unordered_map<std::string, int> uMap) {
	std::vector<std::pair<std::string, int>> sorted_vec(uMap.begin(), uMap.end());
	std::sort(sorted_vec.begin(),sorted_vec.end(), [](auto a, auto b){return a.second>b.second;});
	return sorted_vec;	
}

// 3. print the top 2 elements
void printTopTwo (std::vector<std::pair<std::string, int>> sorted_vec) {
	for (int i = 0; i < sorted_vec.size(); i++) {
		std::cout<<sorted_vec[i].first<<" "<<sorted_vec[i].second<<std::endl;
	}
}

int main() {
    std::string path = "words_file.txt";
    std::unordered_map<std::string, int> count_words = readToUMap(path);
    std::vector<std::pair<std::string, int>> sorted_words = sortUMap(count_words);
    printTopTwo(sorted_words);

    return 0;
}