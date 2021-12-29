#include <stdio.h>
#include <string.h>

int main()
{
	char a[5];
	char b[6];
	char c[3];
	char d[4];
	char e[6];

	printf("%i\n", sizeof(a));

	char* word[5] = {a, b, c, d, e};
	int word_size = sizeof(word)/sizeof(*word); /* char = 8 bits. word = 5 * char. *word = 8
												   portanto: char_size = (5*8)/8 = 5 */

	printf("%i\n", word_size);

	/*From China To The World*/
	int i;
	for (i = 0; i < word_size; i++)
		scanf("%s", *(word+i) );
	
	for (i = 0; i < word_size; i++)
		printf("%s ", word[i] );

	printf("\n");
	return 0;
}