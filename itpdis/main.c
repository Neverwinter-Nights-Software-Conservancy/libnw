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
#include	"itp.h"
#include	"are.h"
#include	"uti.h"
#include	"utc.h"
#include	"git.h"
#include	"gic.h"
#include	"utp.h"
#include	"ute.h"
#include	"utd.h"
#include	"uts.h"
#include	"utm.h"
#include	"jrl.h"
#include	"ifo.h"
#include	"fac.h"
#include	"dlg.h"
#include	"utw.h"
#include	"bic.h"
#include	"gui.h"
#include	"utt.h"
#include	"ptt.h"
#include	"gff.h"
#include	"tlk.h"
#if WORDS_BIGENDIAN
#include	"bendian.h"
#endif

char* MyName = 0;
char* nw_inp_dir = 0;
int vflag = 0;

void read_itp(FILE* fp, long offset0);
void decode_data(int i);

static void usage()
{
	fprintf(stderr, "%s: Usage: %s [-g gamedir] file\n",
		MyName, MyName);
}

static void indent(int i)
{
	while (--i >= 0)
		printf("  ");
}

static int ilevel = 0;

int main(int argc, char** argv)
{
	int c;
	FILE* fp;

	MyName = argv[0];

	nw_inp_dir = get_game_dir();

	while ((c = getopt(argc, argv, "g:?")) != EOF)
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

	argc -= optind;
	argv += optind;

	fp = fopen(argv[0], "rb");
	if (!fp)
	{
		fprintf(stderr, "%s: Can't open <%s> for reading!\n",
			MyName, argv[0]);
		return 1;
	}
	read_itp(fp, 0);
	fclose(fp);

	return 0;
}

struct nwn_itp head;
struct nwn_itp_list* listp;
struct nwn_itp_data* datap;
struct nwn_itp_tag* tagp;
char* valuep;
int* rootp;
int* indexp;

