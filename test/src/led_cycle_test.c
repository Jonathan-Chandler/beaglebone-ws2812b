#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "led.h"
#include "led_test.h"
#include "led_cycle_test.h"

LED_CYCLE_TEST *led_cycle_test[] = {led_cycle_test_create_destroy, led_cycle_test_node_add_destroy, led_cycle_test_write_current, led_cycle_test_write_and_iterate, led_cycle_test_read_write_file};
const int led_cycle_test_count = sizeof(led_cycle_test)/sizeof(led_cycle_test[0]);

#define TEST_LED_COUNT    5
#define TEST_RED_VAL      123
#define TEST_GREEN_VAL    124
#define TEST_BLUE_VAL     125
#define TEST_CYCLE_TIME   100

#define TEST_LED_COUNT2   50
#define TEST_RED_VAL2     230
#define TEST_GREEN_VAL2   91
#define TEST_BLUE_VAL2    180
#define TEST_CYCLE_TIME2  140
#define TEST_FILE_NAME  "led_cycle_test.dat"

const char *test_cycle_file_name = TEST_FILE_NAME;

int led_cycle_test_create_destroy()
{
  led_cycle_t *led_cycle = led_cycle_create();
  led_cycle_t *null_led_cycle = NULL;
  ASSERT_NOT_EQUAL(NULL, led_cycle);

  // deallocate fails with NULL pointer
  ASSERT_NOT_EQUAL(0, led_cycle_destroy(NULL));

  // deallocate fails with pointer to NULL
  ASSERT_NOT_EQUAL(0, led_cycle_destroy(&null_led_cycle));

  // deallocate succeeds
  ASSERT_EQUAL(0, led_cycle_destroy(&led_cycle));

  // deallocate sets pointer to null
  ASSERT_EQUAL(NULL, led_cycle);

  // can't deallocate twice
  ASSERT_NOT_EQUAL(0, led_cycle_destroy(&led_cycle));

  return 0;
}

int led_cycle_test_node_add_destroy()
{
  led_cycle_node_t *temp_node;
  led_cycle_node_t *temp_node2;
  led_cycle_t *led_cycle = led_cycle_create();
  led_color_t *led_color = led_color_init(TEST_RED_VAL, TEST_GREEN_VAL, TEST_BLUE_VAL);
  led_config_t *led_config = led_config_init(TEST_LED_COUNT, led_color);

  led_color_t *led_color2;
  led_config_t *led_config2;

  // initialized
  ASSERT_NOT_EQUAL(NULL, led_cycle);
  ASSERT_NOT_EQUAL(NULL, led_color);
  ASSERT_NOT_EQUAL(NULL, led_config);

  // reject add node with 0 time
  ASSERT_NOT_EQUAL(0, led_cycle_node_add(led_cycle, 0, led_config));

  // reject add node with null led config
  ASSERT_NOT_EQUAL(0, led_cycle_node_add(led_cycle, TEST_CYCLE_TIME, NULL));

  // add 1 node
  ASSERT_EQUAL(0, led_cycle_node_add(led_cycle, TEST_CYCLE_TIME, led_config));

  // expect valid params
  ASSERT_EQUAL(0, led_cycle_check_params(led_cycle));

  // test iterating list of 1 node
  temp_node = led_cycle->current;
  ASSERT_EQUAL(0, led_cycle_iterate(led_cycle));
  ASSERT_EQUAL(temp_node, led_cycle->current);
  ASSERT_EQUAL(temp_node, led_cycle->first);
  ASSERT_EQUAL(temp_node, led_cycle->last);
  ASSERT_EQUAL(0, led_cycle_iterate(led_cycle));
  ASSERT_EQUAL(temp_node, led_cycle->current);
  ASSERT_EQUAL(temp_node, led_cycle->first);
  ASSERT_EQUAL(temp_node, led_cycle->last);

  ASSERT_EQUAL(0, led_cycle_iterate(led_cycle));

  // deallocate succeeds with 1 node
  ASSERT_EQUAL(0, led_cycle_destroy(&led_cycle));
  ASSERT_EQUAL(NULL, led_cycle);

  ASSERT_EQUAL(0, led_color_destroy(&led_color));
  ASSERT_EQUAL(NULL, led_color);

  // initialized
  led_cycle = led_cycle_create();
  led_color = led_color_init(TEST_RED_VAL, TEST_GREEN_VAL, TEST_BLUE_VAL);
  led_config = led_config_init(TEST_LED_COUNT, led_color);
  led_color2 = led_color_init(TEST_RED_VAL, TEST_GREEN_VAL, TEST_BLUE_VAL);
  led_config2 = led_config_init(TEST_LED_COUNT, led_color2);
  ASSERT_NOT_EQUAL(NULL, led_cycle);
  ASSERT_NOT_EQUAL(NULL, led_color);
  ASSERT_NOT_EQUAL(NULL, led_config);
  ASSERT_NOT_EQUAL(NULL, led_color2);
  ASSERT_NOT_EQUAL(NULL, led_config2);

  // add 2 nodes
  ASSERT_EQUAL(0, led_cycle_node_add(led_cycle, TEST_CYCLE_TIME, led_config));
  ASSERT_EQUAL(0, led_cycle_node_add(led_cycle, TEST_CYCLE_TIME, led_config2));

  // test iterating list of 1 node
  temp_node = led_cycle->current;
  ASSERT_EQUAL(0, led_cycle_iterate(led_cycle));
  temp_node2 = led_cycle->current;
  ASSERT_EQUAL(0, led_cycle_iterate(led_cycle));
  ASSERT_NOT_EQUAL(temp_node, temp_node2);

  // first node
  ASSERT_EQUAL(temp_node, led_cycle->current);
  ASSERT_EQUAL(temp_node, led_cycle->first);

  // second node
  ASSERT_EQUAL(0, led_cycle_iterate(led_cycle));
  ASSERT_EQUAL(temp_node2, led_cycle->current);
  ASSERT_EQUAL(temp_node2, led_cycle->last);

  // deallocate succeeds with 2 nodes
  ASSERT_EQUAL(0, led_cycle_destroy(&led_cycle));
  ASSERT_EQUAL(NULL, led_cycle);

  // deallocate
  ASSERT_EQUAL(0, led_color_destroy(&led_color));
  ASSERT_EQUAL(NULL, led_color);
  ASSERT_EQUAL(0, led_color_destroy(&led_color2));
  ASSERT_EQUAL(NULL, led_color2);

  return 0;
}

