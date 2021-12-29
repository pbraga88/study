#include <sstream>// For std::stringstream.
#include <string> // For std::string.
#include <iostream> // For std::cout etc. 
#include <fstream>

int main()
{
	int total;

	/* Get current Total */
	std::ifstream ifile("donation_total.txt");
	if(ifile.is_open())
	{
		std::string line;
		while(std::getline(ifile, line))
		{			
			total = std::stoi(line);
			std::cout<<"Current Total: "<< total << std::endl;
		}
		ifile.close();
	}
	else
	{
		std::cerr << "Could not open File"<< std::endl;
		return 1;
	}

	std::string donation;
	std::getline(std::cin, donation);

	std::stringstream getDonation(donation);
	std::string name;
	int amount;

	getDonation >> name >> amount;

	std::ofstream ofile("donation_total.txt");
	if(ofile.is_open())
	{
		ofile<<amount+total<<std::endl;
	}

	std::cout << "Name: " << name << std::endl << "Amount: " << amount << std::endl;

	return 0;
}