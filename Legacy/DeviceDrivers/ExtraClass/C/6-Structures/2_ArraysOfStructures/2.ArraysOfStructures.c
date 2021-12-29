#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS 100

struct key{
	char *word;
	int count;
} keytab[NKEYS];

int main(){
	int n=0;
	/*keytab[0].word = "Inicio";
	keytab[0].count = 1;
	keytab[NKEYS-1].word = "FIM";
	keytab[NKEYS-1].count = 100;*/	
	
	while(n < NKEYS){
		if(!n){
			keytab[n].word = "Inicio";
			keytab[n].count = 1;			
		}
		else if(n==NKEYS-1){
			keytab[n].word = "Fim";
			keytab[n].count = 100;
		}
		else{
			keytab[n].word = "Running";
			keytab[n].count = n+1;
		}
		n++;
	}
	
	for(n=0;n<NKEYS;n++){
	   	printf("%s %i\n", keytab[n].word, keytab[n].count);
	}
	return 0;
}