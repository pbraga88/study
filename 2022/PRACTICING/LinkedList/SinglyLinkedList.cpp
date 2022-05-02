#include <iostream>
#include <string>

namespace LL{
typedef struct llist{
    int val;
    struct llist* next;
} ll;

ll *head = NULL, *tail = NULL, *auxPtr = NULL;

class SinglyLinkedList
{
private:
    /* data */
    int length;
    void delete_head();
    void delete_tail();
public:
    SinglyLinkedList(int nb);
    ~SinglyLinkedList();
    void append(int val);
    void prepend(int val);
    void parse();
    int delete_node(int index);
    int reverse_pointers();
    int getLength();
};

SinglyLinkedList::SinglyLinkedList(int nb):length(0)
{
    ll *class_ll = new ll;
    class_ll->val = nb;
    class_ll->next = NULL;
    head = class_ll;
    tail = head;
    length+=1;
}

SinglyLinkedList::~SinglyLinkedList()
{
    std::cout<<"Freeing Memory"<<std::endl;
    auxPtr = head;
    while (auxPtr != NULL)
    {
        head = auxPtr->next;
        delete auxPtr;
        auxPtr = head;
    }
}

void SinglyLinkedList::append(int val) {
    auxPtr = tail;
    tail = new ll;
    tail->val = val;
    tail->next = NULL;
    auxPtr->next = tail;
    length+=1;
}

void SinglyLinkedList::prepend(int val) {
    auxPtr = head;
    head = new ll;
    head->val = val;
    head->next = auxPtr;
    length+=1;
}

void SinglyLinkedList::parse() {
    auxPtr = head;
    while (auxPtr != NULL) {
        std::cout<<auxPtr->val<<" ";
        auxPtr = auxPtr->next;
    }
    std::cout<<std::endl;
}

void SinglyLinkedList::delete_head() {
    auxPtr = head->next;
    delete head;
    head = auxPtr;
    length-=1;
}
void SinglyLinkedList::delete_tail() {
    auxPtr = head;
    while (auxPtr->next != tail) {
        auxPtr = auxPtr->next;
    }
    delete tail;
    tail = new ll;
    tail = auxPtr;
    tail->next = NULL;
    length-=1;
}

int SinglyLinkedList::delete_node(int index) {
    if (index<0 || index > length-1 || length <= 1) {
        return 1; //error
    }
    if (index == 0) {
        //delete head
        delete_head();
        return 0;
    }
    if (index == length-1) {
        //delete tail
        delete_tail();
        return 0;
    }
    auxPtr = head;
    ll *auxPtr2 = NULL;
    int position {1};
    while (auxPtr != NULL) {
        if (position == index) {
            auxPtr2 = auxPtr->next;
            auxPtr->next = auxPtr2->next;
            delete auxPtr2;
            break;
        }
        auxPtr = auxPtr->next;
        position += 1;
    }
    length-=1;
    return 0;
}

int SinglyLinkedList::reverse_pointers() {
     if (length < 1) {
         return 1; // Not reversable
     }

    ll *p1, *p2, *p3=NULL;
    p1 = head;
    p2 = p1->next;
    while (p2!=NULL){
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    tail = head;
    tail->next = NULL;
    head = p1;
    return 0;
}

int SinglyLinkedList::getLength() {
    return length;
}

}
/*********************************************/

int main () {
    LL::SinglyLinkedList sll(0);
    for (int i {1}; i<=10; i++) {
        sll.append(i);
    }
    sll.parse();

    std::cout<<"length: "<<sll.getLength()<<std::endl;

    // sll.delete_node(sll.getLength()-1);
    if (sll.delete_node(5)) {
        std::cout<<"Pleas, enter with index between 0 and "<<sll.getLength()-1<<std::endl;
    }
    sll.parse();
    std::cout<<"length: "<<sll.getLength()<<std::endl;

    if (sll.reverse_pointers()){
        std::cout<<"Not reversable"<<std::endl;
    }
    sll.parse();

    return 0;
}