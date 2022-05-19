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
#include	"global.h"
#include	"gamedir.h"
#include	"key.h"
#include	"bin.h"
#include	"bif.h"
#include	"rgb.h"
#include	"v.h"
#include	"set.h"
#include	"restyp.h"
#include	"str.h"
#include	"xref.h"

char* nw_set = 0;
struct nwn_set set;

char* nw_inp_dir = 0;
char* nw_inp_out = 0;

int vflag = 0;

char* MyName = 0;

extern int nwset_debug;

extern char* read_set_file(char* name, int* leng);
extern void write_refs(struct nwn_set* sp);
extern void combine();

static void usage()
{
	fprintf(stderr, "%s: Usage: %s -1 set\n",
		MyName, MyName);
}

int main(int argc, char** argv)
{
	int c;
	char* setfile1;
	int setleng1;

	MyName = argv[0];

	nwset_debug = 0;

	nw_inp_dir = get_game_dir();

	while ((c = getopt(argc, argv, "1:g:vy?")) != EOF)
	{
		switch (c)
		{
		case '1':
			nw_set = optarg;
			break;

		case 'g':
			nw_inp_dir = optarg;
			break;

		case 'v':
			vflag = !vflag;
			break;

		case 'y':
			nwset_debug = !nwset_debug;
			break;

		case '?':
		default:
			usage();
			return 1;
		}
	}

	if (!nw_set)
	{
		fprintf(stderr, "%s: must use -1 to specify 1st tileSet name!\n",
			MyName);
		usage();
		return 1;
	}

	/* read the base resources for the game, if specified */
	if (nw_inp_dir)
	{
		if (read_key(nw_inp_dir) == 0)
		{
			fprintf(stderr, "%s: Can't read game resources in <%s>!\n",
				MyName, nw_inp_dir);
			nw_inp_dir = 0;
		}
	}

	setfile1 = read_set_file(nw_set, &setleng1);
	if (!setfile1)
		return 3;

	nw_parse_set(setfile1, setleng1, &set);

	xrefs = vnew(1);

	write_refs(&set);

	show_xref();

	return 0;
}

void strlower(char* s)
{
	while (*s)
	{
		if (isupper(*s))
			*s = tolower(*s);
		++s;
	}
}

char* read_set_file(char* name, int* leng)
{
	FILE* fp;
	int r;
	int len;
	char* p;

	/* we haven't done anything yet, so we have 0 bytes */
	*leng = 0;

	/* open the file for reading */
	fp = fopen(name, "rb");
	if (!fp)
	{
		fprintf(stderr, "%s: Can't open <%s> for reading!\n", MyName, name);
		return 0;
	}

	/* seek to the end to see how big it is, then seek back to the beginning */
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	/* allocate storage for it all */
	p = malloc(1 + len);

	/* slurp it all in */
	if ((r = fread(p, 1, len, fp)) != len)
	{
		fprintf(stderr, "%s: Read %d bytes from <%s>, wanted %d\n",
			MyName, r, name, len);
		fclose(fp);
		return 0;
	}
	fclose(fp);

	/* got it all! */
	*leng = len;
	return p;
}

void do_mdl_file(char* fname)
{
	FILE* fp;
	char* cmd = 0;
	char buf[BUFSIZ];

	fp = fopen(fname, "rb");
	if (!fp)
	{
		fprintf(stderr, "%s: Can't open <%s>!\n", MyName, fname);
		return;
	}
	fread(buf, 1, 1, fp);
	fclose(fp);
	if (buf[0] == 0)
	{
		cmd = malloc(5 + strlen(fname));
		if (!cmd)
		{
			fprintf(stderr, "%s: Can't allocate command!\n", MyName);
			return;
		}
		sprintf(cmd, "nwnmdlcomp -d -e \"%s\" \"%s\" /dev/stdout", nw_inp_dir, fname);
		fp = popen(cmd, "r");
		if (!fp)
		{
			fprintf(stderr, "%s: Can't open command <%s>!\n", MyName, cmd);
			return;
		}
	}
	else
	{
		fp = fopen(fname, "r");
		if (!fp)
		{
			fprintf(stderr, "%s: Can't open <%s>!\n", MyName, fname);
			return;
		}
	}
	while (fgets(buf, sizeof buf, fp) == buf)
	{
		char* bp;

		bp = strchr(buf, 'b');
		if (!bp)
			continue;
		if (strncmp(bp, "bitmap ", 7) == 0)
		{
			char* np;
			char* tp;

			bp += 7;
			np = bp;
			while (*bp && *bp != '\r' && *bp != '\n')
				++bp;
			*bp = '\0';
			if (strcmp(np, "NULL") != 0)
			{
				tp = malloc(5 + strlen(np));
				if (!tp)
				{
					fprintf(stderr, "%s: Can't allocate filename!\n",
						MyName);
					continue;
				}
				sprintf(tp, "%s.dds", np);
				strlower(tp);
				refers_to(fname, tp);
				sprintf(tp, "%s.tga", np);
				strlower(tp);
				refers_to(fname, tp);
				sprintf(tp, "%s.txi", np);
				strlower(tp);
				refers_to(fname, tp);
				free(tp);
			}
		}
	}
	fclose(fp);
	if (cmd)
		free(cmd);
}

