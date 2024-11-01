/*
 AT91SAM7A3 startup code
 Written by Martin Hinner <hinner@secons.com>
*/

#define RAM_BASE	              (0x00200000) // Internal SRAM base address
#define RAM_SIZE	         (0x00004000) // Internal SRAM size in byte (16 Kbytes)


#define USR_STACK_SIZE  1024
#define USR_STACK_POINTER (RAM_BASE + RAM_SIZE)

#define Mode_USR    0x10
#define Mode_FIQ    0x11
#define Mode_IRQ    0x12
#define Mode_SVC    0x13
#define Mode_ABT    0x17
#define Mode_UNDEF  0x1B
#define Mode_SYS    0x1F

#define I_Bit      0x80
#define F_Bit      0x40

	.text


	.global __vectors

__vectors:
	ldr pc, reset_addr
	ldr pc, undef_addr
	ldr pc, swi_addr
	ldr pc, prefetch_addr
	ldr pc, abort_addr
	nop				@ reserved
	ldr pc, irq_addr
	ldr pc, fiq_addr

reset_addr:
	.word startup_routine
undef_addr:
        .word undef_routine
swi_addr:
        .word 0
prefetch_addr:
        .word abort_routine
abort_addr:
        .word abort_routine
irq_addr:
        .word irq_routine
fiq_addr:
        .word abort_routine

	.global _start
	.extern main
	.extern LowLevelInit

        .global startup_routine
        .global undef_routine
        .global swi_routine
        .global abort_routine
        .global irq_routine



_start:
startup_routine:

	msr cpsr_c, #Mode_SYS | I_Bit | F_Bit
	ldr SP,=USR_STACK_POINTER
	bl LowLevelInit

	msr cpsr_c, #Mode_IRQ | F_Bit | I_Bit
	ldr SP,=(USR_STACK_POINTER-USR_STACK_SIZE-4)

	msr cpsr_c, #Mode_UNDEF | F_Bit | I_Bit
	ldr SP,=(USR_STACK_POINTER-USR_STACK_SIZE-USR_STACK_SIZE-4)

	msr cpsr_c, #Mode_FIQ | F_Bit | I_Bit
	ldr SP,=(USR_STACK_POINTER-USR_STACK_SIZE-USR_STACK_SIZE-USR_STACK_SIZE-4)

	msr cpsr_c, #Mode_ABT | F_Bit | I_Bit
	ldr SP,=(USR_STACK_POINTER-USR_STACK_SIZE-USR_STACK_SIZE-USR_STACK_SIZE-USR_STACK_SIZE-4)
	msr cpsr_c, #Mode_SVC | F_Bit | I_Bit
	ldr SP,=(USR_STACK_POINTER-USR_STACK_SIZE-USR_STACK_SIZE-USR_STACK_SIZE-USR_STACK_SIZE-USR_STACK_SIZE-4)

	msr cpsr_c, #Mode_SYS
	ldr SP,=USR_STACK_POINTER

	b main

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

abort_routine:
undef_routine:
irq_routine:
	b irq_routine
