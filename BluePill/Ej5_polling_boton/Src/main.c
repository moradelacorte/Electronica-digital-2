#include <stdint.h>

int main(void){

    *(volatile int *)(0x40021018) |= (1 << 4) | (1 << 2);   // Reloj de GPIOC y GPIOA

    *(volatile int *)(0x40011004) = (3 << 20);              // PC13: salida push-pull 50 MHz (LED placa)
    *(volatile int *)(0x40010800) = (8 << 4);               // PA1: entrada con pull-up/pull-down (CNF=10, MODE=00)

    *(volatile int *)(0x4001080C) |= (1 << 1);              // ODR bit 1 = 1 -> el pull de PA1 es PULL-UP

    while(1) {
        if (*(volatile int *)(0x40010808) & (1 << 1)) {     // PA1 = 1 -> botón SUELTO (pull-up)
            *(volatile int *)(0x4001100C) = (1 << 13);      // PC13 = 1 -> LED APAGADO
        } else {                                            // PA1 = 0 -> botón APRETADO (conectado a GND)
            *(volatile int *)(0x4001100C) = 0;              // PC13 = 0 -> LED ENCENDIDO
        }
    }

    return 0;
}
