#include <errno.h>
#include <stddef.h>

#include "debug.h"
#include "util.h"
#include "memory_manager.h"
#include "hal/pru_icss/pru_cfg.h"

volatile pru_cfg_t* pru_cfg_init(mem_mgr_t *mem_mgr)
{
    pru_cfg_t *pru_cfg;

    if ( (pru_cfg = mem_mgr_get_map(mem_mgr, PRU_GLOBAL_CFG_BASE_ADDR)) == 0 )
    {
        report_error("Receive NULL pru_cfg\n");
    }

    report_log("pru_cfg = %p\n", pru_cfg);

    return pru_cfg;
}

int pru_cfg_destroy(volatile pru_cfg_t *pru_cfg)
{
    if (!pru_cfg)
    {
        report_log("pru_cfg was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}

int pru_cfg_configure(volatile pru_cfg_t *pru_cfg)
{
    if (!pru_cfg)
        return -EINVAL;

    pru_cfg->SYSCFG.IDLE_MODE = PRU_CFG_IDLE_STANDBY_MODE_NO;       // no idle
    pru_cfg->SYSCFG.STANDBY_MODE = PRU_CFG_IDLE_STANDBY_MODE_NO;    // no standby
    pru_cfg->SYSCFG.STANDBY_INIT = PRU_CFG_STANDBY_INIT_EN_OCP;     // enable ocp master ports
    pru_cfg->PMAO.PMAO_PRU0 = PRU_CFG_PMAO_EN;                      // enable offset to access same addresses as host

    return 0;
}

#if DEBUG_PRINT_REG
void pru_cfg_debug(volatile pru_cfg_t *pru_cfg)
{
    if (!pru_cfg)
    {
        report_error("pru_cfg was null\n");
        return;
    }

    printf("------------------------------------------------PRU_CFG DBG-----------------------------------------------\n");
    printf("pru_cfg addr = %p\n", PRU_GLOBAL_CFG_BASE_ADDR);
    printf("pru_cfg.SYSCFG addr = %p\n", PRU_GLOBAL_CFG_BASE_ADDR + offsetof(pru_cfg_t, SYSCFG));
    printf("pru_cfg.PMAO addr = %p\n", PRU_GLOBAL_CFG_BASE_ADDR + offsetof(pru_cfg_t, PMAO));
    printf("\n");
    printf("pru_cfg.SYSCFG.IDLE_MODE = 0x%X\n", pru_cfg->SYSCFG.IDLE_MODE);         // 0x1 - no idle
    printf("pru_cfg.SYSCFG.STANDBY_MODE = 0x%X\n", pru_cfg->SYSCFG.STANDBY_MODE);   // 0xl - no stby
    printf("pru_cfg.SYSCFG.STANDBY_INIT = 0x%X\n", pru_cfg->SYSCFG.STANDBY_INIT);   // 0x0 - enable OCP
    printf("\n");
    printf("pru_cfg.PMAO.PMAO_PRU0 = 0x%X\n", pru_cfg->PMAO.PMAO_PRU0);             // 0x1 - use PMAO address for pru0
    printf("---------------------------------------------------------------------------------------------------------\n");
}
#endif // if DEBUG_PRINT_REG
