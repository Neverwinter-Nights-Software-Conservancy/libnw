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
#include	<ctype.h>
#include	"v.h"
#include	"agg.h"
#include	"mod.h"
#include	"erf.h"
#include	"hak.h"
#include	"restyp.h"

extern char* MyName;

void agg1dump(char* fname, long off, int dump)
{
	FILE* ifp;
	int i;
	int len;
	struct nwn_agg_toc* toc = agg_toc_load(fname, off);

	if (!toc)
		return;

	if (toc->descs && ((len = vlen(toc->descs)) > 0))
	{
		for (i = 0; i < len; ++i)
		{
			struct nwn_agg_desc* dp = vsubig(toc->descs, i);

			printf("LANG[%ld]:%s\n", dp->lang, dp->desc);
		}
	}

	ifp = fopen(fname, "rb");

	for (i = 0; i < toc->head->rescnt; ++i)
	{
		struct nwn_agg_resc* rp = vsubig(toc->rescs, i);
		struct nwn_agg_so* sp = vsubig(toc->szofs, i);
		const char* t = typ2ext(rp->type);
		char* f = 0;
		
		if (strcmp(t, "???") == 0)
		{
			f = malloc(9);
			sprintf(f, "%.8lx", rp->type);
			fprintf(stderr, "%s: Warning: Unknown resource type (%s)!\n",
				MyName, f);
		}
		else
			f = strdup(t);
		if (dump)
		{
			FILE* ofp;
			char name[26];
			char* buf;
			int j;

			sprintf(name, "%-.16s.%s", rp->name, f);
			/* extracted resource files are always in lower case */
			for (j = strlen(name); j >= 0; --j)
				name[j] = tolower(name[j]);
			ofp = fopen(name, "wb");
			if (!ofp)
			{
				fprintf(stderr, "%s: Can't create <%s>!\n", MyName, name);
				if (f)
					free(f);
				continue;
			}
			buf = malloc(sp->siz);
			if (!buf)
			{
				fprintf(stderr, "%s: Can't allocate %ld for <%s>!\n",
					MyName, sp->siz, name);
				fclose(ofp);
				if (f)
					free(f);
				continue;
			}
			fseek(ifp, sp->off, SEEK_SET);
			if (fread(buf, sp->siz, 1, ifp) != 1)
			{
				fprintf(stderr, "%s: Can't read %ld at 0x%.8lx for <%s>!\n",
					MyName, sp->siz, sp->off, name);
				free(buf);
				fclose(ofp);
				if (f)
					free(f);
				continue;
			}
			if (fwrite(buf, sp->siz, 1, ofp) != 1)
			{
				fprintf(stderr, "%s: Can't write %ld for <%s>!\n",
					MyName, sp->siz, name);
				free(buf);
				fclose(ofp);
				if (f)
					free(f);
				continue;
			}
			free(buf);
			fclose(ofp);
		}
		else
		{
			printf("%-16.16s %-8.8s %10ld 0x%.8lx\n",
				rp->name, t, sp->siz, sp->off);
		}
		if (f)
			free(f);
	}

	agg_toc_delete(toc);

	fclose(ifp);
}
