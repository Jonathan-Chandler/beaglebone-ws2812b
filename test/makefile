CC = gcc
INCLUDES = -I../inc -Iinc
CFLAGS = -Werror -Wall
DEFINES = -DDEBUG_ENABLED=1

SOURCES = $(wildcard ../src/*.c)
SOURCES := $(filter-out ../src/main.c, $(SOURCES))
SOURCES := $(wildcard src/*.c)

OBJS := $(wildcard ../build/*.o)
OBJS := $(filter-out ../build/main.o, $(OBJS))

TEST_OBJS := $(SOURCES:src/%.c=build/%.o)
TEST_OBJ_NAME = led_test.out

all: build_dir $(TEST_OBJS)
	gcc $(INCLUDES) $(DEFINES) $(CFLAGS) $(OBJS) $(TEST_OBJS) -o $(TEST_OBJ_NAME)
	./led_test.out

#	gcc $(INCLUDES) $(DEFINES) $(CFLAGS) -c ../src/led.c -o build/led.o
#	gcc $(INCLUDES) $(DEFINES) $(CFLAGS) -c src/main.c -o build/main.o
#	gcc $(INCLUDES) $(DEFINES) $(CFLAGS) -c src/led_test.c -o build/led_test.o
build/%.o: src/%.c
	$(CC) $(DEFINES) $(CFLAGS) $(INCLUDES) -c $< -o $@

build_dir:
	mkdir -p build

clean:
	rm -rf build/*.o main.out
