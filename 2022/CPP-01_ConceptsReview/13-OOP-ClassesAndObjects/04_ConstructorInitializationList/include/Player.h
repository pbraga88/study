#ifndef __DOG_H__
#define __DOG_H__
#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    Player() : name{"None"}, health{0}, xp{0}{
    }
    Player(std::string name_val) : name{name_val}, health{0}, xp{0}{
    }
    Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val}{
    }

};

#endif 
