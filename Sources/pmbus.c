/*
 * pmbus.c
 *
 *  Created on: Jul 18, 2017
 *      Author: Rishi Soni
 *
 */


#include "main.h"

//void pmbus_read(void)
//{
//    uint8_t cmd, done = 1;
//
//    while(done)
//    {
//       printf("\n\r     *** PMBUS Read Menu ***\n\r");
//       printf("F. Read the PMBUS at address 0x44 (VCU1525)\n\r");
//       printf("0. Return to Main Menu\n\r");
//       printf("Enter option\n\r");
//
//       cmd = getchar();
//
//       switch(cmd)
//       {
//
//           case '1': pmbus_voltage_read(pmbus_addr_0x44); break;
//           case '0': done = 0; break;
//       }
//
//    }
//}
//
//void pmbus_write(void)
//{
//    uint8_t cmd, done = 1;
//
//    while(done)
//    {
//        printf("\n\r     *** PMBUS Write Menu ***\n\r");
//        printf("1. Write to  PMBUS at address 0x44 (VCU1525)\n\r");
//        printf("0. Return to Main Menu\n\r");
//        printf("Enter option\n\r");
//
//       cmd = getchar();
//
//       switch(cmd)
//       {
//           case '1': pmbus_voltage_write(pmbus_addr_0x44); break;
//           case '0': done = 0; break;
//       }
//
//    }
//}

void pmbus_voltage_read_3(uint8_t pmbus_addr)
{
	uint8_t rxbuf[] = {0};
	uint8_t channel_buf[1] = {PMBUS_PORT};
	uint8_t txbuf[1] = {0x8B};
	uint16_t append = 0;
	i2c3_send(I2C3_MUX_ADDR, channel_buf, 1);       //Set I2C MUX to PMBUS
	delay_cycles(DELAY_1250000);

	uint8_t status = i2c3_send_rs_recv(pmbus_addr, txbuf, 1, rxbuf, 2);
	append = rxbuf[1] << 8 | rxbuf[0];
	float voltage = append * 0.000244140625;
	printf("\n\rVCCINT voltage at PMBUS address 0x%x (using I2C3) is 0x%04x = %.4f\n\r", pmbus_addr, append, voltage);
	delay_cycles(DELAY_1250000);    //50ms delay

	if(!status)
	  printf("\r\nVoltage read success\r\n");
	else
	  printf("\r\n Voltage read failed\r\n");
	delay_cycles(DELAY_1250000);
}


void pmbus_voltage_read_0(uint8_t pmbus_addr)
{
	uint8_t rxbuf[] = {0};
//	uint8_t channel_buf[1] = PMBUS_PORT;
	uint8_t txbuf[1] = {0x8B};
	uint16_t append = 0;

	uint8_t status = i2c0_send_rs_recv(pmbus_addr, txbuf, 1, rxbuf, 2);
	delay_cycles(DELAY_1250000);

	append = rxbuf[1] << 8 | rxbuf[0];
	float voltage = append * 0.000244140625;
	printf("\n\rVCCINT voltage at PMBUS address 0x%x (using I2C0) is 0x%04x = %.4f\n\r", pmbus_addr, append, voltage);
	delay_cycles(DELAY_1250000);    //50ms delay

	if(!status)
	  printf("\r\nVoltage read success\r\n");
	else
	  printf("\r\n Voltage read failed\r\n");
}

void pmbus_voltage_write(uint8_t pmbus_addr)
{
    printf("\r\nSetting voltage value to 1.8 V on the PMBUS address 0x%x\r\n", pmbus_addr);
//            uint32_t set_1V8 = 0x1CCD;
//            uint8_t rxbuf[] = {0};
//    uint8_t txbuf[1] = {0x06};
    uint8_t txbuf2[2] = {0x02, 0x1E};
    uint8_t txbuf3[2] = {0x01, 0x40};
    uint8_t txbuf4[3] = {0x21, 0xCD, 0x1C};
    uint8_t txbuf5[2] = {0x01, 0x80};
//            ping_i2c3(0x75);
//            i2c3_recv(0x75, rxbuf, 2);
//    i2c3_send(0x75, txbuf, 1);              //Select the mux lines
    delay_cycles(DELAY_1250000);    //50ms delay
//            while(1)
//            {
    //Vadj Turn - off
    i2c3_send(pmbus_addr, txbuf2, 2);
    delay_cycles(DELAY_1250000);
//            i2c3_send_rs_recv(0x18, txbuf2, 3, rxbuf, 2);
    //delay_cycles(DELAY_1250000);    //50ms delay
//            }
    //Vadj Turn - off
    i2c3_send(pmbus_addr, txbuf3, 2);
    delay_cycles(DELAY_1250000);

    //Send CMD_Vout
    i2c3_send(pmbus_addr, txbuf4, 3);
    delay_cycles(DELAY_1250000);

    //Vadj Turn - on
    uint8_t status = i2c3_send(pmbus_addr, txbuf5, 2);
    delay_cycles(DELAY_1250000);

    if(!status)
        printf("\r\nVoltage set successfully\r\n");
    else
        printf("\r\n Voltage setting failed\r\n");
}
