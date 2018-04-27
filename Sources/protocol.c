/*
 * protocol.c
 *
 *  Created on: Jul 13, 2017
 *      Author: Rishi Soni
 */

#include "main.h"
extern void gpio_out_fpga(void);
extern void gpio_fpga_loopback(void);
//#define LFXTBYPASS
volatile uint8_t counter = 0;
uint8_t Get_cmd(void)
{
    uint8_t status_flag = 1;
    uint8_t cmd;
    while(status_flag)
    {
        printf("\r\n     *** Main Menu ***\n\r");
        printf("\n\r1. Read all ADC channels\n\r");
        printf("2. Read / Write Voltage Regulator Values\n\r");
        printf("3. Adjust GPIO Settings\n\r");
        printf("4. Ping Menu\n\r");
//		printf("5. Test LFXT Crystal using Real-Time Clock (RTC)\n\r");
		printf("5. Test HFXT Crystal using ADCs\n\r");
		printf("6. Check Fan temperature\n\r");
		printf("7. Print out Build Version Info\n\r");
		printf("8. Measure the current on the VCCINT rail\n\r");
		printf("9. Go into the BSL mode (Not yet implemented)\n\r");
		printf("A. Initialize fan controller for speed setting according to remote temp (Not working yet. Needs some work)\n\r");
        printf("0. Device goes in Sleep Mode\n\r");
        printf("Select an option\n\r");

        cmd = getchar();

        switch(cmd)
        {
        	case '1': adc_all_channels(0); break;
//			case '1': adc_menu(); break;
			case '2': voltage_regulator_menu(); break;
		    case '3': gpio_menu(); break;
			case '4': ping_menu(); break;
//			case '5': LFXT_test_on(); break;
			case '5': HFXT_test_on(); break;
			case '6': remote_fan_temp(); break;
			case '7': build_version(); break;
			case '8': current_reading(); break;
			case '9': bsl_mode(); break;
			case 'a':
			case 'A': lm96063_init();
			case '0': status_flag = 0; break;
			default: printf("\r\nInvalid command. Please enter again\r\n"); break;
        }
    }
    return cmd;
}

void build_version(void)
{
	printf("Version: v0.5.6\n\r");
	printf("\n\rDate:2017-08-25\n\r");
	printf("Time:1800 hrs\n\r");
}

void adc_menu(void)
{
    uint8_t cmd, done = 1;

    while(done)
    {
        printf("\n\r     *** ADC Menu ***\n\r");
        printf("1. Get all ADC values\n\r");
        printf("2. Get ADC value of a single channel\n\r");
        printf("0. Return to Main Menu\n\r");
        printf("Enter option\n\r");

        cmd = getchar();

        switch(cmd)
        {
            case '1': adc_all_channels(0); break;
            case '2': adc_channel_menu(); break;
            case '0': done = 0; break;
        }

    }
}
void gpio_menu(void)
{
    uint8_t cmd, done = 1;

   while(done)
   {
       printf("\n\r     *** GPIO Menu ***\n\r");
       printf("1. Read DIPSW\n\r");
       printf("2. Toggle LEDs\n\r");
       printf("3. Read GPIO input\n\r");
       printf("4. Sequence expo Enables OFF\n\r");
       printf("5. Sequence expo Enables ON\n\r");
       printf("6. Set JTAG_OE High\n\r");
       printf("7. Read expo Good Status\n\r");
       printf("8. Read expo Enable Status\n\r");
       printf("9. Send and Read data on FPGA GPIO\n\r");
       printf("a. Toggle GPIO to FPGA\n\r");
       printf("b. Read 12V_AUX present signals\n\r");
       printf("c. Read FAN_ALERTn signal\n\r");
       printf("d. Loopback test\n\r");
       printf("e. Toggle MSP432 JTAG pins\n\r");
       printf("f. Toggle PEX I2C pins\n\r");
       printf("0. Return to Main Menu\n\r");
       printf("Enter option\n\r");

       cmd = getchar();

       switch(cmd)
       {
           case '1': dipsw_in(); break;
           case '2': led_toggle(); break;
           case '3': gpio_in(); break;
           case '4': gpio_pwr_enable_off(); break;
           case '5': gpio_pwr_enable_on(); break;
           case '6': jtag_oe_high(); break;
           case '7': gpio_get_pwr_good(); break;
           case '8': gpio_get_pwr_enable(); break;
           case '9': gpio_out_fpga(); break;
           case 'a':
           case 'A': gpio_out_toggle(); break;
           case 'b':
           case 'B': gpio_get_12vaux(); break;
           case 'c':
           case 'C': gpio_get_fan_alert(); break;
           case 'd':
           case 'D': gpio_fpga_loopback(); break;
           case 'e':
           case 'E': gpio_out_JTAG_toggle(); break;
           case 'f':
           case 'F': gpio_out_PEX_I2C_toggle(); break;
           case '0': done = 0; break;
       }

   }
//    printf("\n\rLED test\n\r");
//    uint8_t i = 50;
////    P1DIR |= BIT0;
////    P2DIR |= BIT2;
//    P9DIR |= (BIT6 | BIT7);
//    P6DIR |= BIT4;
//    while(i > 0)
//    {
//        P9OUT ^= (BIT6 | BIT7);
//        delay_cycles (DELAY_1250000);   //50ms delay
//        delay_cycles (DELAY_1250000);   //50ms delay
//        P6OUT ^= BIT4;
//        delay_cycles (DELAY_1250000);   //50ms delay
//        delay_cycles (DELAY_1250000);   //50ms delay
//        i--;
//    }
//    P1OUT &= ~(BIT0);
//    P2OUT &= ~(BIT2);
}

