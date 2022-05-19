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

char* nw_set = 0;
struct nwn_set set;

char* nw_inp_dir = 0;
char* tsdir = 0;

int vflag = 0;

char* MyName = 0;

extern int nwset_debug;

extern char* read_set_file(char* name, int* leng);
extern void write_set_file(struct nwn_set* s);
extern void add_prules(void);
extern void adj_doors(void);
extern char* dirname(char* fname);

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

	tsdir = dirname(nw_set);

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

	add_prules();

	adj_doors();

	write_set_file(&set);

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

void adj_doors(void)
{
	int i;

	for (i = 0; i < vlen(set.Tiles); ++i)
	{
		struct nwn_set_tile* tp = vsubig(set.Tiles, i);
		int j;

		for (j = 0; j < vlen(tp->Doors); ++j)
		{
			struct nwn_set_tile_door* dp = vsubig(tp->Doors, j);

			if (dp->Type != 0)
			{
				char buf[BUFSIZ];

				fprintf(stderr, "%s: Custom door TILE%dDOOR%d has type=%d.\n",
					MyName, i, j, dp->Type);
				fprintf(stderr, "Enter correct type, or [ENTER] to keep it:");
				fflush(stderr);
				fgets(buf, sizeof buf, stdin);
				if (buf[0] != '\r' && buf[0] != '\n')
				{
					dp->Type = atoi(buf);
					fprintf(stderr, "Changed to %d.\n", dp->Type);
				}
				else
					fprintf(stderr, "Unchanged.\n");
			}
		}
	}
}

void add_prules()
{
	int nterr = vlen(set.Terrains);
	int height = 1 + set.General.HasHeightTransition;
	int i;
	int j;
	int k;
	int l;
	int missing = 0;

	if (!set.PrimaryRules)
		set.PrimaryRules = vnew(nterr * nterr * height * height);

	for (i = 0; i < nterr; ++i)
	{
		struct nwn_set_terrain* pp = vsubig(set.Terrains, i);

		for (j = 0; j < nterr; ++j)
		{
			struct nwn_set_terrain* ap = vsubig(set.Terrains, j);

			for (k = 0; k < height; ++k)
			{
				for (l = 0; l < height; ++l)
				{
					struct nwn_set_rule* rp;
					int m;
					int found;

					/* see if the proposed rule already exists */
					found = 0;
					for (m = 0; m < vlen(set.PrimaryRules); ++m)
					{
						struct nwn_set_rule* ep = vsubig(set.PrimaryRules, m);
						if (k != ep->PlacedHeight)
							continue;
						if (l != ep->AdjacentHeight)
							continue;
						if (strcmp(pp->Name, ep->Placed) != 0)
							continue;
						if (strcmp(ap->Name, ep->Adjacent) != 0)
							continue;
						found = 1;
						break;
					}
					/* yep, forget it */
					if (found)
						continue;
					/* nope, build a new rule */
					rp = malloc(sizeof *rp);
					rp->Placed = strdup(pp->Name);
					rp->PlacedHeight = k;
					rp->Adjacent = strdup(ap->Name);
					rp->AdjacentHeight = l;
					if (i != j)
						rp->Changed = strdup("*FIXME*");
					else
						rp->Changed = strdup(pp->Name);
					if (k != l)
						rp->ChangedHeight = -1;
					else
						rp->ChangedHeight = k;
					vapp(set.PrimaryRules, rp);
					++missing;
				}
			}
		}
	}
	if (missing)
		fprintf(stderr, "%s: %d missing Primary Rules added.\n",
			MyName, missing);
}

