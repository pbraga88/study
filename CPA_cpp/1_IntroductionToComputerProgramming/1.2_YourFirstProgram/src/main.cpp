// preprocessor (#) directive: Operations performed before compilation
// The directive "include" will add to the program the content of what file is refered. 
// In our case, the iostream header
#include <iostream>
#include <string>

// The namespace is an abstract container which holds a logical groups of blocks (entities)
// The desired namespace must be included at the top of the program, outside of any function
using namespace std;
#define BUFFER_SIZE 128

int main(void){
	// float x = 1.0/4.0;
	// int y = x;
	// int a = 0x10;//, b = 26;
	// cout << y << endl;
	// cout << a << endl;

	//float x = 1.0/4.0;
	//int i = x;
	//cout << i << endl;
/*==========================================================*/
	// char bd[7] = {0x42, 0x6f, 0x6d, 0x20, 0x64, 0x69, 0x61};
	// int i;
	// for(i = 0; i < 7; i++)
	// 	cout<<bd[i];
	// cout<<'\n';
/*==================* Convert Hexa to Char *========================================*/
	 char *hex_to_char = (char*)malloc(BUFFER_SIZE);
	 int i;

	 string mystring;
	 size_t sz;
	 int total_size; 	
	 cout<<"Enter your message in hexadecimal: "<<endl;

	 getline(cin, mystring);
	 //total_size = mystring.size();
	 //cout<<total_size<<endl;
	 hex_to_char[0] = stoi(mystring, &sz, 16);
	
	 for(i = 1; i < BUFFER_SIZE; i++){
	 	try {
	 		mystring  = mystring.substr(sz);
	 		hex_to_char[i] = stoi(mystring, &sz, 16);
			cout<<"sz = "<<sz<<endl;
	 	}
	 	catch(std::invalid_argument& ) {
	 		hex_to_char[i] = '\0';
	 		break;
	 	}
	 }

	 for(i = 0; hex_to_char[i] != '\0'; i++)
	 	cout<<hex_to_char[i];
	 cout<<endl;
/*==========================================================*/
	return 0;
}
