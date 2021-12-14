#include <stdlib.h>
#include "debug.h"
#include "led_cycle.h"
#include "pru_shmem.h"
#include "util.h"

extern pru_shmem_t *global_pru_shmem;

led_cycle_t* led_cycle_create()
{
  return calloc(1, sizeof(led_cycle_t));
}

int led_cycle_destroy(led_cycle_t **led_cycle)
{
  led_cycle_node_t *next_node, *current_node;

  if (led_cycle == NULL)
  {
    printDebug("Null led_cycle\n");
    return -1;
  }

  if (*led_cycle == NULL)
  {
    printDebug("Null *led_cycle\n");
    return -1;
  }
  current_node = (*led_cycle)->first;

  while (current_node != NULL)
  {
    next_node = current_node->next;
    led_cycle_node_destroy(&current_node);
    current_node = next_node;
  }

  free(*led_cycle);
  *led_cycle = NULL;

  return 0;
}

int led_cycle_node_destroy(led_cycle_node_t **led_cycle_node)
{
  if (led_cycle_node == NULL)
  {
    printDebug("Null led_cycle_node\n");
    return -1;
  }

  if (*led_cycle_node == NULL)
  {
    printDebug("Null *led_cycle_node\n");
    return -1;
  }

  if (led_config_destroy((*led_cycle_node)->led_config))
  {
    printDebug("Fail to deallocate led_config\n");
  }

  free(*led_cycle_node);
  *led_cycle_node = NULL;

  return 0;
}

int led_cycle_check_params(led_cycle_t *led_cycle)
{
  if (led_cycle == NULL)
  {
    printDebug("Null led_cycle\n");
    return -1;
  }

  if (led_cycle->first == NULL)
  {
    printDebug("Null led cycle list\n");
    return -1;
  }
  
  if (led_cycle->current == NULL)
  {
    printDebug("Null current led\n");
    return -1;
  }

  if (led_cycle->last == NULL)
  {
    printDebug("Null last led\n");
    return -1;
  }

  if (led_cycle->last->next != NULL)
  {
    printDebug("Last node is invalid - not the final LED config\n");
    return -1;
  }

  return 0;
}

int led_cycle_check_equality(led_cycle_t *cycle1, led_cycle_t *cycle2)
{
  led_cycle_node_t *node_iter1 = NULL;
  led_cycle_node_t *node_iter2 = NULL;
  int node_count = 0;

  if (led_cycle_check_params(cycle1))
  {
    printDebug("Fail parameter check on cycle 1\n");
    return -1;
  }
  node_iter1 = cycle1->first;

  if (led_cycle_check_params(cycle2))
  {
    printDebug("Fail parameter check on cycle 2\n");
    return -1;
  }
  node_iter2 = cycle2->first;

  do {
    // check that the nodes have the same led configurations
    if (led_cycle_node_check_equality(node_iter1, node_iter2))
    {
      printDebug("LED cycle node ");
      printf("%d did not match\n", node_count);
    }

    // exit now if reached the last node in linked list
    if (node_iter1 == cycle1->last || node_iter2 == cycle2->last)
    {
      break;
    }

    // cycle to next
    node_iter1 = node_iter1->next;
    node_iter2 = node_iter2->next;
  } while (node_iter1 != NULL && node_iter2 != NULL);

  // make sure last node was reached on both iterators
  if (node_iter1 != cycle1->last || node_iter2 != cycle2->last)
  {
    printDebug("Number of nodes did not match");
    return -1;
  } 

  return 0;
}

int led_cycle_node_check_equality(led_cycle_node_t *node1, led_cycle_node_t *node2)
{
  if (node1 == NULL)
  {
    printDebug("Null led node1\n");
    return -1;
  }

  if (node2 == NULL)
  {
    printDebug("Null led node2\n");
    return -1;
  }
  
  // make sure led configs are not null
  if (NULL == node1->led_config)
  {
    printDebug("Null led configuration in node 1\n");
  }
  if (NULL == node2->led_config)
  {
    printDebug("Null led configuration in node 2\n");
  }

  if (node1->ms_delay != node2->ms_delay)
  {
    printDebug("Node display times did not match\n");
    return -1;
  }

  if (led_config_check_equality(node1->led_config, node2->led_config))
  {
    printDebug("Node led color configuration did not match\n");
    return -1;
  }

  return 0;
}

int led_cycle_node_add(led_cycle_t *led_cycle, uint32_t display_time_ms, led_config_t *led_config)
{
  led_cycle_node_t *new_node;
  if (led_cycle == NULL)
  {
    printDebug("Null led_cycle\n");
    return -1;
  }

  if (display_time_ms == 0)
  {
    printDebug("Display time is 0\n");
    return -1;
  }

  if (led_check_params(led_config))
  {
    printDebug("Fail param check\n");
    return -1;
  }

  new_node = malloc(sizeof(led_cycle_node_t));
  if (new_node == NULL)
  {
    printDebug("Fail allocate new node\n");
    return -1;
  }
  new_node->ms_delay = display_time_ms;
  new_node->led_config = led_config;
  new_node->next = NULL;

  if (led_cycle->first == NULL)
  {
    // adding to empty list
    led_cycle->first = new_node;
    led_cycle->current = new_node;
  }
  else
  {
    // add link to this node
    led_cycle->last->next = new_node;
  }

  // update final node
  led_cycle->last = new_node;
  return 0;
}

