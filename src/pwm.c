// // #include "pwm.h"
// // 
// // uint32_t pwm_duty_cycle;
// // uint32_t pwm_period;
// // 
// // #define PWM_FREQUENCY 1000000000
// // 
// // ERROR_T pwm_init()
// // {
// //   return ERROR_NONE;
// // }
// // 
// // ERROR_T pwm_destroy()
// // {
// //   return ERROR_NONE;
// // }
// // 
// // // int pwm_set_period(uint32_t new_frequency, uint32_t new_duty_cycle)
// // // {
// // //   FILE fd_duty;
// // //   FILE fd_period;
// // // 
// // //   pwm_period_ns = PWM_FREQUENCY / new_frequency;
// // //   pwm_duty_ns = (unsigned long)(period_ns * (new_duty_cycle / 100.0));
// // // }
// // 
// // ERROR_T pwm_set_period(uint32_t new_frequency, uint32_t new_duty_cycle)
// // {
// //   if (duty_cycle > frequency)
// //   {
// //     return ERROR_BAD_PARAMETER;
// //   }
// // 
// //   return ERROR_NONE;
// // }
// // 
// // ERROR_T pwm_init()
// // {
// //   // echo 0 > /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/export
// //   // echo 1000 > /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/pwm-4\:0/period
// //   // echo 500 > /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/pwm-4\:0/duty_cycle
// //   // echo 1 > /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/pwm-4\:0/enable
// //   // echo pwm > /sys/bus/platform/drivers/bone-pinmux-helper/ocp\:P9_14_pinmux/state
// // }
// // 
// // // /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/
// // 
// // // { "EHRPWM1A", "P9_14", 50, 6, -1},
// // 
// // // pwm/pwmchip
// // //    const char *name; 
// // //    const char *key; 
// // //    int gpio;
// // //    int pwm_mux_mode;
// // //    int ain;
// // // 
// // // 
// // // typedef struct pwm_t {
// // //   const char *module;
// // //   const int sysfs;
// // //   const int index;
// // //   const int muxmode;
// // //   const char *path;
// // //   const char *name;
// // //   const char *chip;
// // //   const char *addr;
// // //   const char *key;  // Pin name eg P9_21
// // // } pwm_t;
// // // { "ehrpwm1", 3, 0, 6, "ehrpwm.1:0", "EHRPWM1A", "48302000", "48302200", "P9_14"},
// // // 
// // // ./sys/firmware/devicetree/base/__symbols__/ehrpwm2
// // // ./sys/firmware/devicetree/base/__symbols__/ehrpwm0
// // // ./sys/firmware/devicetree/base/__symbols__/ehrpwm1_tbclk
// // // ./sys/firmware/devicetree/base/__symbols__/ehrpwm1
// // // ./sys/firmware/devicetree/base/__symbols__/ehrpwm2_tbclk
// // // ./sys/firmware/devicetree/base/__symbols__/ehrpwm0_tbclk
// // // ./sys/firmware/devicetree/base/ocp/l4_wkup@44c00000/scm@210000/scm_conf@0/clocks/ehrpwm1_tbclk@44e10664
// // // ./sys/firmware/devicetree/base/ocp/l4_wkup@44c00000/scm@210000/scm_conf@0/clocks/ehrpwm0_tbclk@44e10664
// // // ./sys/firmware/devicetree/base/ocp/l4_wkup@44c00000/scm@210000/scm_conf@0/clocks/ehrpwm2_tbclk@44e10664
// // // ./sys/bus/platform/drivers/ehrpwm
// // // 
// // // 1 /sys/bus/platform/drivers/ehrpwm/48302200.pwm -> pwm/pwmchip[N]
// // // 2 echo 0 > /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/export
// // // 3
// // // 4 echo pwm > /sys/bus/platform/drivers/bone-pinmux-helper/ocp:P9_14_pinmux/state
// // // 
// // // 
// // // /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/export
// // // /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/pwm-4:0
// // // 
// // // 
// // // 
// // // // get pwm chip num
// // // 1 /sys/bus/platform/drivers/ehrpwm/48302200.pwm -> pwm/pwmchip[N]
// // // 
// // // syslog(LOG_DEBUG, "Adafruit_BBIO: pwm_start: sleep 100 ms after export to avoid udev race condition");
// // // usleep(100 * 1000); /* 100 ms */
// // // 
// // // // export pwm
// // // 2 echo 0 > /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/export
// // // 
// // // // disable pwm
// // // 3 echo 0 > /sys/bus/platform/drivers/ehrpwm/48302200.pwm/pwm/pwmchip4/pwm-4:0/
// // // 
// // // // polarity
// // // len = snprintf(buffer, sizeof(buffer), "normal");
// // // len = snprintf(buffer, sizeof(buffer), "inversed");
// // // 
// // // // set duty cycle
// // // 4 
// // // pwm->duty = duty;
// // // pwm->duty_ns = (unsigned long)(pwm->period_ns * (duty / 100.0));
// // // 
// // // len = snprintf(buffer, sizeof(buffer), "%lu", pwm->duty_ns);
// // // lseek(pwm->duty_fd, 0, SEEK_SET); // Seek to beginning of file
// // // 
// // // 
// // // pwm_period = 
// // // pwm_period_ns = PWM_FREQUENCY / frequency;
// // // pwm_duty_ns = (unsigned long)(period_ns * (new_duty_cycle / 100.0));
// // // 
// // // 
// // // pwm_period_ns = 1250
// // // duty_cycle_ns = 1250 * (28/100) = 350
// // // duty_cycle_ns = 1250 * (72/100) = 900
// // // 
