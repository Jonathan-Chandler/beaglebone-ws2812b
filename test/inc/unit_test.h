#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__
#include <stdio.h>

#define ASSERT_EQUAL(a, b) do { \
  if (a != b) \
  { \
    printf("%s::%d::%s::Assert failed\n",__FILE__,__LINE__,__func__); \
    return -1; \
  } \
} while(0)

#define ASSERT_NOT_EQUAL(a, b) do { \
  if (a == b) \
  { \
    printf("%s::%d::%s::Assert failed\n",__FILE__,__LINE__,__func__); \
    return -1; \
  } \
} while(0)

#endif
