/*
 * GPIO.c
 *
 *  Forked from: SC_GPIO.c
 *  Created on: Jul 5, 2017
 *      Author: Punit Kalra
 */

#include "main.h"
#define GPIO_CTRL

extern uint8_t UART1_getchar(void);
extern void UART1_putchar(uint8_t);

// Description: Function to initialize GPIOs
// Parameters:  None
// Returns:     None
void GPIO_init(void)
{
	int i;
	int pg_status;
	int pg_status8;

    P2DIR &= ~(BIT0 | BIT1); // INIT_B, DONE
    P2DIR |= (BIT3);         // UCA1_TXD as GPIO output
    P2DIR &= ~(BIT2);        // UCA1_RXD as GPIO input

	P3DIR |= (BIT4);         // JTAG_OE as output
    P3OUT &= ~(BIT4);        // JTAG_OE set low
    P3DIR |= (BIT5);
    P3OUT |= (BIT5);         // MSP_JTAG_EN

    P10DIR |= (BIT4);
    P10OUT |= (BIT4);        // PEX_JTAG_OE
    P10DIR &= ~(BIT5);       // CPU_RESETn as input


    P6DIR &= ~(BIT2);        // VCCINTAUX_EN as input
    P6DIR &= ~(BIT3);        // FAN_ALERTn as input

	P1DIR &= ~(BIT0);         // TCRITn as input
	P7DIR &= ~(BIT0);         // VCCINT_FAULT as input
	P7DIR &= ~(BIT1 | BIT2);  // 12VAUX[0,1] as inputs
    P9DIR |= (BIT6 | BIT7);   // Outputs: STATUS_LED0, STATUS_LED2
    P6DIR |= BIT4;            // Outputs: STATUS_LED1

    P8DIR  &= ~(BIT1);        // GPIO 0 input
    P10DIR &= ~(BIT3);        // GPIO 1 input
    P9DIR  &= ~(BIT2 | BIT3); // GPIO 2, GPIO 3 inputs

    P9DIR  &= ~(BIT4 | BIT5); // Inputs: DIP0, DIP1
    P10DIR &= ~(BIT0 | BIT1); // Inputs: DIP2, DIP3

    P10DIR &= ~(BIT2); // POWER_GOOD input

//    P7DIR |= (BIT3 | BIT4 | BIT5 | BIT6 | BIT7); // VCCxxx Enables outputs
    P7DIR &= ~(BIT3 | BIT4 | BIT5 | BIT6 | BIT7); // VCCxxx Enables as inputs
    P8DIR &= ~(BIT0);  // DDR4 Enable as input

    P2DIR &= ~(BIT4 | BIT5 | BIT6 | BIT7);  // VCCxxx_PG inputs

    pg_status = P2IN;
    pg_status8 = P8IN;

    for( i = 0; i < 10; i++ )
    {
        P9OUT |= (BIT6 | BIT7);
        P6OUT |= BIT4;
        delay_cycles (DELAY_1250000);   //50ms delay
        delay_cycles (DELAY_1250000);   //50ms delay
        P9OUT &= ~(BIT6 | BIT7);
        P6OUT &= ~(BIT4);
        delay_cycles (DELAY_1250000);   //50ms delay
        delay_cycles (DELAY_1250000);   //50ms delay
    }

//    GPIO_TCRIT_PORT_SEL &= ~GPIO_TCRIT_PORT_PIN;      // Select GPIO
//    GPIO_TCRIT_PORT_DIR &= ~GPIO_TCRIT_PORT_PIN;      // Set input direction
//    GPIO_TCRIT_PORT_REN &= ~GPIO_TCRIT_PORT_PIN;      // Disable pull-up/down resistors
//
//  MSP432_LED0_PORT_SEL &= ~MSP432_LED0_PORT_BIT;          // Select GPIO
//  MSP432_LED0_PORT_DIR |= MSP432_LED0_PORT_BIT;           // Set as output
//  MSP432_LED0_WRITE(1);                                   // Write 1
//
//  MSP432_LED1_PORT_SEL &= ~MSP432_LED1_PORT_BIT;          // Select GPIO
//  MSP432_LED1_PORT_DIR |= MSP432_LED1_PORT_BIT;           // Set as output
//  MSP432_LED1_WRITE(1);                                   // Write 1
//
//  MSP432_LED2_PORT_SEL &= ~MSP432_LED2_PORT_BIT;          // Select GPIO
//  MSP432_LED2_PORT_DIR |= MSP432_LED2_PORT_BIT;           // Set as output
//  MSP432_LED2_WRITE(1);                                   // Write 1
//
//  for( i = 0; i < 10; i++ ) {
//  MSP432_LED0_WRITE(0);
//    delay_cycles (DELAY_1250000);   //50ms delay
//    delay_cycles (DELAY_1250000);   //50ms delay
//  MSP432_LED1_WRITE(0);
//    delay_cycles (DELAY_1250000);   //50ms delay
//    delay_cycles (DELAY_1250000);   //50ms delay
//  MSP432_LED2_WRITE(0);
//    delay_cycles (DELAY_1250000);   //50ms delay
//    delay_cycles (DELAY_1250000);   //50ms delay
//
//  MSP432_LED0_WRITE(1);
//    delay_cycles (DELAY_1250000);   //50ms delay
//    delay_cycles (DELAY_1250000);   //50ms delay
//  MSP432_LED1_WRITE(1);
//    delay_cycles (DELAY_1250000);   //50ms delay
//    delay_cycles (DELAY_1250000);   //50ms delay
//  MSP432_LED2_WRITE(1);
//    delay_cycles (DELAY_1250000);   //50ms delay
//    delay_cycles (DELAY_1250000);   //50ms delay
//  }
    jtag_oe_low();
}

