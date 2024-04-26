#pragma once


class Complex {
public:
    Complex(){}
    ~Complex(){}

    Complex(double a , double b) : real(a), imag(b)
    {}

    Complex(const Complex& rhs);

    // Overload operator '=' passing Complex object as argument
    Complex& operator=(const Complex src);

    // Overload operator '=' passing double as argument
    Complex& operator=(const double scalar);

    // Overload operator '*' with friend function since the lhs will be a scalar
    friend Complex operator*(const double scalar, const Complex& rhs);

    //
    friend Complex operator*(const Complex& lhs, const Complex& rhs);

    friend Complex operator+(const Complex& a, const Complex& b);

    friend Complex operator-(const Complex& a);
    
    double getReal() const;
    double getImag() const;

private:
    double real {0};
    double imag {0};
};