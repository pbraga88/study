// ClassBasics_TopDisc.cpp : Defines the entry point for the console application.
//
// exercise for class basics.
// topdisc

#include <iostream>

#include "TopDisc.h"


int main(int argc, const char* argv[])
{
	(void)argc;
	(void)argv;
	// Create a default TopDisc
	TopDisc disc1;

	// Create a non-default TopicDisc. The second argument is an identifier
	TopDisc disc2("This is the Topic C++ course disc", 200);

	// Show the original contents
	std::cout << "disc 1 : id='" << disc1.getId() << "', contents='" << disc1.Read() << "'" << std::endl;
	//output should be: "disc 1 : id='0', contents=''
	std::cout << "disc 2 : id='" << disc2.getId() << "', contents='" << disc2.Read() << "'" << std::endl;
	//output should be: "disc 2 : id='200', contents='This is the Topic C++ course disc'

	// Copy the contents of disc2 to disc1
	std::cout << "Copying disc2 to disc1" << std::endl;
	disc1.copyContentFrom(disc2);

	// Show the contents after copying
	std::cout << "disc 1 : id='" << disc1.getId() << "', contents='" << disc1.Read() << "'" << std::endl;
	//output should be: "disc 1 : id='0', contents='This is the Topic C++ course disc'
	std::cout << "disc 2 : id='" << disc2.getId() << "', contents='" << disc2.Read() << "'" << std::endl;
	//output should be: "disc 2 : id='200', contents='This is the Topic C++ course disc'

	// Create disc3 with data from disc1
	std::cout << "Creating disc3 from disc1" << std::endl;
	TopDisc disc3(disc1);

	// Show the contents
	std::cout << "disc 3 : id='" << disc3.getId() << "', contents='" << disc3.Read() << "'" << std::endl;
	//output should be: "disc 3 : id='0', contents='This is the Topic C++ course disc'


	// Write other data to disc3
	std::cout << "Writing other data to disc3" << std::endl;
	disc3.Write("This is disc 3");
	//output should be: "disc 3 : id='0', contents='This is disc 3'

	// Show the contents
	std::cout << "disc 3 : id='" << disc3.getId() << "', contents='" << disc3.Read() << "'" << std::endl;

	return 0;
}

