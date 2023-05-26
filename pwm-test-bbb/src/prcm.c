#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "prcm.h"

static const char *cm_per_idlest[] = 
{
    "FUNC       ",
    "TRANSITION ",
    "IDLE       ",
    "DISABLE    ",
};

static const char *cm_per_mode[] = 
{
    "DISABLE    ",
    "RESERVED   ",
    "ENABLE     ",
    "RESERVED2  ",
};

void prcm_debug(prcm_t *PRCM)
{
    if (!PRCM)
    {
        report_error("NULL PRCM\n");
        return;
    }

    printf("------------------------------------------------CTRL  DBG------------------------------------------------\n");
    printf("PRCM cm_per module base addr = %p\n", CM_PER_BASE);
    printf("PRCM cm_per_base addr = %p\n", PRCM->cm_per_base);
    printf("PRCM epwmss0 addr = %p\n", PRCM->cm_per_epwmss0);
    printf("PRCM epwmss1 addr = %p\n", PRCM->cm_per_epwmss1);
    printf("PRCM epwmss2 addr = %p\n", PRCM->cm_per_epwmss2);
    printf("PRCM pru_icss_clkstctrl addr = %p\n", PRCM->cm_per_pru_icss_clkstctrl);
    printf("\n");
    printf("CM_PER_EPWMSS0_CLKCTRL IDLEST: %s\n", cm_per_idlest[(*PRCM->cm_per_epwmss0 & CM_PER_MODULE_IDLEST_MASK) >> CM_PER_MODULE_IDLEST_OFFS]);
    printf("CM_PER_EPWMSS0_CLKCTRL MODULEMODE: %s\n", cm_per_mode[(*PRCM->cm_per_epwmss0 & CM_PER_MODULE_MODE_MASK) >> CM_PER_MODULE_MODE_OFFS]);
    printf("CM_PER_EPWMSS1_CLKCTRL IDLEST: %s\n", cm_per_idlest[(*PRCM->cm_per_epwmss1 & CM_PER_MODULE_IDLEST_MASK) >> CM_PER_MODULE_IDLEST_OFFS]);
    printf("CM_PER_EPWMSS1_CLKCTRL MODULEMODE: %s\n", cm_per_mode[(*PRCM->cm_per_epwmss1 & CM_PER_MODULE_MODE_MASK) >> CM_PER_MODULE_MODE_OFFS]);
    printf("CM_PER_EPWMSS2_CLKCTRL IDLEST: %s\n", cm_per_idlest[(*PRCM->cm_per_epwmss2 & CM_PER_MODULE_IDLEST_MASK) >> CM_PER_MODULE_IDLEST_OFFS]);
    printf("CM_PER_EPWMSS2_CLKCTRL MODULEMODE: %s\n", cm_per_mode[(*PRCM->cm_per_epwmss2 & CM_PER_MODULE_MODE_MASK) >> CM_PER_MODULE_MODE_OFFS]);
    printf("\n");
    printf("CM_PER_PRU_ICSS_CLKCTRL STBYST: %s\n", (*PRCM->cm_per_pru_icss_clkstctrl & CM_PER_MODULE_STBY_STATUS) ? "Standby" : "Func");
    printf("CM_PER_PRU_ICSS_CLKCTRL IDLEST: %s\n", cm_per_mode[(*PRCM->cm_per_pru_icss_clkstctrl & CM_PER_MODULE_IDLEST_MASK) >> CM_PER_MODULE_IDLEST_OFFS]);
    printf("CM_PER_PRU_ICSS_CLKCTRL MODULEMODE: %s\n", cm_per_mode[(*PRCM->cm_per_pru_icss_clkstctrl & CM_PER_MODULE_MODE_MASK) >> CM_PER_MODULE_MODE_OFFS]);
    printf("---------------------------------------------------------------------------------------------------------\n");
}

