#include <iostream>
#include <iomanip>
#include "justification.h"

void justification()
{
	std::cout << std::left << std::setw(10) << "left" << "aligned" << std::endl;
	std::cout << std::right << std::setw(10) << "right" << "aligned" << std::endl;
	std::cout << std::internal << std::setw(10) << -123.45 << std::endl;
	std::cout << std::internal << std::setw(10) << +123.45 << std::endl;
}
