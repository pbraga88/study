#include <iostream>
#include <vector>

void printArray(std::vector<char> arr) {
    for(char item: arr){
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
}

int main() {
    std::vector<char> array({'a','b','c','d'});
    printArray(array);

    std::cout<<array[2]<<std::endl; // O(1)
    
    // Add to last position 
    array.push_back('e'); // O(1)
    printArray(array);

    // Remove last element
    array.pop_back(); // O(1)
    array.pop_back();
    printArray(array);

    // Insert at beggining
    array.insert(array.begin(), 'z'); // O(n)
    printArray(array);

    // Insert at ith position 
    array.insert(array.begin()+2, 'y'); // O(n)
    printArray(array);

    return 0;
}