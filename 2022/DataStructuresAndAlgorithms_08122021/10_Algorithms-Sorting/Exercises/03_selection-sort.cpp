#include <iostream>
#include <vector>

// [2, 0, 1]

std::vector<int> selection_sort(std::vector<int> vec) {
    int minor {0}, aux {0};

    for (int i = 0; i < vec.size(); i++) {
        minor = vec[i];
        for (int j = i+1; j < vec.size(); j++) {
            if (vec[j] < minor) {
                minor = vec[j];
                aux = j;
            }
        }
        if (minor != vec[i]) {
            vec[aux] = vec[i];
            vec[i] = minor;
        }

    }

    return vec;
}

int main() {

    std::vector<int> my_vec = {3,2,1, 0, 4, 120, 5, 2};
    // std::vector<int> my_vec = {2,0,1,2};
    std::vector<int> sorted_vec = selection_sort(my_vec);

    std::vector<int>::iterator it = sorted_vec.begin();
    for (it; it != sorted_vec.end(); it++) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    return 0;
}