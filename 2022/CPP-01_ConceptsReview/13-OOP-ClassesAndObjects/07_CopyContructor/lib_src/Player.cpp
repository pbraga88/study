#include <iostream>
#include "Player.h"

namespace game {
    Player::Player(std::string name_val, int health_val, int xp_val) :
                        name(name_val), health(health_val), xp(xp_val) {
        std::cout<<"Three args constructor"<<std::endl;
    }

    // COPY Constructor
    Player::Player(const Player &source) :
        // name(source.name), health(source.health), xp(source.xp){ // Using Initialization list
        Player{source.name, source.health, source.xp} { // Delegating to "main" constructor.
            std::cout<<"Copy constructor"<<std::endl;
        }

    std::string Player::get_name() {
        return name;
    }
    
    int Player::get_health() {
        return health;
    }

    int Player::get_xp() {
        return xp;
    }

}