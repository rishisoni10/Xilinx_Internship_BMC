/*
 * i2c.c
 *
 *  Forked from: SC_I2C_com.c
 *  Created on: Jun 21, 2017
 *      Author: Rishi Soni
 */

#include "main.h"

#define I2C0_SA                       (0x40)          //I2C0 Slave address
#define i2c2_SA                       (0x20)          //i2c2 Slave address

static uint8_t repeated_start_i2c0;
static uint8_t repeated_start_i2c2;
static uint8_t repeated_start_i2c3;
static uint8_t nak_i2c0;
static uint8_t nak_i2c2;
static uint8_t nak_i2c3;
//////////////////////////////////
// I2C0 INIT
/////////////////////////////////
uint8_t i2c0_init(void)
{
//  //Enable global interrupt
//        __enable_irq();
//
//        //Enable eUSCIB0 interrupt in NVIC
//        NVIC->ISER[0] = 1 << ((EUSCIB0_IRQn) & 31);

    // Configure USCI_B0 for I2C mode
    EUSCI_B0->CTLW0 |= EUSCI_B_CTLW0_SWRST;           // Software reset enabled
    EUSCI_B0->CTLW0 = EUSCI_B_CTLW0_SWRST |           // Remain eUSCI in reset mode
                      EUSCI_B_CTLW0_MODE_3 |          // I2C mode
                      EUSCI_B_CTLW0_MST |             // Master mode
                      EUSCI_B_CTLW0_SYNC |            // Sync mode
                      EUSCI_B_CTLW0_SSEL__SMCLK;      // SMCLK
    //EUSCI_B0->CTLW1 |= EUSCI_B_CTLW1_ASTP_2;        //Automatic stop condition after byte count is reached
    EUSCI_B0->BRW = 1 << 9;                           //fSCL = SMCLK(=DCOCLK) / 512 = ~50kHz
//    EUSCI_B0->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;          // Release eUSCI from reset
    delay_cycles(DELAY_1250000);

    //EUSCI_B0->IE |= EUSCI_A_IE_RXIE |               // Enable receive interrupt
    //                EUSCI_B_IE_NACKIE |             // Enable NACK interrupt
    //                EUSCI_B_IE_BCNTIE;              // Enable byte counter interrupt
    //Commented out for Polled
    //UCB0IE |= UCTXIE;                     // Enable I2C TX interrupt

    return FUNC_SUCCESS;
}

//////////////////////////////////
// I2C2 INIT
/////////////////////////////////
uint8_t i2c2_init(void)
{

    EUSCI_B2->CTLW0 |= EUSCI_B_CTLW0_SWRST;           // Software reset enabled
    EUSCI_B2->CTLW0 = EUSCI_B_CTLW0_SWRST |           // Remain eUSCI in reset mode
                      EUSCI_B_CTLW0_MODE_3 |          // I2C mode
                      EUSCI_B_CTLW0_MST |             // Master mode
                      EUSCI_B_CTLW0_SYNC |            // Sync mode
                      EUSCI_B_CTLW0_SSEL__SMCLK;      // SMCLK
    //EUSCI_B2->CTLW1 |= EUSCI_B_CTLW1_ASTP_2;        //Automatic stop condition after byte count is reached
    EUSCI_B2->BRW = 1 << 9;                           //fSCL = SMCLK(=DCOCLK) / 512 = ~50kHz
    EUSCI_B2->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;          // Release eUSCI from reset
    delay_cycles(DELAY_1250000);

    //EUSCI_B2->IE |= EUSCI_A_IE_RXIE |               // Enable receive interrupt
    //                EUSCI_B_IE_NACKIE |             // Enable NACK interrupt
    //                EUSCI_B_IE_BCNTIE;              // Enable byte counter interrupt
    //Commented out for Polled
    //UCB0IE |= UCTXIE;                     // Enable I2C TX interrupt
    return FUNC_SUCCESS;
}
//////////////////////////////////
// I2C3 INIT
/////////////////////////////////
uint8_t i2c3_init(void)
{
//  //Enable global interrupt
//        __enable_irq();
//
//        //Enable eUSCIB0 interrupt in NVIC
//        NVIC->ISER[0] = 1 << ((EUSCIB0_IRQn) & 31);

    // Configure USCI_B0 for I2C mode
    EUSCI_B3->CTLW0 |= EUSCI_B_CTLW0_SWRST;           // Software reset enabled
    EUSCI_B3->CTLW0 = EUSCI_B_CTLW0_SWRST |           // Remain eUSCI in reset mode
                      EUSCI_B_CTLW0_MODE_3 |          // I2C mode
                      EUSCI_B_CTLW0_MST |             // Master mode
                      EUSCI_B_CTLW0_SYNC |            // Sync mode
                      EUSCI_B_CTLW0_SSEL__SMCLK;      // SMCLK
    //EUSCI_B0->CTLW1 |= EUSCI_B_CTLW1_ASTP_2;        //Automatic stop condition after byte count is reached
    EUSCI_B3->BRW = 1 << 9;                           //fSCL = SMCLK(=DCOCLK) / 512 = ~50kHz
//    EUSCI_B0->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;          // Release eUSCI from reset
    delay_cycles(DELAY_1250000);

    //EUSCI_B0->IE |= EUSCI_A_IE_RXIE |               // Enable receive interrupt
    //                EUSCI_B_IE_NACKIE |             // Enable NACK interrupt
    //                EUSCI_B_IE_BCNTIE;              // Enable byte counter interrupt
    //Commented out for Polled
    //UCB0IE |= UCTXIE;                     // Enable I2C TX interrupt

    return FUNC_SUCCESS;
}

