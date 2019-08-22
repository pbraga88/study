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
/* void printStructure(struct student estudante); */

int main(){
	char *nome = "Joao";
	int i;
    /* EASY WAY*/
	struct student me = {
		"Paulo", 
		"Braga", 
		30, 
		9.8};
	printf("%s %s %d %.2f\n", me.name, me.lastName, me.age, me.grade );

	/* NOT SO EASY WAY*/
	strcpy(me.name, "Maria");
	printf("%s %s %d %.2f\n", me.name, me.lastName, me.age, me.grade );	

	/* TRICKY WAY */
	for (i = 0; i < strlen(nome); i++) {
		me.name[i] = nome[i];
	}
	me.name[i] = '\0';
	printf("%s %s %d %.2f\n",me.name, me.lastName, me.age, me.grade );

	return 0;
}