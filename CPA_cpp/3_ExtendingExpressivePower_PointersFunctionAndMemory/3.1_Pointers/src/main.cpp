#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int add_to_var(int *ponteiro);

int main(){
	int *some_pointer = (int*)malloc(sizeof(int));
	// int *some_pointer = (int*)malloc(1024);
	printf("%p\n",(void*)some_pointer);
	cout<<fixed<<some_pointer<<endl;

	int var = 1024;
	*some_pointer = var;
	printf("%p\n",(void*)some_pointer);

	cout << *some_pointer << endl;
	cout << add_to_var(&var) << endl;
	cout << add_to_var(some_pointer) << endl;

	free(some_pointer);


	return 0;
}

int add_to_var(int *ponteiro){
	int var_to_return = 0;
	cout<<"Add 10"<<endl;
	var_to_return = *ponteiro + 10;
	return var_to_return;
}