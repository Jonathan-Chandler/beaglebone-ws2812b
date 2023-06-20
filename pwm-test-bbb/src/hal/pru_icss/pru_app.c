#include <errno.h>
#include <stddef.h>

#include "debug.h"
#include "util.h"
#include "memory_manager.h"
#include "hal/pru_icss/pru_app.h"

volatile pru_app_t* pru_app_init(mem_mgr_t *mem_mgr)
{
    pru_app_t *pru_app;

    if ( (pru_app = mem_mgr_get_map(mem_mgr, PRU_0_IRAM_BASE_ADDR)) == 0 )
    {
        report_error("Receive NULL pru_app\n");
    }

    report_log("pru_app = %p\n", pru_app);

    return pru_app;
}

int pru_app_destroy(volatile pru_app_t *pru_app)
{
    if (!pru_app)
    {
        report_log("pru_app was null\n");
        return -1;
    }

    // do not deallocate - handled by mem_mgr

    return 0;
}

int pru_app_configure(volatile pru_app_t *pru_app)
{
    FILE *app_ptr = NULL;
    long app_len;
    int retval = 0;

    if (!pru_app)
        return -EINVAL;

    app_ptr = fopen("main.pru0.out", "rb");
    if (app_ptr == NULL)
    {
        report_error("Fail to open main.pru0.out\n");
        retval = -EINVAL;
        goto exit_error;
    }

    // get app len
    fseek(app_ptr, 0, SEEK_END);
    app_len = ftell(app_ptr);

    report_log("app_len = %ld bytes (0x%lX)\n", app_len, app_len);

    // return to beginning of application
    rewind(app_ptr);

    // copy to pru0 memory
    fread((void*)pru_app, app_len, 1, app_ptr);


exit_error:
    if (app_ptr != NULL)
        fclose(app_ptr);

    return retval;
}

#if DEBUG_PRINT_REG
void pru_app_debug(volatile pru_app_t *pru_app)
{
    if (!pru_app)
    {
        report_error("pru_app was null\n");
        return;
    }
}
#endif // if DEBUG_PRINT_REG

