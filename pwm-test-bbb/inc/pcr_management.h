#ifndef __PRCM_H__
#define __PRCM_H__
// Power, Reset, and Clock Management
#define CM_PER_BASE    0x44E00000           // Clock Module Peripheral Registers
#define CM_WKUP_BASE   0x44E00400           // Clock Module Wakeup Registers
#define CM_DEVICE_BASE 0x44E00700           // Clock Module Device Registers

#define PRM_IRQ_BASE   0x44E00B00           // Power Reset Module IRQ Registers
#define PRM_PER_BASE   0x44E00C00           // Power Reset Module Peripheral Registers
#define PRM_WKUP_BASE  0x44E00D00           // Power Reset Module Wakeup Registers
#define PRM_MPU_BASE   0x44E00E00           // Power Reset Module MPU Registers
#define PRM_DEV_BASE   0x44E00F00           // Power Reset Module Device Registers

#endif

