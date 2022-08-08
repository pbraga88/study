#include <iostream>
#include <string>
#include <vector>

namespace move {
    class Move{
        private:
            int *data;
        
        public:
            void set_data_value(int d){*data = d;}
            int get_data_value(){return *data;}
            // Contructor
            Move(int d);

            // Copy Constructor
            Move(const Move &source);

            //Move Constructor
            /* The move constructor will be called when an R-Value is passed
              hence the use of '&&'*/
            Move(Move &&source) noexcept; // noexcept used to no exceptions to be thrown
                                          // The noexcept operator performs a compile-time check that
                                          // returns true if an expression is declared to not throw any
                                          // exceptions

            //Destructor
            ~Move();
    };
    //Constructor
    Move::Move(int d){
        data = new int;
        *data = d;
        std::cout<<"Constructor for: "<<d<<std::endl;
    }
    //Copy Constructor
    Move::Move(const Move &source) 
        :Move {*source.data} {
        std::cout<<"Copy constructor - deep copy for:"<<*data<<std::endl;
    }
    //Move Constructor
    Move::Move( Move &&source) noexcept
    : data{source.data} {
        source.data = nullptr;
        std::cout<<"Move constructor - moving resource: "<<*data<<std::endl;
    }

    // Destructor
    Move::~Move() {
        if(data != nullptr){
            std::cout<<"Destructor freeing data for: "<<*data<<std::endl;
        }
        else {
            std::cout<<"Destructor freeing data for nullptr"<<std::endl;
        }
    }
}

int main() {
    std::vector<move::Move> vec;
    vec.push_back(move::Move{10});
    vec.push_back(move::Move{20});

    // move::Move new_obj {500};
    // vec.push_back(new_obj);

    return 0;
}