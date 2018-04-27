/*
 * fan_ctrl_lm96163.c
 *
 *  Created on: Aug 25, 2017
 *      Author: Rishi Soni
 */

#include "main.h"


uint8_t lut_temp[12] = {
    LUT_TEMP01,
    LUT_TEMP02,
    LUT_TEMP03,
    LUT_TEMP04,
    LUT_TEMP05,
    LUT_TEMP06,
    LUT_TEMP07,
    LUT_TEMP08,
    LUT_TEMP09,
    LUT_TEMP10,
    LUT_TEMP11,
    LUT_TEMP12
};

uint8_t lut_pwm[12] = {
    LUT_PWM01,
    LUT_PWM02,
    LUT_PWM03,
    LUT_PWM04,
    LUT_PWM05,
    LUT_PWM06,
    LUT_PWM07,
    LUT_PWM08,
    LUT_PWM09,
    LUT_PWM10,
    LUT_PWM11,
    LUT_PWM12
};

void lm96063_init(void)
{
	uint8_t i, status;
	uint8_t channel_buf[1] = {FAN_PORT};
	uint8_t txbuf0[1] = {0x33}; 										//POR Status Register
	uint8_t txbuf1[2] = {0x4A, 0x30};									//PWM & RPM Config Register
	uint8_t txbuf2[1] = {0x4B};											//Fan Spin-Up Config Register
	uint8_t txbuf3[2] = {0x4D, 0x12};									//PWM Frequency Register (PWM Output Frequency 10kHz)
	uint8_t txbuf4[1] = {0x45};											//Enhanced Config Register
	uint8_t txbuf5[2] = {PWM_TACH_CFG_ADDR, PWM_TACH_CFG_DATA};			//Reset the PWM config regsiter
	uint8_t txbuf6[1] = {0x4C};
	uint8_t lut_temp_buf[2];
	uint8_t lut_pwm_buf[2];

	uint8_t rxbuf0[] = {0}, rxbuf1[] = {0}, rxbuf2[] = {0}, rxbuf3[] = {0}, rxbuf4[] = {0};

	//Initialization sequence for LM96063 Fan Control Registers (Datasheet: Page no. 20)
	i2c3_send(I2C3_MUX_ADDR, channel_buf, 1);       //Set I2C MUX to PMBUS
	delay_cycles(DELAY_1250000);

	i2c3_send_rs_recv(FAN_ADDR, txbuf0, 1, rxbuf0, 1);		//Step 1

	if(!((rxbuf0[0] & 0x80) >> 7))
		printf("\n\rNot Ready bit cleared on POR\n\r");

	status = i2c3_send(FAN_ADDR, txbuf1, 2);				//Step 2 (Inverted PWM input)
	if(status == FUNC_SUCCESS)
		printf("Inverted PWM Mode\n\r");

//	i2c3_send(FAN_ADDR, txbuf2, 1); 						//Step 3 (commented out as using default values for initial code testing)


//	i2c3_send(FAN_ADDR, txbuf3, 2);							//Step 4 (commented out as using default values for initial code testing)

	for (i = 0; i < LUT_SIZE; i++)							//Step 5 (Populating the Lookup Table)
	{

		lut_temp_buf[0] = (uint8_t)LUT_START_ADDR + (i*2);
		lut_temp_buf[1] = lut_temp[i];

		lut_pwm_buf[0] = (uint8_t)LUT_START_ADDR + ((i*2) + 1);
		lut_pwm_buf[1] = lut_pwm[i];

//		status = i2c3_send(FAN_ADDR, lut_temp_buf, 2);
		status = i2c3_send_rs_recv(FAN_ADDR, lut_temp_buf, 2, rxbuf1, 1);

		if (status == FUNC_SUCCESS)
			printf("LUT_TEMP%d entry write successful\n\r", i);

		status = FUNC_FAILED;

//		status = i2c3_send(FAN_ADDR, lut_pwm_buf, 2);
		status = i2c3_send_rs_recv(FAN_ADDR, lut_pwm_buf, 2, rxbuf2, 1);

		i2c3_send_rs_recv(FAN_ADDR, txbuf6, 1, rxbuf4, 1);
		printf("\n\rCurrent PWM value in Lookup Table\n\r: 0x%02x", rxbuf4[0]);

		if (status == FUNC_SUCCESS)
			printf("LUT_PWM%d entry write successful\n\r", i);
	}
//	status = FUNC_FAILED;
//	status = i2c3_send(FAN_ADDR, txbuf5, 2);
//	if (status == FUNC_SUCCESS)
//		printf("PWM_TACH_CFG_DATA entry write successful\n\r");

}
