#include <iostream>

namespace game {
    class Player {
    private:
        std::string name;
        int health;
        int xp;
    public:
        // Constructor with default parameters
        Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

        /* COPY Constructor Declaration*/
        Player(const Player &source);

        std::string get_name() const; // const qualifier implemented, so const objects can be used as well 
        void set_name(std::string name);
        int get_health();
        int get_xp();
    };

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

    std::string Player::get_name() const{
        return name;
    }
    
    void Player::set_name(std::string name) {
        this->name = name;
    }

    int Player::get_health() {
        return health;
    }

    int Player::get_xp() {
        return xp;
    }

}

int main() {
    const game::Player p1 {"Paulo", 100, 100};
    std::cout<<p1.get_name()<<std::endl;


    return 0;
}