void write_set_file(struct nwn_set* s)
{
	int gtcnt;
	int cnt;
	int i;

	printf("; NEVERWINTER NIGHTS TILESET FILE\n");
	printf("; DO NOT EDIT MANUALLY - UNLESS YOU KNOW WHAT YOU ARE DOING\n");
	printf("\n");

	printf("[GENERAL]\n");
	printf("Name=%s\n", s->General.Name);
	printf("Type=%s\n", s->General.Type);
	printf("Version=%s\n", s->General.Version);
	printf("Interior=%d\n", s->General.Interior);
	printf("HasHeightTransition=%d\n", s->General.HasHeightTransition);
	printf("EnvMap=%s\n", s->General.EnvMap);
	printf("Transition=%d\n", s->General.Transition);
	printf("DisplayName=%d\n", s->General.DisplayName);
	printf("Border=%s\n", s->General.Border);
	printf("Default=%s\n", s->General.Default);
	printf("Floor=%s\n", s->General.Floor);
	printf("\n");

	printf("[GRASS]\n");
	printf("Grass=%d\n", s->Grass.Grass);
	/* only display grass attributes if there is grass */
	if (s->Grass.Grass)
	{
		printf("Density=%5.3f\n", s->Grass.Density);
		printf("Height=%5.3f\n", s->Grass.Height);
		printf("AmbientRed=%5.3f\n", s->Grass.Ambient.r);
		printf("AmbientGreen=%5.3f\n", s->Grass.Ambient.g);
		printf("AmbientBlue=%5.3f\n", s->Grass.Ambient.b);
		printf("DiffuseRed=%5.3f\n", s->Grass.Diffuse.r);
		printf("DiffuseGreen=%5.3f\n", s->Grass.Diffuse.g);
		printf("DiffuseBlue=%5.3f\n", s->Grass.Diffuse.b);
	}
	printf("\n");

	printf("[TERRAIN TYPES]\n");
	cnt = vlen(s->Terrains);
	printf("Count=%d\n", cnt);
	printf("\n");
	for (i = 0; i < cnt; ++i)
	{
		struct nwn_set_terrain* tp = vsubig(s->Terrains, i);

		printf("[TERRAIN%d]\n", i);
		printf("Name=%s\n", tp->Name);
		printf("StrRef=%d\n", tp->StrRef);
		printf("\n");
	}

	printf("[CROSSER TYPES]\n");
	cnt = vlen(s->Crossers);
	printf("Count=%d\n", cnt);
	printf("\n");
	for (i = 0; i < cnt; ++i)
	{
		struct nwn_set_terrain* cp = vsubig(s->Crossers, i);

		printf("[CROSSER%d]\n", i);
		printf("Name=%s\n", cp->Name);
		printf("StrRef=%d\n", cp->StrRef);
		printf("\n");
	}

	printf("[PRIMARY RULES]\n");
	cnt = vlen(s->PrimaryRules);
	printf("Count=%d\n", cnt);
	printf("\n");
	for (i = 0; i < cnt; ++i)
	{
		struct nwn_set_rule* rp = vsubig(s->PrimaryRules, i);

		printf("[PRIMARY RULE%d]\n", i);
		printf("Placed=%s\n", rp->Placed);
		printf("PlacedHeight=%d\n", rp->PlacedHeight);
		printf("Adjacent=%s\n", rp->Adjacent);
		printf("AdjacentHeight=%d\n", rp->AdjacentHeight);
		printf("Changed=%s\n", rp->Changed);
		printf("ChangedHeight=%d\n", rp->ChangedHeight);
		printf("\n");
	}

	printf("[SECONDARY RULES]\n");
	cnt = vlen(s->SecondaryRules);
	printf("Count=%d\n", cnt);
	printf("\n");
#if 0
	/*
	** alas, there are no secondary rules in any of the BioWare-supplied
	**	tilesets, so we don't *really* know what's supposed to be in them.
	*/
	for (i = 0; i < cnt; ++i)
	{
		struct nwn_set_rule* rp = vsubig(s->SecondaryRules, i);

		printf("[SECONDARY RULE%d]\n", i);
		printf("Placed=%s\n", rp->Placed);
		printf("PlacedHeight=%d\n", rp->PlacedHeight);
		printf("Adjacent=%s\n", rp->Adjacent);
		printf("AdjacentHeight=%d\n", rp->AdjacentHeight);
		printf("Changed=%s\n", rp->Changed);
		printf("ChangedHeight=%d\n", rp->ChangedHeight);
		printf("\n");
	}
#endif

	printf("[TILES]\n");
	gtcnt = vlen(s->Tiles);
	printf("Count=%d\n", gtcnt);
	printf("\n");
	for (i = 0; i < gtcnt; ++i)
	{
		struct nwn_set_tile* tp = vsubig(s->Tiles, i);
		int dcnt = vlen(tp->Doors);
		int scnt = vlen(tp->Sounds);

		printf("[TILE%d]\n", i);
		printf("Model=%s\n", tp->Model);
		printf("WalkMesh=%s\n", tp->WalkMesh);
		printf("TopLeft=%s\n", tp->TopLeft);
		printf("TopLeftHeight=%d\n", tp->TopLeftHeight);
		printf("TopRight=%s\n", tp->TopRight);
		printf("TopRightHeight=%d\n", tp->TopRightHeight);
		printf("BottomLeft=%s\n", tp->BottomLeft);
		printf("BottomLeftHeight=%d\n", tp->BottomLeftHeight);
		printf("BottomRight=%s\n", tp->BottomRight);
		printf("BottomRightHeight=%d\n", tp->BottomRightHeight);
		printf("Top=%s\n", tp->Top ? tp->Top : "");
		printf("Right=%s\n", tp->Right ? tp->Right : "");
		printf("Bottom=%s\n", tp->Bottom ? tp->Bottom : "");
		printf("Left=%s\n", tp->Left ? tp->Left : "");
		printf("MainLight1=%d\n", tp->MainLight1);
		printf("MainLight2=%d\n", tp->MainLight2);
		printf("SourceLight1=%d\n", tp->SourceLight1);
		printf("SourceLight2=%d\n", tp->SourceLight2);
		printf("AnimLoop1=%d\n", tp->AnimLoop1);
		printf("AnimLoop2=%d\n", tp->AnimLoop2);
		printf("AnimLoop3=%d\n", tp->AnimLoop3);
		printf("Doors=%d\n", dcnt);
		printf("Sounds=%d\n", scnt);
		printf("PathNode=%s\n", tp->PathNode);
		printf("Orientation=%d\n", tp->Orientation);
		/*
		** only display VisibilityNode (and VisibilityOrientation)
		**	if there is a VisibilityNode specified.
		*/
		if (tp->VisibilityNode)
		{
			printf("VisibilityNode=%s\n", tp->VisibilityNode);
			printf("VisibilityOrientation=%d\n", tp->VisibilityOrientation);
		}
		/*
		** only display DoorVisibilityNode (and DoorVisibilityOrientation)
		**	if there is a DoorVisibilityNode specified.
		*/
		if (tp->DoorVisibilityNode)
		{
			printf("DoorVisibilityNode=%s\n", tp->DoorVisibilityNode);
			printf("DoorVisibilityOrientation=%d\n", tp->DoorVisibilityOrientation);
		}
		printf("ImageMap2D=%s\n", tp->ImageMap2D);
		printf("\n");
		/*
		** if there are any doors on this tile, display them here.
		*/
		if (dcnt)
		{
			int j;

			for (j = 0; j < dcnt; ++j)
			{
				struct nwn_set_tile_door* dp = vsubig(tp->Doors, j);

				printf("[TILE%dDOOR%d]\n", i, j);
				printf("Type=%d\n", dp->Type);
				printf("X=%.2f\n", dp->X);
				printf("Y=%.2f\n", dp->Y);
				printf("Z=%.2f\n", dp->Z);
				printf("Orientation=%.1f\n", dp->Orientation);
				printf("\n");
			}
		}
		/*
		** if there are any sounds on this tile, display them here.
		*/
		if (scnt)
		{
		}
	}

	printf("[GROUPS]\n");
	cnt = vlen(s->Groups);
	printf("Count=%d\n", cnt);
	printf("\n");
	for (i = 0; i < cnt; ++i)
	{
		struct nwn_set_group* gp = vsubig(s->Groups, i);
		int tcnt = vlen(gp->Tiles);
		int j;

		printf("[GROUP%d]\n", i);
		printf("Name=%s\n", gp->Name);
		printf("StrRef=%d\n", gp->StrRef);
		printf("Rows=%d\n", gp->Rows);
		printf("Columns=%d\n", gp->Columns);
		for (j = 0; j < tcnt; ++j)
		{
			struct nwn_set_tile* tp = vsubig(gp->Tiles, j);
			int k;

			if (!tp)
				continue;
			for (k = 0; k < gtcnt; ++k)
			{
				if (tp == vsubig(s->Tiles, k))
				{
					printf("Tile%d=%d\n", j, k);
					break;
				}
			}
			if (k >= gtcnt)
			{
				printf("; LOST GROUP%d TILE%d!\n", i, j);
				fprintf(stderr, "%s: Error: Lost Group %d Tile %d!\n",
					MyName, i, j);
			}
		}
		printf("\n");
	}
}

char* dirname(char* fname)
{
	char* cp;
	char* rp;

	cp = strrchr(fname, '/');
	if (!cp)
		return strdup(".");
	if (cp == fname)
		return strdup("/");
	rp = malloc((cp - fname) + 1);
	strncpy(rp, fname, cp - fname);
	rp[cp - fname] = '\0';
	return rp;
}
