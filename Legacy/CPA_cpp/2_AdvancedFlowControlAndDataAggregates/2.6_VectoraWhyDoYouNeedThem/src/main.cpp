#include <iostream>

using namespace std;

int main(){
	/*****Array*****/
	int array[10];
	int i, sum, aux;
	int limit = sizeof(array)/sizeof(int);

	// Assign values for elements
	for (i=0; i<limit; i++)
		array[i] = i+1;
	// Print elements
	for (i=0; i<limit; i++)
		cout << array[i] << " ";
	cout << endl;
	// Sum elements
	for(i=0; i<limit; i++)
		sum+=array[i];
	cout << sum << endl;
	// Revert elements
	for (i=0; i<(limit/2); i++) {
		aux = array[i];
		array[i] = array[(limit - 1) - i];
		array[(limit - 1) - i] = aux;
	}
	// Print elements
	for (i=0; i<limit; i++)
		cout << array[i] << " ";
	cout << endl;
	/************************************/
	return 0;
}