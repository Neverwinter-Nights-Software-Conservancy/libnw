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
#include	"utt.h"
#include	"object.h"

struct nwn_utt* plist2utt(struct v* pp)
{
	struct nwn_utt* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an nwn_utt!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		asgn(op, ap, AutoRemoveKey, ui8)
		else asgn(op, ap, Cursor, ui8)
		else asgn(op, ap, DisarmDC, ui8)
		else asgn(op, ap, Faction, ui32)
		else asgn(op, ap, HighlightHeight, f)
		else asgn(op, ap, LinkedToFlags, ui8)
		else asgn(op, ap, LoadScreenID, ui16)
		else asgn(op, ap, PaletteID, ui8)
		else asgn(op, ap, PortraitId, si16)
		else asgn(op, ap, TrapDetectDC, ui8)
		else asgn(op, ap, TrapDetectable, ui8)
		else asgn(op, ap, TrapDisarmable, ui8)
		else asgn(op, ap, TrapFlag, ui8)
		else asgn(op, ap, TrapOneShot, ui8)
		else asgn(op, ap, TrapType, ui8)
		else asgn(op, ap, Type, si32)
		else asgnls(op, ap, LocalizedName)
		else asgnrr(op, ap, OnClick)
		else asgnrr(op, ap, OnDisarm)
		else asgnrr(op, ap, OnTrapTriggered)
		else asgnrr(op, ap, ScriptHeartbeat)
		else asgnrr(op, ap, ScriptOnEnter)
		else asgnrr(op, ap, ScriptOnExit)
		else asgnrr(op, ap, ScriptUserDefine)
		else asgnrr(op, ap, TemplateResRef)
		else asgns(op, ap, Comment)
		else asgns(op, ap, KeyName)
		else asgns(op, ap, LinkedTo)
		else asgns(op, ap, Tag)
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in UTT resource!\n", MyName, op->name);
			return 0;
		}
	}
	return ap;
}
