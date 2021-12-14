#ifndef __LED_CYCLE_TEST_H__
#define __LED_CYCLE_TEST_H__

#include <stdint.h>
#include "led.h"
#include "led_cycle.h"
#include "unit_test.h"

int led_cycle_test_create_destroy();
int led_cycle_test_node_add_destroy();
int led_cycle_test_write_current();
int led_cycle_test_write_and_iterate();
int led_cycle_test_read_write_file();

typedef int LED_CYCLE_TEST();

#endif // __LED_CYCLE_TEST_H__
