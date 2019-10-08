#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
struct digit * readNumber();
struct digit *searchNumber(struct digit *start,int number);
struct digit *reverseDigits(struct digit *pStart);
struct digit *addInfront(struct digit *nbdigit, struct digit *bstart);

int main(void) {
    int nb = 5;
    struct digit *start, *ptr, *reverse;
    printf("Please enter a number: ");
    start = readNumber();
    ptr = searchNumber(start, nb);
    if (ptr != NULL) {
        printf("Number %d found at memory location %p.\n", nb, (void*)ptr);
    }
    else {
        printf("Number %d not found.\n", nb);
    }
    printNumber(start);

    reverse = reverseDigits(start);
    printNumber(reverse);

    freeNumber(start);
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit * readNumber() {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c!='\n') {
        d = c - 48;
        newptr = createDigit(d);
        if (start==NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return start;
}

struct digit *searchNumber(struct digit *start,int number)
{
    while(start != NULL && start->num != number) {
        start = start->next;
    } 
    return start;
}

struct digit *reverseDigits(struct digit *pStart)
{
    struct digit *ptr = pStart;
    struct digit *bstart;
    struct digit *nbdigit;

    if (ptr != NULL) {
        bstart = createDigit(ptr->num);
        ptr = ptr->next;
    }

    while (ptr != NULL) {
        nbdigit = createDigit(ptr->num);
        bstart = addInfront(nbdigit, bstart);
        ptr = ptr->next;
    }
    return bstart;
}

struct digit *addInfront(struct digit *nbdigit, struct digit *bstart) 
{
    nbdigit->next = bstart;
    return nbdigit;
}