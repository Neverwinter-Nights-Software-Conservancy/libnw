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
#if TIME_WITH_SYS_TIME
# include	<sys/time.h>
# include	<time.h>
#else
# if HAVE_SYS_TIME_H
#  include	<sys/time.h>
# else
#  include	<time.h>
# endif
#endif
#include	"global.h"
#include	"restyp.h"
#include	"v.h"
#include	"agg.h"
#include	"mod.h"
#include	"erf.h"
#include	"hak.h"
#include	"bendian.h"

/* this is apparently magic... */
#define	MAGIC_DESC_OFF	(0xa0)

static void show_toc(char* fname, struct nwn_agg_toc* toc)
{
	int i;

	if (toc->head)
	{
		printf("Sig: [%4.4s]\n", toc->head->signature);
		printf("Ver: [%4.4s]\n", toc->head->version);
		printf("hasdesc: %ld\n", toc->head->hasdesc);
		printf("desclen: %ld\n", toc->head->desclen);
		printf("rescnt: %ld\n", toc->head->rescnt);
		printf("descoff: 0x%.8lx\n", toc->head->descoff);
		printf("tocoff: 0x%.8lx\n", toc->head->tocoff);
		printf("locoff: 0x%.8lx\n", toc->head->locoff);
		printf("BuildYear: 0x%.8lx\n", toc->head->buildyear);
		printf("BuildDay: 0x%.8lx\n", toc->head->buildday);

		if (toc->rescs && toc->szofs)
		{
			for (i = 0; i < toc->head->rescnt; ++i)
			{
				struct nwn_agg_resc* rp = vsubig(toc->rescs, i);
				struct nwn_agg_so* sp = vsubig(toc->szofs, i);
				const char* t = typ2ext(rp->type);
				char* f = 0;
				
				if (strcmp(t, "???") == 0)
				{
					f = malloc(9);
					sprintf(f, "%.8x", rp->type);
					fprintf(stderr, "%s: Warning: Unknown RES type (%s)!\n",
						MyName, f);
				}
				else
					f = strdup(t);
				printf("%-16.16s %-8.8s %10ld 0x%.8lx\n",
					rp->name, t, sp->siz, sp->off);
				if (f)
					free(f);
			}
		}
	}
}

