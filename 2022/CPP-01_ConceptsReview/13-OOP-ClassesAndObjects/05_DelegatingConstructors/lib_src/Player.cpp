#include <iostream>
#include "Player.h"

namespace game {
    Player::Player() : Player{"None", 0, 0} {
        std::cout<<"No args constructor"<<std::endl;
    }
    Player::Player(std::string name_val) : Player{name_val, 0, 0} {
        std::cout<<"One arg constructor"<<std::endl;
    }
    Player::Player(std::string name_val, int health_val, int xp_val) :
                        name(name_val), health(health_val), xp(xp_val) {
        std::cout<<"Three args constructor"<<std::endl;
    }

}