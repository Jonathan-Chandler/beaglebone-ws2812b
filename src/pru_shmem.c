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
#include "debug.h"
#include "pru_shmem.h"
#include "led.h"
#include "ws2812b.h"
#include "share.h"

//uint32_t leds[WS2812_LED_COUNT];

pru_shmem_t* shmem_allocate()
{
  pru_shmem_t *pru_shmem = malloc(sizeof(pru_shmem_t));
  if (pru_shmem == NULL)
  {
    printDebug("Fail to allocate\n");
    return NULL;
  }

  // default values if failed to get file descriptor / memory map
  pru_shmem->shared_mem_fd = -1;
  pru_shmem->shared_mem_map = MAP_FAILED;

  // open shared memory file descriptor
  pru_shmem->shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
  if (pru_shmem->shared_mem_fd < 0)
  {
    printDebug("Fail to open /dev/mem\n");
    goto exit_error;
  }

  // get memory map on file descriptor
  pru_shmem->shared_mem_map = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, pru_shmem->shared_mem_fd, SHARED_MEM_START_ADDR);
  if (pru_shmem->shared_mem_map == MAP_FAILED) 
  {
    printDebug("Fail to get memory map\n");
    goto exit_error;
  }

  return pru_shmem;

exit_error:

  // failed after allocating memory
  if (pru_shmem != NULL)
  {
    shmem_deallocate(&pru_shmem);
  }

  return NULL;
}

int shmem_deallocate(pru_shmem_t **pru_shmem)
{
  int rc = 0;

  if (pru_shmem == NULL)
  {
    printDebug("NULL shmem_t\n");
    return -1;
  }

  if (*pru_shmem == NULL)
  {
    printDebug("NULL pointer to *shmem_t\n");
    return -1;
  }

  if ((*pru_shmem)->shared_mem_map != MAP_FAILED)
  {
    if (munmap((void *)(*pru_shmem)->shared_mem_map, getpagesize()) == -1) 
    {
      printDebug("FAIL to unmap\n");
      rc = -1;
    }
  }

  // close file desc
  if ((*pru_shmem)->shared_mem_fd >= 0)
  {
    if (close((*pru_shmem)->shared_mem_fd))
    {
      printDebug("FAIL to close file descriptor\n");
      rc = -1;
    }
  }

  // deallocate struct
  free(*pru_shmem);
  *pru_shmem = NULL;

  return rc;
}

int shmem_check_params(pru_shmem_t *pru_shmem)
{
  if (pru_shmem == NULL)
  {
    printDebug("NULL shmem\n");
    return -1;
  }

  if (pru_shmem->shared_mem_fd < 0)
  {
    printDebug("Bad file descriptor\n");
    return -1;
  }

  if (pru_shmem->shared_mem_map == MAP_FAILED)
  {
    printDebug("Bad memory map\n");
    return -1;
  }

  return 0;
}

int shmem_synchronize(pru_shmem_t *pru_shmem, led_strip_t *leds)
{
  // check shared mem was allocated
  if (shmem_check_params(pru_shmem))
  {
    printDebug("Fail shmem param check\n");
    return -1;
  }

  // check led strip is valid
  if (led_check_params(leds))
  {
    printDebug("Fail led param check\n");
    return -1;
  }

  // check allocated enough space for led count
  if ((sizeof(uint32_t) * leds->led_count) > getpagesize())
  {
    printDebug("Write size > pagesize\n");
    return -1;
  }

  // synchronize color values
  for (int i = 0; i < leds->led_count; i++)
  {
    pru_shmem->shared_mem_map[SHARED_MEM_LED_START_OFFSET + i] = leds->led_colors[i].value;
  }

  // set LED count
  pru_shmem->shared_mem_map[SHARED_MEM_LED_COUNT_OFFSET] = leds->led_count;

  // start writing led colors
  pru_shmem->shared_mem_map[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 1;

  return 0;
}

//void synchronize_leds(uint32_t led_count)
//{
//  int shared_mem_fd;
//  volatile uint32_t *shared_mem_map;
//
//  shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
//  if (shared_mem_fd < 0)
//  {
//    perror("Fail to open /dev/mem");
//    exit(EXIT_FAILURE);
//  }
//
//  shared_mem_map = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, SHARED_MEM_START_ADDR);
//  if (shared_mem_map == MAP_FAILED) 
//  {
//    close(shared_mem_fd);
//    perror("Error mmapping");
//    exit(EXIT_FAILURE);
//  }
//
//  // synchronize
//  for (int i = 0; i < led_count; i++)
//  {
//    shared_mem_map[SHARED_MEM_LED_START_OFFSET + i] = leds[i];
//  }
//
//  // set LED count
//  shared_mem_map[SHARED_MEM_LED_COUNT_OFFSET] = led_count;
//
//  // start writing led colors
//  shared_mem_map[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 1;
//
//  if (munmap((void *)shared_mem_map, getpagesize()) == -1) 
//  {
//    close(shared_mem_fd);
//    perror("Error unmapping");
//    exit(EXIT_FAILURE);
//  }
//
//  close(shared_mem_fd);
//  printf("Wrote shared memory\n");
//}
//
//void synchronize_leds(uint32_t led_count)
//{
//  int shared_mem_fd;
//  volatile uint32_t *shared_mem_map;
//
//  shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
//  if (shared_mem_fd < 0)
//  {
//    perror("Fail to open /dev/mem");
//    exit(EXIT_FAILURE);
//  }
//
//  shared_mem_map = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, SHARED_MEM_START_ADDR);
//  if (shared_mem_map == MAP_FAILED) 
//  {
//    close(shared_mem_fd);
//    perror("Error mmapping");
//    exit(EXIT_FAILURE);
//  }
//
//  // synchronize
//  for (int i = 0; i < led_count; i++)
//  {
//    shared_mem_map[SHARED_MEM_LED_START_OFFSET + i] = leds[i];
//  }
//
//  // set LED count
//  shared_mem_map[SHARED_MEM_LED_COUNT_OFFSET] = led_count;
//
//  // start writing led colors
//  shared_mem_map[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 1;
//
//  if (munmap((void *)shared_mem_map, getpagesize()) == -1) 
//  {
//    close(shared_mem_fd);
//    perror("Error unmapping");
//    exit(EXIT_FAILURE);
//  }
//
//  close(shared_mem_fd);
//  printf("Wrote shared memory\n");
//}

