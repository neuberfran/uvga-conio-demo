/*
    hw_lpc21xx.c
    NPX (Philips) lpc21xx hardware low-level routines
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

    MCU:   LPC21048
    Crystal:  16 MHz
    Operating frequency:  16 MHz (PPL is bypassed => CCLK==Fosc)
    UART Speed:     1 Mbit
    Connection:
      MicroVGA.TXD = LPC21048.RXD0 (P0_1)
      MicroVGA.RXD = LPC21048.TXD0 (P0_0)
      MicroVGA.RTS = LPC21048.P0_2
      MicroVGA.CTS = LPC21048.P0_3

    _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/

#include "ma_sfr.h"     /* Special function register bitfield macros */
#include "NXP/iolpc2104.h"  /* Defines Special function registers */
#include <intrinsics.h>

//UART defines
#define NO_PARITY_8D_1STOPBIT 0x03
#define DISABLE_FIFO 0
#define ENABLE_FIFO 1
#define U0LSR_ERR              (U0LSR_RXFE  |\
                               U0LSR_BI    |\
                               U0LSR_FE    |\
                               U0LSR_PE    |\
                               U0LSR_OE)      /* LSR Register Error Mask */

#define XTAL 16000000  //Fosc. Required for baudrate calculation

void Init_UART0( int baudrate ) 
/*
**      Initializes the UART0 module. Only sets those registers with 
**      values not equal to the power-on reset values.
**  Parameters:
**      baudrate      UART0 module baudrate
*/
{
    int uDLL;
    
    uDLL=(XTAL*10)/(16*baudrate);
    
    //correct rounding
    if (uDLL - ((uDLL / 10) * 10) < 5)
      uDLL=uDLL/10;
    else
      uDLL=uDLL/10+1;
    
    /*--- Disable interrupts ---*/
    U0IER = 0;              

    /*--- Initialize registers ---*/
    U0LCR = NO_PARITY_8D_1STOPBIT;
    
    /*----Set fifo----*/
    U0FCR    = ENABLE_FIFO;

    /*--- Initialize baudrate ---*/
    U0LCR_bit.DLAB = 1;    /* Open the divisor register access */    
    U0DLM = (uDLL>>8)&0xff;
    U0DLL = (uDLL)&0xff;

    U0LCR_bit.DLAB = 0;    /* Close the divisor register access */
    
}

signed char GetChar_UART0(unsigned char *pChar ) 
/*
**      Receive a character from the UART 0 channel. This function returns
**      immediately if a character cannot be received successfully.
**
**  Parameters:
**      pChar       A pointer to where the received character shall be saved.
**
**  Returns:
**      0           on success
**      1           if failed
*/
{

    unsigned char  Status;
 
    Status = U0LSR;

    /*--- Any characters received? ---*/
    if( Status & U0LSR_DR_VALID )
    {
        /*--- Detect potential errors ---*/
        if(( Status & U0LSR_ERR ) != 0 )
        {
            /*--- Parity, framing, overrun or break indication detected ---*/
            *pChar = U0RBR;

            return 1;
        }
        else
        {    
            /*--- Read the character ---*/
            *pChar = U0RBR;
        }
    }
    else /*--- UART0 is empty ---*/
        return 1;
    
    return 0;

}

void _putch (char ch) 
{
  // wait for FIFO to be empty
  while ((U0LSR_bit.TEMT) == 0); 
  
  //wait for uVGA to be ready get next data
  while ((IOPIN & IOPIN_P0_2) != 0);
        
  //Write character to transmit
  U0THR = ch;
}

int _getch (void)
{
  int ret;

   while (GetChar_UART0((unsigned char*)&ret)); //wait and read new char 
  
  if (ret==0)
  {
     while (GetChar_UART0((unsigned char*)&ret)); //wait and read new char
     
     ret|=0x100;
  }

  return ret;
}

int _kbhit (void)
{ 
  return (U0LSR & U0LSR_DR_VALID);
}

