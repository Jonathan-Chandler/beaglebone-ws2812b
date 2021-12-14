#ifndef __PRU_SHMEM_H__
#define __PRU_SHMEM_H__
#include <stdint.h>
#include <fcntl.h>
#include "led.h"

// set shared memory
//void synchronize_leds(uint32_t led_count);

typedef struct 
{
  int shared_mem_fd;
  volatile uint32_t *shared_mem_map;
} pru_shmem_t;

pru_shmem_t* shmem_allocate(void);
int shmem_deallocate(pru_shmem_t **pru_shmem);

int shmem_check_params(pru_shmem_t *pru_shmem);
int shmem_synchronize(pru_shmem_t *pru_shmem, led_config_t *leds);

#endif
