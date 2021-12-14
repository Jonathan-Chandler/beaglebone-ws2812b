#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "led.h"
#include "led_test.h"

LED_TEST *led_test[] = {led_test_config_init, led_test_config_destroy, led_test_set_single, led_test_set_range, led_test_set_all, led_test_read_write};
const int led_test_count = sizeof(led_test)/sizeof(led_test[0]);

#define TEST_LED_COUNT  5
#define TEST_RED_VAL    123
#define TEST_GREEN_VAL  124
#define TEST_BLUE_VAL   125

int led_test_config_init()
{
  led_color_t default_color;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  // attempt to allocate led config with 0 leds
  ASSERT_EQUAL(NULL, led_config_init(0, &default_color));

  // attempt using null pointer to default color
  ASSERT_EQUAL(NULL, led_config_init(1, NULL));

  return 0;
}

int led_test_config_destroy()
{
  led_color_t default_color;
  led_config_t *led_config = NULL;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  led_config = led_config_init(TEST_LED_COUNT, &default_color);

  // attempt using pointer to default color
  ASSERT_EQUAL(TEST_RED_VAL, led_config->led_colors[4].red);
  ASSERT_EQUAL(TEST_BLUE_VAL, led_config->led_colors[4].blue);
  ASSERT_EQUAL(TEST_GREEN_VAL, led_config->led_colors[0].green);
  ASSERT_EQUAL(TEST_RED_VAL, led_config->led_colors[0].red);
  ASSERT_EQUAL(TEST_LED_COUNT, led_config->led_count);

  // deallocate null led_config
  ASSERT_EQUAL(-1, led_config_destroy(NULL));

  // deallocate null color list
  free(led_config->led_colors);
  led_config->led_colors = NULL;
  ASSERT_EQUAL(-1, led_config_destroy(led_config));

  // normal deallocation
  led_config = led_config_init(TEST_LED_COUNT, &default_color);
  ASSERT_NOT_EQUAL(-1, led_config_destroy(led_config));

  return 0;
}

#define NEW_TEST_RED_VAL    223
#define NEW_TEST_GREEN_VAL  224
#define NEW_TEST_BLUE_VAL   225

int led_test_set_single()
{
  led_color_t default_color;
  led_color_t new_color;
  led_config_t *led_config = NULL;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  new_color.red = NEW_TEST_RED_VAL;
  new_color.green = NEW_TEST_GREEN_VAL;
  new_color.blue = NEW_TEST_BLUE_VAL;

  // set invalid index
  led_config = led_config_init(TEST_LED_COUNT, &default_color);
  ASSERT_EQUAL(-1, led_set_single(led_config, TEST_LED_COUNT, &new_color));

  // set null new color
  ASSERT_EQUAL(-1, led_set_single(led_config, 0, NULL));

  // set null led config
  ASSERT_EQUAL(-1, led_set_single(NULL, 0, &new_color));

  // set new color
  ASSERT_NOT_EQUAL(-1, led_set_single(led_config, 0, &new_color));

  // check new color
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[0], &new_color, sizeof(led_color_t)));

  // check unchanged color
  ASSERT_NOT_EQUAL(0, memcmp(&led_config->led_colors[1], &new_color, sizeof(led_color_t)));

  // set and check new color
  ASSERT_NOT_EQUAL(-1, led_set_single(led_config, 4, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[4], &new_color, sizeof(led_color_t)));

  // deallocate
  ASSERT_NOT_EQUAL(-1, led_config_destroy(led_config));

  return 0;
}

