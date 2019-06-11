#include <stdio.h>

int main(void) {
    int array[] = {6, 2, -4, 8, 5, 1};
    int *ptr, *ptr2;
    
    printf("Array contains %d, %d, ... , %d\n", array[0], array[1], array[5]);
    printf("\tThese are stored at %p, %p, ..., %p\n", (void*)&array[0], (void*)&array[1], (void*)&array[5]);
    /* array equals &array[0] */
    ptr = array;
    ptr2 = &array[0];
    
    *ptr = 10;
    *(ptr + 1) = 5; 
    *(ptr + 2) = -1;
    printf("%d, %d, %d\n", *ptr, *(ptr+1), *(ptr+2));
    printf("\tAdress: %p, %p, %p:\n", (void*)ptr, (void*)(ptr+1), (void*)(ptr+2));

    *array = 3;
    *(array + 1) = 10;
    *(array + 2) = 99;
    printf("%d, %d, %d\n", array[0], array[1], array[2]);
    printf("\tAdress: %p, %p, %p:\n", (void*)ptr, (void*)(ptr+1), (void*)(ptr+2));
    
    ptr++;
    *ptr = 7;
    printf("%d\n", *ptr);
    printf("\tAdress: %p\n", (void*)ptr);

    ptr += 3;
    *ptr = 8;
    printf("%d\n", *ptr);
    printf("\tAdress: %p\n", (void*)ptr);
    return 0;
}