#include "Complex.h"

// Copy constructor
Complex::Complex(const Complex& rhs) {
    real = rhs.real;
    imag = rhs.imag;
}

double Complex::getReal() const{
    return real;
}

double Complex::getImag() const{
    return imag;
}

Complex& Complex::operator=(const Complex src) {
    this->real = src.real;
    this->imag = src.imag;
    return *this;
}

Complex& Complex::operator=(const double scalar) {
    this->real = scalar;
    return *this;
}

// Friend functions
Complex operator*(const double scalar, const Complex& rhs) {
    return Complex(scalar*rhs.getReal(), scalar*rhs.getImag());
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.getReal()*rhs.getReal() ,
                    lhs.getImag()*rhs.getReal());
}

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.getReal() + b.getReal(), 
                    a.getImag() + b.getImag());
}

Complex operator-(const Complex& a) {
    return Complex(a.getReal() * (-1), 
                    a.getImag() * (-1));
}