void jtag_oe_low(void)
{
    int i;

    P3OUT &= ~(BIT4);
}

void jtag_oe_high(void)
{
    int i;

    P3OUT |= (BIT4);
}

void led_toggle(void)
{
    int i;

    //P9.6 = Red LED
    //P6.7 = Yellow LED
    //P9.7 = Green LED
    for( i = 0; i < 10; i++ )
    {
        P9OUT |= (BIT6 | BIT7);
        P6OUT |= BIT4;
        delay_cycles (DELAY_1250000);   //50ms delay
        delay_cycles (DELAY_1250000);   //50ms delay
        P9OUT &= ~(BIT6 | BIT7);
        P6OUT &= ~(BIT4);
        delay_cycles (DELAY_1250000);   //50ms delay
        delay_cycles (DELAY_1250000);   //50ms delay
    }
}

void gpio_pwr_enable_on(void)
{
	printf("\n\rNot yet implemented\n\r");
	return ;

    printf("gpio_on: Sequencing On - VCCINT, VCC0V85, VCC1V2, MG0V9AVCC, VCC1V8\n\r");
    P7DIR |= (BIT3 | BIT4 | BIT5 | BIT6 | BIT7); // VCCxxx Enables outputs
    P7OUT |= (BIT3);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT |= (BIT4);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT |= (BIT5);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT |= (BIT6);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT |= (BIT7);
    delay_cycles (DELAY_1250000);   //50ms delay
}

void gpio_pwr_enable_off(void)
{
	//VCCINT_EN, VCC0V85_EN, VCC1V2_EN, MGT0V9AVCC_EN, VCC1V8_EN
    printf("gpio_off: Sequencing Off - VCC1V2, VCC1V8, VCC0V85, MGT0V9AVCC, VCCINT\n\r");
    P7DIR |= (BIT3 | BIT4 | BIT5 | BIT6 | BIT7); // VCCxxx Enables outputs
    P7OUT &= ~(BIT5);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT &= ~(BIT7);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT &= ~(BIT4);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT &= ~(BIT6);
    delay_cycles (DELAY_1250000);   //50ms delay
    P7OUT &= ~(BIT3);
    delay_cycles (DELAY_1250000);   //50ms delay
}

void gpio_get_pwr_good(void)
{
	int pwrgood2;


	pwrgood2 = P2IN;

    printf("\n\r");
	printf("P2IN = %02X\n\r", pwrgood2);
	printf("---------------\n\r");
	if(pwrgood2 & BIT4){
		printf("VCC1V8 PG = 1\n\r");
	} else {
		printf("VCC1V8 PG = 0\n\r");
	}
	if(pwrgood2 & BIT5){
		printf("MGT0V9AVCC PG = 1\n\r");
	} else {
		printf("MGT0V9AVCC PG = 0\n\r");
	}
	if(pwrgood2 & BIT6){
		printf("VCCINT PG = 1\n\r");
	} else {
		printf("VCCINT PG = 0\n\r");
	}
	if(pwrgood2 & BIT7){
		printf("VCC0V85 PG = 1\n\r");
	} else {
		printf("VCC0V85 PG = 0\n\r");
	}
}

