//------------------------------------------------------------------------
//      	Example code for MB40 LPC2103 development board
//------------------------------------------------------------------------
//					
//------------------------------------------------------------------------
// -------------------------------------------------------------------
// THIS EXAMPLE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
// INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE.
// -------------------------------------------------------------------
// Target: LPC2103  Directory: \PHIL40-03 4LED
// Code is placed in Flash - Workspace: S2_test.eww

//------------------------------------------------------------------------

//1. This is an IAR EWARM 4.40A project. Start EWARM and open the workspace.
//   Then the source files can be compiled and Intel HEX file can be created.
//   For quick start, precompiled HEX file can be found in /Debug/Exe

//2. Use Philips ISP utility to download Intel HEX file to MB40.
//   Use jumpers default settings as per MB40 manual with the exception of JP3
//   which should be in 2-3 position so that bootloader starts after Reset.
//   After downloading, change JP3 to 1-2, press Reset button.

//3. It is assumed that MB40 board is connected to the PC by using RS232 cable. 
//   Start Hyperterminal, set baud rate to 9600 Bd, no parity, 1 stop bit.
//   Make sure Handshaking is disabled (or set to XON/XOFF) !!!!
//   The text "-Type on your keyboard" is displayed. Then MB40 returns every
//   character it receives from PC.

//------------------------------------------------------------------------
// Notes for your own software development:
//1. Start by compiling projects provided by Pasat first.
//2. Use Pasat provided link file PHIL40-03_Flash.xcl. 
//   To select link file in EWARM:
//      Click Project->Options->Linker->Config
//      Check Linker Command File->Override Default
//      Type $PROJ_DIR$\PHIL40-03_Flash.xcl as linker file (code placed in LPC2103 Flash)
//   To select Intel HEX file as linker output in EWARM:
//      Click Project->Options->Linker->Output
//      Check Output File->Override Default, type output file name
//      Select Format->Other, Output Format: Intel Extended
