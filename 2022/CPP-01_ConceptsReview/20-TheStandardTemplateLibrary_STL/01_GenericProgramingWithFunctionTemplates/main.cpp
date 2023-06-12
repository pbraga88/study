#include <iostream>


template <typename T>
T max(T a, T b) {
    return a>b ? a : b;
}

template <typename T>
void print_func(T a, T b){
    std::cout<<a<<" "<<b<<std::endl;
}

struct Person {
    std::string name;
    int age;
    bool operator>(const Person &rhs) {
        return this->age > rhs.age;
    }
};


int main () {
    Person p1 {"Curly", 50};
    Person p2 {"Moe", 80};

    // Create an object to return Person
    Person OlderPerson = max(p1, p2);
    std::cout<<OlderPerson.name<<" is older"<<std::endl;
    // Directly read the output from max() function
    std::cout<<max(p1, p2).name<<" is older"<<std::endl;

    std::cout<<max<int>(10,9)<<std::endl;
    std::cout<<max(10,9)<<std::endl;
    std::cout<<max(20.1,22.3)<<std::endl;
    std::cout<<max('A','B')<<std::endl;

    // print_func<int>(10,9);
    // print_func(10,9);
    // print_func(20.1,22.3);
    // print_func('A','B');


    return 0;
}