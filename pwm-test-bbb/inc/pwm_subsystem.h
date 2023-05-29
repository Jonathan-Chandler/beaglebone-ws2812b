#ifndef __PWMSS_H__
#define __PWMSS_H__
// Pulse-Width Modulation Subsystem

#include "share.h"
#include "util.h"
#include "memory_manager.h"

#define PWMSS0_BASE_ADDR                    (void*)0x48300000
#define PWMSS1_BASE_ADDR                    (void*)0x48302000
#define PWMSS2_BASE_ADDR                    (void*)0x48304000
#define PWMSS_OFFSET                        (uintptr_t)0x0

#define PWMSS_SYSCONFIG_OFFS  				0x4
#define PWMSS_SYSCONFIG_STANDBY_OFFS		4
#define PWMSS_SYSCONFIG_STANDBY_MASK		BIT_MASK(5,4)
#define PWMSS_SYSCONFIG_STANDBY_NONE		(0x1 << PWMSS_SYSCONFIG_STANDBY_OFFS)
#define PWMSS_SYSCONFIG_STANDBY_SMART		(0x2 << PWMSS_SYSCONFIG_STANDBY_OFFS)
#define PWMSS_SYSCONFIG_IDLE_OFFS			2
#define PWMSS_SYSCONFIG_IDLE_MASK			BIT_MASK(3,2)
#define PWMSS_SYSCONFIG_IDLE_NONE			(0x1 << PWMSS_SYSCONFIG_IDLE_OFFS)
#define PWMSS_SYSCONFIG_IDLE_SMART			(0x2 << PWMSS_SYSCONFIG_IDLE_OFFS)

#define PWMSS_CLKCONFIG_OFFS  				0x8
#define PWMSS_CLKCONFIG_EPWM_STOP     		BIT(9)
#define PWMSS_CLKCONFIG_EPWM_START    		0
#define PWMSS_CLKCONFIG_EPWM_EN  			BIT(8)
#define PWMSS_CLKCONFIG_EPWM_DIS 			0

#define PWMSS_CLKSTATUS_OFFS  				0xC
#define PWMSS_CLKSTATUS_EPWM_STOP     		BIT(9)
#define PWMSS_CLKSTATUS_EPWM_EN  			BIT(8)

// SYSCONFIG - 0x4
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t SOFTRESET:1;       // 0
    uint32_t FREEMU:1;          // 1  
    uint32_t IDLEMODE:2;        // 3-2
    uint32_t STANDBYMODE:2;     // 5-4
    uint32_t RESERVED:26;       // 31-6
} sysconfig_t;

// STANDBYMODE/IDLEMODE bits
#define CFG_FORCE 0x0
#define CFG_NONE  0x1
#define CFG_SMART 0x2
// FREEMU bit
#define CFG_SUS   0x0
#define CFG_NOSUS 0x1

// CLKCONFIG - 0x8
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t eCAPCLK_EN:1;      // 0
    uint32_t eCAPCLKSTOP_REQ:1; // 1
    uint32_t RESERVED3:2;       // 3-2
    uint32_t eQEPCLK_EN:1;      // 4
    uint32_t eQEPCLKSTOP_REQ:1; // 5
    uint32_t RESERVED2:2;       // 7-6
    uint32_t ePWMCLK_EN:1;      // 8
    uint32_t ePWMCLKSTOP_REQ:1; // 9
    uint32_t RESERVED:22;       // 31-10
} clkconfig_t;

// CLKSTOP bits
#define CL_STOP_REQ     0x1
#define CL_START_REQ    0x0
// CLK_EN bits
#define CL_ENABLE       0x1
#define CL_DISABLE      0x0

// CLKSTATUS - 0xC
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t eCAPCLK_EN_ACK:1;  // 0
    uint32_t eCAPCLKSTOP_REQ:1; // 1
    uint32_t RESERVED3:2;       // 3-2
    uint32_t eQEPCLK_EN_ACK:1;  // 4
    uint32_t eQEPCLKSTOP_REQ:1; // 5
    uint32_t RESERVED2:2;       // 7-6
    uint32_t ePWMCLK_EN_ACK:1;  // 8
    uint32_t ePWMCLKSTOP_ACK:1; // 9
    uint32_t RESERVED:22;       // 31-10
} clkstatus_t;

// CLKSTOP_ACK bits
#define CL_STOP_ACK     0x1
#define CL_START_ACK    0x0
// CLK_EN_ACK bits
#define CL_ENABLE_ACK   0x1
#define CL_DISABLE_ACK  0x0

// PWMSS struct
// = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __attribute__((packed, aligned(4)))
{
    uint32_t    IDVER;             // 0x00
    sysconfig_t SYSCONFIG;         // 0x04
    clkconfig_t CLKCONFIG;         // 0x08
    clkstatus_t CLKSTATUS;         // 0x0C
} pwmss_t;
#define PWMSS_REGISTER_SIZE 0x10

int      pwmss_test_size();

volatile pwmss_t* pwmss_init(mem_mgr_t *mem_mgr);
int      pwmss_destroy(volatile pwmss_t *PWMSS);

int      pwmss_configure(volatile pwmss_t *PWMSS);

#if DEBUG_PRINT_REG
void     pwmss_debug(volatile pwmss_t *PWMSS);
#endif

#endif
