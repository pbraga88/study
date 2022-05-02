#include <iostream>
#include <vector>

std::vector<int> b_sort(std::vector<int> vec) {
    int aux {0};

    for (int i = 0; i < vec.size()-1 ; i++) {
        for (int j = 0; j <vec.size()-1; j++) {
            if (vec[j] > vec[j+1]) {
                // aux = vec[j+1];
                // vec[j+1] = vec[j];
                // vec[j]=aux;
                std::swap(vec[j], vec[j+1]);
            }
        }
    }

    return vec;
}

int main() {
    std::vector<int> my_vec = {3,2,1, 0, 4, 120, 5, 2};
    std::vector<int> sorted_vec = b_sort(my_vec);

    std::vector<int>::iterator it = sorted_vec.begin();
    for (it; it != sorted_vec.end(); it++) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
 

    return 0;
}