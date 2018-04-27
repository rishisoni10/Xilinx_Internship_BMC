/*
 *  main.c
 *  Forked from: SC_main.c
 *  Created on: Jun 13, 2017
 *      Author: Rishi Soni
 */
#include "main.h"

int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;                     // stop watchdog timer
    pre_init();		//Initialization of ports for GPIO, UART, I2C, On - board LEDs
	printf("VCU1525 Data Center Board\n\r");
	printf("MSP432 Board Management Controller(BMC)\n\r");
//    P1DIR |= BIT0;
//    P1OUT &= ~BIT0;			//TCRITn low: Turn - off power supply

    while(1)
    {
        uint8_t i = Get_cmd();
        if (i == '0')
            break;
    }
    printf("\n\rPower-cycle board to wake up device\n\r");

    __sleep();
    __no_operation();       //for debugger
}


//Functions for mapping stdio function "printf" to UART
int putchar(int _x)
{
    UART_putchar((unsigned char)_x);            // Put character
    return ((unsigned char)_x);                 // Return
}

int getchar(void)
{
    return ((int) UART_getchar());              // Return the received character
}

int fputc(int _c, register FILE *_fp)
{
    return putchar(_c);
}

int fputs(const char *_ptr, register FILE *_fp)
{
    unsigned int i, len;
    len = strlen(_ptr);
    for( i = 0; i < len; i++ ) {
        putchar(_ptr[i]);
    }
    return len;
}
