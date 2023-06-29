#include <iostream>
#include <vector>
#include <algorithm>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age) : name (name), age (age) {
    }
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person&rhs) const {
        return (this->name==rhs.name && this->age==rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ": " << p.age;
    return os;
}

// Use for_each and a lambda expression to display vector elements
void display2 (const std::vector<int> &vec) {
    std::cout<<"[ ";
    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout<<x<<" ";});
    std::cout<<"]"<<std::endl;
}

// template function to display any vector
template <typename T>
void display (T vec) {
    std::cout<<"[ ";
    for (auto elem:vec) {
        std::cout<<elem<<"; ";
    }
    std::cout<<"]"<<std::endl;
}

void test1() {
    std::cout<<"================ test 01 ================"<<std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);

    vec = {2,4,5,6};
    display2(vec);

    std::vector<int> vec1(10,100); // init vector with ten times '100'
    display(vec1);
}

void test2() {
    std::cout<<"================ test 02 ================"<<std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;

    vec.push_back(6);
    display(vec);
    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl; // If capacity is exceeded, it doubles in size. e.g from 5 to 10

    vec.shrink_to_fit(); // reduce capacity to size
    display(vec);
    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;

    vec.reserve(100);
    display(vec);
    std::cout<<"vec size: "<<vec.size()<<std::endl;
    std::cout<<"vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;
}

void test3() {
    std::cout<<"================ test 03 ================"<<std::endl;

    std::vector<int> vec{1,2,3,4,5};
    display(vec);

    vec[0] = 100; // Does NOT check boundaries
    vec.at(1) = 200; // Does check boundaries and throws 'std::out_of_range' expection in case out of bounds

    display(vec);
}

void test4() {
    std::cout<<"================ test 04 ================"<<std::endl;
    std::vector<Person> stooges;

    Person P1("Larry", 18);
    display(stooges);

    stooges.push_back(P1);
    display(stooges);

    stooges.push_back(Person("Curly", 30));
    display(stooges);

    stooges.emplace_back("Moe", 32); // Constructs the object in place
    display(stooges);
}

void test5() {
    std::cout<<"================ test 05 ================"<<std::endl;
    std::vector<Person> stooges {
        {"Larry", 18},
        {"Curly", 30},
        {"Moe", 32}
    };
    display(stooges);

    std::cout<<"Front: "<<stooges.front()<<std::endl;
    std::cout<<"Back: "<<stooges.back()<<std::endl;

    stooges.pop_back();
    display(stooges);
}


int main() {
/* Testing*/
    // std::vector<int> test {1,2,3,4,5};
    // display2(test);
    // std::vector<Person> family {{"Maria", 2},{"Marianna", 36}, {"Paulo", 34}};
    // display(family);

    // test1();
    // test2();
    // test3();
    // test4();
    test5();


    return 0;
}