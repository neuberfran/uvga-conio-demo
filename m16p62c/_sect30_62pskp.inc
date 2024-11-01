;*******************************************************************************
;  Copyright 2003 	Renesas Technology America, Inc and
;  				  	Renesas Technology Corporation.
;       		  	All Rights Reserved.
;
;  sect30_62pskp.inc : Customized section and macro definitions for the RTA-M16C62P
;				   	   Starter Kit.
;				
;  Description :  This file is specific to the M3062x microcontroller and adapted 
;                 for use with the RTA-M16C62P Starter Kit. 
;
; 				  The M16C/62P's DBC irq is used instead of the UART1 irq vector 
; 				  when using the KD30 debugger with FoUSB-ICD. Not all MCU's have
;				  DBC irq. See MCU datasheet and FoUSB-ICD user's manual for details.
;=============================================================================
;       $Log:$
;			 sect30_62pskp.a30, v 1.01 2003/08/18 12:39    System LSI BU, AE
;=============================================================================                                  
;******************************************************************************

;---------------------------------------------------------------------
; HEAP SIZE definition. Only used for memory allocate functions
;  (malloc, realloc, etc). If these functions are not used, set to 0h.
;---------------------------------------------------------------------
HEAPSIZE	.equ	0h

;---------------------------------------------------------------------
; STACK SIZE definition. Unless the application is running an RTOS, both 
; interrupts and function calls should use the istack only (default startup 
; configuration). If not, set to 0h. 
;---------------------------------------------------------------------
STACKSIZE	.equ	0h

;---------------------------------------------------------------------
; INTERRUPT STACK SIZE definition
;---------------------------------------------------------------------
ISTACKSIZE	.equ	100h

;---------------------------------------------------------------------
; INTERRUPT VECTOR ADDRESS. 
;---------------------------------------------------------------------
; Do NOT set within a flash memory block used by kernel(ROM Monitor)
; during debug with KD30, which starts at 0FF900h. 
; Size of vector table is 256 bytes.
;---------------------------------------------------------------------
VECTOR_ADR 	.equ	0FD000h	; Top of Block 2

;====================================================================
; Initialize macro declarations. These macro's are used by the startup 
; file (ncrto_62pskp.a30) for initializing C variables. Clears global 
; variables, sets initialized variables, etc.
;---------------------------------------------------------------------
N_BZERO	.macro	TOP_ ,SECT_
	mov.b	#00H, R0L
	mov.w	#(TOP_ & 0FFFFH), A1
	mov.w	#sizeof SECT_ , R3
	sstr.b	
	.endm

N_BCOPY .macro	FROM_,TO_,SECT_
	mov.w	#(FROM_ & 0FFFFH),A0
	mov.b	#(FROM_ >>16),R1H
	mov.w	#TO_ ,A1
	mov.w	#sizeof SECT_ , R3
	smovf.b
	.endm

BZERO	.macro	TOP_,SECT_
	push.w	#sizeof SECT_ >> 16
	push.w	#sizeof SECT_  & 0ffffh
	pusha	TOP_ >>16
	pusha	TOP_ & 0ffffh

	.glb	_bzero	
	jsr.a	_bzero
	.endm

BCOPY	.macro	FROM_ ,TO_ ,SECT_
	push.w	#sizeof SECT_  >> 16
	push.w	#sizeof SECT_  & 0ffffh
	pusha	TO_ >>16
	pusha	TO_  & 0ffffh
	pusha	FROM_ >>16
	pusha	FROM_  & 0ffffh

	.glb	_bcopy
	jsr.a	_bcopy
	.endm

HEAPINIT .macro
	.glb	__mbase
	.glb	__mnext
	.glb	__msize
	mov.w	#(heap_top&0FFFFH), __mbase
	mov.w	#(heap_top>>16), __mbase+2
	mov.w	#(heap_top&0FFFFH), __mnext
	mov.w	#(heap_top>>16), __mnext+2
	mov.w	#(HEAPSIZE&0FFFFH), __msize
	mov.w	#(HEAPSIZE>>16), __msize+2
	.endm

;---------------------------------------------------------------
; Special Page Vectors. This macro puts the jump address of  
; functions defined as special page into the special page vector table.
; See example calls below. See the M16C Software Manual and NC30
; manual for more information on special page vectors.
;---------------------------------------------------------------
;macro define for special page
;
;Format:
;	SPECIAL	number
;

