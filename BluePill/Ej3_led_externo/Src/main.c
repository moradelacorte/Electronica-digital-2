#include <stdint.h>

int main(void){

    *(volatile int *)(0x40021018) |= (1 << 4) | (1 << 2);   // Reloj de GPIOC y GPIOA
    *(volatile int *)(0x40011004) = (3 << 20);              // PC13: salida push-pull 50 MHz (LED placa)
    *(volatile int *)(0x40010800) = (3 << 0);               // PA0: salida push-pull 50 MHz (LED externo)

    *(volatile int *)(0x4001100C) = 0;                      // PC13 = 0 -> LED placa ENCENDIDO (activo en bajo)
    *(volatile int *)(0x4001080C) = 0;                      // PA0  = 0 -> LED externo APAGADO (activo en alto)

    while(1) {
        *(volatile int *)(0x4001100C) ^= (1 << 13);         // Invierte LED de la placa
        *(volatile int *)(0x4001080C) ^= (1 << 0);          // Invierte LED externo

        for (volatile int i = 0; i < 300000; i++) { }       // Retardo
    }

    return 0;
}
