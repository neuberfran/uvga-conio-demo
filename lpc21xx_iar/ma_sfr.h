/*--- Avoid including this file more than once ---*/
#ifndef MA_SFR_DEFINED
#define MA_SFR_DEFINED

/*--- Include the target specific header file ---*/
//#include "ma_tgt.h"


#ifndef MA_UNSIGNED_CHAR
#define MA_UNSIGNED_CHAR		*(volatile unsigned char  *)
#endif
#ifndef MA_UNSIGNED_SHORT
#define MA_UNSIGNED_SHORT		*(volatile unsigned short *)
#endif
#ifndef MA_UNSIGNED_LONG
#define MA_UNSIGNED_LONG		*(volatile unsigned long  *)
#endif

/*
**---------------------------------------------------------------------------
**  Watchdog Mode Register
**---------------------------------------------------------------------------
*/

#define WDMOD_WDINT                0x08   /* Bit 3: WDINT (Watchdog interrupt flag (Read Only)) */
#define WDMOD_WDINT_NO_INTERRUPT   0x00   /* No interrupt */
#define WDMOD_WDINT_INTERRUPT      0x01   /* Interrupt */

#define WDMOD_WDTOF                0x04   /* Bit 2: WDTOF (Watchdog time-out flag) */
#define WDMOD_WDTOF_NO_TIME_OUT    0x00   /* No time-out */
#define WDMOD_WDTOF_TIME_OUT       0x01   /* Time-out */

#define WDMOD_WDRESET              0x02   /* Bit 1: WDRESET (Watchdog reset enable bit (Set Only)) */
#define WDMOD_WDRESET_INTERRUPT    0x00   /* Disabled */
#define WDMOD_WDRESET_WDRESET      0x01   /* Enabled */

#define WDMOD_WDEN                 0x01   /* Bit 0: WDEN (Watchdog interrupt enable bit (Set only)) */
#define WDMOD_WDEN_STOPPED         0x00   /* Disabled */
#define WDMOD_WDEN_RUNNING         0x01   /* Enabled (Watchdog interrupt enabled) */


/*
**---------------------------------------------------------------------------
**  Watchdog Timer Constant Register
**---------------------------------------------------------------------------
*/

#define WDTC_COUNT                 0xffffffff /* Bit 31-0: COUNT (Watchdog time-out interval) */


/*
**---------------------------------------------------------------------------
**  Watchdog Feed Sequence Register
**---------------------------------------------------------------------------
*/

#define WDFEED_FEED                0xff   /* Bit 7-0: FEED (Watchdog feed) */


/*
**---------------------------------------------------------------------------
**  Watchdog Timer Value Register
**---------------------------------------------------------------------------
*/

#define WDTV_COUNT                 0xffffffff /* Bit 31-0: COUNT (Watchdog time-out interval) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Interrupt Register
**---------------------------------------------------------------------------
*/

#define T0IR_CR2INT                0x40   /* Bit 6: CR2INT (Interrupt flag for capture channel 2) */
#define T0IR_CR2INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T0IR_CR2INT_INTERRUPT      0x01   /* Interrupt */

#define T0IR_CR1INT                0x20   /* Bit 5: CR1INT (Interrupt flag for capture channel 1) */
#define T0IR_CR1INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T0IR_CR1INT_INTERRUPT      0x01   /* Interrupt */

#define T0IR_CR0INT                0x10   /* Bit 4: CR0INT (Interrupt flag for capture channel 0) */
#define T0IR_CR0INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T0IR_CR0INT_INTERRUPT      0x01   /* Interrupt */

#define T0IR_MR3INT                0x08   /* Bit 3: MR3INT (Interrupt flag for match channel 3) */
#define T0IR_MR3INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T0IR_MR3INT_INTERRUPT      0x01   /* Interrupt */

#define T0IR_MR2INT                0x04   /* Bit 2: MR2INT (Interrupt flag for match channel 2) */
#define T0IR_MR2INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T0IR_MR2INT_INTERRUPT      0x01   /* Interrupt */

#define T0IR_MR1INT                0x02   /* Bit 1: MR1INT (Interrupt flag for match channel 1) */
#define T0IR_MR1INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T0IR_MR1INT_INTERRUPT      0x01   /* Interrupt */

#define T0IR_MR0INT                0x01   /* Bit 0: MR0INT (Interrupt flag for match channel 0) */
#define T0IR_MR0INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T0IR_MR0INT_INTERRUPT      0x01   /* Interrupt */


/*
**---------------------------------------------------------------------------
**  Timer 0 Timer Control Register
**---------------------------------------------------------------------------
*/

#define T0TCR_CR                   0x02   /* Bit 1: CR (Counter reset) */
#define T0TCR_CR_NO_RESET          0x00   /* No reset */
#define T0TCR_CR_RESET             0x01   /* Generate reset */

#define T0TCR_CE                   0x01   /* Bit 0: CE (Counter enable) */
#define T0TCR_CE_DISABLED          0x00   /* Disabled */
#define T0TCR_CE_ENABLED           0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Timer 0 Timer Counter
**---------------------------------------------------------------------------
*/

#define T0TC_VALUE                 0xffffffff /* Bit 31-0: VALUE (Timer counter value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Prescale Register
**---------------------------------------------------------------------------
*/

#define T0PR_VALUE                 0xffffffff /* Bit 31-0: VALUE (Timer prescaler max value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Prescale Counter
**---------------------------------------------------------------------------
*/

#define T0PC_VALUE                 0xffffffff /* Bit 31-0: VALUE (Timer prescale counter value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Match Control Register
**---------------------------------------------------------------------------
*/

#define T0MCR_MR3STOP              0x800  /* Bit 11: MR3STOP (Stop on MR3) */
#define T0MCR_MR3STOP_DISABLED     0x00   /* Disabled */
#define T0MCR_MR3STOP_ENABLED      0x01   /* Enabled */

#define T0MCR_MR3RES               0x400  /* Bit 10: MR3RES (Reset on MR3) */
#define T0MCR_MR3RES_DISABLED      0x00   /* Disabled */
#define T0MCR_MR3RES_ENABLED       0x01   /* Enabled */

#define T0MCR_MR3INT               0x200  /* Bit 9: MR3INT (Interrupt on MR3) */
#define T0MCR_MR3INT_DISABLED      0x00   /* Disabled */
#define T0MCR_MR3INT_ENABLED       0x01   /* Enabled */

#define T0MCR_MR2STOP              0x100  /* Bit 8: MR2STOP (Stop on MR2) */
#define T0MCR_MR2STOP_DISABLED     0x00   /* Disabled */
#define T0MCR_MR2STOP_ENABLED      0x01   /* Enabled */

#define T0MCR_MR2RES               0x80   /* Bit 7: MR2RES (Reset on MR2) */
#define T0MCR_MR2RES_DISABLED      0x00   /* Disabled */
#define T0MCR_MR2RES_ENABLED       0x01   /* Enabled */

#define T0MCR_MR2INT               0x40   /* Bit 6: MR2INT (Interrupt on MR2) */
#define T0MCR_MR2INT_DISABLED      0x00   /* Disabled */
#define T0MCR_MR2INT_ENABLED       0x01   /* Enabled */

#define T0MCR_MR1STOP              0x20   /* Bit 5: MR1STOP (Stop on MR1) */
#define T0MCR_MR1STOP_DISABLED     0x00   /* Disabled */
#define T0MCR_MR1STOP_ENABLED      0x01   /* Enabled */

#define T0MCR_MR1RES               0x10   /* Bit 4: MR1RES (Reset on MR1) */
#define T0MCR_MR1RES_DISABLED      0x00   /* Disabled */
#define T0MCR_MR1RES_ENABLED       0x01   /* Enabled */

#define T0MCR_MR1INT               0x08   /* Bit 3: MR1INT (Interrupt on MR1) */
#define T0MCR_MR1INT_DISABLED      0x00   /* Disabled */
#define T0MCR_MR1INT_ENABLED       0x01   /* Enabled */

#define T0MCR_MR0STOP              0x04   /* Bit 2: MR0STOP (Stop on MR0) */
#define T0MCR_MR0STOP_DISABLED     0x00   /* Disabled */
#define T0MCR_MR0STOP_ENABLED      0x01   /* Enabled */

#define T0MCR_MR0RES               0x02   /* Bit 1: MR0RES (Reset on MR0) */
#define T0MCR_MR0RES_DISABLED      0x00   /* Disabled */
#define T0MCR_MR0RES_ENABLED       0x01   /* Enabled */

#define T0MCR_MR0INT               0x01   /* Bit 0: MR0INT (Interrupt on MR0) */
#define T0MCR_MR0INT_DISABLED      0x00   /* Disabled */
#define T0MCR_MR0INT_ENABLED       0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Timer 0 Match Register 0
**---------------------------------------------------------------------------
*/

#define T0MR0_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Match Register 1
**---------------------------------------------------------------------------
*/

#define T0MR1_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Match Register 2
**---------------------------------------------------------------------------
*/

#define T0MR2_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Match Register 3
**---------------------------------------------------------------------------
*/

#define T0MR3_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Capture Control Register
**---------------------------------------------------------------------------
*/

#define T0CCR_CAP2INT              0x100  /* Bit 8: CAP2INT (Interrupt on capture CAP2) */
#define T0CCR_CAP2INT_DISABLED     0x00   /* Disabled */
#define T0CCR_CAP2INT_ENABLED      0x01   /* Enabled */

#define T0CCR_CAP2FE               0x80   /* Bit 7: CAP2FE (Capture on CAP2 falling edge) */
#define T0CCR_CAP2FE_DISABLED      0x00   /* Disabled */
#define T0CCR_CAP2FE_ENABLED       0x01   /* Enabled */

#define T0CCR_CAP2RE               0x40   /* Bit 6: CAP2RE (Capture on CAP2 rising edge) */
#define T0CCR_CAP2RE_DISABLED      0x00   /* Disabled */
#define T0CCR_CAP2RE_ENABLED       0x01   /* Enabled */

#define T0CCR_CAP1INT              0x20   /* Bit 5: CAP1INT (Interrupt on capture CAP1) */
#define T0CCR_CAP1INT_DISABLED     0x00   /* Disabled */
#define T0CCR_CAP1INT_ENABLED      0x01   /* Enabled */

#define T0CCR_CAP1FE               0x10   /* Bit 4: CAP1FE (Capture on CAP1 falling edge) */
#define T0CCR_CAP1FE_DISABLED      0x00   /* Disabled */
#define T0CCR_CAP1FE_ENABLED       0x01   /* Enabled */

#define T0CCR_CAP1RE               0x08   /* Bit 3: CAP1RE (Capture on CAP1 rising edge) */
#define T0CCR_CAP1RE_DISABLED      0x00   /* Disabled */
#define T0CCR_CAP1RE_ENABLED       0x01   /* Enabled */

#define T0CCR_CAP0INT              0x04   /* Bit 2: CAP0INT (Interrupt on capture CAP0) */
#define T0CCR_CAP0INT_DISABLED     0x00   /* Disabled */
#define T0CCR_CAP0INT_ENABLED      0x01   /* Enabled */

#define T0CCR_CAP0FE               0x02   /* Bit 1: CAP0FE (Capture on CAP0 falling edge) */
#define T0CCR_CAP0FE_DISABLED      0x00   /* Disabled */
#define T0CCR_CAP0FE_ENABLED       0x01   /* Enabled */

#define T0CCR_CAP0RE               0x01   /* Bit 0: CAP0RE (Capture on CAP0 rising edge) */
#define T0CCR_CAP0RE_DISABLED      0x00   /* Disabled */
#define T0CCR_CAP0RE_ENABLED       0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Timer 0 Capture Register 0
**---------------------------------------------------------------------------
*/

#define T0CR0_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Capture Register 1
**---------------------------------------------------------------------------
*/

#define T0CR1_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Capture Register 2
**---------------------------------------------------------------------------
*/

#define T0CR2_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 Capture Register 3
**---------------------------------------------------------------------------
*/

#define T0CR3_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 0 External Match Register
**---------------------------------------------------------------------------
*/

#define T0EMR_EMC2                 0x300  /* Bit 9-8: EMC2 (External match control 2) */
#define T0EMR_EMC2_NOTHING         0x00   /* Do nothing */
#define T0EMR_EMC2_CLEAR           0x01   /* Clear output to 0 */
#define T0EMR_EMC2_SET             0x02   /* Set output to 1 */
#define T0EMR_EMC2_TOGGLE          0x03   /* Toggle output */

#define T0EMR_EMC1                 0xc0   /* Bit 7-6: EMC1 (External match control 1) */
#define T0EMR_EMC1_NOTHING         0x00   /* Do nothing */
#define T0EMR_EMC1_CLEAR           0x01   /* Clear output to 0 */
#define T0EMR_EMC1_SET             0x02   /* Set output to 1 */
#define T0EMR_EMC1_TOGGLE          0x03   /* Toggle output */

#define T0EMR_EMC0                 0x30   /* Bit 5-4: EMC0 (External match control 0) */
#define T0EMR_EMC0_NOTHING         0x00   /* Do nothing */
#define T0EMR_EMC0_CLEAR           0x01   /* Clear output to 0 */
#define T0EMR_EMC0_SET             0x02   /* Set output to 1 */
#define T0EMR_EMC0_TOGGLE          0x03   /* Toggle output */

#define T0EMR_EM2                  0x04   /* Bit 2: EM2 (External match 2) */
#define T0EMR_EM2_LOW              0x00   /* Low */
#define T0EMR_EM2_HIGH             0x01   /* High */

#define T0EMR_EM1                  0x02   /* Bit 1: EM1 (External match 1) */
#define T0EMR_EM1_LOW              0x00   /* Low */
#define T0EMR_EM1_HIGH             0x01   /* High */

#define T0EMR_EM0                  0x01   /* Bit 0: EM0 (External match 0) */
#define T0EMR_EM0_LOW              0x00   /* Low */
#define T0EMR_EM0_HIGH             0x01   /* High */


/*
**---------------------------------------------------------------------------
**  Timer 1 Interrupt Register
**---------------------------------------------------------------------------
*/

#define T1IR_CR3INT                0x80   /* Bit 7: CR3INT (Interrupt flag for capture channel 3) */
#define T1IR_CR3INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_CR3INT_INTERRUPT      0x01   /* Interrupt */

#define T1IR_CR2INT                0x40   /* Bit 6: CR2INT (Interrupt flag for capture channel 2) */
#define T1IR_CR2INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_CR2INT_INTERRUPT      0x01   /* Interrupt */

#define T1IR_CR1INT                0x20   /* Bit 5: CR1INT (Interrupt flag for capture channel 1) */
#define T1IR_CR1INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_CR1INT_INTERRUPT      0x01   /* Interrupt */

#define T1IR_CR0INT                0x10   /* Bit 4: CR0INT (Interrupt flag for capture channel 0) */
#define T1IR_CR0INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_CR0INT_INTERRUPT      0x01   /* Interrupt */

#define T1IR_MR3INT                0x08   /* Bit 3: MR3INT (Interrupt flag for match channel 3) */
#define T1IR_MR3INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_MR3INT_INTERRUPT      0x01   /* Interrupt */

#define T1IR_MR2INT                0x04   /* Bit 2: MR2INT (Interrupt flag for match channel 2) */
#define T1IR_MR2INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_MR2INT_INTERRUPT      0x01   /* Interrupt */

#define T1IR_MR1INT                0x02   /* Bit 1: MR1INT (Interrupt flag for match channel 1) */
#define T1IR_MR1INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_MR1INT_INTERRUPT      0x01   /* Interrupt */

#define T1IR_MR0INT                0x01   /* Bit 0: MR0INT (Interrupt flag for match channel 0) */
#define T1IR_MR0INT_NO_INTERRUPT   0x00   /* No interrupt */
#define T1IR_MR0INT_INTERRUPT      0x01   /* Interrupt */


/*
**---------------------------------------------------------------------------
**  Timer 1 Timer Control Register
**---------------------------------------------------------------------------
*/

#define T1TCR_CR                   0x02   /* Bit 1: CR (Counter reset) */
#define T1TCR_CR_NO_RESET          0x00   /* No reset */
#define T1TCR_CR_RESET             0x01   /* Generate reset */

#define T1TCR_CE                   0x01   /* Bit 0: CE (Counter enable) */
#define T1TCR_CE_DISABLED          0x00   /* Disabled */
#define T1TCR_CE_ENABLED           0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Timer 1 Timer Counter
**---------------------------------------------------------------------------
*/

#define T1TC_VALUE                 0xffffffff /* Bit 31-0: VALUE (Timer counter value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Prescale Register
**---------------------------------------------------------------------------
*/

#define T1PR_VALUE                 0xffffffff /* Bit 31-0: VALUE (Timer prescaler max value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Prescale Counter
**---------------------------------------------------------------------------
*/

#define T1PC_VALUE                 0xffffffff /* Bit 31-0: VALUE (Timer prescale counter value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Match Control Register
**---------------------------------------------------------------------------
*/

#define T1MCR_MR3STOP              0x800  /* Bit 11: MR3STOP (Stop on MR3) */
#define T1MCR_MR3STOP_DISABLED     0x00   /* Disabled */
#define T1MCR_MR3STOP_ENABLED      0x01   /* Enabled */

#define T1MCR_MR3RES               0x400  /* Bit 10: MR3RES (Reset on MR3) */
#define T1MCR_MR3RES_DISABLED      0x00   /* Disabled */
#define T1MCR_MR3RES_ENABLED       0x01   /* Enabled */

#define T1MCR_MR3INT               0x200  /* Bit 9: MR3INT (Interrupt on MR3) */
#define T1MCR_MR3INT_DISABLED      0x00   /* Disabled */
#define T1MCR_MR3INT_ENABLED       0x01   /* Enabled */

#define T1MCR_MR2STOP              0x100  /* Bit 8: MR2STOP (Stop on MR2) */
#define T1MCR_MR2STOP_DISABLED     0x00   /* Disabled */
#define T1MCR_MR2STOP_ENABLED      0x01   /* Enabled */

#define T1MCR_MR2RES               0x80   /* Bit 7: MR2RES (Reset on MR2) */
#define T1MCR_MR2RES_DISABLED      0x00   /* Disabled */
#define T1MCR_MR2RES_ENABLED       0x01   /* Enabled */

#define T1MCR_MR2INT               0x40   /* Bit 6: MR2INT (Interrupt on MR2) */
#define T1MCR_MR2INT_DISABLED      0x00   /* Disabled */
#define T1MCR_MR2INT_ENABLED       0x01   /* Enabled */

#define T1MCR_MR1STOP              0x20   /* Bit 5: MR1STOP (Stop on MR1) */
#define T1MCR_MR1STOP_DISABLED     0x00   /* Disabled */
#define T1MCR_MR1STOP_ENABLED      0x01   /* Enabled */

#define T1MCR_MR1RES               0x10   /* Bit 4: MR1RES (Reset on MR1) */
#define T1MCR_MR1RES_DISABLED      0x00   /* Disabled */
#define T1MCR_MR1RES_ENABLED       0x01   /* Enabled */

#define T1MCR_MR1INT               0x08   /* Bit 3: MR1INT (Interrupt on MR1) */
#define T1MCR_MR1INT_DISABLED      0x00   /* Disabled */
#define T1MCR_MR1INT_ENABLED       0x01   /* Enabled */

#define T1MCR_MR0STOP              0x04   /* Bit 2: MR0STOP (Stop on MR0) */
#define T1MCR_MR0STOP_DISABLED     0x00   /* Disabled */
#define T1MCR_MR0STOP_ENABLED      0x01   /* Enabled */

#define T1MCR_MR0RES               0x02   /* Bit 1: MR0RES (Reset on MR0) */
#define T1MCR_MR0RES_DISABLED      0x00   /* Disabled */
#define T1MCR_MR0RES_ENABLED       0x01   /* Enabled */

#define T1MCR_MR0INT               0x01   /* Bit 0: MR0INT (Interrupt on MR0) */
#define T1MCR_MR0INT_DISABLED      0x00   /* Disabled */
#define T1MCR_MR0INT_ENABLED       0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Timer 1 Match Register 0
**---------------------------------------------------------------------------
*/

#define T1MR0_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Match Register 1
**---------------------------------------------------------------------------
*/

#define T1MR1_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Match Register 2
**---------------------------------------------------------------------------
*/

#define T1MR2_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Match Register 3
**---------------------------------------------------------------------------
*/

#define T1MR3_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer match value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Capture Control Register
**---------------------------------------------------------------------------
*/

#define T1CCR_CAP3INT              0x800  /* Bit 11: CAP3INT (Interrupt on capture CAP3) */
#define T1CCR_CAP3INT_DISABLED     0x00   /* Disabled */
#define T1CCR_CAP3INT_ENABLED      0x01   /* Enabled */

#define T1CCR_CAP3FE               0x400  /* Bit 10: CAP3FE (Capture on CAP3 falling edge) */
#define T1CCR_CAP3FE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP3FE_ENABLED       0x01   /* Enabled */

#define T1CCR_CAP3RE               0x200  /* Bit 9: CAP3RE (Capture on CAP3 rising edge) */
#define T1CCR_CAP3RE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP3RE_ENABLED       0x01   /* Enabled */

#define T1CCR_CAP2INT              0x100  /* Bit 8: CAP2INT (Interrupt on capture CAP2) */
#define T1CCR_CAP2INT_DISABLED     0x00   /* Disabled */
#define T1CCR_CAP2INT_ENABLED      0x01   /* Enabled */

#define T1CCR_CAP2FE               0x80   /* Bit 7: CAP2FE (Capture on CAP2 falling edge) */
#define T1CCR_CAP2FE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP2FE_ENABLED       0x01   /* Enabled */

