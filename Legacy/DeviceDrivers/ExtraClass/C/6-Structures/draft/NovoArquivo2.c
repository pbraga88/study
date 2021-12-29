#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int main(){
	int var = 10;
	int *pvar = &var;
	
	printf("%i",  *pvar);
	
	return 0;
}