#include <sys/types.h>
//#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h> // mmap/munmap
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "debug.h"
#include "share.h"
#include "ehrpwm2.h"

// 1. Disable global interrupts (CPU INTM flag)
// 2. Disable ePWM interrupts
// 3. Initialize peripheral registers
// 4. Clear any spurious ePWM flags
// 5. Enable ePWM interrupts
// 6. Enable global interrupts

#define TEST_CYCLE_TIME_2_SEC 2000 // in milliseconds
#define PWMSS2_BASE 0x48304000
#define PWMSS2_SIZE 0x100

#define EHRPWM2_BASE 0x48304200
#define EHRPWM2_SIZE 0x60

//#define MAP_SIZE 0x800UL
#define MAP_SIZE 0x1000UL
#define MAP_MASK (MAP_SIZE - 1)
void dump_epwm(epwm_t *EPWM);

//off_t target = PWMSS2_BASE;
off_t target = EHRPWM2_BASE;

int shared_mem_fd;
volatile uint32_t *shared_mem_map;
void *map_base;
void *virt_addr;

int pwm_allocate();
int pwm_deallocate();

int main(int argc, char *argv[])
{
	int retval = 0;
    epwm_t *EPWM;

	if ( (retval = pwm_allocate()) < 0)
	{
		goto exit_error;
	}

    EPWM = (epwm_t*)virt_addr;
    dump_epwm(EPWM);

	if ( (retval = pwm_deallocate()) < 0)
	{
		goto exit_error;
	}
	printf("exit");

	return 0;

exit_error:
	printDebug("Error\n");
	return -1;
}

int pwm_allocate()
{
  // open shared memory file descriptor
  //shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
  shared_mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
  if (shared_mem_fd < 0)
  {
    printDebug("Fail to open file\n");
    goto exit_error;
  }
  printf("open fd %d\n", shared_mem_fd);

  // get memory map on file descriptor
  map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, target & ~MAP_MASK);
  virt_addr = map_base + (target & MAP_MASK);
  if (map_base == (void*) -1)
  {
    printDebug("Fail to get memory map\n");
    goto exit_error;
  }
  printf("pagesize  = %X\n", getpagesize());
  printf("map_base  = %p\n", map_base);
  printf("virt_addr = %p\n", virt_addr);
  printf("value     = %08X\n", *((uint32_t*)virt_addr));

  //if (shared_mem_map == MAP_FAILED) 
  //{
  //  printDebug("Fail to get memory map\n");
  //  goto exit_error;
  //}
  printf("mmap\n");

  return 0;

exit_error:

  // failed after allocating memory
  if (map_base == MAP_FAILED)
  {
	pwm_deallocate();
  }

  return -1;
}

int pwm_deallocate()
{
  int rc = 0;

  //if (virt_addr == NULL)
  //{
  //  printDebug("NULL pointer to *shmem_t\n");
  //  return -1;
  //}
  //printf("Not null: %p\n", shared_mem_map);

  if (map_base != MAP_FAILED)
  {
    //if (munmap((void *)shared_mem_map, getpagesize()) == -1) 
    if (munmap((void *)map_base, EHRPWM2_SIZE) == -1) 
    {
      printDebug("FAIL to unmap\n");
      rc = -1;
    }
  }

  // close file desc
  printf("closing fd %d\n", shared_mem_fd);
  if (shared_mem_fd >= 0)
  {
    if (close(shared_mem_fd))
    {
      printDebug("FAIL to close file descriptor\n");
      rc = -1;
    }
  }

  // deallocate struct
  //free((void*)shared_mem_map);
  shared_mem_fd = -1;
  //shared_mem_map = NULL;

  return rc;
}

char *epwm_reg_name[] = 
{
    "TBCTL  ",           // 0x00
    "TBSTS  ",           // 0x02
    "TBPHSHR",           // 0x04
    "TBPHS  ",           // 0x06
    "TBCNT  ",           // 0x08
    "TBPRD  ",           // 0x0A
    "FILL0  ",           // 0x0C
    "CMPCTL ",           // 0x0E
    "CMPAHR ",           // 0x10
    "CMPA   ",           // 0x12
    "CMPB   ",           // 0x14
    "AQCTLA ",           // 0x16
    "AQCTLB ",           // 0x18
    "AQSFRC ",           // 0x1A
    "AQCSFRC",           // 0x1C
    "DBCTL  ",           // 0x1E
    "DBRED  ",           // 0x20
    "DBFED  ",           // 0x22
    "TZSEL  ",           // 0x24
    "FILL1  ",           // 0x26
    "TZCTL  ",           // 0x28
    "TZEINT ",           // 0x2A
    "TZFLG  ",           // 0x2C
    "TZCLR  ",           // 0x2E
    "TZFRC  ",           // 0x30
    "ETSEL  ",           // 0x32
    "ETPS   ",           // 0x34
    "ETFLG  ",           // 0x36
    "ETCLR  ",           // 0x38
    "ETFRC  ",           // 0x3A
    "PCCTL  ",           // 0x3C
    "HRCNFG ",           // 0xC0
};
#define EPWM_REG_COUNT sizeof(epwm_reg_name)/sizeof(epwm_reg_name[0])

void dump_epwm(epwm_t *EPWM)
{
    int i;
    uint16_t *EPWM_MEM = (uint16_t*) EPWM;

    printf("\n------------------------EPWM DUMP------------------------\n");
    for (i = 0; i < EPWM_REG_COUNT; i++)
    {
        printf("%s: %04X\n", epwm_reg_name[i], EPWM_MEM[i]);
    }
    printf("---------------------------------------------------------\n");
}
