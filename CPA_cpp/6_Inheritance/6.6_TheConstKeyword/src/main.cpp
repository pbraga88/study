#include <iostream>

using namespace std;

int main(){
	/*Variáveis constantes*/
	// int const size = 100;
	// int buffer[size];

	/*Ponteiros constante*/
	// int var[2] = {10, 30};
	// int *const ptr = var;
	// for (int i=0; i<2; i++)
	// 	cout<<*(ptr+i)<<endl;

	/*Ponteiro para constante*/
	// int var[2] = {10, 30};
	// const int *ptr = var;
	// for (int i=0; i<2; i++){
	// 	cout<<*ptr<<endl;
	// 	ptr++;
	// }

	/*Ponteiro constante com ponteiro para constante*/
	int var[2] = {10, 30};
	const int *const ptr = var;
	for (int i=0; i<2; i++){
		cout<<*(ptr+i)<<endl;
		// ptr++; // Essa declaração é errada, pois o endereço do ponteiro não pode ser 
				  // alterado.
	}	


	return 0;
}