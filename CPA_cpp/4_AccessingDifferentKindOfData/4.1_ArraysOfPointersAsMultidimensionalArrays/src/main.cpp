#include <iostream>
#include <string>

using namespace std;

int main(){
/******Regular two dimensional array********************************/
	// int rows = 5;
	// int columns = 5;
	// int **array;
	// array = new int* [rows];
	// for(int r = 0; r < rows; r++){
	//  	array[r] = new int[columns];
	//  }
	//  *(*(array)) = 1;
	//  cout<<array[0][0]<<endl;

	//  *(*(array)+2) = 2;
	//  cout<<array[0][2]<<endl;

	//  *(*(array+2)) = 3;
	//  cout<<array[2][0]<<endl;

	//  *(*(array+2)+2) = 10;
	//  cout<<array[2][2]<<endl;

	//  *(*(array+2)+3) = 10;
	//  cout<<array[2][3]<<endl;

	//  for (int r = 0; r<rows; r++){
	//  	for (int c = 0; c<columns; c++)
	//  		cout<<*(*(array+r)+c)<< " "; // Dereferenciando os ponteiros
	//  		// cout<<array[r][c]<<" ";   // Usando notação de matriz 
	//  	cout<<endl;
	//  }

	//  // Free the array
	//  for (int r = 0; r<rows; r++)
	//  	delete []array[r]; // free linha por linha
	//  delete []array; // e finalmente, deleta a array
/*****************************************************************/

/******Triangular two dimensional array********************************/

	int rows = 5;
	int **array;
	// Alocando e inicializando a array
	array = new int*[rows];
	for(int r = 0; r<rows; r++){
		array[r] = new int[r+1];
		for (int c = 0; c <= r; c++)
			array[r][c] = (r+1)*10 + c + 1;
	}
	
	// Print
	for(int r = 0; r<rows; r++){
		for (int c = 0; c <= r; c++)
			cout<<array[r][c]<<" ";
		cout<<endl;
	}

	//Delete
	for(int r = 0; r<rows; r++)
		delete []array[r];
	delete []array;

	return 0;
}