/*
 * uart.c
 *  Forked from: SC_UART.c
 *  Created on: Jun 13, 2017
 *      Author: Rishi Soni
 */
#include "main.h"
#define BUFF_SIZE                               UART_BUFFER_SIZE

static circbuff_t UART_RX_buffer;              // Make an RX buffer
void UART_init(void)
{
    // RX buffer initialization
    UART_RX_buffer._first = 0;                  // Initialize counter values to 0
    UART_RX_buffer._last = 0;
    UART_RX_buffer.num_bytes = 0;
    UART_RX_buffer.buff_empty_flag = 1;         // Show that the buffer is empty
    UART_RX_buffer.buff_full_flag = 0;          // Buffer is not full
    UART_RX_buffer.buff_ovf_flag = 0;           // Overflow has not occurred

    //UART Configuration
    UART_CTL0 |= UCSWRST;                //eUSCI reset for UART configuration
    UART_CTL0 = UCSSEL_2 | UCSWRST;      //Select eUSCI clock source (SMCLK), while keeping eUSCI in reset mode

    UART_BRW = 13;                       //25000000/16/115200
    UART_MCTL = (EUSCI_MCTLW_BRF_25MHz & EUSCI_A_MCTLW_BRF_MASK) | UCOS16;   //According to reference manual table

    UART_CTL0 &= ~(UCSWRST);     //Activate eUCSI;
    UART_IFG &= ~UCRXIFG;       //Clear eUSCI RX interrupt flag
    UART_IE &= ~UCRXIE;          //Disable eUSCI RX interrupts
    UART_IE &= ~UCTXIE;

    //UART1 to FPGA Configuration
    UART1_CTL0 |= UCSWRST;                //eUSCI reset for UART configuration
    UART1_CTL0 = UCSSEL_2 | UCSWRST;      //Select eUSCI clock source (SMCLK), while keeping eUSCI in reset mode

    UART_BRW = 13;                       //25000000/16/115200
    UART_MCTL = (EUSCI_MCTLW_BRF_25MHz & EUSCI_A_MCTLW_BRF_MASK) | UCOS16;   //According to reference manual table

    UART1_CTL0 &= ~(UCSWRST);     //Activate eUCSI;
    UART1_IFG &= ~UCRXIFG;       //Clear eUSCI RX interrupt flag
    UART1_IE &= ~UCRXIE;          //Disable eUSCI RX interrupts
    UART1_IE &= ~UCTXIE;

    // Left from earlier initialization although UART interrupts are disabled
    //Global interrupt
//    __enable_irq();

    //Enable eUSCI_A0 interrupt in NVIC
//    NVIC->ISER[0] = 1 <<((EUSCIA0_IRQn) & 31);
//    NVIC_EnableIRQ(EUSCIA0_IRQn);
   // UART_TX_BUFF = 65;
}



// Description: Function to send a character from the UART buffer
// Parameters:  unsigned char(uint8_t) to send over UART
// Returns:     None
void UART_putchar(uint8_t char_to_tx)
{
   // UART_IE |= UCTXIE;
    while(!(UART_IFG & UCTXIFG));                 // TX buffer ready?
    UART_TX_BUFF = char_to_tx;                    // Send the char
    UART_IFG &= ~UCTXIFG;
    //UART_IE &= ~UCTXIE;
}

void UART1_putchar(uint8_t char_to_tx)
{
   // UART_IE |= UCTXIE;
    while(!(UART1_IFG & UCTXIFG));                 // TX buffer ready?
    UART1_TX_BUFF = char_to_tx;                    // Send the char
    UART1_IFG &= ~UCTXIFG;
    //UART_IE &= ~UCTXIE;
}

// Description: Function to get a character from the UART buffer
// Parameters:  None
// Returns:     unsigned char(uint8_t) received over UART
uint8_t UART_getchar(void)
{
    /*  while(buffer.buff_empty_flag)
    {
        __bis_SR_register(LPM1_bits);
        __no_operation();
    }*/
//    while(!UART_RX_buffer.buff_empty_flag);
//    UART_IE &= ~UCRXIE;                         // Disable receive interrupt
//    unsigned char char_rx = UART_RX_buffer.buff[UART_RX_buffer._first++];
//    UART_RX_buffer.num_bytes--;                 // Decrease counter value
//    if(UART_RX_buffer._first == BUFF_SIZE)      // Roll over the count if at the end
//    {
//        UART_RX_buffer._first = 0;              // Start over from 0
//    }
//    if(UART_RX_buffer._first == UART_RX_buffer._last)       // If latest and last bytes received are the same, the buffer is empty
//    {
//        UART_RX_buffer.buff_empty_flag = 1;     // Set empty flag if _first == _last
//        UART_RX_buffer.num_bytes = 0;           // Reset counter
//    }
//    UART_RX_buffer.buff_full_flag = 0;          // Since one byte was received, the buffer is not full
//    UART_IE |= UCRXIE;                          // Enable receive interrupt

   // UART_IE |= UCRXIE;                           //Enable eUSCI RX interrupts
    uint8_t char_rx;
    while(!(UCA0IFG & EUSCI_A_IFG_RXIFG));
    char_rx = UART_RX_BUFF;
    UART_TX_BUFF = char_rx;
    while(UART_RX_BUFF != '\r');    //wait for Enter key to be pressed
    UART_IFG &= ~UCRXIFG;
    //UART_IE &= ~UCRXIE;          //Disable eUSCI RX interrupts
    return char_rx;                             // return the first unread char
}

uint8_t UART1_getchar(void)
{
    /*  while(buffer.buff_empty_flag)
    {
        __bis_SR_register(LPM1_bits);
        __no_operation();
    }*/
//    while(!UART_RX_buffer.buff_empty_flag);
//    UART_IE &= ~UCRXIE;                         // Disable receive interrupt
//    unsigned char char_rx = UART_RX_buffer.buff[UART_RX_buffer._first++];
//    UART_RX_buffer.num_bytes--;                 // Decrease counter value
//    if(UART_RX_buffer._first == BUFF_SIZE)      // Roll over the count if at the end
//    {
//        UART_RX_buffer._first = 0;              // Start over from 0
//    }
//    if(UART_RX_buffer._first == UART_RX_buffer._last)       // If latest and last bytes received are the same, the buffer is empty
//    {
//        UART_RX_buffer.buff_empty_flag = 1;     // Set empty flag if _first == _last
//        UART_RX_buffer.num_bytes = 0;           // Reset counter
//    }
//    UART_RX_buffer.buff_full_flag = 0;          // Since one byte was received, the buffer is not full
//    UART_IE |= UCRXIE;                          // Enable receive interrupt

    uint8_t char_rx;
   // UART_IE |= UCRXIE;                           //Enable eUSCI RX interrupts
    while(!(UCA1IFG & EUSCI_A_IFG_RXIFG));
    char_rx = UART1_RX_BUFF;
    UART1_TX_BUFF = char_rx;
    while(UART1_RX_BUFF != '\r');    //wait for Enter key to be pressed
    UART1_IFG &= ~UCRXIFG;
    //UART_IE &= ~UCRXIE;          //Disable eUSCI RX interrupts
    return char_rx;                             // return the first unread char
}

// UART interrupt service routine
//void EUSCIA0_IRQHandler(void)
//{
//    if (UART_IFG & UCRXIFG)
//    {
//        // Check if the TX buffer is empty first
//        while(!(UART_IFG & UCTXIFG));
//
//        // Echo received character back to terminal
//        UART_TX_BUFF = UART_RX_BUFF;
//        UART_IFG &= ~UCRXIFG;
//    }
//}

