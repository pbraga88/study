#include <stdio.h>

struct point {
	int x;
	int y;
	struct point *next;
};

void printPoint(struct point *ptr);

int main()
{
	struct point pt1 = {1, 2, NULL};
	struct point pt2 = {-2, 3, NULL};
	struct point pt3 = {4, -5, NULL};
	struct point *start;

	start = &pt1;
	pt1.next = &pt2;
	pt2.next = &pt3;

	printPoint(start);

	return 0;
}

void printPoint(struct point *ptr)
{
	while (ptr != NULL) {
		printf("Value of ptr:%p\n", (void*)ptr);
		printf("%d, %d\n", ptr->x, ptr->y);
		ptr = ptr->next;
	}
	printf("Value of ptr:%p\n", (void*)ptr);
}