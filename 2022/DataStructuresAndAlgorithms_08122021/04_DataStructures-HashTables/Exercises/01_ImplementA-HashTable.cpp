/* javascipt reference
class HashTable {
  constructor(size){
    this.data = new Array(size);
  }

  _hash(key) {
    let hash = 0;
    for (let i =0; i < key.length; i++){
        hash = (hash + key.charCodeAt(i) * i) % this.data.length
    }
    return hash;
  }
}

const myHashTable = new HashTable(50);
myHashTable.set('grapes', 10000)
myHashTable.get('grapes')
myHashTable.set('apples', 9)
myHashTable.get('apples')
*/

#include <iostream>
#include <string>

/* Class */
class HashTable {
    public:
        HashTable(int sz){
            this->size = sz;
            this->myhTable = new struct hTable[size];
        }
        ~HashTable(){
            std::cout<<"bye!"<<std::endl;
            delete []myhTable;
        }
        void set(std::string, int);
        int get(std::string item);
        
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
            int qty;
        } *myhTable;
        int hash {0};

};

int HashTable::get(std::string item) {
    this->hash = hashFunc(item);
    return myhTable[this->hash].qty;
}

void HashTable::set(std::string item, int qty) {
    this->hash = hashFunc(item);
    myhTable[this->hash].item = item;
    myhTable[this->hash].qty = qty;
}


/* class end*/

int main() {
    HashTable myHashTable(100);
    // myHashTable.get();
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

    std::cout<<fruit<<" hash:"<<myHashTable.hashFunc(fruit)<<std::endl;
    std::cout<<fruit_2<<" hash:"<<myHashTable.hashFunc(fruit_2)<<std::endl;
    std::cout<<fruit_3<<" hash:"<<myHashTable.hashFunc(fruit_3)<<std::endl;
    std::cout<<fruit_4<<" hash:"<<myHashTable.hashFunc(fruit_4)<<std::endl;
        
    return 0;
}