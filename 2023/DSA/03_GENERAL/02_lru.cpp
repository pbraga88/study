#include <iostream>
#include <list>
#include <unordered_map>

template <typename T>
class LRU{
    int capacity = 10;
    std::list<std::pair<T, T>> dll; // Doubly Linked List
    // std::unordered_map<T, std::list<std::pair<T, T>>::iterator> cache;
    using ListIterator = typename std::list<std::pair<T, T>>::iterator;
    std::unordered_map<T, ListIterator> cache;

public:
    LRU(){}
    LRU(int cap):capacity(cap){}
    ~LRU(){}

    void set(T key, T value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            dll.splice(dll.begin(), dll, cache[key]); // Move the accessed Node to the front of list
            return;
        }

        if(dll.size()>=capacity) {
            T lastKey = dll.back().first;
            dll.pop_back();
            cache.erase(lastKey);
        }
        dll.emplace_front(std::make_pair(key, value));
        cache[key] = dll.begin();
    }

    T get(T key) {
        if(cache.find(key)!=cache.end()) {
            dll.splice(dll.begin(), dll, cache[key]); // Move the accessed Node to the front of list
            return cache[key]->second;
        }
        return -1;
    }

};

int main() {

    LRU<int> lru;
    lru.set(1,100);
    lru.set(2,200);

    std::cout<<lru.get(1)<<std::endl;
    std::cout<<lru.get(2)<<std::endl;

    lru.set(4,400);
    std::cout<<lru.get(1)<<std::endl;
    std::cout<<lru.get(4)<<std::endl;

    return 0;
}