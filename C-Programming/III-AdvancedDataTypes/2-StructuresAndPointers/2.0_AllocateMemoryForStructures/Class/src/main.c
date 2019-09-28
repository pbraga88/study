#include <stdio.h>
#include <stdlib.h>

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
void printPolygon(ponto *pPolygon,int counter);

int main()
{
	int i, num;
	ponto *polygon;
/*	z[0].y = 1;
	printf("%d\n", z[0].y);
	(z+1)->y = 3;
	printf("%d\n", z[1].y); */

	printf("How many vertices for the plygon?\n");
	scanf("%d", &num);
	polygon = (ponto *)malloc(num * sizeof(ponto));

	for (i = 0; i < num; i++){
		readPoint(&polygon[i]);	
	}
	printPolygon(polygon, num);
	free(polygon);
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

void printPolygon(ponto *pPolygon,int counter)
{
	int i;
	for (i = 0; i < counter; i++) {
		printPoint(*(pPolygon+i));
	}
}