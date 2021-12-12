#!/bin/bash
BBB_IP_ADDR=192.168.4.84

make clean
make
scp -r * jonathan@$BBB_IP_ADDR:/home/jonathan/leds
