// Create the below linked list:
// myLinkedList = {
//   head: {
//     value: 10
//     next: {
//       value: 5
//       next: {
//         value: 16
//         next: null
//       }
//     }
//   }
// };

// class LinkedList {
//   constructor(value) {
//     this.head = {
//       value: value,
//       next: null
//     };
//     this.tail = this.head;
//     this.length = 1;
//   }
//   append(value) {
//     //Code here
//   }
// }

// let myLinkedList = new LinkedList(10);
// myLinkedList.append(5);
// myLinkedList.append(16);

#include <iostream>
#include <string>

class DoublyLL {
  public:
    DoublyLL(int val){
      head = new LinkedList;
      head->value = val;
      head->next = NULL;
      head->before = NULL;
      tail = head;
      this->length += 1;
    }
    ~DoublyLL() {
      std::cout<<"Freeing Linked List"<<std::endl;
      auxPtr = head;
      while(auxPtr != NULL) {
        head = auxPtr->next;
        delete auxPtr;
        auxPtr = head;
      }
    }

    void append(int val) {
      auxPtr = tail;
      tail = new LinkedList;
      tail->value = val;
      tail->next = NULL;
      tail->before = auxPtr;
      auxPtr->next = tail;
      this->length += 1;
    }

    void prepend(int val) {
      auxPtr= head;
      head = new LinkedList;
      head->value = val;
      head->next = auxPtr;
      head->before = NULL;
      auxPtr->before = head;
      this->length += 1;
    }

    int insert(int index, int val) {
      if(index < 0) {
        std::cout<<"Index < 0"<<std::endl;
        return 1;
      }
      if(index == 0) {
        std::cout<<"Appending to head"<<std::endl;
        this->prepend(val);
        return 0;
      }
      if (index >= length) {
        std::cout<<"Appending to tail"<<std::endl;
        this->append(val);
        return 0;
      }

      auxPtr = head;
      LinkedList *insertionAuxPtrBefore, *insertionAuxPtrNext;
      int count = 1;
      while (auxPtr->next != NULL) {
        if(index == count) {
          insertionAuxPtrBefore = auxPtr;
          insertionAuxPtrNext = auxPtr->next;
          auxPtr->next = new LinkedList;
          auxPtr->next->value = val;
          auxPtr->next->before = insertionAuxPtrBefore;
          auxPtr->next->next = insertionAuxPtrNext;
          insertionAuxPtrNext->before = auxPtr->next;
          this->length += 1;
          return 0;
        }
        auxPtr = auxPtr->next;
        count += 1;
      }
      // Insert to the end of the list
      this->append(val);

      return 0;
    }

    void parse() {
      auxPtr = head;
      while(auxPtr != NULL) {
        std::cout<<auxPtr->value<<" ";//<<std::endl;
        auxPtr = auxPtr->next;
      }
      std::cout<<std::endl;
    }
    
    void parse_backwards() {
      auxPtr = tail;
      while(auxPtr != NULL) {
        std::cout<<auxPtr->value<<" ";//<<std::endl;
        auxPtr = auxPtr->before;
      }
      std::cout<<std::endl;
    }

    int delete_node(int index) {
      if(index<0 || index>=length) {
        std::cout<<"Index out of range"<<std::endl;
        return 1;
      }
      
      if(index == 0) { // Delete head node and assign a new one (head + 1)
        auxPtr = head->next;
        delete head;
        head = auxPtr;
        head->before = NULL;
        this->length--;
        return 0;
      }

      
      if(index == (this->length - 1)) { // Delete tail and assign a new one (tail - 1)
        auxPtr = tail->before;
        delete tail; 
        tail = auxPtr;
        tail->next = NULL;
        this->length--;
        return 0;
      }

      auxPtr = head;
      LinkedList *auxDelPtr;
      int count {0};
      while(auxPtr != NULL) {
        if(count == index-1){
          auxDelPtr = auxPtr->next->next;
          delete auxPtr->next;
          auxPtr->next = auxDelPtr;
          auxDelPtr->before = auxPtr;
          this->length--;
          return 0;
        }
        auxPtr = auxPtr->next;
        count+=1;
      }

      return 1; // Error: Should not reach this point
    }

    int get_lentgh() {
      return this->length;
    }

  private:
    typedef struct llist{
      int value;
      struct llist *next, *before;
    } LinkedList;

    LinkedList *head, *tail, *auxPtr;
    int length {0};
};
/******************** Class Definition End ********************************************/

int main(int argc, char** argv) {
  if(argc != 2){
    std::cout<<"Please enter (only) one index"<<std::endl;
    return 1;
  }
  int index = atoi(argv[1]);
  
  DoublyLL my_list(0);

  for(int i = 0; i<10; i++) {
    my_list.append(i+1);
  }

  for(int i = 10; i<=20; i++) {
    my_list.prepend(i);
  }

  my_list.insert(index, 1000);

  my_list.parse();
  my_list.parse_backwards();

  std::cout<<"Linked List length = "<<my_list.get_lentgh()<<std::endl;

  my_list.delete_node(5);

  my_list.parse();
  my_list.parse_backwards();

  std::cout<<"Linked List length = "<<my_list.get_lentgh()<<std::endl;

  return 0;
}