#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
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

void epwm_debug(volatile epwm_t *EPWM)
{
    int i;
    uint16_t *EPWM_MEM = (uint16_t*)EPWM;

    printf("------------------------------------------------EPWM DBG-------------------------------------------------\n");
    printf("EPWM module base addr = %p\n", (void*)((uintptr_t)PWMSS2_BASE_ADDR + EPWM_OFFSET));
    printf("OFFS : REGISTER : VALUE\n");
    for (i = 0; i < EPWM_REG_COUNT; i++)
    {
        printf("%02X   :  %s : %04X\n", i*2, epwm_reg_name[i], EPWM_MEM[i]);
    }
    printf("&EPWM->TBCTL - 0x%X\n", (uint32_t)&EPWM->TBCTL);
    printf("&EPWM->CMPB - 0x%X\n", (uint32_t)&EPWM->CMPB);
    printf("&EPWM->PCCTL - 0x%X\n", (uint32_t)&EPWM->PCCTL);
    printf("EPWM_MEM - 0x%X\n", (uint32_t)&EPWM_MEM[i-1]);
    printf("EPWM - 0x%X\n", (uint32_t)EPWM);

    if (EPWM->TBCTL.FREE_SOFT != TB_FS_FREE)
        printf("EPWM->TBCTL.FREE_SOFT != TB_FS_FREE - 0x%X\n", EPWM->TBCTL.FREE_SOFT);

    if (EPWM->TBCTL.PHSDIR != TB_UP)
        printf("EPWM->TBCTL.PHSDIR != TB_UP - 0x%X\n", EPWM->TBCTL.PHSDIR);

    if (EPWM->TBCTL.CLKDIV != TB_DIV1)
        printf("EPWM->TBCTL.CLKDIV != TB_DIV1 - 0x%X\n", EPWM->TBCTL.CLKDIV);

    if (EPWM->TBCTL.HSPCLKDIV != TB_DIV1)
        printf("EPWM->TBCTL.HSPCLKDIV != TB_DIV1 - 0x%X\n", EPWM->TBCTL.HSPCLKDIV);

    //if (EPWM->TBCTL->SWFSYNC != 1)
    //    printf("EPWM->TBCTL->SWFSYNC != 1 - 0x%X\n", EPWM->TBCTL->SWFSYNC);

    if (EPWM->TBCTL.SYNCOSEL != TB_SYNC_DISABLE)
        printf("EPWM->TBCTL.SYNCOSEL != TB_SYNC_DISABLE - 0x%X\n", EPWM->TBCTL.SYNCOSEL);

    if (EPWM->TBCTL.PRDLD != TB_IMMEDIATE)
        printf("EPWM->TBCTL.PRDLD != TB_IMMEDIATE - 0x%X\n", EPWM->TBCTL.PRDLD);

    if (EPWM->TBCTL.PHSEN != TB_DISABLE)
        printf("EPWM->TBCTL.PHSEN != TB_DISABLE - 0x%X\n", EPWM->TBCTL.PHSEN);

    if (EPWM->TBCTL.CTRMODE != TB_COUNT_UP)
        printf("EPWM->TBCTL.CTRMODE != TB_COUNT_UP - 0x%X\n", EPWM->TBCTL.CTRMODE);

    if (EPWM->TBPRD != 125)
        printf("EPWM->TBPRD: %X\n", EPWM->TBPRD);
    if (EPWM->TBCNT != 0)
        printf("EPWM->TBCNT: %X\n", EPWM->TBCNT);
    if (EPWM->PCCTL.CHPEN != CHP_DISABLE)
        printf("EPWM->PCCTL.CHPEN: %X\n", EPWM->PCCTL.CHPEN);
    if (EPWM->CMPCTL.LOADBMODE != CC_CTR_ZERO)
        printf("EPWM->CMPCTL.LOADBMODE: %X\n", EPWM->CMPCTL.LOADBMODE);
    if (EPWM->AQCTLB.CBU != AQ_CLEAR)
        printf("EPWM->AQCTLB.CBU: %X\n", EPWM->AQCTLB.CBU);
    if (EPWM->AQCTLB.ZRO != AQ_SET)
        printf("EPWM->AQCTLB.ZRO: %X\n", EPWM->AQCTLB.ZRO);
    if (EPWM->AQCSFRC != 0)
        printf("EPWM->AQCSFRC: %X\n", EPWM->AQCSFRC);
    if (EPWM->ETPS.INTPRD != ET_1ST)
        printf("EPWM->ETPS.INTPRD: %X\n", EPWM->ETPS.INTPRD);
    if (EPWM->CMPB != 90)
        printf("EPWM->CMPB: %X\n", EPWM->CMPB);
    printf("---------------------------------------------------------------------------------------------------------\n");
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

volatile epwm_t* epwm_init(volatile pwmss_t *PWMSS)
{
    volatile epwm_t *EPWM;

    if (epwm_test_size() < 0)
        return NULL;

    // EPWM address is 0x200 after PWMSS
    EPWM = (volatile epwm_t*) ((uintptr_t)PWMSS + EPWM_OFFSET);
    report_log("EPWM mapped to address %p\n", EPWM);

    return EPWM;
}

int epwm_destroy(volatile epwm_t *EPWM)
{
    if (!EPWM)
    {
        report_log("EPWM was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}

int epwm_configure(volatile epwm_t *EPWM)
{
    bool timeout = false;
    int i;
    int x;
    int timeout_count = 0;
    uint16_t *epwm_etclr = (uint16_t*) ((uintptr_t)EPWM + 0x38);
    uint16_t *epwm_cmpb = (uint16_t*) ((uintptr_t)EPWM + 0x14);
    uint16_t *epwm_cmpctl = (uint16_t*) ((uintptr_t)EPWM + 0xE);
    uint16_t *epwm_tbcnt = (uint16_t*) ((uintptr_t)EPWM + 0x08);
    epwm_t shadow_epwm;
    memset(&shadow_epwm, 0, sizeof(shadow_epwm));

    report_log("epwm_etclr = %p\n", epwm_etclr);
    report_log("epwm_tbcnt = %p\n", epwm_tbcnt);
    if (!EPWM)
    {
        report_log("EPWM was null\n");
        return -1;
    }

    shadow_epwm.TBCTL.FREE_SOFT = TB_FS_STOP_COMPLETE; // free run mode
    shadow_epwm.TBCTL.PHSDIR = TB_UP;                 // phase direction count up
    shadow_epwm.TBCTL.CLKDIV = TB_DIV1;               // time base clock prescale divide clock by 1
    shadow_epwm.TBCTL.HSPCLKDIV = TB_DIV1;            // divide high speed time base clock by 1
    shadow_epwm.TBCTL.SWFSYNC = 1;                    // do not force software sync
    shadow_epwm.TBCTL.SYNCOSEL = TB_SYNC_DISABLE;     // disable EPWMxSYNCO signal
    shadow_epwm.TBCTL.PRDLD = TB_IMMEDIATE;           // do not load time-base period from shadow register
    shadow_epwm.TBCTL.PHSEN = TB_DISABLE;             // do not load time-base counter from time-base phase register 
    shadow_epwm.TBCTL.CTRMODE = TB_COUNT_UP;          // up count mode

    shadow_epwm.TBPRD = 125;                          // 1250ns
    shadow_epwm.TBCNT = 0;                            // reset timer B counter
    shadow_epwm.PCCTL.CHPEN = CHP_DISABLE;            // no phase chopping
    shadow_epwm.CMPCTL.LOADBMODE = CC_CTR_ZERO;       // load B when counter is 0
    //EPWM->CMPCTL.LOADBMODE = CC_CTR_PRD;        // load B when counter equals period
//  *ehr_cmpctl = EHRPWM_CMPCTL_LOADBMODE_P;

    shadow_epwm.AQCTLB.CBU = AQ_CLEAR;                // force low when B counter equals CMPB
    shadow_epwm.AQCTLB.ZRO = AQ_SET;                  // force high when B counter equals 0
//  *ehr_aqctlb = EHRPWM_AQCTLB_CBU_FORCE_LOW | EHRPWM_AQCTLB_ZRO_FORCE_HIGH; // force high at 0 / force low after B

    shadow_epwm.AQCSFRC = 0;                          // do not force pwm AQC
//  *ehr_aqcsfrc = EHRPWM_AQCSFRC_CSFB_N;

    shadow_epwm.ETPS.INTPRD = ET_1ST;                 // generate interrupt on first event
//  *flag_etps = EHRPWM_ETPS_1_EVENT;           // event count

    shadow_epwm.CMPB = 0;
    memcpy((void*)EPWM, &shadow_epwm, sizeof(epwm_t));

    for (i = 0; i < 50; i++)
    {
        *epwm_etclr = 0x1;                          // clear events
        *epwm_cmpb = 90;                            // set comparison B duty cycle to 90

//            *ehr_cmpb = 90;
        // delay until shadow buffer is empty
        while ((*epwm_cmpctl & BIT(9)) && !timeout)
        {
            for (x = 0; x <= 50; x++)
            {
                if (x >= 50)
                {
                    timeout = true;
                    timeout_count += 1;
                }
            }
        }

        report_log("tbcnt = %u\n", *epwm_tbcnt);
        timeout = false;
    }

    report_log("timeout_count = %d\n", timeout_count);
    
    printf("------------------------------------------------SHADOW DBG-------------------------------------------------\n");
    epwm_debug(&shadow_epwm);
//  *flag_etclr = EHRPWM_ETCLR_CLEAR;
    return 0;
}

//  *flag_etps = 0; // event count
//  *flag_etsel = EHRPWM_ETSEL_INTEN | EHRPWM_ETSEL_INTSEL_PRD;  // interrupt selection
//  *ehr_pcctl = 0; // not using pcctl
//
//
//  *ehr_cmpb = 0;
//
//  // PWM force high at timer equal 0 / force low after timer equal to CMPB
//  
//  // initialize to write finished
//  shared_mem[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 0;
//
//  // disable force pwm low
//  *ehr_tbphs = 0;
//
//  while (1)
//  {
//    // load next value if shadow buffer is empty
//    if (shared_mem[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] > 0)
//    {
//      // read # leds from shared memory
//      led_count = shared_mem[SHARED_MEM_LED_COUNT_OFFSET]; 
//
//      *flag_etclr = EHRPWM_ETCLR_CLEAR;
//
//      // delay until shadow buffer is empty
//      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
//        ; 
//
//      // loop over LEDs
//      for (led_num = 0; led_num < led_count; led_num++)
//      {
//        // loop over color bits for current LED
//        for (bit_num = 0; bit_num < WS2812_LED_BIT_COUNT; bit_num++)
//        {
//          // get current color bit
//          if (shared_mem[SHARED_MEM_LED_START_OFFSET + led_num] & (1 << bit_num))
//          {
//            // ws2812 duty cycle to set bit to 1
//            *ehr_cmpb = 90;
//          }
//          else
//          {
//            // ws2812 duty cycle to set bit to 0
//            *ehr_cmpb = 35;
//          }
//
//          // delay until shadow buffer is empty
//          while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
//              ; 
//        }
//      }
//      
//      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
//        ; 
//      *ehr_cmpb = 0;
//
