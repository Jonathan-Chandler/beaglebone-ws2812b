#include <sys/types.h>
//#include <sys/mman.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h> // mmap/munmap
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "debug.h"
#include "share.h"
#include "pwm_subsystem.h"
#include "enhanced_pwm.h"
#include "control_module.h"

// 1. Disable global interrupts (CPU INTM flag)
// 2. Disable ePWM interrupts
// 3. Initialize peripheral registers
// 4. Clear any spurious ePWM flags
// 5. Enable ePWM interrupts
// 6. Enable global interrupts

int main(int argc, char *argv[])
{
    pwmss_t *PWMSS = NULL;
    epwm_t *EPWM = NULL;
    control_t *CONTROL = NULL;
    mem_mgr_t *mem_mgr = NULL;

    if ( (mem_mgr = mem_mgr_init()) == NULL )
        return -1;

    if ( (CONTROL = control_init(mem_mgr)) == NULL )
        goto exit_error;

    if ( (PWMSS = pwmss_init(mem_mgr)) == NULL )
        goto exit_error;

    if ( (EPWM = epwm_init(PWMSS)) == NULL )
        goto exit_error;

    control_debug(CONTROL);

    pwmss_debug(PWMSS);

    epwm_debug(EPWM);


    //if ( (retval = pwm_deallocate()) < 0)
    //{
    //    goto exit_error;
    //}

    epwm_destroy(EPWM);
    pwmss_destroy(PWMSS);
    control_destroy(CONTROL);
    mem_mgr_destroy(mem_mgr);
    printf("Exit\n");
    return 0;

exit_error:
    epwm_destroy(EPWM);
    pwmss_destroy(PWMSS);
    control_destroy(CONTROL);
    mem_mgr_destroy(mem_mgr);
    printf("Error\n");
    return -1;
}

//int pwm_allocate()
//{
//  // open shared memory file descriptor
//  //shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
//  shared_mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
//  if (shared_mem_fd < 0)
//  {
//    report_error("Fail to open /dev/mem\n");
//    goto exit_error;
//  }
//  printf("open fd %d\n", shared_mem_fd);
//
//  // get memory map on file descriptor
//  map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, target & ~MAP_MASK);
//  virt_addr = map_base + (target & MAP_MASK);
//  if (map_base == (void*) -1)
//  {
//    report_error("Fail to get memory map\n");
//    goto exit_error;
//  }
//
//  printf("pagesize  = %X\n", getpagesize());
//  printf("map_base  = %p\n", map_base);
//  printf("virt_addr = %p\n", virt_addr);
//  printf("value     = %08X\n", *((uint32_t*)virt_addr));
//
//  //if (shared_mem_map == MAP_FAILED) 
//  //{
//  //  report_log("Fail to get memory map\n");
//  //  goto exit_error;
//  //}
//  printf("mmap\n");
//
//  return 0;
//
//exit_error:
//
//  // failed after allocating memory
//  if (map_base == MAP_FAILED)
//  {
//	pwm_deallocate();
//  }
//
//  return -1;
//}
//
//int pwm_deallocate()
//{
//  int rc = 0;
//
//  //if (virt_addr == NULL)
//  //{
//  //  report_log("NULL pointer to *shmem_t\n");
//  //  return -1;
//  //}
//  //printf("Not null: %p\n", shared_mem_map);
//
//  if (map_base != MAP_FAILED)
//  {
//    //if (munmap((void *)shared_mem_map, getpagesize()) == -1) 
//    if (munmap((void *)map_base, MAP_SIZE) == -1) 
//    {
//      report_error("Fail to unmap\n");
//      rc = -1;
//    }
//  }
//
//  // close file desc
//  printf("closing fd %d\n", shared_mem_fd);
//  if (shared_mem_fd >= 0)
//  {
//    if (close(shared_mem_fd))
//    {
//      report_error("Fail to close file descriptor\n");
//      rc = -1;
//    }
//  }
//
//  // deallocate struct
//  //free((void*)shared_mem_map);
//  shared_mem_fd = -1;
//  //shared_mem_map = NULL;
//
//  return rc;
//}
//
