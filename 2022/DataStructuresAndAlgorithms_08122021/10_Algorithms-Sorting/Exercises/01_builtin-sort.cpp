#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

int main() {
    std::vector<int> vec = {2,65,34,2,1,7,8};

    std::sort(vec.begin(), vec.end());

    for (auto val: vec) {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;

    return 0;
}