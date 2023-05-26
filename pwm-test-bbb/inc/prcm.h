#ifndef __PRCM_H__
#define __PRCM_H__
#include "util.h"
#include "memory_manager.h"

// Power, Reset, and Clock Management
#define CM_PER_BASE                     (void*)0x44E00000           // Clock Module Peripheral Registers
#define CM_PER_EPWMSS0_CLKCTRL_OFFS     (uintptr_t)0xD4
#define CM_PER_EPWMSS1_CLKCTRL_OFFS     (uintptr_t)0xCC
#define CM_PER_EPWMSS2_CLKCTRL_OFFS     (uintptr_t)0xD8
#define CM_PER_PRU_ICSS_CLKCTRL_OFFS    (uintptr_t)0xE8

#define CM_PER_MODULE_STBY_STATUS       BIT(18)
#define CM_PER_MODULE_STBY_FUNC         0
#define CM_PER_MODULE_IDLEST_OFFS       16
#define CM_PER_MODULE_IDLEST_MASK       (BIT(17) | BIT(16))
#define CM_PER_MODULE_IDLEST_FUNC       0x0
#define CM_PER_MODULE_IDLEST_TRANSIT    BIT(16)
#define CM_PER_MODULE_IDLEST_IDLE       BIT(17)
#define CM_PER_MODULE_IDLEST_DISABLE    (BIT(17) | BIT(16))
#define CM_PER_MODULE_MODE_OFFS         0
#define CM_PER_MODULE_MODE_MASK         0x3
#define CM_PER_MODULE_MODE_ENABLE       0x2

#define CM_WKUP_BASE                    0x44E00400           // Clock Module Wakeup Registers
#define CM_DEVICE_BASE                  0x44E00700           // Clock Module Device Registers

#define PRM_IRQ_BASE                    0x44E00B00           // Power Reset Module IRQ Registers
#define PRM_PER_BASE                    0x44E00C00           // Power Reset Module Peripheral Registers
#define PRM_WKUP_BASE                   0x44E00D00           // Power Reset Module Wakeup Registers
#define PRM_MPU_BASE                    0x44E00E00           // Power Reset Module MPU Registers
#define PRM_DEV_BASE                    0x44E00F00           // Power Reset Module Device Registers

typedef struct
{
    volatile void     *cm_per_base;
    volatile uint32_t *cm_per_epwmss0;
    volatile uint32_t *cm_per_epwmss1;
    volatile uint32_t *cm_per_epwmss2;
    volatile uint32_t *cm_per_pru_icss_clkstctrl;
} prcm_t;

void    prcm_debug(prcm_t *PRCM);

prcm_t* prcm_init(mem_mgr_t *mem_mgr);
int     prcm_destroy(prcm_t *PRCM);

int     prcm_start_all(prcm_t *PRCM);
int     prcm_start_epwmss(prcm_t *PRCM);
int     prcm_start_pru_icss(prcm_t *PRCM);

#endif

