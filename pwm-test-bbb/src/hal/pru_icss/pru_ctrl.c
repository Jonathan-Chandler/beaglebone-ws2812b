#include <errno.h>
#include <stddef.h>

#include "debug.h"
#include "util.h"
#include "memory_manager.h"
#include "hal/pru_icss/pru_ctrl.h"

volatile pru_ctrl_t* pru_ctrl_init(mem_mgr_t *mem_mgr)
{
    pru_ctrl_t *pru_ctrl;

    if ( (pru_ctrl = mem_mgr_get_map(mem_mgr, PRU_0_CTRL_BASE_ADDR)) == 0 )
    {
        report_error("Receive NULL pru_ctrl\n");
    }

    report_log("pru_ctrl = %p\n", pru_ctrl);

    return pru_ctrl;
}

int pru_ctrl_destroy(volatile pru_ctrl_t *pru_ctrl)
{
    if (!pru_ctrl)
    {
        report_log("pru_ctrl was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}

int pru_ctrl_configure(volatile pru_ctrl_t *pru_ctrl)
{
    if (!pru_ctrl)
        return -EINVAL;

    pru_ctrl->CTRL.SOFT_RST_N = PRU_CTRL_SOFT_RST_N_DO_RESET;   // reset processor
    pru_ctrl->CTRL.EN = PRU_CTRL_EN_PRU_ENABLED;                // enable
    pru_ctrl->CTRL.SLEEPING = PRU_CTRL_SLEEPING_AWAKE;          // wake up
    pru_ctrl->CTRL.CTR_EN = PRU_CTRL_CTR_EN_NOT_COUNTING;       // do not count cycles
    pru_ctrl->CTRL.SINGLE_STEP = PRU_CTRL_SINGLE_STEP_FREE;     // do not stop after single step
    pru_ctrl->CTRL.PCTR_RST_VAL = 0;                            // start at 0x0 after leaving reset

    return 0;
}

#if DEBUG_PRINT_REG
void pru_ctrl_debug(volatile pru_ctrl_t *pru_ctrl)
{
    if (!pru_ctrl)
    {
        report_error("pru_ctrl was null\n");
        return;
    }

    printf("------------------------------------------------PRU_CTRL DBG----------------------------------------------\n");
    printf("pru_ctrl addr = %p\n", PRU_0_CTRL_BASE_ADDR);
    printf("pru_ctrl.CTRL addr = %p\n", PRU_0_CTRL_BASE_ADDR + offsetof(pru_ctrl_t, CTRL));
    printf("pru_ctrl.STS addr = %p\n", PRU_0_CTRL_BASE_ADDR + offsetof(pru_ctrl_t, STS));
    printf("\n");
    printf("pru_ctrl.CTRL.SOFT_RST_N = %X\n", pru_ctrl->CTRL.SOFT_RST_N);       // 0x1
    printf("pru_ctrl.CTRL.EN = %X\n", pru_ctrl->CTRL.EN);                       // 0x1
    printf("pru_ctrl.CTRL.SLEEPING = %X\n", pru_ctrl->CTRL.SLEEPING);           // 0x0
    printf("pru_ctrl.CTRL.CTR_EN = %X\n", pru_ctrl->CTRL.CTR_EN);               // 0x0
    printf("pru_ctrl.CTRL.SINGLE_STEP = %X\n", pru_ctrl->CTRL.SINGLE_STEP);     // 0x0
    printf("pru_ctrl.CTRL.RUNSTATE = %X\n", pru_ctrl->CTRL.RUNSTATE);           // 0x1
    printf("pru_ctrl.CTRL.PCTR_RST_VAL = %X\n", pru_ctrl->CTRL.PCTR_RST_VAL);   // 0x0
    printf("\n");
    printf("pru_ctrl.STS.PCTR = 0x%X\n", pru_ctrl->STS.PCTR);
    printf("---------------------------------------------------------------------------------------------------------\n");
}
#endif // if DEBUG_PRINT_REG
