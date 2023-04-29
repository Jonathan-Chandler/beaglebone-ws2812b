#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include "util.h"
#include "control_module.h"

int _control_get_mmap(int devmem_fd);

control_t* control_init(mem_mgr_t *mem_mgr)
{
    control_t *CONTROL;
    void *control_base_addr;

    CONTROL = malloc(sizeof(control_t));
    if (!CONTROL)
    {
        report_error("Fail to allocate CONTROL\n");
        return NULL;
    }

    if ( (control_base_addr = mem_mgr_get_map(mem_mgr, CONTROL_MODULE_BASE_ADDR)) == 0 )
    {
        report_error("Receive NULL control_base_addr\n");
        goto error_exit;
    }

    CONTROL->base_addr = control_base_addr;
    CONTROL->pin_addr = (uint32_t*)((uintptr_t)control_base_addr + CM_PWMSS_CTRL_OFFS);
    CONTROL->pwm_addr = (uint32_t*)((uintptr_t)control_base_addr + CM_CONF_GPMC_AD9_OFFS);

    report_log("CONTROL base_addr = %p\n", CONTROL->base_addr);
    report_log("CONTROL pin_addr = %p\n", CONTROL->pin_addr);
    report_log("CONTROL pwm_addr = %p\n", CONTROL->pwm_addr);

    return CONTROL;

error_exit:
    if (CONTROL)
        free(CONTROL);

    return NULL;
}

int control_destroy(control_t *CONTROL)
{
    if (!CONTROL)
    {
        report_log("CONTROL was null\n");
        return -1;
    }
        
    free(CONTROL);

    return 0;
}

static const char* P8_13_MODE_NAMES[] = 
{
    "GPMC_AD9       ",  // 0
    "LCD_DATA22     ",  // 1
    "MMC1_DAT1      ",  // 2
    "MMC2_DAT5      ",  // 3
    "EHRPWM2B       ",  // 4
    "PR1_MII0_COL   ",  // 5
    "INVALID        ",  // 6
    "GPIO_0_23      ",  // 7
};

void control_debug(control_t *CONTROL)
{
    if (!CONTROL)
    {
        report_error("NULL CONTROL\n");
        return;
    }

    printf("\n------------------------CTRL  DBG------------------------\n");
    printf("CONTROL base_addr = %p\n", CONTROL->base_addr);
    printf("CONTROL pin_addr = %p\n", CONTROL->pin_addr);
    printf("CONTROL pwm_addr = %p\n", CONTROL->pwm_addr);
    printf("\n");
    printf("PIN SLEW:       %s\n", (*CONTROL->pin_addr & CM_CONF_MOD_PIN_SLEW_SLOW) ? "SLOW" : "FAST");
    printf("PIN RX ACTIVE:  %s\n", (*CONTROL->pin_addr & CM_CONF_MOD_PIN_RX_ACTIVE) ? "INPUT" : "OUTPUT");
    printf("PIN PU TYPESEL: %s\n", (*CONTROL->pin_addr & CM_CONF_MOD_PIN_PU_TYPESEL) ? "PULL UP" : "PULL DOWN");
    printf("PIN PU/PD EN:   %s\n", (*CONTROL->pin_addr & CM_CONF_MOD_PIN_PUD_EN) ? "ENABLED" : "DISABLED");
    printf("PIN MODE_SEL:   %d\n", (*CONTROL->pin_addr & CM_CONF_MOD_PIN_MODE_SEL_MASK));
    printf("PIN MODE NAME:  %s\n", P8_13_MODE_NAMES[(*CONTROL->pin_addr & CM_CONF_MOD_PIN_MODE_SEL_MASK)]);
    printf("\n");
    printf("PWM 0 TBCLK: %s\n", (*CONTROL->pwm_addr & CM_PWMSS_CTRL_PWMSS0_TBCLKEN) ? "ENABLED" : "DISABLED");
    printf("PWM 1 TBCLK: %s\n", (*CONTROL->pwm_addr & CM_PWMSS_CTRL_PWMSS1_TBCLKEN) ? "ENABLED" : "DISABLED");
    printf("PWM 2 TBCLK: %s\n", (*CONTROL->pwm_addr & CM_PWMSS_CTRL_PWMSS2_TBCLKEN) ? "ENABLED" : "DISABLED");
    printf("---------------------------------------------------------\n");
}

