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
#include	"ifo.h"
#include	"object.h"

static struct v* copy_Mod_HakList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_ifo_hak* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't reallocate Mod_HakList entry!\n",
				MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgns(oop, tp, Mod_Hak)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in Mod_HakList!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_Mod_Area_list(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_ifo_area* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't reallocate Mod_Area_list entry!\n",
				MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, ObjectId, ui32)
			else asgnrr(oop, tp, Area_Name)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in Mod_Area_list!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

struct nwn_ifo* plist2ifo(struct v* pp)
{
	struct nwn_ifo* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an nwn_ifo!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		asgn(op, ap, Expansion_Pack, ui16)
		else asgn(op, ap, Mod_Creator_ID, si32)
		else asgn(op, ap, Mod_DawnHour, ui8)
		else asgn(op, ap, Mod_DuskHour, ui8)
		else asgn(op, ap, Mod_Effect_NxtId, ui64)
		else asgn(op, ap, Mod_Entry_Dir_X, f)
		else asgn(op, ap, Mod_Entry_Dir_Y, f)
		else asgn(op, ap, Mod_Entry_Dir_Z, f)
		else asgn(op, ap, Mod_Entry_X, f)
		else asgn(op, ap, Mod_Entry_Y, f)
		else asgn(op, ap, Mod_Entry_Z, f)
		else asgn(op, ap, Mod_IsNWMFile, ui8)
		else asgn(op, ap, Mod_IsSaveGame, ui8)
		else asgn(op, ap, Mod_MinPerHour, ui8)
		else asgn(op, ap, Mod_NextCharId0, ui32)
		else asgn(op, ap, Mod_NextCharId1, ui32)
		else asgn(op, ap, Mod_NextObjId0, ui32)
		else asgn(op, ap, Mod_NextObjId1, ui32)
		else asgn(op, ap, Mod_StartDay, ui8)
		else asgn(op, ap, Mod_StartHour, ui8)
		else asgn(op, ap, Mod_StartMiliSec, ui16)
		else asgn(op, ap, Mod_StartMinute, ui16)
		else asgn(op, ap, Mod_StartMonth, ui8)
		else asgn(op, ap, Mod_StartSecond, ui16)
		else asgn(op, ap, Mod_StartYear, ui8)
		else asgn(op, ap, Mod_Transition, ui32)
		else asgn(op, ap, Mod_Version, ui32)
		else asgn(op, ap, Mod_XPScale, ui8)
		else asgnls(op, ap, Mod_Description)
		else asgnls(op, ap, Mod_Name)
		else asgnrr(op, ap, Mod_Entry_Area)
		else asgnrr(op, ap, Mod_NWMResName)
		else asgnrr(op, ap, Mod_OnAcquirItem)
		else asgnrr(op, ap, Mod_OnActvtItem)
		else asgnrr(op, ap, Mod_OnClientEntr)
		else asgnrr(op, ap, Mod_OnClientLeav)
		else asgnrr(op, ap, Mod_OnCutsnAbort)
		else asgnrr(op, ap, Mod_OnHeartbeat)
		else asgnrr(op, ap, Mod_OnModLoad)
		else asgnrr(op, ap, Mod_OnModStart)
		else asgnrr(op, ap, Mod_OnPlrDeath)
		else asgnrr(op, ap, Mod_OnPlrDying)
		else asgnrr(op, ap, Mod_OnPlrLvlUp)
		else asgnrr(op, ap, Mod_OnPlrRest)
		else asgnrr(op, ap, Mod_OnSpawnBtnDn)
		else asgnrr(op, ap, Mod_OnUnAqreItem)
		else asgnrr(op, ap, Mod_OnUsrDefined)
		else asgnrr(op, ap, Mod_StartMovie)
		else asgns(op, ap, Mod_Hak)
		else asgns(op, ap, Mod_MinGameVer)
		else asgns(op, ap, Mod_Tag)
		else if (strcmp(op->name, "Mod_ID") == 0)
		{
			ap->Mod_ID.len = op->val.blob.len;
			ap->Mod_ID.data = malloc(ap->Mod_ID.len);
			if (!ap->Mod_ID.data)
			{
				fprintf(stderr, "%s: Can't allocate blob!\n", MyName);
				return 0;
			}
			memcpy(ap->Mod_ID.data, op->val.blob.data, ap->Mod_ID.len);
		}
		else if (strcmp(op->name, "Mod_Expan_List") == 0)
		{
			; // TODO: Mod_Expan_List
		}
		else if (strcmp(op->name, "Mod_CutSceneList") == 0)
		{
			; // TODO: Mod_CutSceneList
		}
		else if (strcmp(op->name, "Mod_GVar_List") == 0)
		{
			; // TODO: Mod_GVar_List
		}
		else if (strcmp(op->name, "Creature List") == 0)
		{
			; // TODO: Creature_List
		}
		else if (strcmp(op->name, "Mod_Tokens") == 0)
		{
			; // TODO: Mod_Tokens
		}
		else if (strcmp(op->name, "VarTable") == 0)
		{
			; // TODO: VarTable
		}
		else if (strcmp(op->name, "EventQueue") == 0)
		{
			; // TODO: EventQueue
		}
		else if (strcmp(op->name, "Mod_PlayerList") == 0)
		{
			; // TODO: Mod_PlayerList
		}
		else if (strcmp(op->name, "Mod_TURDList") == 0)
		{
			; // TODO: Mod_TURDList
		}
		else if (strcmp(op->name, "Mod_HakList") == 0)
			ap->Mod_HakList = copy_Mod_HakList(op);
		else if (strcmp(op->name, "Mod_Area_list") == 0)
			ap->Mod_Area_list = copy_Mod_Area_list(op);
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in IFO resource!\n", MyName, op->name);
			return 0;
		}
	}
	return ap;
}
