#include <stdio.h>
#include <stdlib.h>

struct digit {
	int num;
	struct digit *next;
};
struct digit *createDigit(int digit);

int main()
{
	struct digit *numberptr;
	int digitToStore = 10;
	numberptr = createDigit(digitToStore);
	printf("Digit: %d\nPointer: %p\nMemory Location: %p\n", \
		numberptr->num, (void*)numberptr->next, (void*)numberptr);
	free(numberptr);

	return 0;

}

struct digit *createDigit(int digit) 
{
	struct digit *ptr;
	ptr = (struct digit *)malloc(sizeof(struct digit));
	ptr->num = digit;
	ptr->next = NULL;
	return ptr;
}