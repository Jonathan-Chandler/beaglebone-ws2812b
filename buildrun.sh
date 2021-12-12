#!/bin/bash
make clean
make
./scripts/pru-build.sh
./leds