int led_test_set_range()
{
  led_color_t default_color;
  led_color_t new_color;
  led_config_t *led_config = NULL;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  new_color.red = NEW_TEST_RED_VAL;
  new_color.green = NEW_TEST_GREEN_VAL;
  new_color.blue = NEW_TEST_BLUE_VAL;

  // set invalid index
  led_config = led_config_init(TEST_LED_COUNT, &default_color);
  ASSERT_EQUAL(-1, led_set_range(led_config, 5, 1, &new_color));
  ASSERT_EQUAL(-1, led_set_range(led_config, 4, 2, &new_color));
  ASSERT_EQUAL(-1, led_set_range(led_config, 3, 0, &new_color));

  // set null config
  ASSERT_EQUAL(-1, led_set_range(NULL, 0, 1, &new_color));

  // set null new color
  ASSERT_EQUAL(-1, led_set_range(led_config, 0, 1, NULL));

  // set and check single new color
  ASSERT_NOT_EQUAL(-1, led_set_range(led_config, 0, 1, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[0], &new_color, sizeof(led_color_t)));
  ASSERT_NOT_EQUAL(0, memcmp(&led_config->led_colors[1], &new_color, sizeof(led_color_t)));

  // set and check range new color
  ASSERT_NOT_EQUAL(-1, led_set_range(led_config, 0, 3, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[0], &new_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[2], &new_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[3], &default_color, sizeof(led_color_t)));

  // set and check last colors
  ASSERT_NOT_EQUAL(-1, led_set_range(led_config, 3, 2, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[3], &new_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[4], &new_color, sizeof(led_color_t)));

  // set and check all colors
  ASSERT_NOT_EQUAL(-1, led_set_range(led_config, 0, 5, &default_color));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[0], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[1], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[2], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[3], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_config->led_colors[4], &default_color, sizeof(led_color_t)));

  // deallocate
  ASSERT_NOT_EQUAL(-1, led_config_destroy(led_config));

  return 0;
}

int led_test_set_all()
{
  led_color_t default_color;
  led_color_t new_color;
  led_config_t *led_config = NULL;

  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  new_color.red = NEW_TEST_RED_VAL;
  new_color.green = NEW_TEST_GREEN_VAL;
  new_color.blue = NEW_TEST_BLUE_VAL;

  // allocate
  led_config = led_config_init(TEST_LED_COUNT, &default_color);
  ASSERT_NOT_EQUAL(NULL, led_config);

  // set null color
  ASSERT_EQUAL(-1, led_set_all(led_config, NULL));

  // set null config
  ASSERT_EQUAL(-1, led_set_all(NULL, &new_color));

  // set new color
  ASSERT_EQUAL(0, led_set_all(led_config, &new_color));

  // check set all colors
  for (uint32_t i = 0; i < led_config->led_count; i++)
  {
    ASSERT_NOT_EQUAL(0, memcmp(&led_config->led_colors[i], &default_color, sizeof(led_color_t)));
    ASSERT_EQUAL(0, memcmp(&led_config->led_colors[i], &new_color, sizeof(led_color_t)));
  }

  // deallocate
  ASSERT_NOT_EQUAL(-1, led_config_destroy(led_config));

  return 0;
}

int led_test_read_write()
{
  const char *test_file = "test_led.dat";
  led_color_t default_color;
  led_config_t *write_config = NULL;
  led_config_t *read_config = NULL;

  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  // allocate
  write_config = led_config_init(TEST_LED_COUNT, &default_color);
  ASSERT_NOT_EQUAL(NULL, write_config);

  // don't allow null led pointer
  ASSERT_NOT_EQUAL(0, led_write_file(NULL, test_file));

  // don't allow null file name pointer
  ASSERT_NOT_EQUAL(0, led_write_file(write_config, NULL));

  // write leds to file
  ASSERT_EQUAL(0, led_write_file(write_config, test_file));

  // don't allow null return pointer
  ASSERT_NOT_EQUAL(0, led_read_file(NULL, test_file));

  // don't allow null file name pointer
  ASSERT_NOT_EQUAL(0, led_read_file(&read_config, NULL));

  // attempt file read
  ASSERT_EQUAL(0, led_read_file(&read_config, test_file));
  ASSERT_NOT_EQUAL(NULL, read_config);

  // compare led count / colors
  ASSERT_EQUAL(0, memcmp(&(write_config->led_count), &(read_config->led_count), sizeof(uint32_t)));
  ASSERT_EQUAL(0, memcmp(&(write_config->led_colors[0]), &(read_config->led_colors[0]), sizeof(led_color_t)*write_config->led_count));

  // deallocate
  ASSERT_EQUAL(0, led_config_destroy(read_config));
  ASSERT_EQUAL(0, led_config_destroy(write_config));

  return 0;
}

