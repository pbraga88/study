#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char firstName[5];
	char lastName[5];
	int birthYear;
	double aveGrade;	
} student;

void printStructure(student *estudante);

int main()
{
	student me;
	strcpy(me.firstName, "Paulo");
	strcpy(me.lastName, "Braga");
	me.birthYear = 1988;
	me.aveGrade = 10.0;

	printStructure(&me); /*Soma de todos os tipos de variáveis*/


	printf("\nSize of Structure: %lu\n", sizeof(me));

	return 0;
}

void printStructure(student *estudante)
{
	printf("First Name: %s\n", estudante->firstName);
	printf("Last Name: %s\n", estudante->lastName);
	printf("Birth Year: %d\n", estudante->birthYear);
	printf("Average Grade: %.2f\n", estudante->aveGrade);
}