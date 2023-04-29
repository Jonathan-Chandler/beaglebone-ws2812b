#ifndef __CONTROL_H__
#define __CONTROL_H__
#include <stdint.h>
#include <stddef.h>
#include "util.h"
#include "memory_manager.h"

// TBCTL (Time-Base Control) - 0x0
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct
{
    int control_fd;
    void *base_addr;
    uint32_t *pin_addr;
    uint32_t *pwm_addr;
} control_t;

// CONTROL_MODULE
#define CONTROL_MODULE_BASE_ADDR        (void*)0x44E10000

#define CM_PWMSS_CTRL_OFFS              (uintptr_t)0x664    // pulse width modulator subsystem
#define CM_PWMSS_CTRL_PWMSS2_TBCLKEN    BIT(2)              // enable time base clock for pwm subsystem 2
#define CM_PWMSS_CTRL_PWMSS1_TBCLKEN    BIT(1)              // enable time base clock for pwm subsystem 1
#define CM_PWMSS_CTRL_PWMSS0_TBCLKEN    BIT(0)              // enable time base clock for pwm subsystem 0

#define CM_CONF_GPMC_AD9_OFFS           (uintptr_t)0x824    // Pin 8.13 | T10 | GPIO0_23
#define CM_CONF_P8_13_MODE_GPMC_AD9     0x0                 // pin 8.13 signal name = gpmc_ad9
#define CM_CONF_P8_13_MODE_LCD_DATA22   0x1                 // Pin 8.13 signal name = lcd_data22
#define CM_CONF_P8_13_MODE_MMC1_DAT1    0x2                 // Pin 8.13 signal name = mmc1_dat1
#define CM_CONF_P8_13_MODE_MMC2_DAT5    0x3                 // Pin 8.13 signal name = mmc2_dat5
#define CM_CONF_P8_13_MODE_EHRPWM2B     0x4                 // Pin 8.13 signal name = ehrpwm2b (pwm 2 output B)
#define CM_CONF_P8_13_MODE_PR1_MII0_COL 0x5                 // Pin 8.13 signal name = pr1_mii0_col
#define CM_CONF_P8_13_MODE_GPIO_0_23    0x7                 // Pin 8.13 signal name = gpio0_23

#define CM_CONF_MOD_PIN_SLEW_FAST       0x0                 // slew rate fast
#define CM_CONF_MOD_PIN_SLEW_SLOW       BIT(6)              // slew rate slow
#define CM_CONF_MOD_PIN_RX_INACTIVE     0x0                 // input disable
#define CM_CONF_MOD_PIN_RX_ACTIVE       BIT(5)              // input enable
#define CM_CONF_MOD_PIN_PU_TYPESEL      BIT(4)              // pull up type select
#define CM_CONF_MOD_PIN_PD_TYPESEL      0x0                 // pull down type select
#define CM_CONF_MOD_PIN_PUD_EN          BIT(3)              // pull up/down is enabled
#define CM_CONF_MOD_PIN_PUD_DIS         0x0                 // pull up/down is disabled
#define CM_CONF_MOD_PIN_MODE_SEL_MASK   0x7                 // pin multiplex mode select 0-7


void        control_debug(control_t *CONTROL);

control_t*  control_init(mem_mgr_t *mem_mgr);
int         control_destroy(control_t *CONTROL);

#endif
