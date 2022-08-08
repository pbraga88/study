#ifndef __DOG_H__
#define __DOG_H__
#include <string>

namespace game {
    class Player {
    private:
        std::string name;
        int health;
        int xp;
    public:
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);
    };
}

#endif 
