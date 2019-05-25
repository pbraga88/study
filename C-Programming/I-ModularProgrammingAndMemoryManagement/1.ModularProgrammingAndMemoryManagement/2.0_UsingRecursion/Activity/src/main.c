#include <stdio.h>

int sumOfDigits(int n);

int main()
{
	int nb;
	scanf("%d", &nb);
	printf("%d\n", sumOfDigits(nb));

	return 0;
}

int sumOfDigits(int n)
{
	if(n < 10)
		return n;
	return (n%10 + sumOfDigits(n/10));
}