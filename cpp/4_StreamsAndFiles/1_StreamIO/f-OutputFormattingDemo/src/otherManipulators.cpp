#include <iostream>
#include <iomanip>
#include "otherManipulators.h"


void otherManipulators()
{
	/* Mostra o sinal de positivo */
	int x = 10;
	std::cout<< std::showpos;
	std::cout<< x <<std::endl;
	std::cout<< std::noshowpos;
	std::cout<< x << std::endl;

	std::cout<< std::showbase;
	std::cout<< "dec:" << 64 <<std::endl;
	std::cout<<std::oct<< "oct: " << 64 << std::endl;
	std::cout<<std::hex<< "hex: " << 64 << std::endl;
	std::cout<< std::noshowbase;

	std::cout<< std::hex;
	std::cout<< "No uppercase: " << 1234 <<std::endl;
	std::cout<<std::uppercase<< "uppercase: " << 1234 <<std::endl;
	std::cout<<std::nouppercase<< "No uppercase: " << 1234 <<std::endl;

}