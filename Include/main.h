/*
 * main.h
 *  Created on: Jun 13, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

//#define MSP_SYSCTRL                             // Uncomment if using MSP System Controller

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "msp.h"
#include "init.h"
#include "delay.h"
#include "uart.h"
#include "i2c.h"
#include "GPIO.h"
#include "adc.h"
#include "data.h"
#include "circbuff.h"
#include "log.h"
#include "protocol.h"
#include "pmbus.h"
#include "ping_i2c.h"
#include "fan_ctrl_lm96063.h"

#define FUNC_FAILED                             1
#define FUNC_SUCCESS                            0

//extern volatile uint32_t counter;

void pre_init(void);
#endif /* INCLUDE_MAIN_H_ */
