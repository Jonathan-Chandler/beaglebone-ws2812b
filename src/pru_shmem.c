#include "ws2812b.h"
#include "pru_shmem.h"
#include "share.h"
#include <sys/types.h>
#include <sys/mman.h>
// #include <sys/stat.h>
//#include <sys/mman.h>
#include <stdio.h>

//#include <sys/types.h>
//#include <sys/mman.h>
//#include <stdint.h>
#include <stdio.h>
//#include <stdlib.h>

//#include <sys/stat.h>
//#include <fcntl.h>
#include <unistd.h> //getpagesize()
#include "pru_shmem.h"
#include "led.h"
#include "ws2812b.h"
#include "share.h"

uint32_t leds[WS2812_LED_COUNT];

uint32_t reverse_8bit(uint32_t value)
{
  uint32_t bit_num;
  uint32_t reversed_value = 0;

  for (bit_num = 0; bit_num < 8; bit_num++)
  {
    if ((0x80 >> bit_num) & value)
    {
      reversed_value |= (1 << bit_num);
    }
  }

  return reversed_value;
}

void synchronize_leds(uint32_t led_count)
{
  int shared_mem_fd;
  volatile uint32_t *shared_mem_map;

  shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
  if (shared_mem_fd < 0)
  {
    perror("Fail to open /dev/mem");
    exit(EXIT_FAILURE);
  }

  shared_mem_map = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, SHARED_MEM_START_ADDR);
  if (shared_mem_map == MAP_FAILED) 
  {
    close(shared_mem_fd);
    perror("Error mmapping");
    exit(EXIT_FAILURE);
  }

  // synchronize
  for (int i = 0; i < led_count; i++)
  {
    shared_mem_map[SHARED_MEM_LED_START_OFFSET + i] = leds[i];
  }

  // set LED count
  shared_mem_map[SHARED_MEM_LED_COUNT_OFFSET] = led_count;

  // start writing led colors
  shared_mem_map[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 1;

  if (munmap((void *)shared_mem_map, getpagesize()) == -1) 
  {
    close(shared_mem_fd);
    perror("Error unmapping");
    exit(EXIT_FAILURE);
  }

  close(shared_mem_fd);
  printf("Wrote shared memory\n");
}

