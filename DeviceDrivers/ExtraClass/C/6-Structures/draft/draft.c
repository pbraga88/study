#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define XMIN 0
#define YMIN 0

#define XMAX 1920
#define YMAX 1080

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

int main(){
	/*
	int a=10;
	int b=11;
	printf("%i", min(a,b));*/
	
	/* char var='\0'; // '\0' é igual a <null>
	printf("%s", var);*/
	
/*	char c;
	c = getchar();
	printf("Caracter: " );
	putchar(c);*/
	
	/*char *a,*b;
	a = "a";
	b = "a";
	printf("%i\n", strcmp(a,b));*/
	
	//printf("%i", EOF);
	/*
	int ret;
	char *a;
	a='1';
	ret = isspace(a);
	printf("%i\n", ret);
	*/

	int num = 10;
	int n = 2;
	char buffer[num];
	buffer[0]='a';
	buffer[1]='b';
	buffer[2]='c';
	buffer[3]='d';
	//num--;
	printf("%c\n", buffer[++n]);
	printf("%i\n", n);
	return 0;
}