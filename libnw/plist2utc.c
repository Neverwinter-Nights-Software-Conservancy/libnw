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
#include	"utc.h"
#include	"object.h"

static struct v* copy_TemplateList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_template* tp = malloc(sizeof *tp);
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

			asgn(oop, tp, TemplateID, ui16)
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

static struct v* copy_SkillList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_skill* tp = malloc(sizeof *tp);
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

			asgn(oop, tp, Rank, ui8)
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

static struct v* copy_FeatList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_feat* tp = malloc(sizeof *tp);
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

			asgn(oop, tp, Feat, ui16)
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

static struct v* copy_SpecAbilityList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_specability* tp = malloc(sizeof *tp);
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

			asgn(oop, tp, Spell, ui16)
			else asgn(oop, tp, SpellFlags, ui8)
			else asgn(oop, tp, SpellCasterLevel, ui8)
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

static struct v* copy_MemorizedList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_class_memo* tp = malloc(sizeof *tp);
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

			asgn(oop, tp, Spell, si16)
			else asgn(oop, tp, SpellFlags, ui8)
			else asgn(oop, tp, SpellMetaMagic, ui8)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in utc.classlist.memolist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_KnownList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_class_known* tp = malloc(sizeof *tp);
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

			asgn(oop, tp, Spell, si16)
			else asgn(oop, tp, SpellFlags, ui8)
			else asgn(oop, tp, SpellMetaMagic, ui8)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in utc.classlist.knownlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_ClassList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_class* tp = malloc(sizeof *tp);
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

			asgn(oop, tp, Class, si32)
			else asgn(oop, tp, ClassLevel, si16)
			else if (strcmp(oop->name, "MemorizedList0") == 0)
				tp->MemorizedList0 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList1") == 0)
				tp->MemorizedList1 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList2") == 0)
				tp->MemorizedList2 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList3") == 0)
				tp->MemorizedList3 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList4") == 0)
				tp->MemorizedList4 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList5") == 0)
				tp->MemorizedList5 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList6") == 0)
				tp->MemorizedList6 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList7") == 0)
				tp->MemorizedList7 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList8") == 0)
				tp->MemorizedList8 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "MemorizedList9") == 0)
				tp->MemorizedList9 = copy_MemorizedList(oop);
			else if (strcmp(oop->name, "KnownList0") == 0)
				tp->KnownList0 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList1") == 0)
				tp->KnownList1 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList2") == 0)
				tp->KnownList2 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList3") == 0)
				tp->KnownList3 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList4") == 0)
				tp->KnownList4 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList5") == 0)
				tp->KnownList5 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList6") == 0)
				tp->KnownList6 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList7") == 0)
				tp->KnownList7 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList8") == 0)
				tp->KnownList8 = copy_KnownList(oop);
			else if (strcmp(oop->name, "KnownList9") == 0)
				tp->KnownList9 = copy_KnownList(oop);
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in utc.classlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_Equip_ItemList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_eqitem* tp = malloc(sizeof *tp);
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

			asgnrr(oop, tp, EquippedRes)
			else asgn(oop, tp, Dropable, ui8)
			else asgn(oop, tp, Pickpocketable, ui8)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in utc.equip_itemlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_ItemList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_utc_item* tp = malloc(sizeof *tp);
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

			asgnrr(oop, tp, InventoryRes)
			else asgn(oop, tp, Dropable, ui8)
			else asgn(oop, tp, Pickpocketable, ui8)
			else asgn(oop, tp, Repos_PosX, ui16)
			else asgn(oop, tp, Repos_Posy, ui16)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in utc.itemlist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

