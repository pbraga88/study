#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>


template <typename T>
void display(const std::deque<T> &deq) {
    std::cout<<"[ ";
    for (const auto &n:deq) {
        std::cout<<n<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1() {
    std::cout<<"============= Test 01 ============="<<std::endl;
    std::deque<int> d {1,2,3,4,5};
    display(d);

    d = {2,4,5,6};
    display(d);

    std::deque<int> d1 (10,100); // 10 times 100 in the deque
    display(d1);

    d[0] = 100;
    d.at(1) = 200; // bound check
    display(d);

}

void test2() {
    // push and pop
    std::cout<<"============= Test 02 ============="<<std::endl;

    std::deque<int> d(3,0); // 0 three times
    display(d);

    d.push_back(10);
    d.push_back(20);
    display(d);

    d.push_front(100);
    d.push_front(200);
    display(d);

    std::cout<<"Front: "<<d.front()<<std::endl;
    std::cout<<"Back: "<<d.back()<<std::endl;
    std::cout<<"Size: "<<d.size()<<std::endl;

    d.pop_front();
    d.pop_back();
    display(d);
}

void test3() {
    // Insert all even number into the back of a deque and all odd numbers into the front
    std::cout<<"============= Test 03 ============="<<std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    std::deque<int> deq;

    for (const auto &numb:vec) {
        if (numb%2 == 0) {
            deq.push_back(numb);
        }
        else {
            deq.push_front(numb);
        }
    }
    display(deq);
    
}

void test4() {
    // Ordering: push front VS push back
    std::cout<<"============= Test 04 ============="<<std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> deq;

    for (const auto &elem:vec) {
        deq.push_front(elem);
    }
    display(deq);

    deq.clear();
    
    for (const auto &elem:vec) {
        deq.push_back(elem);
    }
    display(deq);
}

void test5() {
    // Same as test4, but using std::copy
    std::cout<<"============= Test 05 ============="<<std::endl;
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;

    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);

    d.clear();

    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);

}

int main() {
    // test1();
    // test2();
    // test3();
    // test4();
    test5();


    return 0;
}