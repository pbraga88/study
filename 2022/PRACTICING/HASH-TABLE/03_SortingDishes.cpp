#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

std::vector<std::vector<std::string>> solution(std::vector<std::vector<std::string>> dishes) {
	std::unordered_map<std::string, std::set<std::string>> u_map;
	std::map<std::string, std::set<std::string>> i_map;

	for (int i = 0; i < dishes.size(); i++) {
		for (int j = 1; j < dishes[i].size(); j++) {
			if (u_map.find(dishes[i][j]) == u_map.end()) { // NOT FOUND
				u_map[dishes[i][j]].insert(dishes[i][0]);
			}
			else {
				if (u_map[dishes[i][j]].size() == 1) {
					u_map[dishes[i][j]].insert(dishes[i][0]);
					i_map[dishes[i][j]].insert(u_map[dishes[i][j]].begin(), u_map[dishes[i][j]].end());
				}
				else {
					i_map[dishes[i][j]].insert(dishes[i][0]);
				}
				
			}
		}
	}
	
    // Iterate through map and add to vector (return type requested in exercise)
	std::vector<std::vector<std::string>> r_vec;
	r_vec.resize(i_map.size());
	std::map<std::string, std::set<std::string>>::iterator m_it = i_map.begin();
	std::set<std::string>::iterator s_it;
	for (int i = 0; i < i_map.size(); i++) {
		r_vec[i].push_back(m_it->first);
		s_it = m_it->second.begin();
		for (int j = 0; j < s_it->size(); j++) {
			r_vec[i].push_back(*s_it);
			s_it++;
		}
		m_it++;
	}
	
	
	return r_vec;
}

int main() {
    std::vector<std::vector<std::string>> dishes = {{"Salad", "Tomato", "Cucumber", "Salad", "Sauce"},
                                     {"Pizza", "Tomato", "Sausage", "Sauce", "Dough"},
                                     {"Quesadilla", "Chicken", "Cheese", "Sauce"},
                                     {"Sandwich", "Salad", "Bread", "Tomato", "Cheese"}};

    std::vector<std::vector<std::string>> dishes_sorted = solution(dishes);
    for(auto val: dishes_sorted){
        for (auto val2: val) {
            std::cout<<val2<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}