#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "share.h"
#include "debug.h"
#include "prm_per.h"

volatile prm_per_t* prm_per_init(mem_mgr_t *mem_mgr)
{
    prm_per_t *prm_per;

    if ( (prm_per = mem_mgr_get_map(mem_mgr, PRM_PER_BASE)) == 0 )
    {
        report_error("Receive NULL prm_per\n");
    }

    report_log("PRCM prm_per_base = %p\n", prm_per);

    return prm_per;
}

int prm_per_destroy(volatile prm_per_t *prm_per)
{
    if (!prm_per)
    {
        report_log("prm_per was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}

int prm_per_configure(volatile prm_per_t *prm_per)
{
    if (!prm_per)
        return -EINVAL;

    // clear PRU ICSS local reset control
    prm_per->prm_per_rstctrl.PRU_ICSS_LRST = PRM_PER_PRU_ICSS_LRST_CLEAR;

    return 0;
}

#if DEBUG_PRINT_REG
void prm_per_debug(volatile prm_per_t *prm_per)
{
    if (!prm_per)
    {
        report_error("prm_per was null\n");
        return;
    }

    printf("------------------------------------------------PRM_PER DBG-----------------------------------------------\n");
    printf("PRM_PER addr = %p\n", PRM_PER_BASE);
    printf("PRM_PER_RSTCTRL addr = %p\n", PRM_PER_BASE + offsetof(prm_per_t, prm_per_rstctrl));
    printf("\n");
    printf("PRM_PER_RSTCTRL.PRU_ICSS_LRST = 0x%x\n", prm_per->prm_per_rstctrl.PRU_ICSS_LRST);
    printf("---------------------------------------------------------------------------------------------------------\n");
}
#endif // if DEBUG_PRINT_REG

