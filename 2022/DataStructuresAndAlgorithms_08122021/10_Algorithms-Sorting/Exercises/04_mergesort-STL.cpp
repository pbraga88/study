#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> merge_sort(std::vector<int> vec) {
    int length = vec.size();
    int i = length/2;
    int j = length/2;

    /* fix if division not balanced */
    if (length%2) {j+=1;}
    
    std::vector<int> first_half(i);
    std::vector<int> second_half(j);

    std::vector<int>::iterator it = vec.begin() + i;
    
    std::copy(vec.begin(), it, first_half.begin());
    std::copy(it, vec.end(), second_half.begin());

    std::sort(first_half.begin(), first_half.end());
    std::sort(second_half.begin(), second_half.end());

    merge(first_half.begin(), first_half.end(), second_half.begin(), second_half.end(), vec.begin());

    return vec;
}

int main() {
    std::vector<int> my_vec = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    
    std::vector<int> sorted_vec = merge_sort(my_vec);
    for (auto val: sorted_vec) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    return 0;
}