#include <iostream>
#include <vector>

class Stack_A {
    public:
        Stack_A(){};
        ~Stack_A(){};

        int peek() {
            return stack_Array.back();
        }
        void push(int value) {
            stack_Array.push_back(value);
            this->length++;
        }
        void pop() {
            stack_Array.pop_back();
            this->length--;
        }
        bool is_empty() {
            return this->length>0 ? false : true;
        }

    private:
        std::vector<int> stack_Array;
        int length {0};
};

int main() {
    Stack_A my_stack;

    my_stack.push(10);
    my_stack.push(20);

    if(!my_stack.is_empty()) {
        std::cout<<my_stack.peek()<<std::endl;
    }

    if(!my_stack.is_empty()) {
        my_stack.pop();
    }
    
    if(!my_stack.is_empty()) {
        std::cout<<my_stack.peek()<<std::endl;
    }

    return 0;
}