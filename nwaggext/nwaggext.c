#include	<config.h>
#include	<stdio.h>
#if HAVE_UNISTD_H
#include	<unistd.h>
#endif
#include	"global.h"

extern int agg1dump(char*, long, int);
extern int agg_create(char**, int);

char* MyName = 0;
char* nw_inp_dir = 0;
int vflag = 0;

static void usage()
{
	fprintf(stderr, "%s: Usage: %s [-x|-c {-t m|-t h|-t e}] file [resfile ...]\n",
		MyName, MyName);
}

int main(int argc, char** argv)
{
	int r;
	int c;
	int dump = 0;
	int create = 0;
	int type = -1;

	MyName = argv[0];

	while ((c = getopt(argc, argv, "ct:x?")) != EOF)
	{
		switch (c)
		{
		case 'c':
			create = 1;
			break;

		case 't':
			if (*optarg == 'm')
				type = 0;
			else
			if (*optarg == 'h')
				type = 1;
			else
			if (*optarg == 'e')
				type = 2;
			else
			{
				fprintf(stderr, "%s: Invalid type to create!\n", MyName);
				usage();
				return 1;
			}
			break;

		case 'x':
			dump = 1;
			break;

		case '?':
		default:
			usage();
			return 1;
		}
	}

	argc -= optind;
	argv += optind;

	if (!*argv)
	{
		usage();
		return 1;
	}

	if (create)
	{
		if (type == -1)
		{
			fprintf(stderr, "%s: Type must be specified for create!\n", MyName);
			usage();
			return 1;
		}
		r = agg_create(argv, type);
	}
	else
		r = agg1dump(*argv, 0, dump);

	return r;
}
