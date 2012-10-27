CC=msp430-gcc
CFLAGS=-O2 -g -mmcu=msp430x2012
 
OBJS=main.o
 
all: $(OBJS)
	$(CC) $(CFLAGS) -o main.elf $(OBJS)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $<
 
clean:
	rm -fr main.elf $(OBJS)
.PHONY: clean
 
program: $(OBJS)
	$(CC) $(CFLAGS) -o main.elf $(OBJS)
	mspdebug uif -j -d /dev/ttyUSB0 "prog main.elf"
.PHONY: program
