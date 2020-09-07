CC = /home/jonathan/beaglebone-compile/pru/bin/clpru
CFLAGS = --run_linker
LIBS = --library=/home/jonathan/beaglebone-compile/pru/lib/rtspruv3_le.lib
INCLUDES = -I=/home/jonathan/beaglebone-compile/pru/include/


all: main.c
	$(CC) main.c $(INCLUDES) $(CFLAGS) $(LIBS)

clean:
	rm *.obj *.out

