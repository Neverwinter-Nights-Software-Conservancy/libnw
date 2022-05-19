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
#include	"restyp.h"
#include	"v.h"
#include	"nwnfopen.h"
#if WORDS_BIGENDIAN
#include	"bendian.h"
#endif

char* nw_mod_filename = 0;
char* nw_hak_filename = 0;

extern int vflag;

struct v* nw_key_rsc_v = 0;
struct v* nw_key_rsc_fnames_v = 0;

static int read_key_internal(char* dirname, char* fname, int complain);
int find_resref(struct nw_key_rsc* rp);

int read_key(char* dirname)
{
	/* chitin.key is the master BIF table of contents */
	if (!read_key_internal(dirname, "chitin.key", 1))
		return 0;
	vsort(nw_key_rsc_v, cmp_key_rsc_name);

	/* xp1.key appears in SoU */
	if (read_key_internal(dirname, "xp1.key", 0))
		vsort(nw_key_rsc_v, cmp_key_rsc_name);

	/* xp1patch.key appears in SoU 1.31 */
	if (read_key_internal(dirname, "xp1patch.key", 0))
		vsort(nw_key_rsc_v, cmp_key_rsc_name);

	/* patch.key appears in 1.28 */
	if (read_key_internal(dirname, "patch.key", 0))
		vsort(nw_key_rsc_v, cmp_key_rsc_name);

	/*
	** some day, read the override directory, and add all its filenames
	**	and resources.	it appears that even with the introduction
	**	of patch.key in 1.28, this is still necessary.
	*/

	return 1;
}

static int read_key_internal(char* dirname, char* fname, int complain)
{
	struct nw_key nw_key;
	char* filename;
	FILE* fp;
	int r;
	int i;
	int nkrf_off = 0;

	fp = nwnfopen(fname, "rb", &filename);
	if (!fp)
	{
		if (complain)
			fprintf(stderr, "%s: read_key(): can't open <%s> for reading!\n",
				MyName, filename);
		return 0;
	}

	r = fread((void*) &nw_key, sizeof nw_key, 1, fp);
	if (r != 1)
	{
		fprintf(stderr, "read_key: can't read KEY header from <%s>!\n",
			filename);
		fclose(fp);
		return 0;
	}

	if (strncmp(nw_key.signature, KEY_SIGNATURE, sizeof nw_key.signature))
	{
		fprintf(stderr, "read_key: KEY signature <%4.4s> invalid!\n",
			nw_key.signature);
		fclose(fp);
		return 0;
	}

	if (strncmp(nw_key.version, KEY_VERSION, sizeof nw_key.version))
	{
		fprintf(stderr, "read_key: KEY version <%4.4s> invalid!\n",
			nw_key.version);
		fclose(fp);
		return 0;
	}

#if WORDS_BIGENDIAN
	be2leul(&nw_key.nfnam);
	be2leul(&nw_key.nrsc);
	be2leul(&nw_key.offrsc);
	be2leul(&nw_key.offfnam);
#endif

	/*
	 * if this is the 1st time through (chitin.key), allocate the key toc;
	 * otherwise, use the existing one
	 */
	if (!nw_key_rsc_v)
		nw_key_rsc_v = vnew(nw_key.nrsc);

	/*
	 * each KEY file has its own list of BIF names; if we already have
	 * some, note how many so we can just add to the list, and adjust
	 * the flag field as we go
	 */
	if (nw_key_rsc_fnames_v)
		nkrf_off = vlen(nw_key_rsc_fnames_v);

	fseek(fp, nw_key.offrsc, SEEK_SET);
	for (i = 0; i < nw_key.nrsc; ++i)
	{
		struct nw_key_rsc* rp = malloc(sizeof (*rp));

		r = fread((void*) rp, sizeof *rp, 1, fp);
		if (r != 1)
		{
			fprintf(stderr, "read_key: read %d nw_key_rscs, not %d!\n",
				r, 1);
			fclose(fp);
			return 0;
		}
#if WORDS_BIGENDIAN
		be2leus(&rp->type);
		be2leul(&rp->resid);
#endif
		/* adjust index into BIF names */
		rp->resid += nkrf_off << 20;

		/*
		 * if this is not the 1st KEY file, we must replace any
		 * existing entries
		 */
		if (nkrf_off)
		{
			struct nw_key_rsc** xp;

			xp = (struct nw_key_rsc**) vbsearch(rp, nw_key_rsc_v, cmp_key_rsc_name);
			if (xp)
			{
				/* found it; replace it */
				free(*xp);
				*xp = rp;
			}
			else
			{
				/*
				 * we have to search for each resource the hard way,
				 * since we can't depend on the list being sorted
				 */
				int i;
				struct nw_key_rsc* zp;

				for (i = 0; i < vlen(nw_key_rsc_v); ++i)
				{
					zp = vsubig(nw_key_rsc_v, i);
					if (rp->type != zp->type)
						continue;
					if (strncasecmp(rp->name, zp->name, sizeof rp->name) != 0)
						continue;
					free(zp);
					vsubip(nw_key_rsc_v, i, rp);
					break;
				}
				if (i >= vlen(nw_key_rsc_v))
					vapp(nw_key_rsc_v, rp);
			}
		}
		else
			vapp(nw_key_rsc_v, rp);
	}

	if (!nw_key_rsc_fnames_v)
		nw_key_rsc_fnames_v = vnew(nw_key.nfnam);

	fseek(fp, nw_key.offfnam, SEEK_SET);
	for (i = 0; i < nw_key.nfnam; ++i)
	{
		struct nw_key_fnam kf;
		int k;
		char* fn;

		fseek(fp, nw_key.offfnam + (i * sizeof kf), SEEK_SET);
		if (fread(&kf, sizeof kf, 1, fp) != 1)
		{
			fprintf(stderr, "%s: read_key(): can't read filename entry[%d]!\n",
				MyName, i);
			fclose(fp);
			return 0;
		}
		fn = malloc(1 + kf.FilenameSize);
		if (!fn)
		{
			fprintf(stderr, "%s: read_key(): can't allocate filename[%d](%d)!\n",
				MyName, i, 1 + kf.FilenameSize);
			fclose(fp);
			return 0;
		}
		fseek(fp, kf.FilenameOffset, SEEK_SET);
		if (fread(fn, kf.FilenameSize, 1, fp) != 1)
		{
			fprintf(stderr, "%s: read_key(): can't read filename[%d] @ %#lx!\n",
				MyName, i, kf.FilenameOffset);
			fclose(fp);
			return 0;
		}

#ifndef WINDOWS
		/* for Linux, translate backslashes to slashes, dammit */
		for (k = 0; k < kf.FilenameSize; ++k)
		{
			if (fn[k] == '\\')
				fn[k] = '/';
		}
#endif
		fn[kf.FilenameSize] = 0;
		vapp(nw_key_rsc_fnames_v, fn);
	}
	fclose(fp);

	return 1;
}

