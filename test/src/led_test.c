#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "led.h"
#include "led_test.h"

LED_TEST *led_test[] = {led_test_strip_init, led_test_strip_destroy, led_test_set_single, led_test_set_range, led_test_set_all, led_test_read_write};
const int led_test_count = sizeof(led_test)/sizeof(led_test[0]);

#define TEST_LED_COUNT  5
#define TEST_RED_VAL    123
#define TEST_GREEN_VAL  124
#define TEST_BLUE_VAL   125

int led_test_strip_init()
{
  led_color_t default_color;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  // attempt to allocate led strip with 0 leds
  ASSERT_EQUAL(NULL, led_strip_init(0, &default_color));

  // attempt using null pointer to default color
  ASSERT_EQUAL(NULL, led_strip_init(1, NULL));

  return 0;
}

int led_test_strip_destroy()
{
  led_color_t default_color;
  led_strip_t *led_strip = NULL;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  led_strip = led_strip_init(TEST_LED_COUNT, &default_color);

  // attempt using pointer to default color
  ASSERT_EQUAL(TEST_RED_VAL, led_strip->led_colors[4].red);
  ASSERT_EQUAL(TEST_BLUE_VAL, led_strip->led_colors[4].blue);
  ASSERT_EQUAL(TEST_GREEN_VAL, led_strip->led_colors[0].green);
  ASSERT_EQUAL(TEST_RED_VAL, led_strip->led_colors[0].red);
  ASSERT_EQUAL(TEST_LED_COUNT, led_strip->led_count);

  // deallocate null led_strip
  ASSERT_EQUAL(-1, led_strip_destroy(NULL));

  // deallocate null color list
  free(led_strip->led_colors);
  led_strip->led_colors = NULL;
  ASSERT_EQUAL(-1, led_strip_destroy(led_strip));

  // normal deallocation
  led_strip = led_strip_init(TEST_LED_COUNT, &default_color);
  ASSERT_NOT_EQUAL(-1, led_strip_destroy(led_strip));

  return 0;
}

#define NEW_TEST_RED_VAL    223
#define NEW_TEST_GREEN_VAL  224
#define NEW_TEST_BLUE_VAL   225

int led_test_set_single()
{
  led_color_t default_color;
  led_color_t new_color;
  led_strip_t *led_strip = NULL;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  new_color.red = NEW_TEST_RED_VAL;
  new_color.green = NEW_TEST_GREEN_VAL;
  new_color.blue = NEW_TEST_BLUE_VAL;

  // set invalid index
  led_strip = led_strip_init(TEST_LED_COUNT, &default_color);
  ASSERT_EQUAL(-1, led_set_single(led_strip, TEST_LED_COUNT, &new_color));

  // set null new color
  ASSERT_EQUAL(-1, led_set_single(led_strip, 0, NULL));

  // set null led strip
  ASSERT_EQUAL(-1, led_set_single(NULL, 0, &new_color));

  // set new color
  ASSERT_NOT_EQUAL(-1, led_set_single(led_strip, 0, &new_color));

  // check new color
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[0], &new_color, sizeof(led_color_t)));

  // check unchanged color
  ASSERT_NOT_EQUAL(0, memcmp(&led_strip->led_colors[1], &new_color, sizeof(led_color_t)));

  // set and check new color
  ASSERT_NOT_EQUAL(-1, led_set_single(led_strip, 4, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[4], &new_color, sizeof(led_color_t)));

  // deallocate
  ASSERT_NOT_EQUAL(-1, led_strip_destroy(led_strip));

  return 0;
}

