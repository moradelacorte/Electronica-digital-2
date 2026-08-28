#include <stdio.h>

int main() {
    int x = 1, y = 2;
    int *ptr;

    printf("Estado inicial:\n");
    printf("x = %d   direccion de x (&x) = %p\n", x, (void*)&x);
    printf("y = %d   direccion de y (&y) = %p\n\n", y, (void*)&y);

    ptr = &x;
    printf("Tras 'ptr = &x;'\n");
    printf("ptr ahora guarda la direccion de x -> ptr = %p\n", (void*)ptr);
    printf("x sigue siendo %d, y sigue siendo %d\n\n", x, y);

    y = *ptr;
    printf("Tras 'y = *ptr;'\n");
    printf("*ptr lee el valor guardado en la direccion %p (o sea, el valor de x) = %d\n", (void*)ptr, *ptr);
    printf("x = %d (&x = %p)   y = %d (&y = %p, no cambio)\n\n", x, (void*)&x, y, (void*)&y);

    *ptr = 0;
    printf("Tras '*ptr = 0;'\n");
    printf("Se escribe 0 en la direccion a la que apunta ptr, es decir, en x\n");
    printf("x = %d (&x = %p, la misma direccion de siempre)   y = %d (&y = %p, no cambio)\n", x, (void*)&x, y, (void*)&y);

    return 0;
}