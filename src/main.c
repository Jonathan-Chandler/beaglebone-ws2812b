#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ws2812b.h"
#include "share.h"

int main(void)
{
  int result;
  uint32_t leds[WS2812_LED_COUNT];
  int shared_mem_fd;
  volatile uint32_t *shared_mem_map;
  printf("%d\n", getpagesize());

  shared_mem_fd = open(SHARED_MEM_MAP_FILE, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
  if (shared_mem_fd < 0)
  {
    perror("Fail to open /dev/mem");
    exit(EXIT_FAILURE);
  }

  // shared_mem_map = mmap((void *)SHARED_MEM_START_ADDR, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, 0);
  shared_mem_map = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, SHARED_MEM_START_ADDR);
  //shared_mem_map = mmap(0, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shared_mem_fd, SHARED_MEM_START_ADDR);
  if (shared_mem_map == MAP_FAILED) 
  {
    close(shared_mem_fd);
    perror("Error mmapping");
    exit(EXIT_FAILURE);
  }

  // all blue
  for (int i = 0; i < WS2812_LED_COUNT; i++)
  {
    leds[i] = WS2812_BLUE_MASK;
  }

  // synchronize
  for (int i = 0; i < WS2812_LED_COUNT; i++)
  {
    // shared_mem_map[SHARED_MEM_LED_START_OFFSET + i] = leds[i];
    shared_mem_map[SHARED_MEM_LED_START_OFFSET + i] = 0xFF;
  }

  // set LED count
  shared_mem_map[SHARED_MEM_LED_COUNT_OFFSET] = WS2812_LED_COUNT;

  // start writing led colors
  shared_mem_map[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 1;

//  for (int i = 0; i < 100; i++)
//  {
//    if (result == 0)
//    {
//      shared_mem_map[0] = 0;
//      result = 1;
//    }
//    else
//    {
//      shared_mem_map[0] = 1;
//      result = 0;
//    }
//    printf("%d\n", shared_mem_map[0]);
//
//    for (int x = 0; x < 100000000; x++)
//    {
//      asm("nop"); 
//    }
//  }

  // if (munmap((void *)shared_mem_map, getpagesize()) == -1) 
  if (munmap((void *)shared_mem_map, getpagesize()) == -1) 
  {
    close(shared_mem_fd);
    perror("Error unmapping");
    exit(EXIT_FAILURE);
  }

  close(shared_mem_fd);
  printf("Wrote shared memory\n");
}

// EHRPWM1A = 9_14
// EHRPWM1B = 9_16

// devices/platform/ocp/48300000.epwmss/48300100.ecap/pwm/pwmchip0/pwm-0:0
// devices/platform/ocp/48302000.epwmss/48302100.ecap/pwm/pwmchip3/pwm-3:0
// devices/platform/ocp/48300000.epwmss/48300100.ecap/pwm/pwmchip0
// devices/platform/ocp/48300000.epwmss/48300200.pwm/pwm/pwmchip1
// devices/platform/ocp/48302000.epwmss/48302100.ecap/pwm/pwmchip3
// devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/pwmchip4
// devices/platform/ocp/48304000.epwmss/48304100.ecap/pwm/pwmchip6
// devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7

// root@beaglebone:/sys/class/pwm# ls -lh
// total 0
// lrwxrwxrwx 1 root root 0 Oct 13 17:14 pwmchip0 -> ../../devices/platform/ocp/48300000.epwmss/48300200.pwm/pwm/pwmchip0
// lrwxrwxrwx 1 root root 0 Oct 13 17:14 pwmchip2 -> ../../devices/platform/ocp/48300000.epwmss/48300100.ecap/pwm/pwmchip2
// lrwxrwxrwx 1 root root 0 Oct 13 17:14 pwmchip3 -> ../../devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/pwmchip3
// lrwxrwxrwx 1 root root 0 Oct 13 17:14 pwmchip5 -> ../../devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip5
// lrwxrwxrwx 1 root root 0 Oct 13 17:14 pwmchip7 -> ../../devices/platform/ocp/48304000.epwmss/48304100.ecap/pwm/pwmchip7
// 
// so grep:
// 
// #P9.21/P9.22
// #ls -lh /sys/devices/platform/ocp/48300000.epwmss/48300200.pwm/pwm/
// #P9.14/P9.16
// #ls -lh /sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/
// #P8.13/P8.16
// #ls -lh /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/
// 
// export ehrpwm0=/sys/devices/platform/ocp/48300000.epwmss/48300200.pwm/pwm/pwmchip0
// #P9.22:
// config-pin P9.22 pwm
// echo 0 > ${ehrpwm0}/export || true
// echo 20000 > ${ehrpwm0}/pwm0/period ; echo 10000 > ${ehrpwm0}/pwm0/duty_cycle
// echo 1 > ${ehrpwm0}/pwm0/enable
// 
// #P9.21:
// config-pin P9.21 pwm
// echo 1 > ${ehrpwm0}/export || true
// echo 20000 > ${ehrpwm0}/pwm1/period ; echo 10000 > ${ehrpwm0}/pwm1/duty_cycle
// echo 1 > ${ehrpwm0}/pwm1/enable
// 
// export ehrpwm1=/sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/pwmchip2
// #P9.14:
// config-pin P9.14 pwm
// echo 0 > ${ehrpwm1}/export || true
// echo 20000 > ${ehrpwm1}/pwm0/period ; echo 10000 > ${ehrpwm1}/pwm0/duty_cycle
// echo 1 > ${ehrpwm1}/pwm0/enable
// echo 0 > 
// echo pwm > /sys/bus/platform/drivers/bone-pinmux-helper/ocp:P9_14_pinmux/state
// 
// #P9.16:
// config-pin P9.16 pwm
// echo 1 > ${ehrpwm1}/export || true
// echo 30000 > ${ehrpwm1}/pwm1/period ; echo 5000 > ${ehrpwm1}/pwm1/duty_cycle
// echo 1 > ${ehrpwm1}/pwm1/enable
// 
// export ehrpwm2=/sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip5
// #P8.19:
// config-pin P8.19 pwm
// echo 0 > ${ehrpwm2}/export || true
// echo 20000 > ${ehrpwm2}/pwm0/period ; echo 10000 > ${ehrpwm2}/pwm0/duty_cycle
// echo 1 > ${ehrpwm2}/pwm0/enable
// 
// #P8.13:
// config-pin P8.13 pwm
// echo 1 > ${ehrpwm2}/export || true
// echo 20000 > ${ehrpwm2}/pwm1/period ; echo 10000 > ${ehrpwm2}/pwm1/duty_cycle
// echo 1 > ${ehrpwm2}/pwm1/enable
// 
// ./opt/source/adafruit-beaglebone-io-python/Adafruit_BBIO
// ./opt/source/adafruit-beaglebone-io-python/build/lib.linux-armv7l-3.7/Adafruit_BBIO
// ./usr/local/lib/python2.7/dist-packages/Adafruit_BBIO
// ./usr/local/lib/python3.7/dist-packages/Adafruit_BBIO-1.1.1-py3.7-linux-armv7l.egg/Adafruit_BBIO
// 
// 
//
