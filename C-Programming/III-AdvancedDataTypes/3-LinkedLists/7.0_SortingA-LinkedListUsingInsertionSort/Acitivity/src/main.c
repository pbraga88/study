#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};


// Add a prototype for countRedun() here
int countRedun(struct digit *start);
struct digit *sortDigits(struct digit *newSortedStart, struct digit *newNbToBeSorted);
struct digit *addInFront(struct digit *start, struct digit *newStart);
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *);
struct digit *readNumber(void); 
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);


// Do not modify this main() function
int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

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

struct digit *readNumber(void) {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c != '\n') {
        d = c-48;
        newptr = createDigit(d);
        if (start == NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return(start);
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int qsum = 0;
    while (ptr!=NULL) {
        qsum += ptr->num;
        ptr = ptr->next;
    }
    if (qsum%3==0) return 1;
    else return 0;
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        if (ptr->num == 3) {
            ptr->num = 9;
            sum++;
        }
        ptr = ptr->next;
    }
    return(sum);
}

// Write your countRedun() function here
int countRedun(struct digit *start) {
    struct digit *ptr = start;
    struct digit *newSortedStart = NULL;
    struct digit *newNbToBeSorted;
    int countRed = 0;

    if (start != NULL) {
        newSortedStart = createDigit(start->num);
        ptr = ptr->next;
    }

    while (ptr != NULL) {
        newNbToBeSorted = createDigit(ptr->num);
        newSortedStart = sortDigits(newSortedStart, newNbToBeSorted);
        ptr = ptr->next;
    }

    start = newSortedStart;
    ptr = newSortedStart->next;
    while (ptr != NULL) {
        if (start->num == ptr->num)
            countRed+=1;
        ptr = ptr->next;
        start = start->next;
    }

    return countRed;
}

struct digit *sortDigits(struct digit *newSortedStart, struct digit *newNbToBeSorted) {
    struct digit *ptr = newSortedStart;
    struct digit *prev = NULL;

    while (ptr!=NULL && ptr->num < newNbToBeSorted->num) {
        prev = ptr;
        ptr  = ptr->next;
    }

    if (prev == NULL) {
        newSortedStart = addInFront(newSortedStart, newNbToBeSorted);
    }
    else {
        prev->next = newNbToBeSorted;
        newNbToBeSorted->next = ptr;
    }

    return newSortedStart;
}

struct digit *addInFront(struct digit *start, struct digit *newStart){
    newStart->next = start;
    return newStart;
}