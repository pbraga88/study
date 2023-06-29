#include <iostream>
#include <string>
#include <vector>

/* Template classes are commonly fully implemented in the header (.h),
   so no source file (.c) is needed to be written
*/

namespace generic {
    template <typename T>
    class item {
    private:
        std::string name;
        T value;
    public:
        item (std::string name, T value) : name{name}, value{value}
        {}

        std::string get_name() const{return name;}
        T get_value() const{return value;}
    };
}

template <typename T1, typename T2>
struct my_pair{
    T1 first;
    T2 second;
};

int main() {
    generic::item<int> item1 {"beans", 100};
    std::cout<<item1.get_name()<<" "<<item1.get_value()<<std::endl;
    
    generic::item<std::string> item2{"rice", "brown"};
    std::cout<<item2.get_name()<<" "<<item2.get_value()<<std::endl;

    generic::item<generic::item<int>> item3 {"beans",{"rice", 100}};
    std::cout<<item3.get_name()<<" "
             <<item3.get_value().get_name()<< " "
             <<item3.get_value().get_value()
             <<std::endl;
    
    std::cout<<"\n===================================================\n"<<std::endl;
    
    std::vector<generic::item<double>> item_vec {};
    item_vec.push_back(generic::item<double>("beans", 100.0));
    item_vec.push_back(generic::item<double>("rice", 100));
    item_vec.push_back(generic::item<double>("potato", 200));

    for (const auto &item : item_vec) {
        std::cout<<item.get_name()<<" "<<item.get_value()<<std::endl;
    }

    std::cout<<"\n===================================================\n"<<std::endl;
    my_pair<std::string, int> pair {"beans", 100};
    std::cout<<pair.first<<" "<<pair.second<<std::endl;

    my_pair<std::string, double> pair2 {"rice", 100.0};
    std::cout<<pair2.first<<" "<<pair.second<<std::endl;

    return 0;
}