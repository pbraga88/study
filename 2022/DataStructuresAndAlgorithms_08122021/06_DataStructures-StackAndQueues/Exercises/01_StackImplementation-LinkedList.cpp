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
    LL(){
      head = NULL;
      tail = NULL;
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

    void create(int val) {
        head = new LinkedList;
        head->value = val;
        head->next = NULL;
        tail = head;
        this->length += 1;
    }

    void append(int val) {
      if (head == NULL) {
        create(val);
      }
      else {
        LinkedList *auxPtr = tail;
        tail = new LinkedList;
        tail->value = val;
        tail->next = NULL;
        auxPtr->next = tail;
        this->length += 1;
      }
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

    void delete_head() {
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            this->length--;
            return;
        }

        LinkedList *auxPtr = head;
        auxPtr = head->next;
        delete head;
        head = auxPtr;
        this->length--;
    }

    void delete_tail() {
        if(tail == head){
            delete_head();
            return;
        }

        int count {0};
        LinkedList *auxPtr = head;
        while(auxPtr != NULL) {
            if(count == this->length-2) {
                delete auxPtr->next;
                tail = auxPtr;
                tail->next = NULL;
                this->length--;
                return;
            }
            auxPtr = auxPtr->next;
            count+=1;
        }
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

  protected:
    typedef struct llist{
      int value;
      struct llist *next;
    } LinkedList;

    LinkedList *head, *tail;
    int length {0};
};

class Stack:LL {
    public:
        Stack(){
        }
        ~Stack(){
        }

        int peek() {
            return tail==NULL ? -1 : tail->value;
        }
        void push(int value) {
            append(value);
        }
        int pop() {
            if (tail == NULL) {
                return -1;
            }
            delete_tail();
            return 0;
        }

    private:
        int value_popped {0};
};

/******************** Class Definition End *********************/

int main(int argc, char** argv) {
    Stack my_stack;
    
    // my_stack.push(10);
    int r_val = my_stack.peek();
    // if (r_val != -1) {
    //     std::cout<<r_val<<std::endl;
    // }

    for (int i = 0; i<=10; i++) {
        my_stack.push(i);
    }

    for (int i = 0; i<20; i++) {
        r_val = my_stack.peek();
        my_stack.pop();
        if (r_val == -1) {break;}
        std::cout<<r_val<<" ";
    }
    std::cout<<std::endl;

    return 0;
}