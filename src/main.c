#include <sys/types.h>
//#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "pru_shmem.h"
#include "led.h"
#include "ws2812b.h"
#include "share.h"

extern uint32_t *leds;

int main(void)
{
  uint32_t menu_selection;
  uint32_t red_value;
  uint32_t green_value;
  uint32_t blue_value;
  uint32_t color_value;
  uint32_t led_num;

  for (led_num = 0; led_num < WS2812_LED_COUNT; led_num++)
  {
    leds[led_num] = 0;
  }

  while (1)
  {
    printf("0: Exit\n");
    printf("1: Set colors\n");
    printf("2: Synchronize\n");
    scanf("%d", &menu_selection);

    if (menu_selection < 1 || menu_selection > 2)
    {
      break;
    }
    else if (menu_selection == 1)
    {
      printf("Red: ");
      scanf("%u", &red_value);
      printf("Green: ");
      scanf("%u", &green_value);
      printf("Blue: ");
      scanf("%u", &blue_value);

      red_value = reverse_8bit(red_value);
      green_value = reverse_8bit(green_value);
      blue_value = reverse_8bit(blue_value);

      color_value  = (red_value << WS2812_RED_OFFSET) & WS2812_RED_MASK;
      color_value |= (green_value << WS2812_GREEN_OFFSET) & WS2812_GREEN_MASK;
      color_value |= (blue_value << WS2812_BLUE_OFFSET) & WS2812_BLUE_MASK;

      for (led_num = 0; led_num < WS2812_LED_COUNT; led_num++)
      {
        leds[led_num] = color_value;
      }

      synchronize_leds(WS2812_LED_COUNT);
    }
    else if (menu_selection == 2)
    {
      synchronize_leds(WS2812_LED_COUNT);
    }
  }

  return 0;
}

