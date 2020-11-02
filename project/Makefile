# makfile configuration

COMMON_OBJECTS  = 

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h

LDFLAGS		= -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: project.elf 



#additional rules for files

project.elf: ${COMMON_OBJECTS}p1_interrupt_handler.o buzzer.o main.o stateMachines.o led.o 
switches.o wdInterruptHandler.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^



load: project.elf

	msp430loader.sh project.elf



clean:

	rm -f *.o *.elf *~



led.o: led.c led.h


buzzer.o: buzzer.h

wdInterruptHandler.o: stateMachines.h buzzer.h switches.h

stateMachines.o: buzzer.h led.h stateMachines.h

