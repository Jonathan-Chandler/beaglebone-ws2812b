TI_CGT_PRU_DIR=./toolchain/share/ti-cgt-pru

CC = ../toolchain/bin/arm-none-linux-gnueabihf-gcc

CFLAGS = -Wall

INCLUDES = -Iinc -Ipru_src
SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = bin/pwm_test
DEFINES = -DDEBUG_ENABLED=1

build/%.o: src/%.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: mk_dirs $(OBJS)
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)

test:
	make -C ./test all

mk_dirs: 
	mkdir -p build
	mkdir -p bin

clean:
	rm build/* $(OBJ_NAME)

