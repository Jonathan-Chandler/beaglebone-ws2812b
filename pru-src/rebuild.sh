#!/bin/bash
make clean
make
scp main.pru0.out root@192.168.50.3:/home/root
