#!/bin/bash
config-pin P8.13 pwm
echo "pruout" > /sys/devices/platform/ocp/ocp\:P9_30_pinmux/state
echo 1 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/export
echo 1250 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/period
echo 900 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/duty_cycle
# echo 350 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/duty_cycle
echo 1 > /sys/devices/platform/ocp/48304000.epwmss/48304200.pwm/pwm/pwmchip7/pwm-7\:1/enable

