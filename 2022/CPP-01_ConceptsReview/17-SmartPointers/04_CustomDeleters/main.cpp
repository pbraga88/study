#include <iostream>
#include <memory>

class Test {
private:
    int data;
public: 
    Test ():data{0} {
        std::cout<<"\tTest Constructor ("<<data<<")"<<std::endl;
    }
    Test (int data):data{data}{
        std::cout<<"\tTest Constructor ("<<data<<")"<<std::endl;
    }
    int get_data() {
        return data;
    }
    ~Test() {
        std::cout<<"\tTest Destructor ("<<data<<")"<<std::endl;
    }
};

void my_deleter(Test *ptr) {
    std::cout<<"\tUsing my custom function deleter"<<std::endl;
    delete ptr;
}

int main(){
    // Using function Custom Deleter
    {
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter};
    }
    std::cout<<"================================================"<<std::endl;
    // Using a Lambda Expression as Custom Deleter
    {
        std::shared_ptr<Test> ptr2 {new Test{1000}, 
        [](Test *ptr) {
            std::cout<<"\tUsing custom Lambda Expression Deleter"<<std::endl;
            delete ptr; 
        }};
        std::cout<<ptr2.get()<<std::endl;
    }

    return 0;
}