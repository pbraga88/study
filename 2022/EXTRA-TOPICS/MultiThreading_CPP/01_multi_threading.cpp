/*
std::thread is the thread class that represents a single thread in C++. To start a thread we simply need to create a new thread object and pass the executing 
code to be called (i.e, a callable object) into the constructor of the object. Once the object is created a new thread is launched which will execute the code 
specified in callable.
A callable can be either of the three
    * A function pointer
    * A function object
    * A lambda expression
*/

#include <iostream>
#include <thread>
#include<unistd.h>
unsigned int microsecond = 1000000;

// Dummy function
void foo(int z) {
    for (int i = 0; i < z; i++) {
        std::cout<<"Thread using function pointer as callable"<<std::endl;
        usleep(1 * microsecond);//sleeps for 1 second
    }
}

// A callable object
class thread_obj {
public:
    void operator()(int x) {
        for (int i = 0; i < x; i++) {
            std::cout<<"Thread using function object as callable"<<std::endl;
            usleep(1 * microsecond);//sleeps for 1 second
        }
    }
};

int main(){
    std::cout<<"Threads 1, 2 and 3 operating independently"<<std::endl;

    // This thread is launched by using function pointer as callable
    std::thread thread_1(foo, 3); // ('Function to Point', 'Argument')

    // This thread is launched by using function object as callable
    std::thread thread_2(thread_obj(), 3); // ('Callable object', 'Argument')

    // Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i<x ; i++) {
            std::cout<<"Thread using lambda expression as callable"<<std::endl;
            usleep(1 * microsecond);//sleeps for 1 second
        }
    };
    // This thread is launched by using lambda expression as callable
    std::thread thread_3(f, 3); // ('Lambda Expression', 'Argument')

    // Wait for the threads to finish
    // Wait for thread_1 to finish
    thread_1.join();
    // Wait for thread_2 to finish
    thread_2.join();
    // Wait for thread_3 to finish
    thread_3.join();

    // for (int i = 0; i < 10; i++) {
    //     std::cout<<"Some delay"<<std::endl;
    //     usleep(0.5 * microsecond);//sleeps for 1 second
    // }

    return 0;
}