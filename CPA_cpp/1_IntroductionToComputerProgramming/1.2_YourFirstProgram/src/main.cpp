// preprocessor (#) directive: Operations performed before compilation
// The directive "include" will add to the program the content of what file is refered. 
// In our case, the iostream header
#include <iostream>

// The namespace is an abstract container which holds a logical groups of blocks (entities)
// The desired namespace must be included at the top of the program, outside of any function
using namespace std;

int main(void){
	cout << "Hello there, my friend!" << endl;

	return 0;
}