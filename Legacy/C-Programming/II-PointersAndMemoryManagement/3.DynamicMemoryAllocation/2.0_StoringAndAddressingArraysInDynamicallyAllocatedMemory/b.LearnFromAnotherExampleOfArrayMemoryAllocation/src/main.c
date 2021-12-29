#include <stdio.h>
#include <stdlib.h>

int *returnSize(int nb);
double getAverage(int *arr, int nb);

int main(){
	int num, i;
	int *array;
	double average;

	printf("How many grades\n");
	scanf("%d", &num);

	array = returnSize(num);
	printf("Enter the grades\n");
	for (i = 0; i < num; i++)
		scanf("%d", array + i);
	average = getAverage(array, num);
	printf("%.2f\n", average);

	return 0;
}

int *returnSize(int nb){
	return (int*)malloc(nb*sizeof(int));
}

double getAverage(int *arr, int nb){
	int i;
	double avg;
	for (i = 0; i < nb; i++)
		avg += *(arr + i);
	return avg/nb;
}