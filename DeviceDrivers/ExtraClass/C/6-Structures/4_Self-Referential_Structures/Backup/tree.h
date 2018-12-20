/* Tree header file*/

#ifndef HEADER_FILE
#define HEADER_FILE

/*struct tnode{ 
/*	char *word;				/* points to the text */
/*	int count;				/* number of ocurrences */
/*	struct tnode *left;		/* left child */
/*	struct tnode *right;	/* right child */
/*};*/

struct tnode *talloc(void);

struct tnode *addtree(struct tnode *, char *);

void treeprint(struct tnode *);

#endif