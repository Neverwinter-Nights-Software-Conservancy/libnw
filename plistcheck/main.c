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
#include	"dlg.h"
#include	"gic.h"
#include	"ifo.h"
#include	"utc.h"
#include	"utd.h"
#include	"ute.h"
#include	"utp.h"
#include	"utt.h"
#include	"object.h"
#include	"rgb.h"
#include	"set.h"
#include	"bin.h"
#include	"itp.h"

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

	/* parse options */
	while ((c = getopt(argc, argv, "g:tv?")) != EOF)
	{
		switch (c)
		{
		case 'v':	/* toggle verbose */
			vflag = !vflag;
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

	/* load the module in question */
	mod_toc = agg_toc_load(argv[0], 0);
	if (!mod_toc)
	{
		fprintf(stderr, "%s: Can't read module <%s>!\n", MyName, argv[0]);
		return 1;
	}

	/* ok, let's go get all the interesting resources in the module */
	areas = vnew(0);
	for (i = 0; i < mod_toc->head->rescnt; ++i)
	{
		struct nwn_agg_resc* adp;
		char name[16+1+3+1];
		int size;
		char* resp;
		struct v* vp;
#if 0
		struct nwn_itp* ip;
#endif

		adp = vsubig(mod_toc->rescs, i);
		switch (adp->type)
		{
		case RR_ARE:
		case RR_DLG:
		case RR_GIC:
		case RR_IFO:
		case RR_UTC:
		case RR_UTD:
		case RR_UTE:
		case RR_UTP:
		case RR_UTT:
			/* yes, arrange to load the resource */
			sprintf(name, "%-.16s.%s", adp->name, typ2ext(adp->type));
			resp = agg_res_load(argv[0], name, &size);
			/* now convert to a property list */
			vp = cvt_to_plist(resp);
			break;
		default:
			continue;
		}
#if 0
		// temporary for debugging....
		ip = (struct nwn_itp*) resp;
		printf("%s:[%-4.4s][%-4.4s]\n", name, ip->signature, ip->version);
		printf("List: %ld @ 0x%.8lx\n", ip->cList, ip->oList);
		printf("Data: %ld @ 0x%.8lx\n", ip->cData, ip->oData);
		printf("Tags: %ld @ 0x%.8lx\n", ip->cTag, ip->oTag);
		printf("Vals: %ld @ 0x%.8lx\n", ip->cValue, ip->oValue);
		printf("Root: %ld @ 0x%.8lx\n", ip->cRoot, ip->oRoot);
		printf("Indx: %ld @ 0x%.8lx\n", ip->cIndex, ip->oIndex);
#endif
		switch (adp->type)
		{
		case RR_ARE:
		{
			struct nwn_are* ap = plist2are(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_DLG:
		{
			struct nwn_dlg* ap = plist2dlg(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_GIC:
		{
			struct nwn_gic* ap = plist2gic(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_IFO:
		{
			struct nwn_ifo* ap = plist2ifo(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_UTC:
		{
			struct nwn_utc* ap = plist2utc(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_UTD:
		{
			struct nwn_utd* ap = plist2utd(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_UTE:
		{
			struct nwn_ute* ap = plist2ute(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_UTP:
		{
			struct nwn_utp* ap = plist2utp(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		case RR_UTT:
		{
			struct nwn_utt* ap = plist2utt(vp);
			if (vflag) printf("%s <%s> %s!\n", typ2ext(adp->type), name, ap ? "OK" : "BAD");
			break;
		}
		}
	}

	return 0;
}
