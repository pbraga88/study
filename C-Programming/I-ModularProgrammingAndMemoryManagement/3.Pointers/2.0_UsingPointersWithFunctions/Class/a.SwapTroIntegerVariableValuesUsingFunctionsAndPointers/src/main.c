#include <stdio.h>

void swap(int*, int*);

int main()
{
	int a = 9;
	int b = 1;
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}