int led_cycle_write_current(led_cycle_t *led_cycle)
{
  led_cycle_node_t *current_node;

  if (led_cycle_check_params(led_cycle))
  {
    printDebug("Fail param check\n");
    return -1;
  }
  current_node = led_cycle->current;

  if (led_check_params(current_node->led_config))
  {
    printDebug("Fail param check\n");
    return -1;
  }

  // write the led values to shared memory
  shmem_synchronize(global_pru_shmem, current_node->led_config);
  if (led_check_params(current_node->led_config))
  {
    printDebug("Fail param check\n");
    return -1;
  }

  // sleep to display for ms_delay milliseconds before return
  msleep(current_node->ms_delay);

  return 0;
}

int led_cycle_iterate(led_cycle_t *led_cycle)
{
  if (led_cycle_check_params(led_cycle))
  {
    printDebug("Fail param check\n");
    return -1;
  }

  if (led_cycle->current == led_cycle->last)
  {
    // loop back to first
    led_cycle->current = led_cycle->first;
  }
  else
  {
    // update current to next node
    led_cycle->current = led_cycle->current->next;
  }
  
  // make sure result was valid
  if (led_cycle->current == NULL)
  {
    printDebug("Fail to update current node\n");
    return -1;
  }

  return 0;
}

int led_cycle_write_and_iterate(led_cycle_t *led_cycle)
{
  if (led_cycle_check_params(led_cycle))
  {
    printDebug("Fail param check\n");
    return -1;
  }

  // send to PRU shared memory
  if (led_cycle_write_current(led_cycle))
  {
    printDebug("Fail cycle LED Write\n");
    return -1;
  }

  // iterate to next element in led cycle list
  if (led_cycle_iterate(led_cycle))
  {
    printDebug("Fail cycle iterate\n");
    return -1;
  }

  return 0;
}

int led_cycle_write_file(led_cycle_t *led_cycle, const char *file_name)
{
  FILE *file_ptr;
  size_t write_elements;
  led_cycle_node_t *current_node;

  if (led_cycle_check_params(led_cycle))
  {
    printDebug("Fail param check\n");
    return -1;
  }

  if (file_name == NULL)
  {
    printDebug("NULL file name\n");
    return -1;
  }

  file_ptr = fopen(file_name, "wb");
  if (file_ptr == NULL)
  {
    printDebug("Fail to open file: ");
    printf("%s", file_name);
    return -1;
  }

  current_node = led_cycle->first;
  while (current_node != NULL)
  {
    // write milliseconds to display this color configuration
    write_elements = fwrite(&(current_node->ms_delay), sizeof(current_node->ms_delay), 1, file_ptr);

    // append led config data to file
    if (led_append_file(current_node->led_config, file_ptr))
    {
      printDebug("Fail to write elements to file: ");
      printf("%s - wrote %zu, expected 1", file_name, write_elements);
      return -1;
    }

    current_node = current_node->next;
  }

  fclose(file_ptr);

  return 0;
}

int led_cycle_read_file(led_cycle_t **ret_cycle, const char *file_name)
{
  FILE *file_ptr;
  led_cycle_t *cycle;
  size_t read_elements;

  // check null return pointer
  if (ret_cycle == NULL)
  {
    printDebug("NULL return pointer\n");
    return -1;
  }
  *ret_cycle = NULL;

  if (file_name == NULL)
  {
    printDebug("NULL file name\n");
    return -1;
  }

  // allocate space for led cycle
  cycle = calloc(1, sizeof(led_cycle_t));
  if (cycle == NULL)
  {
    printDebug("Fail to allocate led_cycle_t\n");
    return -1;
  }

  // open saved led cycle file
  file_ptr = fopen(file_name, "rb");
  if (file_ptr == NULL)
  {
    printDebug("Fail to open file: ");
    printf("%s\n", file_name);
    free(cycle);
    return -1;
  }

  while (1)
  {
    // allocate space for led cycle
    led_cycle_node_t *node = calloc(1, sizeof(led_cycle_node_t));
    if (node == NULL)
    {
      printDebug("Could not allocate led node\n");
      return -1;
    }

    // read led millisecond delay
    read_elements = fread(&(node->ms_delay), sizeof(uint32_t), 1, file_ptr);
    if (read_elements != 1)
    {
      // ran out of elements to read
      free(node);
      break;
    }

    // read led config count/color data
    if (led_read_file_pointer(&(node->led_config), file_ptr))
    {
      // ran out of elements to read
      free(node);
      break;
    }
    
    // update first/current if initializing first node
    if (cycle->first == NULL)
    {
      cycle->first = node;
      cycle->current = node;
    }
    else
    {
      // existing last node.next pointer = this newly read node
      cycle->last->next = node;
    }
    
    // update pointer to last node
    cycle->last = node;
  }

  fclose(file_ptr);

  // return error if failed to read any nodes from file
  if (cycle->first == NULL)
  {
    printDebug("Fail to read nodes from file ");
    printf("%s\n", file_name);
    free (cycle);
    return -1;
  }

  // update returned value to newly created cycle
  *ret_cycle = cycle;

  return 0;
}


