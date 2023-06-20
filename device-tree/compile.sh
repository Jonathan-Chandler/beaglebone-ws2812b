#!/bin/bash
IDE=BB-PWM2-00A0
SRC=$IDE.dts
TMP=$IDE.tmp.dts
DST=$IDE.dtb

cpp -nostdinc -I include -undef -x assembler-with-cpp $SRC > $TMP
dtc -O dtb -b 0 -o $DST $TMP
rm $TMP

