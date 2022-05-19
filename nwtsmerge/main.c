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
#include	"key.h"
#include	"bin.h"
#include	"bif.h"
#include	"rgb.h"
#include	"v.h"
#include	"set.h"
#include	"restyp.h"
#include	"str.h"

int vflag = 0;
char* nw_inp_dir = 0;

char* nw_set1 = 0;
char* nw_set2 = 0;

struct nwn_set set1;
struct nwn_set set2;

char* MyName = 0;

extern int nwset_debug;
extern int nwset__flex_debug;

extern char* read_set_file(char* name, int* leng);
extern void write_set_file(struct nwn_set* sp);
extern void combine();

static void usage()
{
	fprintf(stderr, "%s: Usage: %s -1 set1 -2 set2\n",
		MyName, MyName);
}

int main(int argc, char** argv)
{
	int c;
	char* setfile1;
	char* setfile2;
	int setleng1;
	int setleng2;

	MyName = argv[0];

	while ((c = getopt(argc, argv, "1:2:ly?")) != EOF)
	{
		switch (c)
		{
		case '1':
			nw_set1 = optarg;
			break;

		case '2':
			nw_set2 = optarg;
			break;

		case 'l':
			nwset__flex_debug = !nwset__flex_debug;
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

	if (!nw_set1)
	{
		fprintf(stderr, "%s: must use -1 to specify 1st tileSet name!\n",
			MyName);
		usage();
		return 1;
	}

	if (!nw_set2)
	{
		fprintf(stderr, "%s: must use -2 to specify 2nd tileSet name!\n",
			MyName);
		usage();
		return 1;
	}

	setfile1 = read_set_file(nw_set1, &setleng1);
	if (!setfile1)
		return 3;

	if (nw_parse_set(setfile1, setleng1, &set1))
	{
		fprintf(stderr, "%s: could not parse %s!\n", MyName, nw_set1);
		return 3;
	}

	setfile2 = read_set_file(nw_set2, &setleng2);
	if (!setfile2)
		return 3;

	if (nw_parse_set(setfile2, setleng2, &set2))
	{
		fprintf(stderr, "%s: could not parse %s!\n", MyName, nw_set2);
		return 3;
	}

	combine();

	write_set_file(&set1);

	return 0;
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

void combine()
{
	int i;
	int j;
	int n1;
	int n2;
	int matched;

	/* combine terrain types from set2 into set1 */
	n1 = vlen(set1.Terrains);
	n2 = vlen(set2.Terrains);

	/* for each terrain in set2 */
	for (i = 0; i < n2; ++i)
	{
		struct nwn_set_terrain* t1;
		struct nwn_set_terrain* t2 = vsubig(set2.Terrains, i);

		matched = 0;

		/* see if it matches one already in set1 */
		for (j = 0; j < n1; ++j)
		{
			t1 = vsubig(set1.Terrains, j);
			/* there is no sanity clause.... */
			if (!t1) abort();
			if (!t1->Name) abort();
			if (!t2) abort();
			if (!t2->Name) abort();
			if (strcmp(t1->Name, t2->Name) == 0)
			{
				matched = 1;
				break;
			}
		}
		/* if no match, add it to set1 */
		if (!matched)
			vapp(set1.Terrains, t2);
	}

	/* combine crosser types from set2 into set1 */
	n1 = vlen(set1.Crossers);
	n2 = vlen(set2.Crossers);

	/* for each crosser in set2 */
	for (i = 0; i < n2; ++i)
	{
		struct nwn_set_crosser* c1;
		struct nwn_set_crosser* c2 = vsubig(set2.Crossers, i);

		matched = 0;

		/* see if it matches one already in set1 */
		for (j = 0; j < n1; ++j)
		{
			c1 = vsubig(set1.Crossers, j);
			/* there is no sanity clause.... */
			if (!c1) abort();
			if (!c1->Name) abort();
			if (!c2) abort();
			if (!c2->Name) abort();
			if (strcmp(c1->Name, c2->Name) == 0)
			{
				matched = 1;
				break;
			}
		}
		/* if no match, add it to set1 */
		if (!matched)
			vapp(set1.Crossers, c2);
	}

	/*
	** this is probably insufficient; here we merge just as we have above;
	**	but it seems like all the combinations of a terrain type from
	**	set1 and a terrain type from set2 need to be added here.
	** we probably need to build a matrix of Placed+PlacedHeight
	**	vs. Adjacent+AdjacentHeight to fill in the otherwise missing rules.
	*/

	/* combine primary rules from set2 into set1 */
	n1 = vlen(set1.PrimaryRules);
	n2 = vlen(set2.PrimaryRules);

	/* for each primary rule in set2 */
	for (i = 0; i < n2; ++i)
	{
		struct nwn_set_rule* r1;
		struct nwn_set_rule* r2 = vsubig(set2.PrimaryRules, i);

		matched = 0;

		/* see if it matches one already in set1 */
		for (j = 0; j < n1; ++j)
		{
			r1 = vsubig(set1.PrimaryRules, j);
			if (r1->PlacedHeight == r2->PlacedHeight &&
				r1->AdjacentHeight == r2->AdjacentHeight &&
				r1->ChangedHeight == r2->ChangedHeight &&
				strcmp(r1->Placed, r2->Placed) == 0 &&
				strcmp(r1->Adjacent, r2->Adjacent) == 0 &&
				strcmp(r1->Changed, r2->Changed) == 0)
			{
				matched = 1;
				break;
			}
		}
		/* if no match, add it to set1 */
		if (!matched)
			vapp(set1.PrimaryRules, r2);
	}

	/* combine tiles from set2 into set1 */
	n1 = vlen(set1.Tiles);
	n2 = vlen(set2.Tiles);

	/* for each tile in set2 */
	for (i = 0; i < n2; ++i)
	{
		struct nwn_set_tile* t1;
		struct nwn_set_tile* t2 = vsubig(set2.Tiles, i);

		matched = 0;

		/* see if it matches one already in set1 */
		for (j = 0; j < n1; ++j)
		{
			t1 = vsubig(set1.Tiles, j);
			/* there is no sanity clause.... */
			if (!t1) abort();
			if (!t1->Model) abort();
			if (!t2) abort();
			if (!t2->Model) abort();
			/* there's got to be more than this.... */
			if (strcmp(t1->Model, t2->Model) == 0)
			{
				matched = 1;
				break;
			}
		}
		/* if no match, add it to set1 */
		if (!matched)
			vapp(set1.Tiles, t2);
	}

	/* combine groups from set2 into set1 */
	n1 = vlen(set1.Groups);
	n2 = vlen(set2.Groups);

	/* for each group in set2 */
	for (i = 0; i < n2; ++i)
	{
		struct nwn_set_group* g1;
		struct nwn_set_group* g2 = vsubig(set2.Groups, i);

		matched = 0;

		/* see if it matches one already in set1 */
		for (j = 0; j < n1; ++j)
		{
			g1 = vsubig(set1.Groups, j);
			/* there is no sanity clause.... */
			if (!g1) abort();
			if (!g1->Name) abort();
			if (!g2) abort();
			if (!g2->Name) abort();
			/* there's got to be more than this.... */
			if (strcmp(g1->Name, g2->Name) == 0)
			{
				matched = 1;
				break;
			}
		}
		/* if no match, add it to set1 */
		if (!matched)
			vapp(set1.Groups, g2);
	}
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
		// there are a few tiles that don't have image maps.
		printf("ImageMap2D=%s\n", tp->ImageMap2D ? tp->ImageMap2D : "");
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
