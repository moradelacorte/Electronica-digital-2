#include <stdint.h>

typedef struct {
    volatile uint32_t CR, CFGR, CIR, APB2RSTR, APB1RSTR,
                      AHBENR, APB2ENR, APB1ENR, BDCR, CSR;
} RCC_t;

typedef struct {
    volatile uint32_t CRL, CRH, IDR, ODR, BSRR, BRR, LCKR;
} GPIO_t;

typedef struct {
    volatile uint32_t EVCR, MAPR, EXTICR[4];
} AFIO_t;

typedef struct {
    volatile uint32_t IMR, EMR, RTSR, FTSR, SWIER, PR;
} EXTI_t;

typedef struct {
    volatile uint32_t ISER[8];
} NVIC_t;

#define RCC    ((RCC_t  *)0x40021000)
#define GPIOA  ((GPIO_t *)0x40010800)
#define GPIOC  ((GPIO_t *)0x40011000)
#define AFIO   ((AFIO_t *)0x40010000)
#define EXTI   ((EXTI_t *)0x40010400)
#define NVIC   ((NVIC_t *)0xE000E100)

void EXTI1_IRQHandler(void) {
    EXTI->PR = (1 << 1);                      // limpiar flag pendiente (línea 1)
    if (GPIOA->IDR & (1 << 1)) {
        GPIOC->ODR = (1 << 13);               // suelto -> LED apagado
    } else {
        GPIOC->ODR = 0;                       // apretado -> LED prendido
    }
}

int main(void){
    RCC->APB2ENR |= (1 << 0) | (1 << 2) | (1 << 4);   // AFIO, GPIOA, GPIOC
    GPIOC->CRH = (3 << 20);                   // PC13 salida
    GPIOA->CRL = (8 << 4);                    // PA1 entrada con pull
    GPIOA->ODR |= (1 << 1);                   // pull-UP
    GPIOC->ODR = (1 << 13);                   // LED apagado al inicio

    AFIO->EXTICR[0] &= ~(0xF << 4);           // EXTI1 -> puerto A
    EXTI->RTSR |= (1 << 1);                   // flanco ascendente
    EXTI->FTSR |= (1 << 1);                   // flanco descendente
    EXTI->IMR  |= (1 << 1);                   // desenmascarar línea 1
    NVIC->ISER[0] |= (1 << 7);                // habilitar IRQ 7 (EXTI1)

    while(1) { }
    return 0;
}
