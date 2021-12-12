#include "led_cycle.h"
#include "pru_shmem.h"

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

  if (led_strip_destroy((*led_cycle_node)->led_strip))
  {
    printDebug("Fail to deallocate led_strip\n");
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

  if (led_cycle->last == NULL)
  {
    printDebug("Null last led\n");
    return -1;
  }

  return 0;
}

int led_cycle_add_node(led_cycle_t *led_cycle, uint32_t display_time_ms, led_strip_t *led_strip)
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

  if (led_check_params(led_strip))
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
  new_node->led_strip = led_strip;
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

int led_cycle_start(led_cycle_t* led_cycle)
{
  led_cycle_node_t *current_node;

  if (led_cycle_check_params(led_cycle))
  {
    printDebug("Fail param check\n");
    return -1;
  }
  current_node = led_cycle->first;

  while (current_node)
  {
    if (led_check_params(current_node->led_strip))
    {
      printDebug("Fail param check\n");
      return -1;
    }

    if (led_check_params(current_node->led_strip))
    {
      printDebug("Fail param check\n");
      return -1;
    }
  }

  new_node = malloc(sizeof(led_cycle_node_t));
  if (new_node == NULL)
  {
    printDebug("Fail allocate new node\n");
    return -1;
  }
  new_node->ms_delay = display_time_ms;
  new_node->led_strip = led_strip;
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

