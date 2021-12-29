#include <iostream>

using namespace std;

int main(){
	int *ptr1, *ptr2, array[3], i;
	int size;
	ptr1 = array;
	ptr2 = ptr1;
	size = sizeof array/sizeof array[0];
	if (ptr1 == ptr2)
		cout << "ptr1 address = " << ptr1 << endl << "ptr2 address = " \
		<< ptr2 << endl;

	ptr2 = &array[size];

	for (i = 0; i < size; i++)
		*(ptr1+i) = i;

	for (i = 0; i < size; i++)
		cout << array[i] << endl;

	for (i = 0; i < size; i++) {
		cout << *(--ptr2) << endl;
		cout << "ptr2 address = " << ptr2 << endl;
		cout << "ptr2 - ptr1 = " << ptr2 - ptr1 <<endl;
	}

	if (ptr1 == ptr2)
		cout << "ptr1 address = " << ptr1 << endl << "ptr2 address = " \
		<< ptr2 << endl;
	// cout << size << endl;
	return 0;
}