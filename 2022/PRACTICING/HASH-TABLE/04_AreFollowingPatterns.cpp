#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> strings, vector<string> patterns) {
	unordered_map<string, string> string_umap;
	unordered_map<string, string> pattern_umap;
	
	for (int i = 0; i < strings.size(); i++) {
		if (string_umap.find(strings[i]) == string_umap.end()) { // NOT FOUND
			string_umap[strings[i]] = patterns[i];
			if (pattern_umap.find(patterns[i]) != pattern_umap.end()) {
				return false;
			}
			pattern_umap[patterns[i]] = strings[i];
		}
		else {
			if (string_umap[strings[i]] != patterns[i]){
				return false;
			}
		}
			
	}
	return true;
}

int main() {
    vector<string> strings {"cat", "dog", "dog"};
    vector<string> pattern {"a", "b", "b"};

    cout<<solution(strings, pattern)<<endl;

    return 0;
}