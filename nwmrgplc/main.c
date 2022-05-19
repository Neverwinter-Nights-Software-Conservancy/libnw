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
#include	"gamedir.h"
#include	"2da.h"
#include	"key.h"
#include	"bif.h"
#include	"bin.h"
#include	"agg.h"
#include	"restyp.h"

char* nw_inp_dir = 0;
int vflag = 0;
char* hakpakname = 0;

char* MyName = 0;

/* game resource "placeables.2da" */
void* game_2da = 0;
/* size of game_2da */
int game_2da_len = 0;
/* game_2da converted to char*** */
struct v* game_plc = 0;
/* HAK table of contents */
struct nwn_agg_toc* haktoc = 0;
/* HAK resource "placeables.2da" */
void* hak_2da = 0;
/* size of hak_2da */
int hak_2da_len = 0;
/* hak_2da converted to char*** */
struct v* hak_plc = 0;

static void usage()
{
	fprintf(stderr, "%s: Usage: %s [-g gamedir] -h pack.HAK\n",
		MyName, MyName);
	exit(1);
}

int cmp_row(struct v* g, struct v* h)
{
	int i;
	int r;

	for (i = 0; i < vlen(g) && i < vlen(h); ++i)
	{
		if ((r = strcmp((char*) vsubig(g, i), (char*) vsubig(h, i))) != 0)
			return r;
	}
	return 0;
}

void fprint_row(FILE* fp, struct v* r)
{
	int i;

	for (i = 0; i < vlen(r); ++i)
	{
		fprintf(fp, "%s", (char*) vsubig(r, i));
		if (i != (vlen(r) - 1))
			fprintf(fp, ",");
	}
	fprintf(fp, "\n");
}

void print_row(struct v* r)
{
	fprint_row(stdout, r);
}

void print_2da(struct v* a)
{
	int i;
	int j;
	int cols;
	int* widths;
	struct v* vrp = vsubig(a, 0);

	cols = vlen(vrp);
	widths = (int*) malloc(cols * sizeof *widths);
	if (!widths)
	{
		fprintf(stderr, "%s: Can't allocate %ld for column widths!\n",
			MyName, (long) cols * sizeof *widths);
		return;
	}
	for (i = 0; i < cols; ++i)
		widths[i] = 0;
	for (i = 0; i < vlen(a); ++i)
	{
		vrp = vsubig(a, i);
		for (j = 0; j < vlen(vrp); ++j)
		{
			int len = strlen((char*) vsubig(vrp, j));

			if (len > widths[j])
				widths[j] = len;
		}
	}
	printf("2DA V2.0\n\n");
	for (i = 0; i < vlen(a); ++i)
	{
		vrp = vsubig(a, i);
		for (j = 0; j < vlen(vrp); ++j)
		{
			printf("%-*.*s", widths[j], widths[j], (char*) vsubig(vrp, j));
			if (j != (vlen(vrp) - 1))
				printf(" ");
		}
		printf("\n");
	}
	free(widths);
}

int main(int argc, char** argv)
{
	int r;
	int c;
	struct nwn_agg_resc* rp = 0;
	struct nwn_agg_so* sp = 0;
	unsigned long plc_idx;
	int i;
	int j;
	FILE* fp;

	MyName = argv[0];

	nw_inp_dir = get_game_dir();

	while ((c = getopt(argc, argv, "g:h:?")) != EOF)
	{
		switch (c)
		{
		case 'g':
			nw_inp_dir = optarg;
			break;

		case 'h':
			hakpakname = optarg;
			break;

		case '?':
		default:
			usage();
			return 1;
		}
	}

	if (!nw_inp_dir || !hakpakname)
		usage();

	argv += optind;
	argc -= optind;

	/* read the game's key files */
	r = read_key(nw_inp_dir);
	if (!r)
	{
		fprintf(stderr, "main: failed to read KEY file!\n");
		return 2;
	}

	/* extract the "placeables.2da" resource into memory */
	game_2da = ext_bin("placeables", RR_2DA, &game_2da_len);
	if (!game_2da)
	{
		fprintf(stderr, "%s: Can't find master placeables.2da!\n", MyName);
		return 2;
	}
	/* convert "placeables.2da" to char*** array */
	game_plc = bin22da(game_2da, game_2da_len);

	/* read the HAK's table of contents */
	haktoc = agg_toc_load(hakpakname, 0);
	if (!haktoc)
	{
		fprintf(stderr, "%s: Can't load HAK contents from <%s>!\n",
			MyName, hakpakname);
		return 2;
	}

	/* find which index its "placeables.2da" has */
	plc_idx = -1;
	for (i = 0; i < vlen(haktoc->rescs); ++i)
	{
		rp = vsubig(haktoc->rescs, i);
		if (rp->type == RR_2DA &&
			strncasecmp(rp->name, "placeables", sizeof rp->name) == 0)
		{
			plc_idx = rp->index;
			break;
		}
	}

	/* did we find it? */
	if (plc_idx == -1)
	{
		fprintf(stderr, "%s: Can't find placeables.2da in <%s>!\n",
			MyName, hakpakname);
		return 2;
	}

	/* extract the HAK's "placeables.2da" into memory */
	sp = vsubig(haktoc->szofs, plc_idx);
	hak_2da = malloc(sp->siz);
	if (!hak_2da)
	{
		fprintf(stderr, "%s: Can't allocate (%ld) for <%s>'s placeables.2da!\n",
			MyName, sp->siz, hakpakname);
		return 2;
	}
	hak_2da_len = sp->siz;

	fp = fopen(hakpakname, "rb");
	if (!fp)
	{
		fprintf(stderr, "%s: Can't reopen <%s> for reading!\n",
			MyName, hakpakname);
		return 2;
	}
	fseek(fp, sp->off, SEEK_SET);
	if (fread(hak_2da, hak_2da_len, 1, fp) != 1)
	{
		fprintf(stderr, "%s: Can't read <%s>'s placeables.2da @ 0x%lx!\n",
			MyName, hakpakname, sp->off);
		return 2;
	}
	fclose(fp);

	/* convert HAK's "placeables.2da" to char*** */
	hak_plc = bin22da(hak_2da, hak_2da_len);

	/* search for HAK entries that don't match the game's placeables.2da */
	for (j = 0; j < vlen(hak_plc); ++j)
	{
		int found = 0;
		struct v* hjp = vsubig(hak_plc, j);

		for (i = 0; i < vlen(game_plc); ++i)
		{
			struct v* gip = vsubig(game_plc, i);

			/* matching index? */
			if (strcmp((char*) vsubig(gip, 0), (char*) vsubig(hjp, 0)) == 0)
			{
				if (cmp_row(gip, hjp) != 0)
				{
					fprintf(stderr, "%s: Conflict: master [%d]; HAK [%d]\n",
						MyName, i, j);
					fprint_row(stderr, gip);
					fprint_row(stderr, hjp);
				}
				found = 2;
				break;
			}
			else
			if (cmp_row(gip, hjp) == 0)
			{
				found = 1;
				break;
			}
		}
		if (!found)
			vapp(game_plc, hjp);
	}
	print_2da(game_plc);
	return 0;
}
