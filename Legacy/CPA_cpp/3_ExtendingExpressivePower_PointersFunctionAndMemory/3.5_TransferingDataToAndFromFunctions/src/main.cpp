#include <iostream>
#include <stdio.h>

using namespace std;

void call_with_pointer(int *w_ptr) {
	*w_ptr += 1;
	cout << "with pointer " << w_ptr << endl;
}

void call_by_reference(int &by_ref) {
	by_ref++;
	cout << "by reference " << by_ref << endl;
}

void call_by_value(int by_value){
	by_value++;
	cout << "by value " << by_value << endl;
}

int main(){
	int var = 10;
	cout << var << endl;
	call_by_value(var);
	cout << var << endl;
	call_by_reference(var);
	cout << var << endl;
	call_with_pointer(&var);
	cout << var << endl;

	cout << var << endl;

	return 0;
}