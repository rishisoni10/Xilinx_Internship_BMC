/*
 * log.c
 *
 *  Created on: Jul 11, 2017
 *      Author: Rishi Soni
 */

#include "main.h"

void LOG_string(uint8_t *str)
{
    while(*str != '\0')
    {
        UART_putchar(*str++);
    }
}
