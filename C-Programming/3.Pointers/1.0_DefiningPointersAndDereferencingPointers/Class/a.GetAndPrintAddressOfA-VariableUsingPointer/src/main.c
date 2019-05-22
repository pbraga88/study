#include <stdio.h>

int main()
{
	int a = 10;
	double d = 58.394;
	char c = 'r';

	int* addressOfA = &a;
	printf("Address of a: %p\n",(void*) addressOfA);

	double* addressOfD = &d;
	printf("Address of d: %p\n",(void*) addressOfD);

	char* addressOfC = &c;
	printf("Address of c: %p\n",(void*) addressOfC);
	

	return 0;
}