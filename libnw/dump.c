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
#include	"global.h"
#include	"key.h"
#include	"bif.h"
#include	"restyp.h"
#include	"bin.h"
#include	"nwnfopen.h"

extern int vflag;

int resref2bifidx(const char* name, const unsigned short type, char** bif, int* idx);

void dump_all(int argc, char** argv)
{
	int f;
	int i;
	int gotbif;
	unsigned long nents;
	struct nw_bif_ent* bp;
	char* bifname;
	FILE* fp = 0;
	char* cp;
	char* ofname;
	FILE* ofp;
	int r;
	int resfn;
	int ressect;
	int resnum;

	if (vflag)
		setbuf(stdout, 0);
	if (argc > 0)
	{
		vsort(nw_key_rsc_v, cmp_key_rsc_name);
		for (i = 0; i < argc; ++i)
		{
			void* p;
			int len;

			p = ext_file(argv[i], &len);
			if (!p)
			{
				fprintf(stderr, "%s%s: Resource <%s> not found.\n",
					vflag ? "\n" : "", MyName, argv[i]);
				continue;
			}
			ofp = fopen(argv[i], "wb");
			if (!ofp)
			{
				fprintf(stderr, "%s%s: Can't create file <%s>.\n",
					vflag ? "\n" : "", MyName, argv[i]);
				free(p);
				continue;
			}
			r = fwrite(p, 1, len, ofp);
			if (r != len)
			{
				fprintf(stderr, "%s%s: Write to <%s> failed: %d; expected %d.\n",
					vflag ? "\n" : "", MyName, argv[i], r, len);
				fclose(ofp);
				free(p);
				continue;
			}
			fclose(ofp);
			free(p);
			if (vflag)
				printf(".");
		}
		return;
	}
	vsort(nw_key_rsc_v, cmp_key_rsc_bif);
	for (f = 0; f < vlen(nw_key_rsc_fnames_v); ++f)
	{
		gotbif = 0;
		bp = 0;
		nents = 0;

		for (i = 0; i < vlen(nw_key_rsc_v); ++i)
		{
			struct nw_key_rsc* np = vsubig(nw_key_rsc_v, i);
			const char* ext = typ2ext(np->type);

			if (!ext)
			{
				fprintf(stderr, "%s%s: unknown extension for type 0x%x!\n",
					vflag ? "\n" : "", MyName, np->type);
				continue;
			}
			resfn = np->resid >> 20;
			ressect = (np->resid >> 14) & 0x3F;
			resnum = np->resid & 0x3FFF;
			if (resfn == f)
			{
				if (!gotbif)
				{
					bp = bif_toc_load((char*) vsubig(nw_key_rsc_fnames_v, f), &nents);
					if (!bp || !nents)
					{
						fprintf(stderr, "%s%s: can't get BIF entries from <%s>!",
							vflag ? "\n" : "", MyName,
							(char*) vsubig(nw_key_rsc_fnames_v, f));
						if (bp)
						{
							free(bp);
							bp = 0;
						}
						nents = 0;
						continue;
					}

					fp = nwnfopen((char*) vsubig(nw_key_rsc_fnames_v, f), "rb",
						&bifname);
					if (!fp)
					{
						fprintf(stderr, "%s%s: can't reopen <%s> to get <%-.16s.%s>!\n",
							vflag ? "\n" : "", MyName,
							(char*) vsubig(nw_key_rsc_fnames_v, f),
							np->name, ext);
						free(bifname);
						free(bp);
						bp = 0;
						nents = 0;
						continue;
					}

					if (vflag)
						printf("\n%s:\n", bifname);
					gotbif = 1;
				}

				if (resnum > nents)
				{
					fprintf(stderr, "%s%s: residx %d > # BIF entries (%ld) for <%-.16s> in <%s>!\n",
						vflag ? "\n" : "", MyName, resnum, nents, np->name,
						(char*) vsubig(nw_key_rsc_fnames_v, f));
					continue;
				}

				fseek(fp, bp[resnum].off, SEEK_SET);
				cp = malloc(bp[resnum].len);
				if (!cp)
				{
					fprintf(stderr, "%s%s: can't allocate %ld for <%-.16s.%s> from <%s>!\n",
						vflag ? "\n" : "", MyName, bp[resnum].len, np->name,
						ext, (char*) vsubig(nw_key_rsc_fnames_v, f));
					continue;
				}

				r = fread(cp, 1, bp[resnum].len, fp);
				if (r != bp[resnum].len)
				{
					fprintf(stderr, "%s%s: can't read %ld bytes (got %d) @ 0x%lx for <%-.16s.%s>!\n",
						vflag ? "\n" : "", MyName, bp[resnum].len, r,
						bp[resnum].off, np->name, ext);
					free(cp);
					continue;
				}

				ofname = malloc(16 + 4 + 1);
				if (!ofname)
				{
					fprintf(stderr, "%s%s: can't allocate %d for output filename <%-.16s.%s>!\n",
						vflag ? "\n" : "", MyName, 16 + 4 + 1, np->name, ext);
					free(cp);
					continue;
				}

				sprintf(ofname, "%-.16s.%s", np->name, ext);
				ofp = fopen(ofname, "wb");
				if (!ofp)
				{
					fprintf(stderr, "%s%s: can't create <%s> for writing!\n",
						vflag ? "\n" : "", MyName, ofname);
					free(ofname);
					free(cp);
					continue;
				}

				r = fwrite(cp, 1, bp[resnum].len, ofp);
				if (r != bp[resnum].len)
				{
					fprintf(stderr, "%s%s: can't write %ld bytes on <%s>!\n",
						vflag ? "\n" :"", MyName, bp[resnum].len, ofname);
					fclose(ofp);
					free(ofname);
					free(cp);
					continue;
				}
				fclose(ofp);
				free(cp);
				if (vflag)
					printf(".");
			}
		}
		if (fp)
		{
			fclose(fp);
			fp = 0;
		}
	}
}

