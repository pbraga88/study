#include <stdio.h>
#include <stdlib.h>

char *convertData(int data);

int main()
{
	char dataType;
	int varAmount;
	int dataAmount;

	scanf("%c %d", &dataType, &varAmount);
	if(dataType == 'i')
		dataAmount = sizeof(int)*varAmount;
	else if(dataType == 's')
		dataAmount = sizeof(short)*varAmount;
	else if(dataType == 'c')
		dataAmount = sizeof(char)*varAmount;
	else if(dataType == 'd')
		dataAmount = sizeof(double)*varAmount;
	else
	{
		printf("Invalid data type!\n");
		return 0;
	}

	printf("%s\n", convertData(dataAmount));


	return 0;
}

char *convertData(int data)
{
	/*if(data/1000000)*/

	char *ret = malloc(1024);
	sprintf(ret, "teste %d", data);


	return ret;


}