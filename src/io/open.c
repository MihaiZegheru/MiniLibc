// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	int fd = syscall(2, filename, flags);
	if (fd < 0)
	{
		errno = -fd;
		return -1;
	}
	return 0;
}
