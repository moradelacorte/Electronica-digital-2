#include <stdio.h>

int main() {
    int vector[10] = {4, 8, 15, 16, 23, 42, 7, 13, 19, 25};
    int i;

    printf("Contenido del vector:\n");
    for (i = 0; i < 10; i++) {
        printf("vector[%d] = %d\n", i, vector[i]);
    }

    printf("\nTamano de un int: %zu bytes\n", sizeof(int));
    printf("Tamano total del vector (10 enteros): %zu bytes\n", sizeof(vector));

    return 0;
}