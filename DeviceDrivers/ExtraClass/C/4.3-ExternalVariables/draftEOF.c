#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define SIZE 100
char buf[SIZE];

int bufp = 0;

int getch(void);
void ungetch(int);

int getch(){
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c){
	if(bufp > SIZE)
		printf("Buffer cheio, rapah!");
	else
		buf[bufp++] = c;
	printf("Chamou ungetch. Buffer: %c\n", buf[bufp-1]);
}

int getoper(char ent[]){
	int c;
	c = getch();
	return c;
}

int main(){
	int c;
	int ctrvar = 0;
	while(c != EOF){
		if(c = getch()){
		    printf("%c", c);
			Sleep(500);
			ctrvar++;		
		}
		if(ctrvar != bufp){
			ungetch(c);
			ctrvar = bufp;
		}
	}
	return 0;
}