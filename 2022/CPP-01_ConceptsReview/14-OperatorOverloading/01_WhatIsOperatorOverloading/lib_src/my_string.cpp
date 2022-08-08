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