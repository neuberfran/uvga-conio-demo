/*
    hw_tms470.c
    Texas Instruments TMS470 hardware low-level routines
    Part of MicroVGA CONIO library / demo project
    Copyright (c) 2008-9 SECONS s.r.o., http://www.MicroVGA.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    MCU:   TMS470R1A128
    Crystal:  6 MHz
    Operating frequency:  48 MHz
    UART Speed:     1 Mbit
    Connection:
      MicroVGA.TXD = TMS470.SCI1RX
      MicroVGA.RXD = TMS470.SCI1TX
      MicroVGA.RTS = TMS470.C2SIaRX  (GPIO configuration)
      MicroVGA.CTS = TMS470.C2SIaTX  (GPIO configuration)

   _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/


#include <TexasInstruments/iotms470r1a128.h>
#include <intrinsics.h>
#include <TexasInstruments/tms470r1a256_bit_definitions.h>


// ICODE is the same segment as cstartup. By placing __low_level_init
// in the same segment, we make sure it can be reached with BL.

#pragma language=extended


#undef    PSTDBY_MAX
#undef    PSLEEP_MAX
#undef    BSTDBY_MAX
#undef    BSLEEP_MAX

#define   PSTDBY_MAX     ((unsigned int) 0x3C <<  5)    // 15:5   Pump standby (1.0uS at 60MHz)
#define   PSLEEP_MAX     ((unsigned int) 0x78 <<  0)    // 14:1   Pump sleep (2.0uS at 60MHz)
#define   BSTDBY_MAX     ((unsigned int) 0x06 <<  2)    // 7:2    Bank standby (100nS at 60MHz)
#define   BSLEEP_MAX     ((unsigned int) 0x72 <<  8)    // 14:8   Bank sleep (1.9uS at 60MHz)

#pragma location="ICODE"

//unit MCU
int __low_level_init(void)
{
  // Disable peripheral access violation, memory access rights violation,
  // and illegal address reset
  SYSECR = RESET0 + PACCOVR + ACCOVR + ILLOVR;

  // Flash is 128K at 0x00000000 is einitialized as follows
  // Activate Flash at 0x00000000 that is connected to memory select 0,
  // set size to 128KB, enable read-only protection

  MFBAHR0 = 0x00000000;
  MFBALR0 |= BLOCK_SIZE_128K + RONLY;

  // De activate FLASH at 0x00000000 that is connected to memory select 1,
  // set size to 0KB

  MFBAHR1 = 0x00000000;
  MFBALR1 = 0x00000000;


  // RAM is 12K at 0x00400000 is einitialized as follows
  // Activate RAM at 0x00400000 that is connected to memory select 2,
  // set size to 8KB
  MFBAHR2 = 0x00000040;
  MFBALR2 = BLOCK_SIZE_8K;

  // De activate RAM at 0x00000000 that is connected to memory select 3,
  // set size to 0KB
  MFBAHR3 = 0x00000000;
  MFBALR3 = 0x00000000;

  // HET RAM static memory control register, use 7 wait states and
  // 32-bit access
  SMCR1 = WS_7 + DW_32;

  // Activate HET RAM at 0x00800000 that is connected to memory select 4,
  // set size to 2KB
  MFBAHR4 = 0x00000080;
  MFBALR4 = BLOCK_SIZE_2K;

  // Trailing wait states controlled by TWS bits, use write buffer for
  // expansion bus access
  WCR0 = WTWSOVR + WBENABLE;

  // Enable selected memory map
  MFBALR0 |= MS;

  // Enable Flash configuration mode, set PLL factor X4, divide by 1
  GCR |= FLCONFIG;

//  SET FLASH WAIT STATES

  FMMAC1 = PSLEEP_MAX;                               // pump sleep to standby time
  FMMAC2 = BANK0_ENA + PMPPWR_ACTIVE + PSTDBY_MAX;   // bank0
  FMBAC1 = BNKPWR_ACTIVE+ BSTDBY_MAX;                // active
  FMBAC2 = PIPELINE_MODE + BSLEEP_MAX;               // 0 wait states
  FMREGOPT = ENPIPE;                                 // ENABLE PIPELINE MODE

  // Disable Flash configuration mode
  GCR =  ZPLL_CLK_DIV_PRE_1;                // xtal=6mhz, gclk=8*6MHz

  return 1; // Must return 1 to initialize C data.
}

#pragma language=default


void _putch (char ch) 
{
   // Transmitter buffer and shift registers are both empty.
   // Both SCITXBUF and SCITXSHF must be empty before next char is sended.
   // Otherwise uVGA is unable to signal "stop sending data" due to double buffering  
   while (!(SCI1CTL2 & TX_EMPTY));
   
   //Check RXDIN for uVGA RTS handshake pin (we can send data -> uVGA ready)
   while ((C2SIAPC3 & RXDIN)!=0);
   
   //Check GIO A0 for uVGA RTS handshake pin (we can send data -> uVGA ready)
   //while ((GIODINA & X0) !=0);
   
   SCI1TXBUF = ch;// Transmit character   
}

int _kbhit (void)
{ 
  //new data in SCIRXBUF or new data are coming to SCIRXSHF
  return ((SCI1CTL1&RXRDY) || (SCI1RXST & BUS_BUSY)); 
}

int _getch (void)
{
  int key;
  
  while (!(SCI1CTL1&RXRDY)); //wait for new data in SCIRXBUF
  key = SCI1RXBUF;
  if (key != 0)
    return key;
  
  while (!(SCI1CTL1&RXRDY)); //wait for new data in SCIRXBUF
  key = SCI1RXBUF;
  return 0x100|key;
}

#define ICLK (8*6000000)            // PLL: ICLK=8*XTAL

/*
Functional baudrates for 6Mhz XTAL:
9600, 19200, 38400, 57600, 115200, 460800, 500000, 1000000
*/
void setUARTBaudRate(int baudrate)
{
  int brg;

  brg = (ICLK)/(baudrate*8)-1;
  
  SCI1LBAUD = brg;                        // XTAL/8/baudrate
  SCI1MBAUD = brg>>8;
  SCI1HBAUD = brg>>16;
}

void MCU_Init()
{
  PCR = CLKDIV_1;                         // ICLK = SYSCLK
  PCR |= PENABLE;                         // enable peripherals

  SCI1CTL3 &= ~SW_NRESET;                 // Reset SCI state machine
  SCI1CCR = TIMING_MODE_ASYNC + CHAR_8;   // Async, 8-bit Char
  SCI1CTL1 |= RXENA;                      // RX enabled
  SCI1CTL2 |= TXENA;                      // TX enabled
  SCI1CTL3 |= CLOCK ;                     // Internal clock.
  
  setUARTBaudRate(1000000);
  
  SCI1PC2 |= RX_FUNC;                     // SCIRX is the SCI receive pin
  SCI1PC3 |= TX_FUNC;                     // SCITX is the SCI transmit pin
  SCI1CTL3 |= SW_NRESET;                  // Configure SCI1 state machine
  
  C2SIAPC2 = 0x00;                        // set C2SIATX to low
    
  C2SIAPC1 = C2_TXDIR;                    // set C2SIB pins as GPIO (C2SIATX - output, C2SIARX - input)
  
  
/*  GIODIRA&= ~X0;                    // Set GIO A0 as input
    GIODIRA|= X1;                     // Set GIO A1 as output
*/
  
}