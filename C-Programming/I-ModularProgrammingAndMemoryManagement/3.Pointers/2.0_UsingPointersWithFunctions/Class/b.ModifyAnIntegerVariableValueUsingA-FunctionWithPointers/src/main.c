#include <stdio.h>

void addThree(int *);

int main()
{
	int a = 5;
	addThree(&a);
	printf("Inside main, value of a: %d\n", a);

	return 0;
}

void addThree(int *a)
{
	*a+=3;
}