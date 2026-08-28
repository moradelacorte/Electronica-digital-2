#include <stdio.h>

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int x = 1, y = 2;

    printf("Cuenta: %d + %d = %d\n\n", x, y, sumar(x, y));
    return 0;
}