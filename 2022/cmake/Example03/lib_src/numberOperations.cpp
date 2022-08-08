#include <stdio.h>
#include <stdlib.h>

#include "numberOperations.h"
#include "linkedListOperations.h"

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