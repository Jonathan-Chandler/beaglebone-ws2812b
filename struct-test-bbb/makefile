TI_CGT_PRU_DIR=./toolchain/share/ti-cgt-pru

ifeq ($(localtest),)
CC = ../toolchain/bin/arm-none-linux-gnueabihf-gcc
else
CC = gcc
endif

CFLAGS = -Wall

INCLUDES = -Iinc -Ipru_src
SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = bin/struct_test
DEFINES = -DDEBUG_ENABLED=1

build/%.o: src/%.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: mk_dirs $(OBJS)
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)

test:
	make -C ./test all

mk_dirs: 
ifneq ($(localtest),)
	@echo "------------------------LOCAL TEST------------------------"
endif
	mkdir -p build
	mkdir -p bin

clean:
	rm build/* $(OBJ_NAME)

