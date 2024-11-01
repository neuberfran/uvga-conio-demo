/*
    hw_st710.c
    STMicroelectronics STR71x hardware low-level routines
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

    MCU:   STR712
    Crystal:  4 MHz (PLL1 (4Mhz * 24 / 1 ) = 48Mhz (CPU max))
    Operating frequency:  48 MHz (MCLK = PCLK1 = PCLK2 = 48MHz)
    UART Speed:     1 Mbit
    Connection:
      MicroVGA.TXD = STR712.U0.RX (P0_8)
      MicroVGA.RXD = STR712.U0.TX (P0_9)
      MicroVGA.RTS = STR712.P0_5
      MicroVGA.CTS = STR712.P0_4

    _putch, _getch, _kbhit must be defined for lib (conio.c and ui.c)
*/

#include "library/inc/71x_lib.h"

/* Private define ------------------------------------------------------------*/
#define UART0_Rx_Pin (0x0001 << 8)  /*TQFP 64: pin N° 63, TQFP 144 pin N° 143*/
#define UART0_Tx_Pin (0x0001 << 9)  /*TQFP 64: pin N° 64, TQFP 144 pin N° 144*/

#define UART1_Rx_Pin (0x0001 << 10) /* TQFP 64: pin N° 1, TQFP 144 pin N° 1*/
#define UART1_Tx_Pin (0x0001 << 11) /* TQFP 64: pin N° 2, TQFP 144 pin N° 3*/

#define UART2_Rx_Pin (0x0001 << 13) /* TQFP 64: pin N° 5, TQFP 144 pin N° 9*/
#define UART2_Tx_Pin (0x0001 << 14) /* TQFP 64: pin N° 6, TQFP 144 pin N° 10*/

#define UART3_Rx_Pin (0x0001 << 1)  /* TQFP 64: pin N° 52, TQFP 144 pin N° 123*/
#define UART3_Tx_Pin (0x0001 << 0)  /* TQFP 64: pin N° 53, TQFP 144 pin N° 124*/

#define CTS_PIN_NUMBER 4
#define CTS_PIN (0x0001 << RTS_PIN_NUMBER)
#define CTS_STOP 1 // CTS pin is driven high whenever the device is not ready to receive
#define CTS_GO 0 //The CTS pin  is asserted (driven low) whenever the receiver is ready to receive data
#define RTS_PIN_NUMBER 5
#define RTS_PIN (0x0001 << CTS_PIN_NUMBER)

#define LED_PIN_NUMBER 8
#define LED_PIN (0x0001 << 8)

#define Use_UART0
/* #define Use_UART1 */
/* #define Use_UART2 */
/* #define Use_UART3 */

#ifdef Use_UART0
  #define  UARTX  UART0
  #define  UARTX_Rx_Pin  UART0_Rx_Pin
  #define  UARTX_Tx_Pin  UART0_Tx_Pin
  #define  UARTX_Periph  UART0_Periph
#endif /* Use_UART0 */

#ifdef Use_UART1
  #define  UARTX  UART1
  #define  UARTX_Rx_Pin  UART1_Rx_Pin
  #define  UARTX_Tx_Pin  UART1_Tx_Pin
  #define  UARTX_Periph  UART1_Periph
#endif /* Use_UART1 */

#ifdef Use_UART2
  #define  UARTX  UART2
  #define  UARTX_Rx_Pin  UART2_Rx_Pin
  #define  UARTX_Tx_Pin  UART2_Tx_Pin
  #define  UARTX_Periph  UART2_Periph
#endif /* Use_UART2 */

#ifdef Use_UART3
  #define  UARTX  UART3
  #define  UARTX_Rx_Pin  UART3_Rx_Pin
  #define  UARTX_Tx_Pin  UART3_Tx_Pin
  #define  UARTX_Periph  UART3_Periph
#endif /* Use_UART3 */

u8 led_state;

void blink_led()
{ //debug routine (blink diod on LED_PIN_NUMBER)
  led_state=!led_state;
  GPIO_BitWrite(GPIO1,LED_PIN_NUMBER,led_state);
}

void _putch (char ch)
{
  //Wait for RTS (uVGA ready to recv data) 
  //low -> uVGA is ready to recv data
  while (GPIO_BitRead(GPIO1,RTS_PIN_NUMBER))
  {
    blink_led();
  }

  UART_ByteSend(UARTX, (u8 *)&ch);
        
  while(!((UART_FlagStatus(UARTX)) & UART_TxEmpty))
  {
      /* wait until the data transmission is finished */
  } 
}