SPECIAL	.macro	NUM
	.org	0FFFFEH-(NUM*2)
	.glb	__SPECIAL_@NUM
	.word	__SPECIAL_@NUM  & 0FFFFH
.endm

;---------------------------------------------------------------
; Section Allocation. The following declarations sets the location of the
; sections in the physical memory map. Do NOT change these settings
; without referring to the NC30 manual on startup files.
;---------------------------------------------------------------
; Near RAM Data Area
;---------------------------------------------------------------
; SBDATA area
	.section	data_SE,DATA
	.org		400H

data_SE_top:

	.section	bss_SE,DATA,ALIGN
bss_SE_top:

	.section	data_SO,DATA
data_SO_top:

	.section	bss_SO,DATA
bss_SO_top:

; NEAR RAM area
	.section	data_NE,DATA,ALIGN
data_NE_top:

	.section	bss_NE,DATA,ALIGN
bss_NE_top:

	.section	data_NO,DATA
data_NO_top:

	.section	bss_NO,DATA
bss_NO_top:

;---------------------------------------------------------------
; Stack Area. If the USP is not required, and the RAM 
; allocated for the USP is needed, do not modify the declarations
; below, simply set the STACKSIZE definition (above) to zero.
;---------------------------------------------------------------
	.section	stack,DATA
	.blkb		STACKSIZE
stack_top:

	.blkb		ISTACKSIZE
istack_top:

;---------------------------------------------------------------
; Heap Section. If the heap is not required, and the RAM 
; allocated for the heap is needed, do not modify the declarations
; below, simply set the HEAPSIZE definition (above) to zero.
;---------------------.------------------------------------------
	.section	heap,DATA
heap_top:
	.blkb	HEAPSIZE

;---------------------------------------------------------------
; NEAR ROM Data Area. For "near const".
; By definition, Near ROM is all ROM below address 10000h
;
; A high Erase/Write cycle data block can be found in 0F000h to 0FFFFh. 
; However, the user program must enable access (set pm10 to 1) 
; before using it. 
; NOTE. Not all MCU's have this. See MCU datasheet for details.
;---------------------------------------------------------------
	.section	rom_NE,ROMDATA  

	.org		0F000H	; Near ROM could be Data Flash area
rom_NE_top:

	.section	rom_NO,ROMDATA
rom_NO_top:

;---------------------------------------------------------------
; FAR RAM Data Area. For "far" int's char's, etc
; By definition, far RAM is all RAM above address 0FFFFh
;---------------------------------------------------------------
	.section	data_FE,DATA
	.org		10000H ; Example. External RAM located at 10000h
data_FE_top:

	.section	bss_FE,DATA,ALIGN
bss_FE_top:
 
	.section	data_FO,DATA
data_FO_top:
 
	.section	bss_FO,DATA
bss_FO_top:

;---------------------------------------------------------------
; FAR ROM Data Area
;---------------------------------------------------------------
	.section	rom_FE,ROMDATA
	.org		0D0000H
rom_FE_top:

	.section	rom_FO,ROMDATA
rom_FO_top:

;---------------------------------------------------------------
; Initial data of 'data' section
;---------------------------------------------------------------
	.section	data_SEI,ROMDATA
data_SEI_top:

	.section	data_SOI,ROMDATA
data_SOI_top:

	.section	data_NEI,ROMDATA
data_NEI_top:
 
	.section	data_NOI,ROMDATA
data_NOI_top:
 
	.section	data_FEI,ROMDATA
data_FEI_top:
 
	.section	data_FOI,ROMDATA
data_FOI_top:

;---------------------------------------------------------------
; Switch Table Section
;---------------------------------------------------------------
	.section        switch_table,ROMDATA
switch_table_top:
 
;---------------------------------------------------------------
; Code Area
;---------------------------------------------------------------
	.section	interrupt

	.section	program

	.section	program_S	; special page code must be in the
	.org		0F0000h     ; address range of F0000h to FFFDCh
							; ROM start address will vary depending on 
							; MCU used - see MCU datasheet for details