void adc_channel_menu(void)
{
     printf("\n\r     *** ADC Channel Select Menu *** \n\r");
     printf("\n\rSelect the ADC channel to read:\n\r");
     printf("0. Channel 0 (A0)\n\r");
     printf("1. Channel 1 (A1)\n\r");
     printf("2. Channel 2 (A2)\n\r");
     printf("3. Channel 3 (A3)\n\r");
     printf("4. Channel 4 (A4)\n\r");
     printf("5. Channel 5 (A5)\n\r");
     printf("6. Channel 6 (A6)\n\r");
     printf("7. Channel 7 (A7)\n\r");
     printf("8. Channel 8 (A8)\n\r");
     printf("9. Channel 9 (A9)\n\r");
     printf("A. Channel 10 (A10)\n\r");
     printf("B. Channel 11 (A11)\n\r");
     printf("C. Channel 12 (A12)\n\r");
     printf("D. Channel 13 (A13)\n\r");
     printf("E. Channel 14 (A14)\n\r");
     printf("F. Channel 15 (A15)\n\r");
     printf("G. Channel 16 (A16)\n\r");
     printf("H. Channel 17 (A17)\n\r");
     printf("I. Channel 18 (A18)\n\r");
     printf("J. Channel 19 (A19)\n\r");
     printf("K. Channel 20 (A20)\n\r");
     printf("L. Channel 21 (A21)\n\r");
     printf("M. Channel 22 (A22)\n\r");
     printf("N. Channel 23 (A23)\n\r");
     printf("\n\rSelect an option\n\r");

     uint8_t channel = getchar();
     float value = adc_single_channel(channel, 0);
     if (channel <= '9')
    	 printf("\n\rVoltage on channel - %d is %.5f Volts", (channel - 48), value);
     else
    	 printf("\n\rVoltage on channel - %d is %.5f Volts", (channel - 55), value);
}

void voltage_regulator_menu(void)
{
    uint8_t cmd, done = 1;

    while(done)
    {
        printf("\n\r     *** Voltage Regulator Menu ***\n\r");
        printf("1. Read voltage regulator values\n\r");
        printf("2. Set voltage regulator values\n\r");
        printf("0. Return to Main Menu\n\r");
        printf("Select an option:\n\r");
        cmd = getchar();
        switch(cmd)
        {
            case '1': voltage_read_menu(); break;
            case '2': printf("\n\rNot yet implemented\n\r"); break;
            case '0': done = 0; break;
        }
    }
}

