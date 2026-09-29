#include <stdio.h>

int strlen(char *s) {
    char *p = s;   

    while (*p != '\0')
        p++;       

    return p - s;  
}
/* Ejemplo de uso*/
int main() {
    char texto[] = "Electronica Digital";

    printf("Cadena: \"%s\"\n", texto);
    printf("Largo calculado: %d\n", strlen(texto));

    return 0;
}