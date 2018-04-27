/*
 * delay.c
 *
 *  Created on: Jun 22, 2017
 *      Author: Rishi Soni
 */

#include "main.h"

/* Description: This delay_cycles() function is similar to the intrinsic MSP430 function '__delay_cycles()'
 *              in functionality. Both functions take an input as the number of cycles to be delayed. Since
 *              both projects have their main system clock (MCLK) running at 25MHz, the values passed for
 *              the counter remains the same for both, MSP430 and MSP432. The use of a timer module (Timer32)
 *              in the MSP432 project can possibly make it more accurate compared to the intrinsic MSP430 function.
 *
 */



void delay_cycles (uint32_t count)
{
    // Oneshot mode, 32-bit counter, MCLK divided by 1 (25MHz)
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ONESHOT | TIMER32_CONTROL_SIZE | TIMER32_CONTROL_PRESCALE_0;
    TIMER32_1->LOAD = count;
    //enable timer interrupts
    __enable_irq();
    //NVIC->ISER[0] = 1 << ((T32_INT1_IRQn) & 31);
    NVIC_EnableIRQ(T32_INT1_IRQn);
    TIMER32_1->INTCLR |= BIT0;  //Clear Timer32 interrupt flag
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE;  //start timer and enable interrupt

    //Waits for interrupt, exits code after returning from ISR
    __sleep();
//    __no_operation();
}


void T32_INT1_IRQHandler(void)
{
    TIMER32_1->INTCLR |= BIT0;  //Clear Timer32 interrupt flag

    //Disable timer and interrupt
    TIMER32_1->CONTROL &= ~(TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_IE);
}
