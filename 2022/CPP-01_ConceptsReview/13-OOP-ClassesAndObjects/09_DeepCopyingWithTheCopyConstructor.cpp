#include <iostream>

namespace deep_copy{
    class Deep{
        private:
            int *data;
        public:
            Deep(int d);
            Deep(const Deep &source);
            ~Deep();

            void set_data_value(int d) { *data = d; }
            int get_data_value() { return *data; }
    };

    Deep::Deep(int d){ // Constructor
        std::cout<<"Constructor"<<std::endl;
        data = new int;
        *data = d;
    }

    Deep::Deep(const Deep &source) : // Deep Copy Constructor
        Deep{*source.data}{ /* Delegate object creation to main constructor */
        
        /* creates new storage and copy value (used when delegation is not used) */
        // data = new int;
        // *data = *source.data;
        std::cout<<"Copy Constructor"<<std::endl;
    }

    Deep::~Deep(){
        delete data;
        std::cout<<"Destructor"<<std::endl;
    }
}

void display_deep(deep_copy::Deep s) {
    std::cout<<s.get_data_value()<<std::endl;
}


int main() {
    deep_copy::Deep obj(10);
    display_deep(obj);

    deep_copy::Deep obj2(0);
    display_deep(obj2);
    obj2.set_data_value(1000);
    display_deep(obj2);

    return 0;
}