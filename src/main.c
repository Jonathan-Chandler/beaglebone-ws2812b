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

pru_shmem_t *global_pru_shmem;

int main(void)
{
  global_pru_shmem = shmem_allocate();
  led_cycle_t *led_cycle = NULL;
  led_strip_t *led_strip = NULL;
  led_strip_t *led_strip2 = NULL;
  led_strip_t *led_strip3 = NULL;
  led_color_t *default_color = NULL;
  led_color_t *default_color2 = NULL;
  led_color_t *default_color3 = NULL;

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
  default_color = led_color_init(0, 0, 255);
  if (default_color == NULL)
  {
    printDebug("Fail default_color allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for strip 2
  default_color2 = led_color_init(0, 255, 0);
  if (default_color2 == NULL)
  {
    printDebug("Fail default_color2 allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for strip 3
  default_color3 = led_color_init(255, 0, 0);
  if (default_color3 == NULL)
  {
    printDebug("Fail default_color3 allocate\n");
    goto EXIT_FAIL;
  }

  // create led strip with default color
  led_strip = led_strip_init(WS2812_LED_COUNT, default_color);
  if (led_strip == NULL)
  {
    printDebug("Fail led_strip allocate\n");
    goto EXIT_FAIL;
  }

  // create led strip with default color 2
  led_strip2 = led_strip_init(WS2812_LED_COUNT, default_color2);
  if (led_strip2 == NULL)
  {
    printDebug("Fail led_strip2 allocate\n");
    goto EXIT_FAIL;
  }

  // create led strip with default color 3
  led_strip3 = led_strip_init(WS2812_LED_COUNT, default_color3);
  if (led_strip2 == NULL)
  {
    printDebug("Fail led_strip2 allocate\n");
    goto EXIT_FAIL;
  }

  // add led strip to linked list
  if (led_cycle_node_add(led_cycle, 10000, led_strip))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

  // add led strip to linked list
  if (led_cycle_node_add(led_cycle, 10000, led_strip2))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

  // add led strip to linked list
  if (led_cycle_node_add(led_cycle, 10000, led_strip3))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

//  while (1)
//  {
  // attempt writing to LEDs
  led_cycle_write_and_iterate(led_cycle);
  led_cycle_write_and_iterate(led_cycle);
  led_cycle_write_and_iterate(led_cycle);
//  }

  led_color_destroy(&default_color);
  led_color_destroy(&default_color2);
  led_color_destroy(&default_color3);
  //led_strip_destroy(led_strip);
  //led_strip_destroy(led_strip2);
  //led_strip_destroy(led_strip3);
  led_cycle_destroy(&led_cycle);
  shmem_deallocate(&global_pru_shmem);

  return 0;

EXIT_FAIL:
  led_color_destroy(&default_color);
  led_color_destroy(&default_color2);
  //led_strip_destroy(led_strip);
  //led_strip_destroy(led_strip2);
  //led_strip_destroy(led_strip3);
  led_cycle_destroy(&led_cycle);
  shmem_deallocate(&global_pru_shmem);

  return -1;
}

