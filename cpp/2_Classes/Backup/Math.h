// Math.h declaration
// Header file for the Math class

#pragma once // This is a preprocessor directive that tell the compiler to only include this header once, regardless
			 // of how many times it was imported in the program 

class Math{ // Here, the satic class indicates that there's no need to instantiate the class to use it in the
                   // program
	public:
		// given base and expoent, calculate value
		static int pow(int base, int exp); // In order to call a function within a static class, the function needs 
                                           // to be static too
};

