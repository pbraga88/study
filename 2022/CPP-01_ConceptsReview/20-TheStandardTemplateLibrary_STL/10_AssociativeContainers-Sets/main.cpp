#include <iostream>
#include <set>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name("Uknow"), age{0} {}
    Person(std::string name, int age): name{name}, age{age}{}
    
    bool operator<(const Person&rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name==rhs.name && this->age==rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(const std::set<T> &n) {
    std::cout<<"[ ";
    for (const auto element:n) {
        std::cout<<element<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1() {
    std::cout<<"\n============== TEST 01 =============="<<std::endl;
    std::set<int> s1 {1,4,3,5,2};
    display(s1);

    s1 = {2,2,3,5,5,4,4,4,1,1};
    display(s1);

    s1.insert(0);
    s1.insert(10);
    display(s1);

    if (s1.count(10)){
        std::cout<<"10 found in the set"<<std::endl;
    }
    else {
        std::cout<<"10 not found in the set"<<std::endl;
    }

    auto it = s1.find(5);
    if (it != s1.end()) {
        std::cout<<"Found: "<<*it<<std::endl;
    }

    s1.clear();
    display(s1);
}

void test2() {
    std::cout<<"\n============== TEST 02 =============="<<std::endl;
    std::set<Person> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges);

    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Frank", 50); //Not inserted, since 50 already exist
    display(stooges);

    auto it = stooges.find(Person{"Moe", 2}); // Wiil remove 'Moe'
    if (it != stooges.end()) {
        stooges.erase(it);
    }
    display(stooges);

    it = stooges.find(Person{"XXXX", 50}); // Will remove 'James', because '50' is the one compared
    if (it != stooges.end()) {
        stooges.erase(it);
    }
    display(stooges);
}

void test3() {
    std::cout<<"\n============== TEST 03 =============="<<std::endl;
    std::set<std::string> s{"A", "B", "C", "D"};

    auto result = s.insert("E");
    display(s);
    std::cout<<std::boolalpha;
    std::cout<<"first: "<<*(result.first)<<std::endl;
    std::cout<<"second: "<<result.second<<std::endl;
    if (result.second){
        std::cout<<*(result.first)<<" successfully inserted to the set"<<std::endl;
    }
    else {
        std::cout<<*(result.first)<<" already exist in the set"<<std::endl;
    }

    result = s.insert("A");
    display(s);
    std::cout<<std::boolalpha;
    std::cout<<"first: "<<*(result.first)<<std::endl;
    std::cout<<"second: "<<result.second<<std::endl;
    if (result.second){
        std::cout<<*(result.first)<<" successfully inserted to the set"<<std::endl;
    }
    else {
        std::cout<<*(result.first)<<" already exist in the set"<<std::endl;
    }

}

int main() {
    // test1();
    // test2();
    test3();

    return 0;
}