#define T1CCR_CAP2RE               0x40   /* Bit 6: CAP2RE (Capture on CAP2 rising edge) */
#define T1CCR_CAP2RE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP2RE_ENABLED       0x01   /* Enabled */

#define T1CCR_CAP1INT              0x20   /* Bit 5: CAP1INT (Interrupt on capture CAP1) */
#define T1CCR_CAP1INT_DISABLED     0x00   /* Disabled */
#define T1CCR_CAP1INT_ENABLED      0x01   /* Enabled */

#define T1CCR_CAP1FE               0x10   /* Bit 4: CAP1FE (Capture on CAP1 falling edge) */
#define T1CCR_CAP1FE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP1FE_ENABLED       0x01   /* Enabled */

#define T1CCR_CAP1RE               0x08   /* Bit 3: CAP1RE (Capture on CAP1 rising edge) */
#define T1CCR_CAP1RE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP1RE_ENABLED       0x01   /* Enabled */

#define T1CCR_CAP0INT              0x04   /* Bit 2: CAP0INT (Interrupt on capture CAP0) */
#define T1CCR_CAP0INT_DISABLED     0x00   /* Disabled */
#define T1CCR_CAP0INT_ENABLED      0x01   /* Enabled */

#define T1CCR_CAP0FE               0x02   /* Bit 1: CAP0FE (Capture on CAP0 falling edge) */
#define T1CCR_CAP0FE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP0FE_ENABLED       0x01   /* Enabled */

#define T1CCR_CAP0RE               0x01   /* Bit 0: CAP0RE (Capture on CAP0 rising edge) */
#define T1CCR_CAP0RE_DISABLED      0x00   /* Disabled */
#define T1CCR_CAP0RE_ENABLED       0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Timer 1 Capture Register 0
**---------------------------------------------------------------------------
*/

#define T1CR0_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Capture Register 1
**---------------------------------------------------------------------------
*/

#define T1CR1_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Capture Register 2
**---------------------------------------------------------------------------
*/

#define T1CR2_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 Capture Register 3
**---------------------------------------------------------------------------
*/

#define T1CR3_VALUE                0xffffffff /* Bit 31-0: VALUE (Timer capture value) */


/*
**---------------------------------------------------------------------------
**  Timer 1 External Match Register
**---------------------------------------------------------------------------
*/

#define T1EMR_EMC3                 0xc00  /* Bit 11-10: EMC3 (External match control 3) */
#define T1EMR_EMC3_NOTHING         0x00   /* Do nothing */
#define T1EMR_EMC3_CLEAR           0x01   /* Clear output to 0 */
#define T1EMR_EMC3_SET             0x02   /* Set output to 1 */
#define T1EMR_EMC3_TOGGLE          0x03   /* Toggle output */

#define T1EMR_EMC2                 0x300  /* Bit 9-8: EMC2 (External match control 2) */
#define T1EMR_EMC2_NOTHING         0x00   /* Do nothing */
#define T1EMR_EMC2_CLEAR           0x01   /* Clear output to 0 */
#define T1EMR_EMC2_SET             0x02   /* Set output to 1 */
#define T1EMR_EMC2_TOGGLE          0x03   /* Toggle output */

#define T1EMR_EMC1                 0xc0   /* Bit 7-6: EMC1 (External match control 1) */
#define T1EMR_EMC1_NOTHING         0x00   /* Do nothing */
#define T1EMR_EMC1_CLEAR           0x01   /* Clear output to 0 */
#define T1EMR_EMC1_SET             0x02   /* Set output to 1 */
#define T1EMR_EMC1_TOGGLE          0x03   /* Toggle output */

#define T1EMR_EMC0                 0x30   /* Bit 5-4: EMC0 (External match control 0) */
#define T1EMR_EMC0_NOTHING         0x00   /* Do nothing */
#define T1EMR_EMC0_CLEAR           0x01   /* Clear output to 0 */
#define T1EMR_EMC0_SET             0x02   /* Set output to 1 */
#define T1EMR_EMC0_TOGGLE          0x03   /* Toggle output */

#define T1EMR_EM3                  0x08   /* Bit 3: EM3 (External match 3) */
#define T1EMR_EM3_LOW              0x00   /* Low */
#define T1EMR_EM3_HIGH             0x01   /* High */

#define T1EMR_EM2                  0x04   /* Bit 2: EM2 (External match 2) */
#define T1EMR_EM2_LOW              0x00   /* Low */
#define T1EMR_EM2_HIGH             0x01   /* High */

#define T1EMR_EM1                  0x02   /* Bit 1: EM1 (External match 1) */
#define T1EMR_EM1_LOW              0x00   /* Low */
#define T1EMR_EM1_HIGH             0x01   /* High */

#define T1EMR_EM0                  0x01   /* Bit 0: EM0 (External match 0) */
#define T1EMR_EM0_LOW              0x00   /* Low */
#define T1EMR_EM0_HIGH             0x01   /* High */


/*
**---------------------------------------------------------------------------
**  UART0 Receiver Buffer Register
**---------------------------------------------------------------------------
*/

#define U0RBR_RXD                  0xff   /* Bit 7-0: RXD (Received data) */


/*
**---------------------------------------------------------------------------
**  UART0 Transmit Holding Register
**---------------------------------------------------------------------------
*/

#define U0THR_TXD                  0xff   /* Bit 7-0: TXD (Transmit data) */


/*
**---------------------------------------------------------------------------
**  UART0 Divisor Latch LSB
**---------------------------------------------------------------------------
*/

#define U0DLL_DIVL                 0xff   /* Bit 7-0: DIVL (Baud rate generator divisor [7:0]) */


/*
**---------------------------------------------------------------------------
**  UART0 Divisor Latch MSB
**---------------------------------------------------------------------------
*/

#define U0DLM_DIVM                 0xff   /* Bit 7-0: DIVM (Baud rate generator divisor [15:8]) */


/*
**---------------------------------------------------------------------------
**  UART0 Interrupt Enable Register
**---------------------------------------------------------------------------
*/

#define U0IER_RXLSIE               0x04   /* Bit 2: RXLSIE (Rx Line status interrupt enable (RXLINE)) */
#define U0IER_RXLSIE_DISABLED      0x00   /* Disabled */
#define U0IER_RXLSIE_ENABLED       0x01   /* Enabled */

#define U0IER_THREIE               0x02   /* Bit 1: THREIE (Transmit interrupt enable (THRE)) */
#define U0IER_THREIE_DISABLED      0x00   /* Disabled */
#define U0IER_THREIE_ENABLED       0x01   /* Enabled */

#define U0IER_RDAIE                0x01   /* Bit 0: RDAIE (Receive interrupt enable (RDA)) */
#define U0IER_RDAIE_DISABLED       0x00   /* Disabled */
#define U0IER_RDAIE_ENABLED        0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  UART0 Interrupt ID Register
**---------------------------------------------------------------------------
*/

#define U0IIR_IIRFE                0xc0   /* Bit 7-6: IIRFE (FIFO enable) */
#define U0IIR_IIRFE_ONE            0x00   /* 1 (Trigger level 0 (=1)) */
#define U0IIR_IIRFE_FOUR           0x01   /* 4 (Trigger level 1 (=4)) */
#define U0IIR_IIRFE_EIGHT          0x02   /* 8 (Trigger level 2 (=8)) */
#define U0IIR_IIRFE_FOURTEEN       0x03   /* 14 (Trigger level 3 (=14)) */

#define U0IIR_IID                  0x0e   /* Bit 3-1: IID (Interrupt identification) */
#define U0IIR_IID_THRE_INT         0x01   /* Transmit buffer empty interrupt (THRE) (Third priority) */
#define U0IIR_IID_CTI_INT          0x06   /* Character timeout interrupt (CTI) (Second priority) */
#define U0IIR_IID_RDA_INT          0x02   /* Receive data available or Trigger level interrupt code (RDA) (Second priority) */
#define U0IIR_IID_RX_LINE_INT      0x03   /* Receive line status interrupt (Highest priority) */

#define U0IIR_IP                   0x01   /* Bit 0: IP (Interrupt pending) */
#define U0IIR_IP_INTERRUPT         0x00   /* Interrupt pending  */
#define U0IIR_IP_NO_INTERRUPT      0x01   /* No pending interrupt */


/*
**---------------------------------------------------------------------------
**  UART0 FIFO Control Register
**---------------------------------------------------------------------------
*/

#define U0FCR_RTLS                 0xc0   /* Bit 7-6: RTLS (Receive FIFO trigger level) */
#define U0FCR_RTLS_ONE             0x00   /* 1 (Trigger level 0 (=1)) */
#define U0FCR_RTLS_FOUR            0x01   /* 4 (Trigger level 1 (=4)) */
#define U0FCR_RTLS_EIGHT           0x02   /* 8 (Trigger level 2 (=8)) */
#define U0FCR_RTLS_FOURTEEN        0x03   /* 14 (Trigger level 3 (=14)) */

#define U0FCR_TFR                  0x04   /* Bit 2: TFR (Clear transmit FIFO) */
#define U0FCR_TFR_NOTHING          0x00   /* Nothing happens */
#define U0FCR_TFR_RESET            0x01   /* Reset transfer pointers and clear TX FIFO */

#define U0FCR_RFR                  0x02   /* Bit 1: RFR (Clear receive FIFO) */
#define U0FCR_RFR_NOTHING          0x00   /* Nothing happens */
#define U0FCR_RFR_RESET            0x01   /* Reset receive pointers and clear RX FIFO */

#define U0FCR_FCRFE                0x01   /* Bit 0: FCRFE (FIFO enable) */
#define U0FCR_FCRFE_DISABLED       0x00   /* Disabled (Disabled FIFOs) */
#define U0FCR_FCRFE_ENABLED        0x01   /* Enabled (Enable TX and RX FIFOs) */


/*
**---------------------------------------------------------------------------
**  UART0 Line Control Register
**---------------------------------------------------------------------------
*/

#define U0LCR_DLAB                 0x80   /* Bit 7: DLAB (Divisor latch access bit) */
#define U0LCR_DLAB_TX_RX           0x00   /* Access transmit/receive registers */
#define U0LCR_DLAB_DIVISOR         0x01   /* Access divisor registers (Divisor used for baud rate generator ) */

#define U0LCR_BC                   0x40   /* Bit 6: BC (Break control) */
#define U0LCR_BC_DISABLED          0x00   /* Disabled (No break) */
#define U0LCR_BC_ENABLED           0x01   /* Enabled (Send continous 0 on transmit output) */

#define U0LCR_PS                   0x30   /* Bit 5-4: PS (Parity select) */
#define U0LCR_PS_ODD               0x00   /* Odd parity */
#define U0LCR_PS_EVEN              0x01   /* Even parity */
#define U0LCR_PS_FORCED_1          0x02   /* Forced "1" stick parity */
#define U0LCR_PS_FORCED_0          0x03   /* Forced "0" stick parity */

#define U0LCR_PE                   0x08   /* Bit 3: PE (Parity enable) */
#define U0LCR_PE_DISABLED          0x00   /* Disabled (No parity generation and checking) */
#define U0LCR_PE_ENABLED           0x01   /* Enabled (Parity generation and checking) */

#define U0LCR_SBS                  0x04   /* Bit 2: SBS (Stop bit select) */
#define U0LCR_SBS_S1               0x00   /* 1 stop bit */
#define U0LCR_SBS_S2               0x01   /* 2 stop bits ((=1.5 if 5 bit character length is used)) */

#define U0LCR_WLS                  0x03   /* Bit 1-0: WLS (Word length select) */
#define U0LCR_WLS_D5               0x00   /* 5 data bits */
#define U0LCR_WLS_D6               0x01   /* 6 data bits */
#define U0LCR_WLS_D7               0x02   /* 7 data bits */
#define U0LCR_WLS_D8               0x03   /* 8 data bits */


/*
**---------------------------------------------------------------------------
**  UART0 Line Status Register
**---------------------------------------------------------------------------
*/

#define U0LSR_RXFE                 0x80   /* Bit 7: RXFE (Receive error) */
#define U0LSR_RXFE_OK              0x00   /* No receive error in FIFO mode or Always 0 in non FIFO mode */
#define U0LSR_RXFE_ERROR           0x01   /* Parity, framing or break indication in the FIFO */

#define U0LSR_TEMT                 0x40   /* Bit 6: TEMT (Transmit empty) */
#define U0LSR_TEMT_TRANSMIT        0x00   /* Transmission in progress */
#define U0LSR_TEMT_IDLE            0x01   /* Transmitter idle */

#define U0LSR_THRE                 0x20   /* Bit 5: THRE (Transmit holding register empty) */
#define U0LSR_THRE_VALID           0x00   /* Valid data in transmit register */
#define U0LSR_THRE_EMPTY           0x01   /* Empty */

#define U0LSR_BI                   0x10   /* Bit 4: BI (Break indicator) */
#define U0LSR_BI_NO                0x00   /* No break */
#define U0LSR_BI_BREAK             0x01   /* Break condition detected on receive input line */

#define U0LSR_FE                   0x08   /* Bit 3: FE (Framing error) */
#define U0LSR_FE_OK                0x00   /* No framing error */
#define U0LSR_FE_ERROR             0x01   /* Framing error occured */

#define U0LSR_PE                   0x04   /* Bit 2: PE (Parity error) */
#define U0LSR_PE_OK                0x00   /* No parity error */
#define U0LSR_PE_ERROR             0x01   /* Parity error occured */

#define U0LSR_OE                   0x02   /* Bit 1: OE (Overrun error) */
#define U0LSR_OE_OK                0x00   /* No overrun error */
#define U0LSR_OE_ERROR             0x01   /* Overrun error occured */

#define U0LSR_DR                   0x01   /* Bit 0: DR (Receiver data ready) */
#define U0LSR_DR_EMPTY             0x00   /* Empty */
#define U0LSR_DR_VALID             0x01   /* Valid data in receive buffer register */


/*
**---------------------------------------------------------------------------
**  UART0 Scratch Pad Register
**---------------------------------------------------------------------------
*/

#define U0SCR_DATA                 0xff   /* Bit 7-0: DATA (A readable /writable byte) */


/*
**---------------------------------------------------------------------------
**  UART1 Receiver Buffer Register
**---------------------------------------------------------------------------
*/

#define U1RBR_RXD                  0xff   /* Bit 7-0: RXD (Received data) */


/*
**---------------------------------------------------------------------------
**  UART1 Transmit Holding Register
**---------------------------------------------------------------------------
*/

#define U1THR_TXD                  0xff   /* Bit 7-0: TXD (Transmit data) */


/*
**---------------------------------------------------------------------------
**  UART1 Divisor Latch LSB
**---------------------------------------------------------------------------
*/

#define U1DLL_DIVL                 0xff   /* Bit 7-0: DIVL (Baud rate generator divisor [7:0]) */


/*
**---------------------------------------------------------------------------
**  UART1 Divisor Latch MSB
**---------------------------------------------------------------------------
*/

#define U1DLM_DIVM                 0xff   /* Bit 7-0: DIVM (Baud rate generator divisor [15:8]) */


/*
**---------------------------------------------------------------------------
**  UART1 Interrupt Enable Register
**---------------------------------------------------------------------------
*/

#define U1IER_MSIE                 0x08   /* Bit 3: MSIE (Modem status interrupt enable (MODEM)) */
#define U1IER_MSIE_DISABLED        0x00   /* Disabled */
#define U1IER_MSIE_ENABLED         0x01   /* Enabled */

#define U1IER_RXLSIE               0x04   /* Bit 2: RXLSIE (Rx Line status interrupt enable (RXLINE)) */
#define U1IER_RXLSIE_DISABLED      0x00   /* Disabled */
#define U1IER_RXLSIE_ENABLED       0x01   /* Enabled */

#define U1IER_THREIE               0x02   /* Bit 1: THREIE (Transmit interrupt enable (THRE)) */
#define U1IER_THREIE_DISABLED      0x00   /* Disabled */
#define U1IER_THREIE_ENABLED       0x01   /* Enabled */

#define U1IER_RDAIE                0x01   /* Bit 0: RDAIE (Receive interrupt enable (RDA)) */
#define U1IER_RDAIE_DISABLED       0x00   /* Disabled */
#define U1IER_RDAIE_ENABLED        0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  UART1 Interrupt ID Register
**---------------------------------------------------------------------------
*/

#define U1IIR_IIRFE                0xc0   /* Bit 7-6: IIRFE (FIFO enable) */
#define U1IIR_IIRFE_ONE            0x00   /* 1 (Trigger level 0 (=1)) */
#define U1IIR_IIRFE_FOUR           0x01   /* 4 (Trigger level 1 (=4)) */
#define U1IIR_IIRFE_EIGHT          0x02   /* 8 (Trigger level 2 (=8)) */
#define U1IIR_IIRFE_FOURTEEN       0x03   /* 14 (Trigger level 3 (=14)) */

#define U1IIR_IID                  0x0e   /* Bit 3-1: IID (Interrupt identification) */
#define U1IIR_IID_MODEM_INT        0x00   /* Modem interrupt (Fourth priority) */
#define U1IIR_IID_THRE_INT         0x01   /* Transmit buffer empty interrupt (THRE) (Third priority) */
#define U1IIR_IID_CTI_INT          0x06   /* Character timeout interrupt (CTI) (Second priority) */
#define U1IIR_IID_RDA_INT          0x02   /* Receive data available or Trigger level interrupt code (RDA) (Second priority) */
#define U1IIR_IID_RX_LINE_INT      0x03   /* Receive line status interrupt (Highest priority) */

#define U1IIR_IP                   0x01   /* Bit 0: IP (Interrupt pending) */
#define U1IIR_IP_INTERRUPT         0x00   /* Interrupt pending  */
#define U1IIR_IP_NO_INTERRUPT      0x01   /* No pending interrupt */


/*
**---------------------------------------------------------------------------
**  UART1 FIFO Control Register
**---------------------------------------------------------------------------
*/

#define U1FCR_RTLS                 0xc0   /* Bit 7-6: RTLS (Receive FIFO trigger level) */
#define U1FCR_RTLS_ONE             0x00   /* 1 (Trigger level 0 (=1)) */
#define U1FCR_RTLS_FOUR            0x01   /* 4 (Trigger level 1 (=4)) */
#define U1FCR_RTLS_EIGHT           0x02   /* 8 (Trigger level 2 (=8)) */
#define U1FCR_RTLS_FOURTEEN        0x03   /* 14 (Trigger level 3 (=14)) */

#define U1FCR_TFR                  0x04   /* Bit 2: TFR (Clear transmit FIFO) */
#define U1FCR_TFR_NOTHING          0x00   /* Nothing happens */
#define U1FCR_TFR_RESET            0x01   /* Reset transfer pointers and clear TX FIFO */

#define U1FCR_RFR                  0x02   /* Bit 1: RFR (Clear receive FIFO) */
#define U1FCR_RFR_NOTHING          0x00   /* Nothing happens */
#define U1FCR_RFR_RESET            0x01   /* Reset receive pointers and clear RX FIFO */

#define U1FCR_FCRFE                0x01   /* Bit 0: FCRFE (FIFO enable) */
#define U1FCR_FCRFE_DISABLED       0x00   /* Disabled (Disabled FIFOs) */
#define U1FCR_FCRFE_ENABLED        0x01   /* Enabled (Enable TX and RX FIFOs) */


/*
**---------------------------------------------------------------------------
**  UART1 Line Control Register
**---------------------------------------------------------------------------
*/

#define U1LCR_DLAB                 0x80   /* Bit 7: DLAB (Divisor latch access bit) */
#define U1LCR_DLAB_TX_RX           0x00   /* Access transmit/receive registers */
#define U1LCR_DLAB_DIVISOR         0x01   /* Access divisor registers (Divisor used for baud rate generator ) */

#define U1LCR_BC                   0x40   /* Bit 6: BC (Break control) */
#define U1LCR_BC_DISABLED          0x00   /* Disabled (No break) */
#define U1LCR_BC_ENABLED           0x01   /* Enabled (Send continous 0 on transmit output) */

#define U1LCR_PS                   0x30   /* Bit 5-4: PS (Parity select) */
#define U1LCR_PS_ODD               0x00   /* Odd parity */
#define U1LCR_PS_EVEN              0x01   /* Even parity */
#define U1LCR_PS_FORCED_1          0x02   /* Forced "1" stick parity */
#define U1LCR_PS_FORCED_0          0x03   /* Forced "0" stick parity */

#define U1LCR_PE                   0x08   /* Bit 3: PE (Parity enable) */
#define U1LCR_PE_DISABLED          0x00   /* Disabled (No parity generation and checking) */
#define U1LCR_PE_ENABLED           0x01   /* Enabled (Parity generation and checking) */

#define U1LCR_SBS                  0x04   /* Bit 2: SBS (Stop bit select) */
#define U1LCR_SBS_S1               0x00   /* 1 stop bit */
#define U1LCR_SBS_S2               0x01   /* 2 stop bits ((=1.5 if 5 bit character length is used)) */

#define U1LCR_WLS                  0x03   /* Bit 1-0: WLS (Word length select) */
#define U1LCR_WLS_D5               0x00   /* 5 data bits */
#define U1LCR_WLS_D6               0x01   /* 6 data bits */
#define U1LCR_WLS_D7               0x02   /* 7 data bits */
#define U1LCR_WLS_D8               0x03   /* 8 data bits */


/*
**---------------------------------------------------------------------------
**  UART1 Modem Control Register
**---------------------------------------------------------------------------
*/

#define U1MCR_LMS                  0x10   /* Bit 4: LMS (Loop-back mode select) */
#define U1MCR_LMS_NORMAL           0x00   /* Normal mode */
#define U1MCR_LMS_LOOPBACK         0x01   /* Loop-back mode */

#define U1MCR_RTS                  0x02   /* Bit 1: RTS (RTS control) */

#define U1MCR_DTR                  0x01   /* Bit 0: DTR (DTR control) */


