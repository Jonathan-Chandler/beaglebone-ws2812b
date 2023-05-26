CC = gcc

CFLAGS = -Wall -ggdb

SOURCES = $(wildcard src/*.c)
OBJS = $(SOURCES:src/%.c=build/%.o)
OBJ_NAME = bin/bits
DEFINES = -DDEBUG_ENABLED=1

build/%.o: src/%.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: mk_dirs $(OBJS)
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(OBJ_NAME)

mk_dirs: 
	mkdir -p build
	mkdir -p bin

clean:
	rm build/* $(OBJ_NAME)

