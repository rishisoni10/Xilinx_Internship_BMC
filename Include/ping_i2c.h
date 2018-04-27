/*
 * ping_i2c.h
 *
 *  Created on: Aug 17, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_PING_I2C_H_
#define INCLUDE_PING_I2C_H_


#define I2C3_MUX_ADDR  0x74
#define PMBUS_PORT     0x01
#define QSFP1_PORT     0x02
#define SI570_PORT     0x04
#define FAN_PORT       0x08
#define QSFP0_PORT     0x10
#define EEPROM_PORT    0x20
#define DDR4_SPD_PORT  0x40
#define SYSMON_PORT    0x80

#define VCCINT_ADDR    0x44
#define QSFP0_ADDR     0x50
#define QSFP1_ADDR     0x50
#define SI570_ADDR     0x5D
#define FAN_ADDR       0x4C
#define EEPROM_ADDR    0x54
#define SPD0_ADDR      0x50
#define SPD1_ADDR      0x51
#define SPD2_ADDR      0x52
#define SPD3_ADDR      0x53
#define SYSMON_ADDR    0x32
#define TEMP_U31_ADDR  0x18
#define TEMP_U37_ADDR  0x19
#define TEMP_U50_ADDR  0x1A
#define PCA9536_ADDR   0x41

void pingtest_i2c3(void);
void pingtest_pca9536(void);
void pingtest_rs_sysmon(void);
void pingtest_rs_pca9536(void);
void config_disable_rs_pca9536(void);
void config_enable_rs_pca9536(void);

#endif /* INCLUDE_PING_I2C_H_ */