void gpio_get_pwr_enable(void)
{
	int pwrenb7;
	int ddr4enb8;

	pwrenb7 = P7IN;
	ddr4enb8 = P8IN;

	printf("\n\r");
	printf("P7IN = %02X\n\r", pwrenb7);
    printf("P8IN = %02X\n\r", ddr4enb8);
	printf("---------------\n\r");

	if(pwrenb7 & BIT3){
		printf("VCCINT ENABLE = 1\n\r");
	} else {
		printf("VCCINT ENABLE = 0\n\r");
	}
	if(pwrenb7 & BIT4){
		printf("VCC0V85 ENABLE = 1\n\r");
	} else {
		printf("VCC0V85 ENABLE = 0\n\r");
	}
	if(pwrenb7 & BIT5){
		printf("VCC1V2 ENABLE = 1\n\r");
	} else {
		printf("VCC1V2 ENABLE = 0\n\r");
	}
	if(pwrenb7 & BIT6){
		printf("MGT0V9AVCC ENABLE = 1\n\r");
	} else {
		printf("MGT0V9AVCC ENABLE = 0\n\r");
	}
	if(pwrenb7 & BIT7){
		printf("VCC1V8 ENABLE = 1\n\r");
	} else {
		printf("VCC1V8 ENABLE = 0\n\r");
	}
	if(ddr4enb8 & BIT0){
		printf("DDR4 ENABLE = 1\n\r");
	} else {
		printf("DDR4 ENABLE = 0\n\r");
	}
}

void gpio_get_12vaux(void)
{
	int pwr12aux;


	pwr12aux = P7IN;

    printf("\n\r");
	printf("P7IN = %02X\n\r", pwr12aux);
	printf("---------------\n\r");
	if(pwr12aux & BIT1){
		printf("12V_AUX0 = 1\n\r");
	} else {
		printf("12V_AUX0 = 0\n\r");
	}
	if(pwr12aux & BIT2){
		printf("12V_AUX1 = 1\n\r");
	} else {
		printf("12V_AUX1 = 0\n\r");
	}
}

void gpio_get_fan_alert(void)
{
	int fan6;


	fan6 = P6IN;

    printf("\n\r");
	printf("P6IN = %02X\n\r", fan6);
	printf("---------------\n\r");
	if(fan6 & BIT3){
		printf("FAN_ALERTn = 1\n\r");
	} else {
		printf("FAN_ALERTn = 0\n\r");
	}
}

void dipsw_in(void)
{
    char dipsw9;
    char dipsw10;

    dipsw9 = P9IN;
    dipsw10 = P10IN;

    printf("\n\r");
    if(dipsw9 & BIT4){
    	printf("DIPSW_0 = 1\n\r");
    } else {
        printf("DIPSW_0 = 0\n\r");
    }
    if(dipsw9 & BIT5){
    	printf("DIPSW_1 = 1\n\r");
    } else {
        printf("DIPSW_1 = 0\n\r");
    }
    if(dipsw10 & BIT0){
    	printf("DIPSW_2 = 1\n\r");
    } else {
    	printf("DIPSW_2 = 0\n\r");
    }
    if(dipsw10 & BIT1){
    	printf("DIPSW_3 = 1\n\r");
    } else {
    	printf("DIPSW_3 = 0\n\r");
    }
}

void gpio_in(void)
{
	char gpio8;
	char gpio9;
	char gpio10;

    P8DIR  &= ~(BIT1);        // GPIO 0
    P10DIR &= ~(BIT3);        // GPIO 1
    P9DIR  &= ~(BIT2 | BIT3); // GPIO 2, GPIO 3

    gpio8 = P8IN;
    gpio9 = P9IN;
    gpio10 = P10IN;

    printf("\n\r");
    if(gpio8 & BIT1){
    	printf("GPIO_0 = 1\n\r");
    } else {
        printf("GPIO_0 = 0\n\r");
    }
    if(gpio10 & BIT3){
    	printf("GPIO_1 = 1\n\r");
    } else {
        printf("GPIO_1 = 0\n\r");
    }
    if(gpio9 & BIT2){
    	printf("GPIO_2 = 1\n\r");
    } else {
        printf("GPIO_2 = 0\n\r");
    }
    if(gpio9 & BIT3){
    	printf("GPIO_3 = 1\n\r");
    } else {
        printf("GPIO_3 = 0\n\r");
    }
}

