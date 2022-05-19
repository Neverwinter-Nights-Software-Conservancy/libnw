#include	<config.h>
#include	<stdio.h>
#if HAVE_UNISTD_H
#include	<unistd.h>
#endif
#include	"global.h"
#include	"gamedir.h"
#include	"key.h"
#include	"bif.h"
#include	"bin.h"

char* nw_inp_dir = 0;
int tflag = 0;
int vflag = 0;
int xflag = 0;

char* MyName = 0;

static void usage()
{
	fprintf(stderr, "%s: Usage: %s [-g gamedir] [-v] [-x] [-t] [resource ...]\n",
		MyName, MyName);
}

int main(int argc, char** argv)
{
	int r;
	int c;

	MyName = argv[0];

	nw_inp_dir = get_game_dir();

	while ((c = getopt(argc, argv, "g:tvx?")) != EOF)
	{
		switch (c)
		{
		case 'g':
			nw_inp_dir = optarg;
			break;

		case 't':
			tflag = !tflag;
			break;

		case 'v':
			vflag = !vflag;
			break;

		case 'x':
			xflag = !xflag;
			break;

		case '?':
		default:
			usage();
			return 1;
		}
	}

	if (!nw_inp_dir)
	{
		usage();
		return 1;
	}

	if (tflag && xflag)
	{
		fprintf(stderr, "%s: can't use both -t and -x!\n", MyName);
		usage();
		return 1;
	}

	if (!tflag && !xflag)
	{
		fprintf(stderr, "%s: must use one of -t or -x!\n", MyName);
		usage();
		return 1;
	}

	argv += optind;
	argc -= optind;

	r = read_key(nw_inp_dir);
	if (!r)
	{
		fprintf(stderr, "main: failed to read KEY file!\n");
		return 2;
	}

	if (tflag)
	{
		print_key_rscs();
		return 0;
	}

	dump_all(argc, argv);

	return 0;
}
