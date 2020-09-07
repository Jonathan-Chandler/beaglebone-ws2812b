#!/bin/bash
ssh jonathan@192.168.1.180 rm -rf /home/jonathan/leds
ssh jonathan@192.168.1.180 mkdir /home/jonathan/leds
scp -r * jonathan@192.168.1.180:/home/jonathan/leds/

