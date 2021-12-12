#ifndef __LED_CYCLE_H__
#define __LED_CYCLE_H__
#include "led.h"

typedef struct
{
  uint32_t ms_delay;
  led_strip_t *led_strip;
} led_cycle_node_t;

typedef struct
{
  led_cycle_node_t *first, *last, *current;
} led_cycle_t;

led_cycle_t* led_cycle_create();
int led_cycle_destroy(led_cycle_t *cycle);
int led_cycle_check_params(led_cycle_t *led_cycle);

int led_cycle_add(led_strip_t *strip);
int led_cycle_write_current(led_cycle_t *cycle);

#endif // __LED_CYCLE_H__
