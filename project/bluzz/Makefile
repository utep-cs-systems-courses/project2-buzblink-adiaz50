#makfile configuration

COMMON_OBJECTS 	=

CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: bluzz.elf

#additional rules for files
bluzz.elf: ${COMMON_OBJECTS} main.o led.o buzzer.o switches.o stateMachines.o wdtinterrupthandler.o p1_interrupt_handler.o ../bluzz/timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: bluzz.elf
	msp430loader.sh bluzz.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: stateMachines.h buzzer.h switches.h

stateMachines.o: led.h stateMachines.h buzzer.h

buzzer.o: buzzer.h

