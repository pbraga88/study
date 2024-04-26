//
// Complex.h
//
#pragma once
#include <vector>

namespace Complexcity {
	class Complex
	{
	public:
		Complex()
		{}
		Complex(double x, double y) : a(x), b(y)
		{}

		// // Copy constructor
		// TopDisc(const TopDisc& rhs);
		Complex(const Complex& rhs);
		// // Overload operator=
		// TopDisc& operator=(const TopDisc& rhs);
		// Complex& operator*(const Complex& rhs);
		
		// Why operator* must be a class friend when overloaded?
		// Because the multiplication involves a non-member value (scalar). If only
		// class members were involved, then it would be ok to make the overload a member
		// instead of a friend
		friend Complex operator*(const double scalar, const Complex& complex);

		// The differenc from above operator '*' overloading is that the following 
		// takes as argument to objects of type complex
		friend Complex operator*(const Complex& lhs,const Complex& rhs);
		
		//
		friend Complex operator+(Complex& lhs, const Complex& rhs);

		friend Complex operator-(const Complex& src);

		// Overload assignment operator
		Complex& operator=(const Complex& src){
			if (this != &src) {
				this->a = src.a;
				this->b = src.b;
			}
			return *this;
		}

		Complex& operator=(double scalar){
			this->a = scalar;
			return *this;
		}

		std::vector<double> read_all() const;

	private:
		double a{0.0};
		double b{0.0};
	};
}
