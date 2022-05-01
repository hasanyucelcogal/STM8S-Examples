//HASAN YUCEL COGAL

#include "stm8s.h"
// FCPU=2MHz
/* PORT D SETTINGS*/
#define _SFR_(mem_addr)     (*(volatile uint8_t *)(0x5000 + (mem_addr)))
#define PD_ODR      _SFR_(0x0F)
#define PD_DDR      _SFR_(0x11)
#define PD_CR1      _SFR_(0x12)
#define D0_PIN     0

//USE TIM4 BASIC TIMER
void delay(uint16_t ms){
    for(uint16_t i=0;i<ms;i++){

        // f CK_CNT = f CK_PSC /2 (PSCR[2:0])
        // 1 ms delay
   
        TIM4->PSCR=2; //prescaler = 4
        TIM4->ARR=250-1; //auto reload value = 250
        TIM4->CR1 |=TIM1_CR1_CEN;
        while(!(TIM4->SR1 & TIM4_SR1_UIF));
        TIM4->SR1 &= ~TIM4_SR1_UIF;
    }
}
void main() {
   
    PD_DDR |= (1 << D0_PIN); // PD0  output
    PD_CR1 |= (1 << D0_PIN); // push-pull mode

    while (1) {

        PD_ODR ^= (1 << D0_PIN);
        delay(1000);
    }
}