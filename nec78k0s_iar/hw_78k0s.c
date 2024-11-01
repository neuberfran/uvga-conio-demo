/*
    hw_78k0s.c
    NEC 78k0s hardware low-level routines
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

    MCU:   78k0s
    Operating frequency:  8 MHz
    UART Speed:     1 Mbit
    Connection:
      MicroVGA.TXD = 78k0s.P44_RxD6 (P0_8)
      MicroVGA.RXD = 78k0s.P43_TxD6 (P0_9)
      MicroVGA.CTS = 78k0s.P20

    _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/

#include "io78f9222.h"	
#include <intrinsics.h>

//-----------------------------------------------------------------------------
// Definition of Option Byte
//-----------------------------------------------------------------------------
#pragma location = "OPTBYTE"
__root const unsigned char optbyte = 0x9A;	      //Shortest stabilisation time 2^10/fx
                                                      //RESET pin is used as is
                                                      //External clock input
                                                      //Ring osc can be stopped

//-----------------------------------------------------------------------------
// Global Defines
//-----------------------------------------------------------------------------

//allowed values:9600, 19200, 38400, 57600, 115200,500000,1000000,1250000
#define BAUDRATE 1000000 //set baudrate
//-----------------------------------------------------------------------------
// Module:   init_CPU
// Function: Initialization of CPU
//-----------------------------------------------------------------------------
void init_CPU (void)
{
// stop watchdog timer
  WDTM = 0x70;

//time gererator settings
  PCC = 0x00;			// set CPU time to fx
  PPCC = 0x00;

  HSRCM = 0x00;			// high speed ring oscillator operates
  LSRCM = 0x01;			// low speed ring oscillator stops

  OSTS  = 0x00;			//shortest stabilisation time 2^10/fx

// interrupt setting
   IF0  = 0x00;
   IF1  = 0x00;
   MK0  = 0xFF;
   MK1  = 0xFF;
   
   PMC2_bit.no1=0; // set port mode control of P20 to port mode
   PM2_bit.no0=1; // Set P20 as input
}

//-----------------------------------------------------------------------------
// Module:   init_UART
// Function: Initialization of UART6
//-----------------------------------------------------------------------------
void init_UART()
{
  
  PM4_bit.no4=1;            //input mode for RxD
  PM4_bit.no3=0;            //output mode for TxD
  P4_bit.no3=1;             //set TxD output to high level

//setbaudrate - Fosc (Fxp) == 8Mhz
//baudrate=Fosc/(2^CKSR6)/BRGC6/2
#if BAUDRATE==9600          //initialization for baudrate = 9600
    CKSR6 = 0x02;
    BRGC6 = 104;
#elif BAUDRATE==19200       //initialization for baudrate = 19200
    CKSR6 = 0x01;
    BRGC6 = 104;
#elif BAUDRATE==38400       //initialization for baudrate = 38400
    CKSR6 = 0x00;
    BRGC6 = 104;
#elif BAUDRATE==57600       //initialization for baudrate = 57600
    CKSR6 = 0x00;
    BRGC6 = 69;
#elif BAUDRATE==115200       //initialization for baudrate = 115200
    CKSR6 = 0x00;
    BRGC6 = 34;
#elif BAUDRATE==500000       //initialization for baudrate = 500000
    CKSR6 = 0x00;
    BRGC6 = 8;
#elif BAUDRATE==1000000       //initialization for baudrate = 1000000
    CKSR6 = 0x00;
    BRGC6 = 4;
#elif BAUDRATE==1250000       //initialization for baudrate = 1250000
    CKSR6 = 0x00;
    BRGC6 = 3;
#endif

  POWER6 = 1;               //enable internal clock operation

  ASIM6 |= 0xE5;            //enable transmission
                            //enable reception
                            //no parity
                            //character lenght of data = 8-bits
                            //number of stop bits = 1
}


void MCU_Init(void)
{
  __disable_interrupt();	// global interrupt disable

  init_CPU();                   // cpu initialization
  init_UART();			// uart60 initialization
}


int _kbhit (void)
{
 return (IF1 & 0x20);
}

int _getch (void)
{
  int ch;
     
  while(!(IF1 & 0x20));               // wait for uart receive byte
  ch = RXB6;         // load UART receive buffer
  SRIF6=0;
  
  if (ch == 0)
  { //special key pressed, read second byte
     while(!(IF1 & 0x20));               // wait for uart receive byte
     ch = RXB6;         // load UART receive buffer
     SRIF6=0;
     ch = 0x100 | ch;
  }
  
  return ch;
}

void _putch (char ch)
{
    //Wait for RTS (uVGA ready to recv data) 
    //low -> uVGA is ready to recv data
    while(P2&0x01);
    
    TXB6 = ch;              // load UART transmit buffer
    while(!STIF6);              // wait for transmission finished
    STIF6=0;
}