void write_refs(struct nwn_set* s)
{
	int gtcnt;
	int i;
	char* cp;
	char* setname;

	setname = malloc(5 + strlen(s->General.Name));
	if (!setname)
	{
		fprintf(stderr, "%s: Can't allocate setname!\n", MyName);
		return;
	}
	sprintf(setname, "%s.set", s->General.Name);
	strlower(setname);

	cp = malloc(11 + strlen(s->General.Name));
	if (!cp)
	{
		fprintf(stderr, "%s: Can't allocate filename!\n", MyName);
		return;
	}

	sprintf(cp, "%spal.itp", s->General.Name);
	strlower(cp);
	refers_to(setname, cp);

	sprintf(cp, "%spalstd.itp", s->General.Name);
	strlower(cp);
	refers_to(setname, cp);

	sprintf(cp, "%s.ini", s->General.Name);
	strlower(cp);
	refers_to(setname, cp);

	sprintf(cp, "%s_edge.2da", s->General.Name);
	strlower(cp);
	refers_to(setname, cp);
	if (access(cp, 0) == 0)
	{
		FILE* fp;
		char buf[BUFSIZ];
		char dex[BUFSIZ];
		char cor1[BUFSIZ];
		char edge[BUFSIZ];
		char cor2[BUFSIZ];
		char height[BUFSIZ];
		char model[BUFSIZ];

		/* need to read this to get the edge models */
		fp = fopen(cp, "r");
		if (!fp)
		{
			fprintf(stderr, "%s: Can't open <%s>!\n", MyName, cp);
		}
		else
		{
			while (fgets(buf, sizeof buf, fp) == buf)
			{
				char* rp;

				if (6 != sscanf(buf, "%s %s %s %s %s %s\n", dex, cor1, edge, cor2, height, model))
					continue;
				if ((rp = strchr(model, '\r')) != 0)
					*rp = '\0';
				if ((rp = strchr(model, '\n')) != 0)
					*rp = '\0';
				rp = model + strlen(model);

				strcpy(rp, ".mdl");
				strlower(model);
				refers_to(cp, model);

				if (access(model, 0) == 0)
					do_mdl_file(model);

				strcpy(rp, ".wok");
				refers_to(cp, model);
			}
			fclose(fp);
		}
	}

	sprintf(cp, "%s__env.txi", s->General.Name);
	strlower(cp);
	refers_to(setname, cp);

	if (access(cp, 0) == 0)
	{
		FILE* fp;
		char buf[BUFSIZ];

		/* need to read this to see if there's a "filerange" statement */
		fp = fopen(cp, "r");
		if (!fp)
		{
			fprintf(stderr, "%s: Can't open <%s>!\n", MyName, cp);
		}
		else
		{
			while (fgets(buf, sizeof buf, fp) == buf)
			{
				char* p = strchr(buf, 'f');

				if (!p)
					continue;
				if (strncmp(p, "filerange ", 10) == 0)
				{
					int nenv = atoi(p + 10);
					char* ep = malloc(12 + strlen(s->General.Name));

					if (!ep)
					{
						fprintf(stderr, "%s: Can't open <%s>!\n", MyName, cp);
						continue;
					}
					for (i = 0; i < nenv; ++i)
					{
						sprintf(ep, "%s__env%d.tga", s->General.Name, i);
						strlower(ep);
						refers_to(cp, ep);
					}
				}
			}
			fclose(fp);
		}
	}
	free(cp);

	cp = malloc(5 + strlen(s->General.EnvMap));
	if (!cp)
	{
		fprintf(stderr, "%s: Can't allocate filename!\n", MyName);
		return;
	}
	sprintf(cp, "%s.tga", s->General.EnvMap);
	strlower(cp);
	refers_to(setname, cp);
	free(cp);

	cp = strdup("loadscreens.2da");
	refers_to(setname, cp);
	if (access(cp, 0) == 0)
	{
		FILE* fp;
		char buf[BUFSIZ];
		char dex[BUFSIZ];
		char label[BUFSIZ];
		char script[BUFSIZ];
		char resref[BUFSIZ];
		char tileset[BUFSIZ];
		char strref[BUFSIZ];

		/* need to read this to get the TGAs */
		fp = fopen(cp, "r");
		if (!fp)
		{
			fprintf(stderr, "%s: Can't open <%s>!\n", MyName, cp);
		}
		else
		{
			while (fgets(buf, sizeof buf, fp) == buf)
			{
				char* rp;

				if (6 != sscanf(buf, "%s %s %s %s %s %s\n", dex, label, script, resref, tileset, strref))
					continue;
				if (strcasecmp(tileset, s->General.Name) == 0)
				{
					rp = &resref[strlen(resref)];
					strlower(resref);
					strcpy(rp, ".tga");
					refers_to(cp, resref);
					strcpy(rp, "s.tga");
					refers_to(cp, resref);
				}
			}
			fclose(fp);
		}
	}
	free(cp);

	cp = strdup("doortypes.2da");
	refers_to(setname, cp);
	if (access(cp, 0) == 0)
	{
		FILE* fp;
		char buf[BUFSIZ];
		char dex[BUFSIZ];
		char label[BUFSIZ];
		char model[BUFSIZ];
		char tileset[BUFSIZ];
		char resref[BUFSIZ];
		char strref[BUFSIZ];
		char block[BUFSIZ];
		char visible[BUFSIZ];
		char sound[BUFSIZ];

		/* need to read this to get the TGAs */
		fp = fopen(cp, "r");
		if (!fp)
		{
			fprintf(stderr, "%s: Can't open <%s>!\n", MyName, cp);
		}
		else
		{
			while (fgets(buf, sizeof buf, fp) == buf)
			{
				char* rp;

				if (9 != sscanf(buf, "%s %s %s %s %s %s %s %s %s\n", dex, label, model, tileset, resref, strref, block, visible, sound))
					continue;
				if (strcasecmp(tileset, s->General.Name) == 0)
				{
					rp = &model[strlen(model)];
					strlower(model);
					strcpy(rp, ".dwk");
					refers_to(cp, model);
					strcpy(rp, ".mdl");
					refers_to(cp, model);

					rp = &resref[strlen(resref)];
					strlower(resref);
					strcpy(rp, ".utd");
					refers_to(cp, resref);
				}
			}
			fclose(fp);
		}
	}
	free(cp);

	gtcnt = vlen(s->Tiles);
	for (i = 0; i < gtcnt; ++i)
	{
		struct nwn_set_tile* tp = vsubig(s->Tiles, i);
		char* fname;

		/* might not have a model (?) */
		if (tp->Model)
		{
			fname = malloc(5 + strlen(tp->Model));
			if (!fname)
			{
				fprintf(stderr, "%s: Can't allocate filename!\n", MyName);
				continue;
			}
			sprintf(fname, "%s.mdl", tp->Model);
			strlower(fname);
			refers_to(setname, fname);
			if (access(fname, 0) == 0)
				do_mdl_file(fname);
			sprintf(fname, "%s.wok", tp->Model);
			strlower(fname);
			refers_to(setname, fname);
			free(fname);
		}
		else
		{
			fprintf(stderr, "Warning: Tile%d has no model!\n", i);
		}

		/* might not have an image map */
		if (tp->ImageMap2D)
		{
			fname = malloc(5 + strlen(tp->ImageMap2D));
			if (!fname)
			{
				fprintf(stderr, "%s: Can't allocate filename!\n", MyName);
				continue;
			}
#if 0
			sprintf(fname, "%s.dds", tp->ImageMap2D);
			strlower(fname);
			refers_to(setname, fname);
#endif
			sprintf(fname, "%s.tga", tp->ImageMap2D);
			strlower(fname);
			refers_to(setname, fname);
			free(fname);
		}
	}
}
