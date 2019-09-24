#include <stdio.h>
/*struct point{
	int x;
	int y;
};*/
typedef struct point{
	int x;
	int y;
}ponto;

void readPoint(ponto *ptr);
void printPoint(ponto coord);
void printTriangle(ponto *pTriangle);

int main()
{
	int i;
	ponto z[3];
	z[0].y = 1;
	printf("%d\n", z[0].y);
	(z+1)->y = 3;
	printf("%d\n", z[1].y);

	for (i = 0; i < 3; i++){
		readPoint(&z[i]);	
	}
	printTriangle(z);

	return 0;
}

void readPoint(ponto *ptr)
{
	printf("Read the coordinates\n");
	printf("x: ");
	scanf("%d", &ptr->x);
	printf("y: ");
	scanf("%d", &ptr->y);
}

void printPoint(ponto coord)
{
	printf("(%d, %d)\n", coord.x, coord.y);
}

void printTriangle(ponto *pTriangle)
{
	int i;
	for (i = 0; i < 3; i++) {
		printPoint(*(pTriangle+i));
	}
}