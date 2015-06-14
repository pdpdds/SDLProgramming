#ifndef UTIL_H
#define UTIL_H

#include <Windows.h>
#include <stdint.h> // portable: uint64_t   MSVC: __int64 


int gettimeofday(struct timeval * tp, struct timezone * tzp);

#endif