void voltage_read_menu(void)
{
    uint8_t cmd, done = 1;

    while(done)
    {
        printf("\n\r     *** Voltage Regulator READ Menu ***\n\r");
        printf("1. Read PMBUS for VCCINT using I2C3\n\r");
        printf("2. Read PMBUS for VCCINT using I2C0\n\r");
//        printf()
        printf("3. Read \n\r");
//        printf("3. Set voltage regulator values\n\r");
        printf("0. Return to Main Menu\n\r");
        printf("Select an option:\n\r");
        cmd = getchar();
        switch(cmd)
        {
            case '1': pmbus_voltage_read_3(pmbus_addr_0x44); break;
            case '2': pmbus_voltage_read_0(pmbus_addr_0x44); break;
            case '0': done = 0; break;
        }
    }
}

//void voltage_read_menu(void)
//{
//
//}


void current_reading(void)
{
	float current;
	int16_t Y;
	int8_t expo;
	uint8_t flag = 0, cmd, page_reg, status;
	uint8_t rxbuf0[] = {0};
	uint8_t rxbuf1[] = {0};
	uint8_t channel_buf[1] = {PMBUS_PORT};
	uint8_t txbuf[1] = {0x8C};				//PMBUS command: READ_IOUT
	uint8_t channel0[2] = {0x00, 0x00};
	uint8_t channel1[2] = {0x00, 0x01};
	uint16_t append = 0;
	i2c3_send(I2C3_MUX_ADDR, channel_buf, 1);       //Set I2C MUX to PMBUS
	delay_cycles(DELAY_1250000);
//	printf("\n\rEnter the current channel to be read (0/1)\n\r");
//	cmd = getchar();
//
//	if (cmd == '0')
//	{
	printf("\n\r***Press 'q' to stop current measurement\n\r\n\r");
	while(UART_RX_BUFF != 'q')
	{
		i2c3_send(VCCINT_ADDR, channel0, 2);			//selecting channel 0
		i2c3_send_rs_recv(VCCINT_ADDR, txbuf, 1, rxbuf0, 2);

//		printf("\n\rMSB = 0x%x\n\r", rxbuf0[1]);
//		printf("LSB = 0x%x\n\r", rxbuf0[0]);

		expo = rxbuf0[1] & 0xF8;

		if ((expo & 0x80) >> 7)
			flag = 1;

		expo = ~expo + 1;
		expo = (((expo & 0x80) >> 7) * 16) + (((expo & 0x40) >> 6) * 8) + (((expo & 0x20) >> 5) * 4) + (((expo & 0x10) >> 4) * 2) + (((expo & 0x08) >> 3) * 1);

		if(flag)
		{
			expo = expo * (-1);
			flag = 0;
		}

		Y = ((rxbuf0[1] & 0x07) << 8) | rxbuf0[0];
		current = Y * pow(2, expo);
		printf("value of current in one phase (channel 0) is: %.5f A\n\r", current);

		delay_cycles(DELAY_1250000);    //50ms delay
//	}
//
//	else if (cmd == '1')
//	{
		flag = 0;
		i2c3_send(VCCINT_ADDR, channel1, 2);			//selecting channel 1
		i2c3_send_rs_recv(VCCINT_ADDR, txbuf, 1, rxbuf1, 2);

//		printf("MSB = 0x%x\n\r", rxbuf1[1]);
//		printf("LSB = 0x%x\n\r", rxbuf1[0]);

		expo = rxbuf1[1] & 0xF8;

		if ((expo & 0x80) >> 7)
			flag = 1;
		expo = ~expo + 1;
		expo = (((expo & 0x80) >> 7) * 16) + (((expo & 0x40) >> 6) * 8) + (((expo & 0x20) >> 5) * 4) + (((expo & 0x10) >> 4) * 2) + (((expo & 0x08) >> 3) * 1);

		if(flag)
		{
			expo = expo * (-1);
			flag = 0;
		}

		Y = ((rxbuf1[1] & 0x07) << 8) | rxbuf1[0];
		current = Y * pow(2, expo);
		printf("value of current in one phase (channel 1) is: %.5f A\n\r", current);
//	}

//	printf("\n\rValue of PAGE register is 0x%x\n\r", page_reg);

//	status = i2c3_send_rs_recv(VCCINT_ADDR, txbuf, 1, rxbuf, 2);
//
//	printf("MSB = 0x%x\n\r", rxbuf[1]);
//	printf("LSB = 0x%x\n\r", rxbuf[0]);
//
//	expo = rxbuf[1] & 0xF8;
////	printf("raw value of N: 0x%x", expo);
//
//	if ((expo & 0x80) >> 7)
//		flag = 1;
//	expo = ~expo + 1;
//	expo = (((expo & 0x80) >> 7) * 16) + (((expo & 0x40) >> 6) * 8) + (((expo & 0x20) >> 5) * 4) + (((expo & 0x10) >> 4) * 2) + (((expo & 0x08) >> 3) * 1);
//
//	if(flag)
//	{
//		expo = expo * (-1);
//		flag = 0;
//	}
//	if((rxbuf[1] & 0x04) >> 2)
//		flag = 1;
//	Y = ((rxbuf[1] & 0x07) << 8) | rxbuf[0];
//	current = Y * pow(2, expo);
//	printf("value of current in one phase is: %.5f", current);

//	delay_cycles(DELAY_1250000);    //50ms delay

//	if(!status)
//	  printf("Current read success\r\n");
//	else
//	  printf("Current read failed\r\n");
//	delay_cycles(DELAY_1250000);
	delay_cycles(DELAY_1s);
	printf("\n\r");
	}
}


