#ifndef __WS2812B_H__
#define __WS2812B_H__
#include <stdint.h>
#include <stdlib.h>

// 1 cycle   = 1000 us = 1000 ms = 800 khz
// 1.250 uS     1 ms       1 s

#define WS2812_LED_COUNT              140 // 150 leds

#define WS2812_DUTY_CYCLE_SIGNAL_0    28    // 350 / 1250 = 28%
#define WS2812_DUTY_CYCLE_SIGNAL_1    72    // 900 / 1250 = 72%

#define WS2812_SHORT_SIGNAL_TIME_NS   350
#define WS2812_LONG_SIGNAL_TIME_NS    900
#define WS2812_TOTAL_SIGNAL_TIME_NS   (WS2812_LONG_SIGNAL_TIME_NS + WS2812_SHORT_SIGNAL_TIME_NS)  // 1250 ns (800 khz)

#define WS2812_0_HIGH_TIME_NS         350
#define WS2812_0_LOW_TIME_NS          900
#define WS2812_1_HIGH_TIME_NS         900
#define WS2812_1_LOW_TIME_NS          350
#define WS2812_RESET_LOW_TIME_NS      50001 // >50 us

#define WS2812_GREEN_OFFSET           0
#define WS2812_GREEN_MASK             (0xFF << WS2812_GREEN_OFFSET)
#define WS2812_RED_OFFSET             8
#define WS2812_RED_MASK               (0xFF << WS2812_RED_OFFSET)
#define WS2812_BLUE_OFFSET            16
#define WS2812_BLUE_MASK              (0xFF << WS2812_BLUE_OFFSET)

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
