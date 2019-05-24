#include <stdio.h>

void reverseArray(int *ptr);
int main()
{
	int arr[6];
	scanf("%d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5]);
	reverseArray(arr);
	printf("%d %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
	printf("%ld\n", sizeof(arr)/sizeof(int));

	return 0;
}

void reverseArray(int *ptr)
{
	int sec_arr[6];
	int i;
	int c = 5;
	for(i=0; i<=5; i++)
	{
		sec_arr[i] = ptr[c];
		c--;
	}
	for(i=i; i>=0; i--)
	{
		ptr[i] = sec_arr[i];
	}
}