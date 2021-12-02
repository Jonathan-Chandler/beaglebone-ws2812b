#include <string.h>
#include <stdlib.h>
#include "debug.h"
#include "led.h"

led_strip_t *led_strip_init(uint32_t led_count, led_color_t *default_color)
{
  led_strip_t *led_strip = NULL;
  led_color_t *led_colors = NULL;

  if (led_count == 0)
  {
    printDebug("Request 0 count\n");
    return NULL;
  }

  if (default_color == NULL)
  {
    printDebug("Receive NULL default color\n");
    return NULL;
  }

  led_strip = malloc(sizeof(led_strip_t));
  if (led_strip == NULL)
  {
    printDebug("Fail to allocate\n");
    return NULL;
  }

  led_colors = malloc(led_count*sizeof(led_color_t));

  if (led_colors == NULL)
  {
    free(led_strip);
    printDebug("Fail to allocate\n");
    return NULL;
  }

  // initialize with default color
  for (uint32_t led_index = 0; led_index < led_count; led_index++)
  {
    memcpy(&led_colors[led_index], default_color, sizeof(led_color_t));
  }

  led_strip->led_count = led_count;
  led_strip->led_colors = led_colors;

  return led_strip;
}

int led_strip_destroy(led_strip_t *strip)
{
  if (strip == NULL)
  {
    printDebug("Deallocate NULL led strip\n");
    return -1;
  }

  if (strip->led_colors == NULL)
  {
    printDebug("Deallocate NULL list of colors\n");

    // obj
    free(strip);

    return -1;
  }

  // led color list
  free(strip->led_colors);

  return 0;
}

int led_set_single(led_strip_t *strip, uint32_t index, led_color_t *new_color)
{
  if (strip == NULL)
  {
    printDebug("Set color on NULL led strip\n");
    return -1;
  }

  if (strip->led_colors == NULL)
  {
    printDebug("Set color on NULL led color list\n");
    return -1;
  }

  if (new_color == NULL)
  {
    printDebug("New color is NULL\n");
    return -1;
  }

  if (index >= strip->led_count)
  {
    printDebug("LED index out of range\n");
    return -1;
  }

  memcpy(&strip->led_colors[index], new_color, sizeof(led_color_t));

  return 0;
}

int led_set_range(led_strip_t *strip, uint32_t begin, uint32_t count, led_color_t *new_color)
{
  if (strip == NULL)
  {
    printDebug("Set color range on NULL led strip\n");
    return -1;
  }

  if (count == 0)
  {
    printDebug("Set 0 color count on led strip\n");
    return -1;
  }

  if (strip->led_colors == NULL)
  {
    printDebug("Set color on NULL led color list\n");
    return -1;
  }

  if (new_color == NULL)
  {
    printDebug("New color was NULL\n");
    return -1;
  }

  if (begin >= strip->led_count || begin+count > strip->led_count)
  {
    printDebug("LED index out of range\n");
    return -1;
  }

  for (uint32_t index = begin; index < begin+count; index++)
  {
    memcpy(&strip->led_colors[index], new_color, sizeof(led_color_t));
  }

  return 0;
}

int led_set_all(led_strip_t *strip, led_color_t *new_color)
{
  if (strip == NULL)
  {
    printDebug("Set color range on NULL led strip\n");
    return -1;
  }

  if (strip->led_colors == NULL)
  {
    printDebug("Set color on NULL led color list\n");
    return -1;
  }

  if (new_color == NULL)
  {
    printDebug("New color was NULL\n");
    return -1;
  }

  for (uint32_t index = 0; index < strip->led_count; index++)
  {
    memcpy(&strip->led_colors[index], new_color, sizeof(led_color_t));
  }

  return 0;
}

int led_write()
{
}
