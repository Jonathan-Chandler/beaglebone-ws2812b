#!/bin/bash
dd bs=1 skip="$((0x4a310000))" count=4 if="/dev/mem" |
  od -An -vtu4