;---------------------------------------------------------------
; Variable Vector Section
; For proper interrupt operation, replace "dummy_int" with the assembler
; label or absolute address of the interrupt service routine
; dummy_int routine can be found in ncrt0_62pskp.a30.
;---------------------------------------------------------------
	.section	vector		; variable vector table
	.org		VECTOR_ADR 

	.lword	dummy_int		; BRK						(vector 0)
	.org	(VECTOR_ADR+16)
	.lword	dummy_int		; INT3						(vector 4)
	.lword	dummy_int		; Timer B5					(vector 5)
	.lword	dummy_int		; Timer B4 / UART1 bus collision (vector 6)
	.lword	dummy_int		; timerB3 /UART0 bus collision (vector 7)
	.lword	dummy_int		; SI/O4/INT5				(vector 8)
	.lword	dummy_int		; SI/O3/INT4				(vector 9)
	.lword	dummy_int		; UART2 Bus collision 		(vector 10)
	.lword	dummy_int		; DMA0						(vector 11)
	.lword	dummy_int		; DMA1						(vector 12)
	.lword	dummy_int		; Key input interrupt		(vecttor 14)
	.lword	dummy_int		; A-D						(vector 14)
	.lword	dummy_int		; UART2 transmit/NACK2		(vector 15)
	.lword	dummy_int		; UART2 receive/ACK2		(vector 16)
	.lword	dummy_int		; UART0 transmit/NACK0		(vector 17)
	.lword	dummy_int		; UART0 receive/ACK0		(vector 18)
	.lword	dummy_int  		; UART1 transmit/NACK1		(vector 19)
	.lword	dummy_int		; UART1 receive/ACK1		(vector 20) - Not needed: KD30+FoUSB-ICD will use M16C/62P DBC irq
	.lword	dummy_int   	; Timer A0					(vector 21)
	.lword	dummy_int		; Timer A1					(vector 22)
	.lword	dummy_int		; Timer A2					(vector 23)
	.lword	dummy_int		; Timer A3					(vector 24)
	.lword	dummy_int		; Timer A4					(vector 25)
	.lword	dummy_int		; Timer B0					(vector 26)
	.lword	dummy_int		; Timer B1					(vector 27)
	.lword	dummy_int		; Timer B2					(vector 28)
	.lword	dummy_int		; INT0						(vector 29)
	.lword	dummy_int		; INT1						(vector 30)
	.lword	dummy_int		; INT2						(vector 31)
	.lword	dummy_int		; vector 32 (for user or RTOS)
	; to vector 63 from vector 32 is used by an RTOS 

;===============================================================
; Fixed Vector Section
;---------------------------------------------------------------
	.section	fvector			; fixed vector table

;===============================================================
; Special Page Definition
;---------------------------------------------------------------
; Set-up special page vector table. Calls the macro "SPECIAL" to put
; the jump addresses of functions defined as special page into the 
; special page vector table. Uncomment the line below that corresponds 
; to the C function defined using the "#pragma SPECIAL" directive. See
; the M16C Software Manual and the NC30 manual for more information 
; on special page vectors.
;---------------------------------------------------------------
;	SPECIAL 255  ; example use
;	SPECIAL 254
;	SPECIAL 253
;	   :
;	   :
;	  etc
;	   :
;	   :
;	SPECIAL 24
;	SPECIAL 23
;	SPECIAL 22
;	SPECIAL 21
;	SPECIAL 20
;	SPECIAL 19
;	SPECIAL 18
;
;===============================================================
; Fixed Vector Section. 
; The 7 or'ed values below (commented out) are for specifying 
; the ID codes for serial I/O flash programming (highest 8 bits 
; of the vectors). See See MCU datasheets for details.
;
; Current setting = all zeros by default.
;
; The highest 8 bits of the reset vector is the parallel protection
; 'register'.
; 
;===============================================================
; CAUTION!! CAUTION!! CAUTION!! 
;===============================================================
; Setting these codes could result in loss of all flash programming. 
; See MCU datasheet before operating on these values.
;---------------------------------------------------------------
	.org	0FFFDCH
UDI:                  
	.lword	dummy_int ;  | 0ff000000h 
OVER_FLOW:
	.lword	dummy_int ;  | 0ff000000h 
BRKI:
	.lword	dummy_int   
ADDRESS_MATCH:
	.lword	dummy_int ;  | 0ff000000h 
SINGLE_STEP:
	.lword	dummy_int ;  | 0ff000000h   
WDT:
	.lword	dummy_int ;  | 0ff000000h  
DBC:
	.lword	dummy_int ;  | 0ff000000h
NMI:
	.lword	dummy_int ;  | 0ff000000h
RESET:
	.lword	start ;      | 0ff000000h     
;
