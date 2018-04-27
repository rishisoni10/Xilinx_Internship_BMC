/*
 * data.c
 *
 *  Created on: Jul 6, 2017
 *      Author: Rishi Soni
 */

#include "main.h"

//reverse a char array (string) of length 'len'
void reverse(uint8_t *buffer, uint32_t len)
{
    uint8_t i = 0, temp;
    uint32_t j = len - 1;
    while(i < j)
    {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
        i++; j--;
    }
}
//Converts an integer x to a string buffer[]. 'digits' = no. of digits required in the output
uint32_t itoa(int32_t x, uint8_t buffer[], uint32_t digits)
{
    uint32_t i = 0;
    if (x == 0)
    {
        buffer[i++] = '0';
    }
    while(x)
    {
        buffer[i++] = (x % 10) + '0';
        x = x / 10;
    }

    while(i < digits)
    {
        buffer[i++] = '0';
        //digits--;
    }

    reverse(buffer, i);
    buffer [i] = '\0';
    return i;
}


//Converts floating point number to string
void ftoa(float n, uint8_t *buffer, uint32_t afterpoint)
{
    //Extract integer part
    int32_t int_part = (int32_t)n;

    //Extract floating part
    float float_part = n - (float)int_part;

    //Convert integer part to string
    uint32_t i = itoa(int_part, buffer, 0);

    //Check for numbers after decimal point
    if(afterpoint != 0)
    {
        buffer[i] = '.'; //add decimal point

        // Get the value of fraction part up to required no.
        // of points after dot.

        float_part = float_part * pow(10, afterpoint);
        itoa((int32_t)float_part, buffer + i + 1, afterpoint);

    }
}
