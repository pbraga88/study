#include <stdio.h>
 
int main(void) {
    int i;
    int *iAdr = &i;
 
    *iAdr = 10;
 
    printf(" i = %d\n", i);
    printf(" *iAdr = %d\n", *iAdr);
 
    *iAdr = *iAdr - 2;
    printf(" i = %d\n", i);
    printf(" *iAdr = %d\n", *iAdr);
 
    (*iAdr) += 1;
    printf(" i = %d\n", i);
    printf(" *iAdr = %d\n", *iAdr);
 
    return 0;
}