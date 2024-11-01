/*
    hw_pic18.c
    Microchip pic18 hardware low-level routines
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

    MCU:   PIC18F66J65
    Crystal:  25MHz
    Operating frequency:  41 MHz
    UART Speed:     SPI Mode
    Connection:
      MicroVGA.TXD = PIC18.RC
      MicroVGA.RXD = PIC18.RC
      MicroVGA.RTS = PIC18.RC
      MicroVGA.CTS = PIC18.RC

    _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/

#include <p18f66j65.h>

#include "../h/conio.h"


#pragma config XINST=OFF, CP0=OFF, WDT=OFF, WDTPS=32, FOSC2=ON, FOSC=HSPLL, ETHLED=ON

/*
_putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)

*/

void _putch (char ch)
{
   //unsigned char tmp;

   while (PORTCbits.RC1==1); // wait for completion
   SSPBUF = ch; // send address
   while ( SSPSTATbits.BF == 0) ; // wait until end of  transfer
}

int _getch (void)
{
  int ch;

  return 0;
}

int _kbhit (void)
{
 
   return 0;
}


void MCU_Init()
{
  int i;

  // Enable 4x/5x PLL on PIC18F87J10, PIC18F97J60, etc.
  OSCTUNE = 0x40;

  PORTC = 0;
  TRISCbits.TRISC1 = 1; // RDY# in
  TRISCbits.TRISC5 = 0; // SDO - out
  TRISCbits.TRISC4 = 1; // SDI - in
  TRISCbits.TRISC3 = 0; // SCK - out
  TRISCbits.TRISC2 = 0; // CS# - out

  SSPCON1 = 0;
  /*while (PORTCbits.RC1 == 0) {
    PORTCbits.RC3 = 1;
    PORTCbits.RC3 = 0;
    for (i=1;i;i++);
  }*/

  SSPSTAT = 0x00;  // CKE=0
  SSPCON1 = 0x22; // SSPEN, master mode clock=Fosc/4
}
