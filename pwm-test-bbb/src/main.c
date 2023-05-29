#include <errno.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h> // mmap/munmap
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "debug.h"
#include "share.h"
#include "cm_per.h"
#include "prm_per.h"
#include "pwm_subsystem.h"
#include "enhanced_pwm.h"

int main(void)
{
    int retval = -ENOMEM;
    mem_mgr_t* mem_mgr = NULL;
    volatile prm_per_t *prm_per = NULL; 
    volatile cm_per_t *cm_per = NULL; 
    volatile pwmss_t  *pwmss2 = NULL; 
    volatile epwm_t   *epwm2 = NULL;

    // init peripheral memory manager
    if ( (mem_mgr = mem_mgr_init()) == NULL)
        goto exit_error;

    // init peripheral memory
    if ( (prm_per = prm_per_init(mem_mgr)) == NULL)
        goto exit_error;
    if ( (cm_per = cm_per_init(mem_mgr)) == NULL)
        goto exit_error;
    if ( (pwmss2 = pwmss_init(mem_mgr)) == NULL)
        goto exit_error;
    if ( (epwm2 = epwm_init(pwmss2)) == NULL)
        goto exit_error;

    // configure pru/pwm subsystem
    if ( (retval = prm_per_configure(prm_per)) < 0)
        goto exit_error;
    if ( (retval = cm_per_configure(cm_per)) < 0)
        goto exit_error;
    if ( (retval = pwmss_configure(pwmss2)) < 0)
        goto exit_error;
    if ( (retval = epwm_configure(epwm2)) < 0)
        goto exit_error;

#if DEBUG_PRINT_REG
    prm_per_debug(prm_per);
    cm_per_debug(cm_per);
    pwmss_debug(pwmss2);
    epwm_debug(epwm2);
#endif

exit_error:
    epwm_destroy(epwm2);
    pwmss_destroy(pwmss2);
    cm_per_destroy(cm_per);
    prm_per_destroy(prm_per);
    mem_mgr_destroy(mem_mgr);

    if (retval < 0)
        printf("Error: %d", retval);

    return retval;
}

