#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "share.h"
#include "debug.h"
#include "cm_per.h"

volatile cm_per_t* cm_per_init(mem_mgr_t *mem_mgr)
{
    cm_per_t *cm_per;

    if ( (cm_per = mem_mgr_get_map(mem_mgr, CM_PER_BASE)) == 0 )
    {
        report_error("Receive NULL cm_per\n");
    }

    report_log("PRCM cm_per_base = %p\n", cm_per);

    return cm_per;
}

int cm_per_destroy(volatile cm_per_t *cm_per)
{
    if (!cm_per)
    {
        report_log("cm_per was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}

int cm_per_configure(volatile cm_per_t *cm_per)
{
    if (!cm_per)
        return -EINVAL;

    // enable PRU ICSS clock
    cm_per->pru_icss_clkctrl.MODULEMODE = CM_PER_MODULEMODE_ENABLE;

    // wake up PRU ICSS OCP clock
    cm_per->pru_icss_clkstctrl.CLKTRCTRL = CM_PER_CLKTRCTRL_SW_WKUP;

    return 0;
}

#if DEBUG_PRINT_REG
void cm_per_debug(volatile cm_per_t *cm_per)
{
    if (!cm_per)
    {
        report_error("cm_per was null\n");
        return;
    }

    printf("------------------------------------------------CM_PER DBG------------------------------------------------\n");
    printf("CM_PER addr = %p\n", CM_PER_BASE);
    printf("CM_PER_PRU_ICSS_CLKCTRL addr = %p\n", CM_PER_BASE + offsetof(cm_per_t, pru_icss_clkctrl));
    printf("CM_PER_PRU_ICSS_CLKSTCTRL addr = %p\n", CM_PER_BASE + offsetof(cm_per_t, pru_icss_clkstctrl));
    printf("\n");
    printf("CM_PER_PRU_ICSS_CLKCTRL.MODULEMODE = 0x%x\n", cm_per->pru_icss_clkctrl.MODULEMODE);
    printf("CM_PER_PRU_ICSS_CLKCTRL.IDLEST = 0x%x\n", cm_per->pru_icss_clkctrl.IDLEST);
    printf("CM_PER_PRU_ICSS_CLKCTRL.STBYST = 0x%x\n", cm_per->pru_icss_clkctrl.STBYST);
    printf("\n");
    printf("CM_PER_PRU_ICSS_CLKSTCTRL.CLKTRCTRL = 0x%x\n", cm_per->pru_icss_clkstctrl.CLKTRCTRL);
    printf("---------------------------------------------------------------------------------------------------------\n");
}
#endif // if DEBUG_PRINT_REG
