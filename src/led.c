#include <string.h>
#include <stdlib.h>
#include "debug.h"
#include "util.h"
#include "led.h"
#include "share.h"

led_color_t *led_color_init(uint8_t red_value, uint8_t green_value, uint8_t blue_value)
{
  led_color_t *led_color = calloc(1, sizeof(led_color_t));
  if (led_color == NULL)
  {
    printDebug("Could not allocate led_color_t\n");
    return NULL;
  }
  
  led_color->red  = red_value;
  led_color->green = green_value;
  led_color->blue = blue_value;

  // get reversed bit values for input colors
  red_value = reverse_8bit(red_value);
  green_value = reverse_8bit(green_value);
  blue_value = reverse_8bit(blue_value);

  // value converted to send to 32-bit value for WS2812
  led_color->value  = (red_value << WS2812_RED_OFFSET) & WS2812_RED_MASK;
  led_color->value |= (green_value << WS2812_GREEN_OFFSET) & WS2812_GREEN_MASK;
  led_color->value |= (blue_value << WS2812_BLUE_OFFSET) & WS2812_BLUE_MASK;

  return led_color;
}

int led_color_destroy(led_color_t **led_color)
{
  if (led_color == NULL)
  {
    printDebug("receive null led_color\n");
    return -1;
  }
  if (*led_color == NULL)
  {
    printDebug("receive null *led_color\n");
    return -1;
  }

  free(*led_color);
  *led_color = NULL;

  return 0;
}

led_config_t *led_config_init(uint32_t led_count, led_color_t *default_color)
{
  led_config_t *led_config = NULL;
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

  led_config = malloc(sizeof(led_config_t));
  if (led_config == NULL)
  {
    printDebug("Fail to allocate\n");
    return NULL;
  }

  led_colors = malloc(led_count*sizeof(led_color_t));

  if (led_colors == NULL)
  {
    free(led_config);
    printDebug("Fail to allocate\n");
    return NULL;
  }

  // initialize with default color
  for (uint32_t led_index = 0; led_index < led_count; led_index++)
  {
    memcpy(&led_colors[led_index], default_color, sizeof(led_color_t));
  }

  led_config->led_count = led_count;
  led_config->led_colors = led_colors;

  return led_config;
}

int led_config_destroy(led_config_t *config)
{
  if (config == NULL)
  {
    printDebug("Deallocate NULL led config\n");
    return -1;
  }

  if (config->led_colors == NULL)
  {
    printDebug("Deallocate NULL list of colors\n");

    // obj
    free(config);

    return -1;
  }

  // led color list
  free(config->led_colors);

  return 0;
}

int led_check_params(led_config_t *config)
{
  if (config == NULL)
  {
    printDebug("Null led config\n");
    return -1;
  }

  if (config->led_count == 0)
  {
    printDebug("No leds in config\n");
    return -1;
  }

  if (config->led_colors == NULL)
  {
    printDebug("Null led colors\n");
    return -1;
  }

  return 0;
}

int led_config_check_equality(led_config_t *config1, led_config_t *config2)
{
  if (led_check_params(config1))
  {
    printDebug("LED config 1 fails parameter check\n");
    return -1;
  }
  
  if (led_check_params(config2))
  {
    printDebug("LED config 2 fails parameter check\n");
    return -1;
  }

  if (config1->led_count != config2->led_count)
  {
    printDebug("LED count did not match\n");
    return -1;
  }

  if (config1->led_count != config2->led_count)
  {
    printDebug("LED count did not match\n");
    return -1;
  }

  for (uint32_t i = 0; i < config1->led_count; i++)
  {
    if (led_color_check_equality(&(config1->led_colors[i]), &(config2->led_colors[i])))
    {
      printDebug("LED color ");
      printf("%u did not match\n", i);
      return -1;
    }
  }

  return 0;
}

