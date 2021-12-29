#include <stdio.h>

int main()
{
	int n, facto, i;

	printf("Please, enter a positive integer: ");
	scanf("%d", &n);
	
	facto = 1;
	
	for(i = 1; i<=n; i++)
		facto *=i;

	if(n<0)
		printf("%d is negative! Aborting..\n", n);
	else
		printf("%d! = %d\n", n, facto);

	return 0;
}