//////////////////////////////////
// I2C0 SEND POLLED NEW
/////////////////////////////////
uint8_t i2c0_send(uint8_t i2c_addr, uint8_t *wbuf, uint64_t byte_count)
{
    uint64_t bytes_left;

    while(EUSCI_B0->STATW & UCBBUSY);            // Wait until Bus is Available

    EUSCI_B0->CTLW0 |= UCSWRST;                  // Enable SW reset UCB0
    EUSCI_B0->I2CSA = i2c_addr;                  // Slave Address
    nak_i2c0 = 0;                                // Set NAK received flag to FALSE
    EUSCI_B0->CTLW0 |= UCTR;                     // Master Transmitter
    EUSCI_B0->CTLW0 &= ~UCSWRST;                 // Clear SW reset USCI_B0, resume operation
    repeated_start_i2c0 = 0;

    while(EUSCI_B0->CTLW0 & UCTXSTP);            // Ensure bus 0 stop condition got sent from the previous transmission

    EUSCI_B0->CTLW0 |= UCTXSTT;                  // Send START
    while((EUSCI_B0->IFG & UCTXIFG) == 0 );      // Wait for TXIFG=1:set when start condition is generated
    EUSCI_B0->TXBUF  = *wbuf;                    // slau356f p. 790 says this will be discarded

    bytes_left = byte_count;
    do
    {
        while(EUSCI_B0->CTLW0 & UCTXSTT);        // Wait for Slave ACK or NACK: cleared when complete address is sent

        if(EUSCI_B0->IFG & UCNACKIFG)            //reply back from the slave (NACK)
        {
            EUSCI_B0->CTLW0 |= UCTXSTP;          //send STOP condition if NACK received
            nak_i2c0 = 1;
            delay_cycles(DELAY_100);
            break;
        }
        EUSCI_B0->TXBUF = *wbuf++;
        while((EUSCI_B0->IFG & UCTXIFG) == 0);   // Wait for TXIFG=1

        __delay_cycles(DELAY_100);                 // adding RS v4 for letting some bits get sent. Didn't work
        delay_cycles(DELAY_100);                 // adding RS v4 for letting some bits get sent. Didn't work

        if( bytes_left == 1 )
        {
          if( repeated_start_i2c0 == 0 )
          {
              EUSCI_B0->CTLW0 |= UCTXSTP;
              EUSCI_B0->CTLW0 &= ~UCTXIFG;       // added for RS but didn't work
          }
          else
          {
              EUSCI_B0->CTLW0 &= ~UCTR;          // added for RS but didn't work, Receive after Repeated Start
              EUSCI_B0->CTLW0 |= UCTXSTT;
            //UCB0CTL1 &= ~UCTXIFG;              // added for RS but didn't work
            repeated_start_i2c0 = 0;
          }
          break;
        }
        delay_cycles( DELAY_1000 );
        bytes_left--;
    } while( bytes_left > 0 );

    delay_cycles( DELAY_5000 );

    if( nak_i2c0 == 0 )
    {
       // UART_putchar('Y');
        return FUNC_SUCCESS;
    }

    else
    {
        //UART_putchar('N');
        return FUNC_FAILED;
    }
}

