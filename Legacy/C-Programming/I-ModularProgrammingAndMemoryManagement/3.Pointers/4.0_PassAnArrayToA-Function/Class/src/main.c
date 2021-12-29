#include <stdio.h>

void reset(int *ptr);

int main()
{
	int arr[] = {10, 20, 40};
	printf("%d\n", *arr );
	printf("%d\n", *(arr+1));
	printf("%d\n", *(arr+2));
	
	reset(arr); 

	printf("%d\n", *arr );
	printf("%d\n", *(arr+1));
	printf("%d\n", *(arr+2));
	
	return 0;
}

void reset(int *ptr)
{
	*ptr = 0;
	*(ptr+1) = 0;
	*(ptr+2) = 0;
}