struct nwn_utc* plist2utc(struct v* pp)
{
	struct nwn_utc* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an nwn_utc!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		asgn(op, ap, Appearance_Head, ui8)
		else asgn(op, ap, Appearance_Type, ui16)
		else asgn(op, ap, ArmorPart_RFoot, ui8)
		else asgn(op, ap, BodyBag, ui8)
		else asgn(op, ap, BodyPart_Belt, ui8)
		else asgn(op, ap, BodyPart_LBicep, ui8)
		else asgn(op, ap, BodyPart_LFArm, ui8)
		else asgn(op, ap, BodyPart_LFoot, ui8)
		else asgn(op, ap, BodyPart_LHand, ui8)
		else asgn(op, ap, BodyPart_LShin, ui8)
		else asgn(op, ap, BodyPart_LShoul, ui8)
		else asgn(op, ap, BodyPart_LThigh, ui8)
		else asgn(op, ap, BodyPart_Neck, ui8)
		else asgn(op, ap, BodyPart_Pelvis, ui8)
		else asgn(op, ap, BodyPart_RBicep, ui8)
		else asgn(op, ap, BodyPart_RFArm, ui8)
		else asgn(op, ap, BodyPart_RHand, ui8)
		else asgn(op, ap, BodyPart_RShin, ui8)
		else asgn(op, ap, BodyPart_RShoul, ui8)
		else asgn(op, ap, BodyPart_RThigh, ui8)
		else asgn(op, ap, BodyPart_Torso, ui8)
		else asgn(op, ap, CRAdjust, si32)
		else asgn(op, ap, Cha, ui8)
		else asgn(op, ap, ChallengeRating, f)
		else asgn(op, ap, Color_Hair, ui8)
		else asgn(op, ap, Color_Skin, ui8)
		else asgn(op, ap, Color_Tattoo1, ui8)
		else asgn(op, ap, Color_Tattoo2, ui8)
		else asgn(op, ap, Con, ui8)
		else asgn(op, ap, CurrentHitPoints, si16)
		else asgn(op, ap, Dex, ui8)
		else asgn(op, ap, Disarmable, ui8)
		else asgn(op, ap, FactionID, ui16)
		else asgn(op, ap, Gender, ui8)
		else asgn(op, ap, GoodEvil, ui8)
		else asgn(op, ap, HitPoints, si16)
		else asgn(op, ap, Int, ui8)
		else asgn(op, ap, Interruptable, ui8)
		else asgn(op, ap, IsImmortal, ui8)
		else asgn(op, ap, IsPC, ui8)
		else asgn(op, ap, LawfulChaotic, ui8)
		else asgn(op, ap, MaxHitPoints, si16)
		else asgn(op, ap, NaturalAC, ui8)
		else asgn(op, ap, NoPermDeath, ui8)
		else asgn(op, ap, PaletteID, ui8)
		else asgn(op, ap, PerceptionRange, ui8)
		else asgn(op, ap, Phenotype, si32)
		else asgn(op, ap, Plot, ui8)
		else asgn(op, ap, PortraitId, ui16)
		else asgn(op, ap, Race, ui8)
		else asgn(op, ap, SoundSetFile, ui16)
		else asgn(op, ap, Str, ui8)
		else asgn(op, ap, Tail, ui8)
		else asgn(op, ap, WalkRate, si32)
		else asgn(op, ap, Wings, ui8)
		else asgn(op, ap, Wis, ui8)
		else asgn(op, ap, fortbonus, si16)
		else asgn(op, ap, refbonus, si16)
		else asgn(op, ap, willbonus, si16)
		else asgnls(op, ap, Description)
		else asgnls(op, ap, FirstName)
		else asgnls(op, ap, LastName)
		else asgnrr(op, ap, Conversation)
		else asgnrr(op, ap, ScriptAttacked)
		else asgnrr(op, ap, ScriptDamaged)
		else asgnrr(op, ap, ScriptDeath)
		else asgnrr(op, ap, ScriptDialogue)
		else asgnrr(op, ap, ScriptDisturbed)
		else asgnrr(op, ap, ScriptEndRound)
		else asgnrr(op, ap, ScriptHeartbeat)
		else asgnrr(op, ap, ScriptOnBlocked)
		else asgnrr(op, ap, ScriptOnNotice)
		else asgnrr(op, ap, ScriptRested)
		else asgnrr(op, ap, ScriptSpawn)
		else asgnrr(op, ap, ScriptSpellAt)
		else asgnrr(op, ap, ScriptUserDefine)
		else asgnrr(op, ap, TemplateResRef)
		else asgns(op, ap, Comment)
		else asgns(op, ap, Deity)
		else asgns(op, ap, Subrace)
		else asgns(op, ap, Tag)
		else if (strcmp(op->name, "SkillList") == 0)
			ap->SkillList = copy_SkillList(op);
		else if (strcmp(op->name, "FeatList") == 0)
			ap->FeatList = copy_FeatList(op);
		else if (strcmp(op->name, "SpecAbilityList") == 0)
			ap->SpecAbilityList = copy_SpecAbilityList(op);
		else if (strcmp(op->name, "ClassList") == 0)
			ap->ClassList = copy_ClassList(op);
		else if (strcmp(op->name, "Equip_ItemList") == 0)
			ap->Equip_ItemList = copy_Equip_ItemList(op);
		else if (strcmp(op->name, "ItemList") == 0)
			ap->ItemList = copy_ItemList(op);
		else if (strcmp(op->name, "TemplateList") == 0)
			ap->TemplateList = copy_TemplateList(op);
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in UTC resource!\n", MyName, op->name);
			return 0;
		}
	}
	return ap;
}
