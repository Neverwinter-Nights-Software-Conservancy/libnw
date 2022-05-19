#include	<config.h>
#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#ifdef HAVE_UNISTD_H
#include	<unistd.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include	<memory.h>
# endif
# include	<string.h>
#endif
#ifdef HAVE_GETOPT_H
#include	<getopt.h>
#endif
#include	"gamedir.h"
#include	"tlk.h"

char* MyName;
char* nw_inp_dir = 0;
int vflag = 0;

int wflag = 0;

static void show_strref(long s);

static void usage()
{
	fprintf(stderr, "%s: Usage: %s [-g gamedir] { -w | strref [ ... ] }\n", MyName, MyName);
	exit(2);
}

int main(int argc, char** argv)
{
	int c;
	int i;

	MyName = argv[0];

	nw_inp_dir = get_game_dir();

	while ((c = getopt(argc, argv, "g:w?")) != EOF)
	{
		switch (c)
		{
		case 'g':
			nw_inp_dir = optarg;
			break;

		case 'w':
			wflag = 1;
			break;

		default:
			usage();
			break;
		}
	}

	if (!nw_inp_dir)
		usage();

	argv += optind;
	argc -= optind;

	if (wflag)
	{
		int nstrs = get_n_strrefs();

		for (i = 0; i < nstrs; ++i)
		{
			struct nwn_tlk_ent* ep = get_strref_ent(i);

			if (ep->wavref[0])
				show_strref(i);
		}
	}
	else
	{
		for (i = 0; i < argc; ++i)
		{
			long s = strtol(argv[i], 0, 0);

			show_strref(s);
		}
	}

	return 0;
}

static void show_strref(long s)
{
	struct nwn_tlk_ent* ep = get_strref_ent(s);
	char* cp = get_strref_str(s);

	if (ep && cp)
	{
		printf("%ld: %.1lu [%-16.16s] %5.2f\n",
			s, ep->flags, &ep->wavref[0], ep->wavdur);
		printf("%s\n", cp);
		free(cp);
	}
	else
	{
		if (s < 0 || s >= get_n_strrefs())
		{
			fprintf(stderr, "%s: STRREF %ld out of range (0..%d).\n",
				MyName, s, get_n_strrefs() - 1);
		}
		else
		{
			fprintf(stderr, "%s: Invalid STRREF %ld.\n", MyName, s);
		}
	}
}
