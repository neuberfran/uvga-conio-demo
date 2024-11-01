/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2008
 *
 *    File name   : main.c
 *    Description : Main module
 *
 *    History :
 *    1. Date        : 17, April 2008
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *   This example project shows how to use the IAR Embedded Workbench
 *  for ARM to develop code for the Olimex SAM7-nRF24 board.
 *   It implements wireless point to point USB CDC (Communication Device Class)
 *  device and install it like a Virtual COM port.
 *   The connection realize between device with Node A configuration and
 *  Node B configuration.
 *
 *    $Revision: 22764 $
 **************************************************************************/



/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */


//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

 #include "AT91SAM7S64.h"


//------------------------------------------------------------------------------
// Clocks
//------------------------------------------------------------------------------
/// Frequency of the board main oscillator, in Hz.
#define BOARD_MAINOSC           18432000

/// Master clock frequency (when using board_lowlevel.c), in Hz.
#define BOARD_MCK               48000000
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//         Internal definitions
//------------------------------------------------------------------------------
// Startup time of main oscillator (in number of slow clock ticks).
#define BOARD_OSCOUNT           (AT91C_CKGR_OSCOUNT & (0x40 << 8))

// USB PLL divisor value to obtain a 48MHz clock.
#define BOARD_USBDIV            AT91C_CKGR_USBDIV_1

// PLL frequency range.
#define BOARD_CKGR_PLL          AT91C_CKGR_OUT_0

// PLL startup time (in number of slow clock ticks).
#define BOARD_PLLCOUNT          (16 << 8)

// PLL MUL value.
#define BOARD_MUL               (AT91C_CKGR_MUL & (72 << 16))

// PLL DIV value.
#define BOARD_DIV               (AT91C_CKGR_DIV & 14)

// Master clock prescaler value.
#define BOARD_PRESCALER         AT91C_PMC_PRES_CLK_2

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Default spurious interrupt handler. Infinite loop.
//------------------------------------------------------------------------------
void defaultSpuriousHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for fast interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultFiqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for standard interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultIrqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Performs the low-level initialization of the chip. This includes EFC, master
/// clock, AIC & watchdog configuration, as well as memory remapping.
//------------------------------------------------------------------------------
void LowLevelInit(void)
{
    unsigned char i;

    // Set flash wait states in the EFC
    // 48MHz = 1 wait state
    AT91C_BASE_MC->MC_FMR = AT91C_MC_FWS_1FWS;

    // Initialize main oscillator
    AT91C_BASE_PMC->PMC_MOR = BOARD_OSCOUNT | AT91C_CKGR_MOSCEN;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCS));

    // Initialize PLL at 96MHz (96.109) and USB clock to 48MHz
    AT91C_BASE_PMC->PMC_PLLR = BOARD_USBDIV | BOARD_CKGR_PLL | BOARD_PLLCOUNT
                               | BOARD_MUL | BOARD_DIV;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCK));

    // Wait for the master clock if it was already initialized
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    // Switch to slow clock + prescaler
    AT91C_BASE_PMC->PMC_MCKR = BOARD_PRESCALER;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    // Switch to fast clock + prescaler
    AT91C_BASE_PMC->PMC_MCKR |= AT91C_PMC_CSS_PLL_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    // Initialize AIC
    AT91C_BASE_AIC->AIC_IDCR = 0xFFFFFFFF;
    AT91C_BASE_AIC->AIC_SVR[0] = (unsigned int) defaultFiqHandler;
    for (i = 1; i < 31; i++) {

        AT91C_BASE_AIC->AIC_SVR[i] = (unsigned int) defaultIrqHandler;
    }
    AT91C_BASE_AIC->AIC_SPU = (unsigned int) defaultSpuriousHandler;

    // Unstack nested interrupts
    for (i = 0; i < 8 ; i++) {

        AT91C_BASE_AIC->AIC_EOICR = 0;
    }

    // Enable Debug mode
    AT91C_BASE_AIC->AIC_DCR = AT91C_AIC_DCR_PROT;

    // Watchdog initialization
    AT91C_BASE_WDTC->WDTC_WDMR = AT91C_WDTC_WDDIS;

    // Remap the internal SRAM at 0x0
    
    // Disable RTT and PIT interrupts (potential problem when program A
    // configures RTT, then program B wants to use PIT only, interrupts
    // from the RTT will still occur since they both use AT91C_ID_SYS)
    AT91C_BASE_RTTC->RTTC_RTMR &= ~(AT91C_RTTC_ALMIEN | AT91C_RTTC_RTTINCIEN);
    AT91C_BASE_PITC->PITC_PIMR &= ~AT91C_PITC_PITIEN;
}



