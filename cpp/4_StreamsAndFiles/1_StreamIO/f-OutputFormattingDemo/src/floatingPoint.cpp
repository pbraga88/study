#include <iostream>
#include <iomanip>
#include "floatingPoint.h"

void floatingPoint()
{
	double pi = 3.14159265358979;

	std::cout << std::fixed << pi << std::endl;
	std::cout << std::scientific << pi << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::scientific);
	std::cout << pi << std::endl;

}