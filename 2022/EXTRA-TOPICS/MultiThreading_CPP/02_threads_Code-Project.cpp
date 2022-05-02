#include <iostream>
#include <string>
#include <thread>

void func(int& a) {
    a++;
    // get thread id
    std::cout<<std::this_thread::get_id()<<std::endl;
}

int main() {
    int a = 42;
    std::thread t(func, std::ref(a)); // If the function needs argument to be passed by reference, 'std::ref' must be used
    t.join(); // With the use of 'join' the main thread will wait for the created thread to be concluded
    

    std::cout<<a<<std::endl; // a = 43
}