#include <stdint.h>

void SysTick_Handler(void) {
    *(volatile int *)(0x4001100C) ^= (1 << 13);                 // alternar LED
}

int main(void){
    *(volatile int *)(0x40021018) |= (1 << 4);                  // reloj GPIOC
    *(volatile int *)(0x40011004) = (3 << 20);                  // PC13 salida

    *(volatile int *)(0xE000E014) = 3999999;                    // RVR: 500 ms
    *(volatile int *)(0xE000E018) = 0;                          // CVR = 0
    *(volatile int *)(0xE000E010) = (1<<2)|(1<<1)|(1<<0);       // CLKSOURCE | TICKINT | ENABLE

    while(1) { }
    return 0;
}
