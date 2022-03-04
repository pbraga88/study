/* javascipt reference
class HashTable {
  constructor(size){
    this.data = new Array(size);
    // this.data = [];
  }

  _hash(key) {
    let hash = 0;
    for (let i =0; i < key.length; i++){
        hash = (hash + key.charCodeAt(i) * i) % this.data.length
    }
    return hash;
  }

  set(key, value) {
    let address = this._hash(key);
    if (!this.data[address]) {
      this.data[address] = [];
    }
    this.data[address].push([key, value]);
    return this.data;
  }

  get(key){
    const address = this._hash(key);
    const currentBucket = this.data[address]
    if (currentBucket) {
      for(let i = 0; i < currentBucket.length; i++){
        if(currentBucket[i][0] === key) {
          return currentBucket[i][1]
        }
      }
    }
    return undefined;
  }
}
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

/* Class */
class HashTable {
    public:
        HashTable(int sz):size(sz){
            this->myhTable = new struct hTable[size];
        }
        ~HashTable(){
            std::cout<<"bye!"<<std::endl;
            delete []myhTable;
        }
        void set(std::string, int); /* set items to hashtable, using linked list for chaining*/
        int get(std::string item); /* get items from hashtable, iterating through linked lists */
        std::vector<std::string> keys();

        /* Keeping it public for test purposes */
        int hashFunc(std::string key) {
            int hashed = 0;
            for (int i =0; i < key.length(); i++){
                // hash = (hash + key.charCodeAt(i) * i) % this.data.length
                hashed = (hashed + (int)key[i] * i) % this->size;
            }
            return hashed;
        }   

    private:
        int size {0};
        struct hTable {
            std::string item;
            int qty = 0;
            struct hTable *bucketPointer = NULL;
        } *myhTable;
        
        struct  hTable *auxPtr;
        int hash {0};
};

int HashTable::get(std::string item) {
    this->hash = hashFunc(item);
    auxPtr = &myhTable[this->hash];
    
    while (auxPtr->item != item) {
      auxPtr = auxPtr->bucketPointer;
    }

    return auxPtr->qty;
}

void HashTable::set(std::string item, int qty) {
    this->hash = hashFunc(item);

    if(myhTable[this->hash].item.empty()){
      myhTable[this->hash].item = item;
      myhTable[this->hash].qty = qty;
    }
    else{
      auxPtr = &myhTable[this->hash];
      while(auxPtr->bucketPointer != NULL){
        auxPtr = auxPtr->bucketPointer;
      }
      auxPtr->bucketPointer = new struct hTable;
      auxPtr->bucketPointer->item = item;
      auxPtr->bucketPointer->qty = qty;
    }
}

std::vector<std::string> HashTable::keys() {
  std::vector<std::string> keys_list;
  for(int i = 0; i<this->size; i++) {
    if(!(myhTable[i].item.empty())) {
      auxPtr = &myhTable[i];
      while(auxPtr != NULL) {
        keys_list.push_back(auxPtr->item);
        auxPtr = auxPtr->bucketPointer;
      }
    }
  }

  return keys_list;
}

/* class end*/

int main() {
    HashTable myHashTable(2);

    std::string fruit {"apple"};
    std::string fruit_2 {"banana"};
    std::string fruit_3 {"orange"};
    std::string fruit_4 {"lemon"};
    
    myHashTable.set(fruit, 1000);
    myHashTable.set(fruit_2, 2500);
    myHashTable.set(fruit_3, 1200);
    myHashTable.set(fruit_4, 2050);
    
    std::cout<<myHashTable.get(fruit)<<std::endl;
    std::cout<<myHashTable.get(fruit_2)<<std::endl;
    std::cout<<myHashTable.get(fruit_3)<<std::endl;
    std::cout<<myHashTable.get(fruit_4)<<std::endl;

    std::vector<std::string> key_list;
    key_list = myHashTable.keys();
    for(auto key:key_list) {
      std::cout<<key<<std::endl;
    }
    // std::cout<<fruit<<" hash:"<<myHashTable.hashFunc(fruit)<<std::endl;
    // std::cout<<fruit_2<<" hash:"<<myHashTable.hashFunc(fruit_2)<<std::endl;
    // std::cout<<fruit_3<<" hash:"<<myHashTable.hashFunc(fruit_3)<<std::endl;
    // std::cout<<fruit_4<<" hash:"<<myHashTable.hashFunc(fruit_4)<<std::endl;

    /********** TEST ONLY ****************/
    // std::vector<std::string> string_vec;
    // string_vec.push_back("first");
    // string_vec.push_back("second");
    // for(auto var:string_vec){
    //   std::cout<<var<<std::endl;
    // }
    /*************************************/    

    return 0;
}