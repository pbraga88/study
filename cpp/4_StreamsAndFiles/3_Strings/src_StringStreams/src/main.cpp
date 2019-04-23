#include <iostream>
#include <sstream>
#include "tempStat.h"

int main()
{
	std::ostringstream oss(std::ios_base::binary);

	tempStat(0.1, 20.1).write(oss);
	tempStat(0.2, 20.1).write(oss);
	tempStat(0.3, 20.1).write(oss);
	tempStat(0.4, 20.1).write(oss);
	tempStat(0.5, 20.1).write(oss);
	tempStat(0.6, 20.1).write(oss);
	tempStat(0.7, 20.1).write(oss);
	tempStat(0.8, 20.1).write(oss);
	tempStat(0.9, 20.1).write(oss);
	tempStat(10.0, 20.1).write(oss);
	tempStat(10.1, 20.1).write(oss);
	tempStat(10.2, 20.1).write(oss);

	std::istringstream iss(oss.str(), std::ios_base::binary);
	while (!iss.eof())
	{

		tempStat ts;
		ts.read(iss);

		if(iss.gcount() == 0)
			break;

		std::cout << "Read Temperature stats: " << ts;
	}
}