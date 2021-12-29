#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *array;
	int i;

	array = (int*)malloc(5*sizeof(int));
	
	*array = 1;
	*(array + 1) = 2;
	*(array + 2) = 3;
	array[3] = 4;
	array[4] = 5;

	for(i = 0; i < 5; i++)
		printf("%d\n", *(array+i));

	free(array);

	return 0;
}