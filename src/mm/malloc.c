// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

void *malloc(size_t size)
{
	void *block = mmap(NULL, size, PROT_READ | PROT_WRITE,
					   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (block == MAP_FAILED)
		return NULL;
	if (mem_list_add(block, size) < 0) {
		munmap(block, size);
		return NULL;
	}
	return block;
}

void *calloc(size_t nmemb, size_t size)
{
	void *block = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE,
					   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (block == MAP_FAILED)
		return NULL;
	if (mem_list_add(block, size) < 0) {
		munmap(block, nmemb * size);
		return NULL;
	}
	size_t len = nmemb * size;
	for (char *it = block; len; len--)
		*it = 0;
	return block;
}

void free(void *ptr)
{
	struct mem_list *item = mem_list_find(ptr);
	munmap(ptr, item->len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	if (!ptr)
		return malloc(size);
	if (!size)
	{
		free(ptr);
		return NULL;
	}

	struct mem_list *item = mem_list_find(ptr);
	if (!item)
		return ptr;

	void *block = mremap(ptr, item->len, size, MREMAP_MAYMOVE);
	if (block == MAP_FAILED)
		return ptr;

	if (block != ptr)
	{
		memcpy(block, ptr, MIN(item->len, size));
		munmap(ptr, item->len);
	}
	item->start = block;
	item->len = size;
	return block;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (nmemb * size > SIZE_MAX)
	{
		errno = ENOMEM;
		return NULL;
	}
	return realloc(ptr, nmemb * size);
}
