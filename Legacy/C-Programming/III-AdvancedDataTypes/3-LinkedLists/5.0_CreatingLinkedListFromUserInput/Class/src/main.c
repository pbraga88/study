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
struct digit *readNumber(void);
bool divisibleByThree(struct digit *start);

int main(void) {
    struct digit *start;

    printf("Enter a integer numerical value:\n");
    start = readNumber();
    printNumber(start);
    if (divisibleByThree(start)) 
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
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
    return (end->next);
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

struct digit *readNumber()
{
    char c;
    int d;
    struct digit *start, *end, *newDigptr;
    start = NULL;
    scanf("%c", &c);
    while(c != '\n') {
        d = c - 48; /* Conversion from ASCII value*/
        newDigptr = createDigit(d);
        if(start == NULL) {
            start = newDigptr;
            end = start;
        }
        else {
            end = append(end, newDigptr);
        }
        scanf("%c", &c);
    }
    return start;
}

bool divisibleByThree(struct digit *start)
{
    double n;
    while(start != NULL) {
        n += start->num;
        start = start->next;
    }
    
    if(n%3)
        return FALSE;
    else
        return TRUE;
}