int led_cycle_test_write_current()
{
  return 0;
}

int led_cycle_test_write_and_iterate()
{
  return 0;
}

int led_cycle_test_read_write_file()
{
  led_cycle_t *null_led_cycle = NULL;       // null cycle to attempt to save
  led_cycle_t *led_cycle = NULL;           // led cycle with 1 configuration to be saved
  led_cycle_t *led_cycle_compare = NULL;   // led cycle with 1 configuration to be loaded from file

  led_color_t *led_color1 = NULL;           // led color configuration for led_config1
  led_config_t *led_config1 = NULL;         // led cycle configuration for led_cycle1

  led_color_t *led_color2 = NULL;           // led color configuration for led_config2
  led_config_t *led_config2 = NULL;         // led cycle configuration for led_cycle2

  // create and check 
  led_cycle = led_cycle_create();
  ASSERT_NOT_EQUAL(NULL, led_cycle);

  // shouldn't save empty/null led cycles
  ASSERT_NOT_EQUAL(0, led_cycle_write_file(NULL, test_cycle_file_name));
  ASSERT_NOT_EQUAL(0, led_cycle_write_file(null_led_cycle, test_cycle_file_name));
  ASSERT_NOT_EQUAL(0, led_cycle_write_file(led_cycle, test_cycle_file_name));

  // initialize an led configuration
  led_color1 = led_color_init(TEST_RED_VAL, TEST_GREEN_VAL, TEST_BLUE_VAL);
  led_config1 = led_config_init(TEST_LED_COUNT, led_color1);
  ASSERT_NOT_EQUAL(0, led_color1);
  ASSERT_NOT_EQUAL(0, led_config1);

  // add 1 configuration node to cycle
  ASSERT_EQUAL(0, led_cycle_node_add(led_cycle, TEST_CYCLE_TIME, led_config1));

  // save the led cycle with 1 configuration node
  ASSERT_EQUAL(0, led_cycle_write_file(led_cycle, test_cycle_file_name));

  // load the saved cycle with 1 configuration node
  ASSERT_EQUAL(0, led_cycle_read_file(&led_cycle_compare, test_cycle_file_name));

  // check that original and loaded led cycles are equal
  ASSERT_EQUAL(0, led_cycle_check_equality(led_cycle, led_cycle_compare));

  // deallocate succeeds
  ASSERT_EQUAL(0, led_color_destroy(&led_color1));
  ASSERT_EQUAL(0, led_cycle_destroy(&led_cycle));
  ASSERT_EQUAL(0, led_cycle_destroy(&led_cycle_compare));


  // test with 2 nodes

  // save cycle with 2 configuration nodes
  led_cycle = led_cycle_create();
  ASSERT_NOT_EQUAL(NULL, led_cycle);

  // initialize both led configurations
  led_color1 = led_color_init(TEST_RED_VAL, TEST_GREEN_VAL, TEST_BLUE_VAL);
  led_config1 = led_config_init(TEST_LED_COUNT, led_color1);
  ASSERT_NOT_EQUAL(0, led_color1);
  ASSERT_NOT_EQUAL(0, led_config1);

  led_color2 = led_color_init(TEST_RED_VAL2, TEST_GREEN_VAL2, TEST_BLUE_VAL2);
  led_config2 = led_config_init(TEST_LED_COUNT2, led_color2);
  ASSERT_NOT_EQUAL(0, led_color2);
  ASSERT_NOT_EQUAL(0, led_config2);

  // add 2 configuration nodes to cycle
  ASSERT_EQUAL(0, led_cycle_node_add(led_cycle, TEST_CYCLE_TIME, led_config1));
  ASSERT_EQUAL(0, led_cycle_node_add(led_cycle, TEST_CYCLE_TIME2, led_config2));

  // save 2 nodes to file
  ASSERT_EQUAL(0, led_cycle_write_file(led_cycle, test_cycle_file_name));

  // load the saved cycle with 2 configuration nodes
  ASSERT_EQUAL(0, led_cycle_read_file(&led_cycle_compare, test_cycle_file_name));

  // check that original and loaded led cycles are equal
  ASSERT_EQUAL(0, led_cycle_check_equality(led_cycle, led_cycle_compare));

  // deallocate succeeds
  ASSERT_EQUAL(0, led_color_destroy(&led_color1));
  ASSERT_EQUAL(0, led_color_destroy(&led_color2));
  ASSERT_EQUAL(0, led_cycle_destroy(&led_cycle));
  ASSERT_EQUAL(0, led_cycle_destroy(&led_cycle_compare));

  return 0;
}

