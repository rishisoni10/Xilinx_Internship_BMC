/*
 * GPIO.h
 *
 *  Created on: Jul 5, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

void GPIO_init(void);
void jtag_oe_low(void);
void jtag_oe_high(void);
void led_toggle(void);
void gpio_pwr_enable_on(void);
void gpio_pwr_enable_off(void);
void dipsw_in(void);
void gpio_in(void);
void GPIO_toggle(void);
void gpio_out_JTAG_toggle(void);
void gpio_get_pwr_good(void);
void gpio_get_pwr_enable(void);
void gpio_out_toggle(void);
void gpio_get_12vaux(void);
void gpio_get_fan_alert(void);
void gpio_out_PEX_I2C_toggle(void);


#define INPUT_PIN                               0x00
#define OUTPUT_PIN                              0x01

//#define GPIO_ADDR_MSP430_LEDS                   0x0
//#define MSP430_LED0_PORT_SEL                    P2SEL
//#define MSP430_LED0_PORT_DIR                    P2DIR
//#define MSP430_LED0_PORT_OUT                    P2OUT
//#define MSP430_LED0_PORT_BIT                    BIT7
//#define MSP430_LED0_WRITE(x)                    if(x == 1){ \
//                                                    MSP430_LED0_PORT_OUT |= MSP430_LED0_PORT_BIT;\
//                                                }\
//                                                else{\
//                                                    MSP430_LED0_PORT_OUT &= ~MSP430_LED0_PORT_BIT;\
//                                                }
//
//#define MSP430_LED1_PORT_SEL                    P3SEL
//#define MSP430_LED1_PORT_DIR                    P3DIR
//#define MSP430_LED1_PORT_OUT                    P3OUT
//#define MSP430_LED1_PORT_BIT                    BIT2
//#define MSP430_LED1_WRITE(x)                    if(x == 1){ \
//                                                    MSP430_LED1_PORT_OUT |= MSP430_LED1_PORT_BIT;\
//                                                }\
//                                                else{\
//                                                    MSP430_LED1_PORT_OUT &= ~MSP430_LED1_PORT_BIT;\
//                                                }
//
//#define GPIO_ADDR_DIP_SWITCH                    0x10
//#define DIP_SWITCH_PORT_SEL                     P6SEL
//#define DIP_SWITCH_PORT_DIR                     P6DIR
//#define DIP_SWITCH_PORT_REN                     P6REN
//#define DIP_SWITCH_PORT_OUT                     P6OUT
//
//#define GPIO_ADDR_MSP430_PMU_GPOS               0x11
//#define MSP430_PMU_GPO_PORT_SEL                 P1SEL
//#define MSP430_PMU_GPO_PORT_DIR                 P1DIR
//#define MSP430_PMU_GPO_PORT_REN                 P1REN
//#define MSP430_PMU_GPO_PORT_OUT                 P1OUT
//#define MSP430_PMU_GPO_PORT_IN                  P1IN
//#define MSP430_PMU_GPO_PORT_BITS                (BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5)
//#define MSP430_PMU_GPO_START_NUM                0
//#define MSP430_PMU_GPO_READ()                   ((MSP430_PMU_GPO_PORT_IN & MSP430_PMU_GPO_PORT_BITS) >> MSP430_PMU_GPO_START_NUM)
//
//#define GPIO_ADDR_REG_EN                        0x12
//#define REG_EN_PORT_SEL                         P5SEL
//#define REG_EN_PORT_DIR                         P5DIR
//#define REG_EN_PORT_REN                         P5REN
//#define REG_EN_PORT_OUT                         P5OUT
//#define REG_EN_PORT_IN                          P5IN
//#define REG_EN_PORT_PIN                         BIT0
//#define REG_EN_PIN_START_NUM                    0
//#define REG_EN_READ()                           ((REG_EN_PORT_IN & REG_EN_PORT_PIN) >> REG_EN_PIN_START_NUM)
//
//#define GPIO_ADDR_MAXIM_CABLE_B                 0x13
//#define MAXIM_CABLE_B_PORT_SEL                  P5SEL
//#define MAXIM_CABLE_B_PORT_DIR                  P5DIR
//#define MAXIM_CABLE_B_PORT_REN                  P5REN
//#define MAXIM_CABLE_B_PORT_OUT                  P5OUT
//#define MAXIM_CABLE_B_PORT_IN                   P5IN
//#define MAXIM_CABLE_B_PORT_PIN                  BIT1
//#define MAXIM_CABLE_B_PIN_START_NUM             1
//#define MAXIM_CABLE_B_READ()                    ((MAXIM_CABLE_B_PORT_IN & MAXIM_CABLE_B_PORT_PIN) >> MAXIM_CABLE_B_PIN_START_NUM)
//
//#define GPIO_ADDR_MSP430_PL_GPIO_0              0x20
//#define MSP430_PL_GPIO_0_PORT_PIN               BIT0
//#define MSP430_PL_GPIO_0_PIN_START_NUM          0
//#define MSP430_PL_GPIO_0_SET_OUTPUT()           MSP430_PL_GPIO_PORT_DIR |= MSP430_PL_GPIO_0_PORT_PIN;
//#define MSP430_PL_GPIO_0_SET_INPUT()            MSP430_PL_GPIO_PORT_DIR &= ~MSP430_PL_GPIO_0_PORT_PIN;
//#define MSP430_PL_GPIO_0_READ_DIR()             ((MSP430_PL_GPIO_PORT_DIR & MSP430_PL_GPIO_0_PORT_PIN) >> MSP430_PL_GPIO_0_PIN_START_NUM)
//#define MSP430_PL_GPIO_0_WRITE(x)               if(x == 1){ \
//                                                    MSP430_PL_GPIO_PORT_OUT |= MSP430_PL_GPIO_0_PORT_PIN;\
//                                                }\
//                                                else{\
//                                                    MSP430_PL_GPIO_PORT_OUT &= ~MSP430_PL_GPIO_0_PORT_PIN;\
//                                                }
//#define MSP430_PL_GPIO_0_READ()                 ((MSP430_PL_GPIO_PORT_IN & MSP430_PL_GPIO_0_PORT_PIN) >> MSP430_PL_GPIO_0_PIN_START_NUM)
//
//#define GPIO_ADDR_MSP430_PL_GPIO_1              0x21
//#define MSP430_PL_GPIO_1_PORT_PIN               BIT3
//#define MSP430_PL_GPIO_1_PIN_START_NUM          3
//#define MSP430_PL_GPIO_1_SET_OUTPUT()           MSP430_PL_GPIO_PORT_DIR |= MSP430_PL_GPIO_1_PORT_PIN;
//#define MSP430_PL_GPIO_1_SET_INPUT()            MSP430_PL_GPIO_PORT_DIR &= ~MSP430_PL_GPIO_1_PORT_PIN;
//#define MSP430_PL_GPIO_1_READ_DIR()             ((MSP430_PL_GPIO_PORT_DIR & MSP430_PL_GPIO_1_PORT_PIN) >> MSP430_PL_GPIO_1_PIN_START_NUM)
//#define MSP430_PL_GPIO_1_WRITE(x)               if(x == 1){ \
//                                                    MSP430_PL_GPIO_PORT_OUT |= MSP430_PL_GPIO_1_PORT_PIN;\
//                                                }\
//                                                else{\
//                                                    MSP430_PL_GPIO_PORT_OUT &= ~MSP430_PL_GPIO_1_PORT_PIN;\
//                                                }
//#define MSP430_PL_GPIO_1_READ()                 ((MSP430_PL_GPIO_PORT_IN & MSP430_PL_GPIO_1_PORT_PIN) >> MSP430_PL_GPIO_1_PIN_START_NUM)
//
//#define GPIO_ADDR_MSP430_PL_GPIO_2              0x22
//#define MSP430_PL_GPIO_2_PORT_PIN               BIT6
//#define MSP430_PL_GPIO_2_PIN_START_NUM          6
//#define MSP430_PL_GPIO_2_SET_OUTPUT()           MSP430_PL_GPIO_PORT_DIR |= MSP430_PL_GPIO_2_PORT_PIN;
//#define MSP430_PL_GPIO_2_SET_INPUT()            MSP430_PL_GPIO_PORT_DIR &= ~MSP430_PL_GPIO_2_PORT_PIN;
//#define MSP430_PL_GPIO_2_READ_DIR()             ((MSP430_PL_GPIO_PORT_DIR & MSP430_PL_GPIO_2_PORT_PIN) >> MSP430_PL_GPIO_2_PIN_START_NUM)
//#define MSP430_PL_GPIO_2_WRITE(x)               if(x == 1){ \
//                                                    MSP430_PL_GPIO_PORT_OUT |= MSP430_PL_GPIO_2_PORT_PIN;\
//                                                }\
//                                                else{\
//                                                    MSP430_PL_GPIO_PORT_OUT &= ~MSP430_PL_GPIO_2_PORT_PIN;\
//                                                }
//#define MSP430_PL_GPIO_2_READ()                 ((MSP430_PL_GPIO_PORT_IN & MSP430_PL_GPIO_2_PORT_PIN) >> MSP430_PL_GPIO_2_PIN_START_NUM)
//
//#define GPIO_ADDR_MSP430_PL_GPIO_3              0x23
//#define MSP430_PL_GPIO_3_PORT_PIN               BIT7
//#define MSP430_PL_GPIO_3_PIN_START_NUM          7
//#define MSP430_PL_GPIO_3_SET_OUTPUT()           MSP430_PL_GPIO_PORT_DIR |= MSP430_PL_GPIO_3_PORT_PIN;
//#define MSP430_PL_GPIO_3_SET_INPUT()            MSP430_PL_GPIO_PORT_DIR &= ~MSP430_PL_GPIO_3_PORT_PIN;
//#define MSP430_PL_GPIO_3_READ_DIR()             ((MSP430_PL_GPIO_PORT_DIR & MSP430_PL_GPIO_3_PORT_PIN) >> MSP430_PL_GPIO_3_PIN_START_NUM)
//#define MSP430_PL_GPIO_3_WRITE(x)               if(x == 1){ \
//                                                    MSP430_PL_GPIO_PORT_OUT |= MSP430_PL_GPIO_3_PORT_PIN;\
//                                                }\
//                                                else{\
//                                                    MSP430_PL_GPIO_PORT_OUT &= ~MSP430_PL_GPIO_3_PORT_PIN;\
//                                                }
//#define MSP430_PL_GPIO_3_READ()                 ((MSP430_PL_GPIO_PORT_IN & MSP430_PL_GPIO_3_PORT_PIN) >> MSP430_PL_GPIO_3_PIN_START_NUM)
//
//#define MSP430_PL_GPIO_PORT_SEL                 P4SEL
//#define MSP430_PL_GPIO_PORT_DIR                 P4DIR
//#define MSP430_PL_GPIO_PORT_REN                 P4REN
//#define MSP430_PL_GPIO_PORT_OUT                 P4OUT
//#define MSP430_PL_GPIO_PORT_IN                  P4IN
//#define MSP430_PL_GPIO_PORT_PINS                (MSP430_PL_GPIO_0_PORT_PIN | MSP430_PL_GPIO_1_PORT_PIN | MSP430_PL_GPIO_2_PORT_PIN | MSP430_PL_GPIO_3_PORT_PIN)
//
//#define GPIO_ADDR_MSP430_PS_GPIO_0              0x24
//#define MSP430_PS_GPIO_0_PORT_PIN               BIT6
//#define MSP430_PS_GPIO_0_PIN_START_NUM          6
//#define MSP430_PS_GPIO_0_SET_OUTPUT()           MSP430_PS_GPIO_PORT_DIR |= MSP430_PS_GPIO_0_PORT_PIN;
//#define MSP430_PS_GPIO_0_SET_INPUT()            MSP430_PS_GPIO_PORT_DIR &= ~MSP430_PS_GPIO_0_PORT_PIN;
//#define MSP430_PS_GPIO_0_READ_DIR()             ((MSP430_PS_GPIO_PORT_DIR & MSP430_PS_GPIO_0_PORT_PIN) >> MSP430_PS_GPIO_0_PIN_START_NUM)
//#define MSP430_PS_GPIO_0_WRITE(x)               if(x == 1){ \
//                                                    MSP430_PS_GPIO_PORT_OUT |= MSP430_PS_GPIO_0_PORT_PIN;\
//                                                }\
//                                                else{\
//                                                    MSP430_PS_GPIO_PORT_OUT &= ~MSP430_PS_GPIO_0_PORT_PIN;\
//                                                }
//#define MSP430_PS_GPIO_0_READ()                 ((MSP430_PS_GPIO_PORT_IN & MSP430_PS_GPIO_0_PORT_PIN) >> MSP430_PS_GPIO_0_PIN_START_NUM)
//
//#define GPIO_ADDR_MSP430_PS_GPIO_1              0x25
//#define MSP430_PS_GPIO_1_PORT_PIN               BIT7
//#define MSP430_PS_GPIO_1_PIN_START_NUM          7
//#define MSP430_PS_GPIO_1_SET_OUTPUT()           MSP430_PS_GPIO_PORT_DIR |= MSP430_PS_GPIO_1_PORT_PIN;
//#define MSP430_PS_GPIO_1_SET_INPUT()            MSP430_PS_GPIO_PORT_DIR &= ~MSP430_PS_GPIO_1_PORT_PIN;
//#define MSP430_PS_GPIO_1_READ_DIR()             ((MSP430_PS_GPIO_PORT_DIR & MSP430_PS_GPIO_1_PORT_PIN) >> MSP430_PS_GPIO_1_PIN_START_NUM)
//#define MSP430_PS_GPIO_1_WRITE(x)               if(x == 1){ \
//                                                    MSP430_PS_GPIO_PORT_OUT |= MSP430_PS_GPIO_1_PORT_PIN;\
//                                                }\
//                                                else{\
//                                                    MSP430_PS_GPIO_PORT_OUT &= ~MSP430_PS_GPIO_1_PORT_PIN;\
//                                                }
//#define MSP430_PS_GPIO_1_READ()                 ((MSP430_PS_GPIO_PORT_IN & MSP430_PS_GPIO_1_PORT_PIN) >> MSP430_PS_GPIO_1_PIN_START_NUM)
//
//#define MSP430_PS_GPIO_PORT_SEL                 P1SEL
//#define MSP430_PS_GPIO_PORT_DIR                 P1DIR
//#define MSP430_PS_GPIO_PORT_REN                 P1REN
//#define MSP430_PS_GPIO_PORT_OUT                 P1OUT
//#define MSP430_PS_GPIO_PORT_IN                  P1IN
//#define MSP430_PS_GPIO_0_PORT_PIN               BIT6
//#define MSP430_PS_GPIO_1_PORT_PIN               BIT7
//#define MSP430_PS_GPIO_PORT_PINS                (MSP430_PS_GPIO_0_PORT_PIN | MSP430_PS_GPIO_1_PORT_PIN)

#endif /* INCLUDE_GPIO_H_ */