/*
**---------------------------------------------------------------------------
**  UART1 Line Status Register
**---------------------------------------------------------------------------
*/

#define U1LSR_RXFE                 0x80   /* Bit 7: RXFE (Receive error) */
#define U1LSR_RXFE_OK              0x00   /* No receive error in FIFO mode or Always 0 in non FIFO mode */
#define U1LSR_RXFE_ERROR           0x01   /* Parity, framing or break indication in the FIFO */

#define U1LSR_TEMT                 0x40   /* Bit 6: TEMT (Transmit empty) */
#define U1LSR_TEMT_TRANSMIT        0x00   /* Transmission in progress */
#define U1LSR_TEMT_IDLE            0x01   /* Transmitter idle */

#define U1LSR_THRE                 0x20   /* Bit 5: THRE (Transmit holding register empty) */
#define U1LSR_THRE_VALID           0x00   /* Valid data in transmit register */
#define U1LSR_THRE_EMPTY           0x01   /* Empty */

#define U1LSR_BI                   0x10   /* Bit 4: BI (Break indicator) */
#define U1LSR_BI_NO                0x00   /* No break */
#define U1LSR_BI_BREAK             0x01   /* Break condition detected on receive input line */

#define U1LSR_FE                   0x08   /* Bit 3: FE (Framing error) */
#define U1LSR_FE_OK                0x00   /* No framing error */
#define U1LSR_FE_ERROR             0x01   /* Framing error occured */

#define U1LSR_PE                   0x04   /* Bit 2: PE (Parity error) */
#define U1LSR_PE_OK                0x00   /* No parity error */
#define U1LSR_PE_ERROR             0x01   /* Parity error occured */

#define U1LSR_OE                   0x02   /* Bit 1: OE (Overrun error) */
#define U1LSR_OE_OK                0x00   /* No overrun error */
#define U1LSR_OE_ERROR             0x01   /* Overrun error occured */

#define U1LSR_DR                   0x01   /* Bit 0: DR (Receiver data ready) */
#define U1LSR_DR_EMPTY             0x00   /* Empty */
#define U1LSR_DR_VALID             0x01   /* Valid data in receive buffer register */


/*
**---------------------------------------------------------------------------
**  UART1 Modem Status Register
**---------------------------------------------------------------------------
*/

#define U1MSR_DCD                  0x80   /* Bit 7: DCD (Data carrier detect) */

#define U1MSR_RI                   0x40   /* Bit 6: RI (Ring indicator) */

#define U1MSR_DSR                  0x20   /* Bit 5: DSR (Data set ready) */

#define U1MSR_CTS                  0x10   /* Bit 4: CTS (Clear to send) */

#define U1MSR_DDCD                 0x08   /* Bit 3: DDCD (Delta status change of DCD) */
#define U1MSR_DDCD_NO              0x00   /* No change */
#define U1MSR_DDCD_CHANGED         0x01   /* DCD changed */

#define U1MSR_TERI                 0x04   /* Bit 2: TERI (Trailing edge change of RI) */
#define U1MSR_TERI_NO              0x00   /* No change */
#define U1MSR_TERI_CHANGED         0x01   /* RI changed */

#define U1MSR_DDSR                 0x02   /* Bit 1: DDSR (Delta status change of DSR) */
#define U1MSR_DDSR_NO              0x00   /* No change */
#define U1MSR_DDSR_CHANGED         0x01   /* DSR changed */

#define U1MSR_DCTS                 0x01   /* Bit 0: DCTS (Delta status change of CTS) */
#define U1MSR_DCTS_NO              0x00   /* No change */
#define U1MSR_DCTS_CHANGED         0x01   /* CTS changed */


/*
**---------------------------------------------------------------------------
**  UART1 Scratch Pad Register
**---------------------------------------------------------------------------
*/

#define U1SCR_DATA                 0xff   /* Bit 7-0: DATA (A readable /writable byte) */


/*
**---------------------------------------------------------------------------
**  PWM Interrupt Register
**---------------------------------------------------------------------------
*/

#define PWMIR_MR6INT               0x400  /* Bit 10: MR6INT (Interrupt flag for PWM match channel 6) */
#define PWMIR_MR6INT_NO_INTERRUPT  0x00   /* No interrupt */
#define PWMIR_MR6INT_INTERRUPT     0x01   /* Interrupt */

#define PWMIR_MR5INT               0x200  /* Bit 9: MR5INT (Interrupt flag for PWM match channel 5) */
#define PWMIR_MR5INT_NO_INTERRUPT  0x00   /* No interrupt */
#define PWMIR_MR5INT_INTERRUPT     0x01   /* Interrupt */

#define PWMIR_MR4INT               0x100  /* Bit 8: MR4INT (Interrupt flag for PWM match channel 4) */
#define PWMIR_MR4INT_NO_INTERRUPT  0x00   /* No interrupt */
#define PWMIR_MR4INT_INTERRUPT     0x01   /* Interrupt */

#define PWMIR_MR3INT               0x08   /* Bit 3: MR3INT (Interrupt flag for PWM match channel 3) */
#define PWMIR_MR3INT_NO_INTERRUPT  0x00   /* No interrupt */
#define PWMIR_MR3INT_INTERRUPT     0x01   /* Interrupt */

#define PWMIR_MR2INT               0x04   /* Bit 2: MR2INT (Interrupt flag for PWM match channel 2) */
#define PWMIR_MR2INT_NO_INTERRUPT  0x00   /* No interrupt */
#define PWMIR_MR2INT_INTERRUPT     0x01   /* Interrupt */

#define PWMIR_MR1INT               0x02   /* Bit 1: MR1INT (Interrupt flag for PWM match channel 1) */
#define PWMIR_MR1INT_NO_INTERRUPT  0x00   /* No interrupt */
#define PWMIR_MR1INT_INTERRUPT     0x01   /* Interrupt */

#define PWMIR_MR0INT               0x01   /* Bit 0: MR0INT (Interrupt flag for PWM match channel 0) */
#define PWMIR_MR0INT_NO_INTERRUPT  0x00   /* No interrupt */
#define PWMIR_MR0INT_INTERRUPT     0x01   /* Interrupt */


/*
**---------------------------------------------------------------------------
**  PWM Timer Control Register
**---------------------------------------------------------------------------
*/

#define PWMTCR_PWMEN               0x08   /* Bit 3: PWMEN (PWM enable) */
#define PWMTCR_PWMEN_DISABLED      0x00   /* Disabled */
#define PWMTCR_PWMEN_ENABLED       0x01   /* Enabled (Shadow registers operates) */

#define PWMTCR_CR                  0x02   /* Bit 1: CR (Counter reset) */
#define PWMTCR_CR_NO_RESET         0x00   /* No reset */
#define PWMTCR_CR_RESET            0x01   /* Generate reset */

#define PWMTCR_CE                  0x01   /* Bit 0: CE (Counter enable) */
#define PWMTCR_CE_DISABLED         0x00   /* Disabled */
#define PWMTCR_CE_ENABLED          0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  PWM Timer Counter
**---------------------------------------------------------------------------
*/

#define PWMTC_VALUE                0xffffffff /* Bit 31-0: VALUE (PWM counter value) */


/*
**---------------------------------------------------------------------------
**  PWM Prescale Register
**---------------------------------------------------------------------------
*/

#define PWMPR_VALUE                0xffffffff /* Bit 31-0: VALUE (PWM prescaler max value) */


/*
**---------------------------------------------------------------------------
**  PWM Prescale Counter
**---------------------------------------------------------------------------
*/

#define PWMPC_VALUE                0xffffffff /* Bit 31-0: VALUE (PWM prescale counter value) */


/*
**---------------------------------------------------------------------------
**  PWM Match Control Register
**---------------------------------------------------------------------------
*/

#define PWMMCR_MR6STOP             0x100000 /* Bit 20: MR6STOP (Stop on MR6) */
#define PWMMCR_MR6STOP_DISABLED    0x00   /* Disabled */
#define PWMMCR_MR6STOP_ENABLED     0x01   /* Enabled */

#define PWMMCR_MR6RES              0x80000 /* Bit 19: MR6RES (Reset on MR6) */
#define PWMMCR_MR6RES_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR6RES_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR6INT              0x40000 /* Bit 18: MR6INT (Interrupt on MR6) */
#define PWMMCR_MR6INT_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR6INT_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR5STOP             0x20000 /* Bit 17: MR5STOP (Stop on MR5) */
#define PWMMCR_MR5STOP_DISABLED    0x00   /* Disabled */
#define PWMMCR_MR5STOP_ENABLED     0x01   /* Enabled */

#define PWMMCR_MR5RES              0x10000 /* Bit 16: MR5RES (Reset on MR5) */
#define PWMMCR_MR5RES_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR5RES_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR5INT              0x8000 /* Bit 15: MR5INT (Interrupt on MR5) */
#define PWMMCR_MR5INT_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR5INT_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR4STOP             0x4000 /* Bit 14: MR4STOP (Stop on MR4) */
#define PWMMCR_MR4STOP_DISABLED    0x00   /* Disabled */
#define PWMMCR_MR4STOP_ENABLED     0x01   /* Enabled */

#define PWMMCR_MR4RES              0x2000 /* Bit 13: MR4RES (Reset on MR4) */
#define PWMMCR_MR4RES_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR4RES_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR4INT              0x1000 /* Bit 12: MR4INT (Interrupt on MR4) */
#define PWMMCR_MR4INT_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR4INT_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR3STOP             0x800  /* Bit 11: MR3STOP (Stop on MR3) */
#define PWMMCR_MR3STOP_DISABLED    0x00   /* Disabled */
#define PWMMCR_MR3STOP_ENABLED     0x01   /* Enabled */

#define PWMMCR_MR3RES              0x400  /* Bit 10: MR3RES (Reset on MR3) */
#define PWMMCR_MR3RES_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR3RES_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR3INT              0x200  /* Bit 9: MR3INT (Interrupt on MR3) */
#define PWMMCR_MR3INT_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR3INT_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR2STOP             0x100  /* Bit 8: MR2STOP (Stop on MR2) */
#define PWMMCR_MR2STOP_DISABLED    0x00   /* Disabled */
#define PWMMCR_MR2STOP_ENABLED     0x01   /* Enabled */

#define PWMMCR_MR2RES              0x80   /* Bit 7: MR2RES (Reset on MR2) */
#define PWMMCR_MR2RES_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR2RES_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR2INT              0x40   /* Bit 6: MR2INT (Interrupt on MR2) */
#define PWMMCR_MR2INT_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR2INT_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR1STOP             0x20   /* Bit 5: MR1STOP (Stop on MR1) */
#define PWMMCR_MR1STOP_DISABLED    0x00   /* Disabled */
#define PWMMCR_MR1STOP_ENABLED     0x01   /* Enabled */

#define PWMMCR_MR1RES              0x10   /* Bit 4: MR1RES (Reset on MR1) */
#define PWMMCR_MR1RES_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR1RES_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR1INT              0x08   /* Bit 3: MR1INT (Interrupt on MR1) */
#define PWMMCR_MR1INT_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR1INT_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR0STOP             0x04   /* Bit 2: MR0STOP (Stop on MR0) */
#define PWMMCR_MR0STOP_DISABLED    0x00   /* Disabled */
#define PWMMCR_MR0STOP_ENABLED     0x01   /* Enabled */

#define PWMMCR_MR0RES              0x02   /* Bit 1: MR0RES (Reset on MR0) */
#define PWMMCR_MR0RES_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR0RES_ENABLED      0x01   /* Enabled */

#define PWMMCR_MR0INT              0x01   /* Bit 0: MR0INT (Interrupt on MR0) */
#define PWMMCR_MR0INT_DISABLED     0x00   /* Disabled */
#define PWMMCR_MR0INT_ENABLED      0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  PWM Match Register 0
**---------------------------------------------------------------------------
*/

#define PWMMR0_VALUE               0xffffffff /* Bit 31-0: VALUE (PWM Match value) */


/*
**---------------------------------------------------------------------------
**  PWM Match Register 1
**---------------------------------------------------------------------------
*/

#define PWMMR1_VALUE               0xffffffff /* Bit 31-0: VALUE (PWM Match value) */


/*
**---------------------------------------------------------------------------
**  PWM Match Register 2
**---------------------------------------------------------------------------
*/

#define PWMMR2_VALUE               0xffffffff /* Bit 31-0: VALUE (PWM Match value) */


/*
**---------------------------------------------------------------------------
**  PWM Match Register 3
**---------------------------------------------------------------------------
*/

#define PWMMR3_VALUE               0xffffffff /* Bit 31-0: VALUE (PWM Match value) */


/*
**---------------------------------------------------------------------------
**  PWM Match Register 4
**---------------------------------------------------------------------------
*/

#define PWMMR4_VALUE               0xffffffff /* Bit 31-0: VALUE (PWM Match value) */


/*
**---------------------------------------------------------------------------
**  PWM Match Register 5
**---------------------------------------------------------------------------
*/

#define PWMMR5_VALUE               0xffffffff /* Bit 31-0: VALUE (PWM Match value) */


/*
**---------------------------------------------------------------------------
**  PWM Match Register 6
**---------------------------------------------------------------------------
*/

#define PWMMR6_VALUE               0xffffffff /* Bit 31-0: VALUE (PWM Match value) */


/*
**---------------------------------------------------------------------------
**  PWM Control Register
**---------------------------------------------------------------------------
*/

#define PWMPCR_ENA6                0x4000 /* Bit 14: ENA6 (PWM6 output control) */
#define PWMPCR_ENA6_DISABLED       0x00   /* Disabled */
#define PWMPCR_ENA6_ENABLED        0x01   /* Enabled */

#define PWMPCR_ENA5                0x2000 /* Bit 13: ENA5 (PWM5 output control) */
#define PWMPCR_ENA5_DISABLED       0x00   /* Disabled */
#define PWMPCR_ENA5_ENABLED        0x01   /* Enabled */

#define PWMPCR_ENA4                0x1000 /* Bit 12: ENA4 (PWM4 output control) */
#define PWMPCR_ENA4_DISABLED       0x00   /* Disabled */
#define PWMPCR_ENA4_ENABLED        0x01   /* Enabled */

#define PWMPCR_ENA3                0x800  /* Bit 11: ENA3 (PWM3 output control) */
#define PWMPCR_ENA3_DISABLED       0x00   /* Disabled */
#define PWMPCR_ENA3_ENABLED        0x01   /* Enabled */

#define PWMPCR_ENA2                0x400  /* Bit 10: ENA2 (PWM2 output control) */
#define PWMPCR_ENA2_DISABLED       0x00   /* Disabled */
#define PWMPCR_ENA2_ENABLED        0x01   /* Enabled */

#define PWMPCR_ENA1                0x200  /* Bit 9: ENA1 (PWM1 output control) */
#define PWMPCR_ENA1_DISABLED       0x00   /* Disabled */
#define PWMPCR_ENA1_ENABLED        0x01   /* Enabled */

#define PWMPCR_SEL6                0x40   /* Bit 6: SEL6 (PWM6 select control mode) */
#define PWMPCR_SEL6_SINGLE         0x00   /* Single edge */
#define PWMPCR_SEL6_DOUBLE         0x01   /* Double edge */

#define PWMPCR_SEL5                0x20   /* Bit 5: SEL5 (PWM5 select control mode) */
#define PWMPCR_SEL5_SINGLE         0x00   /* Single edge */
#define PWMPCR_SEL5_DOUBLE         0x01   /* Double edge */

#define PWMPCR_SEL4                0x10   /* Bit 4: SEL4 (PWM4 select control mode) */
#define PWMPCR_SEL4_SINGLE         0x00   /* Single edge */
#define PWMPCR_SEL4_DOUBLE         0x01   /* Double edge */

#define PWMPCR_SEL3                0x08   /* Bit 3: SEL3 (PWM3 select control mode) */
#define PWMPCR_SEL3_SINGLE         0x00   /* Single edge */
#define PWMPCR_SEL3_DOUBLE         0x01   /* Double edge */

#define PWMPCR_SEL2                0x04   /* Bit 2: SEL2 (PWM2 select control mode) */
#define PWMPCR_SEL2_SINGLE         0x00   /* Single edge */
#define PWMPCR_SEL2_DOUBLE         0x01   /* Double edge */

#define PWMPCR_SEL1                0x02   /* Bit 1: SEL1 (PWM1 select control mode) */
#define PWMPCR_SEL1_SINGLE         0x00   /* Single edge */
#define PWMPCR_SEL1_DOUBLE         0x01   /* Double edge */


/*
**---------------------------------------------------------------------------
**  PWM Latch Enable Register
**---------------------------------------------------------------------------
*/

#define PWMLER_EM6L                0x40   /* Bit 6: EM6L (Enable PWM match 6 latch) */
#define PWMLER_EM6L_DISABLED       0x00   /* Disabled */
#define PWMLER_EM6L_ENABLED        0x01   /* Enabled */

#define PWMLER_EM5L                0x20   /* Bit 5: EM5L (Enable PWM match 5 latch) */
#define PWMLER_EM5L_DISABLED       0x00   /* Disabled */
#define PWMLER_EM5L_ENABLED        0x01   /* Enabled */

#define PWMLER_EM4L                0x10   /* Bit 4: EM4L (Enable PWM match 4 latch) */
#define PWMLER_EM4L_DISABLED       0x00   /* Disabled */
#define PWMLER_EM4L_ENABLED        0x01   /* Enabled */

#define PWMLER_EM3L                0x08   /* Bit 3: EM3L (Enable PWM match 3 latch) */
#define PWMLER_EM3L_DISABLED       0x00   /* Disabled */
#define PWMLER_EM3L_ENABLED        0x01   /* Enabled */

#define PWMLER_EM2L                0x04   /* Bit 2: EM2L (Enable PWM match 2 latch) */
#define PWMLER_EM2L_DISABLED       0x00   /* Disabled */
#define PWMLER_EM2L_ENABLED        0x01   /* Enabled */

#define PWMLER_EM1L                0x02   /* Bit 1: EM1L (Enable PWM match 1 latch) */
#define PWMLER_EM1L_DISABLED       0x00   /* Disabled */
#define PWMLER_EM1L_ENABLED        0x01   /* Enabled */

#define PWMLER_EM0L                0x01   /* Bit 0: EM0L (Enable PWM match 0 latch) */
#define PWMLER_EM0L_DISABLED       0x00   /* Disabled */
#define PWMLER_EM0L_ENABLED        0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  I2C Control Set Register
**---------------------------------------------------------------------------
*/

#define I2CONSET_I2EN              0x40   /* Bit 6: I2EN (I2C interface enable) */
#define I2CONSET_I2EN_DISABLED     0x00   /* Disabled */
#define I2CONSET_I2EN_ENABLED      0x01   /* Enabled */

#define I2CONSET_STA               0x20   /* Bit 5: STA (Start flag) */
#define I2CONSET_STA_NO_START      0x00   /* No start */
#define I2CONSET_STA_START         0x01   /* Start */

#define I2CONSET_STO               0x10   /* Bit 4: STO (Stop flag) */
#define I2CONSET_STO_NO_STOP       0x00   /* No stop */
#define I2CONSET_STO_STOP          0x01   /* Stop */

#define I2CONSET_SI                0x08   /* Bit 3: SI (I2C interrupt flag) */
#define I2CONSET_SI_NO_INTERRUPT   0x00   /* No interrupt */
#define I2CONSET_SI_INTERRUPT      0x01   /* Interrupt */

#define I2CONSET_AA                0x04   /* Bit 2: AA (Assert acknowledge flag) */
#define I2CONSET_AA_NO_ACK         0x00   /* Not Acknowledge (Not Acknowledge will be sent when data byte is received) */
#define I2CONSET_AA_ACK            0x01   /* Acknowledge (Acknowledge will be sent if certain conditions occur) */


/*
**---------------------------------------------------------------------------
**  I2C Status Register
**---------------------------------------------------------------------------
*/

#define I2STAT_STATUS              0xff   /* Bit 7-0: STATUS (Status) */


/*
**---------------------------------------------------------------------------
**  I2C Data Register
**---------------------------------------------------------------------------
*/

#define I2DAT_DATA                 0xff   /* Bit 7-0: DATA (Data) */


/*
**---------------------------------------------------------------------------
**  I2C Slave Address Register
**---------------------------------------------------------------------------
*/

#define I2ADR_ADDR                 0xfe   /* Bit 7-1: ADDR (Slave mode address) */

#define I2ADR_GC                   0x01   /* Bit 0: GC (General call bit) */
#define I2ADR_GC_NOT_GENERAL       0x00   /* Not general call */
#define I2ADR_GC_GENERAL           0x01   /* General call received */


/*
**---------------------------------------------------------------------------
**  I2C SCL Duty Cycle High Register
**---------------------------------------------------------------------------
*/

#define I2SCLH_COUNT               0xffff /* Bit 15-0: COUNT (Count for SCL high time period) */


/*
**---------------------------------------------------------------------------
**  I2C SCL Duty Cycle Low Register
**---------------------------------------------------------------------------
*/

#define I2SCLL_COUNT               0xffff /* Bit 15-0: COUNT (Count for SCL low time period) */


/*
**---------------------------------------------------------------------------
**  I2C Control Clear Register
**---------------------------------------------------------------------------
*/

#define I2CONCLR_I2ENC             0x40   /* Bit 6: I2ENC (I2C interface disable) */
#define I2CONCLR_I2ENC_NO_EFFECT   0x00   /* No effect */
#define I2CONCLR_I2ENC_CLEAR       0x01   /* Clear  (I2C Disabled) */

#define I2CONCLR_STAC              0x20   /* Bit 5: STAC (Start flag clear) */
#define I2CONCLR_STAC_NO_EFFECT    0x00   /* No effect */
#define I2CONCLR_STAC_CLEAR        0x01   /* Clear start */

