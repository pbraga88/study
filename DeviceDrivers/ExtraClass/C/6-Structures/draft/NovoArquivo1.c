#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
//#define NKEYS 11
#define NKEYS (sizeof keytab / sizeof(struct key))// O número de keywords é a quantidade(tamanho total) de objetos da 
                                                   // keytab dividido pelo valor (tamanho total) da struct key 

int main(){
	int ret;
	char prim[10];
	char sec[10];
	
	prim[0] = 'a';
	sec[0] = 'b';
	
	prim[1] = '\0';
	sec[1] = '\0';
	
	ret = strcmp(prim, sec);
	printf("%i", ret);
	
}