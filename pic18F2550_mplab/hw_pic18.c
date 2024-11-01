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

    MCU:   PIC18F2550
    Crystal:  16MHz
    Operating frequency:  48 MHz
    UART Speed:     UART Mode
    Connection:
      MicroVGA.TXD = PIC18.RC6
      MicroVGA.RXD = PIC18.RC7
      MicroVGA.RTS = PIC18.RC2
      MicroVGA.CTS = PIC18.RC?
    _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/

#include <p18f2550.h>
//#include "../h/conio.h"

/** CONFIGURATION **************************************************/
#pragma config PLLDIV   = 4         // (20 MHz crystal on PICDEM FS USB board)
#pragma config CPUDIV   = OSC1_PLL2   
#pragma config USBDIV   = 2         // Clock source from 96MHz PLL/2
#pragma config FOSC     = HSPLL_HS
#pragma config FCMEN    = OFF		
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BOR      = ON
#pragma config BORV     = 3
#pragma config VREGEN   = ON      //USB Voltage Regulator
#pragma config WDT      = OFF
#pragma config WDTPS    = 32768
#pragma config MCLRE    = ON
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF
//      #pragma config CCP2MX   = ON
#pragma config STVREN   = ON
#pragma config LVP      = OFF
//      #pragma config ICPRT    = OFF       // Dedicated In-Circuit Debug/Programming
#pragma config XINST    = OFF       // Extended Instruction Set
#pragma config CP0      = OFF
#pragma config CP1      = OFF
//      #pragma config CP2      = OFF
//      #pragma config CP3      = OFF
#pragma config CPB      = OFF
//      #pragma config CPD      = OFF
#pragma config WRT0     = OFF
#pragma config WRT1     = OFF
//      #pragma config WRT2     = OFF
//      #pragma config WRT3     = OFF
#pragma config WRTB     = OFF       // Boot Block Write Protection
#pragma config WRTC     = OFF
//      #pragma config WRTD     = OFF
#pragma config EBTR0    = OFF
#pragma config EBTR1    = OFF
//      #pragma config EBTR2    = OFF
//      #pragma config EBTR3    = OFF
#pragma config EBTRB    = OFF

#define BAUDRATE 1000000

void _putch (char ch)
{ //write char to UART
		while (PORTCbits.RC2==1);
		
		while (TXSTAbits.TRMT==0);
		TXREG = ch;
		Nop();
		while (PIR1bits.TXIF==0);

		while (TXSTAbits.TRMT==0);
}

int _kbhit (void)
{ //return TRUE if keyboard was hit
   
	// If overrun and NO characters in queue, reset flag.
   if (RCSTAbits.OERR ==1 && PIR1bits.RCIF == 0) 
	{
     RCSTAbits.OERR = 0;
   }
   return PIR1bits.RCIF != 0;
}

int _getch (void)
{ //read char from UART
  int ch;

  // wait for key
  while (!_kbhit());
  ch = RCREG;
  PIR1bits.RCIF = 0;

  if (ch == 0) {
	  // wait for key
	  while (!_kbhit());
	  ch = 0x100 | RCREG;
	  PIR1bits.RCIF = 0;
  }
  return ch;
}


void MCU_Init()
{ //init PIC18F MCU and UART
  	unsigned char i,j;
	char dummy;

	RCSTA = 0; 
    TXSTA = 0;
    SPBRGH = 1;
    BAUDCON = 0;  

	TXSTAbits.SYNC = 0;
	RCSTAbits.SPEN = 1;                 // SPEN

	BAUDCONbits.BRG16 = 1;
	TXSTAbits.BRGH = 1;                 // brgh

	// Fop == 48 MHz
	// 16-bit/Asynchronous: baudrate = Fop/[4 (SPBRG + 1)] 
	// 						SPBRG = (Fop/( 4*baudrate))- 1 
	//						SPBRG = (12 000 000/BR)- 1 


	#if BAUDRATE==9600          //initialization for baudrate = 9600
		SPBRGH = 0x04;		// SPRG = 1249
	    SPBRG = 0xE1;
	#elif BAUDRATE==19200       //initialization for baudrate = 19200
		SPBRGH = 0x02;			// SPRG = 624
	    SPBRG = 0x71;
	#elif BAUDRATE==38400       //initialization for baudrate = 38400
		SPBRGH = 0x01;				// SPRG = 312	
	    SPBRG = 0x38;
	#elif BAUDRATE==57600       //initialization for baudrate = 57600
	    SPBRGH = 0;
	    SPBRG = 208;					// SPRG = 208
	#elif BAUDRATE==115200       //initialization for baudrate = 115200
	    SPBRGH = 0;
	    SPBRG = 103;
	#elif BAUDRATE==500000       //initialization for baudrate = 500000
		SPBRGH = 0;
	    SPBRG = 22;
	#elif BAUDRATE==1000000       //initialization for baudrate = 1000000
	    SPBRGH = 0;		
	    SPBRG = 11;
	#elif BAUDRATE==1250000       //initialization for baudrate = 1250000
	    SPBRGH = 0;		
	    SPBRG = 8;
	#endif


	TXSTAbits.TRMT = 0;  
	RCSTAbits.CREN = 1;           // Enable countinues recv    
	TXSTAbits.TXEN = 1;           // Enable transmitter
		  
	PIE1bits.RCIE = 0;            //Disable interrupt
	PIE1bits.TXIE = 0;            //Disable interrupt

	TRISCbits.TRISC6 = 0; // set RC6 (TX port)as output
	TRISCbits.TRISC2 = 1; // set RC2 (handshake pin for uVGA) as input

	
	//wait for UART to init
	for (i=0;i<255;i++)
		for(j=0;j<255;j++)
			dummy=i;

}