#define I2CONCLR_SIC               0x08   /* Bit 3: SIC (I2C interrupt clear) */
#define I2CONCLR_SIC_NO_EFFECT     0x00   /* No effect */
#define I2CONCLR_SIC_CLEAR         0x01   /* Clear interrupt */

#define I2CONCLR_AAC               0x04   /* Bit 2: AAC (Assert acknowledge clear) */
#define I2CONCLR_AAC_NO_EFFECT     0x00   /* No effect */
#define I2CONCLR_AAC_CLEAR         0x01   /* Clear acknowledge */


/*
**---------------------------------------------------------------------------
**  SPI Control Register
**---------------------------------------------------------------------------
*/

#define SPCR_SPIE                  0x80   /* Bit 7: SPIE (SPI interrupt enable) */
#define SPCR_SPIE_DISABLED         0x00   /* Disabled */
#define SPCR_SPIE_ENABLED          0x01   /* Enabled */

#define SPCR_LSBF                  0x40   /* Bit 6: LSBF (Direction order (LSB/MSB)) */
#define SPCR_LSBF_MSB_FIRST        0x00   /* MSB first */
#define SPCR_LSBF_LSB_FIRST        0x01   /* LSB first */

#define SPCR_MSTR                  0x20   /* Bit 5: MSTR (Master/slave select) */
#define SPCR_MSTR_SLAVE            0x00   /* Slave */
#define SPCR_MSTR_MASTER           0x01   /* Master */

#define SPCR_CPOL                  0x10   /* Bit 4: CPOL (Clock polarity) */
#define SPCR_CPOL_HIGH             0x00   /* Active high */
#define SPCR_CPOL_LOW              0x01   /* Active low */

#define SPCR_CPHA                  0x08   /* Bit 3: CPHA (Clock phase) */
#define SPCR_CPHA_FIRST            0x00   /* Data sampled on first clock edge */
#define SPCR_CPHA_SECOND           0x01   /* Data sampled on second clock edge */


/*
**---------------------------------------------------------------------------
**  SPI Status Register
**---------------------------------------------------------------------------
*/

#define SPSR_SPIF                  0x80   /* Bit 7: SPIF (SPI transfer complete flag) */
#define SPSR_SPIF_NOT_COMPLETE     0x00   /* Not complete */
#define SPSR_SPIF_COMPLETE         0x01   /* Complete */

#define SPSR_WCOL                  0x40   /* Bit 6: WCOL (Write collision flag) */
#define SPSR_WCOL_NO_COLLISION     0x00   /* No collision */
#define SPSR_WCOL_COLLISION        0x01   /* Collision */

#define SPSR_ROVR                  0x20   /* Bit 5: ROVR (Read overrun flag) */
#define SPSR_ROVR_NO_OVERRUN       0x00   /* No overrun */
#define SPSR_ROVR_OVERRUN          0x01   /* Overrun */

#define SPSR_MODF                  0x10   /* Bit 4: MODF (Mode fauilt flag) */
#define SPSR_MODF_NO_ERROR         0x00   /* No error */
#define SPSR_MODF_ERROR            0x01   /* Error */

#define SPSR_ABRT                  0x08   /* Bit 3: ABRT (Slave abort) */
#define SPSR_ABRT_NO_ABORT         0x00   /* No abort */
#define SPSR_ABRT_ABORT            0x01   /* Abort */


/*
**---------------------------------------------------------------------------
**  SPI Data Register
**---------------------------------------------------------------------------
*/

#define SPDR_DATA                  0xff   /* Bit 7-0: DATA (Data) */


/*
**---------------------------------------------------------------------------
**  SPI Clock Counter Register
**---------------------------------------------------------------------------
*/

#define SPCCR_COUNTER              0xff   /* Bit 7-0: COUNTER (SPI Clock counter) */


/*
**---------------------------------------------------------------------------
**  SPI Interrupt Register
**---------------------------------------------------------------------------
*/

#define SPINT_SPIINT               0x01   /* Bit 0: SPIINT (SPI interrupt flag) */
#define SPINT_SPIINT_NOT_COMPLETE  0x00   /* Not complete */
#define SPINT_SPIINT_COMPLETE      0x01   /* Complete */


/*
**---------------------------------------------------------------------------
**  Interrupt Location Register
**---------------------------------------------------------------------------
*/

#define ILR_RTCALF                 0x02   /* Bit 1: RTCALF (RTC Alarm register interrupt flag) */
#define ILR_RTCALF_NO_INTERRUPT    0x00   /* No interrupt */
#define ILR_RTCALF_INTERRUPT       0x01   /* Interrupt */

#define ILR_RTCCIF                 0x01   /* Bit 0: RTCCIF (RTC Counter Increment interrupt flag) */
#define ILR_RTCCIF_NO_INTERRUPT    0x00   /* No interrupt */
#define ILR_RTCCIF_INTERRUPT       0x01   /* Interrupt */


/*
**---------------------------------------------------------------------------
**  Clock Tick Counnter
**---------------------------------------------------------------------------
*/

#define CTC_COUNTER                0xfffe /* Bit 15-1: COUNTER (Clock tick counter) */


/*
**---------------------------------------------------------------------------
**  Clock Control Register
**---------------------------------------------------------------------------
*/

#define CCR_CTTEST                 0x0c   /* Bit 3-2: CTTEST (Test enable) */
#define CCR_CTTEST_NORMAL          0x00   /* Normal operation */

#define CCR_CTCRST                 0x02   /* Bit 1: CTCRST (Clock tick counter reset) */
#define CCR_CTCRST_NO_RESET        0x00   /* No reset */
#define CCR_CTCRST_RESET           0x01   /* Generate reset */

#define CCR_CLKEN                  0x01   /* Bit 0: CLKEN (Clock enable) */
#define CCR_CLKEN_DISABLED         0x00   /* Disabled */
#define CCR_CLKEN_ENABLED          0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Counter Increment Interrupt Register
**---------------------------------------------------------------------------
*/

#define CIIR_IMYEAR                0x80   /* Bit 7: IMYEAR (Increment year interrupt) */
#define CIIR_IMYEAR_DISABLED       0x00   /* Disabled */
#define CIIR_IMYEAR_ENABLED        0x01   /* Enabled */

#define CIIR_IMMON                 0x40   /* Bit 6: IMMON (Increment month interrupt) */
#define CIIR_IMMON_DISABLED        0x00   /* Disabled */
#define CIIR_IMMON_ENABLED         0x01   /* Enabled */

#define CIIR_IMDOY                 0x20   /* Bit 5: IMDOY (Increment day of year interrupt) */
#define CIIR_IMDOY_DISABLED        0x00   /* Disabled */
#define CIIR_IMDOY_ENABLED         0x01   /* Enabled */

#define CIIR_IMDOW                 0x10   /* Bit 4: IMDOW (Increment day of week interrupt) */
#define CIIR_IMDOW_DISABLED        0x00   /* Disabled */
#define CIIR_IMDOW_ENABLED         0x01   /* Enabled */

#define CIIR_IMDOM                 0x08   /* Bit 3: IMDOM (Increment day of month interrupt) */
#define CIIR_IMDOM_DISABLED        0x00   /* Disabled */
#define CIIR_IMDOM_ENABLED         0x01   /* Enabled */

#define CIIR_IMHOUR                0x04   /* Bit 2: IMHOUR (Increment hour interrupt) */
#define CIIR_IMHOUR_DISABLED       0x00   /* Disabled */
#define CIIR_IMHOUR_ENABLED        0x01   /* Enabled */

#define CIIR_IMMIN                 0x02   /* Bit 1: IMMIN (Increment minute interrupt) */
#define CIIR_IMMIN_DISABLED        0x00   /* Disabled */
#define CIIR_IMMIN_ENABLED         0x01   /* Enabled */

#define CIIR_IMSEC                 0x01   /* Bit 0: IMSEC (Increment second interrupt) */
#define CIIR_IMSEC_DISABLED        0x00   /* Disabled */
#define CIIR_IMSEC_ENABLED         0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Alarm Mask Register
**---------------------------------------------------------------------------
*/

#define AMR_AMRYEAR                0x80   /* Bit 7: AMRYEAR (Alarm mask year) */
#define AMR_AMRYEAR_ENABLED        0x00   /* Enabled */
#define AMR_AMRYEAR_DISABLED       0x01   /* Disabled */

#define AMR_AMRMON                 0x40   /* Bit 6: AMRMON (Alarm mask month) */
#define AMR_AMRMON_ENABLED         0x00   /* Enabled */
#define AMR_AMRMON_DISABLED        0x01   /* Disabled */

#define AMR_AMRDOY                 0x20   /* Bit 5: AMRDOY (Alarm mask day of year) */
#define AMR_AMRDOY_ENABLED         0x00   /* Enabled */
#define AMR_AMRDOY_DISABLED        0x01   /* Disabled */

#define AMR_AMRDOW                 0x10   /* Bit 4: AMRDOW (Alarm mask day of week) */
#define AMR_AMRDOW_ENABLED         0x00   /* Enabled */
#define AMR_AMRDOW_DISABLED        0x01   /* Disabled */

#define AMR_AMRDOM                 0x08   /* Bit 3: AMRDOM (Alarm mask day of month) */
#define AMR_AMRDOM_ENABLED         0x00   /* Enabled */
#define AMR_AMRDOM_DISABLED        0x01   /* Disabled */

#define AMR_AMRHOUR                0x04   /* Bit 2: AMRHOUR (Alarm mask hour) */
#define AMR_AMRHOUR_ENABLED        0x00   /* Enabled */
#define AMR_AMRHOUR_DISABLED       0x01   /* Disabled */

#define AMR_AMRMIN                 0x02   /* Bit 1: AMRMIN (Alarm mask minute) */
#define AMR_AMRMIN_ENABLED         0x00   /* Enabled */
#define AMR_AMRMIN_DISABLED        0x01   /* Disabled */

#define AMR_AMRSEC                 0x01   /* Bit 0: AMRSEC (Alarm mask second ) */
#define AMR_AMRSEC_ENABLED         0x00   /* Enabled */
#define AMR_AMRSEC_DISABLED        0x01   /* Disabled */


/*
**---------------------------------------------------------------------------
**  Consolidated Time Register 0
**---------------------------------------------------------------------------
*/

#define CTIME0_DOW                 0x7000000 /* Bit 26-24: DOW (Day of week (0-6)) */

#define CTIME0_HOUR                0x1f0000 /* Bit 20-16: HOUR (Hour (0-23)) */

#define CTIME0_MIN                 0x3f00 /* Bit 13-8: MIN (Minute (0-59)) */

#define CTIME0_SEC                 0x3f   /* Bit 5-0: SEC (Second (0-59)) */


/*
**---------------------------------------------------------------------------
**  Consolidated Time Register 1
**---------------------------------------------------------------------------
*/

#define CTIME1_YEAR                0xfff0000 /* Bit 27-16: YEAR (Year (0-4095)) */

#define CTIME1_MON                 0xf00  /* Bit 11-8: MON (Month (1-12)) */

#define CTIME1_DOM                 0x1f   /* Bit 4-0: DOM (Day of month (1-28,29,30,31)) */


/*
**---------------------------------------------------------------------------
**  Consolidated Time Register 2
**---------------------------------------------------------------------------
*/

#define CTIME2_DOY                 0xfff  /* Bit 11-0: DOY (Day of year (1-365,366)) */


/*
**---------------------------------------------------------------------------
**  Seconds Register
**---------------------------------------------------------------------------
*/

#define SEC_SEC                    0x3f   /* Bit 5-0: SEC (Seconds (0-59)) */


/*
**---------------------------------------------------------------------------
**  Minutes Register
**---------------------------------------------------------------------------
*/

#define MIN_MIN                    0x3f   /* Bit 5-0: MIN (Minutes (0-59)) */


/*
**---------------------------------------------------------------------------
**  Hours Register
**---------------------------------------------------------------------------
*/

#define HOUR_HOUR                  0x1f   /* Bit 4-0: HOUR (Hours (0-23)) */


/*
**---------------------------------------------------------------------------
**  Day of Month Register
**---------------------------------------------------------------------------
*/

#define DOM_DOM                    0x1f   /* Bit 4-0: DOM (Day of month (1-28, 29, 30, 31)) */


/*
**---------------------------------------------------------------------------
**  Day of Week Register
**---------------------------------------------------------------------------
*/

#define DOW_DOW                    0x07   /* Bit 2-0: DOW (Day of week (0-6)) */


/*
**---------------------------------------------------------------------------
**  Day of Year Register
**---------------------------------------------------------------------------
*/

#define DOY_DOY                    0x1ff  /* Bit 8-0: DOY (Day of year (1-365, 366)) */


/*
**---------------------------------------------------------------------------
**  Months Register
**---------------------------------------------------------------------------
*/

#define MONTH_MON                  0x0f   /* Bit 3-0: MON (Month (1-12)) */


/*
**---------------------------------------------------------------------------
**  Years Register
**---------------------------------------------------------------------------
*/

#define YEAR_YEAR                  0xfff  /* Bit 11-0: YEAR (Year (0-4095)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Seconds
**---------------------------------------------------------------------------
*/

#define ALSEC_SEC                  0x3f   /* Bit 5-0: SEC (Seconds (0-59)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Minutes
**---------------------------------------------------------------------------
*/

#define ALMIN_MIN                  0x3f   /* Bit 5-0: MIN (Minutes (0-59)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Hours
**---------------------------------------------------------------------------
*/

#define ALHOUR_HOUR                0x1f   /* Bit 4-0: HOUR (Hours (0-23)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Day of Month
**---------------------------------------------------------------------------
*/

#define ALDOM_DOM                  0x1f   /* Bit 4-0: DOM (Day of month (1-28, 29, 30, 31)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Day of Week
**---------------------------------------------------------------------------
*/

#define ALDOW_DOW                  0x07   /* Bit 2-0: DOW (Day of week (0-6)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Day of Year
**---------------------------------------------------------------------------
*/

#define ALDOY_DOY                  0x1ff  /* Bit 8-0: DOY (Day of year (1-365, 366)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Month
**---------------------------------------------------------------------------
*/

#define ALMON_MON                  0x0f   /* Bit 3-0: MON (Month (1-12)) */


/*
**---------------------------------------------------------------------------
**  Alarm value for Year
**---------------------------------------------------------------------------
*/

#define ALYEAR_YEAR                0xfff  /* Bit 11-0: YEAR (Year (0-4095)) */


/*
**---------------------------------------------------------------------------
**  Prescaler value, integer portion
**---------------------------------------------------------------------------
*/

#define PREINT_VALUE               0x1fff /* Bit 12-0: VALUE (Integer portion of RTC prescaler value) */


/*
**---------------------------------------------------------------------------
**  Prescaler value, fraction portion
**---------------------------------------------------------------------------
*/

#define PREFRAC_VALUE              0x7fff /* Bit 14-0: VALUE (Fractional portion of RTC prescaler value) */


/*
**---------------------------------------------------------------------------
**  GPIO Pin Value Register
**---------------------------------------------------------------------------
*/

#define IOPIN_P0_31                0x80000000 /* Bit 31: P0_31 (Port 0.31) */
#define IOPIN_P0_31_LOW            0x00   /* Low */
#define IOPIN_P0_31_HIGH           0x01   /* High */

#define IOPIN_P0_30                0x40000000 /* Bit 30: P0_30 (Port 0.30) */
#define IOPIN_P0_30_LOW            0x00   /* Low */
#define IOPIN_P0_30_HIGH           0x01   /* High */

#define IOPIN_P0_29                0x20000000 /* Bit 29: P0_29 (Port 0.29) */
#define IOPIN_P0_29_LOW            0x00   /* Low */
#define IOPIN_P0_29_HIGH           0x01   /* High */

#define IOPIN_P0_28                0x10000000 /* Bit 28: P0_28 (Port 0.28) */
#define IOPIN_P0_28_LOW            0x00   /* Low */
#define IOPIN_P0_28_HIGH           0x01   /* High */

#define IOPIN_P0_27                0x8000000 /* Bit 27: P0_27 (Port 0.27) */
#define IOPIN_P0_27_LOW            0x00   /* Low */
#define IOPIN_P0_27_HIGH           0x01   /* High */

#define IOPIN_P0_26                0x4000000 /* Bit 26: P0_26 (Port 0.26) */
#define IOPIN_P0_26_LOW            0x00   /* Low */
#define IOPIN_P0_26_HIGH           0x01   /* High */

#define IOPIN_P0_25                0x2000000 /* Bit 25: P0_25 (Port 0.25) */
#define IOPIN_P0_25_LOW            0x00   /* Low */
#define IOPIN_P0_25_HIGH           0x01   /* High */

#define IOPIN_P0_24                0x1000000 /* Bit 24: P0_24 (Port 0.24) */
#define IOPIN_P0_24_LOW            0x00   /* Low */
#define IOPIN_P0_24_HIGH           0x01   /* High */

#define IOPIN_P0_23                0x800000 /* Bit 23: P0_23 (Port 0.23) */
#define IOPIN_P0_23_LOW            0x00   /* Low */
#define IOPIN_P0_23_HIGH           0x01   /* High */

#define IOPIN_P0_22                0x400000 /* Bit 22: P0_22 (Port 0.22) */
#define IOPIN_P0_22_LOW            0x00   /* Low */
#define IOPIN_P0_22_HIGH           0x01   /* High */

#define IOPIN_P0_21                0x200000 /* Bit 21: P0_21 (Port 0.21) */
#define IOPIN_P0_21_LOW            0x00   /* Low */
#define IOPIN_P0_21_HIGH           0x01   /* High */

#define IOPIN_P0_20                0x100000 /* Bit 20: P0_20 (Port 0.20) */
#define IOPIN_P0_20_LOW            0x00   /* Low */
#define IOPIN_P0_20_HIGH           0x01   /* High */

#define IOPIN_P0_19                0x80000 /* Bit 19: P0_19 (Port 0.19) */
#define IOPIN_P0_19_LOW            0x00   /* Low */
#define IOPIN_P0_19_HIGH           0x01   /* High */

#define IOPIN_P0_18                0x40000 /* Bit 18: P0_18 (Port 0.18) */
#define IOPIN_P0_18_LOW            0x00   /* Low */
#define IOPIN_P0_18_HIGH           0x01   /* High */

#define IOPIN_P0_17                0x20000 /* Bit 17: P0_17 (Port 0.17) */
#define IOPIN_P0_17_LOW            0x00   /* Low */
#define IOPIN_P0_17_HIGH           0x01   /* High */

#define IOPIN_P0_16                0x10000 /* Bit 16: P0_16 (Port 0.16) */
#define IOPIN_P0_16_LOW            0x00   /* Low */
#define IOPIN_P0_16_HIGH           0x01   /* High */

#define IOPIN_P0_15                0x8000 /* Bit 15: P0_15 (Port 0.15) */
#define IOPIN_P0_15_LOW            0x00   /* Low */
#define IOPIN_P0_15_HIGH           0x01   /* High */

#define IOPIN_P0_14                0x4000 /* Bit 14: P0_14 (Port 0.14) */
#define IOPIN_P0_14_LOW            0x00   /* Low */
#define IOPIN_P0_14_HIGH           0x01   /* High */

#define IOPIN_P0_13                0x2000 /* Bit 13: P0_13 (Port 0.13) */
#define IOPIN_P0_13_LOW            0x00   /* Low */
#define IOPIN_P0_13_HIGH           0x01   /* High */

#define IOPIN_P0_12                0x1000 /* Bit 12: P0_12 (Port 0.12) */
#define IOPIN_P0_12_LOW            0x00   /* Low */
#define IOPIN_P0_12_HIGH           0x01   /* High */

#define IOPIN_P0_11                0x800  /* Bit 11: P0_11 (Port 0.11) */
#define IOPIN_P0_11_LOW            0x00   /* Low */
#define IOPIN_P0_11_HIGH           0x01   /* High */

#define IOPIN_P0_10                0x400  /* Bit 10: P0_10 (Port 0.10) */
#define IOPIN_P0_10_LOW            0x00   /* Low */
#define IOPIN_P0_10_HIGH           0x01   /* High */

#define IOPIN_P0_9                 0x200  /* Bit 9: P0_9 (Port 0.9) */
#define IOPIN_P0_9_LOW             0x00   /* Low */
#define IOPIN_P0_9_HIGH            0x01   /* High */

#define IOPIN_P0_8                 0x100  /* Bit 8: P0_8 (Port 0.8) */
#define IOPIN_P0_8_LOW             0x00   /* Low */
#define IOPIN_P0_8_HIGH            0x01   /* High */

#define IOPIN_P0_7                 0x80   /* Bit 7: P0_7 (Port 0.7) */
#define IOPIN_P0_7_LOW             0x00   /* Low */
#define IOPIN_P0_7_HIGH            0x01   /* High */

#define IOPIN_P0_6                 0x40   /* Bit 6: P0_6 (Port 0.6) */
#define IOPIN_P0_6_LOW             0x00   /* Low */
#define IOPIN_P0_6_HIGH            0x01   /* High */

#define IOPIN_P0_5                 0x20   /* Bit 5: P0_5 (Port 0.5) */
#define IOPIN_P0_5_LOW             0x00   /* Low */
#define IOPIN_P0_5_HIGH            0x01   /* High */

#define IOPIN_P0_4                 0x10   /* Bit 4: P0_4 (Port 0.4) */
#define IOPIN_P0_4_LOW             0x00   /* Low */
#define IOPIN_P0_4_HIGH            0x01   /* High */

#define IOPIN_P0_3                 0x08   /* Bit 3: P0_3 (Port 0.3) */
#define IOPIN_P0_3_LOW             0x00   /* Low */
#define IOPIN_P0_3_HIGH            0x01   /* High */

#define IOPIN_P0_2                 0x04   /* Bit 2: P0_2 (Port 0.2) */
#define IOPIN_P0_2_LOW             0x00   /* Low */
#define IOPIN_P0_2_HIGH            0x01   /* High */

