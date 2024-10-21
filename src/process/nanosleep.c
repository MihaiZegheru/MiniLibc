#include <time.h>
#include <internal/syscall.h>
#include <stdlib.h>

int nanosleep(const struct timespec *duration, struct timespec *rem)
{
	return syscall(__NR_nanosleep, duration, rem);
}