void print_key_rscs(void)
{
	int i;

	if (vflag)
	{
		printf("KEY RESOURCE TABLE:\n");
		printf("%-16.16s %-6.6s %-6.6s %-5.5s %-4.4s %-5.5s %s\n",
			"RESREF", "RESEXT", "RESTYP", "FILE", "SECT", "INDEX", "FILENAME");
	}
	for (i = 0; i < vlen(nw_key_rsc_v); ++i)
	{
		struct nw_key_rsc* rp = vsubig(nw_key_rsc_v, i);
		char* fnam = vsubig(nw_key_rsc_fnames_v, rp->resid >> 20);

		if (vflag)
		{
			printf("%-16.16s %-6.6s 0x%.4hx 0x%.3lx 0x%.2lx 0x%.4lx %s\n",
				rp->name, typ2ext(rp->type), rp->type,
				rp->resid >> 20, (rp->resid >> 14) & 0x3F, rp->resid & 0x3FFF, fnam);
		}
		else
			printf("%-.16s.%s\n", rp->name, typ2ext(rp->type));
	}
}

/* comparison function for vsort: resource keys in alphabetical order */

int cmp_key_rsc_name(const void* a, const void* b)
{
	struct nw_key_rsc** aa = (struct nw_key_rsc**) a;
	struct nw_key_rsc** bb = (struct nw_key_rsc**) b;
	struct nw_key_rsc* r0 = *aa;
	struct nw_key_rsc* r1 = *bb;
	int r;

	r = strncasecmp(r0->name, r1->name, sizeof r0->name);
	if (r)
		return r;
	return (r0->type - r1->type);
}

/* comparison function for vsort: resource keys in bif order */

int cmp_key_rsc_bif(const void* a, const void* b)
{
	struct nw_key_rsc** aa = (struct nw_key_rsc**) a;
	struct nw_key_rsc** bb = (struct nw_key_rsc**) b;
	struct nw_key_rsc* r0 = *aa;
	struct nw_key_rsc* r1 = *bb;

	return (r0->resid - r1->resid);
}
