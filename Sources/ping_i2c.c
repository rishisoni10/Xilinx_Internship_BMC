/*
 * ping_i2c.c
 *
 *  Created on: Aug 04, 2017
 *      Author: Punit Kalra
 */

#include "main.h"

void pingtest_pca9536(void)
{
    char wbuf[8];
    uint8_t status;

    printf("\n\r");
    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = ping_i2c3((uint8_t)PCA9536_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    } else {
        printf("PING FAILED  I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    }
    delay_cycles(DELAY_1250000);       //50ms delay

}

void config_disable_rs_pca9536(void)
{
    uint8_t wbuf[8];
      uint8_t rbuf[8];
    uint8_t status;

    printf("\n\r");
    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x03;                    //Configuration Port
    wbuf[1] = 0x00;                    //Set as all outputs
    i2c3_send((uint8_t)PCA9536_ADDR, wbuf, 2); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x01;                    // Output Port
    wbuf[1] = 0x00;                    // M0_0 = master serial so no QSPI config
    i2c3_send((uint8_t)PCA9536_ADDR, wbuf, 2); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x00;
    status = FUNC_FAILED;
    status = i2c3_send_rs_recv((uint8_t)PCA9536_ADDR, (uint8_t *)wbuf, (uint64_t)1, (uint8_t *)rbuf, (uint64_t)1);
//    status = ping_i2c3((uint8_t)PCA9536_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("CONFIG_DISABLE RS SUCCESS I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    } else {
        printf("CONFIG_DISABLE RS FAILED  I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    }
    delay_cycles(DELAY_1250000);       //50ms delay

}

void config_enable_rs_pca9536(void)
{
    uint8_t wbuf[8];
      uint8_t rbuf[8];
    uint8_t status;

    printf("\n\r");
    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x03;                    //Configuration Port
    wbuf[1] = 0x00;                    //Set as all outputs
    i2c3_send((uint8_t)PCA9536_ADDR, wbuf, 2); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x01;                    // Output Port
    wbuf[1] = 0xFF;                    // M0_0 = 1, SW_SET1 = 1
    i2c3_send((uint8_t)PCA9536_ADDR, wbuf, 2); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x00;
    status = FUNC_FAILED;
    status = i2c3_send_rs_recv((uint8_t)PCA9536_ADDR, (uint8_t *)wbuf, (uint64_t)1, (uint8_t *)rbuf, (uint64_t)1);
//    status = ping_i2c3((uint8_t)PCA9536_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("CONFIG_DISABLE RS SUCCESS I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    } else {
        printf("CONFIG_DISABLE RS FAILED  I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    }
    delay_cycles(DELAY_1250000);       //50ms delay

}

void pingtest_rs_pca9536(void)
{
    uint8_t wbuf[8];
      uint8_t rbuf[8];
    uint8_t status;

    printf("\n\r");
    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x00;
    status = FUNC_FAILED;
    status = i2c3_send_rs_recv((uint8_t)PCA9536_ADDR, (uint8_t *)wbuf, (uint64_t)1, (uint8_t *)rbuf, (uint64_t)1);
//    status = ping_i2c3((uint8_t)PCA9536_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING RS SUCCESS I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    } else {
        printf("PING RS FAILED  I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
    }
    delay_cycles(DELAY_1250000);       //50ms delay

}

void pingtest_rs_sysmon(void)
{
    uint8_t wbuf[8];
    uint8_t rbuf[8];
    uint8_t status;

    printf("\n\r");
    wbuf[0] = SYSMON_PORT;
    i2c3_send((uint8_t)I2C3_MUX_ADDR, wbuf, (uint64_t)1); // Set I2C mux to SYSMON
//    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = 0x00;
    wbuf[1] = 0x00;
    wbuf[2] = 0x00;  // SYSMON reg 0 has temperature
    wbuf[3] = 0x04;
    status = FUNC_FAILED;
    status = i2c3_send_rs_recv((uint8_t)SYSMON_ADDR, (uint8_t *)wbuf, (uint64_t)4, (uint8_t *)rbuf, (uint64_t)2);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: SYSMON_ADDR 0x%02X\n\r", SYSMON_ADDR);
    } else {
        printf("PING FAILED  I2C3: SYSMON_ADDR 0x%02X\n\r", SYSMON_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay
}

void pingtest_i2c3(void)
{
    char wbuf[8];
    uint8_t status;

    printf("\n\r");
    wbuf[0] = PMBUS_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to PMBUS
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)VCCINT_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: VCCINT_ADDR 0x%02X\n\r", (uint8_t)VCCINT_ADDR);
    } else {
        printf("PING FAILED  I2C3: VCCINT_ADDR 0x%02X\n\r", (uint8_t)VCCINT_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)EEPROM_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: EEPROM_ADDR 0x%02X\n\r", (uint8_t)EEPROM_ADDR);
    } else {
        printf("PING FAILED  I2C3: EEPROM_ADDR 0x%02X\n\r", (uint8_t)EEPROM_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)TEMP_U31_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: TEMP_U31_ADDR 0x%02X\n\r", (uint8_t)TEMP_U31_ADDR);
    } else {
        printf("PING FAILED  I2C3: TEMP_U31_ADDR 0x%02X\n\r", (uint8_t)TEMP_U31_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)TEMP_U37_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: TEMP_U37_ADDR 0x%02X\n\r", (uint8_t)TEMP_U37_ADDR);
    } else {
        printf("PING FAILED  I2C3: TEMP_U37_ADDR 0x%02X\n\r", (uint8_t)TEMP_U37_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = EEPROM_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)TEMP_U50_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: TEMP_U50_ADDR 0x%02X\n\r", (uint8_t)TEMP_U50_ADDR);
    } else {
        printf("PING FAILED  I2C3: TEMP_U50_ADDR 0x%02X\n\r", (uint8_t)TEMP_U50_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay



    wbuf[0] = QSFP1_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to QSPI1
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)QSFP1_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: QSFP1_ADDR 0x%02X\n\r", (uint8_t)QSFP1_ADDR);
    } else {
        printf("PING FAILED  I2C3: QSFP1_ADDR 0x%02X\n\r", (uint8_t)QSFP1_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = SI570_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to SI570
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)SI570_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: SI570_ADDR 0x%02X\n\r", (uint8_t)SI570_ADDR);
    } else {
        printf("PING FAILED  I2C3: SI570_ADDR 0x%02X\n\r", (uint8_t)SI570_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = FAN_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to FAN
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)FAN_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: FAN_ADDR 0x%02X\n\r", (uint8_t)FAN_ADDR);
    } else {
        printf("PING FAILED  I2C3: FAN_ADDR 0x%02X\n\r", (uint8_t)FAN_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = QSFP0_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to QSPI0
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)QSFP0_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: QSFP0_ADDR 0x%02X\n\r", (uint8_t)QSFP0_ADDR);
    } else {
        printf("PING FAILED  I2C3: QSFP0_ADDR 0x%02X\n\r", (uint8_t)QSFP0_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    pingtest_rs_pca9536();

    wbuf[0] = DDR4_SPD_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)SPD0_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: DDR4_SPD0_ADDR 0x%02X\n\r", (uint8_t)SPD0_ADDR);
    } else {
        printf("PING FAILED  I2C3: DDR4_SPD0_ADDR 0x%02X\n\r", (uint8_t)SPD0_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = DDR4_SPD_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)SPD1_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: DDR4_SPD1_ADDR 0x%02X\n\r", (uint8_t)SPD1_ADDR);
    } else {
        printf("PING FAILED  I2C3: DDR4_SPD1_ADDR 0x%02X\n\r", (uint8_t)SPD1_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = DDR4_SPD_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)SPD2_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: DDR4_SPD2_ADDR 0x%02X\n\r", (uint8_t)SPD2_ADDR);
    } else {
        printf("PING FAILED  I2C3: DDR4_SPD2_ADDR 0x%02X\n\r", (uint8_t)SPD2_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

    wbuf[0] = DDR4_SPD_PORT;
    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
    delay_cycles(DELAY_1250000);       //50ms delay
    status = FUNC_FAILED;
    status = ping_i2c3((uint8_t)SPD3_ADDR);
    if(status == FUNC_SUCCESS ) {
        printf("PING SUCCESS I2C3: DDR4_SPD3_ADDR 0x%02X\n\r", (uint8_t)SPD3_ADDR);
    } else {
        printf("PING FAILED  I2C3: DDR4_SPD3_ADDR 0x%02X\n\r", (uint8_t)SPD3_ADDR);
    }
    loop_delay(DELAY_1250000);
    delay_cycles(DELAY_1250000);       //50ms delay

//    wbuf[0] = EEPROM_PORT;
//    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
//    delay_cycles(DELAY_1250000);       //50ms delay
//    status = ping_i2c3((uint8_t)PCA9536_ADDR);
//    if(status == FUNC_SUCCESS ) {
//        printf("PING SUCCESS I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
//    } else {
//        printf("PING FAILED  I2C3: PCA9536_ADDR 0x%02X\n\r", (uint8_t)PCA9536_ADDR);
//    }
//    delay_cycles(DELAY_1250000);       //50ms delay

//    wbuf[0] = SYSMON_PORT;
//    i2c3_send(I2C3_MUX_ADDR, wbuf, 1); // Set I2C mux to EEPROM
//    delay_cycles(DELAY_1250000);       //50ms delay
//    status = FUNC_FAILED;
//    status = ping_i2c3(SYSMON_ADDR);
//    if(status == FUNC_SUCCESS ) {
//        printf("PING SUCCESS I2C3: SYSMON_ADDR 0x%02X\n\r", SYSMON_ADDR);
//    } else {
//        printf("PING FAILED  I2C3: SYSMON_ADDR 0x%02X\n\r", SYSMON_ADDR);
//    }
//    loop_delay(DELAY_1250000);
//    delay_cycles(DELAY_1250000);       //50ms delay
}

void loop_delay(long int delay)
{
	long int i;

	for( i = 0; i < delay; i++ );

}


