#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <stdio.h>

#define DEBUG_PRINT_REG 1
//#define DEBUG_ENABLED 1

#if DEBUG_ENABLED
  #define report_log(...) do { \
    printf("%s::%d::%s::LOG::",__FILE__,__LINE__,__func__); \
    printf(__VA_ARGS__); \
  } while (0)
#else
  #define report_log(...)   do {} while(0)
#endif

#define report_error(...) do { \
  printf("%s::%d::%s::ERROR::",__FILE__,__LINE__,__func__); \
  printf(__VA_ARGS__); \
} while (0)

#endif //__DEBUG_H__
