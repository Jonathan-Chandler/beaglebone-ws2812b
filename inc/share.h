#ifndef __SHARE_H__
#define __SHARE_H__

#define SHARED_MEM_MAP_FILE   "/dev/mem"
#define SHARED_MEM_START_ADDR 0x4a310000

#define SHARED_MEM_LED_BEGIN_WRITE_OFFSET 0x0
#define SHARED_MEM_LED_COUNT_OFFSET       0x1
#define SHARED_MEM_LED_START_OFFSET       0x2
#define WS2812_LED_COUNT                  140 // 150 leds
#define WS2812_LED_BIT_COUNT              24  // 24 bits per led - 8 bits each red/green/blue


#define SHARED_MEM_SIZE       ((WS2812_LED_COUNT + SHARED_MEM_LED_START_OFFSET) * sizeof(uint32_t))


#endif
