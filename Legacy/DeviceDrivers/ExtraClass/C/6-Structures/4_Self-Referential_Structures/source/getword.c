#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "getword.h"

/**getword() function implementation
 get next word or character from input**/
int getword(char* word, int lim)
{
	printf("caiu em getword\n"); /*DEBUG*/
	int c;
	char *w = word;

	while(isspace(c = getch()))	/* return a true value if space and '0' if not*/
		;
	
	if(c != EOF)
		*w++ = c;

	if(!isalpha(c)){
		*w = '\0';
		return c;
	}
	for(;--lim>0; w++){
		if (!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many character");
	else
		buf[bufp++] = c;
}
