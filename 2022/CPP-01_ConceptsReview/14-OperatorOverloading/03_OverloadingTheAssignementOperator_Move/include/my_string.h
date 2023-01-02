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

    /* Overloaded Copy Assignment Operator (=)
    Returns Mystring object by reference: 
        Mystring &
    The overloaded operator is '=': 
        operator=
    The expected argument is a right-hand side (rhs) reference to 
    constant Mystring: 
        (const Mystring &rhs)
    */
    Mystring &operator=(const Mystring &rhs);

    /* Overloaded Move Assignment Operator (=)
    Returns Mystring reference:
        Mystring &
    The overloaded operator is '=': 
        operator=
    The expected argument is a temporary Mystring r-value reference (not itialized anywhere):
        Mystring &&rhs  -> Non-const since it's going to be moved
    
    */
    Mystring &operator=(Mystring &&rhs);

    // Display method
    void display() const;
    // Get string length
    int get_length () const;
    // Get string
    const char* get_str () const;
};


#endif // _MY_STRING_H_