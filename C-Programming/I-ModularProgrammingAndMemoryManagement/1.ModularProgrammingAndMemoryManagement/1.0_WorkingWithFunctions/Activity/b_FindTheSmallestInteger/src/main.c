#include <stdio.h>

int min(int a, int b);

int main()
{ 
	int read[100];
	int read_from_prompt;
	int i;
	int ret;

	scanf("%d", &read_from_prompt);
	for(i=0; i<read_from_prompt;i++)
	{
		scanf("%d", &read[i]);
	}

	ret = read[0];

	for(i=0; i<read_from_prompt; i++)
	{
		ret = min(ret, read[i]);
	}
	printf("%d\n", ret);

	return 0;
}

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}