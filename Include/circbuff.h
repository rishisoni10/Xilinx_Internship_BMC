/*
 * circbuff.h
 *
 *  Created on: Jul 11, 2017
 *      Author: Rishi Soni
 */

#ifndef SOURCES_CIRCBUFF_H_
#define SOURCES_CIRCBUFF_H_


#define BUFFER_SIZE             (32)

#include <stdint.h>

typedef struct _circbuff_t                     // UART RX FIFO buffer
{
    volatile uint8_t buff[BUFFER_SIZE];     // The receive buffer
    volatile uint32_t _first;               // Oldest byte in buff
    volatile uint32_t _last;                // Newest byte in buff
    volatile uint32_t num_bytes;            // Number of bytes in buff
    volatile uint8_t buff_empty_flag;     // Flag to show if the buffer is empty
    volatile uint8_t buff_full_flag;      // Flag to show if the buffer is full
    volatile uint8_t buff_ovf_flag;       // Flag to show that the buffer has overflowed
}circbuff_t;


void circbuff_init(circbuff_t, uint8_t);


#endif /* SOURCES_CIRCBUFF_H_ */
