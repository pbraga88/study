#include <iostream>
#include <string>
#include <vector>

// Template classes are typically completely contained in header files
// So, we would have the template class in Item.h and no Item.cpp file
// would be used
template <typename T>
class item{
    public:
        item(std::string name, T val) : name(name), value(val){
        }
    
    std::string get_name(){
        return this->name;
    }

    T get_value() {
        return this->value;
    }

    private:
        std::string name;
        T value;
};

template <typename T1, typename T2>
struct myPair{
    T1 first;
    T2 second;
};

int main() {
    /* Testing Template Class*/
    item<int> item_1 ("Paulo", 10);
    std::cout<<item_1.get_name()<<" "<<item_1.get_value()<<std::endl;

    item<std::string> item_2 ("Paulo", "Simplicio");
    std::cout<<item_2.get_name()<<" "<<item_2.get_value()<<std::endl;

    item<item<int>> item_3 {"Paulo", {"Simplicio", 10}};
    std::cout<<item_3.get_name()<<" "<<item_3.get_value().get_name()<<" "<<item_3.get_value().get_value()<<std::endl;
    
    std::cout<<"================================================="<<std::endl;
    std::vector<item<double>> vec{};
    vec.push_back(item<double>("Larry", 100.0));
    vec.push_back(item<double>("Moe", 200.0));
    vec.push_back(item<double>("Curly", 300.0));
    
    for(auto item:vec){
        std::cout<<item.get_name()<<" "<<item.get_value()<<std::endl;
    }

    return 0;
}