#include <iostream>

using namespace std;

/******************** Overloaded Functions **********************/
// int inline bigger(int x, int y, int z){
// 	return x>y ? (x>z ? x : z) : (y>z ? y : z);
// }

// inline int bigger(int x, int y){
// 	return x>y ? x : y;
// }

// int main(){
// 	int a = 10, b =13, c = 21;
// 	cout << bigger(a, b) << endl;
// 	cout << bigger(a, b, c) << endl;
// 	return 0;
// }
/**************************************************************/

/****************** Sorting Arrays ****************************/

void sorting(int *ptr, int size) {
	int i;
	bool control = true;
	int maior;

	while (control){
		control = false;
		for (i = 0; i < size-1; i++){
			if (*(ptr+i) > *(ptr+(i+1))) {
				maior = ptr[i];
				ptr[i] = ptr[i+1];
				ptr[i+1] = maior;
				control = true;
			}
		}
	}
}

// int main(){
// 	int size;
// 	int i;
// 	int array[10] = {8, 10, 6, 2, 4, 10, 90, 8, 9, 10};
// 	int *ptr = array;

// 	size = sizeof(array)/sizeof(array[0]);
// 	for(i=0; i<size; i++)
// 		cout<<array[i]<<endl;

// 	cout<<endl;

// 	sorting(ptr, size);

// 	for(i=0; i<size; i++)
// 		cout<<array[i]<<endl;

// 	return 0;
// }

/**************************************************************/

/******************** New and Delete **************************/

int main(){
	// int *arr;
	// int i;
	// int nb_qty;

	// cout << "How many numbers to sort?" << endl;
	// cin >> nb_qty;
	// arr = new int[nb_qty]; // Creating a memory block
	// cout << "insert your numbers" << endl;
	// for(i=0; i<nb_qty; i++)
	// 	cin >> arr[i];

	// for(i=0; i<nb_qty; i++)
	// 	cout << arr[i] <<" ";
	// sorting(arr, nb_qty);

	// cout<<endl;

	// for(i=0; i<nb_qty; i++)
	// 	cout << arr[i] << " ";

	// cout<<endl;

	// delete [] arr; // Deleting the memory block

	// return 0;

	cout << 1/sizeof(float)<<endl;
	return 0;
}



















