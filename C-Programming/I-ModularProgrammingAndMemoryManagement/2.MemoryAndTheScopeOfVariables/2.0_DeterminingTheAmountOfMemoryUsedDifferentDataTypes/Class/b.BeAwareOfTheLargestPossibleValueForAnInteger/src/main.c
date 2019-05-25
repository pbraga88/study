#include <stdio.h>

int main()
{
	unsigned int num = 2147483645;
	int i;

	for(i = 0; i < 8; i++)
	{
		printf("%i\n", num);
		printf("\t%u\n", num);
		printf("\t\t%p\n", num);
		num++;
	}

	return 0;
}