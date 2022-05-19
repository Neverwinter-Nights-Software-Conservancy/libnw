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
#include	"restyp.h"

char* nw_inp_dir = 0;
int vflag = 0;

char* MyName = 0;

static void usage()
{
	fprintf(stderr, "%s: Usage: %s [-g gamedir] [resource.2da ...]\n",
		MyName, MyName);
	exit(1);
}

void prtcsv(struct v* a)
{
	int i;
	int j;

	for (i = 0; i < vlen(a); ++i)
	{
		struct v* vrp = vsubig(a, i);

		for (j = 0; j < vlen(vrp); ++j)
		{
			char* ep = vsubig(vrp, j);
			int len = strlen(ep);

			if (!len || strspn(ep, "-+.0123456789") != len)
				printf("\"%s\"", ep);
			else
				printf("%s", ep);
			if (j != (vlen(vrp) - 1))
				printf(",");
		}
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	int r;
	int c;
	void* game_2da;
	int game_2da_len = 0;
	struct v* game_c2da;

	MyName = argv[0];

	nw_inp_dir = get_game_dir();

	while ((c = getopt(argc, argv, "g:tvx?")) != EOF)
	{
		switch (c)
		{
		case 'g':
			nw_inp_dir = optarg;
			break;

		case '?':
		default:
			usage();
			return 1;
		}
	}

	if (!nw_inp_dir)
		usage();

	argv += optind;
	argc -= optind;

	if (argc <= 0)
		usage();

	r = read_key(nw_inp_dir);
	if (!r)
	{
		fprintf(stderr, "main: failed to read KEY file!\n");
		return 2;
	}

	/* extract the 2DA resource into memory */
	game_2da = ext_bin(argv[0], RR_2DA, &game_2da_len);
	if (!game_2da)
	{
		fprintf(stderr, "%s: Can't find master %s.2da!\n", MyName, argv[0]);
		return 2;
	}
	/* convert 2DA to char*** array */
	game_c2da = bin22da(game_2da, game_2da_len);

	prtcsv(game_c2da);
	free_2da(game_c2da);

	return 0;
}
