
INCLUDE=-I /opt/ti-pru-cgt/include -I ../inc

LD=../toolchain/share/ti-cgt-pru/bin/lnkpru -o
LDFLAGS=--reread_libs --warn_sections --stack_size=0x100 --heap_size=0x100 -m $(basename $(1)).map \
	-i$(PRU_CGT)/lib -i$(PRU_CGT)/include $(COMMON)/$(CHIP)_$(PROC).cmd --library=libc.a \
	--library=$(PRU_SUPPORT)/lib/rpmsg_lib.lib
# CC=clpru -fe
#CC = ../toolchain/share/ti-cgt-pru/bin/clpru -fe

# PATH=/opt/ti-pru-cgt/bin:$PATH
CC=/opt/ti-pru-cgt/bin/clpru
#CFLAGS=--include_path=$(COMMON) --include_path=$(PRU_SUPPORT)/include \
#--include_path=$(PRU_SUPPORT)/include/$(CHIP_REV) \
#--include_path=$(PRU_CGT)/include -DCHIP=$(CHIP) -DCHIP_IS_$(CHIP) -DMODEL=$(MODEL) -DPROC=$(PROC) -DPRUN=$(PRUN) \
#-v3 -O2 --printf_support=minimal --display_error_number --endian=little --hardware_mac=on \
#--obj_directory=$(GEN_DIR) --pp_directory=$(GEN_DIR) --asm_directory=$(GEN_DIR) -ppd -ppa --asm_listing \
#--c_src_interlist

all: main.pru0.out
#	clpru main.pru0.o -o main.pru0.out am335x_pru.cmd

main.pru0.o: main.pru0.c
	$(CC) $(INCLUDE) -o main.pru0.o -c main.pru0.c

main.pru0.out: main.pru0.c
	#$(CC) main.pru0.c $(INCLUDE) -i /opt/ti-pru-cgt/lib -z -o main.pru0.out am335x_pru.cmd
	$(CC) main.pru0.c $(INCLUDE) -z -o main.pru0.out am335x_pru.cmd -i /opt/ti-pru-cgt/lib 

clean:
	rm -rf main.obj
	rm -rf main.pru0.o
	rm -rf main.pru0.obj
	rm -rf main.pru0.out
