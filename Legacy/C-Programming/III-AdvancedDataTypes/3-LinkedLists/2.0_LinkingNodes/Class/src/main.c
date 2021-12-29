#include <stdio.h>
#include <stdlib.h>

struct digit {
	int num;
	struct digit *next;
};
struct digit *createDigit(int digit);
struct digit *append(struct digit *end, struct digit *newDigitptr);
void printNum(struct digit *nb);

int main()
{
	struct digit *start, *newDigitptr, *end, *tmp;
	int first = 1;
	int second = 7;
	int third = 2;

	start = createDigit(first);
	end = start;
	newDigitptr = createDigit(second);
	end = append(end, newDigitptr);
	newDigitptr = createDigit(third);
	end = append(end, newDigitptr);

	printNum(start);

	tmp = start->next;
	free(start);
	start = tmp->next;
	free(tmp);
	free(start);

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

struct digit *append(struct digit *end, struct digit *newDigitptr)
{
	return (end->next = newDigitptr);
}

void printNum(struct digit *nb)
{
	while(nb != NULL) {
		printf("%d\n", nb->num);
		nb = nb->next;
	}
}