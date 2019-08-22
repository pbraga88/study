#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_LEN 64

struct student {
	char name[BUF_LEN];
	char lastName[BUF_LEN];
	int age;
	double grade;
};

void printStructure(struct student estudante);

int main(){

	struct student me = {
		"Paulo", 
		"Braga", 
		30, 
		9.8};
	printStructure(me);

	struct student you;
	strcpy(you.name, "Maria");
	strcpy(you.lastName, "Joao");
	you.age = 40;
	you.grade = 10.0;
	printStructure(you);

	return 0;
}

void printStructure(struct student estudante) {
	printf("%s %s %d %.2f\n", estudante.name, estudante.lastName, estudante.age, estudante.grade);
}