/*
You are given a log file with the follow content:
[    0.000000]  event  foo.bar  START
[    0.500000]  event  other  some log message  
[    1.000000]  event  foo.bar  STOP
[    2.000000]  event  foo.bar  START
[    5.000000]  event  foo.bar  STOP
[    6.000000]  event  foo.bar  START
[    8.000000]  event  foo.bar  STOP
[    8.000000]  event  foo.qux  START
[    9.000000]  event  foo.qux  STOP

produce an output like the follow:
foo.bar: max: 3s; avg: 2s
foo.qux: max: 1s; avg: 1s

*/

// 1. Parse into a vector<vector<string>> using regex to look like:
//    [["0.00000", "foo.bar", "START"]
//     ["1.00000", "foo.bar", "STOP"]...
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <regex>
#include <algorithm>
#include <numeric>

void solution(std::string log_file){
    // Read the file to vector
    std::fstream input_file;
    std::string line;
    std::string word;
    std::vector<std::vector<std::string>> log_vector;

    input_file.open(log_file);
    while(std::getline(input_file, line)) {
        // std::regex pattern("foo.*");
        // if (std::regex_search(line, pattern)){
        if (line.find("foo.")!=std::string::npos) { // Alternative solution to use of regex
            std::stringstream ss(line);
            std::vector<std::string> words;
            
            while(ss>>word) {
                std::string clean_word;
                for (const char &c: word){
                    if (c!='['&&c!=']'){
                        clean_word+=c;
                    }
                }
                if(!clean_word.empty()){
                    words.emplace_back(clean_word);
                }
            }
            log_vector.emplace_back(words);
        }
    }
    input_file.close();

    // FOR DEBUG ONLY
    // for (auto line:log_vector) {
    //     for (auto word:line){
    //         std::cout<<word<<"  ";
    //     }
    //     std::cout<<std::endl;
    // }    

    // Apply the logic to get START and STOP
    std::map<std::string, std::vector<float>> event_ocurrence;
    std::unordered_map<std::string, std::string> single_occurence;
    for(auto event : log_vector) {
        if (single_occurence.find(event[2]) != single_occurence.end()) {
            event_ocurrence[event[2]].emplace_back(
                std::stof(event[0]) - std::stof(single_occurence[event[2]]));
            single_occurence.erase(event[2]);
        }
        else {
            single_occurence[event[2]] = event[0];
        }
    }

    // produce an output like the follow:
    // foo.bar: max: 3s; avg: 2s
    // foo.qux: max: 1s; avg: 1s
    for (auto event:event_ocurrence) {
        std::cout<<event.first<<": ";
        std::sort(event.second.begin(), event.second.end(), [](float x, float y){return x > y;});
        std::vector<float>::iterator it = event.second.begin();
        std::cout<<"max: "<<*it<<"s; ";
        std::cout<<"avg: "<<std::accumulate(event.second.begin(), event.second.end(), 0.0f)/event.second.size()<<"s";
        std::cout<<std::endl;
    }

}

int main() {
    std::string input_log_file {"logs.txt"};
    solution(input_log_file);

    return 0;
}