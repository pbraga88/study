#include <iostream>
#include <string>

#include "Player.h"

int main() {
    game::Player p1;
    game::Player p2("player_2");
    game::Player p3("player_3", 100, 1);
    
    return 0;
}