#include <iostream>

using namespace std;

int main(){
	int vector[5] = {1, 2, 3};
	int sec_vector[5] = { 1, 0, 3, 0, 5};
	int i;
	int vector_und[] = { 0, 1, 2, 3, 4, 5, 6};
	int size = sizeof(vector_und)/sizeof(int);
	cout << size << endl;

	for(i=0; i<5; i++)
		cout << vector[i] << endl;
	cout<<endl;
	for(i=0; i<5; i++)
		cout << sec_vector[i] << endl;

	return 0;
}