#ifndef _MY_STRING_H_
#define _MY_STRING_H_

class Mystring {
    // Insertion and Extraction overoaded operators
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
    
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

    /* Unary Operators (++, --, - , !) as member methods.
    ClassName ClassName::operator-() const;
    ClassName ClassName::operator++();      // pre-increment
    ClassName ClassName::operator++(int);   // post-increment
    bool ClassName::operator!() const;
       // Note that unary operators take no input arguments
    */
//    Mystring operator-() const;  // Make lowercase

   /*Binary Operators (+, -, ==, !=, <, >, etc) as member methods
   ClassName ClassName::operator+(const ClassName &rhs) const;
   ClassName ClassName::operator-(const ClassName &rhs) const;
   bool ClassName::operator==(const ClassName &rhs) const;
   bool ClassName::operator!=(const ClassName &rhs) const;
        // Note that binary operators take the class object as argument
   */
    // Mystring operator+(const Mystring &rhs) const;  // Concatenate
    // bool operator==(const Mystring &rhs) const; // Compare

    // Display method
    void display() const;
    // Get string length
    int get_length () const;
    // Get string
    const char* get_str () const;
};


#endif // _MY_STRING_H_