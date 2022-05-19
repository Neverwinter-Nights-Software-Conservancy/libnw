/* v.c:
**	elementary (correct, not necessarily fast) C code to implement a
**	vector of pointers.  (Yes, this is more easily written in C++.)
**	These are only the functions needed for the task at hand; they
**	will be supplemented as needs arise.
*/

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
#include	"v.h"

#define	V_INIT	2	/* how many slots to start with */
#define	V_INCR	2	/* how many slots to grow */

static const struct v nullv =
{
	0, 0, 0
};

void* vsubig(struct v* vp, int i)
{
	if (!vp || i >= vp->n)
		return 0;
	if (i < 0)
		return 0;
	return vp->p[i];
}

void vsubip(struct v* vp, int i, void* p)
{
	if (!vp || i >= vp->n)
		return;
	if (i < 0)
		return;
	vp->p[i] = p;
}

int vlen(struct v* vp)
{
	return vp ? vp->n : 0;
}

int vapp(struct v* vp, void* ep)
{
	void** newp;

	/* easy case: vp->p is already big enough */
	if (vp->x > vp->n)
	{
		vp->p[vp->n++] = ep;
		return 1;
	}

	/* check for first append */
	if (vp->x == 0)
	{
		vp->p = (void**) malloc(V_INIT * sizeof (void*));
		if (!vp->p)
		{
			abort();
			return 0;
		}
		vp->x = V_INIT;
		vp->p[vp->n++] = ep;
		return 1;
	}

	/* must grow vp->p */
	newp = (void**) malloc((vp->x + V_INCR) * sizeof (void*));
	if (!newp)
	{
		abort();
		return 0;
	}
	memcpy((void*) &newp[0], (void*) &vp->p[0], vp->x * sizeof (void*));
	if (vp->p)
		free(vp->p);
	vp->p = newp;
	vp->x += V_INCR;
	vp->p[vp->n++] = ep;
	return 1;
}

struct v* vnew(int i)
{
	struct v* vp;
	void** newp;

	vp = (struct v*) malloc(sizeof (struct v));
	if (!vp)
	{
		abort();
		return vp;
	}
	*vp = nullv;
	if (i)
	{
		newp = (void**) malloc(i * sizeof (void*));
		if (!newp)
		{
			abort();
		}
		vp->p = newp;
		vp->x = i;
		memset(vp->p, i * sizeof (void*), 0);
	}
	return vp;
}

void nwvfree(struct v* vp)
{
	if (vp->p)
	{
		free(vp->p);
		vp->p = 0;
	}
	vp->x = 0;
	vp->n = 0;
	free(vp);
}

void vsort(struct v* vp, int(*compar)(const void*, const void*))
{
	int nmemb = vlen(vp);

	qsort(vp->p, nmemb, sizeof (void**), compar);
}

void* vbsearch(const void* kp, struct v* vp, int(*compar)(const void*, const void*))
{
	int nmemb = vlen(vp);

	return bsearch(&kp, vp->p, nmemb, sizeof (void**), compar);
}
