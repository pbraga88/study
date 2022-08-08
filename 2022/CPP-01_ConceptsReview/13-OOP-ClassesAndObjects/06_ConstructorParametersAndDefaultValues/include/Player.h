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
        // Contructor with default parameters
        Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    };
}

#endif 
