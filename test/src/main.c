#ifdef DEBUG_ENABLED
#undef DEBUG_ENABLED
#endif

#include "debug.h"
#include "led_test.h"

extern LED_TEST *led_test[];
extern int led_test_count;

int main(void)
{
  printf("\n\n");
  printf("------ UNIT TEST ------\n");
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
  printf("------ TEST FINISHED ------\n");
  printf("\n\n");

  return 0;
}

