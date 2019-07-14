#include <stdio.h>
void setToZero(short** array, int qty);
void setToOne(short** array, int qty);
void print_array(short* array, int size);

int main()
{
/*	short a[4] = {123, 456, 789, '\0'};
	short b[3] = {12, 34, '\0'};*/
	short a[4] = {123, 456, 789};
	short b[3] = {12, 34};
	short* t[2] = {a, b};
	
	print_array(a, 3);
	print_array(b, 2);

	setToZero(t, 2);
	
	print_array(a, 3);
	print_array(b, 2);

	setToOne(t, 2);
	print_array(a, 3);
	print_array(b, 2);	

	return 0;
}

void setToZero(short** array, int qty)
{
	int i, n;
/*	for (i = 0; i < qty; i++)
	{
		for (n = 0; *(*(array+i)+n); n++)
			*(*(array+i)+n) = 0;	
	}*/

	/*var = array;
	printf("%d\n", var);
	printf("%d\n", *((*var)+2) );
	++var;
	printf("%d\n", *((*var)+2) );*/

	for (i = 0; i < qty ; ++i)
	{
		printf("I'm here\n");
		printf("%d\n", array);
		for (n = 0; *((*array) + n) != NULL; ++n)
		{
			printf("I'm also here\n");
			printf("%d\n", *((*array)+n) );
			*((*array) + n) = 0;	
		}
		++array;
	}
}

void setToOne(short** array, int qty)
{
	int i, n;
	for (i = 0; i < qty; i++)
	{
		for (n = 0; !(array[i][n]); n++)
			array[i][n] = 1;
	}
}

void print_array(short *array, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("Element %d = %d\n", i+1, array[i]);
	printf("\n");
}