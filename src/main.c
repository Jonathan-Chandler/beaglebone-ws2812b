#include <sys/types.h>
//#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "debug.h"
#include "pru_shmem.h"
#include "led.h"
#include "led_cycle.h"
#include "ws2812b.h"
#include "share.h"

pru_shmem_t *global_pru_shmem;

#define TEST_CYCLE_TIME_2_SEC 2000 // in milliseconds

int test_led_cycle(void);

int load_led_file(char *file_name)
{
  led_cycle_t *loaded_cycle;
  printf("Loading LED file %s\n", file_name);

  if (led_cycle_read_file(&loaded_cycle, file_name))
  {
    printf("Failed to load led cycle from %s\n", file_name);
    return -1;
  }

  // send each node from loaded led cycle to PRU one time
  do 
  {
    if (led_cycle_write_and_iterate(loaded_cycle))
    {
      printf("Failed to write and iterate loaded led cycle\n");
      return -1;
    }
  } while (loaded_cycle->current != loaded_cycle->first);

  if (led_cycle_destroy(&loaded_cycle))
  {
    printf("Failed to deallocate loaded led cycle\n");
    return -1;
  }

  return 0;
}

int main(int argc, char *argv[])
{
  int opt;
  int retval = 0;
  global_pru_shmem = shmem_allocate();

  // get commandline arguments
  while ((opt = getopt(argc, argv, "l")) != -1)
  {
    switch (opt)
    {
      case 'l':
        // loading file
        if (argc == 3)
        {
          return load_led_file(argv[2]);
          break;
        }
      default:
        printf("Usage: %s [-l <LED cycle data file name>]\n", argv[0]);
        break;
    }
  }

  retval = test_led_cycle();
  if (retval != 0)
  {
    printDebug("Failed to run test led cycle\n");
  }

  shmem_deallocate(&global_pru_shmem);
  return retval;
}

