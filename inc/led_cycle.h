#ifndef __LED_CYCLE_H__
#define __LED_CYCLE_H__
#include "led.h"

typedef struct led_cycle_node_t
{
  uint32_t ms_delay;
  led_config_t *led_config;
  struct led_cycle_node_t *next;
} led_cycle_node_t;

typedef struct
{
  led_cycle_node_t *first, *last, *current;
} led_cycle_t;

led_cycle_t* led_cycle_create(void);
int led_cycle_destroy(led_cycle_t **cycle);
int led_cycle_node_destroy(led_cycle_node_t **led_cycle_node);
int led_cycle_check_params(led_cycle_t *led_cycle);
int led_cycle_check_equality(led_cycle_t *cycle1, led_cycle_t *cycle2);
int led_cycle_node_check_equality(led_cycle_node_t *node1, led_cycle_node_t *node2);

int led_cycle_node_add(led_cycle_t *led_cycle, uint32_t display_time_ms, led_config_t *led_config);
int led_cycle_iterate(led_cycle_t *led_cycle);
int led_cycle_write_current(led_cycle_t *cycle);
int led_cycle_write_and_iterate(led_cycle_t *led_cycle);

int led_cycle_write_file(led_cycle_t *led_cycle, const char *file_name);
int led_cycle_read_file(led_cycle_t **led_cycle, const char *file_name);

#endif // __LED_CYCLE_H__
