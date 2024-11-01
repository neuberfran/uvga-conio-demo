/*
    hw_pic24.c
    Microchip pic24 hardware low-level routines
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

    MCU:   PIC24HJ32GP202-I/SO
    Crystal:  internal frc
    Operating frequency:  40 MHz
    UART Speed:     1 Mbit
    Connection:
      MicroVGA.TXD = PIC24.RB14 (U1RX)
      MicroVGA.RXD = PIC24.RB15 (U1TX)
      MicroVGA.RTS = PIC24.RB12 (U1CTS)
      MicroVGA.CTS = PIC24.RB13 (U1RTS)

    _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/


#include "p24HJ32GP202.h"
#include "conio.h"
#include "kbd.h"

/*
_putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)

*/

void _putch (char ch)
{
  while (PORTBbits.RB12 == 1) ; // wait for RTS#
  while (U1STAbits.TRMT == 0) ;
  U1TXREG = ch;
  while (IFS0bits.U1TXIF == 0) ;
  IFS0bits.U1TXIF = 0;
}

int _getch (void)
{
  int ch;

  // wait for key
  while (!_kbhit());
  ch = U1RXREG;
  IFS0bits.U1RXIF = 0;

  if (ch == 0) {
	  // wait for key
	  while (!_kbhit());
	  ch = 0x100 | U1RXREG;
	  IFS0bits.U1RXIF = 0;
  }

  return ch;
}

int _kbhit (void)
{
  // If overrun and NO characters in queue, reset flag.
  if (U1STAbits.OERR ==1 && U1STAbits.URXDA == 0) {
     U1STAbits.OERR = 0;
  }

   return U1STAbits.URXDA != 0;
}

//Macros for Configuration Fuse Registers:
//Invoke macros to set up  device configuration fuse registers.
//The fuses will select the oscillator source, power-up timers, watch-dog
//timers etc. The macros are defined within the device
//header files. The configuration fuse registers reside in Flash memory.


// Internal FRC Oscillator
_FOSCSEL(FNOSC_FRC);		// FRC Oscillator 
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_NONE); 
// Clock Switching is enabled and Fail Safe Clock Monitor is disabled
// OSC2 Pin Function: OSC2 is Clock Output
// Primary Oscillator Mode: Disabled


_FWDT(FWDTEN_OFF);              // Watchdog Timer Enabled/disabled by user software

_FICD(ICS_PGD1 & JTAGEN_OFF & BKBUG_ON)



void initclock_frc(void)
{ 
	PLLFBD=39;					// M=40 (PLLFBD=39)
	CLKDIVbits.PLLPOST=0;		// N1=2
	CLKDIVbits.PLLPRE=0;		// N2=2
	OSCTUN=16;					// Tune FRC oscillator = 8MHz, OSCTUN=124
 
	// Disable Watch Dog Timer
	RCONbits.SWDTEN=0;

	// Clock switch to incorporate PLL
	__builtin_write_OSCCONH(0x01);		// Initiate Clock Switch to
	// FRC with PLL (NOSC=0b001)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	while (OSCCONbits.COSC != 0b001);	// Wait for Clock switch to occur



	while(OSCCONbits.LOCK!=1) {};
}


void config_per()
{

	//*************************************
	// Unlock Registers
	//*************************************
	asm volatile ( "mov #OSCCONL, w1 \n"
		"mov #0x46, w2 \n"
		"mov #0x57, w3 \n"
		"mov.b w2, [w1] \n"
		"mov.b w3, [w1] \n"
		"bclr OSCCON, #6");

	// Assign U1CTS To Pin RB12 (RTS on uVGA)
	RPINR18bits.U1CTSR = 12;  // bylo 13

	// Assign U1Rx To Pin RP14 / RB14
	RPINR18bits.U1RXR = 14;

	// Assign U1Tx to RB15
	RPOR7bits.RP15R = 3;

	// out U1RTS = RB13
	RPOR6bits.RP13R = 4;

	//*************************************
	// Lock Registers
	//*************************************
	asm volatile ( "mov #OSCCONL, w1 \n"
		"mov #0x46, w2 \n"
		"mov #0x57, w3 \n"
		"mov.b w2, [w1] \n"
		"mov.b w3, [w1] \n"
		"bset OSCCON, #6");
}


