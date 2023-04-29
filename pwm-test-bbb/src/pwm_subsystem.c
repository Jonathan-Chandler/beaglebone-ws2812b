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

void pwmss_debug(pwmss_t *PWMSS)
{
    int i;
    uint32_t *PWMSS_MEM = (uint32_t*) PWMSS;

    printf("\n------------------------PWMSS DBG------------------------\n");
    for (i = 0; i < PWMSS_REG_COUNT; i++)
    {
        printf("%s: %08X\n", pwmss_reg_name[i], PWMSS_MEM[i]);
    }
    printf("---------------------------------------------------------\n");
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

pwmss_t* pwmss_init(mem_mgr_t *mem_mgr)
{
    pwmss_t *PWMSS;
    void *target_addr = PWMSS2_BASE_ADDR;

    if (pwmss_test_size() < 0)
        return NULL;

    PWMSS = (pwmss_t*) mem_mgr_get_map(mem_mgr, target_addr);
    report_log("PWMSS mapped to address %p\n", PWMSS);

    return PWMSS;
}

int pwmss_destroy(pwmss_t *PWMSS)
{
    if (!PWMSS)
    {
        report_log("PWMSS was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}
