
all:	code.bin

CC = arm-elf-gcc
LD = arm-elf-ld
OBJCOPY = arm-elf-objcopy
OBJDUMP = arm-elf-objdump

OBJ = startup.o main.o hw_at91sam7s.o conio.o ui.o 

code.bin:	$(OBJ)
	$(LD) -Ttext 0x000  $(OBJ)  libgcc.a -o code.elf 
	$(OBJCOPY)  -v -O binary code.elf code.bin
	$(OBJDUMP)  --disassemble-all code.elf >code.dis

startup.o:	startup.S
	$(CC) $(CFLAGS) -c $<


conio.o:	../lib/conio.c
	$(CC) $(CFLAGS) -c $<

ui.o:	../lib/ui.c
	$(CC) $(CFLAGS) -c $<

main.o:	../main.c
	$(CC) $(CFLAGS) -c $<
