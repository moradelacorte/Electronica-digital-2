#include <stdint.h>

void EXTI1_IRQHandler(void) {
    *(volatile int *)(0x40010414) = (1 << 1);                       // limpiar EXTI_PR (línea 1)
    if (*(volatile int *)(0x40010808) & (1 << 1)) {                 // PA1 = 1 -> suelto
        *(volatile int *)(0x4001100C) = (1 << 13);                  // LED apagado
    } else {                                                        // PA1 = 0 -> apretado
        *(volatile int *)(0x4001100C) = 0;                          // LED prendido
    }
}

int main(void){
    *(volatile int *)(0x40021018) |= (1 << 0) | (1 << 2) | (1 << 4); // AFIO + GPIOA + GPIOC
    *(volatile int *)(0x40011004) = (3 << 20);                       // PC13 salida
    *(volatile int *)(0x40010800) = (8 << 4);                        // PA1 entrada con pull
    *(volatile int *)(0x4001080C) |= (1 << 1);                       // pull-UP
    *(volatile int *)(0x4001100C) = (1 << 13);                       // LED apagado al inicio

    *(volatile int *)(0x40010008) &= ~(0xF << 4);                    // EXTI1 -> PA
    *(volatile int *)(0x40010408) |= (1 << 1);                       // flanco ascendente
    *(volatile int *)(0x4001040C) |= (1 << 1);                       // flanco descendente
    *(volatile int *)(0x40010400) |= (1 << 1);                       // desenmascarar EXTI1
    *(volatile int *)(0xE000E100) |= (1 << 7);                       // habilitar IRQ 7 en NVIC

    while(1) { }
    return 0;
}
