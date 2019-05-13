/* Fibonacci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... */
#include <stdio.h>

int fibonacci(int n);

int main()
{
	/*int N, fib;*/
	int N;
	printf("Which Fibonacci number would you like: ");
	scanf("%d", &N);
	if(N <= 0)
		printf("%d is not a positive number. Aborting!\n", N);
	else
		printf("The %dth Fibonacci number is %d.\n", N, fibonacci(N));

	return 0;
}

int fibonacci(int n)
{
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return (fibonacci(n-1) + fibonacci(n-2));
}