#define IOPIN_P0_1                 0x02   /* Bit 1: P0_1 (Port 0.1) */
#define IOPIN_P0_1_LOW             0x00   /* Low */
#define IOPIN_P0_1_HIGH            0x01   /* High */

#define IOPIN_P0_0                 0x01   /* Bit 0: P0_0 (Port 0.0) */
#define IOPIN_P0_0_LOW             0x00   /* Low */
#define IOPIN_P0_0_HIGH            0x01   /* High */


/*
**---------------------------------------------------------------------------
**  GPIO Output Set Register
**---------------------------------------------------------------------------
*/

#define IOSET_P0_31                0x80000000 /* Bit 31: P0_31 (Port 0.31) */
#define IOSET_P0_31_LOW            0x00   /* Low */
#define IOSET_P0_31_HIGH           0x01   /* High */

#define IOSET_P0_30                0x40000000 /* Bit 30: P0_30 (Port 0.30) */
#define IOSET_P0_30_LOW            0x00   /* Low */
#define IOSET_P0_30_HIGH           0x01   /* High */

#define IOSET_P0_29                0x20000000 /* Bit 29: P0_29 (Port 0.29) */
#define IOSET_P0_29_LOW            0x00   /* Low */
#define IOSET_P0_29_HIGH           0x01   /* High */

#define IOSET_P0_28                0x10000000 /* Bit 28: P0_28 (Port 0.28) */
#define IOSET_P0_28_LOW            0x00   /* Low */
#define IOSET_P0_28_HIGH           0x01   /* High */

#define IOSET_P0_27                0x8000000 /* Bit 27: P0_27 (Port 0.27) */
#define IOSET_P0_27_LOW            0x00   /* Low */
#define IOSET_P0_27_HIGH           0x01   /* High */

#define IOSET_P0_26                0x4000000 /* Bit 26: P0_26 (Port 0.26) */
#define IOSET_P0_26_LOW            0x00   /* Low */
#define IOSET_P0_26_HIGH           0x01   /* High */

#define IOSET_P0_25                0x2000000 /* Bit 25: P0_25 (Port 0.25) */
#define IOSET_P0_25_LOW            0x00   /* Low */
#define IOSET_P0_25_HIGH           0x01   /* High */

#define IOSET_P0_24                0x1000000 /* Bit 24: P0_24 (Port 0.24) */
#define IOSET_P0_24_LOW            0x00   /* Low */
#define IOSET_P0_24_HIGH           0x01   /* High */

#define IOSET_P0_23                0x800000 /* Bit 23: P0_23 (Port 0.23) */
#define IOSET_P0_23_LOW            0x00   /* Low */
#define IOSET_P0_23_HIGH           0x01   /* High */

#define IOSET_P0_22                0x400000 /* Bit 22: P0_22 (Port 0.22) */
#define IOSET_P0_22_LOW            0x00   /* Low */
#define IOSET_P0_22_HIGH           0x01   /* High */

#define IOSET_P0_21                0x200000 /* Bit 21: P0_21 (Port 0.21) */
#define IOSET_P0_21_LOW            0x00   /* Low */
#define IOSET_P0_21_HIGH           0x01   /* High */

#define IOSET_P0_20                0x100000 /* Bit 20: P0_20 (Port 0.20) */
#define IOSET_P0_20_LOW            0x00   /* Low */
#define IOSET_P0_20_HIGH           0x01   /* High */

#define IOSET_P0_19                0x80000 /* Bit 19: P0_19 (Port 0.19) */
#define IOSET_P0_19_LOW            0x00   /* Low */
#define IOSET_P0_19_HIGH           0x01   /* High */

#define IOSET_P0_18                0x40000 /* Bit 18: P0_18 (Port 0.18) */
#define IOSET_P0_18_LOW            0x00   /* Low */
#define IOSET_P0_18_HIGH           0x01   /* High */

#define IOSET_P0_17                0x20000 /* Bit 17: P0_17 (Port 0.17) */
#define IOSET_P0_17_LOW            0x00   /* Low */
#define IOSET_P0_17_HIGH           0x01   /* High */

#define IOSET_P0_16                0x10000 /* Bit 16: P0_16 (Port 0.16) */
#define IOSET_P0_16_LOW            0x00   /* Low */
#define IOSET_P0_16_HIGH           0x01   /* High */

#define IOSET_P0_15                0x8000 /* Bit 15: P0_15 (Port 0.15) */
#define IOSET_P0_15_LOW            0x00   /* Low */
#define IOSET_P0_15_HIGH           0x01   /* High */

#define IOSET_P0_14                0x4000 /* Bit 14: P0_14 (Port 0.14) */
#define IOSET_P0_14_LOW            0x00   /* Low */
#define IOSET_P0_14_HIGH           0x01   /* High */

#define IOSET_P0_13                0x2000 /* Bit 13: P0_13 (Port 0.13) */
#define IOSET_P0_13_LOW            0x00   /* Low */
#define IOSET_P0_13_HIGH           0x01   /* High */

#define IOSET_P0_12                0x1000 /* Bit 12: P0_12 (Port 0.12) */
#define IOSET_P0_12_LOW            0x00   /* Low */
#define IOSET_P0_12_HIGH           0x01   /* High */

#define IOSET_P0_11                0x800  /* Bit 11: P0_11 (Port 0.11) */
#define IOSET_P0_11_LOW            0x00   /* Low */
#define IOSET_P0_11_HIGH           0x01   /* High */

#define IOSET_P0_10                0x400  /* Bit 10: P0_10 (Port 0.10) */
#define IOSET_P0_10_LOW            0x00   /* Low */
#define IOSET_P0_10_HIGH           0x01   /* High */

#define IOSET_P0_9                 0x200  /* Bit 9: P0_9 (Port 0.9) */
#define IOSET_P0_9_LOW             0x00   /* Low */
#define IOSET_P0_9_HIGH            0x01   /* High */

#define IOSET_P0_8                 0x100  /* Bit 8: P0_8 (Port 0.8) */
#define IOSET_P0_8_LOW             0x00   /* Low */
#define IOSET_P0_8_HIGH            0x01   /* High */

#define IOSET_P0_7                 0x80   /* Bit 7: P0_7 (Port 0.7) */
#define IOSET_P0_7_LOW             0x00   /* Low */
#define IOSET_P0_7_HIGH            0x01   /* High */

#define IOSET_P0_6                 0x40   /* Bit 6: P0_6 (Port 0.6) */
#define IOSET_P0_6_LOW             0x00   /* Low */
#define IOSET_P0_6_HIGH            0x01   /* High */

#define IOSET_P0_5                 0x20   /* Bit 5: P0_5 (Port 0.5) */
#define IOSET_P0_5_LOW             0x00   /* Low */
#define IOSET_P0_5_HIGH            0x01   /* High */

#define IOSET_P0_4                 0x10   /* Bit 4: P0_4 (Port 0.4) */
#define IOSET_P0_4_LOW             0x00   /* Low */
#define IOSET_P0_4_HIGH            0x01   /* High */

#define IOSET_P0_3                 0x08   /* Bit 3: P0_3 (Port 0.3) */
#define IOSET_P0_3_LOW             0x00   /* Low */
#define IOSET_P0_3_HIGH            0x01   /* High */

#define IOSET_P0_2                 0x04   /* Bit 2: P0_2 (Port 0.2) */
#define IOSET_P0_2_LOW             0x00   /* Low */
#define IOSET_P0_2_HIGH            0x01   /* High */

#define IOSET_P0_1                 0x02   /* Bit 1: P0_1 (Port 0.1) */
#define IOSET_P0_1_LOW             0x00   /* Low */
#define IOSET_P0_1_HIGH            0x01   /* High */

#define IOSET_P0_0                 0x01   /* Bit 0: P0_0 (Port 0.0) */
#define IOSET_P0_0_LOW             0x00   /* Low */
#define IOSET_P0_0_HIGH            0x01   /* High */


/*
**---------------------------------------------------------------------------
**  GPIO Direction Register
**---------------------------------------------------------------------------
*/

#define IODIR_P0_31                0x80000000 /* Bit 31: P0_31 (Port 0.31) */
#define IODIR_P0_31_INPUT          0x00   /* Input */
#define IODIR_P0_31_OUTPUT         0x01   /* Output */

#define IODIR_P0_30                0x40000000 /* Bit 30: P0_30 (Port 0.30) */
#define IODIR_P0_30_INPUT          0x00   /* Input */
#define IODIR_P0_30_OUTPUT         0x01   /* Output */

#define IODIR_P0_29                0x20000000 /* Bit 29: P0_29 (Port 0.29) */
#define IODIR_P0_29_INPUT          0x00   /* Input */
#define IODIR_P0_29_OUTPUT         0x01   /* Output */

#define IODIR_P0_28                0x10000000 /* Bit 28: P0_28 (Port 0.28) */
#define IODIR_P0_28_INPUT          0x00   /* Input */
#define IODIR_P0_28_OUTPUT         0x01   /* Output */

#define IODIR_P0_27                0x8000000 /* Bit 27: P0_27 (Port 0.27) */
#define IODIR_P0_27_INPUT          0x00   /* Input */
#define IODIR_P0_27_OUTPUT         0x01   /* Output */

#define IODIR_P0_26                0x4000000 /* Bit 26: P0_26 (Port 0.26) */
#define IODIR_P0_26_INPUT          0x00   /* Input */
#define IODIR_P0_26_OUTPUT         0x01   /* Output */

#define IODIR_P0_25                0x2000000 /* Bit 25: P0_25 (Port 0.25) */
#define IODIR_P0_25_INPUT          0x00   /* Input */
#define IODIR_P0_25_OUTPUT         0x01   /* Output */

#define IODIR_P0_24                0x1000000 /* Bit 24: P0_24 (Port 0.24) */
#define IODIR_P0_24_INPUT          0x00   /* Input */
#define IODIR_P0_24_OUTPUT         0x01   /* Output */

#define IODIR_P0_23                0x800000 /* Bit 23: P0_23 (Port 0.23) */
#define IODIR_P0_23_INPUT          0x00   /* Input */
#define IODIR_P0_23_OUTPUT         0x01   /* Output */

#define IODIR_P0_22                0x400000 /* Bit 22: P0_22 (Port 0.22) */
#define IODIR_P0_22_INPUT          0x00   /* Input */
#define IODIR_P0_22_OUTPUT         0x01   /* Output */

#define IODIR_P0_21                0x200000 /* Bit 21: P0_21 (Port 0.21) */
#define IODIR_P0_21_INPUT          0x00   /* Input */
#define IODIR_P0_21_OUTPUT         0x01   /* Output */

#define IODIR_P0_20                0x100000 /* Bit 20: P0_20 (Port 0.20) */
#define IODIR_P0_20_INPUT          0x00   /* Input */
#define IODIR_P0_20_OUTPUT         0x01   /* Output */

#define IODIR_P0_19                0x80000 /* Bit 19: P0_19 (Port 0.19) */
#define IODIR_P0_19_INPUT          0x00   /* Input */
#define IODIR_P0_19_OUTPUT         0x01   /* Output */

#define IODIR_P0_18                0x40000 /* Bit 18: P0_18 (Port 0.18) */
#define IODIR_P0_18_INPUT          0x00   /* Input */
#define IODIR_P0_18_OUTPUT         0x01   /* Output */

#define IODIR_P0_17                0x20000 /* Bit 17: P0_17 (Port 0.17) */
#define IODIR_P0_17_INPUT          0x00   /* Input */
#define IODIR_P0_17_OUTPUT         0x01   /* Output */

#define IODIR_P0_16                0x10000 /* Bit 16: P0_16 (Port 0.16) */
#define IODIR_P0_16_INPUT          0x00   /* Input */
#define IODIR_P0_16_OUTPUT         0x01   /* Output */

#define IODIR_P0_15                0x8000 /* Bit 15: P0_15 (Port 0.15) */
#define IODIR_P0_15_INPUT          0x00   /* Input */
#define IODIR_P0_15_OUTPUT         0x01   /* Output */

#define IODIR_P0_14                0x4000 /* Bit 14: P0_14 (Port 0.14) */
#define IODIR_P0_14_INPUT          0x00   /* Input */
#define IODIR_P0_14_OUTPUT         0x01   /* Output */

#define IODIR_P0_13                0x2000 /* Bit 13: P0_13 (Port 0.13) */
#define IODIR_P0_13_INPUT          0x00   /* Input */
#define IODIR_P0_13_OUTPUT         0x01   /* Output */

#define IODIR_P0_12                0x1000 /* Bit 12: P0_12 (Port 0.12) */
#define IODIR_P0_12_INPUT          0x00   /* Input */
#define IODIR_P0_12_OUTPUT         0x01   /* Output */

#define IODIR_P0_11                0x800  /* Bit 11: P0_11 (Port 0.11) */
#define IODIR_P0_11_INPUT          0x00   /* Input */
#define IODIR_P0_11_OUTPUT         0x01   /* Output */

#define IODIR_P0_10                0x400  /* Bit 10: P0_10 (Port 0.10) */
#define IODIR_P0_10_INPUT          0x00   /* Input */
#define IODIR_P0_10_OUTPUT         0x01   /* Output */

#define IODIR_P0_9                 0x200  /* Bit 9: P0_9 (Port 0.9) */
#define IODIR_P0_9_INPUT           0x00   /* Input */
#define IODIR_P0_9_OUTPUT          0x01   /* Output */

#define IODIR_P0_8                 0x100  /* Bit 8: P0_8 (Port 0.8) */
#define IODIR_P0_8_INPUT           0x00   /* Input */
#define IODIR_P0_8_OUTPUT          0x01   /* Output */

#define IODIR_P0_7                 0x80   /* Bit 7: P0_7 (Port 0.7) */
#define IODIR_P0_7_INPUT           0x00   /* Input */
#define IODIR_P0_7_OUTPUT          0x01   /* Output */

#define IODIR_P0_6                 0x40   /* Bit 6: P0_6 (Port 0.6) */
#define IODIR_P0_6_INPUT           0x00   /* Input */
#define IODIR_P0_6_OUTPUT          0x01   /* Output */

#define IODIR_P0_5                 0x20   /* Bit 5: P0_5 (Port 0.5) */
#define IODIR_P0_5_INPUT           0x00   /* Input */
#define IODIR_P0_5_OUTPUT          0x01   /* Output */

#define IODIR_P0_4                 0x10   /* Bit 4: P0_4 (Port 0.4) */
#define IODIR_P0_4_INPUT           0x00   /* Input */
#define IODIR_P0_4_OUTPUT          0x01   /* Output */

#define IODIR_P0_3                 0x08   /* Bit 3: P0_3 (Port 0.3) */
#define IODIR_P0_3_INPUT           0x00   /* Input */
#define IODIR_P0_3_OUTPUT          0x01   /* Output */

#define IODIR_P0_2                 0x04   /* Bit 2: P0_2 (Port 0.2) */
#define IODIR_P0_2_INPUT           0x00   /* Input */
#define IODIR_P0_2_OUTPUT          0x01   /* Output */

#define IODIR_P0_1                 0x02   /* Bit 1: P0_1 (Port 0.1) */
#define IODIR_P0_1_INPUT           0x00   /* Input */
#define IODIR_P0_1_OUTPUT          0x01   /* Output */

#define IODIR_P0_0                 0x01   /* Bit 0: P0_0 (Port 0.0) */
#define IODIR_P0_0_INPUT           0x00   /* Input */
#define IODIR_P0_0_OUTPUT          0x01   /* Output */


/*
**---------------------------------------------------------------------------
**  GPIO output set register
**---------------------------------------------------------------------------
*/

#define IOCLR_P0_31                0x80000000 /* Bit 31: P0_31 (Port 0.31) */
#define IOCLR_P0_31_LOW            0x00   /* Low */
#define IOCLR_P0_31_HIGH           0x01   /* High */

#define IOCLR_P0_30                0x40000000 /* Bit 30: P0_30 (Port 0.30) */
#define IOCLR_P0_30_LOW            0x00   /* Low */
#define IOCLR_P0_30_HIGH           0x01   /* High */

#define IOCLR_P0_29                0x20000000 /* Bit 29: P0_29 (Port 0.29) */
#define IOCLR_P0_29_LOW            0x00   /* Low */
#define IOCLR_P0_29_HIGH           0x01   /* High */

#define IOCLR_P0_28                0x10000000 /* Bit 28: P0_28 (Port 0.28) */
#define IOCLR_P0_28_LOW            0x00   /* Low */
#define IOCLR_P0_28_HIGH           0x01   /* High */

#define IOCLR_P0_27                0x8000000 /* Bit 27: P0_27 (Port 0.27) */
#define IOCLR_P0_27_LOW            0x00   /* Low */
#define IOCLR_P0_27_HIGH           0x01   /* High */

#define IOCLR_P0_26                0x4000000 /* Bit 26: P0_26 (Port 0.26) */
#define IOCLR_P0_26_LOW            0x00   /* Low */
#define IOCLR_P0_26_HIGH           0x01   /* High */

#define IOCLR_P0_25                0x2000000 /* Bit 25: P0_25 (Port 0.25) */
#define IOCLR_P0_25_LOW            0x00   /* Low */
#define IOCLR_P0_25_HIGH           0x01   /* High */

#define IOCLR_P0_24                0x1000000 /* Bit 24: P0_24 (Port 0.24) */
#define IOCLR_P0_24_LOW            0x00   /* Low */
#define IOCLR_P0_24_HIGH           0x01   /* High */

#define IOCLR_P0_23                0x800000 /* Bit 23: P0_23 (Port 0.23) */
#define IOCLR_P0_23_LOW            0x00   /* Low */
#define IOCLR_P0_23_HIGH           0x01   /* High */

#define IOCLR_P0_22                0x400000 /* Bit 22: P0_22 (Port 0.22) */
#define IOCLR_P0_22_LOW            0x00   /* Low */
#define IOCLR_P0_22_HIGH           0x01   /* High */

#define IOCLR_P0_21                0x200000 /* Bit 21: P0_21 (Port 0.21) */
#define IOCLR_P0_21_LOW            0x00   /* Low */
#define IOCLR_P0_21_HIGH           0x01   /* High */

#define IOCLR_P0_20                0x100000 /* Bit 20: P0_20 (Port 0.20) */
#define IOCLR_P0_20_LOW            0x00   /* Low */
#define IOCLR_P0_20_HIGH           0x01   /* High */

#define IOCLR_P0_19                0x80000 /* Bit 19: P0_19 (Port 0.19) */
#define IOCLR_P0_19_LOW            0x00   /* Low */
#define IOCLR_P0_19_HIGH           0x01   /* High */

#define IOCLR_P0_18                0x40000 /* Bit 18: P0_18 (Port 0.18) */
#define IOCLR_P0_18_LOW            0x00   /* Low */
#define IOCLR_P0_18_HIGH           0x01   /* High */

#define IOCLR_P0_17                0x20000 /* Bit 17: P0_17 (Port 0.17) */
#define IOCLR_P0_17_LOW            0x00   /* Low */
#define IOCLR_P0_17_HIGH           0x01   /* High */

#define IOCLR_P0_16                0x10000 /* Bit 16: P0_16 (Port 0.16) */
#define IOCLR_P0_16_LOW            0x00   /* Low */
#define IOCLR_P0_16_HIGH           0x01   /* High */

#define IOCLR_P0_15                0x8000 /* Bit 15: P0_15 (Port 0.15) */
#define IOCLR_P0_15_LOW            0x00   /* Low */
#define IOCLR_P0_15_HIGH           0x01   /* High */

#define IOCLR_P0_14                0x4000 /* Bit 14: P0_14 (Port 0.14) */
#define IOCLR_P0_14_LOW            0x00   /* Low */
#define IOCLR_P0_14_HIGH           0x01   /* High */

#define IOCLR_P0_13                0x2000 /* Bit 13: P0_13 (Port 0.13) */
#define IOCLR_P0_13_LOW            0x00   /* Low */
#define IOCLR_P0_13_HIGH           0x01   /* High */

#define IOCLR_P0_12                0x1000 /* Bit 12: P0_12 (Port 0.12) */
#define IOCLR_P0_12_LOW            0x00   /* Low */
#define IOCLR_P0_12_HIGH           0x01   /* High */

#define IOCLR_P0_11                0x800  /* Bit 11: P0_11 (Port 0.11) */
#define IOCLR_P0_11_LOW            0x00   /* Low */
#define IOCLR_P0_11_HIGH           0x01   /* High */

#define IOCLR_P0_10                0x400  /* Bit 10: P0_10 (Port 0.10) */
#define IOCLR_P0_10_LOW            0x00   /* Low */
#define IOCLR_P0_10_HIGH           0x01   /* High */

#define IOCLR_P0_9                 0x200  /* Bit 9: P0_9 (Port 0.9) */
#define IOCLR_P0_9_LOW             0x00   /* Low */
#define IOCLR_P0_9_HIGH            0x01   /* High */

#define IOCLR_P0_8                 0x100  /* Bit 8: P0_8 (Port 0.8) */
#define IOCLR_P0_8_LOW             0x00   /* Low */
#define IOCLR_P0_8_HIGH            0x01   /* High */

#define IOCLR_P0_7                 0x80   /* Bit 7: P0_7 (Port 0.7) */
#define IOCLR_P0_7_LOW             0x00   /* Low */
#define IOCLR_P0_7_HIGH            0x01   /* High */

#define IOCLR_P0_6                 0x40   /* Bit 6: P0_6 (Port 0.6) */
#define IOCLR_P0_6_LOW             0x00   /* Low */
#define IOCLR_P0_6_HIGH            0x01   /* High */

#define IOCLR_P0_5                 0x20   /* Bit 5: P0_5 (Port 0.5) */
#define IOCLR_P0_5_LOW             0x00   /* Low */
#define IOCLR_P0_5_HIGH            0x01   /* High */

