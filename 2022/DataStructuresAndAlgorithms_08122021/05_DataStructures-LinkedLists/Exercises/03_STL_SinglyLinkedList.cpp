#include <iostream>
#include <iterator>
#include <forward_list>

/* Reverse using 'reverse()' method */
void reverse_simple(std::forward_list<int> linked_list){
    std::cout<<__FUNCTION__<<std::endl;
    linked_list.reverse();
    for(auto val: linked_list) {
        std::cout<<val<<" ";
    }
    std::cout<<"\n";
    std::cout<<__FUNCTION__<<std::endl;
}

void show_list(std::forward_list<int> linked_list){
    /* Loop using iterator */
    for(std::forward_list<int>::iterator it = linked_list.begin(); it!=linked_list.end(); ++it){
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
    std::forward_list <int> singly_linked_list;
    for(int i=0; i<=10; i++) {
        singly_linked_list.push_front(i);
    }

    std::forward_list<int>::iterator iter = singly_linked_list.begin();
    std::advance(iter, 2);
    singly_linked_list.insert_after(iter, 12345678);

    show_list(singly_linked_list);
    reverse_simple(singly_linked_list);


    return 0;
}