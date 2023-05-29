.PHONY: clean test

#CC = ../../toolchain/bin/arm-none-linux-gnueabihf-gcc
CC = gcc

main.out: main.c link.ld
	$(CC) -fno-pie -no-pie -o main.out -std=c99 -Wall -Wextra -pedantic main.c link.ld

test: main.out
	[ "$$(./'$<')" = "$$(printf 'adr 0x12345678\nval 0x9abcdef0\nval 0x0')" ]

clean:
	rm -f main.out
