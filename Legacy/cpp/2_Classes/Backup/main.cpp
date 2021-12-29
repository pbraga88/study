#include <iostream>
#include "person.h"


using namespace std;

int main(){
	/** Cria uma instância de Person() utilizando o contructor default **/
	Person *pOne;// = new Person();
	
	/** Cria uma instância de Person utilizando o constructor que recebe dois argumentos **/
	Person *pTwo = new Person("Paulo", "Braga");

	/** Cria uma instância de Person utilizando o constructor que recebe três argumentos **/
	Person *pThree = new Person("Paulo", "Braga", 29);

	return 0;

}