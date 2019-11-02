#include <stdio.h>
#include <stdlib.h>

#include "linkedListOperations.h"

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