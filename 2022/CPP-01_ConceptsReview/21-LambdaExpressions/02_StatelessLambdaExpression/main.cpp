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

    int get_age() const{
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
    std::cout<<"------- Test 01 -------"<<std::endl;
    // Empty capture list ([]) and no parameters given
    [] () {std::cout<<"Hello there!"<<std::endl;}(); // '()' must be used so the labda function executes

    // Empty capture list and 1 parameter given
    [] (int x) {std::cout<<x<<std::endl;}(100); // note that the parameter value is passed in '(100)'

    // Empty capture list and 2 parameters given
    [] (int x, int y) {std::cout<<x+y<<std::endl;}(100,100);
}

// Using values and references as lambda parameters
void test02() {
    std::cout<<"\n------- Test 02 -------"<<std::endl;

    auto l1 = [] () {std::cout<<"Hello there"<<std::endl;};
    l1();

    int num1 {100};
    int num2 {200};
    auto l2 = [] (int x, int y) {std::cout<<x+y<<std::endl;};
    l2(10,10);
    l2(num1, num2);

    auto l3 = [] (int &x, int y) {
        std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
        x = 1000;
        y = 2000;
    };
    l3(num1, num2);
    std::cout<<"num1: "<<num1<<" num2:"<<num2<<std::endl;
}

// Using value and objects as lambda parameters
void test3() {
    std::cout<<"\n------- Test 03 -------"<<std::endl;
    Person stooge {"Larry", 18};
    std::cout<<stooge<<std::endl;

    auto l4 = [](Person p) {
        std::cout<<p<<std::endl;
    };
    l4(stooge);

    auto l5 = [](Person &p) {
        std::cout<<p<<std::endl;
    };
    l5(stooge);

    auto l6 = [](Person &p) {
        p.set_name("Frank");
        p.set_age(25);
        std::cout<<p<<std::endl;
    };
    l6(stooge);
    std::cout<<stooge<<std::endl;
}

// Below function is used within test4()
// Using std::function as a parameter in C++14 and greater
// or
// auto as parameter type in C++20
void filter_vector(const std::vector <int> &vec, std::function <bool(int)> func) { //C++14 and greater
// void filter_vector(const std::vector <int> &vec, auto func) { //C++20
    std::cout<<"[ ";
    for (int i:vec) {
        if(func(i)) {
            std::cout<<i<<" ";
        }
    }
    std::cout<<"]"<<std::endl;
}
bool funcao(int x) {
    return x>0;
};
void test4() {
    std::cout<<"------- Test 04 -------"<<std::endl;
    std::vector<int> nums {10,20,30,40,50,60,70,80,90,100};

    // Passing a function as parameter
    filter_vector(nums, funcao);

    // Passing lambda function as parameter
    filter_vector(nums, [](int x){return x>50;});

    // filter_vector(nums, [](int x){return x<=30;});

    // filter_vector(nums, [](int x){return x>=30 && x<=60;});
}

//used for test 5
auto make_lambda() {
    return [](){std::cout<<"Using make_lambda function"<<std::endl;};
}
// Returning a lambda from a function
void test5() {
    std::cout<<"------- Test 05 -------"<<std::endl;

    auto l5 = make_lambda();

    l5();
}

// Using auto in the lambda parameter list
void test6() {
    std::cout<<"------- Test 06 -------"<<std::endl;
    
    auto l6 = [](auto x, auto y) {std::cout<<"x: "<<x<<" y: "<<y<<std::endl;};

    l6(10, 20);
    l6(100.3, 200.0);
    l6('a', 'b');
    l6(Person("Larry", 18), Person("Curly", 22));
}

// Simple lambda examples with std::sort and std::for_each
void test7() {
    std::cout<<"------- Test 07 -------"<<std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };

    // Sort it lexicographically (ascending by name) 
    std::sort(stooges.begin(), stooges.end(), [](const Person &P1, const Person &P2){
        return P1.get_name() < P2.get_name();
    });
    std::for_each(stooges.begin(), stooges.end(), [](const Person &p){std::cout<<p<<std::endl;});

    std::cout<<std::endl;

    // Sort it numerically (ascending by ages)
    std::sort(stooges.begin(), stooges.end(), [](const Person &P1, const Person &P2){
        return P1.get_age() < P2.get_age();
    });
    std::for_each(stooges.begin(), stooges.end(), [](const Person &p) {std::cout<<p<<std::endl;});
}

int main() {
    // test01();
    // test02();
    // test3();
    test4();
    // test5();
    // test6();
    // test7();

    return 0;
}