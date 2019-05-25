#include <stdio.h>

void reverseArray(int *ptr);
int main()
{
	int arr[6];
	int i;
	for(i = 0; i < 6; i++)
		scanf("%d", &arr[i]);

	reverseArray(arr);

	for(i = 0; i < 6; i++)
		printf("%d ", arr[i]);
	
	printf("\nSize of array/int elements:  %ld\n", sizeof(arr)/sizeof(int));

	return 0;
}

void reverseArray(int *ptr)
{
	int sec_arr[6];
	int i;
	for(i=0; i<=5; i++)
		sec_arr[i] = ptr[5-i];
	for(i=i; i>=0; i--)
		ptr[i] = sec_arr[i];
}