void gpio_config(void)
{
    P7DIR |= BIT3 | BIT4 | BIT5 | BIT6 | BIT7;      //VCCINT_EN, VCC0V85_EN, VCC1V2_EN, MGT0V9AVCC_EN, VCC1V8_EN
}


void LFXT_test_on(void)
{
    // Configure Port J
//    PJ->DIR |= (BIT2 | BIT3);
//    PJ->OUT &= ~(BIT2 | BIT3);
    uint8_t j = 100;

    PJ->SEL0 |= BIT0 | BIT1;                // set LFXT pin as second function
    CS->KEY = CS_KEY_VAL ;                  // Unlock CS module for register access
    CS->CTL2 |= CS_CTL2_LFXT_EN;            // LFXT on

    delay_cycles(DELAY_1250000);      //50ms delay for clock to settle down

    // Loop until XT1, XT2 & DCO fault flag is cleared
    while ((SYSCTL->NMI_CTLSTAT | SYSCTL_NMI_CTLSTAT_CS_FLG) && (CS->IFG & CS_IFG_LFXTIFG) && j > 0) // Test oscillator fault flag
    {
        // Clear XT2,XT1,DCO fault flags
       CS->CLRIFG |= CS_CLRIFG_CLR_DCOR_OPNIFG | CS_CLRIFG_CLR_HFXTIFG | CS_CLRIFG_CLR_LFXTIFG | CS_CLRIFG_CLR_FCNTLFIFG;
       SYSCTL->NMI_CTLSTAT &= ~ SYSCTL_NMI_CTLSTAT_CS_SRC;
       j--;
    }
#ifdef LFXTBYPASS							//Force fault in LFXT crystal
    CS->CTL2 |= CS_CTL2_LFXTBYPASS;
#else
    CS->CTL2 &= ~CS_CTL2_LFXTBYPASS;
    CS->CLRIFG |= CS_CLRIFG_CLR_LFXTIFG;

    // Select ACLK as LFXTCLK
    CS->CTL1 &= ~(CS_CTL1_SELA_MASK) | CS_CTL1_SELA_0;
    CS->KEY = 0;                            // Lock CS module from unintended accesses

    // Configure RTC

    // Unlock RTC key protected registers
    RTC_C->CTL0 = RTC_C_KEY;
    RTC_C->CTL13 = RTC_C_CTL13_HOLD |       // Hold the RTC for now
            RTC_C_CTL13_MODE;               // Set the RTC to calendar mode

    RTC_C->PS1CTL = RTC_C_PS1CTL_RT1IP__128 | // set divider to 128
            RTC_C_PS1CTL_RT1PSIE;           // Enable pre-scaler interrupt enable
    RTCSEC = 0;
    RTCMIN = 0;
    // Start RTC calendar mode
    RTC_C->CTL13 = RTC_C->CTL13 & ~(RTC_C_CTL13_HOLD);

    // Lock the RTC registers
    RTC_C->CTL0 = RTC_C->CTL0 & ~(RTC_C_CTL0_KEY_MASK);

    // Enable global interrupt
    __enable_irq();

    // Enable the RTC_C in the NVIC module
    NVIC->ISER[0] = 1 << ((RTC_C_IRQn) & 31);

//    while (1)
//    {
//        __sleep();
//    }
#endif
//    if(CS->IFG & CS_IFG_LFXTIFG)
//        printf("\n\rLFXT clock FAILED\n\r");
}

