#include <stdio.h>
#include <stdlib.h>

#define MEGA 1000000
#define KILO 1000

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
	char *ret = malloc(1024);
	int b, kb, mb;

	if((mb = data/MEGA))
	{
		kb = (data%MEGA)/KILO;
		b = (data%MEGA)%KILO;
		sprintf(ret, "%d MB and %d KB and %d B", mb, kb, b);
	}

	else if((kb = data/KILO))
	{
		b = data%KILO;
		sprintf(ret, "%d KB and %d B", kb, b);
	}
	
	else
	{
		b = data;
		sprintf(ret,"%d B", b);
	}

	return ret;
}
