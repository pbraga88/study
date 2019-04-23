#pragma once
#include <iostream>

class tempStat
{
	public:
		double minimum, maximum;

		tempStat(double min = 0.0, double max = 0.0)
			: minimum(min), maximum(max)
		{}

		void write(std::ostream & os)
		{
			os.write((char*)&minimum, sizeof(double));
			os.write((char*)&maximum, sizeof(double));
		}

		void read(std::istream & is)
		{
			is.read((char*)&minimum, sizeof(double));
			is.read((char*)&maximum, sizeof(double));
		}
};

// std::ostream& operator << (std::ostream & os, const tempStat & ts);
// std::istream& operator >> (std::istream& is, tempStat & ts);

std::istream& operator >> (std::istream& is, tempStat & ts)
{
    is >> ts.minimum >> ts.maximum;
    return is;
}

std::ostream& operator << (std::ostream & os, const tempStat & ts)
{
    os << ts.minimum << "," << ts.maximum << std::endl;
    return os;
}