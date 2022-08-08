#include <iostream>
#include "Player.h"

namespace game {
    Player::Player(std::string name_val, int health_val, int xp_val) :
                        name(name_val), health(health_val), xp(xp_val) {
        std::cout<<"Three args constructor"<<std::endl;
    }

}