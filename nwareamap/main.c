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
#include	"rgb.h"
#include	"set.h"
#include	"bin.h"

char* nw_inp_dir = 0;
int vflag = 0;
char* MyName = 0;

int tflag = 0;

static void usage()
{
	fprintf(stderr, "%s: Usage: %s [-g gamedir] [-v] [-t] module.mod\n",
		MyName, MyName);
}

int main(int argc, char** argv)
{
	int c;
	struct nwn_agg_toc* mod_toc;
	int i;
	struct v* areas;

	/* set up for diagnostics */
	MyName = argv[0];

	/* get the default game directory, if any */
	nw_inp_dir = get_game_dir();

	/* parse options */
	while ((c = getopt(argc, argv, "g:tvy?")) != EOF)
	{
		switch (c)
		{
		case 'g':	/* override game dir */
			nw_inp_dir = optarg;
			break;

		case 't':	/* tileset info */
			tflag = !tflag;
			break;

		case 'v':	/* toggle verbose */
			vflag = !vflag;
			break;

		case 'y':	/* toggle yacc/lex debugging */
			nwset_debug = !nwset_debug;
			break;

		case '?':	/* emit usage message */
		default:
			usage();
			return 1;
		}
	}

	/* skip past option arguments */
	argv += optind;
	argc -= optind;

	/* complain about missing arguments */
	if (argc < 1)
	{
		fprintf(stderr, "%s: Required module argument missing!\n", MyName);
		return 1;
	}

	/* complain about superfluous arguments */
	if (argc > 1)
	{
		fprintf(stderr, "%s: Too many arguments!\n", MyName);
		return 1;
	}

	/* verify game directory is set */
	if (!nw_inp_dir)
	{
		fprintf(stderr, "%s: Must set game directory with $NWN_GAME_DIR or -g!\n",
			MyName);
		return 1;
	}

	/* load the module in question */
	mod_toc = agg_toc_load(argv[0], 0);
	if (!mod_toc)
	{
		fprintf(stderr, "%s: Can't read module <%s>!\n", MyName, argv[0]);
		return 1;
	}

	/* read the base resources for the game -- only if we'll use 'em */
	if (!tflag)
	{
		if (read_key(nw_inp_dir) == 0)
		{
			fprintf(stderr, "%s: Can't read game resources in <%s>!\n",
				MyName, nw_inp_dir);
			nw_inp_dir = 0;
		}
	}

	/* ok, let's go get all the ARE resources in the module */
	areas = vnew(0);
	for (i = 0; i < mod_toc->head->rescnt; ++i)
	{
		struct nwn_agg_resc* adp;

		adp = vsubig(mod_toc->rescs, i);
		/* is it an ARE? */
		if (adp->type == RR_ARE)
		{
			char name[16+1+3+1];
			int size;
			char* areap;
			struct v* vp;
			struct nwn_are* ap;
			void* tsrp;
			struct nwn_set set;
			struct v* tiles;
			int j;

			/* yes, arrange to load the resource */
			sprintf(name, "%-.16s.%s", adp->name, typ2ext(RR_ARE));
			areap = agg_res_load(argv[0], name, &size);
			/* now convert to a property list */
			vp = cvt_to_plist(areap);
			/* and convert that to an nwn_are structure */
			ap = plist2are(vp);
			/* babble a bit */
			printf("tileset %-.16s; %2d(h) x %2d(w); area <%-.16s>\n",
				ap->Tileset, ap->Height, ap->Width, adp->name);
			if (!tflag)
			{
				/* now, let's get the tileset */
				tsrp = ext_bin(ap->Tileset, RR_SET, &size);
				if (!tsrp)
				{
					fprintf(stderr, "%s: can't find tileset <%s>!\n", MyName, ap->Tileset);
					return 1;
				}
				/* and convert it to a struct nwn_set */
				if (nw_parse_set(tsrp, size, &set))
				{
					fprintf(stderr, "%s: can't parse tileset <%s>!\n", MyName, ap->Tileset);
					return 1;
				}
				/* just accumulate the tiles */
				tiles = vnew(ap->Height * ap->Width);
				for (j = 0; j < (ap->Height * ap->Width); ++j)
				{
					struct nwn_are_tile* atp = vsubig(ap->Tile_List, j);
					struct nwn_set_tile* tp = vsubig(set.Tiles, atp->Tile_ID);

					vapp(tiles, tp);
				}
				/* from this list, get the resource names */
				for (j = 0; j < (ap->Height * ap->Width); ++j)
				{
					struct nwn_set_tile* tp = vsubig(tiles, j);

					printf("tile %4d; minimap <%-.16s>\n", j, tp->ImageMap2D);
				}
			}
		}
	}

	return 0;
}
