#include <stdio.h>

void print_array(short *array, int size);

int main(void)
{
	short a[3] = {123, 456, 789};
	short b[2] = {12, 34};
	short c[4] = {1234, 5678, 9012, 3456};
	short* arrays[3] = {a, b, c};
	print_array(a, 3);
	print_array(b, 2);
	print_array(c, 4);
	
	/* First way to dereference */
	*arrays[0] = 1;
	*(arrays[0] + 1) = 2;
	*(arrays[0] + 2) = 3;
	
	*arrays[1] = 4;
	*(arrays[1] + 1) = 5;

	*arrays[2] = 6;
	*(arrays[2] + 1) = 7;
	*(arrays[2] + 2) = 8;
	*(arrays[2] + 3) = 9;

	print_array(a, 3);
	print_array(b, 2);
	print_array(c, 4);

	/* Second way to dereference */
	arrays[0][0] = 9;
	arrays[0][1] = 8;
	arrays[0][2] = 7;

	arrays[1][0] = 6;
	arrays[1][1] = 5;

	arrays[2][0] = 4;
	arrays[2][1] = 3;
	arrays[2][2] = 2;
	arrays[2][3] = 1;

	print_array(a, 3);
	print_array(b, 2);
	print_array(c, 4);

	return 0;
}

void print_array(short *array, int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("Element %d = %d\n", i+1, array[i]);
	printf("\n");
}