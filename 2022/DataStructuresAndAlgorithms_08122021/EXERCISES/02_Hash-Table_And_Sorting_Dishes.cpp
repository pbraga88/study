/*
You are given a list dishes, where each element consists of a list of strings beginning with the name of the dish, followed by all the ingredients used in preparing it. 
You want to group the dishes by ingredients, so that for each ingredient you'll be able to find all the dishes that contain it (if there are at least 2 such dishes).

Return an array where each element is a list beginning with the ingredient name, followed by the names of all the dishes that contain this ingredient. 
    The dishes inside each list should be sorted lexicographically, and the result array should be sorted lexicographically by the names of the ingredients.

For
  dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
            ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
            ["Quesadilla", "Chicken", "Cheese", "Sauce"],
            ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]
the output should be:
  solution(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
                            ["Salad", "Salad", "Sandwich"],
                            ["Sauce", "Pizza", "Quesadilla", "Salad"],
                            ["Tomato", "Pizza", "Salad", "Sandwich"]]
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

vector<vector<string>> solution(vector<vector<string>> dishes) {
    vector<vector<string>> r_vec;
    unordered_map<string, set<string>> umap;
    map<string, set<string>> i_map;

    for (int i = 0; i<dishes.size(); i++) {
        for (int j = 1; j < dishes[i].size(); j++) {
            if (umap.find(dishes[i][j]) == umap.end()){ // ADD NEW
                umap[dishes[i][j]].insert(dishes[i][0]);
            }
            else {
                if (umap[dishes[i][j]].size() == 1) {
                    umap[dishes[i][j]].insert(dishes[i][0]);
                    i_map.insert(pair<string, set<string>>(dishes[i][j], umap[dishes[i][j]]));
                }
                else {
                    i_map[dishes[i][j]].insert(dishes[i][0]);
                }
            }
        }
    }
    
    // assign i_map to vector<vector<string>>
    map<string, set<string>>::iterator it = i_map.begin();
    set<string>::iterator it_set;

    r_vec.resize(i_map.size());

    for (int i = 0; i < i_map.size(); i++) {
        r_vec[i].push_back(it->first);
        it_set = it->second.begin();
        for (int j = 0; j < it->second.size(); j++) {          
            r_vec[i].push_back(*it_set);
            it_set++;
        }
        it++;
    }

    // set<string>::iterator it;
    // for(auto val: i_map) {
    //     cout<<val.first<<" ";
    //     for (auto val2: val.second) {
    //         cout<<val2<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"======================"<<endl;
    return r_vec;

}

int main() {
    vector<vector<string>> dishes = {{"Salad", "Tomato", "Cucumber", "Salad", "Sauce"},
                                     {"Pizza", "Tomato", "Sausage", "Sauce", "Dough"},
                                     {"Quesadilla", "Chicken", "Cheese", "Sauce"},
                                     {"Sandwich", "Salad", "Bread", "Tomato", "Cheese"}};

    vector<vector<string>> dishes_sorted = solution(dishes);
    for(auto val: dishes_sorted){
        for (auto val2: val) {
            cout<<val2<<" ";
        }
        cout<<endl;
    }

    return 0;
}