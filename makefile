# CC = /home/jonathan/beaglebone-compile/bin/arm-linux-gnueabihf-g++
CC = gcc
PRCC = /home/jonathan/beaglebone-compile/pru/bin/clpru

INCLUDES = -Iinc -Ipru_src
CFLAGS = -Wall

SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = leds

build/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)
	TARGET=main.pru0 make -C ./pru-src all

clean:
	rm build/* leds

