#include <stdlib.h>

void factorize(int num, int* factors, int* count) {
    *count = 0;
    while (num%2 == 0) {
        factors[(*count)++] = 2;
        num /= 2;
    }

    for (int i = 3; i*i <= num; i += 2) {
        while (num%i == 0) {
            factors[(*count)++] = i;
            num /= i;
        }
    }

    if (num > 2) {
        factors[(*count)++] = num;
    }
}