int agg_create(char** argv, int type)
{
	struct nwn_agg_toc* toc;
	char* fname = *argv++;
	FILE* ofp;
	int i;
	unsigned long nextoff;

	if (!fname)
	{
		fprintf(stderr, "%s: No argument list?\n", MyName);
		return 2;
	}

	/* allocate our version of the TOC info */
	toc = malloc(sizeof *toc);
	if (!toc)
	{
		fprintf(stderr, "%s: Can't allocate TOC for <%s>!\n", MyName, fname);
		return 1;
	}

	/* and the mandatory header */
	toc->head = malloc(sizeof *toc->head);
	if (!toc->head)
	{
		fprintf(stderr, "%s: Can't allocate HEAD for <%s>!\n", MyName, fname);
		agg_toc_delete(toc);
		return 1;
	}

	/* set the signature and version for the type chosen */
	switch (type)
	{
	case 0:	/* module */
		strncpy(toc->head->signature, MOD_SIGNATURE, sizeof toc->head->signature);
		strncpy(toc->head->version, MOD_VERSION, sizeof toc->head->version);
		break;

	case 1:	/* hak pak */
		strncpy(toc->head->signature, HAK_SIGNATURE, sizeof toc->head->signature);
		strncpy(toc->head->version, HAK_VERSION, sizeof toc->head->version);
		break;

	case 2:	/* resource export */
		strncpy(toc->head->signature, ERF_SIGNATURE, sizeof toc->head->signature);
		strncpy(toc->head->version, ERF_VERSION, sizeof toc->head->version);
		break;

	default:	/* oops! */
		fprintf(stderr, "%s: Invalid type in agg_create?!\n", MyName);
		agg_toc_delete(toc);
		return 1;
	}

	/* make sure we can create the file! */
	ofp = fopen(fname, "wb");
	if (!ofp)
	{
		fprintf(stderr, "%s: Can't create <%s>!\n", MyName, fname);
		agg_toc_delete(toc);
		return 1;
	}

	/* count up the resources */
	for (i = 0; argv[i]; ++i)
		;

	/* set the count in the header */
	toc->head->rescnt = i;

	/* set the desc offset as long as we're here */
	toc->head->descoff = MAGIC_DESC_OFF;

	/* since we don't (yet) add descriptions, set tocoff as well */
	toc->head->tocoff = toc->head->descoff;

	/* since we can calculate it, set locoff, too */
	toc->head->locoff = toc->head->tocoff +
		(toc->head->rescnt * sizeof (struct nwn_agg_resc));

	/* allocate resc and szof vectors */
	toc->rescs = vnew(toc->head->rescnt);
	toc->szofs = vnew(toc->head->rescnt);

	/* keep track of data offsets */
	nextoff = toc->head->locoff +
		(toc->head->rescnt * sizeof (struct nwn_agg_so));

	/* now fill in the values */
	for (i = 0; i < toc->head->rescnt; ++i)
	{
		struct nwn_agg_resc* rp;
		struct nwn_agg_so* sp;
		char* dotp;
		FILE* ifp;
		char* buf;

		rp = malloc(sizeof *rp);
		if (!rp)
		{
			fprintf(stderr, "%s: Can't allocate RESC in <%s> for <%s>!\n",
				MyName, fname, argv[i]);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}

		sp = malloc(sizeof *sp);
		if (!sp)
		{
			fprintf(stderr, "%s: Can't allocate SZOF in <%s> for <%s>!\n",
				MyName, fname, argv[i]);
			free(rp);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}

		/* we can calculate offset here */
		sp->off = nextoff;

		/* separate the resource name and extension */
		dotp = strchr(argv[i], '.');
		if (!dotp)
		{
			fprintf(stderr, "%s: Resource <%s> has no extension!\n",
				MyName, argv[i]);
			free(sp);
			free(rp);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}
		*dotp = '\0';
		/* save the name */
		strncpy(rp->name, argv[i], sizeof rp->name);
		/* figure out the extension */
		rp->type = ext2typ(dotp + 1);
		/* set the index */
		rp->index = i;
		/* restore the '.' */
		*dotp = '.';

		/* now get the size */
		ifp = fopen(argv[i], "rb");
		if (!ifp)
		{
			fprintf(stderr, "%s: Can't open resource <%s> for <%s>!\n",
				MyName, fname, argv[i]);
			free(sp);
			free(rp);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}
		fseek(ifp, 0, SEEK_END);
		sp->siz = ftell(ifp);

		/* now read the data */
		fseek(ifp, 0, SEEK_SET);
		buf = malloc(sp->siz);
		if (!buf)
		{
			fprintf(stderr, "%s: Can't allocate buffer (%ld) for resource <%s> for <%s>!\n",
				MyName, sp->siz, argv[i], fname);
			fclose(ifp);
			free(sp);
			free(rp);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}
		if (fread(buf, sp->siz, 1, ifp) != 1)
		{
			fprintf(stderr, "%s: Can't read resource <%s> for <%s>!\n",
				MyName, argv[i], fname);
			free(buf);
			fclose(ifp);
			free(sp);
			free(rp);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}
		fclose(ifp);
		fseek(ofp, sp->off, SEEK_SET);
		if (fwrite(buf, sp->siz, 1, ofp) != 1)
		{
			fprintf(stderr, "%s: Can't write resource <%s> for <%s>!\n",
				MyName, argv[i], fname);
			free(buf);
			free(sp);
			free(rp);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}
		free(buf);
		nextoff += sp->siz;

		vapp(toc->rescs, rp);
		vapp(toc->szofs, sp);
	}

	/* finally, we can write the header */
	fseek(ofp, 0, SEEK_SET);
	/* but set the date in the header first */
	{
		time_t t = time(0);
		struct tm* tp = localtime(&t);
		toc->head->buildyear = tp->tm_year;
		toc->head->buildday = tp->tm_yday;
	}
#if WORDS_BIGENDIAN
	/* prepare for writing */
	be2leul(&toc->head->hasdesc);
	be2leul(&toc->head->desclen);
	be2leul(&toc->head->rescnt);
	be2leul(&toc->head->descoff);
	be2leul(&toc->head->tocoff);
	be2leul(&toc->head->locoff);
	be2leul(&toc->head->buildyear);
	be2leul(&toc->head->buildday);
#endif
	if (fwrite(toc->head, sizeof *toc->head, 1, ofp) != 1)
	{
		fprintf(stderr, "%s: Can't write HEAD for <%s>!\n", MyName, fname);
		fclose(ofp);
		agg_toc_delete(toc);
		return 1;
	}
#if WORDS_BIGENDIAN
	/* restore for use */
	be2leul(&toc->head->hasdesc);
	be2leul(&toc->head->desclen);
	be2leul(&toc->head->rescnt);
	be2leul(&toc->head->descoff);
	be2leul(&toc->head->tocoff);
	be2leul(&toc->head->locoff);
	be2leul(&toc->head->buildyear);
	be2leul(&toc->head->buildday);
#endif

	/* and the toc */
	fseek(ofp, toc->head->tocoff, SEEK_SET);
	for (i = 0; i < toc->head->rescnt; ++i)
	{
		struct nwn_agg_resc* rp = vsubig(toc->rescs, i);

#if WORDS_BIGENDIAN
		/* prepare for writing */
		be2leul(&rp->index);
		be2leus(&rp->type);
#endif
		if (fwrite(rp, sizeof *rp, 1, ofp) != 1)
		{
			fprintf(stderr, "%s: Can't write TOC for <%s>!\n", MyName, fname);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}
#if WORDS_BIGENDIAN
		/* restore for use */
		be2leul(&rp->index);
		be2leus(&rp->type);
#endif
	}

	/* and the loc */
	fseek(ofp, toc->head->locoff, SEEK_SET);
	for (i = 0; i < toc->head->rescnt; ++i)
	{
		struct nwn_agg_so* sp = vsubig(toc->szofs, i);

#if WORDS_BIGENDIAN
		be2leul(&sp->off);
		be2leul(&sp->siz);
#endif
		if (fwrite(sp, sizeof *sp, 1, ofp) != 1)
		{
			fprintf(stderr, "%s: Can't write TOC for <%s>!\n", MyName, fname);
			fclose(ofp);
			agg_toc_delete(toc);
			return 1;
		}
	}

	fclose(ofp);
	show_toc(fname, toc);
	agg_toc_delete(toc);

	return 0;
}
