/*
 * adc.c
 *
 *  Created on: Jul 6, 2017
 *      Author: Rishi Soni
 */

#include "main.h"

#define channels    (24)

//#define HFXTBYPASS

//channel: selected ADC channel to be measured
//test: 1 for HFXT test using SMCLK, 0 for normal ADC mode using MCLK
float adc_single_channel(uint8_t channel, uint8_t test)
{
    uint32_t Volt_read;
    uint8_t i, j = 100;
    float Volt_actual;

    //Enable VeREF+ & VeREF-
    P5SELC |= BIT6 | BIT7;

    if (test == 1)
    {
		//*****Start of HFXT config*****
	    PJ->SEL0 |= BIT2 | BIT3;                // set HFXT pin as second function
	    PJ->SEL1 &= ~(BIT2 | BIT3);
	    CS->KEY = CS_KEY_VAL ;                  // Unlock CS module for register access

	    CS->CTL2 |= CS_CTL2_HFXT_EN | CS_CTL2_HFXTFREQ_2 | CS_CTL2_HFXTDRIVE;            // HFXT on with 8MHz to 16MHz

	    delay_cycles(DELAY_1250000);      //50ms delay to settle the HFXT crystal

	    // Loop until XT1, XT2 & DCO fault flag is cleared
	    while ((SYSCTL->NMI_CTLSTAT | SYSCTL_NMI_CTLSTAT_CS_FLG) && (CS->IFG & CS_IFG_HFXTIFG) && j > 0) // Test oscillator fault flag
	   {
	       // Clear XT2,XT1,DCO fault flags
	      CS->CLRIFG |= CS_CLRIFG_CLR_DCOR_OPNIFG | CS_CLRIFG_CLR_HFXTIFG |
	              CS_CLRIFG_CLR_LFXTIFG | CS_CLRIFG_CLR_FCNTLFIFG;
	      SYSCTL->NMI_CTLSTAT &= ~ SYSCTL_NMI_CTLSTAT_CS_SRC;
	      j--;
	   }
	    //Select ACLK as LFXTCLK and MCLK as HFXTCLK
		CS->CTL1 &= ~(CS_CTL1_SELA_MASK) | CS_CTL1_SELS__HFXTCLK;
		CS->KEY = 0;                            // Lock CS module from unintended accesses


		ADC14->CTL0 = ADC14_CTL0_SSEL__SMCLK | ADC14_CTL0_SHT0__192 | ADC14_CTL0_SHT1__192
							  | ADC14_CTL0_SHP  | ADC14_CTL0_CONSEQ_0 | ADC14_CTL0_ON;


    }
    if(test == 0)
	{

		ADC14->CTL0 = ADC14_CTL0_SSEL__MCLK | ADC14_CTL0_SHT0__192 | ADC14_CTL0_SHT1__192
							   | ADC14_CTL0_SHP  | ADC14_CTL0_CONSEQ_0 | ADC14_CTL0_ON;
	}
#ifdef HFXTBYPASS
    	CS->KEY = CS_KEY_VAL ;                  // Unlock CS module for register access
	    CS->CTL2 |= CS_CTL2_HFXTBYPASS;
	    delay_cycles(DELAY_1250000);      //50ms delay
	    CS->KEY = 0;                  // Lock CS module for register access
#else
	    CS->KEY = CS_KEY_VAL ;                  // Unlock CS module for register access
	    CS->CTL2 &= ~CS_CTL2_HFXTBYPASS;
	    CS->CLRIFG |= CS_CLRIFG_CLR_HFXTIFG;
	    CS->KEY = 0;                  // Lock CS module for register access
#endif
    //Select channel
    switch(channel)
    {
        case '0': P5SELC |= BIT5; break;
        case '1': P5SELC |= BIT4; break;
        case '2': P5SELC |= BIT3; break;
        case '3': P5SELC |= BIT2; break;
        case '4': P5SELC |= BIT1; break;
        case '5': P5SELC |= BIT0; break;
        case '6': P4SELC |= BIT7; break;
        case '7': P4SELC |= BIT6; break;
        case '8': P4SELC |= BIT5; break;
        case '9': P4SELC |= BIT4; break;
        case 'A': P4SELC |= BIT3; break;
        case 'B': P4SELC |= BIT2; break;
        case 'C': P4SELC |= BIT1; break;
        case 'D': P4SELC |= BIT0; break;
        case 'E': P6SELC |= BIT1; break;
        case 'F': P6SELC |= BIT0; break;
        case 'G': P9SELC |= BIT1; break;
        case 'H': P9SELC |= BIT0; break;
        case 'I': P8SELC |= BIT7; break;
        case 'J': P8SELC |= BIT6; break;
        case 'K': P8SELC |= BIT5; break;
        case 'L': P8SELC |= BIT4; break;
        case 'M': P8SELC |= BIT3; break;
        case 'N': P8SELC |= BIT2; break;
    }

    //Resolving ASCII chars into unsigned 8-bit integers
    if (channel <= '9')
        i = channel - 48;
    else
        i = channel - 55;
    //Enable global interrupt
//    __enable_irq();

    //Enable ADC interrupt in the NVIC module
//    NVIC_EnableIRQ(ADC14_IRQn);

	ADC14->CTL1 = ADC14_CTL1_RES__14BIT | (ADC14_CTL1_CSTARTADD_MASK & i << 16) ;    //14-bit resolution, 'channel' start

    switch(channel)
    {
        case '0': ADC14->MCTL[0] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_0; break;
        case '1': ADC14->MCTL[1] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_1; break;
        case '2': ADC14->MCTL[2] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_2; break;
        case '3': ADC14->MCTL[3] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_3; break;
        case '4': ADC14->MCTL[4] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_4; break;
        case '5': ADC14->MCTL[5] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_5; break;
        case '6': ADC14->MCTL[6] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_6; break;
        case '7': ADC14->MCTL[7] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_7; break;
        case '8': ADC14->MCTL[8] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_8; break;
        case '9': ADC14->MCTL[9] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_9; break;
        case 'A': ADC14->MCTL[10] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_10; break;
        case 'B': ADC14->MCTL[11] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_11; break;
        case 'C': ADC14->MCTL[12] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_12; break;
        case 'D': ADC14->MCTL[13] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_13; break;
        case 'E': ADC14->MCTL[14] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_14; break;
        case 'F': ADC14->MCTL[15] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_15; break;
        case 'G': ADC14->MCTL[16] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_16; break;
        case 'H': ADC14->MCTL[17] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_17; break;
        case 'I': ADC14->MCTL[18] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_18; break;
        case 'J': ADC14->MCTL[19] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_19; break;
        case 'K': ADC14->MCTL[20] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_20; break;
        case 'L': ADC14->MCTL[21] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_21; break;
        case 'M': ADC14->MCTL[22] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_22; break;
        case 'N': ADC14->MCTL[23] = ADC14_MCTLN_VRSEL_14 | ADC14_MCTLN_INCH_23; break;
    }
//    switch(channel)
//    {
//        case '0': ADC14->IER0 = ADC14_IER0_IE0; break;
//        case '1': ADC14->IER0 = ADC14_IER0_IE1; break;
//        case '2': ADC14->IER0 = ADC14_IER0_IE2; break;
//        case '3': ADC14->IER0 = ADC14_IER0_IE3; break;
//        case '4': ADC14->IER0 = ADC14_IER0_IE4; break;
//        case '5': ADC14->IER0 = ADC14_IER0_IE5; break;
//        case '6': ADC14->IER0 = ADC14_IER0_IE6; break;
//        case '7': ADC14->IER0 = ADC14_IER0_IE7; break;
//        case '8': ADC14->IER0 = ADC14_IER0_IE8; break;
//        case '9': ADC14->IER0 = ADC14_IER0_IE9; break;
//        case 'A': ADC14->IER0 = ADC14_IER0_IE10; break;
//        case 'B': ADC14->IER0 = ADC14_IER0_IE11; break;
//        case 'C': ADC14->IER0 = ADC14_IER0_IE12; break;
//        case 'D': ADC14->IER0 = ADC14_IER0_IE13; break;
//        case 'E': ADC14->IER0 = ADC14_IER0_IE14; break;
//        case 'F': ADC14->IER0 = ADC14_IER0_IE15; break;
//        case 'G': ADC14->IER0 = ADC14_IER0_IE16; break;
//        case 'H': ADC14->IER0 = ADC14_IER0_IE17; break;
//        case 'I': ADC14->IER0 = ADC14_IER0_IE18; break;
//        case 'J': ADC14->IER0 = ADC14_IER0_IE19; break;
//        case 'K': ADC14->IER0 = ADC14_IER0_IE20; break;
//        case 'L': ADC14->IER0 = ADC14_IER0_IE21; break;
//        case 'M': ADC14->IER0 = ADC14_IER0_IE22; break;
//        case 'N': ADC14->IER0 = ADC14_IER0_IE23; break;
//    }

//    delay_cycles(DELAY_1250000);
    ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC;
//    delay_cycles (DELAY_1250000);   //50ms delay

    switch(channel)
   {
       case '0': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG0)); break;
       case '1': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG1)); break;
       case '2': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG2)); break;
       case '3': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG3)); break;
       case '4': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG4)); break;
       case '5': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG5)); break;
       case '6': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG6)); break;
       case '7': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG7)); break;
       case '8': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG8)); break;
       case '9': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG9)); break;
       case 'A': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG10)); break;
       case 'B': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG11)); break;
       case 'C': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG12)); break;
       case 'D': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG13)); break;
       case 'E': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG14)); break;
       case 'F': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG15)); break;
       case 'G': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG16)); break;
       case 'H': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG17)); break;
       case 'I': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG18)); break;
       case 'J': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG19)); break;
       case 'K': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG20)); break;
       case 'L': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG21)); break;
       case 'M': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG22)); break;
       case 'N': while(!(ADC14->IFGR0 & ADC14_IFGR0_IFG23)); break;
   }

    Volt_read = ADC14->MEM[i];
    Volt_actual = (Volt_read * 2.5) / 16384;

