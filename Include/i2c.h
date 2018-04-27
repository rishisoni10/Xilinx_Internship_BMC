/*
 * i2c.h
 *
 *  Created on: Jun 21, 2017
 *      Author: Rishi Soni
 */

#ifndef INCLUDE_I2C_H_
#define INCLUDE_I2C_H_


#define   I2C0_PORT_SEL              P1SEL0                          //Port 1, Primary Module Function
#define   I2C0_SDA_BIT               BIT6                            //Pin 6
#define   I2C0_SCL_BIT               BIT7                            //Pin 7

#define   I2C0_CTL0                  (EUSCI_B0->CTLW0)               //eUSCI_B0 Control Register 0
#define   I2C0_CTL1                  (EUSCI_B0->CTLW1)               //eUSCI_B0 Control Register 1
#define   I2C0_BRW                   UCB0BRW                         //eUSCI_B0 Bit Rate Control Word Register
#define   I2C0_SAR                   UCB0I2CSA                       //I2C0 Slave Address Register
#define   I2C0_IFG                   (EUSCI_B0->IFG)                 //eUSCI_B0 I2C interrupt flag register
#define   I2C0_RX_BUF                UCB0RXBUF                       //eUSCI_B0 Receive Buffer Register
#define   I2C0_TX_BUF                UCB0TXBUF                       //eUSCI_B0 Transmit Buffer Register


#define   I2C2_PORT_SEL              P3SEL0                          //Port 6, Primary Module Function
#define   I2C2_SDA_BIT               BIT6                            //Pin 6
#define   I2C2_SCL_BIT               BIT7                            //Pin 7

#define   I2C2_CTL0                  UCB2CTL1                        //eUSCI_B0 Control Register 0
#define   I2C2_CTL1                  UCB2CTL0                        //eUSCI_B0 Control Register 1
#define   I2C2_BRW                   UCB2BRW                         //eUSCI_B0 Bit Rate Control Word Register
#define   I2C2_SAR                   UCB2I2CSA                       //I2C0 Slave Address Register
#define   I2C2_IFG                   UCB2IFG                         //eUSCI_B1 I2C interrupt flag register
#define   I2C2_RX_BUF                UCB2RXBUF                       //eUSCI_B1 Receive Buffer Register
#define   I2C2_TX_BUF                UCB2TXBUF                       //eUSCI_B1 Transmit Buffer Register

#define   I2C3_PORT_SEL              P6SEL1                          //Port 6, Primary Module Function
#define   I2C3_SDA_BIT               BIT6                            //Pin 6
#define   I2C3_SCL_BIT               BIT7                            //Pin 7

#define   I2C3_CTL0                  UCB3CTL1                        //eUSCI_B3 Control Register 0
#define   I2C3_CTL1                  UCB3CTL0                        //eUSCI_B3 Control Register 1
#define   I2C3_BRW                   UCB3BRW                         //eUSCI_B3 Bit Rate Control Word Register
#define   I2C3_SAR                   UCB3I2CSA                       //I2C3 Slave Address Register
#define   I2C3_IFG                   UCB3IFG                         //eUSCI_B3 I2C interrupt flag register
#define   I2C3_RX_BUF                UCB3RXBUF                       //eUSCI_B3 Receive Buffer Register
#define   I2C3_TX_BUF                UCB3TXBUF                       //eUSCI_B3 Transmit Buffer Register


#define   UCBMODE_0                  EUSCI_B_CTLW0_MODE_0            //3-pin SPI
#define   UCBMODE_1                  EUSCI_B_CTLW0_MODE_1            //4-pin SPI with UCxSTE active high: Slave enabled when UCxSTE = 1
#define   UCBMODE_2                  EUSCI_B_CTLW0_MODE_2            //4-pin SPI with UCxSTE active low: Slave enabled when UCxSTE = 0
#define   UCBMODE_3                  EUSCI_B_CTLW0_MODE_3            //I2C mode
#define   UCBMST                     EUSCI_B_CTLW0_MST               //Master mode select
#define   UCBSSEL_SMCLK              EUSCI_B_CTLW0_SSEL__SMCLK       /*!< SMCLK */
#define   UCBSYNC                    EUSCI_B_CTLW0_SYNC              //Sync mode


uint8_t i2c0_init(void);
uint8_t i2c2_init(void);
uint8_t i2c3_init(void);

uint8_t i2c0_recv(uint8_t i2c_addr, uint8_t *rbuf, uint8_t byte_count);
uint8_t i2c2_recv(uint8_t i2c_addr, uint8_t *rbuf, uint64_t byte_count);

uint8_t i2c0_send(uint8_t i2c_addr, uint8_t *wbuf, uint64_t byte_count);
uint8_t i2c2_send(uint8_t i2c_addr, uint8_t *wbuf, uint64_t byte_count);
uint8_t i2c3_send(uint8_t i2c_addr, uint8_t *wbuf, uint64_t byte_count);

uint8_t i2c0_send_rs_recv(uint8_t i2c_addr, uint8_t *wbuf, uint64_t send_count, uint8_t *rbuf, uint64_t recv_count);
uint8_t i2c3_send_rs_recv(uint8_t i2c_addr, uint8_t *wbuf, uint64_t send_count, uint8_t *rbuf, uint64_t recv_count);

uint8_t ping_i2c0(uint8_t i2c_addr);
uint8_t ping_i2c2(uint8_t i2c_addr);
uint8_t ping_i2c3(uint8_t i2c_addr);
#endif /* INCLUDE_I2C_H_ */
