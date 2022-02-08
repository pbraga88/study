#ifndef LINKED_LIST_HEADER_H
#define LINKED_LIST_HEADER_H

struct digit {
    int num;
    struct digit *next;
};

struct digit *sortDigits(struct digit *newSortedStart, struct digit *newNbToBeSorted);
struct digit *addInFront(struct digit *start, struct digit *newStart);
struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
struct digit *readNumber(void);

#endif
