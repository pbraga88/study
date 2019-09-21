#include <stdio.h>
#include <string.h>

struct student {
	char firstName[30];
	char lastName[30];
	int birthYear;
	double aveGrade;
};

typedef struct {
	char *name;
	int age;
} teacher;

typedef struct {
	char name[30];
	int age;
} principal;

int main()
{
	struct student me = {"Paulo",
						 "Braga",
						 1988,
						 8.0};
	teacher professor;
	principal diretora;

	printf("Aluno\nName: %s %s\n", me.firstName, me.lastName);
	printf("Year of birth: %d\n", me.birthYear);
	printf("Average grade: %.2f\n", me.aveGrade);

	professor.name = "Joao";
	professor.age = 30;
	printf("\nProfessor\nName: %s \nIdade: %d \n", professor.name, professor.age);

	strcpy(diretora.name, "Maria");
	diretora.age = 35;
	printf("\nDiretora\nName: %s\nIdade: %d\n", diretora.name, diretora.age);


	return 0;
}