int test_led_cycle()
{
  const char *save_file_name = "test_led_cycle.dat";
  led_cycle_t *led_cycle = NULL;
  led_config_t *led_config = NULL;
  led_config_t *led_config2 = NULL;
  led_config_t *led_config3 = NULL;
  led_color_t *default_color = NULL;
  led_color_t *default_color2 = NULL;
  led_color_t *default_color3 = NULL;

  // allocate shared mem to communicate to PRU
  if (global_pru_shmem == NULL)
  {
    printDebug("Fail shmem allocate\n");
    goto EXIT_FAIL;
  }

  // create led cycle linked list
  led_cycle = led_cycle_create();
  if (led_cycle == NULL)
  {
    printDebug("Fail led_cycle allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for config 1
  default_color = led_color_init(0, 0, 255);
  if (default_color == NULL)
  {
    printDebug("Fail default_color allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for config 2
  default_color2 = led_color_init(0, 255, 0);
  if (default_color2 == NULL)
  {
    printDebug("Fail default_color2 allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for config 3
  default_color3 = led_color_init(255, 0, 0);
  if (default_color3 == NULL)
  {
    printDebug("Fail default_color3 allocate\n");
    goto EXIT_FAIL;
  }

  // create led config with default color
  led_config = led_config_init(WS2812_LED_COUNT, default_color);
  if (led_config == NULL)
  {
    printDebug("Fail led_config allocate\n");
    goto EXIT_FAIL;
  }

  // create led config with default color 2
  led_config2 = led_config_init(WS2812_LED_COUNT, default_color2);
  if (led_config2 == NULL)
  {
    printDebug("Fail led_config2 allocate\n");
    goto EXIT_FAIL;
  }

  // create led config with default color 3
  led_config3 = led_config_init(WS2812_LED_COUNT, default_color3);
  if (led_config3 == NULL)
  {
    printDebug("Fail led_config3 allocate\n");
    goto EXIT_FAIL;
  }

  // add led config to linked list
  if (led_cycle_node_add(led_cycle, TEST_CYCLE_TIME_2_SEC, led_config))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

  // add led config to linked list
  if (led_cycle_node_add(led_cycle, TEST_CYCLE_TIME_2_SEC, led_config2))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

  // add led config to linked list
  if (led_cycle_node_add(led_cycle, TEST_CYCLE_TIME_2_SEC, led_config3))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

//  while (1)
//  {
  // attempt writing to LEDs
  led_cycle_write_and_iterate(led_cycle);
  led_cycle_write_and_iterate(led_cycle);
  led_cycle_write_and_iterate(led_cycle);
//  }

  if (led_cycle_write_file(led_cycle, save_file_name))
  {
    printDebug("Fail to save led cycle to file");
    printf("%s", save_file_name);
    goto EXIT_FAIL;
  }

  led_color_destroy(&default_color);
  led_color_destroy(&default_color2);
  led_color_destroy(&default_color3);
  //led_config_destroy(led_config);
  //led_config_destroy(led_config2);
  //led_config_destroy(led_config3);
  led_cycle_destroy(&led_cycle);

  return 0;

EXIT_FAIL:
  led_color_destroy(&default_color);
  led_color_destroy(&default_color2);
  //led_config_destroy(led_config);
  //led_config_destroy(led_config2);
  //led_config_destroy(led_config3);
  led_cycle_destroy(&led_cycle);

  return -1;
}

#if 0
{
  global_pru_shmem = shmem_allocate();
  led_cycle_t *led_cycle = NULL;
  led_config_t *led_config = NULL;
  led_config_t *led_config2 = NULL;
  led_config_t *led_config3 = NULL;
  led_color_t *default_color = NULL;
  led_color_t *default_color2 = NULL;
  led_color_t *default_color3 = NULL;

  // allocate shared mem to communicate to PRU
  if (global_pru_shmem == NULL)
  {
    printDebug("Fail shmem allocate\n");
    goto EXIT_FAIL;
  }

  // create led cycle linked list
  led_cycle = led_cycle_create();
  if (led_cycle == NULL)
  {
    printDebug("Fail led_cycle allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for config 1
  default_color = led_color_init(0, 0, 255);
  if (default_color == NULL)
  {
    printDebug("Fail default_color allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for config 2
  default_color2 = led_color_init(0, 255, 0);
  if (default_color2 == NULL)
  {
    printDebug("Fail default_color2 allocate\n");
    goto EXIT_FAIL;
  }

  // color to use for config 3
  default_color3 = led_color_init(255, 0, 0);
  if (default_color3 == NULL)
  {
    printDebug("Fail default_color3 allocate\n");
    goto EXIT_FAIL;
  }

  // create led config with default color
  led_config = led_config_init(WS2812_LED_COUNT, default_color);
  if (led_config == NULL)
  {
    printDebug("Fail led_config allocate\n");
    goto EXIT_FAIL;
  }

  // create led config with default color 2
  led_config2 = led_config_init(WS2812_LED_COUNT, default_color2);
  if (led_config2 == NULL)
  {
    printDebug("Fail led_config2 allocate\n");
    goto EXIT_FAIL;
  }

  // create led config with default color 3
  led_config3 = led_config_init(WS2812_LED_COUNT, default_color3);
  if (led_config3 == NULL)
  {
    printDebug("Fail led_config3 allocate\n");
    goto EXIT_FAIL;
  }

  // add led config to linked list
  if (led_cycle_node_add(led_cycle, 10000, led_config))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

  // add led config to linked list
  if (led_cycle_node_add(led_cycle, 10000, led_config2))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

  // add led config to linked list
  if (led_cycle_node_add(led_cycle, 10000, led_config3))
  {
    printDebug("Fail to add node\n");
    goto EXIT_FAIL;
  }

//  while (1)
//  {
  // attempt writing to LEDs
  led_cycle_write_and_iterate(led_cycle);
  led_cycle_write_and_iterate(led_cycle);
  led_cycle_write_and_iterate(led_cycle);
//  }

  led_color_destroy(&default_color);
  led_color_destroy(&default_color2);
  led_color_destroy(&default_color3);
  //led_config_destroy(led_config);
  //led_config_destroy(led_config2);
  //led_config_destroy(led_config3);
  led_cycle_destroy(&led_cycle);
  shmem_deallocate(&global_pru_shmem);

  return 0;

EXIT_FAIL:
  led_color_destroy(&default_color);
  led_color_destroy(&default_color2);
  //led_config_destroy(led_config);
  //led_config_destroy(led_config2);
  //led_config_destroy(led_config3);
  led_cycle_destroy(&led_cycle);
  shmem_deallocate(&global_pru_shmem);

  return -1;
}
#endif
