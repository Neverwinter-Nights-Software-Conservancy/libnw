#include	<config.h>
#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#if HAVE_UNISTD_H
#include	<unistd.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include	<memory.h>
# endif
# include	<string.h>
#endif
#include	"v.h"
#include	"xref.h"
#include	"bin.h"

struct v* xrefs = 0;

extern char* MyName;

int find_xref(char* name)
{
	int i;

	if (!xrefs)
		xrefs = vnew(1);
	for (i = vlen(xrefs) - 1; i >= 0; --i)
	{
		struct xref* xp = vsubig(xrefs, i);

		if (!xp)
			continue;
		if (strcmp(xp->name, name) == 0)
			return i;
	}
	return i;
}

int add_xref(char* name)
{
	int i;

	i = find_xref(name);
	if (i < 0)
	{
		struct xref* xp = malloc(sizeof *xp);

		if (!xp)
		{
			fprintf(stderr, "%s: Can't allocate xref for <%s>!\n",
				MyName, name);
			return -1;
		}
		xp->name = strdup(name);
		xp->refers_to = vnew(1);
		xp->referd_by = vnew(1);
		vapp(xrefs, xp);
		i = find_xref(name);
	}
	return i;
}

void refers_to(char* referer, char* referee)
{
	int er = add_xref(referer);
	int ee = add_xref(referee);
	struct xref* erp = vsubig(xrefs, er);
	struct xref* eep = vsubig(xrefs, ee);
	int i;

	/* erp refers to eep: add eep to erp->refers_to */
	i = -1;
	if (erp && erp->refers_to)
	{
		for (i = vlen(erp->refers_to) - 1; i >= 0; --i)
		{
			if (strcmp(referee, vsubig(erp->refers_to, i)) == 0)
				break;
		}
	}
	if (i < 0)
		vapp(erp->refers_to, eep->name);

	/* erp refers to eep: add erp to eep->referd_by */
	i = -1;
	if (eep->referd_by)
	{
		for (i = vlen(eep->referd_by) - 1; i >= 0; --i)
		{
			if (strcmp(referer, vsubig(eep->referd_by, i)) == 0)
				break;
		}
	}
	if (i < 0)
		vapp(eep->referd_by, erp->name);
}

int qscomp(const void* aa, const void* ab)
{
	char* a = *(char**) aa;
	char* b = *(char**) ab;

	if (a == b)
		return 0;
	if (a && !b)
		return -1;
	if (!a && b)
		return 1;
	return (-strcmp((char*) a, (char*) b));
}

void show_xref()
{
	int i;

	for (i = vlen(xrefs) - 1; i >= 0; --i)
	{
		struct xref* xp = vsubig(xrefs, i);
		int j;

		if (!xp)
			continue;
		if (xp->refers_to && vlen(xp->refers_to) > 0)
		{
			printf("%s refers to:\n", xp->name);
			qsort(xp->refers_to->p, xp->refers_to->n, sizeof (char*), qscomp);
			for (j = vlen(xp->refers_to) - 1; j >= 0; --j)
			{
				char* cp = vsubig(xp->refers_to, j);
				char* tossme;
				int tossme2 = 0;

				if (!cp)
					continue;
				if (access(cp, 0) == 0)
					printf("\t%s (local)\n", cp);
				else
				{
					tossme = ext_file(cp, &tossme2);
					if (tossme)
					{
						printf("\t%s (base)\n", cp);
						free(tossme);
					}
					else
						printf("\t%s (?)\n", cp);
				}
			}
		}
	}
}
