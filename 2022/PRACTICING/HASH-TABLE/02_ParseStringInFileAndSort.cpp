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
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <regex>
#include <fstream>

// 1 - Parse file and produce vector like:
// 	   [['0.000000', 'foo.bar', 'START'],
//		['0.100000', 'foo.bar', 'STOP'],
//			[...]
std::vector<std::string> reg_func(std::regex reg, std::string str) {
	std::vector<std::string> l_extractions;
	std::sregex_iterator current_match(str.begin(), str.end(), reg);
	std::sregex_iterator last;
	
	while (current_match != last) {
		std::smatch match = *current_match;
		// l_extractions.push_back(match);
        l_extractions.push_back(match.str());
        current_match++;
	}
	return l_extractions;
}

std::vector<std::vector<std::string>> parse_to_vector (std::string path_to_file){
	std::vector<std::vector<std::string>> parsed_file;
    std::vector<std::string> parsed_line;
	std::string line; 
	std::fstream i_file;
	i_file.open(path_to_file, std::ios::in);
	
	std::regex reg("\\d{1,7}.\\d{1,7}|foo.[a-z]+|[A-Z]+");
	while (i_file) {
		std::getline(i_file, line);
        parsed_line = reg_func(reg, line);
        if (parsed_line.size() == 3) {
		    parsed_file.push_back(parsed_line);
        }
        // std::cout<<"loop"<<std::endl;
	}
	return parsed_file;
}

// 2 - send to a hash-table <event, time>
// 			- if event exist:
//					- event_time - <time> and output to a map <event, vector<elapsed_time>>
//					- remove event
//			- else			
//					- add event
//		

std::map <std::string, std::vector<double>> map_vector(std::vector<std::vector<std::string>> parsed_file) {
	std::unordered_map <std::string, double> u_map;
	std::map <std::string, std::vector<double>> m_values;
	
	for (int i = 0; i<parsed_file.size(); i++) {
		if (u_map.find(parsed_file[i][1]) != u_map.end()) {
			m_values[parsed_file[i][1]].push_back(std::stod(parsed_file[i][0]) - u_map[parsed_file[i][1]]);
			u_map.erase(parsed_file[i][1]);
		}
		else {
			u_map[parsed_file[i][1]] = std::stod(parsed_file[i][0]);
		}
	}
	
	return m_values;
}

// 3 - sort (descending) map vector<elapsed_time>
std::map<std::string, std::vector<double>> sort_values(std::map<std::string, std::vector<double>> m_values) {
	// for (auto event:m_values) {
	// 	std::sort(event.second.begin(), event.second.end(), std::greater<double>());
	// }
    for (auto val:m_values) {
        std::sort(m_values[val.first].begin(), m_values[val.first].end(), std::greater<double>());
    }
	return m_values;
}

// 4 - print the required output
// 		produce an output like the follow:
// 		foo.bar: max: 3s; avg: 2s
// 		foo.qux: max: 1s; avg: 1s
void printStats(std::map <std::string, std::vector<double>> sorted_values) {
	double sum {0};
	
	for (auto event:sorted_values) {
		for (auto e_time:event.second) {
			sum+=e_time;
		}
        std::cout<<event.first<<": max: "<<event.second[0]<<"s; avg: "<<sum/event.second.size()<<"s"<<std::endl;
		sum = 0;
	}
}

int main() {
    std::string file_path = "log.txt";
    std::cout<<"1"<<std::endl;
    std::vector<std::vector<std::string>> ptv = parse_to_vector(file_path);
    std::cout<<"2"<<std::endl;
    std::map <std::string, std::vector<double>> mv = map_vector(ptv);
    std::cout<<"3"<<std::endl;
    std::map<std::string, std::vector<double>> sv = sort_values(mv);
    std::cout<<"4"<<std::endl;
    printStats(sv);

    return 0;
}