#include <stdio.h>

/* LE2.1.1: Analog Signaling */
int main() {
    float result_s = 0;
    float result_l = 0;
    float input = 0.5;
    
    result_l = (input*101)/100;
    result_s = (input*99)/100;

    for (int i = 1; i < 50; i++) {
        result_l = (result_l*101)/100;
        result_s = (result_s*99)/100;
        printf("[%d]Smallest: %f  -  Largest: %f\n", i, result_s, result_l);
    }
    
    return 0;
}