void* ext_bin(char* name, unsigned long restyp, int* length)
{
	unsigned long nents;
	struct nw_bif_ent* bp;
	char* bifname;
	FILE* fp = 0;
	char* cp;
	int r;
	char* fname = 0;
	int idx = 0;
	const char* ext = typ2ext(restyp);

	*length = 0;

	if (!resref2bifidx(name, restyp, &fname, &idx))
		return 0;
	bp = bif_toc_load(fname, &nents);
	if (!bp || !nents)
	{
		fprintf(stderr, "%s: can't get BIF entries from <%s>!",
			MyName, fname);
		if (bp)
		{
			free(bp);
			bp = 0;
		}
		return 0;
	}

	fp = nwnfopen(fname, "rb", &bifname);
	if (!fp)
	{
		fprintf(stderr, "%s: can't reopen <%s> to get <%-.16s.%s>!\n",
			MyName, fname, name, ext);
		free(bifname);
		free(bp);
		return 0;
	}

	if (idx > nents)
	{
		fprintf(stderr, "%s: residx %d > # BIF entries (%ld) for <%-.16s> in <%s>!\n",
			MyName, idx, nents, name, fname);
		fclose(fp);
		free(bifname);
		free(bp);
		return 0;
	}

	fseek(fp, bp[idx].off, SEEK_SET);
	cp = malloc(bp[idx].len);
	if (!cp)
	{
		fprintf(stderr, "%s: can't allocate %ld for <%-.16s.%s> from <%s>!\n",
			MyName, bp[idx].off, name, ext, fname);
		fclose(fp);
		free(bifname);
		free(bp);
		return 0;
	}

	r = fread(cp, 1, bp[idx].len, fp);
	if (r != bp[idx].len)
	{
		fprintf(stderr, "%s: can't read %ld bytes (got %d) @ 0x%lx for <%-.16s.%s>!\n",
			MyName, bp[idx].len, r, bp[idx].off, name, ext);
		fclose(fp);
		free(cp);
		free(bifname);
		free(bp);
		return 0;
	}
	fclose(fp);
	*length = bp[idx].len;
	free(bifname);
	free(bp);
	return cp;
}

void* ext_file(char* name, int* length)
{
	char* dp;
	unsigned long rtype;
	void* vp;

	*length = 0;

	dp = strchr(name, '.');
	if (!dp)
		return 0;
	rtype = ext2typ(dp + 1);
	*dp = '\0';
	vp = ext_bin(name, rtype, length);
	*dp = '.';
	return vp;
}

int resref2bifidx(const char* name, const unsigned short type, char** bif, int* idx)
{
	struct nw_key_rsc r;
	struct nw_key_rsc** sp;

	r.type = type;
	strncpy(r.name, name, sizeof r.name);

	*bif = 0;

	sp = vbsearch(&r, nw_key_rsc_v, cmp_key_rsc_name);
	if (!sp)
	{
		fprintf(stderr, "%s(%s): Can't find resource [%s]!\n",
			MyName, "resref2bifidx", name);
		return 0;
	}
	*bif = vsubig(nw_key_rsc_fnames_v, sp[0]->resid >> 20);
	*idx = sp[0]->resid & 0xFFFFF;
	return 1;
}
