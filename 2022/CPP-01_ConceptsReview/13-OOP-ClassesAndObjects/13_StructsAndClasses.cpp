#include <iostream>
#include <string>

namespace game {
    
    /* Structures can be used just the same as Classes, with the diference that, by default, all structure members are
      public */
    struct Player {
    private:
        std::string name;
        int health;
        int xp;
    public:
        Player(std::string name, int health, int xp) : 
                      name(name), health(health), xp(xp) {
        }
        std::string get_name() const{return name;}
        int get_health() const{return health;}
        int get_xp() const{return xp;}
    };
}

typedef struct someStructure{
    int a;
    someStructure* next;
} sm;

int main() {
    sm *ptr = new someStructure;
    ptr->a = 10;
    ptr->next = NULL;
    while(ptr!=NULL) {
        std::cout<<ptr->a<<std::endl;
        ptr = ptr->next;
    }
    delete ptr;

    game::Player p1{"p1", 100, 10};
    std::cout<<p1.get_name()<<std::endl;

    return 0;
}
