#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int add_to_var(int *ponteiro);

int main(){
	/************Examples of pointers **************/
	// int *some_pointer = (int*)malloc(sizeof(int));
	// printf("%p\n",(void*)some_pointer);
	// cout<<fixed<<some_pointer<<endl;

	// int var = 1024;
	// *some_pointer = var;
	// printf("%p\n",(void*)some_pointer);

	// cout << *some_pointer << endl;
	// cout << add_to_var(&var) << endl;
	// cout << add_to_var(some_pointer) << endl;

	// free(some_pointer);

	// cout << sizeof var << endl;
	// cout << sizeof 10 << endl;
	// cout << sizeof(char) << endl;
	/**************************************************/

	/************Size of variables in my env **************/
    cout << "This computing environment uses:" << endl;
    cout << sizeof(char) << " bytes for chars" << endl;
    cout << sizeof(short int) << " bytes for shorts" << endl;
    cout << sizeof(int) << " bytes for ints" << endl;
    cout << sizeof(long int) << " bytes for longs" << endl;
    cout << sizeof(float) << " bytes for floats"  << endl;
    cout << sizeof(double) << " bytes for doubles"  << endl;
    cout << sizeof(bool) << " byte for bools" << endl;
    cout << sizeof(int *) << " bytes for pointers" << endl;
	/**************************************************/
	return 0;
}

int add_to_var(int *ponteiro){
	int var_to_return = 0;
	cout<<"Add 10"<<endl;
	var_to_return = *ponteiro + 10;
	return var_to_return;
}