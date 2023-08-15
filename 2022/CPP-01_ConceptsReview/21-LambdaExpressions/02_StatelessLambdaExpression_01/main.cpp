// Section 21
// Stateless lambda expressions
// [] - empty capture list

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age):name(name), age(age)
    {}
    Person(const Person &p): name(p.name), age(p.age)
    {}
    ~Person() = default;
    
    std::string get_name() const {
        return this->name;
    }
    void set_name(std::string name) {
        this->name = name;
    }

    int get_age() {
        return this->age;
    }
    void set_age(int age) {
        this->age = age;
    }
};
std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os<<"[Person: "<<rhs.name<<": "<<rhs.age<<"]";
    return os;
}

void test01() {
    
}

int main() {




    return 0;
}