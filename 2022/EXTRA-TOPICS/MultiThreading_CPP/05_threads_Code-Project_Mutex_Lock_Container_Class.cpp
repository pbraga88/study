#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <stdarg.h>
#include <vector>

template <typename T>
class container {
    std::recursive_mutex _lock;
    std::vector<T> _elements;

public:
    void add(T element) {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        _elements.push_back(element);
    }

    void addrange(int num, ...) {
        va_list arguments;
        va_start(arguments, num);

        for (int i = 0; i < num; i++) {
            std::lock_guard<std::recursive_mutex> locker(_lock);
            add(va_arg(arguments, T));
        }
        va_end(arguments);
    }

    void dump() {
        std::lock_guard<std::recursive_mutex> locker(_lock);
        for (auto e:_elements) {
            std::cout<<e<<std::endl;
        }
    }
};

void func(container<int>& cont) {
    cont.addrange(3, rand(), rand(), rand());
    
    cont.dump();
}

int main() {
    srand((unsigned int)time(0));
    
    container<int> cont;

    std::thread t1(func, std::ref(cont));
    std::thread t2(func, std::ref(cont));
    std::thread t3(func, std::ref(cont));

    t1.join();
    t2.join();
    t3.join();

    return 0;
}