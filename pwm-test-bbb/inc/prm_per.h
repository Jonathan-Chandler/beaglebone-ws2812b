#ifndef __PRM_PER_H__
#define __PRM_PER_H__
#include "util.h"
#include "memory_manager.h"

#define PRM_PER_BASE                    (void*)0x44E00C00
#define PRM_IRQ_BASE                    0x44E00B00           // Power Reset Module IRQ Registers
#define PRM_WKUP_BASE                   0x44E00D00
#define PRM_MPU_BASE                    0x44E00E00
#define PRM_DEV_BASE                    0x44E00F00

// PRM_PER_BASE
// devmem 0x44E00C00 32 0

// PRU shared memory
// devmem 0x4A310000 32
// ls /proc/device-tree/ocp/interconnect@4a000000/segment@0/target-module@300000/pruss@0

// Power and Reset Management

typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t RESERVED0:1;                   // 0
    uint32_t PRU_ICSS_LRST:1;               // 1
#define PRM_PER_PRU_ICSS_LRST_CLEAR 0x0
#define PRM_PER_PRU_ICSS_LRST_ASSERT 0x1
    uint32_t RESERVED1:30;                  // 31-2 
} prm_per_rstctrl_t;

typedef struct __attribute__((packed, aligned(4)))
{
    prm_per_rstctrl_t prm_per_rstctrl;     // 0x0 - 0x4
} prm_per_t;

volatile prm_per_t* prm_per_init(mem_mgr_t *mem_mgr);
int prm_per_destroy(volatile prm_per_t *prm_per);

int     prm_per_configure(volatile prm_per_t *prm_per);

#if DEBUG_PRINT_REG
void    prm_per_debug(volatile prm_per_t *prm_per);
#endif

// devmem 0x44E00C00 32 0

#endif


