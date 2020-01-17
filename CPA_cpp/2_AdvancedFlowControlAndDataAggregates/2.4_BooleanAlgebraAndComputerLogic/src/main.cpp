#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	/*****Conjunction and Disjuction*****/
	// int i = 1;
	// int j = 0;
	// int log = i && j;
	// cout << log << endl;
	/************************************/

	/*****Bitmask*****/
	// int FlagRegister = 2578; //‭ 00000000 00000000 00001010 00010010‬
	// int mask = 8; 		     // 00000000 00000000 00000000 00001000
	// int i;
	// if(FlagRegister & mask)
	// 	cout<<"bit 3 is set"<<endl;
	// else
	// 	cout<<"bit 3 is not set"<<endl;
	
	// // set bit 3
	// FlagRegister |= mask; // 00000000 00000000 0000‭1010 00011010‬
	// if(FlagRegister & mask)
	// 	cout<<"bit 3 is set"<<endl;
	// else
	// 	cout<<"bit 3 is not set"<<endl;

	// // reset bit 3
	// FlagRegister &= ~mask; // 00000000 00000000 00001010 00010010‬
	// if(FlagRegister & mask)
	// 	cout<<"bit 3 is set"<<endl;
	// else
	// 	cout<<"bit 3 is reseted"<<endl;	

	// // invertendo os bits com operação XOR
	// for (i=0; i<10; i++){
	// 	FlagRegister ^= mask;
	// 	cout << "flip: " << setbase(16) << FlagRegister <<endl; 
	// }
	/************************************/

	/*****Shifting*****/
	int varSigned = 8;
	varSigned <<= 2;// varSigned = 32. Equivalente a multiplicação por 4
	cout << varSigned << endl;
	varSigned >>= 3;// varSigned = 4. Equivalente a divisão por 8
	cout << varSigned << endl;
	/************************************/

	return 0;
}
