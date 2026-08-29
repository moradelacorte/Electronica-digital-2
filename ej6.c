#include <stdio.h>

int main() {
    /* Vector de int */
    int x[5] = {10, 20, 30, 40, 50};
    int *ptr;
    int i;

    ptr = x;   /* a) Para que ptr apunte a la primera posición del vector x*/

    printf("== Vector de int (sizeof(int) = %zu bytes) ==\n", sizeof(int));
    for (i = 0; i < 5; i++) {
        printf("ptr = %p   *ptr = %d\n", (void*)ptr, *ptr);  /* c) printf del puntero ptr para cada incremento del punto b */
        ptr++;   /* b) recorrer con incrementos en el puntero */
    }

    /* Vector de char */
    char c[5] = {'a', 'b', 'c', 'd', 'e'};
    char *pc;
    pc = c;

    printf("\n== Vector de char (sizeof(char) = %zu bytes) ==\n", sizeof(char));
    for (i = 0; i < 5; i++) {
        printf("pc = %p   *pc = %c\n", (void*)pc, *pc);
        pc++;
    }

    return 0;
}