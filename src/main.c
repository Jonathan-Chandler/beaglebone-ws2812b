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

int main(void)
{
  uint32_t menu_selection;
  uint32_t red_value;
  uint32_t green_value;
  uint32_t blue_value;
  uint32_t color_value;
  uint32_t led_num;

  for (led_num = 0; led_num < WS2812_LED_COUNT; led_num++)
  {
    leds[led_num] = 0;
  }

  leds[led_num] = 0x800001; // 1000 0000 0000 0000 0000 0001 
#if 1
  uint32_t i;
  uint32_t x;
  for (i = 0; i < 10; i++)
  {
    synchronize_leds(1);

    for (x = 0; x < 100000; x++)
    {
      asm("nop");
    }
  }
  return 0;
#endif

  while (1)
  {
    printf("0: Exit\n");
    printf("1: Set colors\n");
    printf("2: Synchronize\n");
    scanf("%d", &menu_selection);

    if (menu_selection < 1 || menu_selection > 2)
    {
      break;
    }
    else if (menu_selection == 1)
    {
      printf("Red: ");
      scanf("%u", &red_value);
      printf("Green: ");
      scanf("%u", &green_value);
      printf("Blue: ");
      scanf("%u", &blue_value);

      red_value = reverse_8bit(red_value);
      green_value = reverse_8bit(green_value);
      blue_value = reverse_8bit(blue_value);

      color_value  = (red_value << WS2812_RED_OFFSET) & WS2812_RED_MASK;
      color_value |= (green_value << WS2812_GREEN_OFFSET) & WS2812_GREEN_MASK;
      color_value |= (blue_value << WS2812_BLUE_OFFSET) & WS2812_BLUE_MASK;

      for (led_num = 0; led_num < WS2812_LED_COUNT; led_num++)
      {
        leds[led_num] = color_value;
      }

      synchronize_leds(WS2812_LED_COUNT);
    }
    else if (menu_selection == 2)
    {
      synchronize_leds(WS2812_LED_COUNT);
    }

//    for (int i = 0; i < WS2812_LED_COUNT; i++)
//    {
//      leds[i] = (128 << WS2812_GREEN_OFFSET) & WS2812_GREEN_MASK;
//      leds[i] = (0 << WS2812_RED_OFFSET) & WS2812_RED_MASK;
//      leds[i] = (255 << WS2812_BLUE_OFFSET) & WS2812_BLUE_MASK;
//    }
  }

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