void gpio_out_toggle(void)
{
	char gpio8;
	char gpio9;
	char gpio10;
    char rxfpga[8];
    int i;

    P8DIR  |= (BIT1);        // GPIO 0 as output
    P10DIR |= (BIT3);        // GPIO 1 as output
    P9DIR  |= (BIT2 | BIT3); // GPIO 2, GPIO 3 as outputs

    printf("Toggling GPIO_[0-3]\n\r");  // Output to UART0
    // Set GPIO_[0-3] to FPGA = 0
    for ( i = 0; i < 10000; i++) {
		P8OUT &= ~(BIT1);
		P10OUT &= ~(BIT3);
		P9OUT &= ~(BIT2 | BIT3);
		delay_cycles(DELAY_1250000);
		P8OUT  |= (BIT1);
		P10OUT |= (BIT3);
		P9OUT  |= (BIT2 | BIT3);
		delay_cycles(DELAY_1250000);
    }

}

void gpio_out_fpga(void)
{
	char gpio8;
	char gpio9;
	char gpio10;
    char rxfpga[8];

    P8DIR  |= (BIT1);        // GPIO 0
    P10DIR |= (BIT3);        // GPIO 1
    P9DIR  |= (BIT2 | BIT3); // GPIO 2, GPIO 3

    printf("Sending GPIO = 0x0 to FPGA\n\r");  // Output to UART0
    // Set GPIO_[0-3] to FPGA = 0
    P8OUT &= ~(BIT1);
    P10OUT &= ~(BIT3);
    P9OUT &= ~(BIT2 | BIT3);

    printf("Request for MB Read GPIO 0\n\r");  // Output to UART0
    UART1_putchar('g');
    UART1_putchar('p');
    UART1_putchar('i');
    UART1_putchar('o');
    UART1_putchar(' ');
    UART1_putchar('0');
    UART1_putchar(' ');
    UART1_putchar('r');
    UART1_putchar('\n');

    delay_cycles(DELAY_1250000);

    printf("Reading MB output on UART1\n\r");
    rxfpga[0] = UART1_getchar();  // Expect '0'
    rxfpga[1] = UART1_getchar();  // Expect 'x'
    rxfpga[2] = UART1_getchar();  // Expect '0'
    rxfpga[3] = UART1_getchar();  // Expect '0'
    rxfpga[4] = UART1_getchar();  // Expect '\n'
    rxfpga[5] = UART1_getchar();  // Expect '\r'

    rxfpga[6] = '\0';
    printf("UART1 received GPIO = %s", rxfpga);
    //
    // Sending GPIO_[0-3] = All High (1)
    //
    printf("Sending GPIO = 0xF to FPGA\n\r");  // Output to UART0
    // Set GPIO_[0-3] to FPGA = 0
    P8OUT  |= (BIT1);
    P10OUT |= (BIT3);
    P9OUT  |= (BIT2 | BIT3);

    printf("Request for MB Read GPIO 0\n\r");  // Output to UART0
    UART1_putchar('g');
    UART1_putchar('p');
    UART1_putchar('i');
    UART1_putchar('o');
    UART1_putchar(' ');
    UART1_putchar('0');
    UART1_putchar(' ');
    UART1_putchar('r');
    UART1_putchar('\n');

    delay_cycles(DELAY_1250000);

    printf("Reading MB output on UART1\n\r");
    rxfpga[0] = UART1_getchar();  // Expect '0'
    rxfpga[1] = UART1_getchar();  // Expect 'x'
    rxfpga[2] = UART1_getchar();  // Expect '0'
    rxfpga[3] = UART1_getchar();  // Expect 'F'
    rxfpga[4] = UART1_getchar();  // Expect '\n'
    rxfpga[5] = UART1_getchar();  // Expect '\r'

    rxfpga[6] = '\0';
    printf("UART1 received GPIO = %s", rxfpga);

 }

