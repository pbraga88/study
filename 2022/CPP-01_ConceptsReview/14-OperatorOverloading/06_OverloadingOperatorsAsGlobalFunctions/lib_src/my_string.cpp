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
    delete []str;   // Delete whatever is there in current object's 'str' 
    str = rhs.str;  // Point 'str' to the right-hand side string passed (rhs.str)
    rhs.str = nullptr;  // Nullify rhs.str so data won't be lost when the temporary
                        // object gets destroyed
    return *this;
}

// // Overloaded minus operator (make lowercase)
// Mystring Mystring::operator-() const {
//     char *buff = new char[std::strlen(str) + 1];
//     std::strcpy(buff, str);
//     for (size_t i = 0; i < std::strlen(buff); i++) {
//         buff[i] = std::tolower(buff[i]);
//     }
//     Mystring temp {buff};
//     delete [] buff;
//     return temp;
// }

// // Overloaded equality operator (compare)
// bool Mystring::operator==(const Mystring &rhs) const {
//     return (std::strcmp(str, rhs.str) == 0);
// }

// // Overloaded plus operator (concatenate)
// Mystring Mystring::operator+(const Mystring &rhs) const {
//     char *buff = new char [std::strlen(this->str) + std::strlen(rhs.str) + 1];
//     std::strcpy(buff, this->str);
//     std::strcat(buff, rhs.str);
//     Mystring temp {buff};
//     delete [] buff;
//     return temp;
// }

void Mystring::display() const {
    std::cout<<str<<": "<<std::strlen(str)<<std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char* Mystring::get_str() const {
    return str;
}

// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Make lowercase
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp(buff);
    delete []buff;
    return temp;
}

// Concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp(buff);
    delete []buff;

    return temp;
}