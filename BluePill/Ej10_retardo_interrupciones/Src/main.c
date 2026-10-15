#include <stdint.h>

volatile uint32_t ticks = 0;

void SysTick_Handler(void) {
    ticks++;
}

void delay(uint32_t ms) {
    uint32_t inicio = ticks;
    while ((ticks - inicio) < ms) { }
}

int main(void){
    *(volatile int *)(0x40021018) |= (1 << 4);                // reloj GPIOC
    *(volatile int *)(0x40011004) = (3 << 20);                // PC13 salida

    *(volatile int *)(0xE000E014) = 7999;                     // RVR: 1 ms
    *(volatile int *)(0xE000E018) = 0;                        // CVR = 0
    *(volatile int *)(0xE000E010) = (1<<2)|(1<<1)|(1<<0);     // CLKSOURCE | TICKINT | ENABLE

    while(1) {
        *(volatile int *)(0x4001100C) ^= (1 << 13);           // alternar LED
        delay(1000);                                          // 1000 ms = 1s
    }
    return 0;
}
