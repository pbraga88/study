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
      this->length += 1;
    }
    ~LL() {
      std::cout<<"Freeing Linked List"<<std::endl;
      LinkedList *auxPtr = head;
      while(auxPtr != NULL) {
        head = auxPtr->next;
        delete auxPtr;
        auxPtr = head;
      }
    }

    void append(int val) {
      LinkedList *auxPtr = tail;
      tail = new LinkedList;
      tail->value = val;
      tail->next = NULL;
      auxPtr->next = tail;
      this->length += 1;
    }

    void prepend(int val) {
      LinkedList *auxPtr= head;
      head = new LinkedList;
      head->value = val;
      head->next = auxPtr;
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

      LinkedList *auxPtr = head, *insertionPtr;
      int count = 1;
      while (auxPtr->next != NULL) {
        if(index == count) {
          insertionPtr = auxPtr->next;
          auxPtr->next = new LinkedList;
          auxPtr->next->value = val;
          auxPtr->next->next = insertionPtr;
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
      LinkedList *auxPtr = head;
      while(auxPtr != NULL) {
        std::cout<<auxPtr->value<<" ";//<<std::endl;
        auxPtr = auxPtr->next;
      }
      std::cout<<std::endl;
    }

    int delete_node(int index) {
      if(index<0 || index>=length) {
        std::cout<<"Index out of range"<<std::endl;
        return 1;
      }
      
      LinkedList *auxPtr = head;
      if(index == 0) { // Delete head node and assign a new one (head + 1)
        auxPtr = head->next;
        delete head;
        head = auxPtr;
        this->length--;
        return 0;
      }

      int count {0};
      if(index == (this->length - 1)) { // Delete tail and assign a new one (tail - 1)
        while(auxPtr != NULL) {
          if(count == index-1) {
            delete auxPtr->next;
            tail = auxPtr;
            tail->next = NULL;
            this->length--;
            return 0;
          }
          auxPtr = auxPtr->next;
          count+=1;
        }
      }

      LinkedList *auxDelPtr;
      while(auxPtr != NULL) {
        if(count == index-1){
          auxDelPtr = auxPtr->next->next;
          delete auxPtr->next;
          auxPtr->next = auxDelPtr;
          length--;
          return 0;
        }
        auxPtr = auxPtr->next;
        count+=1;
      }

      return 1;
    }

    void reverse() {
      LinkedList *auxPtr = head;
      this->prepend(head->value);
      LinkedList *newTail = head, *delAuxPtr;
      while(auxPtr != NULL) {
        delAuxPtr = auxPtr->next;
        delete auxPtr;
        if (delAuxPtr == NULL) {break;}
        this->prepend(delAuxPtr->value);
        auxPtr = delAuxPtr;
      }
      tail = newTail;
      tail->next = NULL;
    }

    int reverse_pointers() {
      if (head == NULL) {
        return 1; // error
      }

      if (head->next == NULL) {
        return 0; // 1 member only
      }

      tail=head;
      LinkedList* auxPtr = head;
      LinkedList* auxSec = auxPtr->next, *auxTh = NULL; 
      while (auxSec != NULL) {
        auxTh = auxSec->next;
        auxSec->next = auxPtr;
        auxPtr = auxSec;
        auxSec = auxTh;
      }
      head = auxPtr;
      tail->next = NULL;

      return 0;
    }

    int get_lentgh() {
      return this->length;
    }

  private:
    typedef struct llist{
      int value;
      struct llist *next;
    } LinkedList;

    LinkedList *head, *tail;
    int length {0};
};

int main(int argc, char** argv) {
  if(argc != 2){
    std::cout<<"Please enter (only) one index"<<std::endl;
    return 1;
  }
  int index = atoi(argv[1]);
  
  LL my_list(0);
  
  for(int i = 0; i<10; i++) {
    my_list.append(i+1);
  }

  // for(int i = 0; i<=10; i++) {
  //   my_list.prepend(i);
  // }

  my_list.insert(index, 1000);

  my_list.parse();
  // my_list.reverse();

  if(my_list.reverse_pointers()) {
    std::cout<<"Error"<<std::endl;
  }
  my_list.parse();

  // std::cout<<"Linked List length = "<<my_list.get_lentgh()<<std::endl;

  // my_list.delete_node(5);

  // my_list.parse();

  // std::cout<<"Linked List length = "<<my_list.get_lentgh()<<std::endl;

  return 0;
}