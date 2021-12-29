#include <stdio.h>
#include <stdlib.h>

#include "inverso.h"

int main(int argc, char **argv){
	int i;
	
	i = atoi(argv[1]);
	printf("O inverso de %d, eh igual a: %.2f \n", i, inverso(i));

	return 0;
}