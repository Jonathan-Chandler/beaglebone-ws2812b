#ifndef __WS2812B_H__
#define __WS2812B_H__
#include <stdint.h>
#include <stdlib.h>

// __delay_cycles(100);    // 2 mhz (500 ns)
// pru @ 200 mhz
// 200,000,000 cycles         (1 second)          1 millisecond    =   200 cycles
//    1 second            (1000 milliseconds)   1000 microseconds     1 microsecond 

// 200,000,000 cycles         (1 second)          1 millisecond       1 microsecond   =     .2 cycles
//    1 second            (1000 milliseconds)   1000 microseconds   1000 nanoseconds      1 nanosecond

//    .2 cycles   =     1 cycle
//  1 nanosecond      5 nanoseconds

// 900 nanoseconds      1 cycle       =  180 cycles
//                   (5 nanoseconds)

// 350 nanoseconds      1 cycle       =  70 cycles
//                   (5 nanoseconds)

#endif

// ehrpwm1A
// U14/U3 - ZCZ Ball
// U5 - ZCE Ball
//
// U14? GPMC_A2 - signal name ehrpwm1A - mode 6
// U5 / U3 LCD_DATA10 - ehrpwm1A - mode 2
// export ehrpwm1=/sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/pwmchip2
//
// #P9.14:
// config-pin P9.14 pwm
// p9_14 = gpio_40 = $PINS 18 = 0x44e10848 = gpio_50 = U14 = mode 6 EHRPWM1A
// echo 0 > ${ehrpwm1}/export || true
// echo 20000 > ${ehrpwm1}/pwm0/period ; echo 10000 > ${ehrpwm1}/pwm0/duty_cycle
// echo 1 > ${ehrpwm1}/pwm0/enable
// echo 0 > 
// 

// /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/pwm-4:0
// echo pwm > /sys/bus/platform/drivers/bone-pinmux-helper/ocp:P9_14_pinmux/state
// 
