#include "debug.h"
#include "pwm_subsystem.h"

static const char *pwmss_reg_name[] = 
{
    "IDVER    ",         // 0x00
    "SYSCONFIG",         // 0x04
    "CLKCONFIG",         // 0x08
    "CLKSTATUS",         // 0x0C
};
#define PWMSS_REG_COUNT sizeof(pwmss_reg_name)/sizeof(pwmss_reg_name[0])

void pwmss_debug(volatile pwmss_t *PWMSS)
{
    int i;
    uint32_t *PWMSS_MEM = (uint32_t*) PWMSS;

    printf("------------------------------------------------PWMSS DBG------------------------------------------------\n");
    printf("PWMSS module base addr = %p\n", PWMSS2_BASE_ADDR);
    for (i = 0; i < PWMSS_REG_COUNT; i++)
    {
        printf("%s: %08X\n", pwmss_reg_name[i], PWMSS_MEM[i]);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}

int pwmss_test_size()
{
    if (sizeof(pwmss_t) != PWMSS_REGISTER_SIZE)
    {
        report_error("sizeof pwmss_t = %zu (expected %d)\n", sizeof(pwmss_t), PWMSS_REGISTER_SIZE);
        return -1;
    }

    return 0;
}

volatile pwmss_t* pwmss_init(mem_mgr_t *mem_mgr)
{
    volatile pwmss_t *PWMSS;
    void *target_addr = PWMSS2_BASE_ADDR;

    if (pwmss_test_size() < 0)
        return NULL;

    PWMSS = (volatile pwmss_t*) mem_mgr_get_map(mem_mgr, target_addr);
    report_log("PWMSS mapped to address %p\n", PWMSS);

    return PWMSS;
}

int pwmss_destroy(volatile pwmss_t *PWMSS)
{
    if (!PWMSS)
    {
        report_log("PWMSS was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}

int pwmss_configure(volatile pwmss_t *PWMSS)
{
    if (!PWMSS)
    {
        report_log("PWMSS was null\n");
        return -1;
    }

    // smart idle/standby, no reset, ignore emulation
    PWMSS->SYSCONFIG.STANDBYMODE = CFG_SMART;
    PWMSS->SYSCONFIG.IDLEMODE = CFG_SMART;
    PWMSS->SYSCONFIG.FREEMU = CFG_NOSUS;
    PWMSS->SYSCONFIG.SOFTRESET = 0;

    // ePWM only
    PWMSS->CLKCONFIG.eCAPCLK_EN = CL_DISABLE;
    PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ = CL_STOP_REQ;
    PWMSS->CLKCONFIG.eQEPCLK_EN = CL_DISABLE;
    PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ = CL_STOP_REQ;
    PWMSS->CLKCONFIG.ePWMCLK_EN = CL_ENABLE;
    PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ = CL_START_REQ;

    // sysconfig
    if (PWMSS->SYSCONFIG.STANDBYMODE != CFG_SMART)
        printf("PWMSS->SYSCONFIG.STANDBYMODE: %X\n",PWMSS->SYSCONFIG.STANDBYMODE);
    if (PWMSS->SYSCONFIG.IDLEMODE != CFG_SMART)
        printf("PWMSS->SYSCONFIG.IDLEMODE: %X\n",PWMSS->SYSCONFIG.IDLEMODE);
    if (PWMSS->SYSCONFIG.FREEMU != CFG_NOSUS)
        printf("PWMSS->SYSCONFIG.FREEMU: %X\n",PWMSS->SYSCONFIG.FREEMU);
    if (PWMSS->SYSCONFIG.SOFTRESET != 0)
        printf("PWMSS->SYSCONFIG.SOFTRESET: %X\n",PWMSS->SYSCONFIG.SOFTRESET);

    // clkconfig
    if (PWMSS->CLKCONFIG.eCAPCLK_EN != CL_DISABLE)
        printf("PWMSS->CLKCONFIG.eCAPCLK_EN: %X\n",PWMSS->CLKCONFIG.eCAPCLK_EN);
    if (PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ != CL_STOP_REQ)
        printf("PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ: %X\n",PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ);
    if (PWMSS->CLKCONFIG.eQEPCLK_EN != CL_DISABLE)
        printf("PWMSS->CLKCONFIG.eQEPCLK_EN: %X\n",PWMSS->CLKCONFIG.eQEPCLK_EN);
    if (PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ != CL_STOP_REQ)
        printf("PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ: %X\n",PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ);
    if (PWMSS->CLKCONFIG.ePWMCLK_EN != CL_ENABLE)
        printf("PWMSS->CLKCONFIG.ePWMCLK_EN: %X\n",PWMSS->CLKCONFIG.ePWMCLK_EN);
    if (PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ != CL_START_REQ)
        printf("PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ: %X\n",PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ);

    return 0;
}

