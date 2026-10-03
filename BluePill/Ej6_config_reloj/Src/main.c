#include <stdint.h>

int main(void){

    /* Encender el HSE */
    *(volatile int *)(0x40021000) |= (1 << 16);                       // RCC_CR: HSEON = 1
    while (!(*(volatile int *)(0x40021000) & (1 << 17))) { }          // esperar HSERDY = 1

    /* Configurar prescalers y PLL */
    *(volatile int *)(0x40021004) =                                   // RCC_CFGR
          (1 << 16)      // PLLSRC   = 1    -> el PLL toma el HSE
        | (1 << 17)      // PLLXTPRE = 1    -> HSE dividido por 2
        | (2 << 18)      // PLLMUL   = 0010 -> multiplicador x4
        | (8 << 4)       // HPRE     = 1000 -> AHB  / 2
        | (4 << 8)       // PPRE1    = 100  -> APB1 / 2
        | (5 << 11);     // PPRE2    = 101  -> APB2 / 4

    /* Encender el PLL */
    *(volatile int *)(0x40021000) |= (1 << 24);                       // RCC_CR: PLLON = 1
    while (!(*(volatile int *)(0x40021000) & (1 << 25))) { }          // esperar PLLRDY = 1

    /* Cambiar SYSCLK al PLL */
    *(volatile int *)(0x40021004) |= (2 << 0);                        // SW = 10 -> SYSCLK = PLL
    while (((*(volatile int *)(0x40021004) >> 2) & 3) != 2) { }       // esperar SWS = 10

    /* Micro corre a 16 MHz */

    /* Parpadeo del punto 2 */
    *(volatile int *)(0x40021018) |= (1 << 4);                        // Reloj de GPIOC
    *(volatile int *)(0x40011004) = (3 << 20);                        // PC13: salida push-pull 50 MHz

    while(1) {
        *(volatile int *)(0x4001100C) ^= (1 << 13);                   // Invierte el LED
        for (volatile int i = 0; i < 300000; i++) { }                 // Mismo retardo que el punto 2
    }

    return 0;
}
