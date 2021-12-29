#include <stdio.h>

int main() {

#if 0
printf("commented code 1\n");
printf("commented code 2\n");
#endif

#define TEST1

#ifdef TEST1
printf("MACRO TEST1 is defined\n");
#endif

#ifdef TEST3
printf("MACRO TEST3 is defined\n");
#else
printf("MACRO TEST3 is NOT defined\n");
#endif

return 0;
}