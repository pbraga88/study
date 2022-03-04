#include <iostream>
#include <iterator>
#include <list>

/* Reverse using 'reverse()' method */
void reverse_simple(std::list<int> linked_list){
    linked_list.reverse();
    for(auto val: linked_list) {
        std::cout<<val<<" ";
    }
    std::cout<<"\n";
}

/* Reverse using 'reverse_iterator' */
void reverse_list(std::list<int> linked_list) {
    std::list<int>::reverse_iterator it_ll;
    for(it_ll = linked_list.rbegin(); it_ll != linked_list.rend(); it_ll++) {
        std::cout<<*it_ll<<" ";
    }
    std::cout<<std::endl;
}

void show_list(std::list<int> linked_list){
    /* Loop using iterator */
    for(std::list<int>::iterator it = linked_list.begin(); it!=linked_list.end(); ++it){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    /* Loop using auto ranged for */
    // for(auto val:linked_list){
    //     std::cout<<val<<" ";
    // }
    // std::cout<<std::endl;
}

int main(){
    
    std::list<int> doubly_linked_list;
    for(int i=0; i<=10; i++) {
        doubly_linked_list.push_back(i);
    }

    for(int i=100; i<=200; i+=10) {
        doubly_linked_list.push_front(i);
    }

    std::list<int>::iterator iter = doubly_linked_list.begin();
    std::advance(iter, 2);
    doubly_linked_list.insert(iter, 12345678);

    show_list(doubly_linked_list);
    reverse_list(doubly_linked_list);
    reverse_simple(doubly_linked_list);


    return 0;
}