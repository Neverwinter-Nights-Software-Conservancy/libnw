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
#include	"ute.h"
#include	"object.h"

static struct v* copy_CreatureList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_ute_creaturelist* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't reallocate nwn_ute_creaturelist!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, Appearance, si32)
			else asgn(oop, tp, CR, f)
			else asgn(oop, tp, SingleSpawn, ui8)
			else asgnrr(oop, tp, ResRef)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in ute_creaturelist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

struct nwn_ute* plist2ute(struct v* pp)
{
	struct nwn_ute* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an nwn_ute!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		asgn(op, ap, Active, ui8)
		else asgn(op, ap, Difficulty, si32)
		else asgn(op, ap, DifficultyIndex, si32)
		else asgn(op, ap, Faction, ui32)
		else asgn(op, ap, MaxCreatures, si32)
		else asgn(op, ap, PaletteID, ui8)
		else asgn(op, ap, PlayerOnly, ui8)
		else asgn(op, ap, RecCreatures, si32)
		else asgn(op, ap, Reset, ui8)
		else asgn(op, ap, ResetTime, si32)
		else asgn(op, ap, Respawns, si32)
		else asgn(op, ap, SpawnOption, si32)
		else asgnls(op, ap, LocalizedName)
		else asgnrr(op, ap, OnEntered)
		else asgnrr(op, ap, OnExhausted)
		else asgnrr(op, ap, OnExit)
		else asgnrr(op, ap, OnHeartbeat)
		else asgnrr(op, ap, OnUserDefined)
		else asgnrr(op, ap, TemplateResRef)
		else asgns(op, ap, Comment)
		else asgns(op, ap, Tag)
		else if (strcmp(op->name, "CreatureList") == 0)
			ap->CreatureList = copy_CreatureList(op);
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in UTE resource!\n", MyName, op->name);
			return 0;
		}
	}
	return ap;
}
