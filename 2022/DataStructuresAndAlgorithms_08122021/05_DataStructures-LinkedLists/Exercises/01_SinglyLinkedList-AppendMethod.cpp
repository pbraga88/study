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

class LL {
  public:
    LL(int val){
      head = new LinkedList;
      head->value = val;
      head->next = NULL;
      tail = head;
    }

    void append(int val) {
      LinkedList *auxPtr = tail;
      tail = new LinkedList;
      tail->value = val;
      tail->next = NULL;
      auxPtr->next = tail;
    }

    void parse() {
      LinkedList *auxPtr = head;
      while(auxPtr != NULL) {
        std::cout<<auxPtr->value<<std::endl;
        auxPtr = auxPtr->next;
      }
    }

  private:
    typedef struct llist{
      int value;
      struct llist *next;
    } LinkedList;

    LinkedList *head, *tail;

};

int main() {
  LL my_list(0);

  for(int i = 0; i<10; i++) {
    my_list.append(i+1);
  }

  my_list.parse();
  return 0;
}