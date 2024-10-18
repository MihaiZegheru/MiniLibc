// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	for (char *it = destination; *source != '\0'; ++it, ++source)
		*it = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *it = destination;
	for (; len > 0 && *source != '\0'; --len, ++source, ++it)
	{
		*it = *source;
	}
	while (len--) {
		*it++ = 0; 
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{	
	char *it = destination;
	while (*it++ != '\0');
	*it--;
	while (*source != '\0')
	{
		*it++ = *source++;
	}
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *it = destination;
	while (*it++ != '\0');
	it--;
	while (*source != '\0' && len--)
	{
		*it++ = *source++;
	}
	*it = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && (*str1 == *str2)) {
		str1++, str2++;
	}
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (--len && *str1 != '\0' && (*str1 == *str2)) {
		str1++, str2++;
	}
	return *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	return source;
}
