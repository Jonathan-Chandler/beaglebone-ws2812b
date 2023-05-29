#ifndef __UTIL_H__
#define __UTIL_H__
#include <stdint.h>

#define BIT(a)			(1U << (a))

#define BIT_MASK(a, b)	((a < b) ? \
		(((unsigned) -1 >> (31 - (b))) & ~((1U << (a)) - 1)) : (((unsigned) -1 >> (31 - (a))) & ~((1U << (b)) - 1)))


//int msleep(long msec);
uint32_t reverse_8bit(uint32_t value);

#endif // __UTIL_H__
