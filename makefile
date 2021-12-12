# CC = /home/jonathan/beaglebone-compile/bin/arm-linux-gnueabihf-g++
CC = gcc
PRCC = /home/jonathan/beaglebone-compile/pru/bin/clpru

INCLUDES = -Iinc -Ipru_src
CFLAGS = -Wall

SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = leds
DEFINES = -DDEBUG_ENABLED=1

build/%.o: src/%.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: mk_dirs $(OBJS)
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)
	#TARGET=main.pru0 make -C ./pru-src all
	make -C ./test all

mk_dirs: 
	mkdir -p build

clean:
	rm build/* leds

