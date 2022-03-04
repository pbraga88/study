#include <iostream>
#include <stack>

int main() {
    std::stack<int> my_stack;

    /* Add to stack */
    my_stack.push(10);
    my_stack.push(20);

    /* Read latest value added */
    std::cout<<my_stack.top()<<std::endl;

    /* Remove latest value added */
    my_stack.pop();

    std::cout<<my_stack.top()<<std::endl;

    return 0;
}