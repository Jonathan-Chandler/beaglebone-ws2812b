#ifndef __WS2812B_H__
#define __WS2812B_H__
#include <stdint.h>
#include <stdlib.h>

// 1 cycle   = 1000 us = 1000 ms = 800 khz
// 1.250 uS     1 ms       1 s

#define WS2812_DUTY_CYCLE_SIGNAL_0      28    // 350 / 1250 = 28%
#define WS2812_DUTY_CYCLE_SIGNAL_1      72    // 900 / 1250 = 72%

#define WS2812_SHORT_SIGNAL_TIME_NS     350
#define WS2812_LONG_SIGNAL_TIME_NS      900
#define WS2812_TOTAL_SIGNAL_TIME_NS     (WS2812_LONG_SIGNAL_TIME_NS + WS2812_SHORT_SIGNAL_TIME_NS)  // 1250 ns (800 khz)

#define WS2812_0_HIGH_TIME_NS         350
#define WS2812_0_LOW_TIME_NS          900
#define WS2812_1_HIGH_TIME_NS         900
#define WS2812_1_LOW_TIME_NS          350
#define WS2812_RESET_LOW_TIME_NS      50001 // >50 us

typedef struct
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} rgb_t;

typedef struct
{
  size_t led_count;
  rgb_t *led_color;
} led_t;

void test_ws(void);
led_t* init_leds(size_t led_count);
int destroy_leds(led_t **leds);

int set_led(led_t *leds, size_t led_id, uint8_t red, uint8_t green, uint8_t blue);
int set_all_leds(led_t *leds, uint8_t red, uint8_t green, uint8_t blue);

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
