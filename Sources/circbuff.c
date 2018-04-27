/*
 * circbuff.c
 *
 *  Created on: Jul 11, 2017
 *      Author: Rishi Soni
 */
#include "circbuff.h"
void circbuff_init(circbuff_t buffer, uint8_t size)
{
    buffer._first = 0;                  // Initialize counter values to 0
    buffer._last = 0;
    buffer.num_bytes = 0;               //No data in the buffer
    buffer.buff_empty_flag = 1;         // Show that the buffer is empty
    buffer.buff_full_flag = 0;          // Buffer is not full
    buffer.buff_ovf_flag = 0;           // Overflow has not occurred
}


