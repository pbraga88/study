#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
//#define NKEYS 11
#define NKEYS (sizeof keytab / sizeof(struct key))// O n�mero de keywords � a quantidade(tamanho total) de objetos da 
                                                   // keytab dividido pelo valor (tamanho total) da struct key 

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	/* ... */
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */

int main(){
	int n;
	char word[MAXWORD];
	
	while (getword(word, MAXWORD) != EOF){ 
		   if(isalpha(word[0])){ // isalpha() verifica se � letra
		   		if((n = binsearch(word, keytab, NKEYS)) >= 0){
			   		keytab[n].count++;
	  	    	  }	   
		   }
	}
	for(n = 0; n<NKEYS; n++){
		if (keytab[n].count>0){
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}	
	}
	return 0;	
}
/** binsearch: find word in tab[0]...tab[n-1]**/
int binsearch(char *word, struct key tab[],int n){
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n-1;
	while(low<=high){
		mid = (low+high)/2;
		if((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if(cond > 0)
			low = mid+1;
		else
			return mid;
			
	}
	return -1;
}

/**getword() function implementation
 get next word or character from input**/
int getword(char* word, int lim){
	int getch(void);
	void ungetch(int);
	
	int c;
	char *w = word;
	
	while(isspace(c = getch())) // ispsace() retorna '0' se n�o for espa�o e um valor >0 se for espa�o
		printf("Entered get char\n"); //DEBUG
		;
    printf("Passed loop\n");
	if(c != EOF){
		*w++ = c;
		printf("w = %s\n", w); //DEBUG
	}
	if(!isalpha(c)){
		*w = '\0'; // '\0' � igual <null>
		return c;
	}
	for(; --lim > 0; w++){
		if (!isalnum(*w = getch())){
			printf("UNGET CH !!!\n"); 
			ungetch(*w);
			break;
		}
	}
	*w = '\0'; // '\0' � igual <null>
	printf("RETURNED!!! word[0] = %i\n", word[0]);
	return word[0];
}
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
//	return (bufp > 0) ? buf[--bufp] : getchar();
	printf("bufp = %i\n", bufp);
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}