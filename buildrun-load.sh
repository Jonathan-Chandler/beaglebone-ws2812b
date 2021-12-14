#!/bin/bash
make clean
make
./scripts/pru-build.sh
./setup-pwm.sh
./leds -l test_led_cycle.dat
