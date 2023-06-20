dd bs=1 if=main.pru0.out of=/dev/mem seek=1244872704 count=33300 conv=notrunc
dd bs=1 of=test.out if=/dev/mem skip=1244872704 count=33300 conv=notrunc
dd bs=1 of=test.out if=/dev/mem skip=0x4A334000 count=33300 conv=notrunc

dd bs=1 count=1 of=test.out if=/dev/mem skip=1244872704 count=33300 conv=notrunc
