#!/bin/bash
BBB_IP_ADDR=192.168.4.84
ssh jonathan@$BBB_IP_ADDR rm -rf /home/jonathan/leds
ssh jonathan@$BBB_IP_ADDR mkdir /home/jonathan/leds
scp -r * jonathan@$BBB_IP_ADDR:/home/jonathan/leds/