#define IOCLR_P0_4                 0x10   /* Bit 4: P0_4 (Port 0.4) */
#define IOCLR_P0_4_LOW             0x00   /* Low */
#define IOCLR_P0_4_HIGH            0x01   /* High */

#define IOCLR_P0_3                 0x08   /* Bit 3: P0_3 (Port 0.3) */
#define IOCLR_P0_3_LOW             0x00   /* Low */
#define IOCLR_P0_3_HIGH            0x01   /* High */

#define IOCLR_P0_2                 0x04   /* Bit 2: P0_2 (Port 0.2) */
#define IOCLR_P0_2_LOW             0x00   /* Low */
#define IOCLR_P0_2_HIGH            0x01   /* High */

#define IOCLR_P0_1                 0x02   /* Bit 1: P0_1 (Port 0.1) */
#define IOCLR_P0_1_LOW             0x00   /* Low */
#define IOCLR_P0_1_HIGH            0x01   /* High */

#define IOCLR_P0_0                 0x01   /* Bit 0: P0_0 (Port 0.0) */
#define IOCLR_P0_0_LOW             0x00   /* Low */
#define IOCLR_P0_0_HIGH            0x01   /* High */


/*
**---------------------------------------------------------------------------
**  Pin Function Select Register 0
**---------------------------------------------------------------------------
*/

#define PINSEL0_P0_15              0xc0000000 /* Bit 31-30: P0_15 (Port 0.15) */
#define PINSEL0_P0_15_PORT0_15     0x00   /* GPIO Port 0.15 */
#define PINSEL0_P0_15_RI1          0x01   /* RI1 (UART1) */
#define PINSEL0_P0_15_EINT2        0x02   /* EINT2 (INTR) */

#define PINSEL0_P0_14              0x30000000 /* Bit 29-28: P0_14 (Port 0.14) */
#define PINSEL0_P0_14_PORT0_14     0x00   /* GPIO Port 0.14 */
#define PINSEL0_P0_14_DCD1         0x01   /* DCD1 (UART1) */
#define PINSEL0_P0_14_EINT1        0x02   /* EINT1 (INTR) */

#define PINSEL0_P0_13              0xc000000 /* Bit 27-26: P0_13 (Port 0.13) */
#define PINSEL0_P0_13_PORT0_13     0x00   /* GPIO Port 0.13 */
#define PINSEL0_P0_13_DTR1         0x01   /* DTR1 (UART1) */
#define PINSEL0_P0_13_MAT1_1       0x02   /* Match 1.1 (Timer 1) */

#define PINSEL0_P0_12              0x3000000 /* Bit 25-24: P0_12 (Port 0.12) */
#define PINSEL0_P0_12_PORT0_12     0x00   /* GPIO Port 0.12 */
#define PINSEL0_P0_12_DSR1         0x01   /* DSR1 (UART1) */
#define PINSEL0_P0_12_MAT1_0       0x02   /* Match 1.0 (Timer 1) */

#define PINSEL0_P0_11              0xc00000 /* Bit 23-22: P0_11 (Port 0.11) */
#define PINSEL0_P0_11_PORT0_11     0x00   /* GPIO Port 0.11 */
#define PINSEL0_P0_11_CTS1         0x01   /* CTS1 (UART1) */
#define PINSEL0_P0_11_CAP1_1       0x02   /* Capture 1.1 (Timer 1) */

#define PINSEL0_P0_10              0x300000 /* Bit 21-20: P0_10 (Port 0.10) */
#define PINSEL0_P0_10_PORT0_10     0x00   /* GPIO Port 0.10 */
#define PINSEL0_P0_10_RTS1         0x01   /* RTS1  (UART1) */
#define PINSEL0_P0_10_CAP1_0       0x02   /* Capture 1.0 (Timer 1) */

#define PINSEL0_P0_9               0xc0000 /* Bit 19-18: P0_9 (Port 0.9) */
#define PINSEL0_P0_9_PORT0_9       0x00   /* GPIO Port 0.9 */
#define PINSEL0_P0_9_RXD1          0x01   /* RxD1 (UART1) */
#define PINSEL0_P0_9_PWM6          0x02   /* PWM6 */

#define PINSEL0_P0_8               0x30000 /* Bit 17-16: P0_8 (Port 0.8) */
#define PINSEL0_P0_8_PORT0_8       0x00   /* GPIO Port 0.8 */
#define PINSEL0_P0_8_TXD1          0x01   /* TxD1 (UART1) */
#define PINSEL0_P0_8_PWM4          0x02   /* PWM4 */

#define PINSEL0_P0_7               0xc000 /* Bit 15-14: P0_7 (Port 0.7) */
#define PINSEL0_P0_7_PORT0_7       0x00   /* GPIO Port 0.7 */
#define PINSEL0_P0_7_SSEL          0x01   /* SSEL (SPI) */
#define PINSEL0_P0_7_PWM2          0x02   /* PWM2 */

#define PINSEL0_P0_6               0x3000 /* Bit 13-12: P0_6 (Port 0.6) */
#define PINSEL0_P0_6_PORT0_6       0x00   /* GPIO Port 0.6 */
#define PINSEL0_P0_6_MOSI          0x01   /* MOSI (SPI) */
#define PINSEL0_P0_6_CAP0_2        0x02   /* Capture 0.2 (Timer 0) */

#define PINSEL0_P0_5               0xc00  /* Bit 11-10: P0_5 (Port 0.5) */
#define PINSEL0_P0_5_PORT0_5       0x00   /* GPIO Port 0.5 */
#define PINSEL0_P0_5_MISO          0x01   /* MISO (SPI) */
#define PINSEL0_P0_5_MAT0_1        0x02   /* Match 0.1 (Timer 0) */

#define PINSEL0_P0_4               0x300  /* Bit 9-8: P0_4 (Port 0.4) */
#define PINSEL0_P0_4_PORT0_4       0x00   /* GPIO Port 0.4 */
#define PINSEL0_P0_4_SCK           0x01   /* SCK (SPI) */
#define PINSEL0_P0_4_CAP0_1        0x02   /* Capture 0.1 (Timer 0) */

#define PINSEL0_P0_3               0xc0   /* Bit 7-6: P0_3 (Port 0.3) */
#define PINSEL0_P0_3_PORT0_3       0x00   /* GPIO Port 0.3 */
#define PINSEL0_P0_3_SDA           0x01   /* SDA (I2C) */
#define PINSEL0_P0_3_MAT0_0        0x02   /* Match 0.0 (Timer 0) */

#define PINSEL0_P0_2               0x30   /* Bit 5-4: P0_2 (Port 0.2) */
#define PINSEL0_P0_2_PORT0_2       0x00   /* GPIO Port 0.2 */
#define PINSEL0_P0_2_SCL           0x01   /* SCL (I2C) */
#define PINSEL0_P0_2_CAP0_0        0x02   /* Capture 0.0 (Timer 0) */

#define PINSEL0_P0_1               0x0c   /* Bit 3-2: P0_1 (Port 0.1) */
#define PINSEL0_P0_1_PORT0_1       0x00   /* GPIO Port 0.1 */
#define PINSEL0_P0_1_RXD0          0x01   /* RxD0 (UART0) */
#define PINSEL0_P0_1_PWM3          0x02   /* PWM3 */

#define PINSEL0_P0_0               0x03   /* Bit 1-0: P0_0 (Port 0.0) */
#define PINSEL0_P0_0_PORT0_0       0x00   /* GPIO Port 0.0 */
#define PINSEL0_P0_0_TXD0          0x01   /* TxD0 (UART0) */
#define PINSEL0_P0_0_PWM1          0x02   /* PWM1 */


/*
**---------------------------------------------------------------------------
**  Pin Function Select Register 1
**---------------------------------------------------------------------------
*/

#define PINSEL1_P0_31              0xc0000000 /* Bit 31-30: P0_31 (Port 0.31) */
#define PINSEL1_P0_31_PORT0_31     0x00   /* GPIO Port 0.31 */
#define PINSEL1_P0_31_TDO          0x01   /* TDO (JTAG) */

#define PINSEL1_P0_30              0x30000000 /* Bit 29-28: P0_30 (Port 0.30) */
#define PINSEL1_P0_30_PORT0_30     0x00   /* GPIO Port 0.30 */
#define PINSEL1_P0_30_TDI          0x01   /* TDI (JTAG) */

#define PINSEL1_P0_29              0xc000000 /* Bit 27-26: P0_29 (Port 0.29) */
#define PINSEL1_P0_29_PORT0_29     0x00   /* GPIO Port 0.29 */
#define PINSEL1_P0_29_TCK          0x01   /* TCK (JTAG) */

#define PINSEL1_P0_28              0x3000000 /* Bit 25-24: P0_28 (Port 0.28) */
#define PINSEL1_P0_28_PORT0_28     0x00   /* GPIO Port 0.28 */
#define PINSEL1_P0_28_TMS          0x01   /* TMS (JTAG) */

#define PINSEL1_P0_27              0xc00000 /* Bit 23-22: P0_27 (Port 0.27) */
#define PINSEL1_P0_27_PORT0_27     0x00   /* GPIO Port 0.27 */
#define PINSEL1_P0_27_TRST         0x01   /* TRST (JTAG) */

#define PINSEL1_P0_26              0x300000 /* Bit 21-20: P0_26 (Port 0.26) */
#define PINSEL1_P0_26_PORT0_26     0x00   /* GPIO Port 0.26 */

#define PINSEL1_P0_25              0xc0000 /* Bit 19-18: P0_25 (Port 0.25) */
#define PINSEL1_P0_25_PORT0_25     0x00   /* GPIO Port 0.25 */

#define PINSEL1_P0_24              0x30000 /* Bit 17-16: P0_24 (Port 0.24) */
#define PINSEL1_P0_24_PORT0_24     0x00   /* GPIO Port 0.24 */

#define PINSEL1_P0_23              0xc000 /* Bit 15-14: P0_23 (Port 0.23) */
#define PINSEL1_P0_23_PORT0_23     0x00   /* GPIO Port 0.23 */

#define PINSEL1_P0_22              0x3000 /* Bit 13-12: P0_22 (Port 0.22) */
#define PINSEL1_P0_22_PORT0_22     0x00   /* GPIO Port 0.22 */

#define PINSEL1_P0_21              0xc00  /* Bit 11-10: P0_21 (Port 0.21) */
#define PINSEL1_P0_21_PORT0_21     0x00   /* GPIO Port 0.21 */
#define PINSEL1_P0_21_PWM5         0x01   /* PWM5 */

#define PINSEL1_P0_20              0x300  /* Bit 9-8: P0_20 (Port 0.20) */
#define PINSEL1_P0_20_PORT0_20     0x00   /* GPIO Port 0.20 */
#define PINSEL1_P0_20_MAT1_3       0x01   /* Match 1.3 (Timer 1) */

#define PINSEL1_P0_19              0xc0   /* Bit 7-6: P0_19 (Port 0.19) */
#define PINSEL1_P0_19_PORT0_19     0x00   /* GPIO Port 0.19 */
#define PINSEL1_P0_19_MAT1_2       0x01   /* Match 1.2 (Timer 1) */

#define PINSEL1_P0_18              0x30   /* Bit 5-4: P0_18 (Port 0.18) */
#define PINSEL1_P0_18_PORT0_18     0x00   /* GPIO Port 0.18 */
#define PINSEL1_P0_18_CAP1_3       0x01   /* Capture 1.3 (Timer 1) */

#define PINSEL1_P0_17              0x0c   /* Bit 3-2: P0_17 (Port 0.17) */
#define PINSEL1_P0_17_PORT0_17     0x00   /* GPIO Port 0.17 */
#define PINSEL1_P0_17_CAP1_2       0x01   /* Capture 1.2 (Timer 1) */

#define PINSEL1_P0_16              0x03   /* Bit 1-0: P0_16 (Port 0.16) */
#define PINSEL1_P0_16_PORT0_16     0x00   /* GPIO Port 0.16 */
#define PINSEL1_P0_16_EINT0        0x01   /* EINT0 (INTR) */
#define PINSEL1_P0_16_MAT0_2       0x02   /* Match 0.2 (Timer 0) */


/*
**---------------------------------------------------------------------------
**  MAM Control Register
**---------------------------------------------------------------------------
*/

#define MAMCR_MODECTRL             0x03   /* Bit 1-0: MODECTRL (MAM mode control) */
#define MAMCR_MODECTRL_DISABLED    0x00   /* MAM disabled */
#define MAMCR_MODECTRL_PARTIALLY   0x01   /* MAM partially enabled */
#define MAMCR_MODECTRL_ENABLED     0x02   /* MAM fully enabled */


/*
**---------------------------------------------------------------------------
**  MAM Timing Control Register
**---------------------------------------------------------------------------
*/

#define MAMTIM_CYCLES              0x07   /* Bit 2-0: CYCLES (MAM fetch cycle timing) */
#define MAMTIM_CYCLES_ONE          0x01   /* 1 processor clock */
#define MAMTIM_CYCLES_TWO          0x02   /* 2 processor clock */
#define MAMTIM_CYCLES_THREE        0x03   /* 3 processor clock */
#define MAMTIM_CYCLES_FOUR         0x04   /* 4 processor clock */
#define MAMTIM_CYCLES_FIVE         0x05   /* 5 processor clock */
#define MAMTIM_CYCLES_SIX          0x06   /* 6 processor clock */
#define MAMTIM_CYCLES_SEVEN        0x07   /* 7 processor clock */


/*
**---------------------------------------------------------------------------
**  Memory Mapping Control Register
**---------------------------------------------------------------------------
*/

#define MEMMAP_MAP                 0x03   /* Bit 1-0: MAP (Memory map control) */
#define MEMMAP_MAP_BOOT            0x00   /* Boot loader mode */
#define MEMMAP_MAP_FLASH           0x01   /* Flash mode */
#define MEMMAP_MAP_RAM             0x02   /* RAM mode */


/*
**---------------------------------------------------------------------------
**  PLL Control Register
**---------------------------------------------------------------------------
*/

#define PLLCON_PLLC                0x02   /* Bit 1: PLLC (PLL Connect) */
#define PLLCON_PLLC_DISCONNECTED   0x00   /* Disconnected */
#define PLLCON_PLLC_CONNECTED      0x01   /* Connected */

#define PLLCON_PLLE                0x01   /* Bit 0: PLLE (PLL Enabled) */
#define PLLCON_PLLE_DISABLED       0x00   /* Disabled */
#define PLLCON_PLLE_ENABLED        0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  PLL Configuration Register
**---------------------------------------------------------------------------
*/

#define PLLCFG_PSEL                0x60   /* Bit 6-5: PSEL (PLL Divider value) */

#define PLLCFG_MSEL                0x1f   /* Bit 4-0: MSEL (PLL Multiplier value) */


/*
**---------------------------------------------------------------------------
**  PLL Status Register
**---------------------------------------------------------------------------
*/

#define PLLSTAT_PLOCK              0x400  /* Bit 10: PLOCK (PLL Lock status) */
#define PLLSTAT_PLOCK_UNLOCKED     0x00   /* Unlocked */
#define PLLSTAT_PLOCK_LOCKED       0x01   /* Locked */

#define PLLSTAT_PLLC               0x200  /* Bit 9: PLLC (PLL Connect) */
#define PLLSTAT_PLLC_DISCONNECTED  0x00   /* Disconnected */
#define PLLSTAT_PLLC_CONNECTED     0x01   /* Connected */

#define PLLSTAT_PLLE               0x100  /* Bit 8: PLLE (PLL Enabled) */
#define PLLSTAT_PLLE_DISABLED      0x00   /* Disabled */
#define PLLSTAT_PLLE_ENABLED       0x01   /* Enabled */

#define PLLSTAT_PSEL               0x60   /* Bit 6-5: PSEL (PLL Divider value) */

#define PLLSTAT_MSEL               0x1f   /* Bit 4-0: MSEL (PLL Multiplier value) */


/*
**---------------------------------------------------------------------------
**  PLL Feed Register
**---------------------------------------------------------------------------
*/

#define PLLFEED_FEED               0xff   /* Bit 7-0: FEED (PLL feed) */


/*
**---------------------------------------------------------------------------
**  Power Control Register
**---------------------------------------------------------------------------
*/

#define PCON_PD                    0x02   /* Bit 1: PD (Power down mode) */
#define PCON_PD_DISABLED           0x00   /* Disabled */
#define PCON_PD_ENABLED            0x01   /* Enabled */

#define PCON_IDL                   0x01   /* Bit 0: IDL (Idle mode) */
#define PCON_IDL_DISABLED          0x00   /* Disabled */
#define PCON_IDL_ENABLED           0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Power Control for Peripherals Register
**---------------------------------------------------------------------------
*/

#define PCONP_PCRTC                0x200  /* Bit 9: PCRTC (Power control RTC) */
#define PCONP_PCRTC_DISABLED       0x00   /* Disabled */
#define PCONP_PCRTC_ENABLED        0x01   /* Enabled */

#define PCONP_PCSPI                0x100  /* Bit 8: PCSPI (Power control SPI) */
#define PCONP_PCSPI_DISABLED       0x00   /* Disabled */
#define PCONP_PCSPI_ENABLED        0x01   /* Enabled */

#define PCONP_PCI2C                0x80   /* Bit 7: PCI2C (Power control I2C) */
#define PCONP_PCI2C_DISABLED       0x00   /* Disabled */
#define PCONP_PCI2C_ENABLED        0x01   /* Enabled */

#define PCONP_PCPWM0               0x20   /* Bit 5: PCPWM0 (Power control PWM0) */
#define PCONP_PCPWM0_DISABLED      0x00   /* Disabled */
#define PCONP_PCPWM0_ENABLED       0x01   /* Enabled */

#define PCONP_PCURT1               0x10   /* Bit 4: PCURT1 (Power control UART1) */
#define PCONP_PCURT1_DISABLED      0x00   /* Disabled */
#define PCONP_PCURT1_ENABLED       0x01   /* Enabled */

#define PCONP_PCURT0               0x08   /* Bit 3: PCURT0 (Power control UART0) */
#define PCONP_PCURT0_DISABLED      0x00   /* Disabled */
#define PCONP_PCURT0_ENABLED       0x01   /* Enabled */

#define PCONP_PCTIM1               0x04   /* Bit 2: PCTIM1 (Power control TIMER1) */
#define PCONP_PCTIM1_DISABLED      0x00   /* Disabled */
#define PCONP_PCTIM1_ENABLED       0x01   /* Enabled */

#define PCONP_PCTIM0               0x02   /* Bit 1: PCTIM0 (Power control TIMER0) */
#define PCONP_PCTIM0_DISABLED      0x00   /* Disabled */
#define PCONP_PCTIM0_ENABLED       0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  VPB Divider Register
**---------------------------------------------------------------------------
*/

#define VPBDIV_VPBDIV              0x03   /* Bit 1-0: VPBDIV (VPB divider) */
#define VPBDIV_VPBDIV_DIV_1        0x01   /* VPB bus clock is same as the processor clock */
#define VPBDIV_VPBDIV_DIV_2        0x02   /* VPB bus clock is 1/2 of the processor clock */
#define VPBDIV_VPBDIV_DIV_4        0x00   /* VPB bus clock is 1/4 of the processor clock */


/*
**---------------------------------------------------------------------------
**  External Interrupt Flag Register
**---------------------------------------------------------------------------
*/

#define EXTINT_EINT2               0x04   /* Bit 2: EINT2 (EINT2 status) */
#define EXTINT_EINT2_NO_INTERRUPT  0x00   /* No interrupt */
#define EXTINT_EINT2_INTERRUPT     0x01   /* Interrupt */

#define EXTINT_EINT1               0x02   /* Bit 1: EINT1 (EINT1 status) */
#define EXTINT_EINT1_NO_INTERRUPT  0x00   /* No interrupt */
#define EXTINT_EINT1_INTERRUPT     0x01   /* Interrupt */

#define EXTINT_EINT0               0x01   /* Bit 0: EINT0 (EINT0 status) */
#define EXTINT_EINT0_NO_INTERRUPT  0x00   /* No interrupt */
#define EXTINT_EINT0_INTERRUPT     0x01   /* Interrupt */


/*
**---------------------------------------------------------------------------
**  External Interrupt Wakeup Register
**---------------------------------------------------------------------------
*/

#define EXTWAKE_EXTWAKE2           0x04   /* Bit 2: EXTWAKE2 (EINT2 wake up) */
#define EXTWAKE_EXTWAKE2_DISABLED  0x00   /* Disabled */
#define EXTWAKE_EXTWAKE2_ENABLED   0x01   /* Enabled */

#define EXTWAKE_EXTWAKE1           0x02   /* Bit 1: EXTWAKE1 (EINT1 wake up) */
#define EXTWAKE_EXTWAKE1_DISABLED  0x00   /* Disabled */
#define EXTWAKE_EXTWAKE1_ENABLED   0x01   /* Enabled */

#define EXTWAKE_EXTWAKE0           0x01   /* Bit 0: EXTWAKE0 (EINT0 wake up) */
#define EXTWAKE_EXTWAKE0_DISABLED  0x00   /* Disabled */
#define EXTWAKE_EXTWAKE0_ENABLED   0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  IRQ Status Register
**---------------------------------------------------------------------------
*/

#define VICIRQSTATUS_INT31         0x80000000 /* Bit 31: INT31 (Interrupt 31) */

#define VICIRQSTATUS_INT30         0x40000000 /* Bit 30: INT30 (Interrupt 30) */

#define VICIRQSTATUS_INT29         0x20000000 /* Bit 29: INT29 (Interrupt 29) */

#define VICIRQSTATUS_INT28         0x10000000 /* Bit 28: INT28 (Interrupt 28) */

#define VICIRQSTATUS_INT27         0x8000000 /* Bit 27: INT27 (Interrupt 27) */

