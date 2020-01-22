#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	/******Declarando a estrutura e criando variável******/
	// struct STUDENT {
	// 	string name;
	// 	int age;
	// 	float time_per_chapter;
	// } estudante;	// já cria a variável 'estudante'
	/*****************************************************/

	/*****Apenas declarando a estrutura*****/
	// struct GENDER {
	// 	char gen;
	// };

	// struct STUDENT {
	// 	string name;
	// 	int age;
	// 	float time_per_chapter;
	// 	GENDER genero; // Declarar uma outra estrutura dentro da própria estrutura também é possível
	// };

	// /*Diferentes formas de criar a variável */
	// STUDENT estudante;
	// struct STUDENT estudante_2;

	// estudante.name = "Paulo";
	// estudante.age = 31;
	// estudante.time_per_chapter = 20.0;
	// estudante.genero.gen = 'M';

	// cout << estudante.name << endl;
	// cout << estudante.age << endl;
	// printf("%0.2f\n", estudante.time_per_chapter);
	// printf("%c\n", estudante.genero.gen);
	/*****************************************************/

	/*****Declarando sem TAG*****/
	struct {
		int dia, mes, ano;
	} data;
	printf("%d\n", sizeof(data));

	/*****************************************************/
	return 0;
}