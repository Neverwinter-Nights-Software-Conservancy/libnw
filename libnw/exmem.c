#include	<config.h>
#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include	<memory.h>
# endif
# include	<string.h>
#endif
#if HAVE_MALLOC_H
#include	<malloc.h>
#endif
#include	"global.h"
#include	"exmem.h"

struct exmem* exmem_new(int size)
{
	struct exmem* mp;

	mp = malloc(sizeof *mp);
	if (!mp)
	{
		fprintf(stderr, "%s: Can't allocate an exmem!\n", MyName);
		return 0;
	}
	memset(mp, 0, sizeof *mp);

	if (size < 1024)
		size = 1024;

	mp->mem = malloc(size);
	if (!mp->mem)
	{
		fprintf(stderr, "%s: Can't allocate %d for exmem!\n", MyName, size);
		free(mp);
		return 0;
	}
	mp->len = size;
	return mp;
}

int exmem_push(struct exmem* mp, char* bytes, int size)
{
	if (!mp)
		abort();
	if (!mp->mem)
		abort();
	if ((mp->used + size) < mp->len)
	{
		char* m = malloc(mp->used + size);

		if (!m)
		{
			fprintf(stderr, "%s: Can't reallocate %d for exmem!\n", MyName, mp->used + size);
			return 0;
		}
		memcpy(m, mp->mem, mp->used);
		memset(&m[mp->used], 0, size);
		free(mp->mem);
		mp->mem = m;
		mp->len = mp->used + size;
	}
	memcpy(&mp->mem[mp->used], bytes, size);
	mp->used += size;
	return 1;
}

int exmem_pop(struct exmem* mp, char* bytes, int size)
{
	if (!mp)
		abort();
	if (!mp->mem)
		abort();
	if (size > mp->used)
	{
		fprintf(stderr, "%s: exmem underflow!\n", MyName);
		return 0;
	}
	memcpy(bytes, &mp->mem[mp->used - size], size);
	mp->used -= size;
	return 1;
}

void exmem_del(struct exmem* mp)
{
	if (!mp)
		abort();
	if (!mp->mem)
		return;
	free(mp->mem);
	mp->len = 0;
	mp->used = 0;
}

int exmem_len(struct exmem* mp)
{
	if (!mp)
		abort();
	return mp->len;
}
