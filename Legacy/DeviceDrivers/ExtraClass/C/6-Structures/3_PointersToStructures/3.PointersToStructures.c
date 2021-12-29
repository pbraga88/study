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
struct key *binsearch(char *, struct key *, int);

/* Count C keywords. Pointer version */
int main(){
	
	char word[MAXWORD];
	struct key *p;

	int contador=0; //DEBUG ADD
	//while (getword(word, MAXWORD) != EOF){ 
    while (contador<5){
       getword(word, MAXWORD);
	   printf("Retorna de getword()\n");
  	   if(isalpha(word[0])) // isalpha() verifica se eh letra
	   		if ((p=binsearch(word, keytab, NKEYS)) != NULL){
				p->count++;
			    contador++;
	  	    }	
	}

	for(p = keytab; p < keytab+NKEYS; p++){
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);	
	}
	return 0;	
}
/** binsearch: find word in tab[0]...tab[n-1]**/
struct key *binsearch(char *word, struct key *tab, int n){
	int cond;
	struct key *low = &tab[0];
//	struct key *low = tab; // Means the same as the previous line, since points out to the first element of the 
						   // structure
	struct key *high = &tab[n];
	struct key *mid;

	printf("Caiu no binsearch(). word = %s\n", word); // DEBUG
	
//	printf("1st high = %i\n1st low = %i\n1st mid = %i\n\n", high, low, mid);
	while(low < high){
		mid = low + (high-low) / 2;

		printf(" high = %i\n low = %i\n mid = %i\n\n", high, low, mid);
//		printf("tab[mid]->word = %s\n", tab[mid]->word);

		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if(cond > 0)
			low = mid+1;
		else{
			printf("Retorno mid = %i \n", mid);
			return mid;
		}
	}
	printf("retornou NULL\n");
	return NULL;
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
    printf("Passed loop\n"); //DEBUG
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