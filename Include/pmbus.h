/*
 * pmbus.h
 *
 *  Created on: Jul 18, 2017
 *      Author: rsoni
 */

#ifndef INCLUDE_PMBUS_H_
#define INCLUDE_PMBUS_H_

#define pmbus_addr_0x44     (0x44)          //VCU1525 PMBus

void pmbus_read(void);
void pmbus_write(void);
void pmbus_voltage_read_3(uint8_t);
void pmbus_voltage_read_0(uint8_t);
void pmbus_voltage_write(uint8_t pmbus_addr);

#endif /* INCLUDE_PMBUS_H_ */
