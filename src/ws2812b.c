#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "ws2812b.h"

void test_ws()
{
  printf("testws\n");
}

led_t *init_leds(size_t led_count)
{
  led_t *led_temp = calloc(1, sizeof(led_t));
  if (!led_temp)
  {
    return 0;
  }

  rgb_t *rgb_temp = calloc(led_count, sizeof(rgb_t));
  if (!rgb_temp)
  {
    return 0;
  }
  
  led_temp->led_count = led_count;
  led_temp->led_color = rgb_temp;

  return led_temp;
}

int destroy_leds(led_t **leds)
{
  free((*leds)->led_color);
  free(*leds);
  *leds = (void *) 0;
  return 0;
}

int set_led(led_t *leds, size_t led_id, uint8_t red, uint8_t green, uint8_t blue)
{
  if (!leds)
  {
    return -1;
  }

  if (!leds->led_color)
  {
    return -1;
  }

  if (led_id >= leds->led_count)
  {
    return -1;
  }

  leds->led_color[led_id].red = red;
  leds->led_color[led_id].green = green;
  leds->led_color[led_id].blue = blue;

  return 0;
}

int set_all_leds(led_t *leds, uint8_t red, uint8_t green, uint8_t blue)
{
  if (!leds)
  {
    return -1;
  }

  if (!leds->led_color)
  {
    return -1;
  }

  for (size_t i = 0; i < leds->led_count; i++)
  {
    leds->led_color[i].red = red;
    leds->led_color[i].green = green;
    leds->led_color[i].blue = blue;
  }

  return 0;
}


