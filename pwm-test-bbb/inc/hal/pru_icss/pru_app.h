#ifndef __PRU_APP_H__
#define __PRU_APP_H__
#include <stdint.h>
#include <errno.h>
#include "util.h"
#include "memory_manager.h"

#define PRU_DATA_8KB_RAM0_BASE_ADDR         (void*)0x4A300000
#define PRU_0_IRAM_BASE_ADDR                (void*)0x4A334000

// PWMSS struct
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint8_t data[0x4000];
} pru_app_t;

volatile pru_app_t* pru_app_init(mem_mgr_t *mem_mgr);
int pru_app_destroy(volatile pru_app_t *pru_app);

int pru_app_configure(volatile pru_app_t *pru_app);

#if DEBUG_PRINT_REG
void pru_app_debug(volatile pru_app_t *pru_app);
#endif // if DEBUG_PRINT_REG

#endif

