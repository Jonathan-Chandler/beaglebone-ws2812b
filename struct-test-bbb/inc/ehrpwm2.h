#ifndef __EHRPWM_2_H__
#define __EHRPWM_2_H__
#include <stdint.h>

// TBCTL (Time-Base Control) - 0x0
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(2)))
{
    uint16_t PHSDIR:1;
    uint16_t CLKDIV:3;
    uint16_t HSPCLKDIV:3;
    uint16_t SWFSYNC:1;
    uint16_t SYNCOSEL:2;
    uint16_t PRDLD:1;
    uint16_t PHSEN:1;
    uint16_t CTRMODE:2;
    uint16_t FREE_SOFT:2; 
} tbctl_t;

// TBCNT MODE bits
#define TB_COUNT_UP 0x0
#define TB_COUNT_DOWN 0x1
#define TB_COUNT_UPDOWN 0x2
#define TB_FREEZE 0x3
// PHSEN bit
#define TB_DISABLE 0x0
#define TB_ENABLE 0x1
// PRDLD bit
#define TB_SHADOW 0x0
#define TB_IMMEDIATE 0x1
// SYNCOSEL bits
#define TB_SYNC_IN 0x0
#define TB_CTR_ZERO 0x1
#define TB_CTR_CMPB 0x2
#define TB_SYNC_DISABLE 0x3
// HSPCLKDIV and CLKDIV bits
#define TB_DIV1 0x0
#define TB_DIV2 0x1
#define TB_DIV4 0x2
// PHSDIR bit
#define TB_DOWN 0x0
#define TB_UP 0x1

// CMPCTL (Compare Control) - 0xE
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(2)))
{
} cmpctl_t;

// LOADAMODE and LOADBMODE bits
#define CC_CTR_ZERO 0x0
#define CC_CTR_PRD 0x1
#define CC_CTR_ZERO_PRD 0x2
#define CC_LD_DISABLE 0x3
// SHDWAMODE and SHDWBMODE bits

#define CC_SHADOW 0x0
#define CC_IMMEDIATE 0x1
// AQCTLA and AQCTLB (Action-qualifier Control)
// = = = = = = = = = = = = = = = = = = = = = = = = = =
// ZRO, PRD, CAU, CAD, CBU, CBD bits
#define AQ_NO_ACTION 0x0
#define AQ_CLEAR 0x1
#define AQ_SET 0x2
#define AQ_TOGGLE 0x3
// DBCTL (Dead-Band Control)
// = = = = = = = = = = = = = = = = = = = = = = = = = =
// MODE bits
#define DB_DISABLE 0x0
#define DBA_ENABLE 0x1
#define DBB_ENABLE 0x2
#define DB_FULL_ENABLE 0x3
// POLSEL bits
#define DB_ACTV_HI 0x0
#define DB_ACTV_LOC 0x1
#define DB_ACTV_HIC 0x2
#define DB_ACTV_LO 0x3
// PCCTL (chopper control)
// = = = = = = = = = = = = = = = = = = = = = = = = = =
// CHPEN bit
#define CHP_ENABLE 0x0
#define CHP_DISABLE 0x1
// CHPFREQ bits
#define CHP_DIV1 0x0
#define CHP_DIV2 0x1
#define CHP_DIV3 0x2
#define CHP_DIV4 0x3
#define CHP_DIV5 0x4
#define CHP_DIV6 0x5
#define CHP_DIV7 0x6
#define CHP_DIV8 0x7
// CHPDUTY bits
#define CHP1_8TH 0x0
#define CHP2_8TH 0x1
#define CHP3_8TH 0x2
#define CHP4_8TH 0x3
#define CHP5_8TH 0x4
#define CHP6_8TH 0x5
#define CHP7_8TH 0x6

// TZSEL (Trip-zone Select)
// = = = = = = = = = = = = = = = = = = = = = = = = = =
// CBCn and OSHTn bits
#define TZ_ENABLE 0x0
#define TZ_DISABLE 0x1

// TZCTL (Trip-zone Control)
// = = = = = = = = = = = = = = = = = = = = = = = = = =
// TZA and TZB bits
#define TZ_HIZ 0x0
#define TZ_FORCE_HI 0x1
#define TZ_FORCE_LO 0x2
#define TZ_DO_NOTHING 0x3

// ETSEL (Event-trigger Select)
// = = = = = = = = = = = = = = = = = = = = = = = = = =
// INTSEL, SOCASEL, SOCBSEL bits
#define ET_CTR_ZERO 0x1
#define ET_CTR_PRD 0x2
#define ET_CTRU_CMPA 0x4
#define ET_CTRD_CMPA 0x5
#define ET_CTRU_CMPB 0x6
#define ET_CTRD_CMPB 0x7

// ETPS (Event-trigger Prescale)
// = = = = = = = = = = = = = = = = = = = = = = = = = =
// INTPRD, SOCAPRD, SOCBPRD bits
#define ET_DISABLE 0x0
#define ET_1ST 0x1
#define ET_2ND 0x2
#define ET_3RD 0x3

typedef struct __attribute__((packed, aligned(2)))
{
    tbctl_t TBCTL;              // 0x00
    uint16_t TBSTS;             // 0x02
    uint16_t TBPHSHR;           // 0x04
    uint16_t TBPHS;             // 0x06
    uint16_t TBCNT;             // 0x08
    uint16_t TBPRD;             // 0x0A
    uint16_t FILL0;             // 0x0C
    uint16_t CMPCTL;            // 0x0E
    uint16_t CMPAHR;            // 0x10
    uint16_t CMPA;              // 0x12
    uint16_t CMPB;              // 0x14
    uint16_t AQCTLA;            // 0x16
    uint16_t AQCTLB;            // 0x18
    uint16_t AQSFRC;            // 0x1A
    uint16_t AQCSFRC;           // 0x1C
    uint16_t DBCTL;             // 0x1E
    uint16_t DBRED;             // 0x20
    uint16_t DBFED;             // 0x22
    uint16_t TZSEL;             // 0x24
    uint16_t FILL1;             // 0x26
    uint16_t TZCTL;             // 0x28
    uint16_t TZEINT;            // 0x2A
    uint16_t TZFLG;             // 0x2C
    uint16_t TZCLR;             // 0x2E
    uint16_t TZFRC;             // 0x30
    uint16_t ETSEL;             // 0x32
    uint16_t ETPS;              // 0x34
    //uint16_t ETFLG;           // 0x36
    //uint16_t ETCLR;           // 0x38
    //uint16_t ETFRC;           // 0x3A
    //uint16_t PCCTL;           // 0x3C
    //uint16_t HRCNFG;          // 0xC0
} epwm_t;
#define EPWM_REGISTER_SIZE 0x36

#endif
