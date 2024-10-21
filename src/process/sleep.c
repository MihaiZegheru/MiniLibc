#include <time.h>
#include <internal/syscall.h>
#include <stdlib.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec duration = {.sec = seconds, .nsec = 0};
    struct timespec rem;

    return nanosleep(&duration, &rem);
}
