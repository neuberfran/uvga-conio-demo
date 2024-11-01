/*
    hw_atmega.c
    Atmel ATMega128/ATMega103 hardware low-level routines
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

    MCU:   ATMega128/ATMega103
    Internal osc:  1 MHz
    Operating frequency:  1 MHz
    UART Speed:     57600 kbit
    Connection:
      MicroVGA.TXD = ATMega128.RCD0 (RXD)
      MicroVGA.RXD = ATMega128.TXD0 (TXD)
      MicroVGA.CTS = ATMega128.PB7 (GPIO configuration)
	
	Defines are used to provide code compatibility between one UART and 
	two UART atmel devices.

   _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/

#include <avr/io.h>
#include <avr/wdt.h>

char Get_Put_Char(int ch)
{

//Putchar -- Master
/* Start transmission */
SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
/* Return data register */
return SPDR;
}

void MCU_Init(void)
{ //http://www.atmel.com/dyn/resources/prod_documents/doc2467.pdf  page:165

//Master init
/* Set MOSI and SCK output, all others input */
DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
/* Enable SPI, Master, set clock rate fck/16 */
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

/*
Slave init
// Set MISO output, all others input 
DDR_SPI = (1<<DD_MISO);
// Enable SPI 
SPCR = (1<<SPE);
*/

}
