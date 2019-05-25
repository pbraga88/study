#include <stdio.h>

int main(){
    int a = 10;
    int b = 11;
    int *p;

    {
        /*Inside the block.*/
        int c = 12;
        int d = 13;
        int e = a + c;
        c = b + d;
        p = &c;
        printf("c: %d\n", c);
        printf("e: %d\n", e);
        /* As variáveis são excluidas, quando o programa sai do bloco.*/
    }
    /* Mesmo excluidas as variáveis, o valor naquela posição de memória permanece até 
    que um novo valor seja escrito.*/
    printf("The value in pointer p which points to int var c: %d\n", *p);
    
    /* As novas variáveis declaradas irão ocupar a posição em memória das variáveis
       excluidas no bloco anterior.*/
    int f = 14;
    int g = 15;
    printf("f: %d\n",f);
    printf("g: %d\n", g);

    return 0;
}