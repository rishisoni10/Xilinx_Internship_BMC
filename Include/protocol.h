/*
 * protocol.h
 *
 *  Created on: Jul 13, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_PROTOCOL_H_
#define INCLUDE_PROTOCOL_H_



uint8_t Get_cmd(void);
void adc_menu(void);
void voltage_regulator_menu(void);
void voltage_read_menu(void);
void voltage_write_menu(void);
void gpio_menu(void);
void LFXT_test_on(void);
void HFXT_test_on(void);
void ping_menu(void);
void remote_fan_temp(void);
void build_version(void);
void bsl_mode(void);
void current_reading(void);


#endif /* INCLUDE_PROTOCOL_H_ */
