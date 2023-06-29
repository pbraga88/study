#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person {
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name(name), age(age) {}
    
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Find an element in a container
void find_test() {
    std::cout<<"========================================================="<<std::endl;
    std::vector<int> vec {1,2,3,4,5};

    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    if (loc != std::end(vec)) {
        std::cout<<"Found: "<<*loc<<std::endl;
    }
    else {
        std::cout<<"Not found!"<<std::endl;
    }
    
    std::cout<<"========================================================="<<std::endl;

    std::list<Person> Players {
        {"Larry",   18},
        {"Moe",     20},
        {"Curly",   21}
    };
    auto loc1 = std::find(std::begin(Players), std::end(Players), Person("Moe", 20));
    if (loc1 != std::end(Players)) {
        std::cout<<"Moe found!"<<std::endl;
    }
    else {
        std::cout<<"Moe not found"<<std::endl;
    }

}

// Count the number of occurrences of an element in a container
void count_test() {
    std::cout<<"========================================================="<<std::endl;
    std::vector<int> nums {1,2,3,4,5,6,7,8,9,1,2,1,2,1};
    
    // Count the occurrences of number 1
    int count = std::count(std::begin(nums), std::end(nums), 1);
    std::cout<<count<<" occurrences found!"<<std::endl;
}

// Count the number of occurrences of an element in a container
// based on a predicate using a lambda expression
void count_if_test() {
    std::cout<<"========================================================="<<std::endl;

    // Count only if the element is even
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10,100,1000,101,1001};
    int even_count = std::count_if(std::begin(vec), std::end(vec), [](int x) {return x%2==0;});
    std::cout<<even_count<<" even numbers found"<<std::endl;

    // Count only if the element is odd
    int odd_count = std::count_if(std::begin(vec), std::end(vec), [](int x) {return x%2!=0;});
    std::cout<<odd_count<<" odd numbers found"<<std::endl;

    // Count only if element >= 5
    int count_five = std::count_if(std::begin(vec), std::end(vec), [](int x) {return x >= 5;});
    std::cout<<count_five<<" numbers >= 5 found"<<std::endl;
}

// Replace occurences of elements in a container
void replace_test() {
    std::cout<<"========================================================="<<std::endl;
    std::vector<int> vec{1,2,3,4,5,1,2,1};
    for (auto i: vec) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    std::replace(vec.begin(), vec.end(), 1, 200);
    for (auto i: vec) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

}

// Check all of the elements in a container
void all_of_test() {
    std::cout<<"========================================================="<<std::endl;
    std::vector<int> vec1 {1,3,5,7,9,1,3,13,19,5};
    if(std::all_of(vec1.begin(), vec1.end(), [](int x){ return x > 10;})) {
        std::cout<<"All elements are > 10"<<std::endl;
    }
    else {
        std::cout<<"Not all elements are > 10"<<std::endl;
    }

    if (std::all_of(std::begin(vec1), std::end(vec1), [] (int x){return x<20;})) {
        std::cout<<"All elements are < 20"<<std::endl;
    }
    else {
        std::cout<<"Not all elements are > 20"<<std::endl;
    }
}

// Transform elements in a container. e.g string to uppercase
void string_transform_test() {
    std::cout<<"========================================================="<<std::endl;
    std::string str1 {"this is a test string"};
    std::cout<<"Before transform: "<<str1<<std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout<<"After transform: "<<str1<<std::endl;

    // Return to lower
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);

    // Insert resulting uppercase strin in another string
    std::string str2;
    str2.resize(str1.size());
    std::cout<<"Before transform: "<<str1<<std::endl;
    std::transform(str1.begin(), str1.end(), str2.begin(), ::toupper);
    std::cout<<"After transform: "<<str2<<std::endl;
}

int main() {
    // find_test();
    // count_test();
    // count_if_test();
    // replace_test();
    all_of_test();
    // string_transform_test();

    return 0;
}