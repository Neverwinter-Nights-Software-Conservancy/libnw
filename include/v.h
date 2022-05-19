#ifndef	_MJS_NWN_V_H_
#define	_MJS_NWN_V_H_

/*! \file v.h
	\brief routines to manipulate an extensible array of pointers.

	These are elementary (correct, not necessarily fast) C routines
	to implement an extensible vector of pointers.	(Yes, this is more
	easily written in C++.)
 */

/*! \struct v v.h <libnw/v.h>
	\brief internal representation of an extensible array of pointers.
	Do *NOT* use directly except in v.c (or here, for "inlined" versions).
*/
struct v
{
	int n;		/**< how many slots are occupied */
	int x;		/**< how many slots are allocated */
	void** p;	/**< the slots */
};

/**
 * create a new vector with initial size \a i; returns 0 on error.
 */
extern struct v* vnew(int i);

/**
 * free storage used by vector \a vp.
 */
extern void nwvfree(struct v* vp);

/**
 * returns the number of occupied slots in vector \a vp.
 */
#if _LIBNW_INLINE_
// conditional provides minimal protection
#define	vlen(x)	((x) ? (x)->n : 0)
#else
extern int vlen(struct v* vp);
#endif

/**
 * appends element \a v to vector \a vp.
 */
extern int vapp(struct v* vp, void* v);

/**
 * returns the \a ith element of vector \a vp.
 */
#if _LIBNW_INLINE_
// conditional provides minimal protection
#define	vsubig(x,i)	((x) ? (x)->p[i] : 0)
#else
extern void* vsubig(struct v* vp, int i);
#endif

/**
 * replaces the \a ith element of vector \a vp with \a v.
 */
#if _LIBNW_INLINE_
#define	vsubip(x,i,y)	((x)->p[i] = (y))
#else
extern void vsubip(struct v* vp, int i, void* v);
#endif

/**
 * sorts the elements of vector \a vp according to the ordering defined by
 * \a compar (using qsort()).
 */
extern void vsort(struct v* vp, int(*compar)(const void*, const void*));

/**
 * performs a binary search for element \a kp in vector \a vp according to
 * the ordering defined by \a compar (using bsearch()).
 */
void* vbsearch(const void* kp, struct v* vp, int(*compar)(const void*, const void*));

#endif
