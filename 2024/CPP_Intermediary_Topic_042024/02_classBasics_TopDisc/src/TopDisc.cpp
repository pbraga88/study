//
// TopDisc.cpp
//


#include "TopDisc.h"

TopDisc::TopDisc() {
}

TopDisc::TopDisc(std::string desc, int ident) : description(desc) , identifier(ident){
};

int TopDisc::getId(){
    return this->identifier;
}
std::string TopDisc::Read() {
    return this->description;
}

TopDisc::TopDisc(const TopDisc& td) {
    this->identifier = td.identifier;
    this->description = td.description;
}


void TopDisc::copyContentFrom(TopDisc td){
    this->identifier = td.identifier;
    this->description = td.description;
}

void TopDisc::Write(std::string desc, int ident) {
    this->description = desc;
    this->identifier = ident;
}
// Implement the functions as defined in the TopDisc class