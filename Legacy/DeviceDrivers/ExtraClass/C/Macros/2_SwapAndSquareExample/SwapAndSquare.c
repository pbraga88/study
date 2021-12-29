#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b) ({a ^= b; b ^= a; a ^= b;})
#define SQUARE(x) (x*x)

int main(int argc, char* argv[])
{
	/* SWAP */
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	printf("Inicialmente:\n\ta = %d\n\tb = %d\n\n", x, y);

	SWAP(x,y);
	printf("Depois do swap:\n\ta = %d\n\tb = %d\n\n", x, y);
	
	/* Square */
	printf("Square of swapped x = %d\n", SQUARE(x));
	printf("Square 0f swapped y = %d\n", SQUARE(y));

	return 0;
}