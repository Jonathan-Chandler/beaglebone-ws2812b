#include "debug.h"
#include "enhanced_pwm.h"
#include "memory_manager.h"

static const char *epwm_reg_name[] = 
{
    "TBCTL  ",           // 0x00
    "TBSTS  ",           // 0x02
    "TBPHSHR",           // 0x04
    "TBPHS  ",           // 0x06
    "TBCNT  ",           // 0x08
    "TBPRD  ",           // 0x0A
    "FILL0  ",           // 0x0C
    "CMPCTL ",           // 0x0E
    "CMPAHR ",           // 0x10
    "CMPA   ",           // 0x12
    "CMPB   ",           // 0x14
    "AQCTLA ",           // 0x16
    "AQCTLB ",           // 0x18
    "AQSFRC ",           // 0x1A
    "AQCSFRC",           // 0x1C
    "DBCTL  ",           // 0x1E
    "DBRED  ",           // 0x20
    "DBFED  ",           // 0x22
    "TZSEL  ",           // 0x24
    "FILL1  ",           // 0x26
    "TZCTL  ",           // 0x28
    "TZEINT ",           // 0x2A
    "TZFLG  ",           // 0x2C
    "TZCLR  ",           // 0x2E
    "TZFRC  ",           // 0x30
    "ETSEL  ",           // 0x32
    "ETPS   ",           // 0x34
    "ETFLG  ",           // 0x36
    "ETCLR  ",           // 0x38
    "ETFRC  ",           // 0x3A
    "PCCTL  ",           // 0x3C
    //"HRCNFG ",         // 0xC0
};
#define EPWM_REG_COUNT sizeof(epwm_reg_name)/sizeof(epwm_reg_name[0])

void epwm_debug(epwm_t *EPWM)
{
    int i;
    uint16_t *EPWM_MEM = (uint16_t*) EPWM;

    printf("\n------------------------EPWM DBG-------------------------\n");
    for (i = 0; i < EPWM_REG_COUNT; i++)
    {
        printf("%s: %04X\n", epwm_reg_name[i], EPWM_MEM[i]);
    }
    printf("---------------------------------------------------------\n");
}

int epwm_test_size()
{
    if (sizeof(epwm_t) != EPWM_REGISTER_SIZE)
    {
        report_error("sizeof epwm_t = %zu (expected %d)\n", sizeof(epwm_t), EPWM_REGISTER_SIZE);
        return -1;
    }

    return 0;
}

epwm_t* epwm_init(pwmss_t *PWMSS)
{
    epwm_t *EPWM;

    if (epwm_test_size() < 0)
        return NULL;

    // EPWM address is 0x200 after PWMSS
    EPWM = (epwm_t*) ((uintptr_t)PWMSS + EPWM_OFFSET);
    report_log("EPWM mapped to address %p\n", EPWM);

    return EPWM;
}

int epwm_destroy(epwm_t *EPWM)
{
    if (!EPWM)
    {
        report_log("EPWM was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}