// RTC interrupt service routine
void RTC_C_IRQHandler(void)
{
    if ((RTC_C->PS1CTL & RTC_C_PS1CTL_RT1PSIFG))
    {
		//P9.7 = Green LED
		P9OUT ^= BIT7;
//        printf("%dmin %ds\n\r", RTCMIN, RTCSEC);			//Prints the time from start of RTC every 1 second
        // Clear the pre-scalar timer interrupt flag
        RTC_C->PS1CTL &= ~(RTC_C_PS1CTL_RT1PSIFG);
    }
}


void ping_menu(void)
{
    uint8_t cmd, done = 1;
	while(done)
	{
		printf("\n\r     *** PING I2C Menu ***\n\r");
		printf("1. Ping test I2C_MAIN\n\r");
		printf("2. Ping PCA9536\n\r");
		printf("3. Ping SYSMON\n\r");
		printf("4. Ping Repeated Start PCA9536\n\r");
		printf("5. Disable FPGA Config (M0_0 = 0)\n\r");
		printf("6. Enable  FPGA Config (M0_0 = 1)\n\r");
		printf("0. Return to Main Menu\n\r");
		printf("Select an option:\n\r");
		cmd = getchar();
		switch(cmd)
		{
			case '1': pingtest_i2c3(); break;
			case '2': pingtest_pca9536(); break;
			case '3': pingtest_rs_sysmon(); break;
			case '4': pingtest_rs_pca9536(); break;
			case '5': config_disable_rs_pca9536(); break;
			case '6': config_enable_rs_pca9536(); break;
			case '0': done = 0; break;
		}
	}
}

void HFXT_test_on(void)
{
	adc_all_channels(1);	//HFXT test ON
}

