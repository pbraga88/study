#include <iostream>
#include <string>

template <typename Tplt>
Tplt min(Tplt a, Tplt b){
    return (a<b) ? a : b;
}

template <typename T1, typename T2>
void print_only(T1 a, T2 b){
    std::cout<<a<<" and "<<b<<std::endl;
}

struct Person{
    std::string name;
    int age;
    /* Overload operator to compare and return the object with minor age*/
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os<<p.name;
    return os;
}


int main() {
    print_only<int, int>(10,100);
    print_only(10,100);

    /* Both work just the same */
    // std::cout << min(2,3) << std::endl;  
    // std::cout<<min<int>(2,3)<<std::endl;

    /* Note that, different from C, C++ allow the declaration without the use of 
    keyword struct*/
    Person p1 {"Curly", 50};
    Person p2 {"Moe", 35};
    Person p3 = min(p1, p2);
    std::cout<<p3.name<<" is younger"<<std::endl;
    print_only(p2, p1);

    return 0;
}