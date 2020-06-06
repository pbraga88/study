#include <iostream>

using namespace std;


/*********Variáveis, Ponteiros e Funcções constantes********/
// const char* fun(){return "Cuidado!";}

// int main(){
// 	/*Variáveis constantes*/
// 	// int const size = 100;
// 	// int buffer[size];

// 	/*Ponteiros constante*/
// 	// int var[2] = {10, 30};
// 	// int *const ptr = var;
// 	// for (int i=0; i<2; i++)
// 	// 	cout<<*(ptr+i)<<endl;

// 	/*Ponteiro para constante*/
// 	// int var[2] = {10, 30};
// 	// const int *ptr = var;
// 	// for (int i=0; i<2; i++){
// 	// 	cout<<*ptr<<endl;
// 	// 	ptr++;
// 	// }

// 	/*Ponteiro constante com ponteiro para constante*/
// 	// int var[2] = {10, 30};
// 	// const int *const ptr = var;
// 	// for (int i=0; i<2; i++){
// 	// 	cout<<*(ptr+i)<<endl;
// 	// 	// ptr++; // Essa declaração é errada, pois o endereço do ponteiro não pode ser 
// 	// 			  // alterado.
// 	// }	

// 	/*Constant functions*/
// 	// char *str = "Hello!";
// 	// str[5] = '?'; // Esta linha irá causar um erro de segmentação (segmentation fault) 
// 				  // por que strings estilo C ficam em uma região da memória de onde 
// 				  // não se pode ler

// 	// char *str = fun(); // Conversão invalida de 'const char* fun()' para 'char* str'
// 	const char *str = fun();
// 	cout<<str<<endl;

// 	return 0;
// }
/**********************************************************/

/***********Constant class variables***********/
// class Class{
// private:
// 	const int field;
// public:
// 	Class(int n) : field(n){};
// 	Class(Class &c) : field(0){};
// 	Class(void) : field(1){};
// 	void print_field(){cout<<field<<endl;}
// };

// int main(){
// 	Class a(1);
// 	Class b(a);
// 	Class c;

// 	a.print_field();
// 	b.print_field();
// 	c.print_field();

// 	return 0;
// }

/***********Constant objects***********/
// class Class{
// public:
// 	int field;

// 	Class(int n) : field(n){};
// 	Class(Class &c) : field(0){};
// 	Class(void) : field(1){};
// 	void print_field(){cout<<field<<endl;}
// };

// int main(){
// 	Class a(1);
// 	Class b(a);
// 	const Class c; 

// 	a.print_field();
// 	b.print_field();
// 	c.print_field(); // Não é possível nada do objeto, pois ele foi declarado como 
// 					 // constante.

// 	return 0;
// }

/***********Constant member functions***********/
class Class{
public:
	int field;

	Class(int n) : field(n){};
	Class(Class &c) : field(0){};
	Class(void) : field(1){};
	void  print_field() const{
		// field++; // Causa erro, pois a classe constante não pode alterar um campo
		cout<<field<<endl;
	}
};

int main(){
	Class a(1);
	Class b(a);
	Class c; 

	a.print_field();
	b.print_field();
	// c.print_field(); // Não é possível nada do objeto, pois ele foi declarado como 
					 // constante.

	return 0;
}






