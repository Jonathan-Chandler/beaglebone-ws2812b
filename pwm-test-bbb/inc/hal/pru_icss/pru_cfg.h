#ifndef __PRU_CFG_H__
#define __PRU_CFG_H__
#include <stdint.h>
#include <errno.h>
#include "util.h"
#include "memory_manager.h"

#define PRU_GLOBAL_CFG_BASE_ADDR            (void*)0x4A326000

// SYSCFG - 0x4
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t IDLE_MODE:2;       // 1-0
    uint32_t STANDBY_MODE:2;    // 3-2
    uint32_t STANDBY_INIT:1;    // 4
    uint32_t SUB_MWAIT:1;       // 5
    uint32_t RESERVED0:26;      // 31-6
} pru_icss_cfg_syscfg_t;

#define PRU_CFG_IDLE_STANDBY_MODE_FORCE     0x0 // force standby/idle
#define PRU_CFG_IDLE_STANDBY_MODE_NO        0x1 // no standby/idle mode
#define PRU_CFG_IDLE_STANDBY_MODE_SMART     0x2 // smart standby/idle mode
#define PRU_CFG_IDLE_STANDBY_MODE_RESERVED  0x3

#define PRU_CFG_STANDBY_INIT_EN_OCP         0x0
#define PRU_CFG_STANDBY_INIT_STANDBY        0x1

// PMAO - 0x28
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t PMAO_PRU0:1;       // 0
    uint32_t PMAO_PRU1:1;       // 1
    uint32_t RESERVED:30;       // 31-2
} pru_icss_cfg_pmao_t;

#define PRU_CFG_PMAO_EN     0x1 // enable address offset of -0x8_0000
#define PRU_CFG_PMAO_DIS    0x0 // disable address offset

// PRU_CFG struct
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t REVID;                     // 0x0
    pru_icss_cfg_syscfg_t SYSCFG;       // 0x4
    char fill[0x20];                    // 0x8 - 0x28
    pru_icss_cfg_pmao_t PMAO;
} pru_cfg_t;
#define PRU_CTRL_REGISTER_SIZE      0x10

volatile pru_cfg_t* pru_cfg_init(mem_mgr_t *mem_mgr);
int pru_cfg_destroy(volatile pru_cfg_t *pru_cfg);

int pru_cfg_configure(volatile pru_cfg_t *pru_cfg);

#if DEBUG_PRINT_REG
void pru_cfg_debug(volatile pru_cfg_t *pru_cfg);
#endif // if DEBUG_PRINT_REG
#endif

