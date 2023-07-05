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

void test6() {
    std::cout<<"================ test 06 ================"<<std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);

    vec.clear(); // remove all elements
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);
    vec.erase(vec.begin(), vec.begin()+2); // remove first two elements
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    // erase all even numbers
    auto it = vec.begin();
    while (it != vec.end()) {
        if(*it % 2 == 0) {
            vec.erase(it);
        }
        else {
            it++; // Only increment if not erased
        }
        
    }
    display(vec);

}

void test7() {
    std::cout<<"================ test 07 ================"<<std::endl;
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};

    display(vec1);
    display(vec2);
    std::cout<<std::endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

void test8() {
    std::cout<<"================ test 08 ================"<<std::endl;
    std::vector<int> vec {100,45,99,1,0,5,88,74,68,33,28,49,71,13};
    display(vec);

    std::sort(vec.begin(), vec.end());
    display(vec);
    
}

void test9() {
    // std::back_inserter constructs a back-insert iterator that inserts new elements
    // at the end of the container it applied to. It's a special output iterator.
    // There is also a front_inserter to be used with deques and lists
    std::cout<<"================ test 09 ================"<<std::endl;

    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20};
    display(vec1);
    display(vec2);
    std::cout<<std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout<<std::endl;

    // copy_if element is even
    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x){return x%2==0;});
    display(vec1);
    display(vec2);
}

void test10() {
    std::cout<<"================ test 10 ================"<<std::endl;
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3;

    // 1*10, 2*20,0 3*30, 4*40, 5*50 and store in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3),
                    [](int x, int y) {return x*y;});
    display(vec3);

}

void test11() {
    std::cout<<"================ test 11 ================"<<std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};

    display(vec1);
    display(vec2);

    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()) {
        std::cout<<"Inserting..."<<std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    }
    else {
        std::cout<<"5 not found!"<<std::endl;
    }
    display(vec1);

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
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    // test10();
    test11();


    return 0;
}