#ifndef __LED_H__
#define __LED_H__

#include <stdint.h>
#include <stdio.h>

typedef struct
{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  uint32_t value;
} led_color_t;

typedef struct
{
  uint32_t led_count;
  led_color_t *led_colors;
} led_config_t;

led_color_t *led_color_init(uint8_t red_value, uint8_t green_value, uint8_t blue_value);
int led_color_destroy(led_color_t **led_color);

led_config_t *led_config_init(uint32_t led_count, led_color_t *default_color);
int led_config_destroy(led_config_t *config);
int led_check_params(led_config_t *config);
int led_config_check_equality(led_config_t *config1, led_config_t *config2);
int led_color_check_equality(led_color_t *color1, led_color_t *color2);

int led_set_single(led_config_t *config, uint32_t index, led_color_t *new_color);
int led_set_range(led_config_t *config, uint32_t begin, uint32_t count, led_color_t *new_color);
int led_set_all(led_config_t *config, led_color_t *new_color);
int led_write_file(led_config_t *config, const char *file_name);
int led_read_file(led_config_t **ret_config, const char *file_name);
int led_append_file(led_config_t *config, FILE *file_ptr);
int led_read_file_pointer(led_config_t **ret_config, FILE *file_ptr);

#endif // __LED_H__
