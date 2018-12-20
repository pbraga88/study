#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "getword.h"


#define MAXWORD 100

struct tnode{ 
	char *word;				/* points to the text */
	int count;				/* number of ocurrences */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
};

struct tnode *talloc(void);

struct tnode *addtree(struct tnode *, char *);

void treeprint(struct tnode *);

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
	printf("caiu em adtree\n"); /*DEBUG*/
	int cond;
	printf("Declara int cond\n");

	if (p == NULL) {	/* a new word has arrived */
	
		printf("caiu no if 1\n"); /*DEBUG*/
		p = talloc();	/* make a new node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0){
		printf("caiu no if 2\n"); /*DEBUG*/
		p->count++;
		}		/* repeated word */
	else if (cond < 0 ){	/* less than into left subtree*/
		printf("caiu no if 3\n"); /*DEBUG*/
		p->left = addtree(p->left, w);
	}
	else{				/* greater than into right subtree */
	    printf("caiu no else\n"); /*DEBUG*/
		p->right = addtree(p->right, w);
	}
	printf("retorna p\n"); /*DEBUG*/
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

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}