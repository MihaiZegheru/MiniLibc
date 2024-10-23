#include <stdio.h>
#include <internal/io.h>
#include <string.h>

int puts(const char* str)
{
    if (write(1, str, strlen(str)) == -1)
        return -1;
    const char nl = '\n';
    if (write(1, &nl, 1) == -1)
        return EOF;
    return 0;
}
