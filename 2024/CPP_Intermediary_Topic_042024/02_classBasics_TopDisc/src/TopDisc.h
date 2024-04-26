//
// TopDisc.h
//
#include <string>
class TopDisc{
    std::string description {};
    int identifier = 0;
public:
    TopDisc();
    TopDisc(std::string desc, int ident);
    TopDisc(const TopDisc& td);

    int getId();
    std::string Read();
    void copyContentFrom(TopDisc td);
    void Write(std::string desc, int ident=0);
    // ~TopDisc();
};

// Declare the TopDisc class in here, 
// for the required member functions: see the main function.
