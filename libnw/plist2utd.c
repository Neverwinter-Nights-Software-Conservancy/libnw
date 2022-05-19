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
#include	"utd.h"
#include	"object.h"

struct nwn_utd* plist2utd(struct v* pp)
{
	struct nwn_utd* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an nwn_utd!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		asgn(op, ap, AnimationState, ui8)
		else asgn(op, ap, Appearance, ui32)
		else asgn(op, ap, AutoRemoveKey, ui8)
		else asgn(op, ap, CloseLockDC, ui8)
		else asgn(op, ap, CurrentHP, si16)
		else asgn(op, ap, DisarmDC, ui8)
		else asgn(op, ap, Faction, ui32)
		else asgn(op, ap, Fort, ui8)
		else asgn(op, ap, GenericType, ui8)
		else asgn(op, ap, HP, si16)
		else asgn(op, ap, Hardness, ui8)
		else asgn(op, ap, Interruptable, ui8)
		else asgn(op, ap, KeyRequired, ui8)
		else asgn(op, ap, LinkedToFlags, ui8)
		else asgn(op, ap, LoadScreenID, ui16)
		else asgn(op, ap, Lockable, ui8)
		else asgn(op, ap, Locked, ui8)
		else asgn(op, ap, OpenLockDC, ui8)
		else asgn(op, ap, PaletteID, ui8)
		else asgn(op, ap, Plot, ui8)
		else asgn(op, ap, PortraitId, ui16)
		else asgn(op, ap, Ref, ui8)
		else asgn(op, ap, TrapDetectDC, ui8)
		else asgn(op, ap, TrapDetectable, ui8)
		else asgn(op, ap, TrapDisarmable, ui8)
		else asgn(op, ap, TrapFlag, ui8)
		else asgn(op, ap, TrapOneShot, ui8)
		else asgn(op, ap, TrapType, ui8)
		else asgn(op, ap, Will, ui8)
		else asgnls(op, ap, Description)
		else asgnls(op, ap, LocName)
		else asgnrr(op, ap, Conversation)
		else asgnrr(op, ap, OnClick)
		else asgnrr(op, ap, OnClosed)
		else asgnrr(op, ap, OnDamaged)
		else asgnrr(op, ap, OnDeath)
		else asgnrr(op, ap, OnDisarm)
		else asgnrr(op, ap, OnFailToOpen)
		else asgnrr(op, ap, OnHeartbeat)
		else asgnrr(op, ap, OnLock)
		else asgnrr(op, ap, OnMeleeAttacked)
		else asgnrr(op, ap, OnOpen)
		else asgnrr(op, ap, OnSpellCastAt)
		else asgnrr(op, ap, OnTrapTriggered)
		else asgnrr(op, ap, OnUnlock)
		else asgnrr(op, ap, OnUserDefined)
		else asgnrr(op, ap, Portrait)
		else asgnrr(op, ap, TemplateResRef)
		else asgns(op, ap, Comment)
		else asgns(op, ap, KeyName)
		else asgns(op, ap, LinkedTo)
		else asgns(op, ap, Tag)
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in UTD resource!\n", MyName, op->name);
			return 0;
		}
	}
	return ap;
}
