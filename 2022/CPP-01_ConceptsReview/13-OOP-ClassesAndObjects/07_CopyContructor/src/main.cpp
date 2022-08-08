#include <iostream>
#include <string>

#include "Player.h"
void print_stats(game::Player player_local) {
    std::cout<<"name: "<<player_local.get_name()<<std::endl;
    std::cout<<"health: "<<player_local.get_health()<<std::endl;
    std::cout<<"xp: "<<player_local.get_xp()<<std::endl;
}

int main() {
    // game::Player p1;
    // game::Player p1_2(p1); // Copy Contructor called

    // game::Player p2("player_2");
    game::Player p3("player_3", 100, 1);
    game::Player p3_2 {p3}; // Also Copy Constructor called (with slightly different syntax)

    /* When an object goes as a parameter in a function call, it's the 
    COPY CONSTRUCTOR which is used as well */
    print_stats(p3);
       

    return 0;
}