#include <stdint.h>

uint32_t onda[2] = { (1 << 0), (1 << 16) };   // BSRR: set PA0 / reset PA0

int main(void){
    *(volatile int *)(0x40021014) |= (1 << 0);                         // reloj DMA1
    *(volatile int *)(0x40021018) |= (1 << 2);                         // reloj GPIOA
    *(volatile int *)(0x4002101C) |= (1 << 0);                         // reloj TIM2
    *(volatile int *)(0x40010800) = (3 << 0);                          // PA0 salida

    *(volatile int *)(0x40020024) = 0x40010810;                        // CPAR2: GPIOA_BSRR
    *(volatile int *)(0x40020028) = (int)onda;                         // CMAR2: arreglo
    *(volatile int *)(0x40020020) = 2;                                 // CNDTR2: 2 datos
    *(volatile int *)(0x4002001C) = (1<<4)|(1<<5)|(1<<7)|(2<<8)|(2<<10); // CCR2
    *(volatile int *)(0x4002001C) |= (1 << 0);                         // habilitar canal

    *(volatile int *)(0x40000028) = 7999;                              // PSC: 1 kHz
    *(volatile int *)(0x4000002C) = 499;                               // ARR: 500 ms   <-- PRUEBA
    // Para el osciloscopio usar:
    //*(volatile int *)(0x40000028) = 0;       // PSC
    //*(volatile int *)(0x4000002C) = 3999;    // ARR -> 1 kHz

    *(volatile int *)(0x4000000C) |= (1 << 8);                         // UDE
    *(volatile int *)(0x40000000) |= (1 << 0);                         // CEN

    while(1) { }
    return 0;
}
