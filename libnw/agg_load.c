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
#include	<ctype.h>
#if HAVE_GETOPT_H
#include	<getopt.h>
#endif
#include	"global.h"
#include	"gamedir.h"
#include	"key.h"
#include	"agg.h"
#include	"restyp.h"
#include	"are.h"
#include	"object.h"

void* agg_res_load(char* aggname, char* resname, int* size)
{
	FILE* fp;
	struct nwn_agg_toc* toc;
	unsigned rtype;
	void* rp = 0;
	char* cp;
	int i;

	if (size)
		*size = 0;

	toc = agg_toc_load(aggname, 0);
	if (!toc)
	{
		fprintf(stderr, "%s: Can't load <%s>!\n", MyName, aggname);
		return rp;
	}

	/* convert resname to resref + type */
	cp = strchr(resname, '.');
	if (!cp)
	{
		fprintf(stderr, "%s: resname <%s> has no type!\n", MyName, resname);
		agg_toc_delete(toc);
		return rp;
	}
	*cp = '\0';
	rtype = ext2typ(cp + 1);
	for (i = 0; i < toc->head->rescnt; ++i)
	{
		struct nwn_agg_resc* adp;

		adp = vsubig(toc->rescs, i);
		if (adp->type == rtype && strncmp(resname, adp->name, sizeof adp->name) == 0)
		{
			struct nwn_agg_so* sop;

			*cp = '.';
			sop = vsubig(toc->szofs, adp->index);
			rp = malloc(sop->siz);
			if (!rp)
			{
				fprintf(stderr, "%s: Can't allocate %ld for <%s>!\n",
					MyName, sop->siz, resname);
				agg_toc_delete(toc);
				return rp;
			}
			fp = fopen(aggname, "rb");
			if (!fp)
			{
				fprintf(stderr, "%s: Can't reopen <%s> for reading!\n",
					MyName, aggname);
				agg_toc_delete(toc);
				free(rp);
				rp = 0;
				return rp;
			}
			fseek(fp, sop->off, SEEK_SET);
			if (fread(rp, sop->siz, 1, fp) != 1)
			{
				fprintf(stderr, "%s: Can't read from <%s>!\n", MyName, aggname);
				agg_toc_delete(toc);
				free(rp);
				rp = 0;
				return rp;
			}
			fclose(fp);
			*size = sop->siz;
			break;
		}
	}
	return rp;
}
