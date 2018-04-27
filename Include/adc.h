/*
 * adc.h
 *
 *  Created on: Jul 10, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

void adc_temp(void);
void adc_pin(void);
void adc_channel_menu(void);
float adc_single_channel(uint8_t, uint8_t);
uint32_t adc_all_channels(uint8_t test);

#endif /* INCLUDE_ADC_H_ */
