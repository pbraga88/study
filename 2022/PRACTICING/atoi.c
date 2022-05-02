#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int atoi(const char* s) {
    int n = 0, j = 0;
    size_t len = strlen(s);
    bool neg = false;

    if (s[0] == '-') {
        j++;
        len--;
        neg = true;
    }

    for (int i = pow(10, len-1); i != 0; i/=10) {
        n += (s[j]-'0') * i;
        j++;
    }

    return neg ? (n*=-1) : (n);
}

int main() {
    char *nb = "10";
    int cnb = atoi(nb);
    printf("%d\n", cnb);

    return 0;
}