#!/bin/bash
make clean
make
scp -r * jonathan@192.168.1.180:/home/jonathan/leds
