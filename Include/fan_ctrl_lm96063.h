/*
 * fan_ctrl_lm96063.h
 *
 *  Created on: Aug 25, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_FAN_CTRL_LM96063_H_
#define INCLUDE_FAN_CTRL_LM96063_H_

void lm96063_init(void);


#define LUT_TEMP01 0
#define LUT_TEMP02 50
#define LUT_TEMP03 60
#define LUT_TEMP04 65
#define LUT_TEMP05 70
#define LUT_TEMP06 75
#define LUT_TEMP07 80
#define LUT_TEMP08 85
#define LUT_TEMP09 87
#define LUT_TEMP10 90
#define LUT_TEMP11 95
#define LUT_TEMP12 100

#define LUT_PWM01 0x2E
#define LUT_PWM02 0x2E
#define LUT_PWM03 0x2E
#define LUT_PWM04 0x2E
#define LUT_PWM05 0x2E
#define LUT_PWM06 0x2E
#define LUT_PWM07 0x2E
#define LUT_PWM08 0x2E
#define LUT_PWM09 0x2E
#define LUT_PWM10 0x2E
#define LUT_PWM11 0x2E
#define LUT_PWM12 0x2E

#define LUT_START_ADDR    0x50
#define PWM_TACH_CFG_ADDR 0x4A
#define PWM_TACH_CFG_DATA 0x00
#define XFER_COUNT  0x1A
#define LUT_SIZE    12
#define I2CMUXADDR  0x74
#define I2CMUXLEG   0x20
#define LM96163ADDR 0x4C


#endif /* INCLUDE_FAN_CTRL_LM96063_H_ */
