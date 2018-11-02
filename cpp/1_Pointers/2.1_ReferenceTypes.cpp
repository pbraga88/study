#include <iostream>

using namespace std;

void passByRef(int &num1); // Aqui a função é chamada por referência, logo,
						   // o valor original da variável é alterado

int main()
{
	int num = 3;
	cout<<"In main()"<<endl;
	cout<<"Value of num is "<<num<<endl;
	
	passByRef(num);
	
	cout<<"Back in main and the value of num is "<< num <<endl;
	
	return 0;
}

void passByRef(int &num1) // O '&num1' vira um alias para num, ou seja '&num1 = num'
{
	cout<<"In passByRef()"<<endl;
	cout<<"Value of num1 is "<< num1 <<endl;
	
	//Alterar num1 também vai alterar num
	num1++;
	
	cout << "num1 is now " << num1 <<endl;
	
}