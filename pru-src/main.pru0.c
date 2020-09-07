// Programmable Real-time Unit Industrial Control SubSystem (PRU-ICSS) 
// /home/jonathan/beaglebone-compile/pru/bin/clpru
// #include <stdint.h>

// /sys/devices/platform/ocp/4a326004.pruss-soc-bus/4a300000.pruss/
// "P8_27 P8_28 P8_29 P8_30 P8_39 P8_40 P8_41 P8_42"
//
// /sys/devices/platform/ocp/ocp\:P9_27_pinmux/subsystem/devices/44e07000.gpio/driver/481ae000.gpio/gpiochip3/gpio/gpio105/value
// /sys/devices/platform/ocp/ocp\:P9_27_pinmux/
// echo 105 > ./sys/class/gpio/export
// echo out > /sys/devices/platform/ocp/ocp\:P9_27_pinmux/subsystem/devices/44e07000.gpio/driver/481ae000.gpio/gpiochip3/gpio/gpio105/direction
// echo 1 > /sys/class/gpio/gpio105/value
//
// P9_27_pinmux - pin 105 - pru 31_5
//    echo $pin
//    config-pin $pin pruout
//    config-pin -q $pin

#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"
#include "prugpio.h"

volatile register unsigned int __R30;
volatile register unsigned int __R31;

void main(void) 
{
	int i;

	uint32_t *gpio1 = (uint32_t *)GPIO1;
  // AM33XX_PRUSS_SHAREDRAM_BASE = 0x4a310000
  // PRU_SHAREDMEM   : org = 0x00010000 len = 0x00003000 CREGISTER=28 /* 12kB Shared RAM */
  uint32_t *shared_mem = (uint32_t *)AM33XX_PRUSS_SHAREDRAM_BASE;
//  printf("test\n");
	
	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

//  while (true)
//  {
    for(i=0; i<1000; i++) 
    {
      shared_mem[i] = 0xAABB;
    }

    for(i=0; i<1000; i++) 
    {
    }

    for(i=0; i<10; i++) 
    {
      gpio1[GPIO_SETDATAOUT]   = USR1;			// The the USR3 LED on
      gpio1[GPIO_CLEARDATAOUT] = USR2;

      // __R30 |= gpio;		// Set the GPIO pin to 1

      __delay_cycles(500000000/5);    // Wait 1/2 second

      gpio1[GPIO_CLEARDATAOUT] = USR1;
      gpio1[GPIO_SETDATAOUT]   = USR2;

      // __R30 &= ~gpio;		// Clearn the GPIO pin

      __delay_cycles(500000000/5); 
    }
//  }
	__halt();
}

// Turns off triggers
#pragma DATA_SECTION(init_pins, ".init_pins")
#pragma RETAIN(init_pins)
const char init_pins[] =  
	"/sys/class/leds/beaglebone:green:usr1/trigger\0none\0" \
	"/sys/class/leds/beaglebone:green:usr2/trigger\0none\0" \
	"\0\0";

