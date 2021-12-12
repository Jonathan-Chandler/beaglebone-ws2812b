#include <sys/types.h>
//#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "debug.h"
#include "pru_shmem.h"
#include "led.h"
#include "led_cycle.h"
#include "ws2812b.h"
#include "share.h"

extern uint32_t *leds;

pru_shmem_t *global_pru_shmem;

int main(void)
{
  global_pru_shmem = shmem_allocate();
  led_cycle_t *led_cycle = NULL;
  led_strip_t *led_strip = NULL;
  led_color_t *default_color = NULL;

  // allocate shared mem to communicate to PRU
  if (global_pru_shmem == NULL)
  {
    printDebug("Fail shmem allocate\n");
    goto EXIT_FAIL;
  }

  // create led cycle linked list
  led_cycle = led_cycle_create();
  if (led_cycle == NULL)
  {
    printDebug("Fail led_cycle allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for strip
  default_color = led_color_init(200, 0, 200);
  if (default_color == NULL)
  {
    printDebug("Fail default_color allocate\n");
    goto EXIT_FAIL;
  }

  // create led strip with default color
  led_strip = led_strip_init(WS2812_LED_COUNT, default_color);
  if (led_strip == NULL)
  {
    printDebug("Fail default_color allocate\n");
    goto EXIT_FAIL;
  }

  // add led strip to linked list
  if (led_cycle_add_node(led_cycle, 10000, led_strip))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

//  while (1)
//  {
  // attempt writing to LEDs
  led_cycle_write_current(led_cycle);
//  }

  shmem_deallocate(global_pru_shmem);

  return 0;

EXIT_FAIL:
  led_color_destroy(&default_color);
  led_strip_destroy(led_strip);
  led_cycle_destroy(&led_cycle);
  shmem_deallocate(&global_pru_shmem);

  return -1;
}

#if 0
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
#endif

