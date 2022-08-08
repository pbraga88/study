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
        // Constructor with default parameters
        Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

        /* COPY Constructor Declaration*/
        Player(const Player &source); /* const is used since no changes to source constructor shall be made */
        /* A compiler generated default Copy Constructor is used, when nothing is defined by the user */

        std::string get_name();
        int get_health();
        int get_xp();
    };
}

#endif 
