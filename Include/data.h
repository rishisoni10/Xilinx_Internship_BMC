/*
 * data.h
 *
 *  Created on: Jul 11, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_DATA_H_
#define INCLUDE_DATA_H_

uint32_t itoa(int32_t x, uint8_t buffer[], uint32_t digits);
void ftoa(float n, uint8_t *buffer, uint32_t afterpoint);
void reverse(uint8_t *buffer, uint32_t len);

#endif /* INCLUDE_DATA_H_ */
