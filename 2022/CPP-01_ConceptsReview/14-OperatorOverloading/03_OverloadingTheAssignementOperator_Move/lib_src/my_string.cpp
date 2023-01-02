#include <iostream>
#include <cstring>
#include "my_string.h"

// Constructor
Mystring::Mystring() : str(nullptr) {
    std::cout<<"Standard Constructor"<<std::endl;
    str = new char[1];
    *str = '\0';
}

// Overloaded Constructor
Mystring::Mystring(const char *s) : str(nullptr) {
    std::cout<<"Overloaded Constructor"<<std::endl;
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

// Overloaded Copy Assignment Operator (=)
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout<<"Overloaded Copy Assignment Operator (=)"<<std::endl;
    if (this == &rhs) { // Check self-assignment: 
                        //    If current object address == rhs 
        return *this;   //   return reference for current object 
                        //   (which is same address as rhs Mystring object)
    }
    delete [] this->str; // Delete whatever is there in current object str
    str = new char[std::strlen(rhs.str) + 1]; // Allocate the length of 
                                              // "rhs.str + 1" for null-terminator character
    std::strcpy(this->str, rhs.str);
    return *this; // Return a reference to current object
}

// Overloaded Move Assignment Operator (=)
Mystring &Mystring::operator=(Mystring &&rhs){
    std::cout<<"Overloaded Move Assignment Operator (=)"<<std::endl;
    if (this == &rhs) { // Check self-assignment: 
                        //    If current object address == rhs 
        return *this;   //   return reference for current object 
                        //   (which is same address as rhs Mystring object)
    }
    delete []str;   // Delete whatever is ther in current object's 'str' 
    str = rhs.str;  // Point 'str' to the right-hand side string passed (rhs.str)
    rhs.str = nullptr;  // Nullify rhs.str so data won't be lost when the temporary
                        // object gets destroyed
    return *this;
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