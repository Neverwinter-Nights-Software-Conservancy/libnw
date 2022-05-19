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
#include	<memory.h>
#include	"v.h"
#include	"agg.h"
#include	"mod.h"
#include	"erf.h"
#include	"hak.h"
#include	"restyp.h"
#if WORDS_BIGENDIAN
#include	"bendian.h"
#endif

extern char* MyName;

// extract the TOC of a single ERF/HAK/MOD file.

void agg_toc_delete(struct nwn_agg_toc* tp)
{
	if (!tp)
		return;
	if (tp->head)
	{
		free(tp->head);
		tp->head = 0;
	}
	if (tp->descs)
	{
		int i = vlen(tp->descs);
		struct nwn_agg_desc* dp;

		while (--i >= 0)
		{
			dp = vsubig(tp->descs, i);
			if (dp)
			{
				if (dp->desc)
				{
					free(dp->desc);
					dp->desc = 0;
				}
				free(dp);
			}
		}
		free(tp->descs);
		tp->descs = 0;
	}
	if (tp->rescs)
	{
		int i = vlen(tp->rescs);
		struct nwn_agg_resc* rp;

		while (--i >= 0)
		{
			rp = vsubig(tp->rescs, i);
			if (rp)
				free(rp);
		}
		free(tp->rescs);
		tp->rescs = 0;
	}
	if (tp->szofs)
	{
		int i = vlen(tp->szofs);
		struct nwn_agg_so* sp;

		while (--i >= 0)
		{
			sp = vsubig(tp->szofs, i);
			if (sp)
				free(sp);
		}
		free(tp->szofs);
		tp->szofs = 0;
	}
	free(tp);
}

struct nwn_agg_toc* agg_toc_load(const char* fname, long off)
{
	FILE* ifp;
	int i;
	struct nwn_agg_toc* tp = 0;
	struct nwn_agg* hp = 0;

	ifp = fopen(fname, "rb");
	if (!ifp)
	{
		fprintf(stderr, "%s: Can't open <%s> for reading!\n", MyName, fname);
		return tp;
	}

	/* file is good, so let's allocate space for header */
	hp = malloc(sizeof *hp);
	if (!hp)
	{
		fprintf(stderr, "%s: Can't allocate HEAD for <%s>!\n", MyName, fname);
		fclose(ifp);
		return tp;
	}

	/* let's get the header */
	if (fread((void*) hp, sizeof *hp, 1, ifp) != 1)
	{
		fprintf(stderr, "%s: Can't read ERF/HAK/MOD header from <%s>!\n",
			MyName, fname);
		free(hp);
		fclose(ifp);
		return tp;
	}

	/* got it, so see if we have the right kind of file */
	if (strncmp(hp->signature, HAK_SIGNATURE, sizeof hp->signature) == 0 &&
		strncmp(hp->version, HAK_VERSION, sizeof hp->version) == 0)
		;
	else
	if (strncmp(hp->signature, ERF_SIGNATURE, sizeof hp->signature) == 0 &&
		strncmp(hp->version, ERF_VERSION, sizeof hp->version) == 0)
		;
	else
	if (strncmp(hp->signature, MOD_SIGNATURE, sizeof hp->signature) == 0 &&
		strncmp(hp->version, MOD_VERSION, sizeof hp->version) == 0)
		;
	else
	{
		fprintf(stderr, "%s: ERF/HAK/MOD signature (%-.4s) or version (%-.4s) invalid in <%s>!\n",
			MyName, hp->signature, hp->version, fname);
		free(hp);
		fclose(ifp);
		return tp;
	}

#if WORDS_BIGENDIAN
	be2leul(&hp->hasdesc);
	be2leul(&hp->desclen);
	be2leul(&hp->rescnt);
	be2leul(&hp->descoff);
	be2leul(&hp->tocoff);
	be2leul(&hp->locoff);
#endif

	/* we have a (probably) valid file, so let's allocate the return value */
	tp = malloc(sizeof *tp);
	if (!tp)
	{
		fprintf(stderr, "%s: Can't allocate TOC for <%s>!\n", MyName, fname);
		free(hp);
		fclose(ifp);
		return tp;
	}
	memset(tp, '\0', sizeof *tp);

	/* stash the header away */
	tp->head = hp;

