//
// TopDisc.cpp
//
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

#include "Complex.h"


// Implement the functions as defined in the Complex class
namespace Complexcity {
	Complex::Complex(const Complex& rhs) {
		a=rhs.a;
		b=rhs.b;
	}

	// Friend function to overload operator '*'
	Complex operator*(const double scalar, const Complex& complex) { 
        return Complex(complex.a * scalar, complex.b * scalar);
    }
	
	Complex operator*(const Complex& lhs,const Complex& rhs) {
		return Complex(lhs.a*rhs.a, lhs.b*rhs.a);
	}

	Complex operator+(Complex& lhs, const Complex& rhs) {
		lhs.a += rhs.a;
		lhs.b += rhs.b;
		return lhs;
	}

	Complex operator-(const Complex& src) {
		return Complex((src.a!=0 ? src.a*(-1) : src.a),
						(src.b!=0 ? src.b*(-1) : src.b));
	}

	std::vector<double> Complex::read_all() const{
		return {a,b};
	}
}