#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
//#define NKEYS 11
#define NKEYS (sizeof keytab / sizeof(struct key))// O número de keywords é a quantidade(tamanho total) de objetos da 
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
	int contador=0;
	//while (getword(word, MAXWORD) != EOF){ 
    while (contador<NKEYS){
       getword(word, MAXWORD);
	   printf("Retorna de getword()\n");
  	   if(isalpha(word[0])){ // isalpha() verifica se é letra
	   		if((n = binsearch(word, keytab, NKEYS)) >= 0){
		   		keytab[n].count = n+1;
		   		contador++;
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
	printf("Caiu no binsearch(). word = %s\n", word); 
	
	low = 0;
	high = n-1;
	while(low<=high){
		mid = (low+high)/2;
		printf("high = %i\nlow = %i\nmid = %i\n",high, low, mid);
		printf("word = %s tab[mid].word = %s\n", word, tab[mid].word);
		if((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if(cond > 0)
			low = mid+1;
		else{
			printf("Retorno mid = %i \n", mid);
			return mid;
		}
	}
	printf("retornou -1\n");
	return -1;
}

/**getword() function implementation
 get next word or character from input**/
int getword(char* word, int lim){
	int getch(void);
	void ungetch(int);
	
	int c;
	char *w = word;
	
	while(isspace(c = getch())) // ispsace() retorna '0' se não for espaço e um valor >0 se for espaço
		;
    printf("Passed loop\n");
	if(c != EOF){
		*w++ = c;
		printf("entered c!=EOF w = %c\n", c); //DEBUG
	}
	if(!isalpha(c)){
		printf("entered !alpha\n"); //DEBUG
		*w = '\0'; // '\0' é igual <null>
		return c;
	}
	for(; --lim > 0; w++){
		if (!isalnum(*w = getch())){
			printf("calling ungetch()\n"); //DEBUG
			ungetch(*w);
			break;
		}
	}
	*w = '\0'; // '\0' é igual <null>
	printf("RETURNED!!! word[0] = %c\n", word[0]); //DEBUG
	return word[0]; // Retorna a posição [0] apenas para controle(?)
}
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
//	return (bufp > 0) ? buf[--bufp] : getchar();
	printf("Entered getch()\n"); //DEBUG
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}