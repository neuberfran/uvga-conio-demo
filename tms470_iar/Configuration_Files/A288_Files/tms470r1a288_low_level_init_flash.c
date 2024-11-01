//**************************************************************************
//
// FILE:   __low_level_init
//
// TITLE:  TMS470R1x low level init for the A288.
//
// This function is called before the `main' function of the program.  Normally
// preforming the low-level initializations.
//
// Note: that this function is called before the data segments are
// initialized, this function cannot rely on the values of global or static variables.
//
// When this function returns zero, the startup code will inhibit the// initialization of the data segments.
// The result is faster startup, the drawback is that neither global nor static data will be
// initialized.
//
//**************************************************************************
//
//  Ver  | dd mmm yyyy | Who  | Description of changes
// ======|=============|======|==============================================
//  0.01 | 29 sept 2005 | J.M. | Original
//  0.02 | 20 oct 2005  | J.M. | Modified Mapping
//  0.03 |             |      |
//       |             |      |
//       |             |      |
//  Texas Instruments, Inc
//**************************************************************************

// ICODE is the same segment as cstartup. By placing __low_level_init
// in the same segment, we make sure it can be reached with BL.

#ifdef __cplusplus
extern "C" {
#endif

#pragma language=extended

#include <TexasInstruments/iotms470r1a288.h>
#include <TexasInstruments/tms470r1a256_bit_definitions.h>


#undef    PSTDBY_MAX
#undef    PSLEEP_MAX
#undef    BSTDBY_MAX
#undef    BSLEEP_MAX
#define   BSTDBY_MAX     ((unsigned int) 0x06 <<  2)    // 7:2    Bank standby (100nS at 60MHz)
#define   BSLEEP_MAX     ((unsigned int) 0x72 <<  8)    // 14:8   Bank sleep (1.9uS at 60MHz)
#define   PSTDBY_MAX     ((unsigned int) 0x3C <<  5)    // 15:5   Pump standby (1.0uS at 60MHz)
#define   PSLEEP_MAX     ((unsigned int) 0x78 <<  0)    // 14:1   Pump sleep (2.0uS at 60MHz)

#pragma location="ICODE"
int __low_level_init(void)
{
 // Temp2=(unsigned long int *)IRQV;
  // Disable peripheral access violation, memory access rights violation,
  // and illegal address reset
  SYSECR = RESET0 + PACCOVR + ACCOVR + ILLOVR;

  // Activate Flash at 0x00000000 that is connected to memory select 0,
  // set size to 288KB, enable read-only protection
  MFBAHR0 = 0x00000000;
  MFBALR0 |= BLOCK_SIZE_32K + RONLY;

   // De activate FLASH at 0x00000000 that is connected to memory select 1,
  // set size to 32KB

  MFBAHR1 = 0x00000004;
  MFBALR1 = BLOCK_SIZE_256K + RONLY;

  // Activate RAM at 0x00400000 that is connected to memory select 2,
  // set size to 64KB
  MFBAHR2 = 0x00000040;
  MFBALR2 = BLOCK_SIZE_16K;

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

  // Enable Flash configuration mode
  GCR |= FLCONFIG;

//  SET FLASH WAIT STATES
  FMMAC1 = PSLEEP_MAX;                               // pump sleep to standby time
  FMMAC2 = BANK0_ENA + PMPPWR_ACTIVE + PSTDBY_MAX;   // bank0
  FMBAC1 = BNKPWR_ACTIVE+ BSTDBY_MAX;                // active
  FMBAC2 = PIPELINE_MODE + BSLEEP_MAX;               // 0 wait states
  FMMAC2 = BANK1_ENA + PMPPWR_ACTIVE + PSTDBY_MAX;   // bank1
  FMBAC1 = BNKPWR_ACTIVE+ BSTDBY_MAX;                // active
  FMBAC2 = PIPELINE_MODE + BSLEEP_MAX;               // 0 wait states
  FMREGOPT = ENPIPE;                                 // ENABLE PIPELINE MODE
 GCR =  ZPLL_MULT4 + ZPLL_CLK_DIV_PRE_4;


  return 1; // Must return 1 to initialize C data.
}

#pragma language=default

#ifdef __cplusplus
}
#endif
