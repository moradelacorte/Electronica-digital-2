#include <stdint.h>

typedef struct {
    volatile uint32_t CR, CFGR, CIR, APB2RSTR, APB1RSTR,
                      AHBENR, APB2ENR, APB1ENR, BDCR, CSR;
} RCC_t;

typedef struct {
    volatile uint32_t CRL, CRH, IDR, ODR, BSRR, BRR, LCKR;
} GPIO_t;

#define RCC    ((RCC_t  *)0x40021000)
#define GPIOA  ((GPIO_t *)0x40010800)
#define GPIOC  ((GPIO_t *)0x40011000)

int main(void){
    RCC->APB2ENR |= (1 << 4) | (1 << 2);      // reloj GPIOC y GPIOA
    GPIOC->CRH = (3 << 20);                   // PC13 salida push-pull 50 MHz
    GPIOA->CRL = (8 << 4);                    // PA1 entrada con pull
    GPIOA->ODR |= (1 << 1);                   // pull-UP

    while(1) {
        if (GPIOA->IDR & (1 << 1)) {
            GPIOC->ODR = (1 << 13);           // suelto -> LED apagado
        } else {
            GPIOC->ODR = 0;                   // apretado -> LED prendido
        }
    }
    return 0;
}
