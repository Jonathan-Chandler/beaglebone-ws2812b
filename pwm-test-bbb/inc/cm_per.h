#ifndef __CM_PER_H__
#define __CM_PER_H__
#include "util.h"
#include "memory_manager.h"

#define CM_WKUP_BASE                    0x44E00400           // Clock Module Peripheral Registers
#define CM_DEVICE_BASE                  0x44E00700           // Clock Module Peripheral Registers

// Power, Reset, and Clock Management
#define CM_PER_BASE                     (void*)0x44E00000           // Clock Module Peripheral Registers
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

typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t MODULEMODE:2;                  // 1-0      - module configure (r/w)
#define CM_PER_MODULEMODE_DISABLE      0x0
#define CM_PER_MODULEMODE_RESERVED     0x1
#define CM_PER_MODULEMODE_ENABLE       0x2
    uint32_t RESERVED0:14;                  // 15-2
    uint32_t IDLEST:2;                      // 17-16    - idle status
#define CM_PER_IDLEST_FUNCTIONAL       0x0
#define CM_PER_IDLEST_TRANSITIONING    0x1
#define CM_PER_IDLEST_IDLE             0x2
#define CM_PER_IDLEST_DISABLED         0x3
    uint32_t STBYST:1;                      // 18       - standby status
#define CM_PER_STBYST_FUNCTIONAL       0x0
#define CM_PER_STBYST_STANDBY          0x1
    uint32_t RESERVED:13;                   // 31-19
} clkctrl_t;

typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t CLKTRCTRL:2;                   // 1-0
#define CM_PER_CLKTRCTRL_NO_SLEEP      0x0
#define CM_PER_CLKTRCTRL_SW_SLEEP      0x1
#define CM_PER_CLKTRCTRL_SW_WKUP       0x2
#define CM_PER_CLKTRCTRL_RESERVED      0x3
    uint32_t RESERVED0:2;                   // 3-2
    uint32_t CLKACTIVITY_OCP:1;             // 4
    uint32_t CLKACTIVITY_IEP:1;             // 5
    uint32_t CLKACTIVITY_UART:1;            // 6
    uint32_t RESERVED1:25;                  // 31-7
} clkstctrl_t;

typedef struct __attribute__((packed, aligned(4)))
{
    char fill0[0xE8];               // 0x000 - 0x0E8
    clkctrl_t pru_icss_clkctrl;     // 0x0E8 - 0x0EC
    char fill1[0x54];               // 0x0EC - 0x140
    clkstctrl_t pru_icss_clkstctrl; // 0x140 - 0x144
} cm_per_t;

volatile cm_per_t* cm_per_init(mem_mgr_t *mem_mgr);
int cm_per_destroy(volatile cm_per_t *cm_per);

int     cm_per_configure(volatile cm_per_t *CM_PER);

#if DEBUG_PRINT_REG
void    cm_per_debug(volatile cm_per_t *cm_per);
#endif

// devmem 0x44E00C00 32 0

#endif

