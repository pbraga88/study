#include <iostream>
#include "person.h"


using namespace std;

int main(){
	/** Cria uma inst�ncia de Person() utilizando o contructor default **/
	Person *pOne;// = new Person();
	
	/** Cria uma inst�ncia de Person utilizando o constructor que recebe dois argumentos **/
	Person *pTwo = new Person("Paulo", "Braga");

	/** Cria uma inst�ncia de Person utilizando o constructor que recebe tr�s argumentos **/
	Person *pThree = new Person("Paulo", "Braga", 29);

	return 0;

}