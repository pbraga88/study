#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>



int main() {
    std::vector<std::pair<int, int>> pairs = {{1, 5}, {2, 3}, {3, 2}};

    int sum = std::accumulate(pairs.begin(), pairs.end(), 0, [](int acc, const auto& p) {
        return acc + /*p.first +*/ p.second;
    });
    std::cout<<sum<<std::endl;

    std::vector<int> first_elements;
    std::transform(pairs.begin(), pairs.end(), std::back_inserter(first_elements), [](const auto& p) {
        return p.first;
    });

    for (const auto& pair:pairs) {
        std::cout<<pair.first<<","<<pair.second<<" ";
    }
    std::cout<<std::endl;

    for (const auto& element:first_elements) {
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
