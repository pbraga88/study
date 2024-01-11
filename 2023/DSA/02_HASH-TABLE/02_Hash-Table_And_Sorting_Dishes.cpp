/*
You are given a list dishes, where each element consists of a list of strings beginning with the name of the dish, followed by all the ingredients used in 
preparing it. 
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
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>

std::vector<std::vector<std::string>> solution (std::vector<std::vector<std::string>> dishes) {
    std::vector<std::vector<std::string>> ingredients_grouped;
    std::unordered_map<std::string, std::set<std::string>> ingredients_mapped;

    for (const auto& elem: dishes) {
        for (int i = 1; i < elem.size(); i++) {
            ingredients_mapped[elem[i]].emplace(elem[0]);
        }
    }

    for (const auto& elem:ingredients_mapped) {
        if (elem.second.size()>=2){
            std::vector<std::string> group;
            group.push_back(elem.first);
            for(const auto& dish: elem.second) {
                group.push_back(dish);
            }
            ingredients_grouped.push_back(group);
        }
    }
    std::sort(ingredients_grouped.begin(), ingredients_grouped.end(),
        [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
            return a[0] < b[0];  // Compare the first word of each inner vector
        });

    return ingredients_grouped;
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