#ifndef _MY_STRING_H_
#define _MY_STRING_H_

class Mystring {
    char *str;

public:
    // Constructor
    Mystring();
    // Overloaded Constructor
    Mystring(const char *s);
    // Copy Constructor
    Mystring(const Mystring &source);
    // Destructor
    ~Mystring();

    // Display method
    void display() const;
    // Get string length
    int get_length () const;
    // Get string
    const char* get_str () const;
};


#endif // _MY_STRING_H_