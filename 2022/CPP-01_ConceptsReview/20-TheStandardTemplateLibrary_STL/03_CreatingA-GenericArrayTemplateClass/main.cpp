#include <iostream>
#include <string>

template <typename T, int N>
class Array {
    int size{N};    // The 'N' must to be know at compile-time
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T,N> &arr) {
        os<<"[ ";
        for(const auto &val: arr.values) {
            os<<val<<" ";
        }
        os<<"]"<<std::endl;
        return os;
    }
public:
    Array() = default; // default constructor
    Array(T initial_val) {
        for(auto &item: values) {
            item = initial_val;
        }
    }

    void fill(T val) {
        for(auto &item:values) {
            item = val; 
        }
    }
    int get_size() const{
        return size;
    }
    // overloaded subscript ('[]') operator for easy use
    T &operator[](int index) {
        return values[index];
    }
};

int main() {
    Array<double, 5> nums(0);
    std::cout<<"The size of nums if:"<<nums.get_size()<<std::endl;
    std::cout<<nums<<std::endl;

    std::cout<<"\n===================================================\n"<<std::endl;

    nums.fill(10);
    std::cout<<nums<<std::endl;

    std::cout<<"\n===================================================\n"<<std::endl;

    nums[0] = 100;
    nums[4] = 10000;
    std::cout<<nums<<std::endl;

    std::cout<<"\n===================================================\n"<<std::endl;

    Array<int, 100> nums2;
    std::cout<<"The size of nums2 is: "<<nums2.get_size()<<std::endl;
    nums2.fill(0);
    std::cout<<nums2<<std::endl;

    std::cout<<"\n===================================================\n"<<std::endl;

    Array<std::string, 10> str_array("NA");
    std::cout<<str_array<<std::endl;
    str_array[0] = "X";
    std::cout<<str_array<<std::endl;
    str_array.fill("Y");
    std::cout<<str_array<<std::endl;

    return 0;
}