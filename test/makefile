INCLUDES = -I../inc -Iinc
DEFINES = -DDEBUG_ENABLED=1
OPT = -Werror -Wall

all: build_dir
	gcc $(INCLUDES) $(DEFINES) $(OPT) -c ../src/led.c -o build/led.o
	gcc $(INCLUDES) $(DEFINES) $(OPT) -c src/main.c -o build/main.o
	gcc $(INCLUDES) $(DEFINES) $(OPT) -c src/led_test.c -o build/led_test.o
	gcc build/led.o build/led_test.o build/main.o -o main.out
	./main.out

build_dir:
	mkdir -p build

clean:
	rm -rf build/*.o main.out
