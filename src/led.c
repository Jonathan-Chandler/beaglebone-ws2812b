#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

int led_write_file(led_strip_t *strip, const char *file_name)
{
  FILE *file_ptr;
  size_t write_elements;

  if (strip == NULL)
  {
    printDebug("Attempt write NULL led strip\n");
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

  // write led count
  write_elements = fwrite(&(strip->led_count), sizeof(strip->led_count), 1, file_ptr);
  if (write_elements != 1)
  {
    printDebug("Fail to write elements to file: ");
    printf("%s - wrote %lu, expected 1", file_name, write_elements);
    return -1;
  }

  // write led color array
  write_elements = fwrite(&(strip->led_colors[0]), sizeof(led_color_t), strip->led_count, file_ptr);
  if (write_elements != strip->led_count)
  {
    printDebug("Fail to write elements to file: ");
    printf("%s - wrote %lu, expected %u", file_name, write_elements, strip->led_count);
    return -1;
  }

  fclose(file_ptr);

  return 0;
}

int led_read_file(led_strip_t **ret_strip, const char *file_name)
{
  FILE *file_ptr;
  led_strip_t *strip;
  size_t read_elements;

  // check null return pointer
  if (ret_strip == NULL)
  {
    printDebug("NULL return pointer\n");
    return -1;
  }
  *ret_strip = NULL;

  if (file_name == NULL)
  {
    printDebug("NULL file name\n");
    return -1;
  }

  // allocate space for led struct
  strip = malloc(sizeof(led_strip_t));
  if (strip == NULL)
  {
    printDebug("Attempt write NULL led strip\n");
    return -1;
  }

  // open saved led file
  file_ptr = fopen(file_name, "rb");
  if (file_ptr == NULL)
  {
    printDebug("Fail to open file: ");
    printf("%s\n", file_name);
    free(strip);
    return -1;
  }

  // read led count
  read_elements = fread(&(strip->led_count), sizeof(uint32_t), 1, file_ptr);
  if (read_elements != 1)
  {
    printDebug("Fail to read file: ");
    printf("%s\n", file_name);
    fclose(file_ptr);
    free(strip);
    return -1;
  }
  printDebug("test\n");

  // make sure data is valid
  if (strip->led_count == 0)
  {
    printDebug("Read 0 led count from file: \n");
    printf("%s\n", file_name);
    fclose(file_ptr);
    free(strip);
    return -1;
  }

  // allocate space for led colors
  strip->led_colors = malloc(sizeof(led_color_t)*strip->led_count);
  if (strip->led_colors == NULL)
  {
    printDebug("Fail to allocate space for leds\n");
    fclose(file_ptr);
    free(strip);
    return -1;
  }

  // write led color array
  read_elements = fread(&(strip->led_colors[0]), sizeof(led_color_t), strip->led_count, file_ptr);
  if (read_elements != strip->led_count)
  {
    printDebug("Fail to read LEDs from file: ");
    printf("read %lu bytes but expected %u\n", read_elements, strip->led_count);
    fclose(file_ptr);
    free(&(strip->led_colors[0]));
    free(strip);
    return -1;
  }
  
  fclose(file_ptr);

  *ret_strip = strip;

  return 0;
}


