#include <stdio.h>

void myFunction(int*, double*, char*);

int main(void) {
    int i = 42;
    int *iAdr = &i;
    double a = 3.14;
    double * aAdr = &a;
    char c = 'p';
    char * cAdr;
    cAdr = &c;
    printf("i = %d and its address is %p.\n", i, (void*)iAdr);
    printf("a = %.2lf and its address is %p.\n", a, (void*)aAdr);
    printf("c = %c and its address is %p.\n", c, (void*)cAdr);
    myFunction(iAdr, aAdr, cAdr);
    printf("Values after calling myFunction(): %d, %.2lf and %c.\n", *iAdr, *aAdr, *cAdr);

    return(0);
}

void myFunction(int *iptr, double * aptr, char * cptr) {
    printf("Function received addresses %p, %p and %p.\n", (void*)iptr, (void*)aptr, (void*)cptr);
    printf("Values received %d, %.2lf and %c.\n", *iptr, *aptr, *cptr);
    *iptr = 50;
    *aptr = 10.0;
    *cptr = 'b';
}