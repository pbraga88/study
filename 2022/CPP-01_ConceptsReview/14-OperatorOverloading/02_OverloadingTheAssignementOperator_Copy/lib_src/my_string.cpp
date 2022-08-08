#include <iostream>
#include <cstring>
#include "my_string.h"

// Constructor
Mystring::Mystring() : str(nullptr) {
    str = new char[1];
    *str = '\0';
}

// Overloaded Constructor
Mystring::Mystring(const char *s) : str(nullptr) {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy Constructor
Mystring::Mystring(const Mystring &source) : str(nullptr) {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Overloaded Copy Assignment Operator (=)
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout<<"Overloaded Copy Assignment Operator (=)"<<std::endl;
    if (this == &rhs) { // If current object address == rhs 
        return *this;   // return reference for current object 
                        // (which is same address as rhs Mystring object)
    }
    delete [] this->str; // Delete whatever is there in current object str
    str = new char[std::strlen(rhs.str) + 1]; // Allocate the length of 
                                              // "rhs.str + 1" for null-terminator character
    return *this; // Return a reference to current object
}

// Destructor
Mystring::~Mystring() {
    delete []str;
}

void Mystring::display() const {
    std::cout<<str<<": "<<std::strlen(str)<<std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char* Mystring::get_str() const {
    return str;
}