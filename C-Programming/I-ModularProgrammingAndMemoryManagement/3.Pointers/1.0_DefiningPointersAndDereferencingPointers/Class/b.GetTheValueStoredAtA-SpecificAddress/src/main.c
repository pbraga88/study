#include <stdio.h>

int main()
{
	double a = 42.98;
	double *addressOfA = &a;
	printf("At address %p there is the value %.2lf\n", (void*)addressOfA, *addressOfA);	

	char c = 'm';
	char* addressOfC = &c;
	char d = *addressOfC;

	*addressOfA = 32;
	*addressOfA = *addressOfA +1;
	printf("At address %p there is the value %.2lf\n", (void*)addressOfA, *addressOfA);	
	
	return 0;
}