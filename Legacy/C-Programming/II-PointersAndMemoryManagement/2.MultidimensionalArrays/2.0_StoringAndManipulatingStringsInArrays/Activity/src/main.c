#include <stdio.h>

int main(){

	char text[68][41];
	int i;

	for (i = 0; i < 68; i++)
		scanf("%s", text[i]);
	printf("\n");
	for (i = 67; i>= 0; i--)
		printf("%s ", text[i]);
	printf("\n");

	return 0;
}