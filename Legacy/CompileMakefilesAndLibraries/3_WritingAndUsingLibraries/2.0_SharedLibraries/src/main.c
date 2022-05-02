#include <stdio.h>
#include <stdlib.h>

#include "linkedListOperations.h"
/* Testing the inclusion of the below header in Makefile as:
CFLAGS += -include $(INC)/numberOperations.h

#include "numberOperations.h" */
#include "printAndFree.h"

int main(void) {
    struct digit *start;
    start = readNumber();
    set_value(1000); /*For testing purpose*/
    printf("The number ");
    printNumber(start);
    printf("contains %d redundancies.\n", countRedun(start));
    get_value(); /*For testing purpose*/
    freeNumber(start);

    return 0;
}
