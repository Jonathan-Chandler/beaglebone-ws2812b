#ifndef __LED_CYCLE_H__
#define __LED_CYCLE_H__
#include "led.h"

typedef struct
{

};

led_cycle_t create_cycle(int cycles);
int destroy_cycle(led_cycle_t *cycle);

#endif // __LED_CYCLE_H__