#define VICIRQSTATUS_INT26         0x4000000 /* Bit 26: INT26 (Interrupt 26) */

#define VICIRQSTATUS_INT25         0x2000000 /* Bit 25: INT25 (Interrupt 25) */

#define VICIRQSTATUS_INT24         0x1000000 /* Bit 24: INT24 (Interrupt 24) */

#define VICIRQSTATUS_INT23         0x800000 /* Bit 23: INT23 (Interrupt 23) */

#define VICIRQSTATUS_INT22         0x400000 /* Bit 22: INT22 (Interrupt 22) */

#define VICIRQSTATUS_INT21         0x200000 /* Bit 21: INT21 (Interrupt 21) */

#define VICIRQSTATUS_INT20         0x100000 /* Bit 20: INT20 (Interrupt 20) */

#define VICIRQSTATUS_INT19         0x80000 /* Bit 19: INT19 (Interrupt 19) */

#define VICIRQSTATUS_INT18         0x40000 /* Bit 18: INT18 (Interrupt 18) */

#define VICIRQSTATUS_INT17         0x20000 /* Bit 17: INT17 (Interrupt 17) */

#define VICIRQSTATUS_INT16         0x10000 /* Bit 16: INT16 (Interrupt 16) */

#define VICIRQSTATUS_INT15         0x8000 /* Bit 15: INT15 (Interrupt 15) */

#define VICIRQSTATUS_INT14         0x4000 /* Bit 14: INT14 (Interrupt 14) */

#define VICIRQSTATUS_INT13         0x2000 /* Bit 13: INT13 (Interrupt 13) */

#define VICIRQSTATUS_INT12         0x1000 /* Bit 12: INT12 (Interrupt 12) */

#define VICIRQSTATUS_INT11         0x800  /* Bit 11: INT11 (Interrupt 11) */

#define VICIRQSTATUS_INT10         0x400  /* Bit 10: INT10 (Interrupt 10) */

#define VICIRQSTATUS_INT9          0x200  /* Bit 9: INT9 (Interrupt 9) */

#define VICIRQSTATUS_INT8          0x100  /* Bit 8: INT8 (Interrupt 8) */

#define VICIRQSTATUS_INT7          0x80   /* Bit 7: INT7 (Interrupt 7) */

#define VICIRQSTATUS_INT6          0x40   /* Bit 6: INT6 (Interrupt 6) */

#define VICIRQSTATUS_INT5          0x20   /* Bit 5: INT5 (Interrupt 5) */

#define VICIRQSTATUS_INT4          0x10   /* Bit 4: INT4 (Interrupt 4) */

#define VICIRQSTATUS_INT3          0x08   /* Bit 3: INT3 (Interrupt 3) */

#define VICIRQSTATUS_INT2          0x04   /* Bit 2: INT2 (Interrupt 2) */

#define VICIRQSTATUS_INT1          0x02   /* Bit 1: INT1 (Interrupt 1) */

#define VICIRQSTATUS_INT0          0x01   /* Bit 0: INT0 (Interrupt 0) */


/*
**---------------------------------------------------------------------------
**  FIQ Status Register
**---------------------------------------------------------------------------
*/

#define VICFIQSTATUS_INT31         0x80000000 /* Bit 31: INT31 (Interrupt 31) */

#define VICFIQSTATUS_INT30         0x40000000 /* Bit 30: INT30 (Interrupt 30) */

#define VICFIQSTATUS_INT29         0x20000000 /* Bit 29: INT29 (Interrupt 29) */

#define VICFIQSTATUS_INT28         0x10000000 /* Bit 28: INT28 (Interrupt 28) */

#define VICFIQSTATUS_INT27         0x8000000 /* Bit 27: INT27 (Interrupt 27) */

#define VICFIQSTATUS_INT26         0x4000000 /* Bit 26: INT26 (Interrupt 26) */

#define VICFIQSTATUS_INT25         0x2000000 /* Bit 25: INT25 (Interrupt 25) */

#define VICFIQSTATUS_INT24         0x1000000 /* Bit 24: INT24 (Interrupt 24) */

#define VICFIQSTATUS_INT23         0x800000 /* Bit 23: INT23 (Interrupt 23) */

#define VICFIQSTATUS_INT22         0x400000 /* Bit 22: INT22 (Interrupt 22) */

#define VICFIQSTATUS_INT21         0x200000 /* Bit 21: INT21 (Interrupt 21) */

#define VICFIQSTATUS_INT20         0x100000 /* Bit 20: INT20 (Interrupt 20) */

#define VICFIQSTATUS_INT19         0x80000 /* Bit 19: INT19 (Interrupt 19) */

#define VICFIQSTATUS_INT18         0x40000 /* Bit 18: INT18 (Interrupt 18) */

#define VICFIQSTATUS_INT17         0x20000 /* Bit 17: INT17 (Interrupt 17) */

#define VICFIQSTATUS_INT16         0x10000 /* Bit 16: INT16 (Interrupt 16) */

#define VICFIQSTATUS_INT15         0x8000 /* Bit 15: INT15 (Interrupt 15) */

#define VICFIQSTATUS_INT14         0x4000 /* Bit 14: INT14 (Interrupt 14) */

#define VICFIQSTATUS_INT13         0x2000 /* Bit 13: INT13 (Interrupt 13) */

#define VICFIQSTATUS_INT12         0x1000 /* Bit 12: INT12 (Interrupt 12) */

#define VICFIQSTATUS_INT11         0x800  /* Bit 11: INT11 (Interrupt 11) */

#define VICFIQSTATUS_INT10         0x400  /* Bit 10: INT10 (Interrupt 10) */

#define VICFIQSTATUS_INT9          0x200  /* Bit 9: INT9 (Interrupt 9) */

#define VICFIQSTATUS_INT8          0x100  /* Bit 8: INT8 (Interrupt 8) */

#define VICFIQSTATUS_INT7          0x80   /* Bit 7: INT7 (Interrupt 7) */

#define VICFIQSTATUS_INT6          0x40   /* Bit 6: INT6 (Interrupt 6) */

#define VICFIQSTATUS_INT5          0x20   /* Bit 5: INT5 (Interrupt 5) */

#define VICFIQSTATUS_INT4          0x10   /* Bit 4: INT4 (Interrupt 4) */

#define VICFIQSTATUS_INT3          0x08   /* Bit 3: INT3 (Interrupt 3) */

#define VICFIQSTATUS_INT2          0x04   /* Bit 2: INT2 (Interrupt 2) */

#define VICFIQSTATUS_INT1          0x02   /* Bit 1: INT1 (Interrupt 1) */

#define VICFIQSTATUS_INT0          0x01   /* Bit 0: INT0 (Interrupt 0) */


/*
**---------------------------------------------------------------------------
**  VIQ Raw Interrupt Status Register
**---------------------------------------------------------------------------
*/

#define VICRAWINTR_INT31           0x80000000 /* Bit 31: INT31 (Interrupt 31) */

#define VICRAWINTR_INT30           0x40000000 /* Bit 30: INT30 (Interrupt 30) */

#define VICRAWINTR_INT29           0x20000000 /* Bit 29: INT29 (Interrupt 29) */

#define VICRAWINTR_INT28           0x10000000 /* Bit 28: INT28 (Interrupt 28) */

#define VICRAWINTR_INT27           0x8000000 /* Bit 27: INT27 (Interrupt 27) */

#define VICRAWINTR_INT26           0x4000000 /* Bit 26: INT26 (Interrupt 26) */

#define VICRAWINTR_INT25           0x2000000 /* Bit 25: INT25 (Interrupt 25) */

#define VICRAWINTR_INT24           0x1000000 /* Bit 24: INT24 (Interrupt 24) */

#define VICRAWINTR_INT23           0x800000 /* Bit 23: INT23 (Interrupt 23) */

#define VICRAWINTR_INT22           0x400000 /* Bit 22: INT22 (Interrupt 22) */

#define VICRAWINTR_INT21           0x200000 /* Bit 21: INT21 (Interrupt 21) */

#define VICRAWINTR_INT20           0x100000 /* Bit 20: INT20 (Interrupt 20) */

#define VICRAWINTR_INT19           0x80000 /* Bit 19: INT19 (Interrupt 19) */

#define VICRAWINTR_INT18           0x40000 /* Bit 18: INT18 (Interrupt 18) */

#define VICRAWINTR_INT17           0x20000 /* Bit 17: INT17 (Interrupt 17) */

#define VICRAWINTR_INT16           0x10000 /* Bit 16: INT16 (Interrupt 16) */

#define VICRAWINTR_INT15           0x8000 /* Bit 15: INT15 (Interrupt 15) */

#define VICRAWINTR_INT14           0x4000 /* Bit 14: INT14 (Interrupt 14) */

#define VICRAWINTR_INT13           0x2000 /* Bit 13: INT13 (Interrupt 13) */

#define VICRAWINTR_INT12           0x1000 /* Bit 12: INT12 (Interrupt 12) */

#define VICRAWINTR_INT11           0x800  /* Bit 11: INT11 (Interrupt 11) */

#define VICRAWINTR_INT10           0x400  /* Bit 10: INT10 (Interrupt 10) */

#define VICRAWINTR_INT9            0x200  /* Bit 9: INT9 (Interrupt 9) */

#define VICRAWINTR_INT8            0x100  /* Bit 8: INT8 (Interrupt 8) */

#define VICRAWINTR_INT7            0x80   /* Bit 7: INT7 (Interrupt 7) */

#define VICRAWINTR_INT6            0x40   /* Bit 6: INT6 (Interrupt 6) */

#define VICRAWINTR_INT5            0x20   /* Bit 5: INT5 (Interrupt 5) */

#define VICRAWINTR_INT4            0x10   /* Bit 4: INT4 (Interrupt 4) */

#define VICRAWINTR_INT3            0x08   /* Bit 3: INT3 (Interrupt 3) */

#define VICRAWINTR_INT2            0x04   /* Bit 2: INT2 (Interrupt 2) */

#define VICRAWINTR_INT1            0x02   /* Bit 1: INT1 (Interrupt 1) */

#define VICRAWINTR_INT0            0x01   /* Bit 0: INT0 (Interrupt 0) */


/*
**---------------------------------------------------------------------------
**  Interrupt Select Register
**---------------------------------------------------------------------------
*/

#define VICINTSELECT_INT31         0x80000000 /* Bit 31: INT31 (Interrupt 31) */
#define VICINTSELECT_INT31_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT31_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT30         0x40000000 /* Bit 30: INT30 (Interrupt 30) */
#define VICINTSELECT_INT30_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT30_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT29         0x20000000 /* Bit 29: INT29 (Interrupt 29) */
#define VICINTSELECT_INT29_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT29_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT28         0x10000000 /* Bit 28: INT28 (Interrupt 28) */
#define VICINTSELECT_INT28_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT28_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT27         0x8000000 /* Bit 27: INT27 (Interrupt 27) */
#define VICINTSELECT_INT27_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT27_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT26         0x4000000 /* Bit 26: INT26 (Interrupt 26) */
#define VICINTSELECT_INT26_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT26_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT25         0x2000000 /* Bit 25: INT25 (Interrupt 25) */
#define VICINTSELECT_INT25_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT25_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT24         0x1000000 /* Bit 24: INT24 (Interrupt 24) */
#define VICINTSELECT_INT24_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT24_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT23         0x800000 /* Bit 23: INT23 (Interrupt 23) */
#define VICINTSELECT_INT23_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT23_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT22         0x400000 /* Bit 22: INT22 (Interrupt 22) */
#define VICINTSELECT_INT22_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT22_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT21         0x200000 /* Bit 21: INT21 (Interrupt 21) */
#define VICINTSELECT_INT21_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT21_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT20         0x100000 /* Bit 20: INT20 (Interrupt 20) */
#define VICINTSELECT_INT20_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT20_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT19         0x80000 /* Bit 19: INT19 (Interrupt 19) */
#define VICINTSELECT_INT19_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT19_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT18         0x40000 /* Bit 18: INT18 (Interrupt 18) */
#define VICINTSELECT_INT18_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT18_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT17         0x20000 /* Bit 17: INT17 (Interrupt 17) */
#define VICINTSELECT_INT17_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT17_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT16         0x10000 /* Bit 16: INT16 (Interrupt 16) */
#define VICINTSELECT_INT16_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT16_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT15         0x8000 /* Bit 15: INT15 (Interrupt 15) */
#define VICINTSELECT_INT15_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT15_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT14         0x4000 /* Bit 14: INT14 (Interrupt 14) */
#define VICINTSELECT_INT14_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT14_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT13         0x2000 /* Bit 13: INT13 (Interrupt 13) */
#define VICINTSELECT_INT13_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT13_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT12         0x1000 /* Bit 12: INT12 (Interrupt 12) */
#define VICINTSELECT_INT12_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT12_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT11         0x800  /* Bit 11: INT11 (Interrupt 11) */
#define VICINTSELECT_INT11_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT11_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT10         0x400  /* Bit 10: INT10 (Interrupt 10) */
#define VICINTSELECT_INT10_IRQ     0x00   /* IRQ category */
#define VICINTSELECT_INT10_FIQ     0x01   /* FIQ category */

#define VICINTSELECT_INT9          0x200  /* Bit 9: INT9 (Interrupt 9) */
#define VICINTSELECT_INT9_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT9_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT8          0x100  /* Bit 8: INT8 (Interrupt 8) */
#define VICINTSELECT_INT8_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT8_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT7          0x80   /* Bit 7: INT7 (Interrupt 7) */
#define VICINTSELECT_INT7_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT7_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT6          0x40   /* Bit 6: INT6 (Interrupt 6) */
#define VICINTSELECT_INT6_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT6_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT5          0x20   /* Bit 5: INT5 (Interrupt 5) */
#define VICINTSELECT_INT5_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT5_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT4          0x10   /* Bit 4: INT4 (Interrupt 4) */
#define VICINTSELECT_INT4_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT4_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT3          0x08   /* Bit 3: INT3 (Interrupt 3) */
#define VICINTSELECT_INT3_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT3_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT2          0x04   /* Bit 2: INT2 (Interrupt 2) */
#define VICINTSELECT_INT2_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT2_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT1          0x02   /* Bit 1: INT1 (Interrupt 1) */
#define VICINTSELECT_INT1_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT1_FIQ      0x01   /* FIQ category */

#define VICINTSELECT_INT0          0x01   /* Bit 0: INT0 (Interrupt 0) */
#define VICINTSELECT_INT0_IRQ      0x00   /* IRQ category */
#define VICINTSELECT_INT0_FIQ      0x01   /* FIQ category */


/*
**---------------------------------------------------------------------------
**  Interrupt Enable Register
**---------------------------------------------------------------------------
*/

#define VICINTENABLE_INT31         0x80000000 /* Bit 31: INT31 (Interrupt 31) */
#define VICINTENABLE_INT31_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT31_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT30         0x40000000 /* Bit 30: INT30 (Interrupt 30) */
#define VICINTENABLE_INT30_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT30_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT29         0x20000000 /* Bit 29: INT29 (Interrupt 29) */
#define VICINTENABLE_INT29_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT29_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT28         0x10000000 /* Bit 28: INT28 (Interrupt 28) */
#define VICINTENABLE_INT28_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT28_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT27         0x8000000 /* Bit 27: INT27 (Interrupt 27) */
#define VICINTENABLE_INT27_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT27_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT26         0x4000000 /* Bit 26: INT26 (Interrupt 26) */
#define VICINTENABLE_INT26_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT26_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT25         0x2000000 /* Bit 25: INT25 (Interrupt 25) */
#define VICINTENABLE_INT25_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT25_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT24         0x1000000 /* Bit 24: INT24 (Interrupt 24) */
#define VICINTENABLE_INT24_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT24_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT23         0x800000 /* Bit 23: INT23 (Interrupt 23) */
#define VICINTENABLE_INT23_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT23_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT22         0x400000 /* Bit 22: INT22 (Interrupt 22) */
#define VICINTENABLE_INT22_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT22_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT21         0x200000 /* Bit 21: INT21 (Interrupt 21) */
#define VICINTENABLE_INT21_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT21_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT20         0x100000 /* Bit 20: INT20 (Interrupt 20) */
#define VICINTENABLE_INT20_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT20_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT19         0x80000 /* Bit 19: INT19 (Interrupt 19) */
#define VICINTENABLE_INT19_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT19_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT18         0x40000 /* Bit 18: INT18 (Interrupt 18) */
#define VICINTENABLE_INT18_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT18_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT17         0x20000 /* Bit 17: INT17 (Interrupt 17) */
#define VICINTENABLE_INT17_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT17_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT16         0x10000 /* Bit 16: INT16 (Interrupt 16) */
#define VICINTENABLE_INT16_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT16_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT15         0x8000 /* Bit 15: INT15 (Interrupt 15) */
#define VICINTENABLE_INT15_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT15_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT14         0x4000 /* Bit 14: INT14 (Interrupt 14) */
#define VICINTENABLE_INT14_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT14_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT13         0x2000 /* Bit 13: INT13 (Interrupt 13) */
#define VICINTENABLE_INT13_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT13_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT12         0x1000 /* Bit 12: INT12 (Interrupt 12) */
#define VICINTENABLE_INT12_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT12_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT11         0x800  /* Bit 11: INT11 (Interrupt 11) */
#define VICINTENABLE_INT11_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT11_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT10         0x400  /* Bit 10: INT10 (Interrupt 10) */
#define VICINTENABLE_INT10_DISABLED  0x00 /* Disabled */
#define VICINTENABLE_INT10_ENABLED  0x01  /* Enabled */

#define VICINTENABLE_INT9          0x200  /* Bit 9: INT9 (Interrupt 9) */
#define VICINTENABLE_INT9_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT9_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT8          0x100  /* Bit 8: INT8 (Interrupt 8) */
#define VICINTENABLE_INT8_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT8_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT7          0x80   /* Bit 7: INT7 (Interrupt 7) */
#define VICINTENABLE_INT7_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT7_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT6          0x40   /* Bit 6: INT6 (Interrupt 6) */
#define VICINTENABLE_INT6_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT6_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT5          0x20   /* Bit 5: INT5 (Interrupt 5) */
#define VICINTENABLE_INT5_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT5_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT4          0x10   /* Bit 4: INT4 (Interrupt 4) */
#define VICINTENABLE_INT4_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT4_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT3          0x08   /* Bit 3: INT3 (Interrupt 3) */
#define VICINTENABLE_INT3_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT3_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT2          0x04   /* Bit 2: INT2 (Interrupt 2) */
#define VICINTENABLE_INT2_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT2_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT1          0x02   /* Bit 1: INT1 (Interrupt 1) */
#define VICINTENABLE_INT1_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT1_ENABLED  0x01   /* Enabled */

#define VICINTENABLE_INT0          0x01   /* Bit 0: INT0 (Interrupt 0) */
#define VICINTENABLE_INT0_DISABLED  0x00  /* Disabled */
#define VICINTENABLE_INT0_ENABLED  0x01   /* Enabled */


/*
**---------------------------------------------------------------------------
**  Interrupt Enable Clear Register
**---------------------------------------------------------------------------
*/

#define VICINTENCLR_INT31          0x80000000 /* Bit 31: INT31 (Interrupt 31) */
#define VICINTENCLR_INT31_LOW      0x00   /* Low */
#define VICINTENCLR_INT31_HIGH     0x01   /* High */

#define VICINTENCLR_INT30          0x40000000 /* Bit 30: INT30 (Interrupt 30) */
#define VICINTENCLR_INT30_LOW      0x00   /* Low */
#define VICINTENCLR_INT30_HIGH     0x01   /* High */

#define VICINTENCLR_INT29          0x20000000 /* Bit 29: INT29 (Interrupt 29) */
#define VICINTENCLR_INT29_LOW      0x00   /* Low */
#define VICINTENCLR_INT29_HIGH     0x01   /* High */

#define VICINTENCLR_INT28          0x10000000 /* Bit 28: INT28 (Interrupt 28) */
#define VICINTENCLR_INT28_LOW      0x00   /* Low */
#define VICINTENCLR_INT28_HIGH     0x01   /* High */

#define VICINTENCLR_INT27          0x8000000 /* Bit 27: INT27 (Interrupt 27) */
#define VICINTENCLR_INT27_LOW      0x00   /* Low */
#define VICINTENCLR_INT27_HIGH     0x01   /* High */

#define VICINTENCLR_INT26          0x4000000 /* Bit 26: INT26 (Interrupt 26) */
#define VICINTENCLR_INT26_LOW      0x00   /* Low */
#define VICINTENCLR_INT26_HIGH     0x01   /* High */

#define VICINTENCLR_INT25          0x2000000 /* Bit 25: INT25 (Interrupt 25) */
#define VICINTENCLR_INT25_LOW      0x00   /* Low */
#define VICINTENCLR_INT25_HIGH     0x01   /* High */

#define VICINTENCLR_INT24          0x1000000 /* Bit 24: INT24 (Interrupt 24) */
#define VICINTENCLR_INT24_LOW      0x00   /* Low */
#define VICINTENCLR_INT24_HIGH     0x01   /* High */

#define VICINTENCLR_INT23          0x800000 /* Bit 23: INT23 (Interrupt 23) */
#define VICINTENCLR_INT23_LOW      0x00   /* Low */
#define VICINTENCLR_INT23_HIGH     0x01   /* High */

#define VICINTENCLR_INT22          0x400000 /* Bit 22: INT22 (Interrupt 22) */
#define VICINTENCLR_INT22_LOW      0x00   /* Low */
#define VICINTENCLR_INT22_HIGH     0x01   /* High */

#define VICINTENCLR_INT21          0x200000 /* Bit 21: INT21 (Interrupt 21) */
#define VICINTENCLR_INT21_LOW      0x00   /* Low */
#define VICINTENCLR_INT21_HIGH     0x01   /* High */

