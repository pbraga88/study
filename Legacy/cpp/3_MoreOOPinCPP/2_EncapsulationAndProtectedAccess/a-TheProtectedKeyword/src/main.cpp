#include <iostream>
#include "student.h"

using namespace std;

int main()
{
	//int idade;
	Student estudante;
	estudante.setAge(30);
	//idade = estudante.getAge();
	cout<<estudante.getAge()<<endl;

	return 0;
}