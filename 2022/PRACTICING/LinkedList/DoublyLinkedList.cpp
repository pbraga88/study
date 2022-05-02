#include <iostream>
#include <string>

namespace DLL{
typedef struct doublyll {
    int val;
    doublyll *previous;
    doublyll *next;
} dll;
dll *head, *tail, *auxPtr;

class DoublyLinkedList
{
private:
    /* data */
    int length;
    void delete_head();
    void delete_tail();
public:
    DoublyLinkedList(int val);
    ~DoublyLinkedList();
    void append(int val);
    void prepend(int val);
    void parse();
    void parseBackwards();
    int delete_node(int index);
    int insert_node(int index, int val);
    int getLength();
};

DoublyLinkedList::DoublyLinkedList(int val):length(0)
{
    dll *class_dll = new dll;
    head = class_dll;
    head->val = val;
    head->next = NULL;
    head->previous = NULL;
    tail = head;
    length += 1;
}

DoublyLinkedList::~DoublyLinkedList()
{
    std::cout<<"Freeing the linked list"<<std::endl;
    auxPtr = head;
    while (auxPtr != NULL) {
        head = auxPtr->next;
        delete auxPtr;
        auxPtr = head;
    }
}

void DoublyLinkedList::append(int val) {
    auxPtr = tail;
    tail = new dll;
    tail->val = val;
    tail->previous = auxPtr;
    tail->next = NULL;
    auxPtr->next = tail;
    length += 1;
}

void DoublyLinkedList::prepend(int val) {
    auxPtr = head;
    head = new dll;
    head->val = val;
    head->previous = NULL;
    head->next = auxPtr;
    auxPtr->previous = head;
    length += 1;
}

void DoublyLinkedList::parse() {
    auxPtr = head;
    while (auxPtr != NULL) {
        std::cout<<auxPtr->val<<" ";
        auxPtr = auxPtr->next;
    }
    std::cout<<std::endl;    
}

void DoublyLinkedList::parseBackwards() {
    auxPtr = tail;
    while (auxPtr != NULL) {
        std::cout<<auxPtr->val<<" ";
        auxPtr = auxPtr->previous;
    }
    std::cout<<std::endl;
}
void DoublyLinkedList::delete_head() {
    auxPtr = head;
    head = head->next;
    head->previous = NULL;
    delete auxPtr;
    length -= 1;
}
void DoublyLinkedList::delete_tail() {
    auxPtr = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete auxPtr;
    length -= 1;
}

int DoublyLinkedList::delete_node(int index) {
    if (index<0 || index > length-1 || length == 0) {
        return 1; //error
    }
    if (index == 0) {
        // delete head
        delete_head();
        return 0;
    }
    if (index == length-1) {
        //delete tail
        std::cout<<"Delete from tail"<<std::endl;
        delete_tail();
        return 0;
    }
    auxPtr = head;
    dll *deletionPtr = NULL;
    int position {1};
    while (auxPtr != NULL) {
        if (position == index) {
            deletionPtr = auxPtr->next;
            auxPtr->next = deletionPtr->next;
            deletionPtr->next->previous = auxPtr;
            delete deletionPtr;
            break;
        }
        auxPtr = auxPtr->next;
        position++;
    }
    length -= 1;
    return 0;
}

int DoublyLinkedList::insert_node(int index, int val) {
    if (index < 0 || index > length-1) {
        return 1; // error
    }
    if (index == 0) {
        prepend(val);
        return 0;
    }
    // if (index == length-1) {
    //     append(val);
    //     return 0;
    // }
    auxPtr = head;
    dll *insertionPtr = NULL;
    dll *newNode = NULL;
    int position {1};
    while (auxPtr != NULL) {
        if (position == index) {
            insertionPtr = auxPtr->next;
            newNode = new dll;
            newNode->val = val;
            newNode->previous = auxPtr;
            newNode->next = insertionPtr;
            auxPtr->next = newNode;
            insertionPtr->previous = newNode;
            break;
        }
        auxPtr = auxPtr->next;
        position++;
    }
    length += 1;
    return 0;
}

int DoublyLinkedList::getLength() {
    return length;
}

} // namespace end

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout<<"Please enter with linked list"<<std::endl;
        return 1;
    }
    DLL::DoublyLinkedList integers_list(0);
    
    for (int i = 1; i <= std::stoi(argv[1]); i++) {
        integers_list.append(i);
    }
    integers_list.parse();
    integers_list.parseBackwards();
    std::cout<<"length: "<<integers_list.getLength()<<std::endl;

    if (integers_list.delete_node(5)) {
        std::cout<<"Not possible to delete"<<std::endl;
    }
    integers_list.parse();
    integers_list.parseBackwards();
    std::cout<<"length: "<<integers_list.getLength()<<std::endl;

    if (integers_list.insert_node(5, 5000)) {
        std::cout<<"Not possible to insert"<<std::endl;
    }
    integers_list.parse();
    integers_list.parseBackwards();
    std::cout<<"length: "<<integers_list.getLength()<<std::endl;

    return 0;
}