#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {
	int vertices;
	struct point *polygon;
	scanf("%d", &vertices);
	polygon = (struct point*) malloc(vertices * sizeof(polygon));
	initializePoly(polygon, vertices);
	printPoly(polygon, vertices);

	free(polygon);
    return 0;
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

void initializePoly(struct point *ptrPoly, int pVertices)
{
	int i;
	for (i = 0; i<pVertices; i++) {
		ptrPoly[i].x = -i;
		(ptrPoly+i)->y = i*i;
	}

}