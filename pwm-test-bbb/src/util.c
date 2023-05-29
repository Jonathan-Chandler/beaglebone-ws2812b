#include "util.h"
#include <time.h>
#include <errno.h>

///* msleep(): Sleep for the requested number of milliseconds. */
//int msleep(long msec)
//{
//    struct timespec ts;
//    int res;
//
//    if (msec < 0)
//    {
//        errno = EINVAL;
//        return -1;
//    }
//
//    ts.tv_sec = msec / 1000;
//    ts.tv_nsec = (msec % 1000) * 1000000;
//
//    do {
//        res = nanosleep(&ts, &ts);
//    } while (res && errno == EINTR);
//
//    return res;
//}
//
// reverse single 8 bit value in order to be used by PRU
uint32_t reverse_8bit(uint32_t value)
{
  uint32_t bit_num;
  uint32_t reversed_value = 0;

  for (bit_num = 0; bit_num < 8; bit_num++)
  {
    if ((0x80 >> bit_num) & value)
    {
      reversed_value |= (1 << bit_num);
    }
  }

  return reversed_value;
}

