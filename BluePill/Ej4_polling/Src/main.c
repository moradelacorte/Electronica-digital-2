#include <stdint.h>

int main(void){

    *(volatile int *)(0x40021018) |= (1 << 4) | (1 << 2);   // Reloj de GPIOC y GPIOA

    *(volatile int *)(0x40011004) = (3 << 20);              // PC13: salida push-pull 50 MHz (LED placa)
    *(volatile int *)(0x40010800) = (8 << 4);               // PA1: entrada con pull-down (CNF=10, MODE=00)

    while(1) {
        if (*(volatile int *)(0x40010808) & (1 << 1)) {     // ¿PA1 en alto (3.3 V)?
            *(volatile int *)(0x4001100C) = 0;              // Sí -> PC13 = 0 -> LED ENCENDIDO
        } else {
            *(volatile int *)(0x4001100C) = (1 << 13);      // No -> PC13 = 1 -> LED APAGADO
        }
    }

    return 0;
}
