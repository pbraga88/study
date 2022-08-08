#include <iostream>
#include <string>

namespace game {
    class player_friend {
        public:
            void display_friend_stats(Player &p);
    };

    class Player {
    private:
        static int number_of_players; // static data member will be visible only for the class
                                      // and can be incremented/decremented with contructor/destructor
                                      // static members can not be initialized in class declaration
        std::string name;
        int health;
        int xp; 
    public:
        static int get_number_of_players(); // static functions only have access to static members
        std::string get_name();
        int get_health();
        int get_xp();

        /*Constructor*/
        Player(std::string name, int health, int xp);
        /*Copy Constructor*/
        Player(const Player &source);
        /*Destructor*/
        ~Player();

        friend void display_player_stat(Player &p); // Friend Function: This function will access to class private members once
                                                    // it's declared within the class using the 'friend' keyword

        friend void player_friend::display_friend_stats(Player &p); // Friend class method: This declaration will make the method 
                                                                    // 'display_friend_stats' become a friend of the class, hence 
                                                                    // access to it's (Player class) private members will be granted
    };

    int Player::number_of_players {0}; // initialize static member with '0'
                                       // Note there's no need to use 'static' keyword on member definition (only when declaring it)
    int Player::get_number_of_players() {
        return number_of_players;
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

    // Constructor
    Player::Player(std::string name, int health, int xp) :
        name(name), health(health) , xp(xp) {
            number_of_players += 1;
        }
    // Copy Constructor
    Player::Player(const Player &source) : Player{source.name, source.health, source.xp} { // Delegating to constructor
    }
    
    Player::~Player() {
        number_of_players -= 1;
    }

    void display_player_stat(Player &p) { // Friend function with access to 'Player' class private members
        std::cout<<p.name<<std::endl;
        std::cout<<p.health<<std::endl;
        std::cout<<p.xp<<std::endl;
    }

    class player_friend {
        public:
            void display_friend_stats(Player &p);
    };

}

int numb_player(){
    return game::Player::get_number_of_players();
}

int main() {
    // std::cout<<numb_player()<<std::endl;
    // {
    //     game::Player p1("p1", 100, 10);
    //     std::cout<<numb_player()<<std::endl;
    //     {
    //         game::Player p2("p2", 100, 10);
    //         std::cout<<numb_player()<<std::endl;
    //     }
    //     std::cout<<numb_player()<<std::endl;
    // }
    // std::cout<<numb_player()<<std::endl;

    game::Player p1("p1", 100, 10);
    game::display_player_stat(p1);

    return 0;
}