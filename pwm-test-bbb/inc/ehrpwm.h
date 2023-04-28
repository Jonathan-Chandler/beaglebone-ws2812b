#ifndef _EHRPWM2_H_
#define _EHRPWM2_H_

#define EHRPWM2_BASE 0x48304200

#define EHRPWM_ETSEL_OFFSET 0x32
#define EHRPWM_ETSEL_INTEN  0x8
#define EHRPWM_ETSEL_INTSEL_MASK 0x7
#define EHRPWM_ETSEL_INTSEL_ZERO 0x1
#define EHRPWM_ETSEL_INTSEL_PRD  0x2

#define EHRPWM_ETPS_OFFSET  0x34
#define EHRPWM_ETPS_INTPRD_MASK 0x3
#define EHRPWM_ETPS_1_EVENT 0x1
#define EHRPWM_ETPS_2_EVENTS 0x2
#define EHRPWM_ETPS_3_EVENTS 0x3

#define EHRPWM_ETFLG_OFFSET 0x36
#define EHRPWM_ETFLG_SET    0x1

#define EHRPWM_ETCLR_OFFSET 0x38
#define EHRPWM_ETCLR_CLEAR  0x1

#define EHRPWM_CMPB_OFFSET      0x14
#define EHRPWM_CMPB_MASK        0xFFFF

#define EHRPWM_PCCTL_OFFSET     0x3C
#define EHRPWM_PCCTL_DUTY_MASK (0x7 << 8)
#define EHRPWM_PCCTL_DUTY_25   (0x1 << 8)
#define EHRPWM_PCCTL_DUTY_75   (0x5 << 8)
#define EHRPWM_PCCTL_FREQ_MASK (0x7 << 5)
#define EHRPWM_PCCTL_CHP_EN    0x1

#define EHRPWM_TBPRD_OFFSET 0xA
  // sets pwm frequency
//             - shadowed with TBCTL[PRDLD] == 0
#define EHRPWM_TBPRD_MASK   0xFFFF

#define EHRPWM_AQCTLB_OFFSET 0x18
#define EHRPWM_AQCTLB_CBU_FORCE_LOW (0x1 << 8)    // incrementing and equals B
#define EHRPWM_AQCTLB_CBU_FORCE_HIGH (0x2 << 8)
#define EHRPWM_AQCTLB_PRD_FORCE_LOW (0x1 << 2)
#define EHRPWM_AQCTLB_PRD_FORCE_HIGH (0x2 << 2)
#define EHRPWM_AQCTLB_ZRO_FORCE_LOW (0x1)
#define EHRPWM_AQCTLB_ZRO_FORCE_HIGH (0x2)

#define EHRPWM_CMPCTL_OFFSET        0xE
#define EHRPWM_CMPCTL_SHDWBFULL     (0x1 << 9) // shadow buffer B is full
#define EHRPWM_CMPCTL_SHDWBMODE_DIS (0x1 << 6) // disable shadow buffer for pwm B
#define EHRPWM_CMPCTL_LOADBMODE_Z   (0x0 << 2) // load when time base equal to zero
#define EHRPWM_CMPCTL_LOADBMODE_P   (0x1 << 2) // load when time base equal to period
#define EHRPWM_CMPCTL_LOADBMODE_A   (0x2 << 2) // load when time base equal to period or zero
#define EHRPWM_CMPCTL_LOADBMODE_F   (0x3 << 2) // freeze


#define EHRPWM_AQSFRC_OFFSET        0x1A
#define EHRPWM_AQSFRC_OTSFB         (0x1 << 5) // one-time software force B
#define EHRPWM_AQSFRC_ACTSFB_C      (0x1 << 3) // one-time event - clear
#define EHRPWM_AQSFRC_ACTSFB_S      (0x2 << 3) // one-time event - set


#define EHRPWM_AQCSFRC_OFFSET       0x1C
#define EHRPWM_AQCSFRC_CSFB_N       (0x0 << 2)  // do not force pwm
#define EHRPWM_AQCSFRC_CSFB_L       (0x1 << 2)  // force PWM B low
#define EHRPWM_AQCSFRC_CSFB_H       (0x2 << 2)  // force PWM B high
#define EHRPWM_RLDCSF_LOAD_Z        (0x0 << 6)  // load shadow register when counter equals zero
#define EHRPWM_RLDCSF_LOAD_P        (0x1 << 6)  // load shadow register when counter equals period
#define EHRPWM_RLDCSF_CSFB_H        (0x2 << 6)  // load shadow register when counter equals either zero or period

#define EHRPWM_TBPHS_OFFSET         0x6

#endif
