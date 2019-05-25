#include <stdio.h>

int main() {
    char c = '?';
    printf("%p\n\t%i\n",c,c);
    short s = 2301;
    printf("%p\n\t%i\n",s,s);
    int i = 987654;
    printf("%p\n\t%i\n",i,i);
    double d = 26.49;
    printf("%p\n\t%f\n",d,d);
    char l[5] = {'a','b','c', 'd', 'e'};
    short lShort[4] = {163, 365, 852, 1424};
    int lInt[3] = {2876, 26532, 37652};
    double lDouble[2] = {86.263, 265.2774};
    return 0;
}