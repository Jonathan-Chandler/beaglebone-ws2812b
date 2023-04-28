#ifndef __SHARE_H__
#define __SHARE_H__
// 1 cycle   = 1000 us = 1000 ms = 800 khz
// 1.250 uS     1 ms       1 s

#define WS2812_LED_COUNT              150 // 150 leds

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


#define SHARED_MEM_MAP_FILE   "/dev/mem"
//#define AM33XX_PRUSS_SHAREDRAM_BASE		0x4a310000
#define SHARED_MEM_START_ADDR 0x4A310000

#define SHARED_MEM_LED_BEGIN_WRITE_OFFSET 0x0
#define SHARED_MEM_LED_COUNT_OFFSET       0x1
#define SHARED_MEM_LED_START_OFFSET       0x2
#define WS2812_LED_COUNT                  150 // 150 leds
#define WS2812_LED_BIT_COUNT              24  // 24 bits per led - 8 bits each red/green/blue


#define SHARED_MEM_SIZE       ((WS2812_LED_COUNT + SHARED_MEM_LED_START_OFFSET) * sizeof(uint32_t))


#endif
