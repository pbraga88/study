#include <stdio.h>

int main()
{
	char words[3][10];
	printf("%i\n", sizeof(words));
	int i;
	printf("Enter 3 words:\n");
	for (i=0; i<3; i++)
		scanf("%s", words[i]);

	printf("Words entered:\n");
	for (i=0; i <3; i++)
		printf("%s ", words[i]);
	printf("\n");
	for (i=0; i <3; i++)
		printf("%s ", *(words+i));

	for(i=0; i<3; i++)
		printf("\n \"%s\" first letter is %c \n", words[i], words[i][0]);
	for(i=0; i<3; i++)
		printf("\n \"%s\" second letter is %c \n", *(words+i), *(*(words+i)+1));


	return 0;
}