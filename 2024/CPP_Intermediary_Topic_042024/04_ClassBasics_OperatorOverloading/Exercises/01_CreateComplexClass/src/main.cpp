// Complex.cpp : Defines the entry point for the console application.
//
// exercise for class basics.
// topdisc

#include <iostream>

#include "Complex.h"
void printObj(Complexcity::Complex obj) {
	// auto get_values = obj.read_all();
	for (auto &value : obj.read_all()) {
		std::cout<<value<<" ";
	}
	std::cout<<std::endl;
}

int main(int argc, const char* argv[])
{
	(void)argc;
	(void)argv;

	const Complexcity::Complex a(1.0,2.0);//a should get the value (1.0, 2.0)
	// printObj(a);

	Complexcity::Complex b(a); //b should get the value (1./0, 2.0) & a (1.0, 2.0)
	// printObj(b);

	Complexcity::Complex c; //c should get the value (0.0, 0.0)
	// printObj(c);

	b = 2.0 * a; //b should get the value (2.0, 4.0) & a (1.0, 2.0)
	printObj(b);
	printObj(a);

	double x = 3.0;
	c = x; //c should get the value (3.0, 0.0)
	printObj(c);

	b = b * c; //b should get the value (6.0, 12.0) & c (3.0, 0.0)
	printObj(b);
	printObj(c);

	b = b + a; //b should get the value (7.0, 14.0) & a (1.0, 2.0)
	printObj(b);
	printObj(a);

	b = -b; //b should get the value (-7.0, -14.0)
	printObj(b);

	b = -c; //b should get the value (-3.0, 0.0) & c (3.0, 0.0)
	printObj(b);
	printObj(c);

	return 0;
}


