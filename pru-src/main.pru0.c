// Programmable Real-time Unit Industrial Control SubSystem (PRU-ICSS) 
// /home/jonathan/beaglebone-compile/pru/bin/clpru
// #include <stdint.h>

// /sys/devices/platform/ocp/4a326004.pruss-soc-bus/4a300000.pruss/
// "P8_27 P8_28 P8_29 P8_30 P8_39 P8_40 P8_41 P8_42"
//
// /sys/devices/platform/ocp/ocp\:P9_27_pinmux/subsystem/devices/44e07000.gpio/driver/481ae000.gpio/gpiochip3/gpio/gpio105/value
// /sys/devices/platform/ocp/ocp\:P9_27_pinmux/
// echo 105 > ./sys/class/gpio/export
// echo out > /sys/devices/platform/ocp/ocp\:P9_27_pinmux/subsystem/devices/44e07000.gpio/driver/481ae000.gpio/gpiochip3/gpio/gpio105/direction
// echo 1 > /sys/class/gpio/gpio105/value
//
// P9_27_pinmux - pin 105 - pru 31_5
//    echo $pin
//    config-pin $pin pruout
//    config-pin -q $pin

// LDI32     r0, 0x00022000
// LBBO      &r1, r0, 0, 4

#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"
#include "share.h"
#include "prugpio.h"

volatile register unsigned int __R30;
volatile register unsigned int __R31;

