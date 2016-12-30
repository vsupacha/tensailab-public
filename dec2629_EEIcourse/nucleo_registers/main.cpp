#include "mbed.h"

int main() {
    // setup
    RCC->AHB1ENR |= ( (1 << 2) | (1 << 0));
    // 0001            0100    |   0001 =     0101
    // ****  |  0101   =  *1*1
    // PA5 output (01), push-pull (0), low-speed (00)
    GPIOA->MODER |= (1 << 10);
    GPIOA->MODER &= ~(1 << 11);
    // 0001      1110
    // ****  &  1110  =  ***0
    GPIOA->OTYPER &= ~(1 << 5);
    GPIOA->OSPEEDR &= ~( (1 << 11) | (1 << 10) );
    // PC13 input (00), no pull (00)
    GPIOC->MODER &= ~( (1 << 27) | (1 << 26) );
    GPIOC->PUPDR &= ~( (1 << 27) | (1 << 26) );
    
    while(1) {
        // loop
        if (GPIOC->IDR & (1 << 13)) {
            GPIOA->ODR |= (1 << 5);  // ON
            wait(0.2);
            GPIOA->ODR &= ~(1 << 5); // OFF
            wait(0.2);
        }
    }
}