int led_color_check_equality(led_color_t *color1, led_color_t *color2)
{
  if (color1 == NULL)
  {
    printDebug("Receive NULL color1 for equality check\n");
    return -1;
  }

  if (color2 == NULL)
  {
    printDebug("Receive NULL color2 for equality check\n");
    return -1;
  }
  
  if (color1->red != color2->red)
  {
    printDebug("Led color red value did not match\n");
    return -1;
  }

  if (color1->green != color2->green)
  {
    printDebug("Led color green value did not match\n");
    return -1;
  }

  if (color1->blue != color2->blue)
  {
    printDebug("Led color blue value did not match\n");
    return -1;
  }

  if (color1->value != color2->value)
  {
    printDebug("Led color pru value did not match\n");
    return -1;
  }

  return 0;
}


int led_set_single(led_config_t *config, uint32_t index, led_color_t *new_color)
{
  if (config == NULL)
  {
    printDebug("Set color on NULL led config\n");
    return -1;
  }

  if (config->led_colors == NULL)
  {
    printDebug("Set color on NULL led color list\n");
    return -1;
  }

  if (new_color == NULL)
  {
    printDebug("New color is NULL\n");
    return -1;
  }

  if (index >= config->led_count)
  {
    printDebug("LED index out of range\n");
    return -1;
  }

  memcpy(&config->led_colors[index], new_color, sizeof(led_color_t));

  return 0;
}

int led_set_range(led_config_t *config, uint32_t begin, uint32_t count, led_color_t *new_color)
{
  if (config == NULL)
  {
    printDebug("Set color range on NULL led config\n");
    return -1;
  }

  if (count == 0)
  {
    printDebug("Set 0 color count on led config\n");
    return -1;
  }

  if (config->led_colors == NULL)
  {
    printDebug("Set color on NULL led color list\n");
    return -1;
  }

  if (new_color == NULL)
  {
    printDebug("New color was NULL\n");
    return -1;
  }

  if (begin >= config->led_count || begin+count > config->led_count)
  {
    printDebug("LED index out of range\n");
    return -1;
  }

  for (uint32_t index = begin; index < begin+count; index++)
  {
    memcpy(&config->led_colors[index], new_color, sizeof(led_color_t));
  }

  return 0;
}

int led_set_all(led_config_t *config, led_color_t *new_color)
{
  if (config == NULL)
  {
    printDebug("Set color range on NULL led config\n");
    return -1;
  }

  if (config->led_colors == NULL)
  {
    printDebug("Set color on NULL led color list\n");
    return -1;
  }

  if (new_color == NULL)
  {
    printDebug("New color was NULL\n");
    return -1;
  }

  for (uint32_t index = 0; index < config->led_count; index++)
  {
    memcpy(&config->led_colors[index], new_color, sizeof(led_color_t));
  }

  return 0;
}

