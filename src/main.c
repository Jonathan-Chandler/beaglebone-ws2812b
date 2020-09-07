// #include <stdio.h>
// #include <stdbool.h>
// #include <stdint.h>
// #include "ws2812b.h"

#define WS2812_LED_COUNT 150
#define WS2812_LED_COUNT 150

// lib/ti/pru-software-support-package/include/am572x_2_0/pru_cfg.h
// lib/ti/pru-software-support-package/include/am335x/pru_cfg.h
// lib/ti/pru-software-support-package/include/am571x/pru_cfg.h
// lib/ti/pru-software-support-package/include/am572x_1_1/pru_cfg.h
// lib/ti/pru-software-support-package/include/am437x/pru_cfg.h
// lib/ti/pru-software-support-package/include/k2g/pru_cfg.h


// /sys/devices/platform/ocp/ocp\:P9_14_pinmux/driver/ocp\:P9_30_pinmux/of_node/pinctrl-names
// /sys/devices/platform/ocp/ocp\:P9_14_pinmux/driver/ocp\:P9_30_pinmux/of_node/pinctrl-names
// pruout
// // int main()
// // {
// //   led_t *leds = init_leds(WS2812_LED_COUNT);
// // 
// //   if (!leds)
// //   {
// //     printf("fail to allocate\n");
// //     return -1;
// //   }
// // 
// //   set_all_leds(leds, 255, 0, 255);
// // 
// //   destroy_leds(&leds);
// //   if (leds)
// //   {
// //     printf("fail to deallocate\n");
// //     return -1;
// //   }
// // 
// //   printf("exit\n");
// //   return 0;
// // }

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <phys_addr> <offset>\n", argv[0]);
        return 0;
    }

    off_t offset = strtoul(argv[1], NULL, 0);
    size_t len = strtoul(argv[2], NULL, 0);

    // Truncate offset to a multiple of the page size, or mmap will fail.
    size_t pagesize = sysconf(_SC_PAGE_SIZE);
    off_t page_base = (offset / pagesize) * pagesize;
    off_t page_offset = offset - page_base;

    int fd = open("/dev/mem", O_SYNC);
    unsigned char *mem = (unsigned char *)mmap(NULL, page_offset + len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, page_base);
    if (mem == MAP_FAILED) {
        perror("Can't map memory");
        return -1;
    }

    size_t i;
    for (i = 0; i < len; ++i)
        printf("%02x ", (int)mem[page_offset + i]);

    return 0;
}

// void test(void)
// {
//   led_t *leds = init_leds(WS2812_LED_COUNT);
// 
//   if (!leds)
//   {
//     printf("fail to allocate\n");
//     return -1;
//   }
// 
//   if (leds->led_count != 20)
//   {
//     printf("wrong led count\n");
//   }
// 
//   if (leds->led_color[0].red != 0)
//   {
//     printf("red\n");
//   }
// 
//   if (leds->led_color[0].green != 0)
//   {
//     printf("green\n");
//   }
// 
//   if (leds->led_color[0].blue != 0)
//   {
//     printf("blue\n");
//   }
// 
//   set_led(leds, 0, 20, 0, 0);
// 
// 
//   if (leds->led_color[0].red != 20)
//   {
//     printf("red\n");
//   }
// 
//   if (leds->led_color[0].green != 0)
//   {
//     printf("green\n");
//   }
// 
//   if (leds->led_color[0].blue != 0)
//   {
//     printf("blue\n");
//   }
// 
//   destroy_leds(&leds);
//   if (leds)
//   {
//     printf("fail to deallocate\n");
//     return -1;
//   }
// 
//   test_ws();
//   printf("exit\n");
// }

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
