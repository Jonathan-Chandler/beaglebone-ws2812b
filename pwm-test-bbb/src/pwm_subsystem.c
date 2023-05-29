#include "debug.h"
#include "pwm_subsystem.h"

#if DEBUG_PRINT_REG
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
    unsigned int i;
    uint32_t *PWMSS_MEM = (uint32_t*) PWMSS;

    printf("------------------------------------------------PWMSS DBG------------------------------------------------\n");
    printf("PWMSS module base addr = %p\n", PWMSS2_BASE_ADDR);
    for (i = 0; i < PWMSS_REG_COUNT; i++)
    {
        printf("%s: %08X\n", pwmss_reg_name[i], PWMSS_MEM[i]);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}
#endif // if DEBUG_PRINT_REG

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
    PWMSS->SYSCONFIG.IDLEMODE = CFG_SMART;
    PWMSS->SYSCONFIG.FREEMU = CFG_SUS;
    PWMSS->SYSCONFIG.SOFTRESET = 0;

    // ePWM only
    PWMSS->CLKCONFIG.eCAPCLK_EN = CL_DISABLE;
    PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ = CL_STOP_REQ;
    PWMSS->CLKCONFIG.eQEPCLK_EN = CL_DISABLE;
    PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ = CL_STOP_REQ;
    PWMSS->CLKCONFIG.ePWMCLK_EN = CL_ENABLE;
    PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ = CL_START_REQ;

    // sysconfig
    if (PWMSS->SYSCONFIG.IDLEMODE != CFG_SMART)
        report_error("PWMSS->SYSCONFIG.IDLEMODE: %X\n",PWMSS->SYSCONFIG.IDLEMODE);
    if (PWMSS->SYSCONFIG.FREEMU != CFG_SUS)
        report_error("PWMSS->SYSCONFIG.FREEMU: %X\n",PWMSS->SYSCONFIG.FREEMU);
    if (PWMSS->SYSCONFIG.SOFTRESET != 0)
        report_error("PWMSS->SYSCONFIG.SOFTRESET: %X\n",PWMSS->SYSCONFIG.SOFTRESET);

    // clkconfig
    if (PWMSS->CLKCONFIG.eCAPCLK_EN != CL_DISABLE)
        report_error("PWMSS->CLKCONFIG.eCAPCLK_EN: %X\n",PWMSS->CLKCONFIG.eCAPCLK_EN);
    if (PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ != CL_STOP_REQ)
        report_error("PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ: %X\n",PWMSS->CLKCONFIG.eCAPCLKSTOP_REQ);
    if (PWMSS->CLKCONFIG.eQEPCLK_EN != CL_DISABLE)
        report_error("PWMSS->CLKCONFIG.eQEPCLK_EN: %X\n",PWMSS->CLKCONFIG.eQEPCLK_EN);
    if (PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ != CL_STOP_REQ)
        report_error("PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ: %X\n",PWMSS->CLKCONFIG.eQEPCLKSTOP_REQ);
    if (PWMSS->CLKCONFIG.ePWMCLK_EN != CL_ENABLE)
        report_error("PWMSS->CLKCONFIG.ePWMCLK_EN: %X\n",PWMSS->CLKCONFIG.ePWMCLK_EN);
    if (PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ != CL_START_REQ)
        report_error("PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ: %X\n",PWMSS->CLKCONFIG.ePWMCLKSTOP_REQ);

    return 0;
}