//    delay_cycles (DELAY_1250000);   //50ms delay

    ADC14->CTL0 &= ~(ADC14_CTL0_ENC | ADC14_CTL0_SC);

    //clear ADC14MEMx flag
    switch(channel)
   {
       case '0': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG0; break;
       case '1': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG1; break;
       case '2': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG2; break;
       case '3': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG3; break;
       case '4': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG4; break;
       case '5': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG5; break;
       case '6': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG6; break;
       case '7': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG7; break;
       case '8': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG8; break;
       case '9': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG9; break;
       case 'A': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG10; break;
       case 'B': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG11; break;
       case 'C': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG12; break;
       case 'D': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG13; break;
       case 'E': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG14; break;
       case 'F': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG15; break;
       case 'G': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG16; break;
       case 'H': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG17; break;
       case 'I': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG18; break;
       case 'J': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG19; break;
       case 'K': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG20; break;
       case 'L': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG21; break;
       case 'M': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG22; break;
       case 'N': ADC14->CLRIFGR0 |= ADC14_CLRIFGR0_CLRIFG23; break;
   }
//    delay_cycles (DELAY_2500);   //1ms delay
#ifndef HFXTBYPASS
	return Volt_actual;
#else
	return 1;
#endif
}

//test: 1 for HFXT test using SMCLK, 0 for normal ADC mode using MCLK
uint32_t adc_all_channels(uint8_t test)
{
    uint8_t i;
    float result; //PEX_12V, VIN_VCC1V8_MGTAVCC, result_VIN_VCC1V8_MGTAVCC[100], result_PEX[100], avg1 = 0.0, avg2 = 0.0, sum_VIN_VCC1V8_MGTAVCC = 0.0, sum_12V_PEX = 0.0
    printf("\n\r");
    uint32_t status_word = 0; //N, M = 0;

//    for(i = '0'; i <= '9'; i++)
//    {
//        sum = 0.0, avg = 0.0;
//        for(j = 0; j < 100; j++)
//        {
//            result = adc_single_channel(i);
//            sum += result;
//        }
//        avg = sum / 100;
//        printf("Channel %d: %.3f Volts\n\r", (i - 48), avg);
//    }


//    for(i = 'A'; i <= 'N'; i++ )
//    {
//        sum = 0.0; avg = 0.0;
//        for(j = 0; j < 100; j++)
//        {
//            result = adc_single_channel(i);
//            sum += result;
//        }
//        avg = sum / 100;
//        printf("Channel %d: %.3f Volts\n\r", (i - 55), avg);
//    }

//    /*
    for(i = '0'; i <= '9'; i++)
    {
    	result = adc_single_channel(i, test);
        if((CS->IFG & CS_IFG_HFXTIFG) && test == 1)
        {
            printf("HFXT clock FAILED\n\r");
            break;
        }
       else
       {
    	   switch(i - 48)
    	   {
    	   	   case 0: if(result >= 0.97 * 1.29527 && result <= 1.03 * 1.29527) {printf("12V_PEX: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.10793934);} else printf("12V_PEX: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 1: if(result >= 0.97 * 1.079189 && result <= 1.03 * 1.079189) {printf("3V3_PEX: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);} else printf("3V3_PEX: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 2: if(result >= 0.97 * 1.079189 && result <= 1.03 * 1.079189) {printf("3V3_AUX: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);} else printf("3V3_AUX: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 3: if(result >= 0.97 * 1.29527 && result <= 1.03 * 1.29527) {printf("12V_AUX: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.10793934);} else printf("12V_AUX: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 4: if(result >= 0.97 * 0.81756 && result <= 1.03 * 0.81756) {printf("DDR4_VPP_BTM: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);} else printf("DDR4_VPP_BTM: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 5: if(result >= 0.97 * 1.7986 && result <= 1.03 * 1.7986) {printf("SYS_5V5: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);} else printf("SYS_5V5: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 6: if(result >= 0.97 * 0.39243 && result <= 1.03 * 0.39243) {printf("VCC1V2_TOP: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);} else printf("VCC1V2_TOP: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 7: if(result >= 0.97 * 0.588648 && result <= 1.03 * 0.588648) {printf("VCC1V8: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);}else printf("VCC1V8: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 8: if(result >= 0.97 * 0.2779729 && result <= 1.03 * 0.2779729) {printf("VCC0V85: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);} else printf("VCC0V85: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   	   case 9: if(result >= 0.97 * 0 && result <= 1.03 * 0) {printf("ADC_USR1: Channel - %d value within +/- 3%% error range\n\r", i - 48); printf("Channel %d: %.3f Volts\n\r", (i - 48), result/0.327027027);} else printf("ADC_USR1: Channel - %d inaccurate: %.3f Volts\n\r", i - 48, result);break;
    	   }
//    	   if (i - 48 == 0)
//    		   PEX_12V = result;

//           printf("\n\rHFXT clock SUCCESS\n\r");
           status_word = status_word | (0x0001 << (i - 48));
           printf("\n\r");
       }
    }

    for(i = 'A'; i <= 'N'; i++ )
    {
        result = adc_single_channel(i, test);
        if((CS->IFG & CS_IFG_HFXTIFG) && test == 1)
        {
            printf("HFXT clock FAILED\n\r");
            break;
        }
       else
       {
    	   switch(i - 55)
    	   {
    	   	   case 10: if(result >= 0.97 * 0.294324 && result <= 1.03 * 0.294324) {printf("MGT0V9AVCC: Channel - %d value within +/- 3%% error range\n\r", i - 55);printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.327027027);}
else printf("MGT0V9AVCC: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 11: if(result >= 0.97 * 0.2779729 && result <= 1.03 * 0.2779729) {printf("VCCINT: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.327027027);}
else printf("VCCINT: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 12: if(result >= 0.97 * 0.39243 && result <= 1.03 * 0.39243) {printf("MGTAVTT: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.327027027);}
else printf("MGTAVTT: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 13: if(result >= 0.97 * 0 && result <= 1.03 * 0) {printf("ADC_USR: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
else printf("ADC_USR: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   //Unsure calculations case 14: if(result >= 0.97 * 0.294324 && result <= 1.03 * 0.294324) {printf("12V_AUX_VIN: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
//else printf("12V_AUX_VIN: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 15: if(result >= 0.97 * 0.269848 && result <= 1.03 * 0.269848) {printf("DDR4_VPP_TOP: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
else printf("DDR4_VPP_TOP: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 16: if(result >= 0.97 * 0.39243 && result <= 1.03 * 0.39243) {printf("VCC1V2_BTM: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.327027027);}
else printf("VCC1V2_BTM: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 17: if(result >= 0.97 * 1.29527 && result <= 1.03 * 1.29527) {printf("VIN_VCC1V8_MGTAVCC: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
else printf("VIN_VCC1V8_MGTAVCC: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 18: if(result >= 0.97 * 1.29527 && result <= 1.03 * 1.29527) {printf("VIN_VCC0V85: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
else printf("VIN_VCC0V85: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 19: if(result >= 0.97 * 1.29527 && result <= 1.03 * 1.29527) {printf("12V_SW: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
else printf("12V_SW: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   //Error in REV A case 20: if(result >= 0.97 *  && result <= 1.03 *  ) {printf("3V3_PEX_IN: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
//else printf("3V3_PEX_IN: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   //Error in REV A case 21: if(result >= 0.97 *  && result <= 1.03 *  ) {printf("12V_IN: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
//else printf("12V_IN: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 22: if(result >= 0.97 * 1.29527 && result <= 1.03 * 1.29527) {printf("VIN_VCC1V2: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
else printf("VIN_VCC1V2: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   	   case 23: if(result >= 0.97 * 1.29527 && result <= 1.03 * 1.29527) {printf("VIN_MGTAVTT: Channel - %d value within +/- 3%% error range\n\r", i - 55); printf("Channel %d: %.3f Volts\n\r", (i - 55), result/0.10793934);}
else printf("VIN_MGTAVTT: Channel - %d inaccurate: %.3f Volts\n\r", i - 55, result);break;
    	   }
//    	   if (i - 55 == 17)
//    		   VIN_VCC1V8_MGTAVCC = result;
//           printf("\n\rHFXT clock SUCCESS\n\r");
           status_word = status_word | (0x0001 << (i - 55));
//           printf("Channel %d: %.3f Volts\n\r", (i - 55), result);
           printf("\n\r");
       }
    }
//    */

//    printf("12V_PEX\t\tVIN_VCC1V8_MGTAVCC\n\r");
//    while (M < 100)
//    {
//    	N = 0; avg1 = 0.0; avg2 = 0.0; sum_VIN_VCC1V8_MGTAVCC = 0.0; sum_12V_PEX = 0.0;
//		while (N < 100)
//		{
//			result_PEX[N] = ((adc_single_channel('0', 0)) / 0.10793934);
//			sum_12V_PEX += result_PEX[N];
//			result_VIN_VCC1V8_MGTAVCC[N] = ((adc_single_channel('H', 0)) / 0.10793934);
//			sum_VIN_VCC1V8_MGTAVCC += result_VIN_VCC1V8_MGTAVCC[N];
////			result[N] = (result_PEX[N] - result_VIN_VCC1V8_MGTAVCC[N]);
//			N++;
//		}
//		avg1 = sum_12V_PEX / 100.0;
//		avg2 = sum_VIN_VCC1V8_MGTAVCC / 100.0;
//		printf("%.7f\t\t%.7f\n\r", avg1, avg2);
//		M++;
//    }

//    PEX_12V = (PEX_12V / 0.10793934);
//    VIN_VCC1V8_MGTAVCC = (VIN_VCC1V8_MGTAVCC / 0.10793934);
//    printf("Measured of PEX_12V is %.7f\n\r", PEX_12V);
//    printf("Measured of VIN_VCC1V8_MGTAVCC is %.7f\n\r", VIN_VCC1V8_MGTAVCC);
//    float pot_diff = PEX_12V - VIN_VCC1V8_MGTAVCC;
//    printf("Current measurement is %.7f", (pot_diff / 0.001));
//    printf("\n\r");

    printf("Channel read successful");
    if ((status_word & 0xFFFFFF) && test == 1)
        printf("\n\rAll ADC channels read with active HFXT clock: SUCCESS\n\r");
    else if (((status_word != 0xFFFFFF) && test == 1))
        printf("\n\rAll ADC channels read with active HFXT clock FAILED\n\r");
    return status_word;
}
