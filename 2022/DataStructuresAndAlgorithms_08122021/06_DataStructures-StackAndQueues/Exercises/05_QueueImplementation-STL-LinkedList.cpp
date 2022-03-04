#include <iostream>
#include <list>
#include <string>

class Queue {
    public:
        Queue() {}
        ~Queue() {}
        int peek() {
            return queue_ll.front();
        }
        void enqueue(int val) {
            queue_ll.push_back(val);
            this->lentgh++;
        }
        void dequeue() {
            queue_ll.pop_front();
            this->lentgh--;
        }
        bool is_empty() {
            return (this->lentgh <= 0);
        }

    private:
        std::list<int> queue_ll;
        int lentgh {0};
};

int main() {
    Queue my_queue;
    my_queue.enqueue(10);
    my_queue.enqueue(20);

    if(!my_queue.is_empty()) {
        std::cout<<my_queue.peek()<<std::endl;
    }
    if(!my_queue.is_empty()) {
        my_queue.dequeue();
    }
    if(!my_queue.is_empty()) {
        std::cout<<my_queue.peek()<<std::endl;
    }
    return 0;
}