#!/bin/bash
make clean
make
./scripts/pru-build.sh
./setup-pwm.sh
./leds