void gpio_fpga_loopback(void)
{
	char gpio23;
	char rxfpga;
	char gpio2;

    P8DIR  |= (BIT1);         // GPIO_0 output
    P10DIR |= (BIT3);         // GPIO_1 output
    P9DIR  &= ~(BIT2 | BIT3); // GPIO_2, GPIO_3 inputs

    P8OUT  &= ~(BIT1);        // Set GPIO_0 = 0
    P10OUT &= ~(BIT3);        // Set GPIO_1 = 0
    gpio23 = P9IN>>2;            // GPIO[0,1] loopback to GPIO[2,3] in FPGA
    if ( (gpio23 & 0x03) == 0x00 ) {
    	printf("\n\rFPGA Loopback: Write 0x00 test PASSED\n\r");
    } else {
    	printf("\n\rFPGA Loopback: Write 0x00 test FAILED\n\r");
    }

    P8OUT  |= (BIT1);         // Set GPIO_0 = 1
    P10OUT &= ~(BIT3);        // Set GPIO_1 = 0
    gpio23 = P9IN>>2;            // GPIO[0,1] loopback to GPIO[2,3] in FPGA
    if ( (gpio23 & 0x03) == 0x01 ) {
    	printf("FPGA Loopback: Write 0x01 test PASSED\n\r");
    } else {
    	printf("FPGA Loopback: Write 0x01 test FAILED\n\r");
    }

    P8OUT  &= ~(BIT1);        // Set GPIO_0 = 0
    P10OUT |= (BIT3);         // Set GPIO_1 = 1
    gpio23 = P9IN>>2;            // GPIO[0,1] loopback to GPIO[2,3] in FPGA
    if ( (gpio23 & 0x03) == 0x02 ) {
    	printf("FPGA Loopback: Write 0x02 test PASSED\n\r");
    } else {
    	printf("FPGA Loopback: Write 0x02 test FAILED\n\r");
    }

    P8OUT  |= (BIT1);         // Set GPIO_0 = 1
    P10OUT |= (BIT3);         // Set GPIO_1 = 1
    gpio23 = P9IN>>2;            // GPIO[0,1] loopback to GPIO[2,3] in FPGA
    if ( (gpio23 & 0x03) == 0x03 ) {
    	printf("FPGA Loopback: Write 0x03 test PASSED\n\r");
    } else {
    	printf("FPGA Loopback: Write 0x03 test FAILED\n\r");
    }

    P2OUT  &= ~(BIT3);           // Set UCA1_TXD = 0
    gpio2 = P2IN>>2;            // FPGA_TXD, FPGA_RXD loopback in FPGA
    if ( (gpio2 & 0x01) == 0x00 ) {
    	printf("FPGA TXD/RXD Loopback: Write 0x00 test PASSED\n\r");
    } else {
    	printf("FPGA TXD/RXD Loopback: Write 0x00 test FAILED\n\r");
    }

    P2OUT  |= (BIT3);           // Set UCA1_TXD = 1
    gpio2 = P2IN>>2;            // FPGA_TXD, FPGA_RXD loopback in FPGA
    if ( (gpio2 & 0x01) == 0x01 ) {
    	printf("FPGA TXD/RXD Loopback: Write 0x01 test PASSED\n\r");
    } else {
    	printf("FPGA TXD/RXD Loopback: Write 0x01 test FAILED\n\r");
    }

//    UART1_putchar('A');
//    delay_cycles(DELAY_1250000);
//    rxfpga = UART1_getchar();  // Expect 'A'
//    printf("FPGA UART Loopback recveived char = %1c\n\r", rxfpga);
//    if( rxfpga == 'A' ) {
//    	printf("FPGA UART Loopback: PASSED\n\r");
//    } else {
//    	printf("FPGA UART Loopback: FAILED\n\r");
//    }

}

void gpio_out_JTAG_toggle(void)
{
	uint8_t cmd;
	P3DIR |= (BIT0 | BIT1 | BIT2 | BIT3 | BIT5);
	printf("Enter the MSP432 JTAG pin to test:\n\r");
	printf("1. MSP_TCK\n\r");
	printf("2. MSP_TDI\n\r");
	printf("3. MSP_TDO\n\r");
	printf("4. MSP_TMS\n\r");
	jtag_oe_high();
	P3OUT &= ~(BIT5);
	cmd = getchar();

	switch(cmd)
	{
		case '1': P3OUT ^= BIT0;
		case '2': P3OUT ^= BIT1;
		case '3': P3OUT ^= BIT2;
		case '4': P3OUT ^= BIT3;
	}
}

void gpio_out_PEX_I2C_toggle(void)
{
	uint8_t cmd;
	P3DIR |= (BIT6 | BIT7);
	printf("Enter the PEX I2C pin to test:\n\r");
	printf("1. PEX_SDA\n\r");
	printf("2. PEX_SCL\n\r");

	cmd = getchar();

	switch(cmd)
	{
		case '1': P3OUT ^= BIT6;
		case '2': P3OUT ^= BIT7;
	}
}
