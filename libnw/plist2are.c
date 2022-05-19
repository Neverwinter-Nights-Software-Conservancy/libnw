#include	<config.h>
#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include	<memory.h>
# endif
# include	<string.h>
#endif
#include	"global.h"
#include	"are.h"
#include	"object.h"

static struct v* copy_Tile_List(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_are_tile* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't reallocate Tile!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, Tile_ID, si32)
			else asgn(oop, tp, Tile_Orientation, si32)
			else asgn(oop, tp, Tile_Height, si32)
			else asgn(oop, tp, Tile_MainLight1, ui8)
			else asgn(oop, tp, Tile_MainLight2, ui8)
			else asgn(oop, tp, Tile_SrcLight1, ui8)
			else asgn(oop, tp, Tile_SrcLight2, ui8)
			else asgn(oop, tp, Tile_AnimLoop1, ui8)
			else asgn(oop, tp, Tile_AnimLoop2, ui8)
			else asgn(oop, tp, Tile_AnimLoop3, ui8)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in Tile_List!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

struct nwn_are* plist2are(struct v* pp)
{
	struct nwn_are* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an area!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		asgn(op, ap, ChanceLightning, si32)
		else asgn(op, ap, ChanceRain, si32)
		else asgn(op, ap, ChanceSnow, si32)
		else asgn(op, ap, Comments, s)
		else asgn(op, ap, Creator_ID, si32)
		else asgn(op, ap, DayNightCycle, ui8)
		else asgn(op, ap, Flags, ui32)
		else asgn(op, ap, Height, si32)
		else asgn(op, ap, ID, si32)
		else asgn(op, ap, IsNight, ui8)
		else asgn(op, ap, LightingScheme, ui8)
		else asgn(op, ap, LoadScreenID, ui16)
		else asgn(op, ap, ModListenCheck, si32)
		else asgn(op, ap, ModSpotCheck, si32)
		else asgn(op, ap, MoonAmbientColor, ui32)
		else asgn(op, ap, MoonDiffuseColor, ui32)
		else asgn(op, ap, MoonFogAmount, ui8)
		else asgn(op, ap, MoonFogColor, ui32)
		else asgn(op, ap, MoonShadows, ui8)
		else asgn(op, ap, NoRest, ui8)
		else asgn(op, ap, PlayerVsPlayer, ui8)
		else asgn(op, ap, ShadowOpacity, ui8)
		else asgn(op, ap, SunAmbientColor, ui32)
		else asgn(op, ap, SunDiffuseColor, ui32)
		else asgn(op, ap, SunFogAmount, ui8)
		else asgn(op, ap, SunFogColor, ui32)
		else asgn(op, ap, SunShadows, ui8)
		else asgn(op, ap, Version, ui32)
		else asgn(op, ap, Width, si32)
		else asgn(op, ap, WindPower, si32)
		else asgnls(op, ap, Name)
		else asgnrr(op, ap, OnEnter)
		else asgnrr(op, ap, OnExit)
		else asgnrr(op, ap, OnHeartbeat)
		else asgnrr(op, ap, OnUserDefined)
		else asgnrr(op, ap, ResRef)
		else asgnrr(op, ap, Tileset)
		else asgns(op, ap, Tag)
		else if (strcmp(op->name, "Tile_List") == 0)
			ap->Tile_List = copy_Tile_List(op);
		else if (strcmp(op->name, "Expansion_List") == 0)
		{
			; // list
		}
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in ARE resource!\n", MyName, op->name);
			return 0;
		}
	}
	return ap;
}
