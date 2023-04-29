#include <stdint.h>
#include <stdio.h>
#include "util.h"
#include "epwm.h"

void dump_epwm(epwm_t *EPWM);

#define BIT_MASK(a, b) ((a < b) ? \
        (((unsigned) -1 >> (31 - (b))) & ~((1U << (a)) - 1)) : (((unsigned) -1 >> (31 - (a))) & ~((1U << (b)) - 1)))

int main(void)
{
    tbctl_t tbctl;
    epwm_t EPWM;

    EPWM.TBCTL.FREE_SOFT = 0x3;              // free run
    EPWM.TBCTL.PHSDIR = TB_UP;               // count up after sync
    EPWM.TBCTL.CLKDIV = TB_DIV1;             // CLKDIV=1 (TBCLK=SYSCLKOUT/(HSPCLKDIV*CLKDIV))
    EPWM.TBCTL.HSPCLKDIV = TB_DIV1;          // HSPCLKDIV=1 (TBCLK=SYSCLKOUT/(HSPCLKDIV*CLKDIV))
    EPWM.TBCTL.SWFSYNC = 0;                  // force software sync pulse (valid if SYNCOSEL=TB_SYNC_IN)
    EPWM.TBCTL.SYNCOSEL = TB_SYNC_DISABLE;   // disable EPWMxSYNCO synchronize signal
    EPWM.TBCTL.PRDLD = TB_SHADOW;            // load from shadow register when TBCNT = 0
    EPWM.TBCTL.PHSEN = TB_DISABLE;           // do not load time base counter from phase register (TBPHS)
    EPWM.TBCTL.CTRMODE = TB_COUNT_UP;        // timer counts up only

    printf("FREE_SOFT = %X\n", EPWM.TBCTL.FREE_SOFT);

    if (sizeof(tbctl) != 2)
    {
        printf("Error - size tbctl != 2\n");
    }

    if (sizeof(epwm_t) != EPWM_REGISTER_SIZE)
    {
        printf("Error - size epwm_t = %zu (expected %d)\n", sizeof(epwm_t), EPWM_REGISTER_SIZE);
    }
    printf("size epwm_t = %zu (expected %d)\n", sizeof(epwm_t), EPWM_REGISTER_SIZE);

    dump_epwm(&EPWM);

    return 0;
}

char *epwm_reg_name[] = 
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
    "HRCNFG ",           // 0xC0
};
#define EPWM_REG_COUNT sizeof(epwm_reg_name)/sizeof(epwm_reg_name[0])

void dump_epwm(epwm_t *EPWM)
{
    int i;
    uint16_t *EPWM_MEM = (uint16_t*) EPWM;

    printf("\n------------------------EPWM DUMP------------------------\n");
    for (i = 0; i < EPWM_REG_COUNT; i++)
    {
        printf("%s: %04X\n", epwm_reg_name[i], EPWM_MEM[i]);
    }
    printf("---------------------------------------------------------\n");
}
