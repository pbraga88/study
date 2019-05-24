#include <stdio.h>

int main()
{
	int arr[3] = {2, 3, 5};
	printf("Address arr[0]: %p\n", arr);
	int *ptr = arr;
	*ptr = 20;
	printf("\tValue: %d\n", *ptr);
	printf("\tValue: %d\n", ptr[0]);

	printf("Address arr[1]: %p\n", arr + 1);
	*(ptr + 1) = 30;
	printf("\tValue: %d\n", *(ptr + 1));
	printf("\tValue: %d\n", ptr[1]);

	printf("Address arr[2]: %p\n", arr + 2);
	*(ptr + 2) = 50;
	printf("\tValue: %d\n", *(ptr + 2));
	printf("\tValue: %d\n", ptr[2]);

	return 0;
}