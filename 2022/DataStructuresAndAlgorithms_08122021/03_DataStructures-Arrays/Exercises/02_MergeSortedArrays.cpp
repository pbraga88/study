#include <iostream>
#include <vector>

// Create a aux int var
// Add values from vec2 to vec1 
// Bubble-sort vec1 

// First Solution: O(n²)
std::vector<int> mergeAndSort(std::vector<int> vec1, std::vector<int> vec2) {
    int aux {0};

    for (int value:vec2) {
        vec1.push_back(value);
    }

    // for(int i = 0; i<vec1.size(); i++) {
    //     for(int j = i+1; j < vec1.size(); j++) {
    //         if (vec1[i] > vec1[j]) {
    //             aux = vec1[j];
    //             vec1[j] = vec1[i];
    //             vec1[i] = aux;
    //         }
    //     }
    // }

    for(int i = 0; i<vec1.size(); i++) {
        for(int j = i+1; j < vec1.size(); j++) {
            if (vec1[i] > vec1[j]) {
                aux = vec1[j];
                vec1[j] = vec1[i];
                vec1[i] = aux;
            }
        }
    }

    // USE SWAP
    return vec1;    
}


std::vector<int> mergeAndSort2(std::vector<int> vec1, std::vector<int> vec2) {
    std::vector<int> merged;
    int pvec1 = vec1[0];
    int pvec2 = vec2[0];

    int i{0}, j{0};

    while (i<vec1.size() || j<vec2.size()) {
        if(i<vec1.size() && (j == vec2.size() || pvec1 <= pvec2)) {
            merged.push_back(pvec1);
            pvec1 = vec1[i+1];
            i++;
        }
        else {
            merged.push_back(pvec2);
            pvec2 = vec2[j+1];
            j++;
        }
    }


    return merged;
}


int main() {
    // [0,3,4,31], [3,4,6,30]
    std::vector<int> vec2 {3, 4, 6, 30};
    std::vector<int> vec1 {0, 3, 4, 31};
    
    std::vector<int> mergedVectors = mergeAndSort2(vec1, vec2);

    for(int value:mergedVectors) {
        std::cout<<value<<" ";
    }
    std::cout<<std::endl;
    

    return 0;
}