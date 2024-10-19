// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{	
	char *it = destination;
	while (*source)
		*it++ = *source++;
	*it = 0;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *it = destination;
	while (*source && len) {
		*it++ = *source++;
		len--;
	}
	*it = *source;
	while (len--)
		*it++ = 0; 
	return destination;
}

char *strcat(char *destination, const char *source)
{	
	char *it = destination;
	while (*it)
		it++;
	while (*source)
		*it++ = *source++;
	*it = 0;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *it = destination;
	while (*it)
		it++;
	while (*source && len--)
		*it++ = *source++;
	*it = 0;
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
		str1++, str2++;
	return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (--len && *str1 != '\0' && (*str1 == *str2))
		str1++, str2++;
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
	while(*str)
	{
		if (*str == c)
			break;
		str++;
	}
	return *str == c ? str : NULL;
}

char *strrchr(const char *str, int c)
{
	char *r = NULL;
	while(*str)
	{
		r = *str == c ? str : r;
		str++;
	}
	return r;
}

char *strstr(const char *haystack, const char *needle)
{
	char *n_it;
	char *h_it;
	while (*haystack)
	{
		h_it = haystack;
		n_it = needle;
		while (*h_it && *h_it == *n_it)
			h_it++, n_it++;
		if (!*n_it)
			return haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *n_it;
	char *h_it;
	char *r = NULL;
	while (*haystack)
	{
		h_it = haystack;
		n_it = needle;
		while (*h_it && *h_it == *n_it)
			h_it++, n_it++;
		if (!*n_it)
			r = haystack;
		haystack++;
	}
	return r;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *it = destination;
	while (num--)
		*it++ = *(char*)source++;
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *it = destination;
	while (num--)
		*(char*)it++ = *(char*)source++;
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	while (--num && *(char*)ptr1 && (*(char*)ptr1 == *(char*)ptr2))
		(char*)ptr1++, (char*)ptr2++;
	return *(char*)ptr1 - *(char*)ptr2;
}

void *memset(void *source, int value, size_t num)
{
	while(num--)
		*(char*)source++ = (unsigned char)value;
	return source;
}
