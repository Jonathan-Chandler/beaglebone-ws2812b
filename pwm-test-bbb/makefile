TI_CGT_PRU_DIR=./toolchain/share/ti-cgt-pru

CC = ../toolchain/bin/arm-none-linux-gnueabihf-gcc

CFLAGS = -Wall -ggdb

INCLUDES = -Iinc -Ipru_src
SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = bin/pwm_test
DEFINES = -DDEBUG_ENABLED=1

ASM_OBJS = $(SOURCES:src/%.c=asm/%.S)
ASM_FLAGS = -O0

build/%.o: src/%.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

asm/%.S: src/%.c
	$(CC) $(DEFINES) $(ASM_FLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

all: mk_dirs $(OBJS)
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)

test:
	make -C ./test all

mk_dirs: 
	mkdir -p build
	mkdir -p bin

asm_debug: asm_dir $(ASM_OBJS)
	$(CC) $(DEFINES) $(ASM_FLAGS) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)

asm_dir:
	mkdir -p asm

clean:
	rm build/* $(OBJ_NAME)

