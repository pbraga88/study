#include <iostream>
#include <string>

class Player{
    public:
        int get_age(){
            return age;
        }
        std::string get_name() {
            return name;
        }

    private:
        friend class Auxiliar; // Give rights to 'Auxiliar' to access private/public members of 'Player' class
        std::string name;
        int age;
};

class Auxiliar{
    public:
        void set_age(Player &p, int n) {
            p.age = n;
        }
        void set_name(Player &p, std::string name) {
            p.name = name;
        }
};

int main() {
    Player p;
    Auxiliar aux;
    aux.set_name(p, "Paulo");
    aux.set_age(p, 33);

    std::cout<<p.get_name()<<std::endl;
    std::cout<<p.get_age()<<std::endl;

    return 0;
}