void main(void) 
{
  uint32_t  bit_num = 0;
  uint32_t  led_num = 0;
  uint32_t  led_count = 0;
  uint32_t  *gpio1 = (uint32_t *)GPIO1;
  uint32_t  *shared_mem = (uint32_t *)AM33XX_PRUSS_SHAREDRAM_BASE;
  uint32_t delay_cycles = 0;
  // AM33XX_PRUSS_SHAREDRAM_BASE = 0x4a310000
  // local/global shared data 12K Ram 2: 0x10000
  // PRU_SHAREDMEM   : org = 0x00010000 len = 0x00003000 CREGISTER=28 /* 12kB Shared RAM */

  /* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
  CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

  // config-pin P8.13 pwm
  // echo 0 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/export
  // echo 1 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/export
  // echo 1250 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/period
  // - 1 bit
  // echo 900 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/duty_cycle
  // - 0 bit
  // echo 350 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/duty_cycle
  // echo 1 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/enable
  //
  // PWMSS0 0x4830_0000
  // ecap0
  // PWMSS1 0x4830_2000
  // PWMSS2 0x4830_4000
  // ePWM2  0x4830_4200 to 0x4830_425F
  //
  // eHRPWM1/ecap1/eQEP1 0x4830_0000
  // eHRPWM2/ecap2/ePWM2 0x4830_2000
  // eHRPWM3/ecap3/ePWM3 0x4830_4000
  //
  //
  // eHRPWM2 = 37 = epwm_intr_intr_pend PRU0_RX_NIBBLE_ODD

  // ETSEL = 0x32
  // ETPS = 0x34
  // ETFLG = 0x36
  // ETCLR = 0x38
  // ETSEL[INTSEL] used to select interrupt trigger (TBCNT == 0 || TBCNT == TBPRD)
  // ETPS[INTCNT] == ETPS[INTPRD] then interrupt generated
  // ETFLG[INT] = 1
  // interrupts disabled: interrupt counter stops when ETPS[INTCNT] == ETPS[INTPRD]
  // interrupts enabled and flag not set (ETFLG[INT] == 0):  
  //
  // 1. disable global interrupt
  // 2. disable epwm interrupts
  // 3. init peripherals
  // 4. clear flags
  // 5. disable epwm interrupts
  // 6. enable global interrupt
  //
  // 0x00020000 pru-icss intc (global and local)

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


// CMPB - 0x14 compared to tbcnt / shadowed
// pull nothing/low/high/toggle
//
// CMPCTL - 0xE - SHDWBFULL (1 << 9)
//        - LOADBMODE - trigger to load shadow
//          - (0 << 2) - load on ctr==0
//          - (1 << 2) - load on ctr==prd
//          - (3 << 2) - load on either
//

  volatile uint16_t *flag_etsel = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_ETSEL_OFFSET);
  volatile uint16_t *flag_etps = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_ETPS_OFFSET);
  volatile uint16_t *flag_status = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_ETFLG_OFFSET);
  volatile uint16_t *flag_etclr = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_ETCLR_OFFSET);

  volatile uint16_t *ehr_cmpb = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_CMPB_OFFSET);
  volatile uint16_t *ehr_pcctl = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_PCCTL_OFFSET);
  volatile uint16_t *ehr_tbprd = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_TBPRD_OFFSET);
  volatile uint16_t *ehr_aqctlb = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_AQCTLB_OFFSET);
  volatile uint16_t *ehr_cmpctl = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_CMPCTL_OFFSET);
  volatile uint16_t *ehr_aqcsfrc = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_AQCSFRC_OFFSET);
  volatile uint16_t *ehr_tbphs = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_TBPHS_OFFSET);
  volatile uint16_t *ehr_aqsfrc = (volatile uint16_t*)(EHRPWM2_BASE + EHRPWM_AQSFRC_OFFSET);
  
  
  *ehr_cmpctl = EHRPWM_CMPCTL_LOADBMODE_Z;
//  *ehr_cmpctl = EHRPWM_CMPCTL_LOADBMODE_P;
  // EHRPWM_CMPCTL_LOADBMODE_P

  *flag_etps = 0; // event count
  *flag_etsel = EHRPWM_ETSEL_INTEN | EHRPWM_ETSEL_INTSEL_PRD;  // interrupt selection
  *ehr_pcctl = 0; // not using pcctl

  *flag_etps = EHRPWM_ETPS_1_EVENT; // event count
//  *flag_etsel = EHRPWM_ETSEL_INTEN | EHRPWM_ETSEL_INTSEL_ZERO;  // interrupt selection
  *flag_etclr = EHRPWM_ETCLR_CLEAR;
  //*ehr_tbprd = 10000;
  *ehr_tbprd = 125; // 1250 ns

  *ehr_cmpb = 0;

  // PWM force high at timer equal 0 / force low after timer equal to CMPB
  *ehr_aqctlb = EHRPWM_AQCTLB_CBU_FORCE_LOW | EHRPWM_AQCTLB_ZRO_FORCE_HIGH; // force high at 0 / force low after B
  
  // initialize to write finished
  shared_mem[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 0;

  // disable force pwm low
  *ehr_aqcsfrc = EHRPWM_AQCSFRC_CSFB_N;
  *ehr_tbphs = 0;
  *ehr_cmpctl = EHRPWM_CMPCTL_LOADBMODE_P;

  while (1)
  {
    // load next value if shadow buffer is empty
//    if (shared_mem[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] > 0)
    {
      // read # leds from shared memory
      led_count = shared_mem[SHARED_MEM_LED_COUNT_OFFSET]; 

      *flag_etclr = EHRPWM_ETCLR_CLEAR;

      // delay until shadow buffer is empty
      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
        ; 

      // loop over LEDs
      for (led_num = 0; led_num < led_count; led_num++)
      {
        // loop over color bits for current LED
        for (bit_num = 0; bit_num < WS2812_LED_BIT_COUNT; bit_num++)
        {
          uint32_t value = 0x800003;

          // get current color bit
          //if (shared_mem[SHARED_MEM_LED_START_OFFSET + led_num] & (1 << bit_num))
          if (value & (1 << bit_num))
          {
            // ws2812 duty cycle to set bit to 1
            *ehr_cmpb = 90;
          }
          else
          {
            // ws2812 duty cycle to set bit to 0
            *ehr_cmpb = 35;
          }

          // delay until shadow buffer is empty
          while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
              ; 
        }
      }
      
      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
        ; 
      *ehr_cmpb = 0;
//      *ehr_aqsfrc = EHRPWM_AQSFRC_OTSFB | EHRPWM_AQSFRC_ACTSFB_C;
//
      //while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
      //  ; 
      //*ehr_aqcsfrc = EHRPWM_AQCSFRC_CSFB_L;

      // *ehr_aqsfrc = EHRPWM_AQSFRC_OTSFB | EHRPWM_AQSFRC_ACTSFB_C;
      __delay_cycles(10000);


      //// set PWM duty cycle to 0 
      //*ehr_cmpb = 0;

      //while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
      //  ;
 
////      // set PWM duty cycle to 0 
////      *ehr_cmpb = 1;
////
////      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
////        ;
////      
////      // force PWM low to before dummy value is used
////      *ehr_aqcsfrc = EHRPWM_AQCSFRC_CSFB_L;
////
////      // set PWM duty cycle to 0 
////      *ehr_cmpb = 0;
////
////      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
////        ;
////      
////      // force PWM low to before dummy value is used
////      *ehr_aqcsfrc = EHRPWM_AQCSFRC_CSFB_N;
////
//      // delay until shadow buffer is empty
//      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
//        ;


//      // delay until shadow buffer is empty
//      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
//        ;

#if 0
      // delay until shadow buffer is empty
      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
        ;

      // dummy PWM duty cycle that will be ignored
      *ehr_cmpb = 1;

      // delay until shadow buffer is empty
      while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
        ;

      // force PWM low to before dummy value is used
      *ehr_aqcsfrc = EHRPWM_AQCSFRC_CSFB_L;

      // reset by holding low for >50 microseconds
      for (delay_cycles = 0; delay_cycles < 50; delay_cycles++)
      {
          // delay until shadow buffer is empty
          while (*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL)
            ;

          // set PWM duty cycle to 0 
          *ehr_cmpb = 0;
      }
      
      // disable pwm force low
      *ehr_aqcsfrc = EHRPWM_AQCSFRC_CSFB_N;

#endif
      // signal that the write is finished
      //shared_mem[SHARED_MEM_LED_BEGIN_WRITE_OFFSET] = 0;
    }

    // poll delay
    __delay_cycles(10000);
  }

  __halt();
}

    //        __R30 = 0;
    //        __delay_cycles(100000000/5);    // Wait 1/2 second
    //        // gpio1[GPIO_SETDATAOUT]   = USR0 | USR1 | USR2 | USR3;			// led test
    //
    //        __R30 = P9_30;
    //
    //        // P9_30 (GPIO_112) ( pruout?)
    //
    //        i = 1;
    //      }
    //      else
    //      {
    //        // gpio1[GPIO_CLEARDATAOUT] = USR0 | USR1 | USR2 | USR3 | P9_14;			// The the USR3 LED on
    //
    //        __R30 = 0;
    //
    //        i = 0;
    //      }

    // test
    // echo "pruout" > /sys/devices/platform/ocp/ocp\:P9_30_pinmux/state
    // __delay_cycles(100);    // 2 mhz (500 ns)

    // __R30 = P9_30;
    // __delay_cycles(180);    // 2 mhz (500 ns)
    // __R30 = 0;
    // __delay_cycles(70);    // 2 mhz (500 ns)

//  // 9_14
//  while (1)
//  {
//    // load next value if shadow buffer is empty
//    if (!(*ehr_cmpctl & EHRPWM_CMPCTL_SHDWBFULL))
//    {
//      __R30 = P9_30; // pulse D3
//      if (test)
//      {
//        //*ehr_tbprd = 10; // 333 ns
//        //*ehr_tbprd = 1; // ~292 ns
//        *ehr_cmpb = 90;
//        //*ehr_pcctl = EHRPWM_PCCTL_DUTY_25 | EHRPWM_PCCTL_CHP_EN;
//        test = 0;
//      }
//      else
//      {
//        //*ehr_aqctlb = EHRPWM_AQCTLB_PRD_FORCE_LOW;
//        //*ehr_tbprd = 1199; // ~12083 ns
//        //*ehr_pcctl = EHRPWM_PCCTL_DUTY_75 | EHRPWM_PCCTL_CHP_EN;
//        //*ehr_cmpb = 100;
//        *ehr_cmpb = 35;
//        test = 1;
//      }
//      //__delay_cycles(100);
//      *flag_etclr = EHRPWM_ETCLR_CLEAR;
//      // __delay_cycles(100);
//    }
//
//    __R30 = 0; // pulse D3
//    //__R30 = P9_30; // pulse D3
//    //__delay_cycles(1000);
//    //__R30 = 0;
//    //__delay_cycles(1000);
//    // P8.13 pwm - pulse D5
//  }

// 1. Disableglobalinterrupts(CPUINTMflag)
// 2. Disable ePWM interrupts
// 3. Initializeperipheralregisters
// 4. Clear any spuriouse PWM flags
// 5. Enable ePWM interrupts
// 6. Enable global interrupts
//
// p226
// 1. Set polarityand type of systemeventthroughthe SystemEventPolarityRegisters(SIPR1and SPIR2)and the SystemEventTypeRegisters(SITR1and SITR2).Polarityof all systemeventsis alwayshigh.Typeof all systemeventsis alwayspulse.
// 2. Map system event to INTC channel through Channel Map registers.
// 3. Map channelto host interrupt through HostInterruptMap registers.Recommendchannel“x” bemappedto host interrupt“x”.
// 4. Clearsystemeventby writing1s to SECRregisters.
// 5. Enablehost interruptby writingindexvalueto HIERregister.
// 6. Enable interrupt nesting if desired. 
// 7. Globally enable all interruptsthroughGERregister.
//
// PRU interrupt
// #37 epwm_intr_intr_pend eHRPWM2 PRU-ICSS0 PRU0_RX_NIBBLE_ODD
//
// EPWMxINT
// CTR == CMPB -> TBCNT == CMPB
// CTR = PRD -> TBCNT == TBPRD (use to load active counter-compare from shadow register)
// CMPCTL = counter compare control register = 0xE
// CMPB = counter compare B = 0x14
//
// CMPCTL[LOADBMODE] - mode to determine which comparison event to use shadowed register
//
// CMPCTL[SHDWBMODE] - shadow mode enabled by clearing bit (shadow enabled by default)
// TBCTL[SHADWAMODE] - immediate mode == 1
// When using up-count mode to generatean asymmetricPWM:•  
// To achieve0-100%asymmetricPWM
// use the followingconfiguration:
// Load CMPA/CMPB on TBPRD.
// Use the Zero action to set the PWM and a compare-up action to clear the PWM.
// Modulate the compare value from 0 to TBPRD+1 to achieve 0-100% PWMduty.
// CMPB - duty cycle
// AQCTL - actian qualifier submodule
//
// TZEINT - offset 0x2A - value == 0x2 - trip zone cycle by cycle interrupt enable causing EPWMxTZINT interrupt
// TZFLG - offset 0x2C - value == 0x2 - CBC trip event occurred - 0x1 - latched trip interrupt event ocurred
// TZCLR - offset 0x2E - value == 0x2 - clear CBC trip latch - 0x1 - clear global interrupt flag
//
// EPWMx_INT
// 0x32 - ETSEL -> enable ePWM interrupts
//      - 0x8 | 0x1 == interrupt enable | interrupt on TBCNT == 0
// 0x34 - read -> (value & 0xC) >> 2 == interrupt count
//      - INTPRD = # events to generate interrupt 
//      -> set = 0x1

// header P8
// pin 13 - PROC T10 - ehrpwm2b = mode4 (mode 7 gpio0[23])
// echo 1 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/
// 
// echo 1 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/enable
//
// #P8.13/P8.16 -> ehrpwm2b
// epwm2int - TZ1 to TZn - xSYNCI/xSYNCO - eCAP1
//
// #ls -lh /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/
//
// error = +/- 150 ns
// #define WS2812_0_HIGH_TIME_NS         350
// #define WS2812_0_LOW_TIME_NS          900
// #define WS2812_1_HIGH_TIME_NS         900
// #define WS2812_1_LOW_TIME_NS          350
//
// 10000 -> 100 khz -> 10 us / cycle
// 5000 -> 200 khz -> 5000 ns / cycle
//
// 1250 nanoseconds / period -> 900 
// 
//
// pin 19 - PROC U10 - ehrpwm2a = mode4 (mode 7 gpio0[22])
// pin 34 - PROC U4  - ehrpwm1b = mode2 (mode 7 gpio2[17])
// pin 36 - PROC U3  - ehrpwm1a = mode2 (mode 7 gpio2[16])
// pin 45 - PROC R1  - ehrpwm2a = mode2 (mode 7 gpio2[6])
// pin 46 - PROC R2  - ehrpwm2b = mode2 (mode 7 gpio2[7])

//  "/sys/class/gpio/export\0 105 \0" \
//

// Turns off triggers
#pragma DATA_SECTION(init_pins, ".init_pins")
#pragma RETAIN(init_pins)
const char init_pins[] =  
	"/sys/class/leds/beaglebone:green:usr0/trigger\0none\0" \
	"/sys/class/leds/beaglebone:green:usr1/trigger\0none\0" \
	"/sys/class/leds/beaglebone:green:usr2/trigger\0none\0" \
	"/sys/class/leds/beaglebone:green:usr3/trigger\0none\0" \
  "/sys/devices/platform/ocp/ocp\:P9_30_pinmux/state\0 pruout \0" \
	"\0\0";