/*
_putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)

*/

void _putch (char ch)
{
    while ((AT91C_BASE_PIOA->PIO_PDSR & (1<<0)) != 0); // wait for uvga to become ready for next byte
    AT91C_BASE_DBGU->DBGU_THR = ch;
    while(!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXRDY));  // Wait for empty transmit buffer
} 

int _kbhit (void)

{
   return   AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_RXRDY;
}

int _getch (void)
{
  int ch;

  // wait for key
  while (!_kbhit());
  ch = AT91C_BASE_DBGU->DBGU_RHR;
  
  if (ch == 0) {
	  // wait for key
	  while (!_kbhit());
	  ch = 0x100 | AT91C_BASE_DBGU->DBGU_RHR;
  }

  return ch; 
}

void MCU_Init(void)
{
  
  LowLevelInit();

    // Reset & disable receiver and transmitter, disable interrupts
    AT91C_BASE_DBGU->DBGU_CR = AT91C_US_RSTRX | AT91C_US_RSTTX;
    
  /* Disable interrupts */   
     AT91C_BASE_DBGU->DBGU_IDR = 0xFFFFFFFF;   
    
     /* Configure PIOs for DBGU */   
     AT91C_BASE_PIOA->PIO_ASR = AT91C_PA9_DRXD | AT91C_PA10_DTXD;   
     AT91C_BASE_PIOA->PIO_BSR = 0;   
     AT91C_BASE_PIOA->PIO_PDR = AT91C_PA9_DRXD | AT91C_PA10_DTXD;   

    // Configure baud rate
    AT91C_BASE_DBGU->DBGU_BRGR = BOARD_MCK / (1000000 * 16);
    
    // Configure mode register
    AT91C_BASE_DBGU->DBGU_MR = AT91C_US_PAR_NONE| AT91C_US_CHMODE_NORMAL;
    
    // Disable DMA channel
    AT91C_BASE_DBGU->DBGU_PTCR = AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;

    // Enable receiver and transmitter
    AT91C_BASE_DBGU->DBGU_CR = AT91C_US_RXEN | AT91C_US_TXEN;
       
       
   // Setup PIO
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_PIOA;  // Enable clock to PIO
    
//    AT91C_BASE_PIOA->PIO_OER = LED_MASK;    // Output on PA0-PA3
//    AT91C_BASE_PIOA->PIO_OWER = LED_MASK;   // Enable to set/clear PA0-PA3 with status register
    
    // pa15 - microvga CS
    AT91C_BASE_PIOA->PIO_PER = 1 << 15; // Set PA15 - the EEPROM ~enable - in PIO mode
    AT91C_BASE_PIOA->PIO_OER = 1 << 15; // Configure in Output
    AT91C_BASE_PIOA->PIO_CODR = 1 << 15; // Set Output lo

    // pa0(OUT) - microvga cts(IN)
    AT91C_BASE_PIOA->PIO_PER = 1 << 1; // Set PA0 
    AT91C_BASE_PIOA->PIO_OER = 1 << 1; // Configure Output
    AT91C_BASE_PIOA->PIO_CODR = 1 << 1; // Set Output lo
    
    // pa1(IN) - microvga rts(OUT)
    AT91C_BASE_PIOA->PIO_PER = 1 << 0; // Set PA0 
    AT91C_BASE_PIOA->PIO_ODR = 1 << 0; // Configure input
}
