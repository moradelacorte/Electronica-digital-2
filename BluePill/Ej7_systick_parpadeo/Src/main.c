#include <stdint.h>

int main(void){

    *(volatile int *)(0x40021018) |= (1 << 4);                        // Reloj de GPIOC
    *(volatile int *)(0x40011004) = (3 << 20);                        // PC13: salida push-pull 50 MHz

    /* Valor de recarga para 500 ms (HCLK = 8 MHz) */
    *(volatile int *)(0xE000E014) = 3999999;                          // SYST_RVR

    /* Limpio el contador y la bandera */
    *(volatile int *)(0xE000E018) = 0;                                // SYST_CVR

    /* Encender el SysTick (reloj = HCLK, sin interrupción) */
    *(volatile int *)(0xE000E010) = (1 << 2) | (1 << 0);              // SYST_CSR: CLKSOURCE = 1, ENABLE = 1

    while(1) {
        while (!(*(volatile int *)(0xE000E010) & (1 << 16))) { }      // esperar COUNTFLAG = 1
        *(volatile int *)(0x4001100C) ^= (1 << 13);                   // invertir el LED
    }

    return 0;
}
