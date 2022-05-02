
/*
Given an array strings, determine whether it follows the sequence given in the patterns array. 
In other words, there should be no i and j for which strings[i] = strings[j] and patterns[i] ≠ patterns[j] or for which strings[i] ≠ strings[j] and patterns[i] = patterns[j].

Example:
For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
solution(strings, patterns) = true;
For strings = ["cat", "dog", "doggy"] and patterns = ["a", "b", "b"], the output should be
solution(strings, patterns) = false.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> strings, vector<string> patterns) {
    unordered_map<string, string> sp_umap;
    unordered_map<string, string> ps_umap;

    for (int i = 0; i < strings.size(); i++) {
        if (sp_umap.find(strings[i]) != sp_umap.end()) {
            if (sp_umap[strings[i]] != patterns[i]) {
                return false;
            }
        }
        else {
            if (ps_umap.find(patterns[i]) != ps_umap.end()) {
                return false;
            }
            sp_umap[strings[i]] = patterns[i];
            ps_umap[patterns[i]] = strings[i];
        }
    }
    
    return true;
}

int main() {
    vector<string> strings {"cat", "dog", "doggy"};
    vector<string> pattern {"a", "b", "c"};

    cout<<solution(strings, pattern)<<endl;

    return 0;
}