int led_write_file(led_config_t *config, const char *file_name)
{
  FILE *file_ptr;
  size_t write_elements;

  if (config == NULL)
  {
    printDebug("Attempt write NULL led config\n");
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
  write_elements = fwrite(&(config->led_count), sizeof(config->led_count), 1, file_ptr);
  if (write_elements != 1)
  {
    printDebug("Fail to write elements to file: ");
    printf("%s - wrote %zu, expected 1", file_name, write_elements);
    return -1;
  }

  // write led color array
  write_elements = fwrite(&(config->led_colors[0]), sizeof(led_color_t), config->led_count, file_ptr);
  if (write_elements != config->led_count)
  {
    printDebug("Fail to write elements to file: ");
    printf("%s - wrote %zu, expected %u", file_name, write_elements, config->led_count);
    return -1;
  }

  fclose(file_ptr);

  return 0;
}

int led_read_file(led_config_t **ret_config, const char *file_name)
{
  FILE *file_ptr;
  led_config_t *config;
  size_t read_elements;

  // check null return pointer
  if (ret_config == NULL)
  {
    printDebug("NULL return pointer\n");
    return -1;
  }
  *ret_config = NULL;

  if (file_name == NULL)
  {
    printDebug("NULL file name\n");
    return -1;
  }

  // allocate space for led struct
  config = malloc(sizeof(led_config_t));
  if (config == NULL)
  {
    printDebug("Attempt write NULL led config\n");
    return -1;
  }

  // open saved led file
  file_ptr = fopen(file_name, "rb");
  if (file_ptr == NULL)
  {
    printDebug("Fail to open file: ");
    printf("%s\n", file_name);
    free(config);
    return -1;
  }

  // read led count
  read_elements = fread(&(config->led_count), sizeof(uint32_t), 1, file_ptr);
  if (read_elements != 1)
  {
    printDebug("Fail to read file: ");
    printf("%s\n", file_name);
    fclose(file_ptr);
    free(config);
    return -1;
  }
  printDebug("test\n");

  // make sure data is valid
  if (config->led_count == 0)
  {
    printDebug("Read 0 led count from file: \n");
    printf("%s\n", file_name);
    fclose(file_ptr);
    free(config);
    return -1;
  }

  // allocate space for led colors
  config->led_colors = malloc(sizeof(led_color_t)*config->led_count);
  if (config->led_colors == NULL)
  {
    printDebug("Fail to allocate space for leds\n");
    fclose(file_ptr);
    free(config);
    return -1;
  }

  // write led color array
  read_elements = fread(&(config->led_colors[0]), sizeof(led_color_t), config->led_count, file_ptr);
  if (read_elements != config->led_count)
  {
    printDebug("Fail to read LEDs from file: ");
    printf("read %zu bytes but expected %u\n", read_elements, config->led_count);
    fclose(file_ptr);
    free(&(config->led_colors[0]));
    free(config);
    return -1;
  }
  
  fclose(file_ptr);

  *ret_config = config;

  return 0;
}

int led_append_file(led_config_t *config, FILE *file_ptr)
{
  size_t write_elements;

  if (config == NULL)
  {
    printDebug("Attempt write NULL led config\n");
    return -1;
  }

  if (file_ptr == NULL)
  {
    printDebug("NULL file pointer\n");
    return -1;
  }

  // write led count
  write_elements = fwrite(&(config->led_count), sizeof(config->led_count), 1, file_ptr);
  if (write_elements != 1)
  {
    printDebug("Fail to write led count to file pointer: ");
    printf("wrote %zu, expected 1", write_elements);
    return -1;
  }

  // write led color array
  write_elements = fwrite(&(config->led_colors[0]), sizeof(led_color_t), config->led_count, file_ptr);
  if (write_elements != config->led_count)
  {
    printDebug("Fail to write led color data to file pointer: ");
    printf("wrote %zu, expected %u", write_elements, config->led_count);
    return -1;
  }

  return 0;
}

int led_read_file_pointer(led_config_t **ret_config, FILE *file_ptr)
{
  led_config_t *config;
  size_t read_elements;

  // check null return pointer
  if (ret_config == NULL)
  {
    printDebug("NULL return pointer\n");
    return -1;
  }
  *ret_config = NULL;

  if (file_ptr == NULL)
  {
    printDebug("NULL file pointer\n");
    return -1;
  }

  // allocate space for led struct
  config = malloc(sizeof(led_config_t));
  if (config == NULL)
  {
    printDebug("Fail to allocate led_config_t\n");
    return -1;
  }

  // read led count
  read_elements = fread(&(config->led_count), sizeof(uint32_t), 1, file_ptr);
  if (read_elements != 1)
  {
    printDebug("Fail to read file pointer");
    free(config);
    return -1;
  }

  // make sure data is valid
  if (config->led_count == 0)
  {
    printDebug("Read 0 led count from file pointer\n");
    free(config);
    return -1;
  }

  // allocate space for led colors
  config->led_colors = malloc(sizeof(led_color_t)*config->led_count);
  if (config->led_colors == NULL)
  {
    printDebug("Fail to allocate space for leds\n");
    fclose(file_ptr);
    free(config);
    return -1;
  }

  // read led color array
  read_elements = fread(&(config->led_colors[0]), sizeof(led_color_t), config->led_count, file_ptr);
  if (read_elements != config->led_count)
  {
    printDebug("Fail to read LEDs from file: ");
    printf("read %zu bytes but expected %u\n", read_elements, config->led_count);
    free(&(config->led_colors[0]));
    free(config);
    return -1;
  }
  
  *ret_config = config;

  return 0;
}

