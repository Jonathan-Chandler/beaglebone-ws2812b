#ifndef __PRU_SHMEM_H__
#define __PRU_SHMEM_H__
#include <stdint.h>
#include <fcntl.h>

// set shared memory
void synchronize_leds(uint32_t led_count);

// reverse single 8 bit value in order to be used by PRU
uint32_t reverse_8bit(uint32_t value);

#endif