int led_test_set_range()
{
  led_color_t default_color;
  led_color_t new_color;
  led_strip_t *led_strip = NULL;
  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  new_color.red = NEW_TEST_RED_VAL;
  new_color.green = NEW_TEST_GREEN_VAL;
  new_color.blue = NEW_TEST_BLUE_VAL;

  // set invalid index
  led_strip = led_strip_init(TEST_LED_COUNT, &default_color);
  ASSERT_EQUAL(-1, led_set_range(led_strip, 5, 1, &new_color));
  ASSERT_EQUAL(-1, led_set_range(led_strip, 4, 2, &new_color));
  ASSERT_EQUAL(-1, led_set_range(led_strip, 3, 0, &new_color));

  // set null strip
  ASSERT_EQUAL(-1, led_set_range(NULL, 0, 1, &new_color));

  // set null new color
  ASSERT_EQUAL(-1, led_set_range(led_strip, 0, 1, NULL));

  // set and check single new color
  ASSERT_NOT_EQUAL(-1, led_set_range(led_strip, 0, 1, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[0], &new_color, sizeof(led_color_t)));
  ASSERT_NOT_EQUAL(0, memcmp(&led_strip->led_colors[1], &new_color, sizeof(led_color_t)));

  // set and check range new color
  ASSERT_NOT_EQUAL(-1, led_set_range(led_strip, 0, 3, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[0], &new_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[2], &new_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[3], &default_color, sizeof(led_color_t)));

  // set and check last colors
  ASSERT_NOT_EQUAL(-1, led_set_range(led_strip, 3, 2, &new_color));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[3], &new_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[4], &new_color, sizeof(led_color_t)));

  // set and check all colors
  ASSERT_NOT_EQUAL(-1, led_set_range(led_strip, 0, 5, &default_color));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[0], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[1], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[2], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[3], &default_color, sizeof(led_color_t)));
  ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[4], &default_color, sizeof(led_color_t)));

  // deallocate
  ASSERT_NOT_EQUAL(-1, led_strip_destroy(led_strip));

  return 0;
}

int led_test_set_all()
{
  led_color_t default_color;
  led_color_t new_color;
  led_strip_t *led_strip = NULL;

  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  new_color.red = NEW_TEST_RED_VAL;
  new_color.green = NEW_TEST_GREEN_VAL;
  new_color.blue = NEW_TEST_BLUE_VAL;

  // allocate
  led_strip = led_strip_init(TEST_LED_COUNT, &default_color);
  ASSERT_NOT_EQUAL(NULL, led_strip);

  // set null color
  ASSERT_EQUAL(-1, led_set_all(led_strip, NULL));

  // set null strip
  ASSERT_EQUAL(-1, led_set_all(NULL, &new_color));

  // set new color
  ASSERT_EQUAL(0, led_set_all(led_strip, &new_color));

  // check set all colors
  for (uint32_t i = 0; i < led_strip->led_count; i++)
  {
    ASSERT_NOT_EQUAL(0, memcmp(&led_strip->led_colors[i], &default_color, sizeof(led_color_t)));
    ASSERT_EQUAL(0, memcmp(&led_strip->led_colors[i], &new_color, sizeof(led_color_t)));
  }

  // deallocate
  ASSERT_NOT_EQUAL(-1, led_strip_destroy(led_strip));

  return 0;
}

int led_test_read_write()
{
  const char *test_file = "test_led.dat";
  led_color_t default_color;
  led_strip_t *write_strip = NULL;
  led_strip_t *read_strip = NULL;

  default_color.red = TEST_RED_VAL;
  default_color.green = TEST_GREEN_VAL;
  default_color.blue = TEST_BLUE_VAL;

  // allocate
  write_strip = led_strip_init(TEST_LED_COUNT, &default_color);
  ASSERT_NOT_EQUAL(NULL, write_strip);

  // don't allow null led pointer
  ASSERT_NOT_EQUAL(0, led_write_file(NULL, test_file));

  // don't allow null file name pointer
  ASSERT_NOT_EQUAL(0, led_write_file(write_strip, NULL));

  // write leds to file
  ASSERT_EQUAL(0, led_write_file(write_strip, test_file));

  // don't allow null return pointer
  ASSERT_NOT_EQUAL(0, led_read_file(NULL, test_file));

  // don't allow null file name pointer
  ASSERT_NOT_EQUAL(0, led_read_file(&read_strip, NULL));

  // attempt file read
  ASSERT_EQUAL(0, led_read_file(&read_strip, test_file));
  ASSERT_NOT_EQUAL(NULL, read_strip);

  // compare led count / colors
  ASSERT_EQUAL(0, memcmp(&(write_strip->led_count), &(read_strip->led_count), sizeof(uint32_t)));
  ASSERT_EQUAL(0, memcmp(&(write_strip->led_colors[0]), &(read_strip->led_colors[0]), sizeof(led_color_t)*write_strip->led_count));

  // deallocate
  ASSERT_EQUAL(0, led_strip_destroy(read_strip));
  ASSERT_EQUAL(0, led_strip_destroy(write_strip));

  return 0;
}

