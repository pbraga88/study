#include <stdio.h>
#include <stdlib.h>

#include "linkedListOperations.h"
#include "numberOperations.h"
#include "printAndFree.h"
#include "new_test_lib.h"

int main(void) {
    struct digit *start;
    start = readNumber();

    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));

    freeNumber(start);

    test_lib_function();
    return 0;
}