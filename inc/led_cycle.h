#ifndef __LED_CYCLE_H__
#define __LED_CYCLE_H__
#include "led.h"

typedef struct led_cycle_node_t
{
  uint32_t ms_delay;
  led_strip_t *led_strip;
  struct led_cycle_node_t *next;
} led_cycle_node_t;

typedef struct
{
  led_cycle_node_t *first, *last, *current;
} led_cycle_t;

led_cycle_t* led_cycle_create();
int led_cycle_destroy(led_cycle_t **cycle);
int led_cycle_node_destroy(led_cycle_node_t **led_cycle_node);
int led_cycle_check_params(led_cycle_t *led_cycle);

int led_cycle_add_node(led_cycle_t *led_cycle, uint32_t display_time_ms, led_strip_t *led_strip);
int led_cycle_write_current(led_cycle_t *cycle);
int led_cycle_write_and_iterate(led_cycle_t *led_cycle);

#endif // __LED_CYCLE_H__
