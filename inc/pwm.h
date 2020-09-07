#ifndef __PWM_H__
#define __PWM_H__
#include <stdint.h>
#include "error.h"

ERROR_T pwm_init();
ERROR_T pwm_destroy();
ERROR_T pwm_set_period(uint32_t new_frequency, uint32_t new_duty_cycle);

#endif