prcm_t*     prcm_init(mem_mgr_t *mem_mgr)
{
    prcm_t *PRCM;
    void *cm_per_base;

    PRCM = malloc(sizeof(prcm_t));
    if (!PRCM)
    {
        report_error("Fail to allocate PRCM\n");
        return NULL;
    }

    if ( (cm_per_base = mem_mgr_get_map(mem_mgr, CM_PER_BASE)) == 0 )
    {
        report_error("Receive NULL cm_per_base\n");
        goto error_exit;
    }

    PRCM->cm_per_base = cm_per_base;
    PRCM->cm_per_epwmss0 = (volatile uint32_t*)((uintptr_t)cm_per_base + CM_PER_EPWMSS0_CLKCTRL_OFFS);
    PRCM->cm_per_epwmss1 = (volatile uint32_t*)((uintptr_t)cm_per_base + CM_PER_EPWMSS1_CLKCTRL_OFFS);
    PRCM->cm_per_epwmss2 = (volatile uint32_t*)((uintptr_t)cm_per_base + CM_PER_EPWMSS2_CLKCTRL_OFFS);
    PRCM->cm_per_pru_icss_clkstctrl = (volatile uint32_t*)((uintptr_t)cm_per_base + CM_PER_PRU_ICSS_CLKCTRL_OFFS);

    report_log("PRCM cm_per_base = %p\n", PRCM->cm_per_base);
    report_log("PRCM cm_per_epwmss0 = %p\n", PRCM->cm_per_epwmss0);
    report_log("PRCM cm_per_epwmss1 = %p\n", PRCM->cm_per_epwmss1);
    report_log("PRCM cm_per_epwmss2 = %p\n", PRCM->cm_per_epwmss2);
    report_log("PRCM cm_per_pru_icss = %p\n", PRCM->cm_per_pru_icss_clkstctrl);

    return PRCM;

error_exit:
    if (PRCM)
        free(PRCM);

    return NULL;
}

int prcm_destroy(prcm_t *PRCM)
{
    if (!PRCM)
    {
        report_log("PRCM was null\n");
        return -1;
    }
        
    free(PRCM);

    return 0;
}

int prcm_start_all(prcm_t *PRCM)
{
    int rc = 0;

    rc = prcm_start_epwmss(PRCM);
    rc |= prcm_start_pru_icss(PRCM);

    return rc;
}

int prcm_start_epwmss(prcm_t *PRCM)
{
    int rc = 0;

    if ((*PRCM->cm_per_epwmss0 & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
        *PRCM->cm_per_epwmss0 = CM_PER_MODULE_MODE_ENABLE;

    if ((*PRCM->cm_per_epwmss1 & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
        *PRCM->cm_per_epwmss1 = CM_PER_MODULE_MODE_ENABLE;

    if ((*PRCM->cm_per_epwmss2 & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
        *PRCM->cm_per_epwmss2 = CM_PER_MODULE_MODE_ENABLE;

    if ((*PRCM->cm_per_epwmss0 & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
    {
        report_error("Fail to enable cm_per_epwmss0\n");
        rc = -1;
    }

    if ((*PRCM->cm_per_epwmss1 & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
    {
        report_error("Fail to enable cm_per_epwmss1\n");
        rc = -1;
    }

    if ((*PRCM->cm_per_epwmss2 & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
    {
        report_error("Fail to enable cm_per_epwmss2\n");
        rc = -1;
    }

    return rc;
}

int prcm_start_pru_icss(prcm_t *PRCM)
{
    int rc = 0;

    if ((*PRCM->cm_per_pru_icss_clkstctrl & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
        *PRCM->cm_per_pru_icss_clkstctrl = CM_PER_MODULE_MODE_ENABLE;

    if ((*PRCM->cm_per_pru_icss_clkstctrl & CM_PER_MODULE_MODE_MASK) != CM_PER_MODULE_MODE_ENABLE)
    {
        report_error("Fail to enable cm_per_pru_icss_clkstctrl\n");
        rc = -1;
    }

    return rc;
}

