#ifndef __PRU_CTRL_H__
#define __PRU_CTRL_H__
#include <stdint.h>
#include <errno.h>
#include "util.h"
#include "memory_manager.h"

#define PRU_ICSS_BASE_ADDR                  (void*)0x4A300000
#define PRU_DATA_8KB_RAM0_BASE_ADDR         (void*)0x4A300000
#define PRU_DATA_8KB_RAM1_BASE_ADDR         (void*)0x4A302000
#define PRU_ICSS_SHMEM_START                (void*)0x4A310000
#define PRU_0_CTRL_BASE_ADDR                (void*)0x4A322000
#define PRU_0_DEBUG_BASE_ADDR               (void*)0x4A322400
#define PRU_1_CTRL_BASE_ADDR                (void*)0x4A324000
#define PRU_1_DEBUG_BASE_ADDR               (void*)0x4A324400
#define PRU_GLOBAL_CFG_BASE_ADDR            (void*)0x4A326000


// CTRL - 0x0
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t SOFT_RST_N:1;      // 0
    uint32_t EN:1;              // 1
    uint32_t SLEEPING:1;        // 2
    uint32_t CTR_EN:1;          // 3
    uint32_t RESERVED0:4;       // 4-7
    uint32_t SINGLE_STEP:1;     // 8
    uint32_t RESERVED1:6;       // 14-9
    uint32_t RUNSTATE:1;        // 15 - RO
    uint32_t PCTR_RST_VAL:16;   // 31-16
} pru_icss_pru_ctrl_t;

#define PRU_CTRL_SOFT_RST_N_DO_RESET    0x0
#define PRU_CTRL_SOFT_RST_N_DONT_RESET  0x1
#define PRU_CTRL_EN_PRU_DISABLED        0x0
#define PRU_CTRL_EN_PRU_ENABLED         0x1
#define PRU_CTRL_SLEEPING_AWAKE         0x0
#define PRU_CTRL_SLEEPING_SLEEPING      0x1
#define PRU_CTRL_CTR_EN_NOT_COUNTING    0x0
#define PRU_CTRL_CTR_EN_COUNTING        0x1
#define PRU_CTRL_SINGLE_STEP_FREE       0x0
#define PRU_CTRL_SINGLE_STEP_SINGLE     0x1

// PRU_ICSS 0x4A30_0000
// devmem 0x4A322000 32
// devmem 0x4A322000 32 0x1
// 0000 0000 0000 0000 1000 0000 0000 1011
// 0x0000800B
// devmem 0x4A322000 32 0x0000800B
// 
//0x00002001
// am335x-pru1-fw


// STS - 0x4
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t PCTR:16;           // 15-0 - RO
    uint32_t RESERVED0:16;      // 31-16
} pru_icss_pru_sts_t;

// PWMSS struct
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    pru_icss_pru_ctrl_t CTRL;
    pru_icss_pru_sts_t  STS;
} pru_ctrl_t;
#define PRU_CTRL_REGISTER_SIZE      0x10

volatile pru_ctrl_t* pru_ctrl_init(mem_mgr_t *mem_mgr);
int pru_ctrl_destroy(volatile pru_ctrl_t *pru_ctrl);

int pru_ctrl_configure(volatile pru_ctrl_t *pru_ctrl);

#if DEBUG_PRINT_REG
void pru_ctrl_debug(volatile pru_ctrl_t *pru_ctrl);
#endif // if DEBUG_PRINT_REG

#endif
