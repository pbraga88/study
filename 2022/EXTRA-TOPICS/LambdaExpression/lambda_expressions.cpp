#include <iostream>
#include <vector>
#include <algorithm>

// Function to print vector
void  printVector(std::vector<int> v) {
    std::for_each(v.begin(), v.end(), [](int i){std::cout<<i<<" ";} );
    std::cout<<std::endl;
}

int main() {
    std::vector<int> vec {1,2,5,4,3};
    printVector(vec);

    // Below snippet finds first number greater than 4
    // 'find_if' searches for an elemente for which 'function(third argument)' returns 'true'
    std::vector<int>::iterator p = std::find_if(vec.begin(), vec.end(), [](int i) {
            return i>4;
        });
    std::cout<<"First number greater than 4 is: "<<*p<<std::endl;

    // Function to sort vector. Lambda expression is for sorting in non-increaseing order
    // Compiler can make out return type as bool, but it's explicitly shown here for the sake of example
    std::sort(vec.begin(), vec.end(), [](const int &a, const int &b) -> bool{
        return a>b;
    });
    // Print sorted vector (decreasing order)
    printVector(vec);
    return 0;
}