	/* fill in the description block, if we have one */
	if (hp->hasdesc)
	{
		long descread = 0;
		struct nwn_agg_desc* dp;

		/* we have at least 1 description; let's get 'em */
		tp->descs = vnew(1);
		fseek(ifp, hp->descoff, SEEK_SET);
		while (descread < hp->desclen && (descread + hp->descoff) < hp->tocoff)
		{
			dp = malloc(sizeof *dp);
			if (!dp)
			{
				fprintf(stderr, "%s: Can't allocate DESC for <%s>!\n",
					MyName, fname);
				agg_toc_delete(tp);
				fclose(ifp);
				return 0;
			}
			if (fread((void*) &dp->lang, sizeof dp->lang, 1, ifp) != 1)
			{
				fprintf(stderr, "%s: Can't read desc's language in <%s>!\n",
					MyName, fname);
				free(dp);
				agg_toc_delete(tp);
				fclose(ifp);
				return 0;
			}
#if WORDS_BIGENDIAN
			be2leul(&dp->lang);
#endif
			if (fread((void*) &dp->len, sizeof dp->len, 1, ifp) != 1)
			{
				fprintf(stderr, "%s: Can't read desc's length in <%s>!\n",
					MyName, fname);
				free(dp);
				agg_toc_delete(tp);
				fclose(ifp);
				return 0;
			}
#if WORDS_BIGENDIAN
			be2leul(&dp->len);
#endif
			dp->desc = malloc(1 + dp->len);
			if (!dp->desc)
			{
				fprintf(stderr, "%s: Can't allocate desc (%ld) in <%s>!\n",
					MyName, dp->len, fname);
				free(dp);
				agg_toc_delete(tp);
				fclose(ifp);
				return 0;
			}
			if (dp->len)
			{
				if (fread((void*) dp->desc, dp->len, 1, ifp) != 1)
				{
					fprintf(stderr, "%s: Can't read desc's text (len: %ld) in <%s>!\n",
						MyName, dp->len, fname);
					free(dp->desc);
					free(dp);
					agg_toc_delete(tp);
					fclose(ifp);
					return 0;
				}
			}
			dp->desc[dp->len] = '\0';
			vapp(tp->descs, dp);
			descread += (sizeof dp->lang) + (sizeof dp->len) + dp->len;
		}
	}

	/* now get the resource descriptor block */
	fseek(ifp, hp->tocoff, SEEK_SET);

	/* allocate space for the resource block */
	tp->rescs = vnew(hp->rescnt);

	/* and get 'em */
	for (i = 0; i < hp->rescnt; ++i)
	{
		struct nwn_agg_resc* rp = malloc(sizeof *rp);

		if (!rp)
		{
			fprintf(stderr, "%s: Can't allocate RBLK for <%s>!\n",
				MyName, fname);
			agg_toc_delete(tp);
			fclose(ifp);
			return 0;
		}
		if (fread((void*) rp, sizeof *rp, 1, ifp) != 1)
		{
			fprintf(stderr, "%s: Can't read resource descriptor[%d] in <%s>!\n",
				MyName, i, fname);
			free(rp);
			agg_toc_delete(tp);
			fclose(ifp);
			return 0;
		}
#if	WORDS_BIGENDIAN
		be2leul(&rp->index);
		be2leus(&rp->type);
#endif
		vapp(tp->rescs, rp);
	}

	/* now get the resource location block */
	fseek(ifp, hp->locoff, SEEK_SET);

	/* allocate space for the szof block */
	tp->szofs = vnew(hp->rescnt);

	/* and get 'em */
	for (i = 0; i < hp->rescnt; ++i)
	{
		struct nwn_agg_so* sp = malloc(sizeof *sp);

		if (!sp)
		{
			fprintf(stderr, "%s: Can't allocate SZOF for <%s>!\n",
				MyName, fname);
			agg_toc_delete(tp);
			fclose(ifp);
			return 0;
		}
		if (fread((void*) sp, sizeof *sp, 1, ifp) != 1)
		{
			fprintf(stderr, "%s: Can't read SZOF [%d] in <%s>!\n",
				MyName, i, fname);
			free(sp);
			agg_toc_delete(tp);
			fclose(ifp);
			return 0;
		}
#if	WORDS_BIGENDIAN
		be2leul(&sp->off);
		be2leul(&sp->siz);
#endif
		vapp(tp->szofs, sp);
	}
	fclose(ifp);
	return tp;
}
