#ifdef DEBUG_ENABLED
#undef DEBUG_ENABLED
#endif

#include "debug.h"
#include "pru_shmem.h"
#include "led_test.h"
#include "led_cycle_test.h"

extern LED_TEST *led_test[];
extern int led_test_count;

extern LED_CYCLE_TEST *led_cycle_test[];
extern int led_cycle_test_count;

pru_shmem_t *global_pru_shmem; // not used

int main(void)
{
  printf("\n\n");
  printf("------ UNIT TEST ------\n");
  printf("------    LED    ------\n");
  for (int i = 0; i < led_test_count; i++)
  {
    if (led_test[i]())
    {
      printf("Fail on test %d\n", i);
      return -1;
    }
    else
    {
      printf("Complete test %d\n", i);
    }
  }
  printf("------ LED_CYCLE ------\n");
  for (int i = 0; i < led_cycle_test_count; i++)
  {
    if (led_cycle_test[i]())
    {
      printf("Fail on test %d\n", i);
      return -1;
    }
    else
    {
      printf("Complete test %d\n", i);
    }
  }
  printf("------ TEST FINISHED ------\n");
  printf("\n\n");

  return 0;
}

