TI_CGT_PRU_DIR=./toolchain/share/ti-cgt-pru

CC = ../toolchain/bin/arm-none-linux-gnueabihf-gcc
READELF = ../toolchain/bin/arm-none-linux-gnueabihf-readelf
# ../toolchain/bin/arm-none-linux-gnueabihf-readelf -l ./build/*
# ../toolchain/bin/arm-none-linux-gnueabihf-readelf -l ./pwm_test

# jonathan@jonathan-amd  ~/work/bbb/beaglebone-ws2812b/pwm-test-bbb   led-tdd-rework ±  ../toolchain/bin/arm-none-linux-gnueabihf-readelf -l ./pwm_test
#
#Elf file type is DYN (Shared object file)
#Entry point 0x6dd
#There are 9 program headers, starting at offset 52
#
#Program Headers:
#  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
#  EXIDX          0x0024c0 0x000024c0 0x000024c0 0x00008 0x00008 R   0x4
#  PHDR           0x000034 0x00000034 0x00000034 0x00120 0x00120 R   0x4
#  INTERP         0x000154 0x00000154 0x00000154 0x00019 0x00019 R   0x1
#      [Requesting program interpreter: /lib/ld-linux-armhf.so.3]
#  LOAD           0x000000 0x00000000 0x00000000 0x024cc 0x024cc R E 0x10000
#  LOAD           0x002e84 0x00012e84 0x00012e84 0x00184 0x00188 RW  0x10000
#  DYNAMIC        0x002e8c 0x00012e8c 0x00012e8c 0x00108 0x00108 RW  0x4
#  NOTE           0x000170 0x00000170 0x00000170 0x00020 0x00020 R   0x4
#  GNU_STACK      0x000000 0x00000000 0x00000000 0x00000 0x00000 RW  0x10
#  GNU_RELRO      0x002e84 0x00012e84 0x00012e84 0x0017c 0x0017c R   0x1
#
# Section to Segment mapping:
#  Segment Sections...
#   00     .ARM.exidx 
#   01     
#   02     .interp 
#   03     .interp .note.ABI-tag .hash .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rel.dyn .rel.plt .init .plt .text .fini .rodata .ARM.exidx .eh_frame 
#   04     .init_array .fini_array .dynamic .got .data .bss 
#   05     .dynamic 
#   06     .note.ABI-tag 
#   07     
#   08     .init_array .fini_array .dynamic .got 


CFLAGS = -ggdb -std=c99 -Wall -Wextra

INCLUDES = -Iinc -Ipru_src
SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = bin/pwm_test
DEFINES = -DDEBUG_ENABLED=1
#DEFINES = -DDEBUG_ENABLED=1 -fno-pie -no-pie -std=c99 -Wall -Wextra

ASM_OBJS = $(SOURCES:src/%.c=asm/%.S)
ASM_FLAGS = -O0

build/%.o: src/%.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

asm/%.S: src/%.c
	$(CC) $(DEFINES) $(ASM_FLAGS) $(CFLAGS) $(INCLUDES) -S $< -o $@

all: mk_dirs $(OBJS)
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -o $(OBJ_NAME) $(OBJS)
	#$(CC) -fno-pie -no-pie -o bin/pwm_test -std=c99 -Wall -Wextra -pedantic link.ld ./src/main.c

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

