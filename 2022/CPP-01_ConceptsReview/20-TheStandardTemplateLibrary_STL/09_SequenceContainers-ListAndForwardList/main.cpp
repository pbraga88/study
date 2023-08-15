// List: Doubly Linked List
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name {"Unknown"}, age{0} {}
    Person(std::string name, int age) : name{name}, age{age}{}

    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os<<p.name<<": "<<p.age;
    return os;
}

template <typename T>
void display(const std::list<T> &lista) {
    std::cout<<"[ ";
    for (const auto &elem:lista) {
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1() {
    std::cout<<"=============== Test 01 ==============="<<std::endl;

    std::list<int> lista1 {1,2,3,4,5};
    display(lista1);

    std::list<std::string> lista2;
    lista2.push_back("back");
    lista2.push_front("front");
    display(lista2);

    std::list<int> lista3;
    lista3 = {1,2,3,4,5,6,7,8,9,10};
    display(lista3);

    std::list<int> lista4 (10,100); // 10x 100
    display(lista4);
}

void test2() {
    std::cout<<"=============== Test 02 ==============="<<std::endl;
    std::list<int> lista1 {1,2,3,4,5,6,7,8,9,10};
    display(lista1);
    std::cout<<"Size: "<<lista1.size()<<std::endl;

    std::cout<<"Front: "<<lista1.front()<<std::endl;
    std::cout<<"Back: "<<lista1.back()<<std::endl;

    lista1.clear();
    display(lista1);
    std::cout<<"Size: "<<lista1.size()<<std::endl;
}

void test3() {
    std::cout<<"=============== Test 03 ==============="<<std::endl;
    std::list<int> lista1 {1,2,3,4,5,6,7,8,10};
    display(lista1);
    
    lista1.resize(5);
    display(lista1);

    lista1.resize(10);
    display(lista1);

    std::list<Person> persons;
    persons.resize(5);
    display(persons);
}

void test4() {
    std::cout<<"=============== Test 04 ==============="<<std::endl;

    std::list<int> lista1 {1,2,3,4,5,6,7,8,9,10};
    display(lista1);
    auto it = std::find(lista1.begin(), lista1.end(), 5);
    std::cout<<"*it= "<<*it<<std::endl; // points to '5'
    if (it != lista1.end()) {
        lista1.insert(it, 100); // Inserts '100' before '5'
    }
    display(lista1);
    std::cout<<"*it= "<<*it<<std::endl;

    std::list<int> lista2 {1000, 2000, 3000};
    lista1.insert(it, lista2.begin(), lista2.end()); // Insert the whole lista2 into lista1 at iterator it position
    display(lista1);

    std::cout<<"*it= "<<*it<<std::endl;
    std::advance(it, -4); // Move the iterator 4 positions backwards
    std::cout<<"*it= "<<*it<<std::endl; // Iterator now points to '100'

    lista1.erase(it);
    display(lista1);
}

void test5() {
    std::cout<<"=============== Test 05 ==============="<<std::endl;

    std::list<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };

    display(stooges);
    std::string name;
    int age {};
    std::cout<<"\nEnter the name of the next stooge: ";
    std::cin>>name;
    std::cout<<"\nEnter his age: ";
    std::cin>>age;

    stooges.emplace_back(name, age);
    display(stooges);

    // Insert Frank before Moe
    auto it = std::find(stooges.begin(), stooges.end(), Person("Moe", 25));
    if (it != stooges.end()) {
        stooges.emplace(it, "Frank", 20);
    }
    display(stooges);
}

void test6() {
    std::cout<<"=============== Test 06 ==============="<<std::endl;
    std::list<Person> stooges {
        {"Larry", 20},
        {"Curly", 40},
        {"Moe", 30}
    };
    display(stooges);
    stooges.sort();
    display(stooges);
}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();



    return 0;
}