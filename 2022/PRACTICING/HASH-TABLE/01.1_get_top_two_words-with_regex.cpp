/* Given a string of words, get the top 2 occurrence
 input: "this is an example of input. as you can see this this is repeated of unknown magnitude is not this?"
 output: is
		 this
*/

/*
	1 - Parse the string into a hash-table {word:qty}
	
	2 - Copy hash-table values into a vector {word:qty}
	
	3 - Sort vector {key:value} in descending as per its value
	
	4 - Print the desired output
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <regex>

using namespace std;

unordered_map<string, int> str_parser(string str) {
	unordered_map<string, int> u_map;
	regex reg("[a-zA-Z]+");
	sregex_iterator current_match(str.begin(), str.end(), reg);
	sregex_iterator last_match;
	
	while (current_match != last_match){
		// ADD regex to capture [a-zA-Z]
		smatch match = *current_match;
		if (u_map.find(match.str()) != u_map.end()) {//FOUND IT
			u_map[match.str()] += 1;
		}
		else { // NOT FOUND
			u_map[match.str()] = 1;
		}
		current_match++;
	}
	return u_map;
}

vector<pair<string, int>> fill_vec(unordered_map<string, int> u_map) {
	vector<pair<string, int>> vec(u_map.begin(), u_map.end());
	return vec;
}

void sort_vector(vector<pair<string, int>>& vec) {
	sort(vec.begin(), vec.end(), [](auto a, auto b){return a.second>b.second;});
}

void print_top_two(vector<pair<string, int>> vec) {
    if (!vec.size()) {
        cout<<"error"<<endl;
        return;
    }

	int count {0};

    for (int i = 0; i<2; i++) {
        cout<<vec[i].first<<endl;
        if (vec.size() == 1) {
            break;
        }
    }
}

int main() {
    string str {"this is an example of input. as you can see this this is repeated of unknown magnitude is not it?"};
    unordered_map<string, int> umap = str_parser(str);
    vector<pair<string, int>> str_vec = fill_vec(umap);
    sort_vector(str_vec);
    print_top_two(str_vec);

    return 0;
}