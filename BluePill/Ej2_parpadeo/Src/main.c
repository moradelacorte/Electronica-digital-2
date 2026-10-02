#include <stdint.h>


int main(void){

    *(volatile int *)(0x40021018) |= (1 << 4) | (1 << 2);   // Reloj de GPIOC y GPIOA
    *(volatile int *)(0x40011004) = (3 << 20);              // PC13: salida push-pull 50 MHz

    while(1) {
        *(volatile int *)(0x4001100C) ^= (1 << 13);         // Invierte el LED (prende <-> apaga)

        for (volatile int i = 0; i < 300000; i++) { }       // Retardo: perder tiempo contando
    }

    return 0;
}
