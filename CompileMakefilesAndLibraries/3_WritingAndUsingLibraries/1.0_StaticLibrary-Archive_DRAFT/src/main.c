#include <stdio.h>
#include <stdlib.h>

#include "linkedListOperations.h"
#include "numberOperations.h"
#include "printAndFree.h"

int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    return 0;
}