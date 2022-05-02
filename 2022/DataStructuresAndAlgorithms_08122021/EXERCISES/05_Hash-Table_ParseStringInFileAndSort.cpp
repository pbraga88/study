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
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm> //For sorting. To remove if not needed
#include <fstream>   // For file manipulation
#include <regex>

// using namespace std;
// [    0.000000]  event  foo.bar  START
// [    0.500000]  event  other  some log message  
std::vector<std::string> getMatches(std::regex reg, std::string str) {
    std::vector<std::string> reg_match;
    std::sregex_iterator currentMatch (str.begin(), str.end(), reg);
    std::sregex_iterator last_match;
    // std::cout<<str<<std::endl;
    while (currentMatch != last_match) {
        std::smatch match = *currentMatch;
        // std::cout<<match.str()<<std::endl;
        reg_match.push_back(match.str());
        currentMatch++;
    }
    // std::cout<<std::endl;

    return reg_match;
}

std::vector<std::vector<std::string>> parse_file(std::string file) {

    std::vector<std::vector<std::string>> parsed_file;
    std::vector<std::string> parse_line;;
    
    // open file and read it
    std::string line;
    std::fstream file_io;
    
    // Define regex rules
    std::regex reg("\\d{1,7}.\\d{1,7}|foo.[a-z]+|[A-Z]+");
                  
    // std::ios::in -> open for read
    // std::ios::out -> open for write
    // std::ios::app -> open for append
    file_io.open(file, std::ios::in);
    
    while (file_io) {
        std::getline(file_io, line);
        // CALL REGEX FUNCTION
        parse_line = getMatches(reg, line);
        if (parse_line.size() == 3) {
            parsed_file.push_back(parse_line);        
        }        
    }
    file_io.close();
    
    return parsed_file;
}

// 2. Throw into hash-table <string, double> 
//    message exist in table?
//      y: push to list (vector[i] - table[event])
//         erase table[event]
//      n: add event (vector[i][1]) and starting time (stod(vector[i][0])) to map<double, string> 
std::map<std::string, std::vector<double>> parse_to_map(std::vector<std::vector<std::string>> p_values) {
    std::unordered_map<std::string, double> h_table;
    std::map<std::string, std::vector<double>> events;

    for (int i = 0; i < p_values.size(); i++) {
        // check hash-table
        if (h_table.find(p_values[i][1]) != h_table.end()) {
            // found: add to map and erase from table
            events[p_values[i][1]].push_back(std::stod(p_values[i][0]) - h_table[p_values[i][1]]);
            h_table.erase(p_values[i][1]);
        }
        else {
            // not found: add to table
            h_table[p_values[i][1]] = std::stod(p_values[i][0]);
        }
    }

    return events;
}

// 3. Parse map to produce desired output string
//    Write the output into a file
void printOutuput(std::map<std::string, std::vector<double>> sorted_values) {
    // a. Parse map and print desired output
    //      foo.bar: max: 3s; avg: 2s
    //      foo.qux: max: 1s; avg: 1s
    double sum {0.0};
    for (auto event:sorted_values) {
        for (auto e_time:event.second) {
            sum += e_time;
        }
        sum /= event.second.size();
        std::cout<<event.first<<": max: "<<event.second[0]<<"s; avg: "<<sum<<"s"<<std::endl;
        sum = 0.0;
    }

    // b. Write to file
    std::fstream pfile;
    // open to write appending at file end (std::ios::out|std::ios::app)
    pfile.open("parsed_file.txt", std::ios::out|std::ios::app);
    for (auto event:sorted_values) {
        for (auto e_time:event.second) {
            sum += e_time;
        }
        sum /= event.second.size();
        pfile<<event.first<<": max: "<<event.second[0]<<"s; avg: "<<sum<<"s"<<std::endl;
        sum = 0.0;
    }
    pfile.close();

}

int main() {
    /* PARSE FILE */
    std::vector<std::vector<std::string>> p_file;
    p_file = parse_file("log.txt");
    
    /* ADD TO map<string, vector<double>> and sort values in vector*/
    std::map<std::string, std::vector<double>> mapped;
    mapped = parse_to_map(p_file);
    // sort (descending order) vector inside 'mapped'
    for (auto val:mapped) {
        std::sort(mapped[val.first].begin(), mapped[val.first].end(), std::greater<double>());
    }
    
    /* Print output and write to file */
    printOutuput(mapped);

    return 0;
}
