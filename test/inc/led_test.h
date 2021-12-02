#ifndef __LED_TEST_H__
#define __LED_TEST_H__

#include <stdint.h>
#include "led.h"
#include "unit_test.h"

int led_test_strip_init(void);
int led_test_strip_destroy(void);
int led_test_set_single(void);
int led_test_set_range(void);
int led_test_set_all(void);
int led_test_read_write();

typedef int LED_TEST();

#endif // __LED_TEST_H__
