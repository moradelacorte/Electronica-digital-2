#include <stdio.h>
  
int main(void) {
    
    /* Caso para el item a */

    /*char a;
    int b = 0x12345678;
    short int c;*/

    /* Caso para el item b */
    char a;
    short int c;
    int b = 0x12345678;
    
    printf("\n\nDireccion asignada para la variable a:\t%p\n", &a);
    printf("\nDireccion asignada para la variable b:\t%p\n", &b);
    printf("\nDireccion asignada para la variable c:\t%p\n", &c);
 
    return 0;
}