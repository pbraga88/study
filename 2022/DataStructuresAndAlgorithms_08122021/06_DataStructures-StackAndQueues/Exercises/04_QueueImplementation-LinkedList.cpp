#include <iostream>
#include <string>

class DoublyLL {
  public:
    DoublyLL(){
        head=NULL;
        tail=NULL;
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

    void create(int val) {
        head = new LinkedList;
        head->value = val;
        head->next = NULL;
        head->before = NULL;
        tail = head;
        this->length += 1;
    }

    void append(int val) {
      if (head == NULL) {
          this->create(val);
          return;
      }
      auxPtr = tail;
      tail = new LinkedList;
      tail->value = val;
      tail->next = NULL;
      tail->before = auxPtr;
      auxPtr->next = tail;
      this->length += 1;
    }

    void prepend(int val) {
      if (head == NULL) {
          this->create(val);
          return;
      }
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

    void delete_head() {
        auxPtr = head->next;
        delete head;
        head = auxPtr;
        head->before = NULL;
        this->length--;
        if (this->length == 0) {
            head = NULL;
            tail = NULL;
        }
    }

    void delete_tail() {
        auxPtr = tail->before;
        delete tail; 
        tail = auxPtr;
        tail->next = NULL;
        this->length--;
        if (this->length == 0) {
            head = NULL;
            tail = NULL;
        }
    }

    int delete_node(int index) {
      if(index<0 || index>=length) {
        std::cout<<"Index out of range"<<std::endl;
        return 1;
      }
      
      if(index == 0) { // Delete head node and assign a new one (head + 1)
        delete_head();
        return 0;
      }

      
      if(index == (this->length - 1)) { // Delete tail and assign a new one (tail - 1)
        delete_tail();
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

  protected:
    typedef struct llist{
      int value;
      struct llist *next, *before;
    } LinkedList;

    LinkedList *head, *tail, *auxPtr;
    int length {0};
};

class Queue:DoublyLL {
    public:
        Queue(){}
        ~Queue(){}
    
        int peek() {
            return head->value;
        }
        void enqueue(int val) {
            append(val);
        }
        void dequeue(){
            delete_head();
        }
        bool is_empty() {
            return length>0 ? false : true;
        }
};
/******************** Class Definition End ********************************************/

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