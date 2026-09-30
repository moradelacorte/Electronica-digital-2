#include <stdio.h>

union aux {
    int a; 
    char b;       
};

int main(void) {
    union aux var;

    var.a = 77;
    printf("a: %d\n", var.a);
    printf("b: %c\n", var.b);

    return 0;
}