#define MA_MAMCR_SCB           0x00000000  /* MAM Control Register */
#define MA_MAMCR_SCB_MASK      0x00000003  /* Used bits */
#define MA_MAMTIM_SCB          0x00000007  /* MAM Timing Control Register */
#define MA_MAMTIM_SCB_MASK     0x00000007  /* Used bits */
#define MA_MEMMAP_SCB          0x00000001  /* Memory Mapping Control Register */
#define MA_MEMMAP_SCB_MASK     0x00000003  /* Used bits */
#define MA_PLLCON_SCB          0x00000000  /* PLL Control Register */
#define MA_PLLCON_SCB_MASK     0x00000003  /* Used bits */
#define MA_PLLCFG_SCB          0x00000000  /* PLL Configuration Register */
#define MA_PLLCFG_SCB_MASK     0x0000007F  /* Used bits */
#define MA_PLLFEED_SCB         0x00000000  /* PLL Feed Register */
#define MA_PLLFEED_SCB_MASK    0x000000FF  /* Used bits */
#define MA_PCON_SCB            0x00000000  /* Power Control Register */
#define MA_PCON_SCB_MASK       0x00000003  /* Used bits */
#define MA_PCONP_SCB           0x000003BE  /* Power Control for Peripherals Register */
#define MA_PCONP_SCB_MASK      0x000003BE  /* Used bits */
#define MA_VPBDIV_SCB          0x00000000  /* VPB Divider Register */
#define MA_VPBDIV_SCB_MASK     0x00000003  /* Used bits */
#define MA_EXTINT_SCB          0x00000000  /* External Interrupt Flag Register */
#define MA_EXTINT_SCB_MASK     0x00000007  /* Used bits */
#define MA_EXTWAKE_SCB         0x00000000  /* External Interrupt Wakeup Register */
#define MA_EXTWAKE_SCB_MASK    0x00000007  /* Used bits */


#define APB_NO_DIV 0x01
#define MA_PINSEL0_PCB         0x00855505  /* Pin Function Select Register 0 */

void MCU_Init(void)
{
    /*SCB == System control block*/
    /*--- Reset SCB registers ---*/     
    /*PPL is bypassed => CCLK==Fosc*/
    MAMCR    = ( MAMCR & ~MA_MAMCR_SCB_MASK ) | MA_MAMCR_SCB;
    MAMTIM   = ( MAMTIM & ~MA_MAMTIM_SCB_MASK ) | MA_MAMTIM_SCB;
    MEMMAP   = ( MEMMAP & ~MA_MEMMAP_SCB_MASK ) | MA_MEMMAP_SCB;
    PLLCON   = ( PLLCON & ~MA_PLLCON_SCB_MASK ) | MA_PLLCON_SCB;
    PLLCFG   = ( PLLCFG & ~MA_PLLCFG_SCB_MASK ) | MA_PLLCFG_SCB;
    PLLFEED  = ( PLLFEED & ~MA_PLLFEED_SCB_MASK ) | MA_PLLFEED_SCB;
    PCON     = ( PCON & ~MA_PCON_SCB_MASK ) | MA_PCON_SCB;
    PCONP    = ( PCONP & ~MA_PCONP_SCB_MASK ) | MA_PCONP_SCB;
    VPBDIV   = ( VPBDIV & ~MA_VPBDIV_SCB_MASK ) | MA_VPBDIV_SCB;
    EXTINT   = ( EXTINT & ~MA_EXTINT_SCB_MASK ) | MA_EXTINT_SCB;
    EXTWAKE  = ( EXTWAKE & ~MA_EXTWAKE_SCB_MASK ) | MA_EXTWAKE_SCB;
    
    APBDIV = APB_NO_DIV;

    
    /*--- Reset PCB registers ---*/     
    PINSEL0  = MA_PINSEL0_PCB;
    PINSEL1  = 0;    
  
   //GPIO settings for handshaking
    /*--- Reset IODIR register ---*/     
    IODIR    = 0xF0000400;
    
    /*--- Set direction to input ---*/
    IODIR &= ~IOPIN_P0_2;    
    
    /*--- Set direction to output ---*/
    IODIR |= IOPIN_P0_3;
	
    Init_UART0(1000000);
}