void read_itp(FILE* fp, long offset0)
{
	int i;

	fseek(fp, offset0, SEEK_SET);
	if (fread(&head, sizeof head, 1, fp) != 1)
	{
		fprintf(stderr, "%s: Can't read ITP head!\n", MyName);
		return;
	}

	/* this format is used for several resources; match the ones we can
	**	cope with
	*/
	if (strncmp(head.signature, NWN_ITP_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, NWN_ITP_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, ARE_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, ARE_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTI_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTI_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTC_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTC_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, GIT_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, GIT_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, GIC_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, GIC_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTP_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTP_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTE_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTE_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTD_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTD_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTS_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTS_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTM_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTM_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, JRL_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, JRL_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, IFO_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, IFO_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, FAC_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, FAC_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, DLG_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, DLG_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTW_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTW_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, BIC_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, BIC_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, GUI_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, GUI_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, UTT_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, UTT_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, PTT_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, PTT_VERSION, sizeof head.version) == 0)
		;
	else
	if (strncmp(head.signature, GFF_SIGNATURE, sizeof head.signature) == 0 &&
		strncmp(head.version, GFF_VERSION, sizeof head.version) == 0)
		;
	else
	{
		fprintf(stderr, "%s: Invalid signature <%-.4s> or version <%-.4s>!\n",
			MyName, head.signature, head.version);
		return;
	}
#if WORDS_BIGENDIAN
	be2lel(&head.oList);
	be2lel(&head.cList);
	be2lel(&head.oData);
	be2lel(&head.cData);
	be2lel(&head.oTag);
	be2lel(&head.cTag);
	be2lel(&head.oValue);
	be2lel(&head.cValue);
	be2lel(&head.oRoot);
	be2lel(&head.cRoot);
	be2lel(&head.oIndex);
	be2lel(&head.cIndex);
#endif

	listp = malloc(head.cList * sizeof *listp);
	if (!listp)
	{
		fprintf(stderr, "%s: Can't allocate %ld list's!\n",
			MyName, head.cList);
		return;
	}
	fseek(fp, offset0 + head.oList, SEEK_SET);
	if (fread(listp, sizeof *listp, head.cList, fp) != head.cList)
	{
		fprintf(stderr, "%s: Can't read %ld list's!\n", MyName, head.cList);
		return;
	}
#if WORDS_BIGENDIAN
	for (i = 0; i < head.cList; ++i)
	{
		be2lel(&listp[i].code);
		be2lel(&listp[i].index);
		be2lel(&listp[i].count);
	}
#endif

	datap = malloc(head.cData * sizeof *datap);
	if (!datap)
	{
		fprintf(stderr, "%s: Can't allocate %ld data's!\n",
			MyName, head.cData);
		return;
	}
	fseek(fp, offset0 + head.oData, SEEK_SET);
	if (fread(datap, sizeof *datap, head.cData, fp) != head.cData)
	{
		fprintf(stderr, "%s: Can't read %ld data's!\n", MyName, head.cData);
		return;
	}
#if WORDS_BIGENDIAN
	for (i = 0; i < head.cData; ++i)
	{
		be2lel(&datap[i].type);
		be2lel(&datap[i].index);
		be2lel(&datap[i].data);
	}
#endif

	tagp = malloc(head.cTag * sizeof *tagp);
	if (!tagp)
	{
		fprintf(stderr, "%s: Can't allocate %ld tags!\n",
			MyName, head.cTag);
		return;
	}
	fseek(fp, offset0 + head.oTag, SEEK_SET);
	if (fread(tagp, sizeof *tagp, head.cTag, fp) != head.cTag)
	{
		fprintf(stderr, "%s: Can't read %ld tags!\n", MyName, head.cTag);
		return;
	}

	valuep = malloc(head.cValue * sizeof *valuep);
	if (!valuep)
	{
		fprintf(stderr, "%s: Can't allocate %ld value bytes!\n",
			MyName, head.cValue);
		return;
	}
	fseek(fp, offset0 + head.oValue, SEEK_SET);
	if (fread(valuep, sizeof *valuep, head.cValue, fp) != head.cValue)
	{
		fprintf(stderr, "%s: Can't read %ld value bytes!\n",
			MyName, head.cValue);
		return;
	}

	/* cRoot is bytes; we want ints */
	i = head.cRoot / sizeof *rootp;
	rootp = malloc(i * sizeof *rootp);
	if (!rootp)
	{
		fprintf(stderr, "%s: Can't allocate %d roots!\n", MyName, i);
		return;
	}
	fseek(fp, offset0 + head.oRoot, SEEK_SET);
	if (fread(rootp, sizeof *rootp, i, fp) != i)
	{
		fprintf(stderr, "%s: Can't read %d roots!\n", MyName, i);
		return;
	}
#if WORDS_BIGENDIAN
	for (i = 0; i < (head.cRoot / sizeof *rootp); ++i)
		be2lei(&rootp[i]);
#endif

	/* cIndex is bytes; we want ints */
	i = head.cIndex / sizeof *indexp;
	indexp = malloc(i * sizeof *indexp);
	if (!indexp)
	{
		fprintf(stderr, "%s: Can't allocate %d indexes!\n", MyName, i);
		return;
	}
	fseek(fp, offset0 + head.oIndex, SEEK_SET);
	if (fread(indexp, sizeof *indexp, i, fp) != i)
	{
		fprintf(stderr, "%s: Can't read %d indexes!\n", MyName, i);
		return;
	}
#if WORDS_BIGENDIAN
	for (i = 0; i < (head.cIndex / sizeof *indexp); ++i)
		be2lei(&indexp[i]);
#endif

	printf("<?xml version=\"1.0\" standalone=\"no\"?>\n");
	printf("<!DOCTYPE ITP SYSTEM \"itp.dtd\">\n");
	printf("<ITP xmlns=\"http://www.bioware.com/\" COUNT=\"%ld\">\n",
		listp[0].count);
	if (listp[0].count)
	{
		++ilevel;
		if (listp[0].count == 1)
			decode_data(listp[0].index / sizeof (int));
		else
		{
			int* rp = &rootp[listp[0].index / sizeof (int)];
			int k;

			for (k = 0; k < listp[0].count; k++)
				decode_data(rp[k]);
		}
		--ilevel;
	}
	printf("</ITP>\n");
}

void outstring(int len, unsigned char* s)
{
	int i;

	for (i = 0; i < len; ++i)
	{
		if (s[i] < ' ')
		{
			switch (s[i])
			{
			case '\n': putchar(s[i]); indent(ilevel); break;
			case '\r': /* ignore */; break;
			default:
				printf("&#x%X;", s[i]);
				break;
			}
		}
		else
		if (s[i] == '&') printf("&amp;");
		else
		if (s[i] == '<') printf("&lt;");
		else
		if (s[i] == '>') printf("&gt;");
		else
		if (s[i] == '"') printf("&quot;");
		else
		if (s[i] > '~')
			printf("&#x%X;", s[i]);
		else
			printf("%c", s[i]);
	}
}

