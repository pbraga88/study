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
	// TopDisc disc1;
	
	// // Create a non-default TopicDisc. The second argument is an identifier
	// TopDisc disc2("This is the Topic C++ course disc", 200);

	// // Show the original contents
	// std::cout << "disc 1 : id='" << disc1.getId() << "', contents='" << disc1.Read() << "'" << std::endl;
	// //output should be: "disc 1 : id='0', contents=''
	// std::cout << "disc 2 : id='" << disc2.getId() << "', contents='" << disc2.Read() << "'" << std::endl;
	// //output should be: "disc 2 : id='200', contents='This is the Topic C++ course disc'

	// // Copy the contents of disc2 to disc1
	// std::cout << "Copying disc2 to disc1" << std::endl;
	// disc1.copyContentFrom(disc2);

	// // Show the contents after copying
	// std::cout << "disc 1 : id='" << disc1.getId() << "', contents='" << disc1.Read() << "'" << std::endl;
	// //output should be: "disc 1 : id='0', contents='This is the Topic C++ course disc'
	// std::cout << "disc 2 : id='" << disc2.getId() << "', contents='" << disc2.Read() << "'" << std::endl;
	// //output should be: "disc 2 : id='200', contents='This is the Topic C++ course disc'

	// // Create disc3 with data from disc1
	// std::cout << "Creating disc3 from disc1" << std::endl;
	// TopDisc disc3(disc1);
	// // Show the contents
	// std::cout << "disc 3 : id='" << disc3.getId() << "', contents='" << disc3.Read() << "'" << std::endl;
	// //output should be: "disc 3 : id='0', contents='This is the Topic C++ course disc'


	// // Write other data to disc3
	// std::cout << "Writing other data to disc3" << std::endl;
	// disc3.Write("This is disc 3");
	// //output should be: "disc 3 : id='0', contents='This is disc 3'
	
	// // Show the contents
	// std::cout << "disc 3 : id='" << disc3.getId() << "', contents='" << disc3.Read() << "'" << std::endl;

	
	/*Extend the TopDisc exercise from lesson 2:
	Start from the ‘ClassBasics_TopDisc_iteration2’.
	- Every TopDisc has a unique identifier, also when copied - OK
	- Modify the unique identifier so that it is constant during the lifetime of the disc. - OK
	- It should be possible to specify maximum storage capacity during construction. - OK
	- It should be possible to copy TopDiscs easily, with the operator=. - OK
	- It should be possible to initialize a TopDisc with another TopDisc (copy constructor) - OK
	- Make the complete exercise ‘const correct’. - OK
	- EXTRA:
		- FIX copyContentFrom()
		- Modify write() method accordingly: Raise exception in case size to write is bigger than max_capacity
	 */

	TopDisc disc_1;
	std::cout<<disc_1.getId()<<std::endl;

	TopDisc disc_2;
	std::cout<<disc_2.getId()<<std::endl;

	TopDisc disc_3(disc_1);
	std::cout<<disc_3.getId()<<std::endl;

	TopDisc disc_4("This is a disc", 512);
	std::cout<<"Disc 4 ID:"<<disc_4.getId()<<std::endl;
	std::cout<<"Disc 4 capacity: "<<disc_4.get_capacity()<<std::endl;

	TopDisc disc_5(disc_4);
	std::cout<<"Disc 5 ID:"<<disc_5.getId()<<std::endl;
	std::cout<<"Disc 5 capacity: "<<disc_5.get_capacity()<<std::endl;
	std::cout<<"Read Disc 5: "<<disc_5.Read()<<std::endl;

	TopDisc disc_6 = disc_5;
	std::cout<<"Disc 6 ID:"<<disc_6.getId()<<std::endl;
	std::cout<<"Disc 6 capacity: "<<disc_6.get_capacity()<<std::endl;
	std::cout<<"Read Disc 6: "<<disc_6.Read()<<std::endl;

	return 0;
}


