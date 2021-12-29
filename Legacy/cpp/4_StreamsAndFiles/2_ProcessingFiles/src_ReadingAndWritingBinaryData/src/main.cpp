#include <iostream>
#include <string>
#include <fstream>
#include "tempStat.h"

void updateStat(int index);
void displayStat(int index);
void displayAllStats();

int main()
{
	std::cout << "Temperature stats initially:" << std::endl;
	displayAllStats();

	int index;
	std::cout << "Which month's stats do you want to update [0 ~ 11]? ";
	std::cin >> index;

	if(index<0 || index>=12)
		std::cerr << "Invalid index." << std::endl;
	else
	{
		updateStat(index);
		displayStat(index);

		std::cout << std::endl << "Temperature stats finally:" << std::endl;
		displayAllStats();
	}

	return 0;
}

void displayAllStats()
{
	std::fstream ifile("tempStats.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::in);
	if (ifile.is_open())
	{
		int index = 0;
		while (!ifile.eof())
		{
			tempStat ts;
			ts.read(ifile);

			if(ifile.gcount() == 0)
				break;

			std::cout<<"Index ="<< index <<", tempStat: "<< ts <<std::endl;

			index++;
		}
		ifile.close();
	}
	else
		std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
}

/* Helper function, update a tempStat at a particular index*/
void updateStat(int index)
{
	tempStat ts;
	std::cout << "Enter minimim and maximum temperatures: ";
	std::cin >> ts;

	std::fstream ofile("tempStats.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::in);
	if(ofile.is_open())
	{
		ts.write(ofile, index);
		ofile.close();
	}
	else
		std::cerr << "Couldn't open tempStats.bin for writing." << std::endl;
}

/* Helper function, display a tempStat at a particular index. */
void displayStat(int index)
{
	std::fstream ifile("tempStats.bin", std::ios_base::binary | std::ios_base::out | std::ios_base::in);
	if (ifile.is_open())
	{
		tempStat ts;
		ts.read(ifile, index);
		ifile.close();
	}
	else
		std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
}




// void writetoFile()
// {
//     std::ofstream ofile("tempStats.bin", std::ios_base::binary);
//     if (ofile.is_open())
//     {
//         tempStat(-2.5, 7.5).write(ofile);
//         tempStat(0, 9.9).write(ofile);
//         tempStat(2.5, 11.0).write(ofile);
//         tempStat(5.5, 14.5).write(ofile);
//         tempStat(7.0, 17.7).write(ofile);
//         tempStat(10.5, 23.7).write(ofile);
//         tempStat(11.7, 29.5).write(ofile);
//         tempStat(7.6, 22.9).write(ofile);
//         tempStat(7.2, 21.5).write(ofile);
//         tempStat(2.0, 16.0).write(ofile);
//         tempStat(-4.7, 12.5).write(ofile);
//         tempStat(-1.9, 8.5).write(ofile);
        
//         ofile.close();
    
//         std::cout << "Finished writing binary data to tempStats.bin." << std::endl;
//     }
//     else
//     {
//         std::cerr << "Couldn't open tempStats.bin for writing." << std::endl;
//     }

// }

// void readfromFile()
// {
// 	std::ifstream ifile("tempStats.bin", std::ios_base::binary);
// 	if (ifile.is_open())
// 	{
// 	    while (!ifile.eof())
// 	    {
// 	        tempStat ts;
// 	        ts.read(ifile);

// 	        if (ifile.gcount() == 0) 
// 	        {
// 	            break;  // If no bytes read, we're done.
// 	        }

// 	        std::cout << "Read temperature stats: " << ts << std::endl;
// 	    }
// 	    ifile.close();

// 	    std::cout << "Finished reading binary data from tempStats.bin." << std::endl;
// 	}
// 	else
// 	{
// 	    std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
// 	}
// }