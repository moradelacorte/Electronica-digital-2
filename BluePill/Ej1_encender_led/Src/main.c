#include <stdint.h>

int main(void){

    *(int *)(0x40021018) |= (1 << 4) | (1 << 2);   // Reloj de GPIOC y GPIOA
    *(int *)(0x40011004) = (3 << 20);              // PC13: salida push-pull 50 MHz
    *(int *)(0x4001100C) = (0 << 13);              // PC13 = 0 -> LED encendido (activo en bajo)

    while(1) {
    }

    return 0;
}
