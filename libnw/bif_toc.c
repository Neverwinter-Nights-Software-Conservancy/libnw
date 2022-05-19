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
#include	"key.h"
#include	"bif.h"
#include	"nwnfopen.h"
#if WORDS_BIGENDIAN
#include	"bendian.h"
#endif

struct nw_bif_ent* bif_toc_load(char* relpath, unsigned long* nents)
{
	struct nw_bif_ent* rp = 0;
	char* filename;
	FILE* fp;
	int r;
	struct nw_bif_head bh;

	*nents = 0;
	fp = nwnfopen(relpath, "rb", &filename);
	if (!fp)
	{
		fprintf(stderr, "%s: bif_toc_load: can't open <%s> for reading!\n",
			MyName, filename);
		return rp;
	}

	r = fread((void*) &bh, sizeof bh, 1, fp);
	if (r != 1)
	{
		fprintf(stderr, "%s: bif_toc_load(%s): can't read BIF header!\n",
			MyName, relpath);
		fclose(fp);
		return rp;
	}

	if (strncmp(bh.signature, NW_BIF_SIGNATURE, sizeof bh.signature))
	{
		fprintf(stderr, "%s: bif_toc_load(%s): invalid signature <%-4.4s>!\n",
			MyName, relpath, bh.signature);
		fclose(fp);
		return rp;
	}

	if (strncmp(bh.version, NW_BIF_VERSION, sizeof bh.version))
	{
		fprintf(stderr, "%s: bif_toc_load(%s): invalid version <%-4.4s>!\n",
			MyName, relpath, bh.version);
		fclose(fp);
		return rp;
	}

#if WORDS_BIGENDIAN
	be2leul(&bh.varcnt);
	be2leul(&bh.varoff);
#endif

	rp = malloc(bh.varcnt * sizeof rp[0]);
	if (!rp)
	{
		fprintf(stderr, "%s: bif_toc_load(%s): can't allocate %ld BIF entries!\n",
			MyName, relpath, bh.varcnt);
		fclose(fp);
		return rp;
	}

	fseek(fp, bh.varoff, SEEK_SET);

	r = fread((void*) rp, sizeof rp[0], bh.varcnt, fp);
	if (r != bh.varcnt)
	{
		fprintf(stderr, "%s: bif_toc_load(%s): read %d BIF entries, not %ld!\n",
			MyName, relpath, r, bh.varcnt);
		fclose(fp);
		free(rp);
		rp = 0;
		return rp;
	}

#if WORDS_BIGENDIAN
	for (r = 0; r < bh.varcnt; ++r)
	{
		be2leul(&rp[r].resid);
		be2leul(&rp[r].off);
		be2leul(&rp[r].len);
		be2leul(&rp[r].restyp);
	}
#endif

	fclose(fp);

	*nents = bh.varcnt;

	return rp;
}