int _getch (void)
{
  int ch;
 
  //wait until data is received
  //GPIO_BitWrite(GPIO1,RTS_PIN_NUMBER,RTS_GO);
  while(!(UART_FlagStatus(UARTX) & UART_RxBufNotEmpty));
  //GPIO_BitWrite(GPIO1,RTS_PIN_NUMBER,RTS_STOP);
  
  UART_ByteReceive(UARTX, (u8 *)&ch,0xFF);
  
  if (ch == 0)
  { //special key pressed, read second byte

      //wait until data is received
      //GPIO_BitWrite(GPIO1,RTS_PIN_NUMBER,RTS_GO);
      while(!(UART_FlagStatus(UARTX) & UART_RxBufNotEmpty));
      //GPIO_BitWrite(GPIO1,RTS_PIN_NUMBER,RTS_STOP);
 
     UART_ByteReceive(UARTX, (u8 *)&ch,0xFF);
      ch = 0x100 | ch;
  }
  else
    blink_led();
  
  return ch;
}

int _kbhit (void)
{
  // If overrun and NO characters in queue, reset flag.
   u8 res;
  
  //GPIO_BitWrite(GPIO1,RTS_PIN_NUMBER,RTS_GO);
  
  res=(UART_FlagStatus(UARTX) & UART_RxBufNotEmpty);
  
  //if (res) //keyboard was hit, stop recv another data
    //GPIO_BitWrite(GPIO1,RTS_PIN_NUMBER,RTS_STOP);
  
  return res;
}

void MCU_Init(void)
{
#ifdef DEBUG
  debug();
  #endif
 
  /* System clocks configuration ---------------------------------------------*/
  /* MCLK = PCLK1 = PCLK2 = 48MHz*/ 
  
  /* Configure FCLK = RCLK / 1 */
  RCCU_PCLK1Config (RCCU_DEFAULT);

  /* Configure PCLK = RCLK / 1 */
  RCCU_PCLK2Config (RCCU_DEFAULT);

  /* Configure MCLK clock for the CPU, RCCU_DEFAULT = RCLK /1 */
  RCCU_MCLKConfig (RCCU_DEFAULT);
   
  // 4 Mhz on board OSC
  /* Configure the PLL1 (4Mhz * 24 / 1 ) = 48Mhz (CPU max) */
  RCCU_PLL1Config (RCCU_PLL1_Mul_24, RCCU_Div_1) ;

  while(RCCU_FlagStatus(RCCU_PLL1_LOCK) == RESET)
  {
    /* Wait PLL to lock */
  }
  /* Select PLL1_Output as RCLK clock */
  RCCU_RCLKSourceConfig (RCCU_PLL1_Output) ;  
  
  /* Enable UART0 clock on APB1 */
  APB_ClockConfig (APB1, ENABLE, UART0_Periph | UART1_Periph
                    | UART2_Periph | UART3_Periph);
 
  /* Enable GPIO0 clock on APB2 */
  APB_ClockConfig (APB2, ENABLE, GPIO0_Periph );
  
  /* GPIO configuration ------------------------------------------------------*/

  /*  Configure the GPIO pins */
  GPIO_Config(GPIO0, UARTX_Tx_Pin, GPIO_AF_PP);
  GPIO_Config(GPIO0, UARTX_Rx_Pin, GPIO_IN_TRI_CMOS);
  
  /* Configure CTS*/
  GPIO_Config(GPIO1,CTS_PIN,GPIO_OUT_PP); //CTS handshake OUT
  //GPIO_BitWrite(GPIO1,RTS_PIN_NUMBER,RTS_STOP);
  
  GPIO_BitWrite(GPIO1,CTS_PIN_NUMBER,CTS_GO);
  
  /*Configure RTS*/
  GPIO_Config(GPIO1,RTS_PIN,GPIO_IN_TRI_CMOS); //RTS handshake IN
  
  /*Configure LED*/
  led_state=0;
  GPIO_Config(GPIO1,LED_PIN,GPIO_OUT_PP); //LED for debug
  GPIO_BitWrite(GPIO1,LED_PIN_NUMBER,led_state);
 
  /* UART configuration ------------------------------------------------------*/
  UART_Init(UARTX);
  
  /*  Turn UARTX on */
  UART_OnOffConfig(UARTX, ENABLE); 
  
  /*  Disable FIFOs */      
  UART_FifoConfig (UARTX, ENABLE); 
  
  /*  Reset the UART_RxFIFO */     
  UART_FifoReset  (UARTX , UART_RxFIFO); 
  
  /*  Reset the UART_TxFIFO */
  UART_FifoReset  (UARTX , UART_TxFIFO); 
  
  /*  Disable Loop Back */
  UART_LoopBackConfig(UARTX , DISABLE);                                           
 
  /* Configure UART*/
  UART_Config(UARTX, 1000000, UART_NO_PARITY, UART_1_StopBits, UARTM_8D);
  
  /*  Enable Rx */
  UART_RxConfig(UARTX ,ENABLE); 
}