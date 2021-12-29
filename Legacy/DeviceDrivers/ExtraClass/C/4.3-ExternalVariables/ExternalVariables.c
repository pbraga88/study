#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

/* getch() and ungetch() implementation*/
char buf[BUFSIZE]; /* buffer ungetch */
int bufp = 0; /* next free position in buf */

int getch(void){ /* get a possibly pushed-back character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}
ungetch(int c){
	if(bufp > BUFSIZE)
		printf("ungetch: too many character\n");
	else
		buf[bufp++] = c;
}

/* getop: get next cahracter or numeric operand */
int getop(char s[]){
	int i, c;
	//while((s[0] = c = getch()) == ' ' || c == '\t')
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] =  '\0'; // Technically, a string constant is an array of characters. The internal representation of a string
                  // has a null character '\0' at the end, so the physical storage required is one more than the
                  // number of characters written between the quotes.
	if(!isdigit(c) && c != '.') // Verifica se c é um digito decimal [0 ~ 9]
		return c; /* Não é um número */
	i=0;
	if(isdigit(c)) /* Collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
    if(c == '.')/* Collect fraction part */
		while(isdigit(s[++i] = c = getch))
			;
	s[i] = '\0'; 
	if(c != EOF){ // EOF is a distinctive value when there is no more input
		printf("chamou ungetch\n");
		ungetch(c);
	}
	return NUMBER;
	
}

#define MAXVAL 100 /* Maximum depth of val stack */

int sp = 0; /* Next free stack position */
double val[MAXVAL]; /* Value stack */

/* push: push f onto value stack */
void push(double f){
	if(sp < MAXVAL){
		val[sp++]=f;
		printf("val %.1f\n", val[sp-1]);
	}
	else
	 printf("Stack full! Can't push %g\n", f);	
}

/* pop;: pop and return to value from stack */
double pop(void){
	if(sp > 0){
		printf("caiu no pop\n");
		return val[--sp];
	}
	else{
		printf("Error! Stack empty\n");
		return 0.0;
	}
}

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				printf("\n pushing: %s\n", s);
				push(atof(s));
				break;
			case '+':
				printf("chamou por soma\n");
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();		
				push(pop() - op2); // Lembrando que Polish Calculator: 'pop() op2 -'
								   // Logo, a variável op2 é utilizada, devido a posição na stack (Last In First Out) 
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Erro! Divisao por zero\n");
				break;
			case '\n':
				printf("Caiu aqui no tab, bixo\n");
				//printf("\t%.8g\n", pop());
				printf("Resultado = %.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
			}
	}
	
	return 0;
}