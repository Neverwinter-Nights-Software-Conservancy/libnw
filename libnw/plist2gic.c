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
#include	"gic.h"
#include	"object.h"

static struct v* copy_Placeable_List(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_placeable* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.placeable!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.placeablelist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_WaypointList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_waypoint* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.waypoint!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.waypointlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_TriggerList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_trigger* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.trigger!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.triggerlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_StoreList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_store* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.store!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.storelist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_SoundList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_sound* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.sound!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, PlayInToolset, ui8)
			else asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.soundlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_List(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_list* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.list!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.list!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_Encounter_List(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_encounter* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.encounter!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			//else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.encounterlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_Door_List(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_door* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.door!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.doorlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_Creature_List(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_gic_creature* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate gic.creature!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Comment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in gic.creaturelist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

struct nwn_gic* plist2gic(struct v* pp)
{
	struct nwn_gic* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an nwn_gic!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		if (strcmp(op->name, "Creature List") == 0)
			ap->Creature_List = copy_Creature_List(op);
		else if (strcmp(op->name, "Door List") == 0)
			ap->Door_List = copy_Door_List(op);
		else if (strcmp(op->name, "Encounter List") == 0)
			ap->Encounter_List = copy_Encounter_List(op);
		else if (strcmp(op->name, "List") == 0)
			ap->List = copy_List(op);
		else if (strcmp(op->name, "SoundList") == 0)
			ap->SoundList = copy_SoundList(op);
		else if (strcmp(op->name, "StoreList") == 0)
			ap->StoreList = copy_StoreList(op);
		else if (strcmp(op->name, "TriggerList") == 0)
			ap->TriggerList = copy_TriggerList(op);
		else if (strcmp(op->name, "WaypointList") == 0)
			ap->WaypointList = copy_WaypointList(op);
		else if (strcmp(op->name, "Placeable List") == 0)
			ap->Placeable_List = copy_Placeable_List(op);
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in GIC resource!\n", MyName, op->name);
			return 0;
		}
	}
	return ap;
}
