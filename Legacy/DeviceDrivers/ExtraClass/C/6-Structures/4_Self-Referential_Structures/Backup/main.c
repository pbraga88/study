#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

/* The etree node*/
struct tnode{ 
	char *word;				/* points to the text */
	int count;				/* number of ocurrences */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode *talloc(void);
//char *strdup(char *);


/* Word frequency count */
int main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;

	int contador = 0; 

	while (contador < 5){
		getword(word, MAXWORD);
		if (isalpha(word[0])){
			root = addtree(root, word);
			contador ++;
		}
	}
	treeprint(root);
	return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;


	if (p == NULL) {	/* a new word has arrived */
		p = talloc();	/* make a new node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;		/* repeated word */
	else if (cond < 0 )	/* less than into left subtree*/
		p->left = addtree(p->left, w);
	else				/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* talloca: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/**getword() function implementation
 get next word or character from input**/

int getword(char* word, int lim)
{
	int getch(void);
	void ungetch(int);

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
