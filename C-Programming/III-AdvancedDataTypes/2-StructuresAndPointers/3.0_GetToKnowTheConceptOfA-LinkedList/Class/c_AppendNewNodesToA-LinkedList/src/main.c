#include <stdio.h>

struct point {
	int x;
	int y;
	struct point *next;
};

void printPoint(struct point *start);
struct point *append(struct point *end, struct point *newPoint);

int main()
{
	struct point pt1 = {1, 2, NULL};
	struct point pt2 = {-2, 3, NULL};
	struct point pt3 = {4, -5, NULL};
	struct point *start, *end;

	start = end = &pt1;
	end = append(end, &pt3);
	end = append(end, &pt2);

	printPoint(start);

	return 0;
}

void printPoint(struct point *start)
{
	struct point *ptr;
	ptr = start;

	while (ptr != NULL) {
		printf("Value of ptr:%p\n", (void*)ptr);
		printf("%d, %d\n", ptr->x, ptr->y);
		ptr = ptr->next;
	}
	printf("Value of ptr:%p\n", (void*)ptr);
}

struct point *append(struct point *end, struct point *newPoint)
{
	end->next = newPoint;

	return (end->next);
}