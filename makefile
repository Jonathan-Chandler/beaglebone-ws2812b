# CC = /home/jonathan/beaglebone-compile/bin/arm-linux-gnueabihf-g++

uname_m = $(shell uname -m)

ifeq ($(uname_m),armv7l)
CC = gcc
TEST_CC = gcc
else
CC = ../gcc/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc
TEST_CC=gcc
endif

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
ifeq ($(uname_m),armv7l)
	TARGET=main.pru0 make -C ./pru-src all
endif

test:
	make -C ./test all

mk_dirs: 
	mkdir -p build

clean:
	rm build/* leds