////////////////////////////////////////////////
// I2C0 REPEATED START SEND and RECV POLLED NEW
////////////////////////////////////////////////
uint8_t i2c0_send_rs_recv(uint8_t i2c_addr, uint8_t *wbuf, uint64_t send_count, uint8_t *rbuf, uint64_t recv_count)
{
  uint64_t bytes_left;

  while(EUSCI_B0->STATW & UCBBUSY);           // Wait until Bus is Available

  EUSCI_B0->CTLW0 |= UCSWRST;                // Enable SW reset UCB0
  EUSCI_B0->I2CSA = i2c_addr;               // Slave Address
  nak_i2c0 = 0;                       // Set NAK received flag to FALSE
  EUSCI_B0->CTLW0 |= UCTR;                   // Master Transmitter
  EUSCI_B0->CTLW0 &= ~UCSWRST;               // Clear SW reset USCI_B0, resume operation

  while(EUSCI_B0->CTLW0 & UCTXSTP);           // Ensure bus 0 stop condition got sent
  EUSCI_B0->CTLW0 |= UCTXSTT;                  // Send START

  while((EUSCI_B0->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1
  EUSCI_B0->TXBUF = *wbuf;                    // slau356f p. 790 says this will be discarded

  bytes_left = send_count;

  do {
        while(EUSCI_B0->CTLW0 & UCTXSTT);          // Wait for Slave ACK or NACK: cleared after complete address is sent

        if(EUSCI_B0->IFG & UCNACKIFG )
        {
            EUSCI_B0->CTLW0 |= UCTXSTP;
            nak_i2c0 = 1;
            delay_cycles( DELAY_100 );
            break;
        }

        EUSCI_B0->TXBUF = *wbuf++;
        while((EUSCI_B0->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1

        bytes_left--;
        } while(bytes_left >= 1); //changed from > to >= 8-25-16

  if(nak_i2c0 == 0)               // Slave sent ACK
   {
      EUSCI_B0->CTLW0 &= ~UCTR;                // added for RS but didn't work, Receive after Repeated Start
      EUSCI_B0->CTLW0 |= UCTXSTT;
        //UCB0CTL1 &= ~UCTXIFG;             // added for RS but didn't work

        while(EUSCI_B0->CTLW0 & UCTXSTT);        // Wait for Slave ACK or NAK

        if(EUSCI_B0->IFG & UCNACKIFG)
        {
            EUSCI_B0->CTLW0 |= UCTXSTP;
            nak_i2c0 = 1;
            delay_cycles(DELAY_100 );
        }

        if(nak_i2c0 == 0)         // Slave sent ACK
        {
            bytes_left = recv_count;
            do {
                if(bytes_left == 1)
                {
                    delay_cycles( DELAY_1000);
                    EUSCI_B0->CTLW0 |= UCTXSTP;           // Send STOP condition
                }

                while((EUSCI_B0->IFG & UCRXIFG) == 0 ); // Wait for RXIFG=1
                *rbuf++ = EUSCI_B0->RXBUF;               // Read character

                bytes_left--;
                } while( bytes_left > 0 );
        }
    }

    if( nak_i2c0 == 0 )
    {
        // UART_putchar('Y');
         return FUNC_SUCCESS;
    }

    else
    {
        // UART_putchar('N');
         return FUNC_FAILED;
    }
}


//////////////////////////////////
// i2c2 SEND POLLED NEW
/////////////////////////////////
uint8_t i2c2_send(uint8_t i2c_addr, uint8_t *wbuf, uint64_t byte_count)
{
    uint64_t bytes_left;

    while(EUSCI_B2->STATW & UCBBUSY);           // Wait until Bus is Available

    EUSCI_B2->CTLW0 |= UCSWRST;                 // Enable SW reset UCB0
    EUSCI_B2->I2CSA = i2c_addr;                  // Slave Address
    nak_i2c2 = 0;                         // Set NAK received flag to FALSE
    EUSCI_B2->CTLW0 |= UCTR;                    // Master Transmitter
    EUSCI_B2->CTLW0 &= ~UCSWRST;                // Clear SW reset USCI_B0, resume operation
    repeated_start_i2c2 = 0;

    while(EUSCI_B2->CTLW0 & UCTXSTP);           // Ensure bus 0 stop condition got sent

    EUSCI_B2->CTLW0 |= UCTXSTT;                 // Send START
    while((EUSCI_B2->IFG & UCTXIFG) == 0 );    // Wait for TXIFG=1:set when start condition is generated
    I2C2_TX_BUF = *wbuf;                    // slau356f p. 790 says this will be discarded

    bytes_left = byte_count;
    do
    {
        while(EUSCI_B2->CTLW0 & UCTXSTT);            // Wait for Slave ACK or NACK: cleared when complete address is sent

        if( EUSCI_B2->IFG & UCNACKIFG )
        {
            EUSCI_B2->CTLW0 |= UCTXSTP;
            nak_i2c2 = 1;
            delay_cycles( DELAY_100 );
            break;
        }

        I2C2_TX_BUF = *wbuf++;
        while((EUSCI_B2->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1

        delay_cycles( DELAY_100 );         // adding RS v4 for letting some bits get sent. Didn't work
        delay_cycles( DELAY_100 );         // adding RS v4 for letting some bits get sent. Didn't work
        if( bytes_left == 1 )
        {
          if( repeated_start_i2c2 == 0 )
          {
              EUSCI_B2->CTLW0 |= UCTXSTP;
              EUSCI_B2->CTLW0 &= ~UCTXIFG;             // added for RS but didn't work
          }
          else
          {
              EUSCI_B2->CTLW0 &= ~UCTR;                // added for RS but didn't work, Receive after Repeated Start
              EUSCI_B2->CTLW0 |= UCTXSTT;
            //UCB0CTL1 &= ~UCTXIFG;             // added for RS but didn't work
            repeated_start_i2c0 = 0;
          }
          break;
        }
        delay_cycles( DELAY_1000 );

        bytes_left--;
    } while( bytes_left > 0 );

    delay_cycles( DELAY_5000 );

    if( nak_i2c2 == 0 )
   {
        //UART_putchar('Y');
        return FUNC_SUCCESS;
   }

   else
   {
        //UART_putchar('N');
        return FUNC_FAILED;
   }
}
////////////////////////////////////////////////
// I2C2 REPEATED START SEND and RECV POLLED NEW
////////////////////////////////////////////////
uint8_t i2c2_send_rs_recv(uint8_t i2c_addr, uint8_t *wbuf, uint64_t send_count, uint8_t *rbuf, uint64_t recv_count)
{
  uint64_t bytes_left;

  while(EUSCI_B2->STATW & UCBBUSY);           // Wait until Bus is Available

  EUSCI_B2->CTLW0 |= UCSWRST;                // Enable SW reset UCB0
  EUSCI_B2->I2CSA = i2c_addr;               // Slave Address
  nak_i2c2 = 0;                       // Set NAK received flag to FALSE
  EUSCI_B2->CTLW0 |= UCTR;                   // Master Transmitter
  EUSCI_B2->CTLW0 &= ~UCSWRST;               // Clear SW reset USCI_B0, resume operation

  while(EUSCI_B2->CTLW0 & UCTXSTP);           // Ensure bus 0 stop condition got sent
  EUSCI_B2->CTLW0 |= UCTXSTT;                  // Send START

  while((EUSCI_B2->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1
  EUSCI_B2->TXBUF = *wbuf;                    // slau356f p. 790 says this will be discarded

  bytes_left = send_count;

  do {
        while(EUSCI_B2->CTLW0 & UCTXSTT);          // Wait for Slave ACK or NACK: cleared after complete address is sent

        if(EUSCI_B2->IFG & UCNACKIFG )
        {
            EUSCI_B2->CTLW0 |= UCTXSTP;
            nak_i2c2 = 1;
            delay_cycles( DELAY_100 );
            break;
        }

        EUSCI_B2->TXBUF = *wbuf++;
        while((EUSCI_B2->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1

        bytes_left--;
        } while(bytes_left >= 1); //changed from > to >= 8-25-16

  if(nak_i2c2 == 0)               // Slave sent ACK
   {
      EUSCI_B2->CTLW0 &= ~UCTR;                // added for RS but didn't work, Receive after Repeated Start
      EUSCI_B2->CTLW0 |= UCTXSTT;
        //UCB2CTL1 &= ~UCTXIFG;             // added for RS but didn't work

        while(EUSCI_B2->CTLW0 & UCTXSTT);        // Wait for Slave ACK or NAK

        if(EUSCI_B2->IFG & UCNACKIFG)
        {
            EUSCI_B2->CTLW0 |= UCTXSTP;
            nak_i2c2 = 1;
            delay_cycles(DELAY_100 );
        }

        if(nak_i2c2 == 0)         // Slave sent ACK
        {
            bytes_left = recv_count;
            do {
                if(bytes_left == 1)
                {
                    delay_cycles( DELAY_1000);
                    EUSCI_B2->CTLW0 |= UCTXSTP;           // Send STOP condition
                }

                while((EUSCI_B2->IFG & UCRXIFG) == 0 ); // Wait for RXIFG=1
                *rbuf++ = EUSCI_B2->RXBUF;               // Read character

                bytes_left--;
                } while( bytes_left > 0 );
        }
    }

    if( nak_i2c2 == 0 )
    {
        // UART_putchar('Y');
         return FUNC_SUCCESS;
    }

    else
    {
        // UART_putchar('N');
         return FUNC_FAILED;
    }
}

//////////////////////////////////
// I2C0 RECV POLLED
/////////////////////////////////
uint8_t i2c0_recv(uint8_t i2c_addr, uint8_t *rbuf, uint8_t byte_count)
{
    uint64_t bytes_left;

    while(EUSCI_B0->STATW & UCBBUSY);              // Wait until Bus is Available

    EUSCI_B0->CTLW0 |= UCSWRST;                           // Enable SW reset for eUSCI_B0
    EUSCI_B0->I2CSA = i2c_addr;                           // Slave Address
    nak_i2c0 = 0;                                         // Set NACK received flag to FALSE
    EUSCI_B0->CTLW0 &= ~UCTR;                             // Master Receiver Mode
    EUSCI_B0->CTLW0 &= ~UCSWRST;                          // Clear SW reset for eUSCI_B0, resume operation

    while(EUSCI_B0->CTLW0 & UCTXSTP);                     // Ensure bus 0 stop condition got sent
    EUSCI_B0->CTLW0 |= UCTXSTT;                           // Send START

    while(EUSCI_B0->CTLW0 & UCTXSTT);                     // Wait for Slave ACK or NACK
    if( EUSCI_B0->IFG & UCNACKIFG )
    {
      EUSCI_B0->CTLW0 |= UCTXSTP;
      nak_i2c0 = 1;
      delay_cycles( DELAY_100 );
    }

    if(nak_i2c0 == 0)                                     // Slave sent ACK
    {
    bytes_left = byte_count;

    do {
        if( bytes_left == 1 )
        {
            delay_cycles(DELAY_1000);
            EUSCI_B0->CTLW0 |= UCTXSTP;                 // Send STOP condition
        }

        while((EUSCI_B0->IFG & UCRXIFG) == 0 );         // Wait for RXIFG=1
        *rbuf++ = EUSCI_B0->RXBUF;                      // Read character

        bytes_left--;

        } while( bytes_left > 0 );
    }

    delay_cycles( DELAY_5000 );

    if( nak_i2c0 == 0 )
    {
        // UART_putchar('Y');
         return FUNC_SUCCESS;
    }

    else
    {
         //UART_putchar('N');
         return FUNC_FAILED;
    }
}


//////////////////////////////////
// i2c2 RECV POLLED
/////////////////////////////////
uint8_t i2c2_recv(uint8_t i2c_addr, uint8_t *rbuf, uint64_t byte_count)
{
  uint64_t bytes_left;

  while( EUSCI_B2->STATW & UCBBUSY );        // Wait until Bus is Available

  EUSCI_B2->CTLW0 |= UCSWRST;                // Enable SW reset UCB0
  EUSCI_B2->I2CSA = i2c_addr;               // Slave Address is 020h
  nak_i2c2 = 0;
  EUSCI_B2->CTLW0 &= ~UCTR;                  // Become Master Receiver
  EUSCI_B2->CTLW0 &= ~UCSWRST;               // Clear SW reset USCI_B2, resume operation

  while( EUSCI_B2->CTLW0 & UCTXSTP );      // Ensure bus 0 stop condition got sent
  EUSCI_B2->CTLW0 |= UCTXSTT;              // Send START

  while( EUSCI_B2->CTLW0 & UCTXSTT );        // Wait for Slave ACK or NAK
  if( EUSCI_B2->IFG & UCNACKIFG )
  {
      EUSCI_B2->CTLW0 |= UCTXSTP;
      nak_i2c2 = 1;
      delay_cycles( DELAY_100 );
  }

  if( nak_i2c2 == 0 )           // Slave sent ACK
  {
    bytes_left = byte_count;

    do {
       if( bytes_left == 1 )
       {
        delay_cycles(DELAY_1000);
        EUSCI_B2->CTLW0 |= UCTXSTP;           // Send STOP condition
       }

       while( (EUSCI_B2->IFG & UCRXIFG) == 0 ); // Wait for RXIFG=1
       *rbuf++ = EUSCI_B2->RXBUF;               // Read character

       bytes_left--;
    } while( bytes_left > 0 );
  }

  delay_cycles( DELAY_5000 );

  if( nak_i2c2 == 0 )
  {
     //  UART_putchar('Y');
       return FUNC_SUCCESS;
  }

  else
  {
    //   UART_putchar('N');
       return FUNC_FAILED;
  }
}

//////////////////////////////////
// I2C0 PING
/////////////////////////////////
uint8_t ping_i2c0(uint8_t i2c_addr)
{
    EUSCI_B0->CTLW0 |= UCSWRST;         // Enable SW reset UCB0
    EUSCI_B0->I2CSA = i2c_addr;         // Slave Address
    EUSCI_B0->CTLW0 &= ~UCTR;           // Become Master Receiver
    EUSCI_B0->CTLW0 &= ~UCSWRST;        // Clear SW reset USCI_B2, resume operation
//    UCB0IE |= UCRXIE;            // Enable I2C RX interrupt
//    UCB0IE |= UCNACKIE;           // Enable NAK interrupt

    nak_i2c0 = 0;
//    PRxData_i2c0 = &ReadBuffer;  // RX array start address
                                 // Place breakpoint here to see each
                                 // transmit operation.
//    RXByteCtr_i2c0 = 1;          // Load RX byte counter
   // EUSCI_B0->CTLW0 |= UCTXSTP;         // I2C stop condition

    while (EUSCI_B0->CTLW0 & UCTXSTP);  // Ensure bus 1 stop condition got sent
    EUSCI_B0->CTLW0 |= UCTXSTT;         // I2C RX, bus 1 start condition
    while((EUSCI_B0->CTLW0) & UCTXSTT ); // Start condition sent?
    EUSCI_B0->CTLW0 |= UCTXSTP;         // I2C stop condition

    if( EUSCI_B0->IFG & UCNACKIFG )
    {
        EUSCI_B0->CTLW0 |= UCTXSTP;
        nak_i2c0 = 1;
        delay_cycles( DELAY_100 );
    }

    if( nak_i2c0 == 0 )
    {
//       printf("I2C0 PING SUCCESSFUL\n\r");
       return FUNC_SUCCESS;
    }

    else
    {
//        printf("I2C0 PING FAILED\n\r");
        return FUNC_FAILED;
    }
}

//////////////////////////////////
// i2c2 PING
/////////////////////////////////
uint8_t ping_i2c2(uint8_t i2c_addr)
{
    EUSCI_B2->CTLW0 |= UCSWRST;         // Enable SW reset UCB0
    EUSCI_B2->I2CSA = i2c_addr;                // Slave Address
    EUSCI_B2->CTLW0 &= ~UCTR;           // Become Master Receiver
    EUSCI_B2->CTLW0 &= ~UCSWRST;        // Clear SW reset USCI_B2, resume operation
//    UCB0IE |= UCRXIE;            // Enable I2C RX interrupt
//    UCB0IE |= UCNACKIE;           // Enable NAK interrupt

    nak_i2c2 = 0;
//    PRxData_i2c0 = &ReadBuffer;  // RX array start address
                                 // Place breakpoint here to see each
                                 // transmit operation.
//    RXByteCtr_i2c0 = 1;          // Load RX byte counter
   // EUSCI_B0->CTLW0 |= UCTXSTP;         // I2C stop condition

    while (EUSCI_B2->CTLW0 & UCTXSTP);  // Ensure bus 1 stop condition got sent
    EUSCI_B2->CTLW0 |= UCTXSTT;         // I2C RX, bus 1 start condition
    while((EUSCI_B2->CTLW0) & UCTXSTT ); // Start condition sent?
    EUSCI_B2->CTLW0 |= UCTXSTP;         // I2C stop condition

    if( EUSCI_B2->IFG & UCNACKIFG )
    {
        EUSCI_B2->CTLW0 |= UCTXSTP;
        nak_i2c2 = 1;
        delay_cycles( DELAY_100 );
    }

    if( nak_i2c2 == 0 )
    {
      //  UART_putchar('Y');
        return FUNC_SUCCESS;
    }

    else
    {
      //  UART_putchar('N');
        return FUNC_FAILED;
    }
}


//////////////////////////////////
// I2C3 PING
/////////////////////////////////
uint8_t ping_i2c3(uint8_t i2c_addr)
{
    EUSCI_B3->CTLW0 |= UCSWRST;         // Enable SW reset UCB0
    EUSCI_B3->I2CSA = i2c_addr;         // Slave Address
    EUSCI_B3->CTLW0 &= ~UCTR;           // Become Master Receiver
    EUSCI_B3->CTLW0 &= ~UCSWRST;        // Clear SW reset USCI_B1, resume operation
//    UCB0IE |= UCRXIE;            // Enable I2C RX interrupt
//    UCB0IE |= UCNACKIE;           // Enable NAK interrupt

    nak_i2c3 = 0;
//    PRxData_i2c0 = &ReadBuffer;  // RX array start address
                                 // Place breakpoint here to see each
                                 // transmit operation.
//    RXByteCtr_i2c0 = 1;          // Load RX byte counter
   // EUSCI_B0->CTLW0 |= UCTXSTP;         // I2C stop condition

    while (EUSCI_B3->CTLW0 & UCTXSTP);  // Ensure bus 1 stop condition got sent
    EUSCI_B3->CTLW0 |= UCTXSTT;         // I2C RX, bus 1 start condition
//    delay_cycles(DELAY_1250000);
    while((EUSCI_B3->CTLW0) & UCTXSTT ); // Start condition sent?
//    delay_cycles(DELAY_2500);
    EUSCI_B3->CTLW0 |= UCTXSTP;         // I2C stop condition

    if( EUSCI_B3->IFG & UCNACKIFG )
    {
        EUSCI_B3->CTLW0 |= UCTXSTP;
        nak_i2c3 = 1;
        delay_cycles( DELAY_100 );
    }

    if( nak_i2c3 == 0 )
    {
//       printf("Success\n\r");
        return FUNC_SUCCESS;
    }

    else
    {
//       printf("Failed\n\r");
        return FUNC_FAILED;
    }
}

//////////////////////////////////
// i2c3 SEND POLLED NEW
/////////////////////////////////
uint8_t i2c3_send(uint8_t i2c_addr, uint8_t *wbuf, uint64_t byte_count)
{
    uint64_t bytes_left;

    while(EUSCI_B3->STATW & UCBBUSY);           // Wait until Bus is Available

    EUSCI_B3->CTLW0 |= UCSWRST;                 // Enable SW reset UCB3
    EUSCI_B3->I2CSA = i2c_addr;                  // Slave Address
    nak_i2c3 = 0;                         // Set NAK received flag to FALSE
    EUSCI_B3->CTLW0 |= UCTR;                    // Master Transmitter
    EUSCI_B3->CTLW0 &= ~UCSWRST;                // Clear SW reset USCI_B0, resume operation
    repeated_start_i2c3 = 0;

    while(EUSCI_B3->CTLW0 & UCTXSTP);           // Ensure bus 0 stop condition got sent

    EUSCI_B3->CTLW0 |= UCTXSTT;                 // Send START
    delay_cycles(DELAY_2500);
    while((EUSCI_B3->IFG & UCTXIFG) == 0 );    // Wait for TXIFG=1:set when start condition is generated
    I2C3_TX_BUF = *wbuf;                    // slau356f p. 790 says this will be discarded

    bytes_left = byte_count;
    do
    {
        while(EUSCI_B3->CTLW0 & UCTXSTT);            // Wait for Slave ACK or NACK: cleared when complete address is sent

        if( EUSCI_B3->IFG & UCNACKIFG )
        {
            EUSCI_B3->CTLW0 |= UCTXSTP;
            nak_i2c3 = 1;
            delay_cycles( DELAY_100 );
            break;
        }

        I2C3_TX_BUF = *wbuf++;
        while((EUSCI_B3->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1

        delay_cycles( DELAY_100 );         // adding RS v4 for letting some bits get sent. Didn't work
        delay_cycles( DELAY_100 );         // adding RS v4 for letting some bits get sent. Didn't work
        if( bytes_left == 1 )
        {
          if( repeated_start_i2c3 == 0 )
          {
              EUSCI_B3->CTLW0 |= UCTXSTP;
              EUSCI_B3->CTLW0 &= ~UCTXIFG;             // added for RS but didn't work
          }
          else
          {
              EUSCI_B3->CTLW0 &= ~UCTR;                // added for RS but didn't work, Receive after Repeated Start
              EUSCI_B3->CTLW0 |= UCTXSTT;
            //UCB0CTL1 &= ~UCTXIFG;             // added for RS but didn't work
            repeated_start_i2c3 = 0;
          }
          break;
        }
        delay_cycles( DELAY_1000 );

        bytes_left--;
    } while( bytes_left > 0 );

    delay_cycles( DELAY_5000 );

    if( nak_i2c3 == 0 )
   {
//        printf("Send Success\n\r");
        return FUNC_SUCCESS;
   }

   else
   {
//       printf("Send Failed\n\r");
       return FUNC_FAILED;
   }
}
//////////////////////////////////
// I2C3 RECV POLLED
/////////////////////////////////
uint8_t i2c3_recv(uint8_t i2c_addr, uint8_t *rbuf, uint8_t byte_count)
{
    uint64_t bytes_left;

    while(EUSCI_B3->STATW & UCBBUSY);              // Wait until Bus is Available

    EUSCI_B3->CTLW0 |= UCSWRST;                           // Enable SW reset for eUSCI_B0
    EUSCI_B3->I2CSA = i2c_addr;                           // Slave Address
    nak_i2c3 = 0;                                         // Set NACK received flag to FALSE
    EUSCI_B3->CTLW0 &= ~UCTR;                             // Master Receiver Mode
    EUSCI_B3->CTLW0 &= ~UCSWRST;                          // Clear SW reset for eUSCI_B0, resume operation

    while(EUSCI_B3->CTLW0 & UCTXSTP);                     // Ensure bus 0 stop condition got sent
    EUSCI_B3->CTLW0 |= UCTXSTT;                           // Send START

    while(EUSCI_B3->CTLW0 & UCTXSTT);                     // Wait for Slave ACK or NACK
    if( EUSCI_B3->IFG & UCNACKIFG )
    {
      EUSCI_B3->CTLW0 |= UCTXSTP;
      nak_i2c3 = 1;
      delay_cycles( DELAY_100 );
    }

    if(nak_i2c3 == 0)                                     // Slave sent ACK
    {
    bytes_left = byte_count;

    do {
        if( bytes_left == 1 )
        {
            delay_cycles(DELAY_1000);
            EUSCI_B3->CTLW0 |= UCTXSTP;                 // Send STOP condition
        }

        while((EUSCI_B3->IFG & UCRXIFG) == 0 );         // Wait for RXIFG=1
        *rbuf++ = EUSCI_B3->RXBUF;                      // Read character

        bytes_left--;

        } while( bytes_left > 0 );
    }

    delay_cycles( DELAY_5000 );

    if( nak_i2c3 == 0 )
    {
        // UART_putchar('Y');
         return FUNC_SUCCESS;
    }

    else
    {
         //UART_putchar('N');
         return FUNC_FAILED;
    }
}

////////////////////////////////////////////////
// I2C3 REPEATED START SEND and RECV POLLED NEW
////////////////////////////////////////////////
uint8_t i2c3_send_rs_recv(uint8_t i2c_addr, uint8_t *wbuf, uint64_t send_count, uint8_t *rbuf, uint64_t recv_count)
{
  uint64_t bytes_left;

  while(EUSCI_B3->STATW & UCBBUSY);           // Wait until Bus is Available

  EUSCI_B3->CTLW0 |= UCSWRST;                // Enable SW reset UCB3
  EUSCI_B3->I2CSA = i2c_addr;               // Slave Address
  nak_i2c3 = 0;                       // Set NAK received flag to FALSE
  EUSCI_B3->CTLW0 |= UCTR;                   // Master Transmitter
  EUSCI_B3->CTLW0 &= ~UCSWRST;               // Clear SW reset USCI_B0, resume operation

  while(EUSCI_B3->CTLW0 & UCTXSTP);           // Ensure bus 0 stop condition got sent
  EUSCI_B3->CTLW0 |= UCTXSTT;                  // Send START

  while((EUSCI_B3->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1
  EUSCI_B3->TXBUF = *wbuf;                    // slau356f p. 790 says this will be discarded

  bytes_left = send_count;

  do {
        while(EUSCI_B3->CTLW0 & UCTXSTT);          // Wait for Slave ACK or NACK: cleared after complete address is sent

        if(EUSCI_B3->IFG & UCNACKIFG )
        {
            EUSCI_B3->CTLW0 |= UCTXSTP;
            nak_i2c3 = 1;
            delay_cycles( DELAY_100 );
            break;
        }

        EUSCI_B3->TXBUF = *wbuf++;
        while((EUSCI_B3->IFG & UCTXIFG) == 0);    // Wait for TXIFG=1

        bytes_left--;
        } while(bytes_left >= 1); //changed from > to >= 8-25-16

  if(nak_i2c3 == 0)               // Slave sent ACK
   {
      EUSCI_B3->CTLW0 &= ~UCTR;                // added for RS but didn't work, Receive after Repeated Start
      EUSCI_B3->CTLW0 |= UCTXSTT;
        //UCB2CTL1 &= ~UCTXIFG;             // added for RS but didn't work

        while(EUSCI_B3->CTLW0 & UCTXSTT);        // Wait for Slave ACK or NAK

        if(EUSCI_B3->IFG & UCNACKIFG)
        {
            EUSCI_B3->CTLW0 |= UCTXSTP;
            nak_i2c3 = 1;
            delay_cycles(DELAY_100 );
        }

        if(nak_i2c3 == 0)         // Slave sent ACK
        {
            bytes_left = recv_count;
            do {
                if(bytes_left == 1)
                {
                    delay_cycles( DELAY_1000);
                    EUSCI_B3->CTLW0 |= UCTXSTP;           // Send STOP condition
                }

                while((EUSCI_B3->IFG & UCRXIFG) == 0 ); // Wait for RXIFG=1
                *rbuf++ = EUSCI_B3->RXBUF;               // Read character

                bytes_left--;
                } while( bytes_left > 0 );
        }
    }

    if( nak_i2c3 == 0 )
    {
//        printf("RS Success\n\r");
        return FUNC_SUCCESS;
    }

    else
    {
//        printf("RS Failed\n\r");
        return FUNC_FAILED;
    }
}
