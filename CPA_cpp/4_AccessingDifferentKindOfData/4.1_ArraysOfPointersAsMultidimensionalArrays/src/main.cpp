#include <iostream>
#include <string>

using namespace std;

int main(){
	int rows = 5;
	int columns = 5;
	int **array;
	array = new int* [rows];
	for(int r = 0; r < rows; r++){
	 	array[r] = new int[columns];
	 }
	 *(*(array)) = 1;
	 cout<<array[0][0]<<endl;

	 *(*(array)+2) = 2;
	 cout<<array[0][2]<<endl;

	 *(*(array+2)) = 3;
	 cout<<array[2][0]<<endl;

	 *(*(array+2)+2) = 10;
	 cout<<array[2][2]<<endl;

	return 0;
}