//Reading from LM96063
void remote_fan_temp(void)
{
	uint8_t cmd, N, MSB_temp;
	float LSB_temp, final_temp;
	uint8_t status;
	uint8_t rxbuf1[1] = {0};
	uint8_t rxbuf2[1] = {0};
	uint8_t rxbuf3[1] = {0};
	uint8_t channel_buf[1] = {FAN_PORT};
	uint8_t txbuf1[1] = {0x31};					//Reading Remote temperature MSB - must be read first before LSB as per datasheet
	uint8_t txbuf2[1] = {0x32};					//Reading Remote temperature LSB
	uint8_t dig_filt[2] = {0xBF, 0x06}; 		//Enhanced Filter level 2 (maximum filtering)
	printf("\n\rDigital Filter is OFF by default\n\r");
	printf("Turn - ON digital filter? (y/n): \n\r");
	cmd = getchar();

	if (cmd == 'n' || cmd == 'N')
	{
		printf("\n\rEnter the number of times fan temperature should be displayed\n\r");
		printf("1. Once\n\r");
		printf("2. 10 times\n\r");
		printf("3. 25 times\n\r");
		printf("4. 50 times\n\r");
		printf("5. 100 times\n\r");
		printf("***Press 'q' to interrupt printing\n\r");
		cmd = getchar();
		switch(cmd)
		{
			case '1': N = 1; break;
			case '2': N = 10; break;
			case '3': N = 25; break;
			case '4': N = 50; break;
			case '5': N = 100; break;
		}
		printf("\n\r");
		while(N > 0 && UART_RX_BUFF != 'q')
		{
			i2c3_send(I2C3_MUX_ADDR, channel_buf, 1);       //Set I2C MUX to PMBUS
			delay_cycles(DELAY_1250000);

			status = i2c3_send_rs_recv(FAN_ADDR, txbuf1, 1, rxbuf1, 1);
			delay_cycles(DELAY_1250000);
			status = i2c3_send_rs_recv(FAN_ADDR, txbuf2, 1, rxbuf2, 1);

//			printf("MSB: 0x%x\n\r", rxbuf1[0]);
//			printf("LSB: 0x%x\n\r", rxbuf2[0]);
			MSB_temp = (((rxbuf1[0] & 0x80) >> 7) * 128) + (((rxbuf1[0] & 0x40) >> 6) * 64) + (((rxbuf1[0] & 0x20) >> 5) * 32) + (((rxbuf1[0] & 0x10) >> 4) * 16) + (((rxbuf1[0] & 0x08) >> 3) * 8) + (((rxbuf1[0] & 0x04) >> 2) * 4) + (((rxbuf1[0] & 0x02) >> 1) * 2) + ((rxbuf1[0] & 0x01) * 1);
			LSB_temp = (((rxbuf2[0] & 0x80) >> 7) * 0.5) + (((rxbuf2[0] & 0x40) >> 6) * 0.25) + (((rxbuf2[0] & 0x20) >> 5) * 0.125);
			final_temp = MSB_temp + LSB_temp;
			printf("Remote Temperature reading: %.3f deg. Celcius\n\r", final_temp);
			delay_cycles(DELAY_1s);    //1s delay
			N--;
		}
	}
	else if (cmd == 'Y' || cmd == 'y')
	{
		i2c3_send(I2C3_MUX_ADDR, channel_buf, 1);      	 				//Set I2C MUX to PMBUS
		i2c3_send_rs_recv(FAN_ADDR, dig_filt, 2, rxbuf3, 1);			//Set Remote Diode temp filter (maximum filtering)
		printf("\n\rFilter register value: 0x%x\n\r", rxbuf3[0]);

		printf("Enter the number of times fan temperature should be displayed\n\r");
		printf("1. Once\n\r");
		printf("2. 10 times\n\r");
		printf("3. 25 times\n\r");
		printf("4. 50 times\n\r");
		printf("5. 100 times\n\r");
		printf("***Press 'q' to interrupt printing\n\r");
		cmd = getchar();
		switch(cmd)
		{
			case '1': N = 1; break;
			case '2': N = 10; break;
			case '3': N = 25; break;
			case '4': N = 50; break;
			case '5': N = 100; break;
		}
		printf("\n\r");
		while(N > 0 && UART_RX_BUFF != 'q')
		{
			i2c3_send(I2C3_MUX_ADDR, channel_buf, 1);       //Set I2C MUX to PMBUS
			delay_cycles(DELAY_1250000);

			status = i2c3_send_rs_recv(FAN_ADDR, txbuf1, 1, rxbuf1, 1);
			delay_cycles(DELAY_1250000);
			status = i2c3_send_rs_recv(FAN_ADDR, txbuf2, 1, rxbuf2, 1);

//			printf("MSB: 0x%x\n\r", rxbuf1[0]);
//			printf("LSB: 0x%x\n\r", rxbuf2[0]);
			MSB_temp = (((rxbuf1[0] & 0x80) >> 7) * 128) + (((rxbuf1[0] & 0x40) >> 6) * 64) + (((rxbuf1[0] & 0x20) >> 5) * 32) + (((rxbuf1[0] & 0x10) >> 4) * 16) + (((rxbuf1[0] & 0x08) >> 3) * 8) + (((rxbuf1[0] & 0x04) >> 2) * 4) + (((rxbuf1[0] & 0x02) >> 1) * 2) + ((rxbuf1[0] & 0x01) * 1);
			LSB_temp = (((rxbuf2[0] & 0x80) >> 7) * 0.5) + (((rxbuf2[0] & 0x40) >> 6) * 0.25) + (((rxbuf2[0] & 0x20) >> 5) * 0.125) + (((rxbuf2[0] & 0x10) >> 4) * 0.0625) + (((rxbuf2[0] & 0x08) >> 3) * 0.03125);
			final_temp = MSB_temp + LSB_temp;
			printf("Remote Temperature reading: %.3f deg. Celcius\n\r", final_temp);
			delay_cycles(DELAY_1s);    //1s delay
			N--;
		}
	}


	if(!status)
	  printf("\r\nVoltage read success\r\n");
	else
	  printf("\r\n Voltage read failed\r\n");
	delay_cycles(DELAY_1250000);
}

//Still needs work
void bsl_mode(void)
{
	printf("Still needs work......\n\r");
	uint32_t BSL_PARAM = 0xFC48FFFF; 	// I2C slave address = 0x48, Interface selection = Auto
	BSL_INVOKE(BSL_DEFAULT_PARAM);		// Call the BSL with given BSL parameters

}
