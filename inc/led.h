#ifndef __LED_H__
#define __LED_H__

#include <stdint.h>

typedef struct
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} led_color_t;

typedef struct
{
  uint32_t led_count;
  led_color_t *led_colors;
} led_strip_t;

led_strip_t *led_strip_init(uint32_t led_count, led_color_t *default_color);
int led_strip_destroy(led_strip_t *strip);

int led_set_single(led_strip_t *strip, uint32_t index, led_color_t *new_color);
int led_set_range(led_strip_t *strip, uint32_t begin, uint32_t count, led_color_t *new_color);
int led_set_all(led_strip_t *strip, led_color_t *new_color);

#endif // __LED_H__
