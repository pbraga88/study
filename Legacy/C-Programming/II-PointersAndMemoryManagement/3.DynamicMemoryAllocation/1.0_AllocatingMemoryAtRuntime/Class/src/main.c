#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *iptr;
	double *dptr;

	iptr = (int*)malloc(sizeof(int));
	*iptr = 10;
	printf("%d\n", *iptr);

	
	dptr = (double*)malloc(sizeof(double));
	*dptr = 10.0;
	printf("%.1f\n", *dptr);

	free(iptr);
	free(dptr);

	return 0;
}