int needs_escapes(int len, unsigned char* s)
{
	int i;

	for (i = 0; i < len && s[i]; ++i)
	{
		if (s[i] < ' ' || s[i] > '~')
			return 1;
		if (strchr("\"&<>", s[i]))
			return 1;
	}
	return 0;
}

void outstr(int len, unsigned char* s)
{
	++ilevel;
	outstring(len, s);
	--ilevel;
}

static char* TypeName[] =
{
	"UINT8",
	"INT8",
	"UINT16",
	"INT16",
	"UINT32",
	"INT32",
	"UINT64",
	"INT64",
	"FLOAT",
	"DOUBLE",
	"STRING",
	"RESREF",
	"LOCSTR",
	"DATREF",
	"CAPREF",
	"LIST",
};

void decode_data(int i)
{
	struct nwn_itp_data* dp = &datap[i];
	int j;
	int len;
	char* s;

	indent(ilevel);
	printf("<OBJECT NAME=\"");
	len = 0;
	for (s = tagp[dp->index].name, j = 0; j < 16 && s[j]; ++j)
		;
	len = j;
	if (needs_escapes(len, s))
	{
		fprintf(stderr, "%s: Warning: tag \"%s\" needed escapes!\n", MyName, s);
		outstring(len, s);
	}
	else
		printf("%-.*s", len, s);
	printf("\">\n");
	++ilevel;
	switch (dp->type)
	{
		short ss;
		unsigned short uss;
		int ii;
		unsigned int uii;
		long l;
		long long ll;
		unsigned long long ull;

	case t_uint8:
		indent(ilevel);
		printf("<SCALAR TYPE=\"UINT8\" VALUE=\"%u\"/>\n",
			(unsigned char) dp->data);
		break;

	case t_uint16:
		indent(ilevel);
		uss = (unsigned short) dp->data;
		printf("<SCALAR TYPE=\"UINT16\" VALUE=\"%u\"/>\n", uss);
		break;

	case t_uint32:
		indent(ilevel);
		uii = (unsigned int) dp->data;
		printf("<SCALAR TYPE=\"UINT32\" VALUE=\"%u\"/>\n", uii);
		if (nw_inp_dir)
		{
			if (strncasecmp(s, "STRREF", len) == 0)
			{
				char* cp = get_strref_str(dp->data);

				if (cp)
				{
					indent(ilevel);
					printf("<-- %s -->\n", cp);
					free(cp);
				}
			}
		}
		break;

	case t_uint64:
		indent(ilevel);
		uii = (unsigned int) dp->data;
		ull = *((unsigned long long*) &valuep[uii]);
#if WORDS_BIGENDIAN
		be2leull(&ull);
#endif
		printf("<SCALAR TYPE=\"UINT64\" VALUE=\"%llu\"/>\n", ull);
		break;

	case t_int8:
		indent(ilevel);
		printf("<SCALAR TYPE=\"SINT8\" VALUE=\"%d\"/>\n", (char) dp->data);
		break;

	case t_int16:
		indent(ilevel);
		ss = (short) dp->data;
		printf("<SCALAR TYPE=\"SINT16\" VALUE=\"%d\"/>\n", ss);
		break;

	case t_int32:
		indent(ilevel);
		l = (long) dp->data;
		printf("<SCALAR TYPE=\"SINT32\" VALUE=\"%ld\"/>\n", l);
		break;

	case t_int64:
		indent(ilevel);
		uii = (unsigned int) dp->data;
		ll = *((unsigned long long*) &valuep[uii]);
#if WORDS_BIGENDIAN
		be2leull(&ll);
#endif
		printf("<SCALAR TYPE=\"SINT64\" VALUE=\"%lld\"/>\n", ll);
		break;

	case t_float:
		indent(ilevel);
		printf("<SCALAR TYPE=\"FLOAT32\" VALUE=\"%g\"/>\n",
			*((float*) &dp->data));
		break;

	case t_double:
		indent(ilevel);
		printf("<SCALAR TYPE=\"FLOAT64\" VALUE=\"%g\"/>\n",
			*((double*) &valuep[dp->data]));
		break;

	case t_string:
	{
		unsigned int leng;

		ii = (int) dp->data;
		leng = *((unsigned int*) &valuep[ii]);
#if WORDS_BIGENDIAN
		be2leui(&leng);
#endif
		indent(ilevel);
		printf("<STRING%s>", leng ? "" : "/");
		if (leng)
		{
			outstr(leng,
				(unsigned char*) &valuep[ii + sizeof (unsigned int)]);
			printf("</STRING>");
		}
		printf("\n");
		break;
	}

	case t_resref:
	{
		unsigned int leng;

		ii = (int) dp->data;
		leng = *((unsigned char*) &valuep[ii]);
		indent(ilevel);
		printf("<SCALAR TYPE=\"RESREF\" VALUE=\"");
		outstr(leng,
			(unsigned char*) &valuep[ii + sizeof (unsigned char)]);
		printf("\"/>\n");
		break;
	}

	case t_locstr:
	{
		struct nwn_itp_slist* slp;
		char* cp;
		unsigned long strref;
		unsigned long count;

		ii = dp->data;
		slp = (struct nwn_itp_slist*) &valuep[ii];
		strref = slp->strref;
		count = slp->count;
#if WORDS_BIGENDIAN
		be2leul(&strref);
		be2leul(&count);
#endif
		cp = (char*) (slp + 1);
		indent(ilevel);
		printf("<LOCSTRS STRREF=\"%ld\" COUNT=\"%ld\"%s>\n", strref, count, count ? "" : "/");
		if (count)
		{
			++ilevel;
			for (j = 0; j < count; ++j)
			{
				int lang;
				int leng;

				lang = *((int*) cp);
#if WORDS_BIGENDIAN
				be2lei(&lang);
#endif
				cp += sizeof (int);
				leng = *((int*) cp);
#if WORDS_BIGENDIAN
				be2lei(&leng);
#endif
				cp += sizeof (int);
				indent(ilevel);
				printf("<LOCSTR LANG=\"%d\"%s>%s",
					lang, leng ? "" : "/", leng ? "" : "\n");
				if (leng)
				{
					outstr(leng, cp);
					printf("</LOCSTR>\n");
				}
				cp += leng;
			}
			indent(--ilevel);
			printf("</LOCSTRS>\n");
		}
		break;
	}

	case t_datref:
	{
		int leng;

		ii = (int) dp->data;
		leng = *((int*) &valuep[ii]);
#if WORDS_BIGENDIAN
		be2lei(&leng);
#endif
		indent(ilevel);
		printf("<BLOB COUNT=\"%d\"%s>\n", leng, leng ? "" : "/");
		if (leng)
		{
			indent(++ilevel);
			for (j = 0; j < leng; ++j)
				printf("0x%.2x ", 0xff & valuep[ii + sizeof (int) + j]);
			printf("\n");
			indent(--ilevel);
			printf("</BLOB>\n");
		}
		break;
	}

	case t_capref:
	{
		struct nwn_itp_list* lp;

		ii = (int) dp->data;
		lp = &listp[ii];
		indent(ilevel);
		printf("<RECORD COUNT=\"%ld\" CODE=\"%ld\"%s>\n", lp->count,
			lp->code, lp->count ? "" : "/");
		if (lp->count)
		{
			++ilevel;
			if (lp->count == 1)
				decode_data(lp->index);
			else
			{
				int* rp = &rootp[lp->index / sizeof (int)];

				for (j = 0; j < lp->count; j++)
					decode_data(rp[j]);
			}
			indent(--ilevel);
			printf("</RECORD>\n");
		}
		break;
	}

	case t_list:
	{
		int* ip;
		int leng;

		ii = (int) dp->data;
		ip = &indexp[ii / sizeof (int)];
		leng = *ip++;
		indent(ilevel);
		printf("<LIST COUNT=\"%d\"%s>\n", leng, leng ? "" : "/");
		if (leng)
		{
			++ilevel;
			for (j = 0; j < leng; ++j)
			{
				struct nwn_itp_list* lp;
				int* rp;
				int k;

				ii = ip[j];
				lp = &listp[ii];
				rp = &rootp[lp->index / sizeof (int)];
				indent(ilevel);
				printf("<LISTITEM CODE=\"%ld\"%s>\n", lp->code,
					lp->count ? "" : "/");
				if (lp->count)
				{
					++ilevel;
					if (lp->count == 1)
						decode_data(lp->index);
					else
					{
						for (k = 0; k < lp->count; k++)
							decode_data(rp[k]);
					}
					indent(--ilevel);
					printf("</LISTITEM>\n");
				}
			}
			indent(--ilevel);
			printf("</LIST>\n");
		}
		break;
	}

	default:
		abort();
		break;
	}
	indent(--ilevel);
	printf("</OBJECT>\n");
}
