#include <stdio.h>
#include <stdbool.h>
#include "client.h"


int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    
    printf("Flag value: %d\n", get_value());

    calculation(1,1);

    printf("Flag value: %d\n", get_value());

    return 0;
}