#define VICINTENCLR_INT20          0x100000 /* Bit 20: INT20 (Interrupt 20) */
#define VICINTENCLR_INT20_LOW      0x00   /* Low */
#define VICINTENCLR_INT20_HIGH     0x01   /* High */

#define VICINTENCLR_INT19          0x80000 /* Bit 19: INT19 (Interrupt 19) */
#define VICINTENCLR_INT19_LOW      0x00   /* Low */
#define VICINTENCLR_INT19_HIGH     0x01   /* High */

#define VICINTENCLR_INT18          0x40000 /* Bit 18: INT18 (Interrupt 18) */
#define VICINTENCLR_INT18_LOW      0x00   /* Low */
#define VICINTENCLR_INT18_HIGH     0x01   /* High */

#define VICINTENCLR_INT17          0x20000 /* Bit 17: INT17 (Interrupt 17) */
#define VICINTENCLR_INT17_LOW      0x00   /* Low */
#define VICINTENCLR_INT17_HIGH     0x01   /* High */

#define VICINTENCLR_INT16          0x10000 /* Bit 16: INT16 (Interrupt 16) */
#define VICINTENCLR_INT16_LOW      0x00   /* Low */
#define VICINTENCLR_INT16_HIGH     0x01   /* High */

#define VICINTENCLR_INT15          0x8000 /* Bit 15: INT15 (Interrupt 15) */
#define VICINTENCLR_INT15_LOW      0x00   /* Low */
#define VICINTENCLR_INT15_HIGH     0x01   /* High */

#define VICINTENCLR_INT14          0x4000 /* Bit 14: INT14 (Interrupt 14) */
#define VICINTENCLR_INT14_LOW      0x00   /* Low */
#define VICINTENCLR_INT14_HIGH     0x01   /* High */

#define VICINTENCLR_INT13          0x2000 /* Bit 13: INT13 (Interrupt 13) */
#define VICINTENCLR_INT13_LOW      0x00   /* Low */
#define VICINTENCLR_INT13_HIGH     0x01   /* High */

#define VICINTENCLR_INT12          0x1000 /* Bit 12: INT12 (Interrupt 12) */
#define VICINTENCLR_INT12_LOW      0x00   /* Low */
#define VICINTENCLR_INT12_HIGH     0x01   /* High */

#define VICINTENCLR_INT11          0x800  /* Bit 11: INT11 (Interrupt 11) */
#define VICINTENCLR_INT11_LOW      0x00   /* Low */
#define VICINTENCLR_INT11_HIGH     0x01   /* High */

#define VICINTENCLR_INT10          0x400  /* Bit 10: INT10 (Interrupt 10) */
#define VICINTENCLR_INT10_LOW      0x00   /* Low */
#define VICINTENCLR_INT10_HIGH     0x01   /* High */

#define VICINTENCLR_INT9           0x200  /* Bit 9: INT9 (Interrupt 9) */
#define VICINTENCLR_INT9_LOW       0x00   /* Low */
#define VICINTENCLR_INT9_HIGH      0x01   /* High */

#define VICINTENCLR_INT8           0x100  /* Bit 8: INT8 (Interrupt 8) */
#define VICINTENCLR_INT8_LOW       0x00   /* Low */
#define VICINTENCLR_INT8_HIGH      0x01   /* High */

#define VICINTENCLR_INT7           0x80   /* Bit 7: INT7 (Interrupt 7) */
#define VICINTENCLR_INT7_LOW       0x00   /* Low */
#define VICINTENCLR_INT7_HIGH      0x01   /* High */

#define VICINTENCLR_INT6           0x40   /* Bit 6: INT6 (Interrupt 6) */
#define VICINTENCLR_INT6_LOW       0x00   /* Low */
#define VICINTENCLR_INT6_HIGH      0x01   /* High */

#define VICINTENCLR_INT5           0x20   /* Bit 5: INT5 (Interrupt 5) */
#define VICINTENCLR_INT5_LOW       0x00   /* Low */
#define VICINTENCLR_INT5_HIGH      0x01   /* High */

#define VICINTENCLR_INT4           0x10   /* Bit 4: INT4 (Interrupt 4) */
#define VICINTENCLR_INT4_LOW       0x00   /* Low */
#define VICINTENCLR_INT4_HIGH      0x01   /* High */

#define VICINTENCLR_INT3           0x08   /* Bit 3: INT3 (Interrupt 3) */
#define VICINTENCLR_INT3_LOW       0x00   /* Low */
#define VICINTENCLR_INT3_HIGH      0x01   /* High */

#define VICINTENCLR_INT2           0x04   /* Bit 2: INT2 (Interrupt 2) */
#define VICINTENCLR_INT2_LOW       0x00   /* Low */
#define VICINTENCLR_INT2_HIGH      0x01   /* High */

#define VICINTENCLR_INT1           0x02   /* Bit 1: INT1 (Interrupt 1) */
#define VICINTENCLR_INT1_LOW       0x00   /* Low */
#define VICINTENCLR_INT1_HIGH      0x01   /* High */

#define VICINTENCLR_INT0           0x01   /* Bit 0: INT0 (Interrupt 0) */
#define VICINTENCLR_INT0_LOW       0x00   /* Low */
#define VICINTENCLR_INT0_HIGH      0x01   /* High */


/*
**---------------------------------------------------------------------------
**  Software Interrupt Register
**---------------------------------------------------------------------------
*/

#define VICSOFTINT_INT31           0x80000000 /* Bit 31: INT31 (Interrupt 31) */
#define VICSOFTINT_INT31_LOW       0x00   /* Low */
#define VICSOFTINT_INT31_HIGH      0x01   /* High */

#define VICSOFTINT_INT30           0x40000000 /* Bit 30: INT30 (Interrupt 30) */
#define VICSOFTINT_INT30_LOW       0x00   /* Low */
#define VICSOFTINT_INT30_HIGH      0x01   /* High */

#define VICSOFTINT_INT29           0x20000000 /* Bit 29: INT29 (Interrupt 29) */
#define VICSOFTINT_INT29_LOW       0x00   /* Low */
#define VICSOFTINT_INT29_HIGH      0x01   /* High */

#define VICSOFTINT_INT28           0x10000000 /* Bit 28: INT28 (Interrupt 28) */
#define VICSOFTINT_INT28_LOW       0x00   /* Low */
#define VICSOFTINT_INT28_HIGH      0x01   /* High */

#define VICSOFTINT_INT27           0x8000000 /* Bit 27: INT27 (Interrupt 27) */
#define VICSOFTINT_INT27_LOW       0x00   /* Low */
#define VICSOFTINT_INT27_HIGH      0x01   /* High */

#define VICSOFTINT_INT26           0x4000000 /* Bit 26: INT26 (Interrupt 26) */
#define VICSOFTINT_INT26_LOW       0x00   /* Low */
#define VICSOFTINT_INT26_HIGH      0x01   /* High */

#define VICSOFTINT_INT25           0x2000000 /* Bit 25: INT25 (Interrupt 25) */
#define VICSOFTINT_INT25_LOW       0x00   /* Low */
#define VICSOFTINT_INT25_HIGH      0x01   /* High */

#define VICSOFTINT_INT24           0x1000000 /* Bit 24: INT24 (Interrupt 24) */
#define VICSOFTINT_INT24_LOW       0x00   /* Low */
#define VICSOFTINT_INT24_HIGH      0x01   /* High */

#define VICSOFTINT_INT23           0x800000 /* Bit 23: INT23 (Interrupt 23) */
#define VICSOFTINT_INT23_LOW       0x00   /* Low */
#define VICSOFTINT_INT23_HIGH      0x01   /* High */

#define VICSOFTINT_INT22           0x400000 /* Bit 22: INT22 (Interrupt 22) */
#define VICSOFTINT_INT22_LOW       0x00   /* Low */
#define VICSOFTINT_INT22_HIGH      0x01   /* High */

#define VICSOFTINT_INT21           0x200000 /* Bit 21: INT21 (Interrupt 21) */
#define VICSOFTINT_INT21_LOW       0x00   /* Low */
#define VICSOFTINT_INT21_HIGH      0x01   /* High */

#define VICSOFTINT_INT20           0x100000 /* Bit 20: INT20 (Interrupt 20) */
#define VICSOFTINT_INT20_LOW       0x00   /* Low */
#define VICSOFTINT_INT20_HIGH      0x01   /* High */

#define VICSOFTINT_INT19           0x80000 /* Bit 19: INT19 (Interrupt 19) */
#define VICSOFTINT_INT19_LOW       0x00   /* Low */
#define VICSOFTINT_INT19_HIGH      0x01   /* High */

#define VICSOFTINT_INT18           0x40000 /* Bit 18: INT18 (Interrupt 18) */
#define VICSOFTINT_INT18_LOW       0x00   /* Low */
#define VICSOFTINT_INT18_HIGH      0x01   /* High */

#define VICSOFTINT_INT17           0x20000 /* Bit 17: INT17 (Interrupt 17) */
#define VICSOFTINT_INT17_LOW       0x00   /* Low */
#define VICSOFTINT_INT17_HIGH      0x01   /* High */

#define VICSOFTINT_INT16           0x10000 /* Bit 16: INT16 (Interrupt 16) */
#define VICSOFTINT_INT16_LOW       0x00   /* Low */
#define VICSOFTINT_INT16_HIGH      0x01   /* High */

#define VICSOFTINT_INT15           0x8000 /* Bit 15: INT15 (Interrupt 15) */
#define VICSOFTINT_INT15_LOW       0x00   /* Low */
#define VICSOFTINT_INT15_HIGH      0x01   /* High */

#define VICSOFTINT_INT14           0x4000 /* Bit 14: INT14 (Interrupt 14) */
#define VICSOFTINT_INT14_LOW       0x00   /* Low */
#define VICSOFTINT_INT14_HIGH      0x01   /* High */

#define VICSOFTINT_INT13           0x2000 /* Bit 13: INT13 (Interrupt 13) */
#define VICSOFTINT_INT13_LOW       0x00   /* Low */
#define VICSOFTINT_INT13_HIGH      0x01   /* High */

#define VICSOFTINT_INT12           0x1000 /* Bit 12: INT12 (Interrupt 12) */
#define VICSOFTINT_INT12_LOW       0x00   /* Low */
#define VICSOFTINT_INT12_HIGH      0x01   /* High */

#define VICSOFTINT_INT11           0x800  /* Bit 11: INT11 (Interrupt 11) */
#define VICSOFTINT_INT11_LOW       0x00   /* Low */
#define VICSOFTINT_INT11_HIGH      0x01   /* High */

#define VICSOFTINT_INT10           0x400  /* Bit 10: INT10 (Interrupt 10) */
#define VICSOFTINT_INT10_LOW       0x00   /* Low */
#define VICSOFTINT_INT10_HIGH      0x01   /* High */

#define VICSOFTINT_INT9            0x200  /* Bit 9: INT9 (Interrupt 9) */
#define VICSOFTINT_INT9_LOW        0x00   /* Low */
#define VICSOFTINT_INT9_HIGH       0x01   /* High */

#define VICSOFTINT_INT8            0x100  /* Bit 8: INT8 (Interrupt 8) */
#define VICSOFTINT_INT8_LOW        0x00   /* Low */
#define VICSOFTINT_INT8_HIGH       0x01   /* High */

#define VICSOFTINT_INT7            0x80   /* Bit 7: INT7 (Interrupt 7) */
#define VICSOFTINT_INT7_LOW        0x00   /* Low */
#define VICSOFTINT_INT7_HIGH       0x01   /* High */

#define VICSOFTINT_INT6            0x40   /* Bit 6: INT6 (Interrupt 6) */
#define VICSOFTINT_INT6_LOW        0x00   /* Low */
#define VICSOFTINT_INT6_HIGH       0x01   /* High */

#define VICSOFTINT_INT5            0x20   /* Bit 5: INT5 (Interrupt 5) */
#define VICSOFTINT_INT5_LOW        0x00   /* Low */
#define VICSOFTINT_INT5_HIGH       0x01   /* High */

#define VICSOFTINT_INT4            0x10   /* Bit 4: INT4 (Interrupt 4) */
#define VICSOFTINT_INT4_LOW        0x00   /* Low */
#define VICSOFTINT_INT4_HIGH       0x01   /* High */

#define VICSOFTINT_INT3            0x08   /* Bit 3: INT3 (Interrupt 3) */
#define VICSOFTINT_INT3_LOW        0x00   /* Low */
#define VICSOFTINT_INT3_HIGH       0x01   /* High */

#define VICSOFTINT_INT2            0x04   /* Bit 2: INT2 (Interrupt 2) */
#define VICSOFTINT_INT2_LOW        0x00   /* Low */
#define VICSOFTINT_INT2_HIGH       0x01   /* High */

#define VICSOFTINT_INT1            0x02   /* Bit 1: INT1 (Interrupt 1) */
#define VICSOFTINT_INT1_LOW        0x00   /* Low */
#define VICSOFTINT_INT1_HIGH       0x01   /* High */

#define VICSOFTINT_INT0            0x01   /* Bit 0: INT0 (Interrupt 0) */
#define VICSOFTINT_INT0_LOW        0x00   /* Low */
#define VICSOFTINT_INT0_HIGH       0x01   /* High */


/*
**---------------------------------------------------------------------------
**  Software Interrupt Clear Register
**---------------------------------------------------------------------------
*/

#define VICSOFTINTCLEAR_INT31      0x80000000 /* Bit 31: INT31 (Interrupt 31) */
#define VICSOFTINTCLEAR_INT31_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT31_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT30      0x40000000 /* Bit 30: INT30 (Interrupt 30) */
#define VICSOFTINTCLEAR_INT30_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT30_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT29      0x20000000 /* Bit 29: INT29 (Interrupt 29) */
#define VICSOFTINTCLEAR_INT29_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT29_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT28      0x10000000 /* Bit 28: INT28 (Interrupt 28) */
#define VICSOFTINTCLEAR_INT28_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT28_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT27      0x8000000 /* Bit 27: INT27 (Interrupt 27) */
#define VICSOFTINTCLEAR_INT27_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT27_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT26      0x4000000 /* Bit 26: INT26 (Interrupt 26) */
#define VICSOFTINTCLEAR_INT26_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT26_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT25      0x2000000 /* Bit 25: INT25 (Interrupt 25) */
#define VICSOFTINTCLEAR_INT25_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT25_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT24      0x1000000 /* Bit 24: INT24 (Interrupt 24) */
#define VICSOFTINTCLEAR_INT24_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT24_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT23      0x800000 /* Bit 23: INT23 (Interrupt 23) */
#define VICSOFTINTCLEAR_INT23_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT23_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT22      0x400000 /* Bit 22: INT22 (Interrupt 22) */
#define VICSOFTINTCLEAR_INT22_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT22_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT21      0x200000 /* Bit 21: INT21 (Interrupt 21) */
#define VICSOFTINTCLEAR_INT21_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT21_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT20      0x100000 /* Bit 20: INT20 (Interrupt 20) */
#define VICSOFTINTCLEAR_INT20_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT20_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT19      0x80000 /* Bit 19: INT19 (Interrupt 19) */
#define VICSOFTINTCLEAR_INT19_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT19_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT18      0x40000 /* Bit 18: INT18 (Interrupt 18) */
#define VICSOFTINTCLEAR_INT18_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT18_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT17      0x20000 /* Bit 17: INT17 (Interrupt 17) */
#define VICSOFTINTCLEAR_INT17_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT17_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT16      0x10000 /* Bit 16: INT16 (Interrupt 16) */
#define VICSOFTINTCLEAR_INT16_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT16_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT15      0x8000 /* Bit 15: INT15 (Interrupt 15) */
#define VICSOFTINTCLEAR_INT15_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT15_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT14      0x4000 /* Bit 14: INT14 (Interrupt 14) */
#define VICSOFTINTCLEAR_INT14_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT14_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT13      0x2000 /* Bit 13: INT13 (Interrupt 13) */
#define VICSOFTINTCLEAR_INT13_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT13_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT12      0x1000 /* Bit 12: INT12 (Interrupt 12) */
#define VICSOFTINTCLEAR_INT12_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT12_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT11      0x800  /* Bit 11: INT11 (Interrupt 11) */
#define VICSOFTINTCLEAR_INT11_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT11_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT10      0x400  /* Bit 10: INT10 (Interrupt 10) */
#define VICSOFTINTCLEAR_INT10_LOW  0x00   /* Low */
#define VICSOFTINTCLEAR_INT10_HIGH  0x01  /* High */

#define VICSOFTINTCLEAR_INT9       0x200  /* Bit 9: INT9 (Interrupt 9) */
#define VICSOFTINTCLEAR_INT9_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT9_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT8       0x100  /* Bit 8: INT8 (Interrupt 8) */
#define VICSOFTINTCLEAR_INT8_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT8_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT7       0x80   /* Bit 7: INT7 (Interrupt 7) */
#define VICSOFTINTCLEAR_INT7_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT7_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT6       0x40   /* Bit 6: INT6 (Interrupt 6) */
#define VICSOFTINTCLEAR_INT6_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT6_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT5       0x20   /* Bit 5: INT5 (Interrupt 5) */
#define VICSOFTINTCLEAR_INT5_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT5_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT4       0x10   /* Bit 4: INT4 (Interrupt 4) */
#define VICSOFTINTCLEAR_INT4_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT4_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT3       0x08   /* Bit 3: INT3 (Interrupt 3) */
#define VICSOFTINTCLEAR_INT3_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT3_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT2       0x04   /* Bit 2: INT2 (Interrupt 2) */
#define VICSOFTINTCLEAR_INT2_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT2_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT1       0x02   /* Bit 1: INT1 (Interrupt 1) */
#define VICSOFTINTCLEAR_INT1_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT1_HIGH  0x01   /* High */

#define VICSOFTINTCLEAR_INT0       0x01   /* Bit 0: INT0 (Interrupt 0) */
#define VICSOFTINTCLEAR_INT0_LOW   0x00   /* Low */
#define VICSOFTINTCLEAR_INT0_HIGH  0x01   /* High */


/*
**---------------------------------------------------------------------------
**  Protection Enable Register
**---------------------------------------------------------------------------
*/

#define VICPROTECTION_PROTECT      0x01   /* Bit 0: PROTECT (VIC register protection) */
#define VICPROTECTION_PROTECT_USER_PRIVELEGED  0x00 /* Access in User mode and Priveleged mode */
#define VICPROTECTION_PROTECT_PRIVELEGED  0x01 /* Access in Priveleged mode only */


/*
**---------------------------------------------------------------------------
**  Vector Address Register
**---------------------------------------------------------------------------
*/

#define VICVECTADDR_ADDRESS        0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Default Vector Address Register
**---------------------------------------------------------------------------
*/

#define VICDEFVECTADDR_ADDRESS     0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 0
**---------------------------------------------------------------------------
*/

#define VICVECTADDR0_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 1
**---------------------------------------------------------------------------
*/

#define VICVECTADDR1_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 2
**---------------------------------------------------------------------------
*/

#define VICVECTADDR2_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 3
**---------------------------------------------------------------------------
*/

#define VICVECTADDR3_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 4
**---------------------------------------------------------------------------
*/

#define VICVECTADDR4_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 5
**---------------------------------------------------------------------------
*/

#define VICVECTADDR5_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 6
**---------------------------------------------------------------------------
*/

#define VICVECTADDR6_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 7
**---------------------------------------------------------------------------
*/

#define VICVECTADDR7_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 8
**---------------------------------------------------------------------------
*/

#define VICVECTADDR8_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 9
**---------------------------------------------------------------------------
*/

#define VICVECTADDR9_ADDRESS       0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 10
**---------------------------------------------------------------------------
*/

#define VICVECTADDR10_ADDRESS      0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 11
**---------------------------------------------------------------------------
*/

#define VICVECTADDR11_ADDRESS      0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 12
**---------------------------------------------------------------------------
*/

#define VICVECTADDR12_ADDRESS      0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 13
**---------------------------------------------------------------------------
*/

#define VICVECTADDR13_ADDRESS      0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 14
**---------------------------------------------------------------------------
*/

#define VICVECTADDR14_ADDRESS      0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Address Register 15
**---------------------------------------------------------------------------
*/

#define VICVECTADDR15_ADDRESS      0xffffffff /* Bit 31-0: ADDRESS (Vector address) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 0
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL0_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL0_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL0_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL0_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 1
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL1_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL1_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL1_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL1_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 2
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL2_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL2_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL2_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL2_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 3
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL3_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL3_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL3_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL3_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 4
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL4_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL4_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL4_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL4_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 5
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL5_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL5_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL5_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL5_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 6
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL6_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL6_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL6_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL6_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 7
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL7_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL7_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL7_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL7_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 8
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL8_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL8_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL8_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL8_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 9
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL9_ENABLED       0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL9_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL9_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL9_NUMBER        0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 10
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL10_ENABLED      0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL10_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL10_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL10_NUMBER       0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 11
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL11_ENABLED      0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL11_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL11_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL11_NUMBER       0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 12
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL12_ENABLED      0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL12_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL12_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL12_NUMBER       0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 13
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL13_ENABLED      0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL13_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL13_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL13_NUMBER       0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 14
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL14_ENABLED      0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL14_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL14_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL14_NUMBER       0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */


/*
**---------------------------------------------------------------------------
**  Vector Control Register 15
**---------------------------------------------------------------------------
*/

#define VICVECTCNTL15_ENABLED      0x20   /* Bit 5: ENABLED (Interrupt enabled) */
#define VICVECTCNTL15_ENABLED_DISABLED  0x00 /* Disabled */
#define VICVECTCNTL15_ENABLED_ENABLED  0x01 /* Enabled */

#define VICVECTCNTL15_NUMBER       0x1f   /* Bit 4-0: NUMBER (Interrupt is assigned to this number) */

#endif /* Match the re-definition guard */

