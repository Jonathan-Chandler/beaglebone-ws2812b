#ifndef __DEBUG_H__
#define __DEBUG_H__
#include <stdio.h>

//#define DEBUG_ENABLED 1

#if DEBUG_ENABLED
  #define printDebug(dbg_message) do { \
    printf("%s::%d::%s::ERROR - ",__FILE__,__LINE__,__func__); \
    printf(dbg_message); \
  } while (0)
#else
  #define printDebug(dbg_message)
#endif

typedef enum 
{
  ERROR_NONE,
  ERROR_BAD_PARAMETER,
  ERROR_COUNT
} ERROR_T;

#endif //__DEBUG_H__
