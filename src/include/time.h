/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
#include <internal/essentials.h>

struct timespec
{
    long sec;
    long nsec;
};

unsigned int sleep(unsigned int size);
int nanosleep(const struct timespec *duration, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