void InitUART1() {
	// This is an EXAMPLE, so brutal typing goes into explaining all bit sets

	// The HPC16 board has a DB9 connector wired to UART2, so we will
	// be configuring this port only

	// configure U1MODE
	U1MODEbits.UARTEN = 0;	// Bit15 TX, RX DISABLED, ENABLE at end of func
	//U1MODEbits.notimplemented;	// Bit14
	U1MODEbits.USIDL = 0;	// Bit13 Continue in Idle
	U1MODEbits.IREN = 0;	// Bit12 No IR translation
	U1MODEbits.RTSMD = 0;	// Bit11 Flow control mode!
	//U1MODEbits.notimplemented;	// Bit10
	U1MODEbits.UEN = 0b10;		// Bits8,9 TX,RX enabled, CTS,RTS also used & enabled
	U1MODEbits.WAKE = 0;	// Bit7 No Wake up (since we don't sleep here)
	U1MODEbits.LPBACK = 0;	// Bit6 No Loop Back
	U1MODEbits.ABAUD = 0;	// Bit5 No Autobaud (would require sending '55')
	U1MODEbits.URXINV = 0;	// Bit4 IdleState = 1  (for dsPIC)
	U1MODEbits.BRGH = 1;	// Bit3 16 clocks per bit period
	U1MODEbits.PDSEL = 0;	// Bits1,2 8bit, No Parity
	U1MODEbits.STSEL = 0;	// Bit0 One Stop Bit

	// Load a value into Baud Rate Generator.  Example is for 9600.
	// See section 19.3.1 of datasheet.
	//  U1BRG = (Fcy/(16*BaudRate))-1
	//  U1BRG = (37M/(16*9600))-1
	//  U1BRG = 240
//	U1BRG = ((40000000/38400)/4) -1; 	// 40Mhz osc, 38400 Baud
	U1BRG = ((40000000/1000000)/4)-1; 	// 40Mhz osc, 1M Baud

	// Load all values in for U1STA SFR
	U1STAbits.UTXISEL0 = 0;	//Bit13 Other half of Bit15
	U1STAbits.UTXISEL1 = 1;	//Bit15 Int when Char is transferred (1/2 config!)
	U1STAbits.UTXINV = 0;	//Bit14 N/A, IRDA config
	//U1STAbits.notimplemented = 0;	//Bit12
	U1STAbits.UTXBRK = 0;	//Bit11 Disabled
	U1STAbits.UTXEN = 0;	//Bit10 TX pins controlled by periph

	U1STAbits.URXISEL = 0;	//Bits6,7 Int. on character recieved
	U1STAbits.ADDEN = 0;	//Bit5 Address Detect Disabled
	U1STAbits.RIDLE = 0;	//Bit4 *Read Only Bit*
	U1STAbits.PERR = 0;		//Bit3 *Read Only Bit*
	U1STAbits.FERR = 0;		//Bit2 *Read Only Bit*
	U1STAbits.OERR = 0;		//Bit1 *Read Only Bit*
	U1STAbits.URXDA = 0;	//Bit0 *Read Only Bit*

	//IPC7 = 0x4400;	// Mid Range Interrupt Priority level, no urgent reason

	IPC3bits.U1TXIP2=0;//Set Uart TX Interrupt Priority
	IPC3bits.U1TXIP1=0;
	IPC3bits.U1TXIP0=0;

	IFS0bits.U1TXIF = 0;	// Clear the Transmit Interrupt Flag
	IEC0bits.U1TXIE = 0;//1;	// Enable Transmit Interrupts
	IFS0bits.U1RXIF = 0;	// Clear the Recieve Interrupt Flag
	IEC0bits.U1RXIE = 0;	// Enable Recieve Interrupts

	U1MODEbits.UARTEN = 1;	// And turn the peripheral on

	U1STAbits.UTXEN = 1;
	// I think I have the thing working now.

}


void MCU_Init(void)
{
 TRISA = 0xFFFF;

 AD1PCFGL = 0xFFFE;   // PCFG0=0 => RA0=Analog

 // RTS=>out
 TRISBbits.TRISB13 = 0; // configure out

 initclock_frc();
 config_per();
 InitUART1();

}

