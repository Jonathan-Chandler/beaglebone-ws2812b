CC = /home/jonathan/beaglebone-compile/bin/arm-linux-gnueabihf-g++
PRCC = /home/jonathan/beaglebone-compile/pru/bin/clpru

INCLUDES = -Iinc
CFLAGS = -Wall

SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = leds

build/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)
	make -C ./pru-src all

clean:
	rm *.exe build/*.o $(OBJ_NAME)

