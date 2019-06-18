#include <stdio.h>

void printArray(int* ptr, int size);
void squareArray(int* ptr, int size);

int main()
{
	int array[] = {6, 2, -4, 8, 5, 1};
	int N = 6;
	printArray(array, N);
	squareArray(array, N);
	printArray(array, N);

	return 0;
}

void printArray(int* ptr, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		/* Ambos métodos abaixo dereferenciam ptr*/
		printf("%d \n", *(ptr + i));
		printf("\t %d \n", ptr[i]);
	}
}

void squareArray(int* ptr, int size)
{
	int i;
	for(i=0; i<size; i++)
		/* Elevando ao quadrado com duas notações diferentes */
		ptr[i] = ptr[i] * (*(ptr+i));
}