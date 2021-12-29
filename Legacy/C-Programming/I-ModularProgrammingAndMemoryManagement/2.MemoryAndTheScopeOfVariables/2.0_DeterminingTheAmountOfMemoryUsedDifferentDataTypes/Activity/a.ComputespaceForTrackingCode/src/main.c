#include <stdio.h>

int sizeChar(int a);
int sizeInt(int b);
int sizeDouble(int c);

int main()
{
	int varNb;
	int nb;
	char ch;
	int i;
	int value = 0;
	int valueFlag = 1;

	scanf("%d", &varNb);

	for(i = 0; i < varNb; i++)
	{
		scanf("%d %c", &nb, &ch);
		if(ch == 'c')
			value += sizeChar(nb);
		else if(ch == 'i')
			value += sizeInt(nb);
		else if(ch == 'd')
			value += sizeDouble(nb);
		else
			valueFlag = 0;
	}

	if(!valueFlag)
		printf("Invalid tracking code type\n");
	else
		printf("%d bytes\n", value);

	return 0;
}

int sizeChar(int a)
{
	return (a * sizeof(char));
}

int sizeInt(int b)
{
	return (b * sizeof(int));
}

int sizeDouble(int c)
{
	return (c * sizeof(double));
}