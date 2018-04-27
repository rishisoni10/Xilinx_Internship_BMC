/*
 * init.c
 *  Forked from: SC_Init.c
 *  Created on: Jun 13, 2017
 *      Author: Rishi Soni
*/
#include "main.h"

circbuff_t TXBUFF, RXBUFF;

/******************************************************************************
*                       Internally available functions
******************************************************************************/

// Description: Initializes GPIOs
// Parameters:  None
// Returns:     None
void Periph_init(void)
{
	P1SEL1 = 0x00;
	P1SEL0 = 0x00;
	P2SEL1 = 0x00;
	P2SEL0 = 0x00;
	P3SEL1 = 0x00;
	P3SEL0 = 0x00;
	P4SEL1 = 0x00;
	P4SEL0 = 0x00;
	P5SEL1 = 0x00;
	P5SEL0 = 0x00;
	P6SEL1 = 0x00;
	P6SEL0 = 0x00;
	P7SEL1 = 0x00;
	P7SEL0 = 0x00;
	P8SEL1 = 0x00;
	P8SEL0 = 0x00;
	P9SEL1 = 0x00;
	P9SEL0 = 0x00;
	P10SEL1 = 0x00;
	P10SEL0 = 0x00;

    UART_PORT_SEL |= (UART_TX_BIT | UART_RX_BIT);           // Assign UART pins to USCI_A0
    I2C0_PORT_SEL |= (I2C0_SDA_BIT | I2C0_SCL_BIT);         // Assign I2C0 pins to USCI_B0
    //pskI2C1_PORT_SEL |= (I2C1_SDA_BIT + I2C1_SCL_BIT);         // Assign I2C1 pins to USCI_B1

    EUSCI_B3->CTLW0 |= UCSWRST;                  // Enable SW reset USCI_B3
    P6SEL1 |= (BIT6 | BIT7);                     // Assign I2C3 pins to USCI_B3
    EUSCI_B3->CTLW0 &= ~UCSWRST;                 // Clear SW reset USCI_B3, resume operation


    GPIO_init();
}


// Description: Sets DCO clock frequency to 25 MHz (internal resistor mode)
// Parameters:  None
// Returns:     None
void SetMCLK25MHz(void)
{
       CS->KEY = CS_KEY_VAL;                                                 //Unlock CS (Clock System) registers
       CS->CTL0 = 0;                                                         //Tuning parameters reset
       CS->CTL0 = CS_CTL0_DCORSEL_4 | CS_DCO_TUNE_25MHz;                     //DCO frequency Range (MHz): 16 to 32, center frequency: 24, DCOTUNE bits = 0x19

       /* MCLK SOURCE = DCOCLK
        * SMCLK SOURCE = DCOCLK
        * ACLK SOURCE = LFXTCLK
        */
       CS->CTL1 = CS_CTL1_SELA_0 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;

       while(((CS->STAT & CS_STAT_DCO_ON) && (CS->STAT & CS_STAT_MCLK_ON))); //Checking whether the clock source is ON

       CS->KEY = 0;                                                          //Lock Clock module for safety
}

void pre_init(void)
{
//    SetMCLK25MHz_HFXT();                      // Set clock frequency to 25 MHz
    SetMCLK25MHz();                            // Set clock frequency to 25 MHz
    Periph_init();                            // Initialize the GPIOs
    UART_init();                              // Initialize UART
//    UART_init_HFXT_test();
    i2c0_init();                              // Initialize I2C0
    i2c2_init();                              // Initialize I2C2
    i2c3_init();                              // Initialize I2C3
    LFXT_test_on();							  //RTC for board status for blinking Green Status LED
    //jtag_oe_low();
}
