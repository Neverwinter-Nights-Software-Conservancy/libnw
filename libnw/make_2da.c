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
#include	"global.h"
#include	"2da.h"
#include	"restyp.h"
#include	"bin.h"
#include	"str.h"
#include	"key.h"
#include	"v.h"

void free_2da(struct v* vp)
{
	struct v* vrp;
	int i;

	for (i = 0; i < vlen(vp); ++i)
	{
		vrp = vsubig(vp, i);
		nwvfree(vrp);
		vsubip(vp, i, 0);
	}
	nwvfree(vp);
}

struct v* bin22da(void* res, int length)
{
	char* raw = (char*) res;
	char* cp;
	int i;
	int j;
	struct v* strs;
	struct v* r = 0;
	int headrow;
	int nrows;
	int ncols;
	int irow;
	int orow;

	/* is it really a 2DA? */
	if (strncmp(raw, "2DA V2.0", 8))
	{
		fprintf(stderr, "%s: bin22da(): Signature/Version mismatch [%-.8s] in 2DA!\n",
			MyName, raw);
		return r;
	}

	/* make an array of lines (no line termination) */
	strs = str2arr(raw, length);

	/* kill trailing blanks on each line */
	for (i = 0; i < vlen(strs); ++i)
	{
		cp = vsubig(strs, i);
		for (j = strlen(cp) - 1; j >= 0; --j)
		{
			if (cp[j] == ' ' || cp[j] == '\t')
				cp[j] = '\0';
			else
				break;
		}
	}
	/* save last row count */
	nrows = i;

	/* find 1st line of data (column headers) */
	for (i = 1; i < vlen(strs); ++i)
	{
		cp = vsubig(strs, i);
		if (cp && cp[0])
			break;
	}

	/* did we find any data? */
	if (i >= vlen(strs))
	{
		fprintf(stderr, "%s: bin22da(): Empty 2DA?\n", MyName);
		return r;
	}

	/* adjust for skipped rows + header */
	nrows -= i;
	headrow = i;

	/* now we can allocate array */
	r = vnew(nrows);
	if (!r)
	{
		fprintf(stderr, "%s: bin22da(): Can't allocate %d row ptrs for 2DA!\n",
			MyName, nrows);
		return r;
	}

	/* find out how many columns there are */
	ncols = 1;
	cp = vsubig(strs, headrow);
	while (*cp)
	{
		while (*cp && (*cp == ' ' || *cp == '\t'))
			++cp;
		while (*cp && *cp != ' ' && *cp != '\t')
			++cp;
		++ncols;
	}

	/* finally, we can fill in elements */
	for (irow = 0, orow = 0; irow < nrows; ++irow, ++orow)
	{
		struct v* vrp = vnew(ncols);

		/* get next row */
		cp = vsubig(strs, irow + headrow);

		/* but advance to next non-blank row */
		while (cp && strlen(cp) == 0)
			cp = vsubig(strs, ++irow + headrow);
		/* bail out if the last row is blank */
		if (irow >= nrows)
			break;

		/* fill in each element */
		for (j = 0; j < ncols; ++j)
		{
			char* sp = cp;
			char* t;

			while (*sp && *sp != ' ' && *sp != '\t')
				++sp;
			t = malloc(1 + (sp - cp));
			if (!t)
			{
				fprintf(stderr, "%s(%s): Can't allocate element (%d) @[%d,%d] for 2DA!\n",
					MyName, "make_2da", 1 + (sp - cp), orow, j);
				free_2da(r);
				return 0;
			}
			strncpy(t, cp, sp - cp);
			t[sp - cp] = '\0';
			vapp(vrp, t);
			cp = sp + (*sp ? 1 : 0);
			while (*cp && (*cp == ' ' || *cp == '\t'))
				++cp;
		}
		vapp(r, vrp);
	}

	nwvfree(strs);
	return r;
}
