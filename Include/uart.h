/*
 * uart.h
 *
 *  Forked from: SC_UART.h
 *  Created on: Jun 13, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_UART_H_
#define INCLUDE_UART_H_

#define UART_BUFFER_SIZE                        32
#define BUFF_SIZE                               UART_BUFFER_SIZE

void UART_init_HFXT_test(void);


void UART_init(void);
void UART_putchar(unsigned char);
uint8_t UART_getchar(void);
void EUSCIA0_IRQHandler(void);

#define CS_DCO_TUNE_25MHz           ((uint32_t)0x00000019)
#define EUSCI_MCTLW_BRF_25MHz        ((uint32_t)0x00000090)

//This file includes MSP430 style component and register definitions for legacy components re-used in MSP432

#define UART_PORT_SEL                           P1SEL0
#define UART_TX_BIT                             BIT3
#define UART_RX_BIT                             BIT2

#define UART1_PORT_SEL                           P2SEL0
#define UART1_TX_BIT                             BIT3
#define UART1_RX_BIT                             BIT2

#define UART_BR0_VAL                            217
#define UART_BR1_VAL                            0

#define UART_RX_BUFF                            UCA0RXBUF
#define UART_TX_BUFF                            UCA0TXBUF
#define UART_CTL0                               UCA0CTL0
#define UART_BRW                                UCA0BRW
#define UART_MCTL                               UCA0MCTLW
#define UART_IFG                                UCA0IFG
#define UART_IE                                 UCA0IE
#define UART_IV                                 UCA0IV

#define UART1_RX_BUFF                            UCA1RXBUF
#define UART1_TX_BUFF                            UCA1TXBUF
#define UART1_CTL0                               UCA1CTL0
#define UART1_BRW                                UCA1BRW
#define UART1_MCTL                               UCA1MCTLW
#define UART1_IFG                                UCA1IFG
#define UART1_IE                                 UCA1IE
#define UART1_IV                                 UCA1IV
#endif /* INCLUDE_UART_H_ */
