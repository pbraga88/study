#include <stdio.h>
#include <stdlib.h>

int feetConvert(double valuea);
int poundconvert(double valueb);
int temperatureConvert(double valuec);

int main()
{
	int nConv;
	int i;
	int contador;
	char *read_from_prompt = malloc(1);
	double int_part;
	char str_part;
	
	scanf("%i", &nConv);

	for(i=0; i<nConv; i++)
	{
		for(contador = 0; contador < 2; contador++)
		{
			scanf("%s", read_from_prompt);
			if(!contador)
				int_part = atof(read_from_prompt);
			else
				str_part = *read_from_prompt;
		}

		if(str_part == 'm')
			feetConvert(int_part);
		else if (str_part == 'g')
			poundconvert(int_part);
		else if (str_part == 'c')
			temperatureConvert(int_part);
		else
			printf("Invalid value\n");

	}
	free(read_from_prompt);
	return 0;
}

int feetConvert(double valuea)
{
	printf("%.6f ft\n", valuea*3.2808);
	return 0;
}
int poundconvert(double valueb)
{
	printf("%.6f lbs\n", valueb*0.002205);
	return 0;
}
int temperatureConvert(double valuec)
{
	printf("%.6f f\n", valuec*1.8+32);
	return 0;
}