#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// Auxiliar function to display vector of integers in a range based loop
void display_vector(const std::vector<int> &vec) {
    std::cout<<"[ ";
    for (const auto &val:vec) {
        std::cout<<val<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1() {
    std::cout<<"\n===================================================\n"<<std::endl;
    std::vector<int> nums1 {1,2,3,4,5};
    std::vector<int>::iterator it = nums1.begin(); // point to 1
    std::cout<<*it<<std::endl;

    it++;   // point to 2
    std::cout<<*it<<std::endl;

    it+=2;  // point to 4
    std::cout<<*it<<std::endl;

    it-=2;  // point to 2
    std::cout<<*it<<std::endl;
    
    it = nums1.end()-1; // point to 5
    std::cout<<*it<<std::endl;
}

void test2() {
    std::cout<<"\n===================================================\n"<<std::endl;
    // Display all vectors elements using an iterator
    std::vector<int> nums {1,2,3,4,5};
    auto it = nums.begin();
    while (it != nums.end()) {
        std::cout<<*it<<std::endl;
        it++;
    }

    // Set all elements to 0
    it = nums.begin();
    while (it != nums.end()) {
        *it = 0;
        it++;
    }
    
    display_vector(nums);
}

void test3() {
    std::cout<<"\n===================================================\n"<<std::endl;
    // Using const iterators

    std::vector<int>nums {1,2,3,4,5};
    // Follow two lines are equivalent
    std::vector<int>::const_iterator it = nums.begin();
    // auto it = nums.cbegin(); // cbegin() = constant begin

    while (it != nums.end()) {
        std::cout<<*it<<std::endl;
        it++;
    }

    // If one tries to modify values using const iterator, compiler will shoot an error
    it = nums.cbegin();
    while (it != nums.cend()) {
        // *it = 0; // Compilation error: error: assignment of read-only location ‘it.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()’
        it++;
    }

    display_vector(nums);    
}

void test4() {
    // more iterators
    // using a reverse iterator
    std::cout<<"\n===================================================\n"<<std::endl;
    std::vector<int> nums {1,2,3,4,5};
    auto it = nums.rbegin(); // reverse iterator starts at 5
    while (it != nums.rend()) {
        std::cout<<*it<<std::endl;
        it++;
    }
    std::cout<<"\n===================================================\n"<<std::endl;
    // const reverse iterator over a string list
    std::list<std::string> names {"Larry", "Curly", "Moe"};
    auto it2 = names.crbegin();
    while(it2 != names.crend()) {
        std::cout<<*it2<<std::endl;
        it2++;
    }
    std::cout<<"\n===================================================\n"<<std::endl;
    // iterator over a map
    std::map<std::string, std::string> favorites {
        {"Frank","C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    auto it3 = favorites.begin();
    while (it3 != favorites.end()) {
        std::cout<<it3->first<<": "<<it3->second<<std::endl;
        it3++;
    }

}

void test5() {
    std::cout<<"\n===================================================\n"<<std::endl;
    // iterate over a subset
    std::vector<int> nums;
    for(int i = 0; i <=10; i++ ) {
        nums.push_back(i);
    }
    auto start = nums.begin()+2;
    auto end = nums.end() - 2;
    while (start != end) {
        std::cout<<*start<<std::endl;
        start++;
    }
}

int main() {

    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    return 0;
}