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

    MCU:   Renesas M16C 62p
    Operating frequency:  24 MHz
    UART Speed:    19200
    Connection:
      MicroVGA.TXD = M16C62P.P6_2
      MicroVGA.RXD = M16C62P.P6_3
      MicroVGA.CTS = not used

    _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/


/* Include the required header files */

#include "sfr62p.h"  		// M16C/62P special function register definitions
#include "../../h/conio.h"
#define BAUD_RATE	19200

#define	f1_CLK_SPEED		24000000		// Peripheral Clock Speed - set up in mcu_init()

void _putch(char ch)
{
		u0tb = ch;
		while (ti_u0c1 == 0); 			//  puts it in the UART 0 transmit buffer 
}

int _kbhit()
{
		if (ri_u0c1) 
		  return 1;

		return 0;
}

int _getch(void)
{
  int ch;
     
  while(!(ri_u0c1));               // wait for uart receive byte
  ch = u0rb;         // load UART receive buffer
  
  if (ch == 0)
  { //special key pressed, read second byte
     while(!(ri_u0c1));               // wait for uart receive byte
     ch = u0rb;         // load UART receive buffer
     ch = 0x100 | ch;
  }
  
  return ch;
}

void MCU_Init(void)
{
	 unsigned int count = 20000;
  
	/* configure clock for divide by 1 mode */
	prc0 =1;					/* enable access to clock registers */
	cm1 = 0x20;					/* set CM16,CM17 divide ratio to 1, 
									main clock on in high drive no PLL*/
	cm06 = 0;					/* set divide ratio to 1 */		
	
    /* configure and switch main clock to PLL at 24MHz - comment this section
		out if PLL operation is not desired								*/
   
	prc1 = 1;					/* allow writing to processor mode register */
	pm20 = 1;					/* set SFR access to 2 wait which is required for
   									operation greater than 16 MHz */
	prc1 = 0;					/* protect processor mode register */

	plc0= 0x91;					// enable PLL (2X) and turn on

	while(count > 0) count--;   /* wait for PLL to stabilize (20mS maximum, 240,000 cycles @12Mhz)
                                   this decrement with no optimization is 12 cycles each */
    cm11 = 1;                   /* switch to PLL */
    prc0 = 0;   				/* protect clock control register */
	
	prc1 = 1;
	pm10 = 1;		// enable data flash area
	prc1 = 0;



  // Initialize UART
	u0brg = (unsigned char)(((f1_CLK_SPEED/16)/19200)-1);	// set UART0 bit rate generator
		 /*
	  	  bit rate can be calculated by:
	  	  bit rate = ((BRG count source / 16)/baud rate) - 1

		  in this example: BRG count source = f1 (12MHz - Xin in SKP16C62P)
						   baud rate = 19200
						   bit rate = ((12MHz/16)/19200) - 1 = 38 

	  	  ** one has to remember that the value of BCLK does not affect BRG count source */
  
  	ucon = 0x00; 		// UART transmit/receive control register 2
		 /*
		  00000000; 	// transmit irq not used
		  ||||||||______UART0 transmit irq cause select bit, U0IRS
	   	  |||||||_______UART1 transmit irq cause select bit, U1IRS
	   	  ||||||________UART0 continuous receive mode enable bit, U0RRM - set to 0 in UART mode
	  	  |||||_________UART1 continuous receive mode enable bit, U1RRM	- set to 0 in UART mode
	   	  ||||__________CLK/CLKS select bit 0, CLKMD0 - set to 0 in UART mode
	   	  |||___________CLK/CLKS select bit 1, CLKMD1 - set to 0 in UART mode
	   	  ||____________Separate CTS/RTS bit, RCSP
	  	  |_____________Reserved, set to 0 */

  	u0c0 = 0x10; 		// UART0 transmit/receive control register 1
		 /*
		  00010000;		// f1 count source, CTS/RTS disabled, CMOS output  
		  ||||||||______BRG count source select bit, CLK0
	   	  |||||||_______BRG count source select bit, CLK1
	   	  ||||||________CTS/RTS function select bit, CRS
	  	  |||||_________Transmit register empty flag, TXEPT
	   	  ||||__________CTS/RTS disable bit, CRD
	   	  |||___________Data output select bit, NCH
	   	  ||____________CLK polarity select bit, CKPOL 		- set to 0 in UART mode
	  	  |_____________Transfer format select bit, UFORM 	- set to 0 in UART mode */

  	u0c1 = 0x00; 		// UART0 transmit/receive control register 1
		 /*
		  00000000;		// disable transmit and receive 
		  ||||||||______Transmit enable bit, TE
	   	  |||||||_______Transmit buffer empty flag, TI
	   	  ||||||________Receive enable bit, RE
	  	  |||||_________Receive complete flag, RI
	   	  ||||__________Reserved, set to 0
	   	  |||___________Reserved, set to 0
	   	  ||____________Data logic select bit, U0LCH
	  	  |_____________Error signal output enable bit, U0ERE */

  	u0mr = 0x05;		// UART0 transmit/receive mode register, not reversed
		 /*
		  00000101;		// 8-bit data, internal clock, 1 stop bit, no parity
		  ||||||||______Serial I/O Mode select bit, SMD0
	   	  |||||||_______Serial I/O Mode select bit, SMD1
	   	  ||||||________Serial I/O Mode select bit, SMD2
	  	  |||||_________Internal/External clock select bit, CKDIR
	   	  ||||__________Stop bit length select bit, STPS
	   	  |||___________Odd/even parity select bit, PRY
	   	  ||____________Parity enable bit, PRYE
	  	  |_____________TxD, RxD I/O polarity reverse bit */

  	u0tb = u0rb;		// clear UART0 receive buffer by reading
  	u0tb = 0;			// clear UART0 transmit buffer

    			// disable irqs before setting irq registers
 
   
  	u0c1 = 0x05; 		// UART0 transmit/receive control register 1
		 /*
		  00000101;		// enable transmit and receive 
		  ||||||||______Transmit enable bit, TE
	   	  |||||||_______Transmit buffer empty flag, TI
	   	  ||||||________Receive enable bit, RE
	  	  |||||_________Receive complete flag, RI
	   	  ||||__________Reserved, set to 0
	   	  |||___________Reserved, set to 0
	   	  ||____________Data logic select bit, U0LCH
	  	  |_____________Error signal output enable bit, U0ERE */
 

   // P6_0 is used as uVGA RTS# input

}


