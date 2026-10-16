#include <stdint.h>

#define OFF (1 << 13)

uint32_t patron[8] = { 0, OFF, 0, OFF, OFF, OFF, OFF, OFF };

int main(void){
    *(volatile int *)(0x40021014) |= (1 << 0);                         // reloj DMA1
    *(volatile int *)(0x40021018) |= (1 << 4);                         // reloj GPIOC
    *(volatile int *)(0x4002101C) |= (1 << 0);                         // reloj TIM2
    *(volatile int *)(0x40011004) = (3 << 20);                         // PC13 salida

    *(volatile int *)(0x40020024) = 0x4001100C;                        // CPAR2: GPIOC_ODR
    *(volatile int *)(0x40020028) = (int)patron;                       // CMAR2: arreglo
    *(volatile int *)(0x40020020) = 8;                                 // CNDTR2: 8 datos
    *(volatile int *)(0x4002001C) = (1<<4)|(1<<5)|(1<<7)|(2<<8)|(2<<10); // CCR2
    *(volatile int *)(0x4002001C) |= (1 << 0);                         // habilitar canal

    *(volatile int *)(0x40000028) = 7999;                              // PSC
    *(volatile int *)(0x4000002C) = 199;                               // ARR
    *(volatile int *)(0x4000000C) |= (1 << 8);                         // UDE
    *(volatile int *)(0x40000000) |= (1 << 0);                         // CEN

    while(1) { }
    return 0;
}
