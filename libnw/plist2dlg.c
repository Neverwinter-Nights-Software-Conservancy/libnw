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
#include	"dlg.h"
#include	"object.h"

static struct v* copy_RepliesList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_dlg_entry_reply* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate dlg_entry!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, Index, ui32)
			else asgn(oop, tp, IsChild, ui8)
			else asgnrr(oop, tp, Active)
			else asgns(oop, tp, LinkComment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in dlg.entrylist.replieslist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_EntryList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_dlg_entry* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate dlg_entry!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, Animation, ui32)
			else asgn(oop, tp, AnimLoop, ui32)
			else asgn(oop, tp, Delay, ui32)
			else asgn(oop, tp, QuestEntry, ui32)
			else asgnls(oop, tp, Text)
			else asgnrr(oop, tp, Script)
			else asgnrr(oop, tp, Sound)
			else asgns(oop, tp, Comment)
			else asgns(oop, tp, Quest)
			else asgns(oop, tp, Speaker)
			else if (strcmp(oop->name, "RepliesList") == 0)
				tp->RepliesList = copy_RepliesList(oop);
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in dlg.entrylist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_EntriesList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_dlg_reply_entry* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate dlg_reply_entry!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, Index, ui32)
			else asgn(oop, tp, IsChild, ui8)
			else asgnrr(oop, tp, Active)
			else asgns(oop, tp, LinkComment)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in dlg.replylist.entrieslist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_ReplyList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_dlg_reply* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate dlg_entry!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, Animation, ui32)
			else asgn(oop, tp, AnimLoop, ui8)
			else asgn(oop, tp, Delay, ui32)
			else asgn(oop, tp, QuestEntry, ui32)
			else asgnls(oop, tp, Text)
			else asgnrr(oop, tp, Script)
			else asgnrr(oop, tp, Sound)
			else asgns(oop, tp, Comment)
			else asgns(oop, tp, Quest)
			else if (strcmp(oop->name, "EntriesList") == 0)
				tp->EntriesList = copy_EntriesList(oop);
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in dlg.replylist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

static struct v* copy_StartingList(struct nwn_object* op)
{
	struct v* vp = vnew(vlen(op->val.rec.v));
	int j;

	for (j = 0; j < vlen(op->val.rec.v); ++j)
	{
		struct nwn_object_record* lip = vsubig(op->val.rec.v, j);
		struct nwn_dlg_start* tp = malloc(sizeof *tp);
		int k;

		if (!tp)
		{
			fprintf(stderr, "%s: Can't allocate dlg_start!\n", MyName);
			return 0;
		}
		tp->Code = lip->code;
		for (k = 0; k < vlen(lip->v); ++k)
		{
			struct nwn_object* oop = vsubig(lip->v, k);

			asgn(oop, tp, Index, ui32)
			else asgnrr(oop, tp, Active)
			else
			{
				fprintf(stderr, "%s: Unknown Property <%s> in dlg.startinglist!\n",
					MyName, oop->name);
				return 0;
			}
		}
		vapp(vp, tp);
	}
	return vp;
}

struct nwn_dlg* plist2dlg(struct v* pp)
{
	struct nwn_dlg* ap;
	int i;

	ap = malloc(sizeof *ap);
	if (!ap)
	{
		fprintf(stderr, "%s: Can't allocate an nwn_dlg!\n", MyName);
		return ap;
	}
	for (i = 0; i < vlen(pp); ++i)
	{
		struct nwn_object* op = vsubig(pp, i);

		asgn(op, ap, DelayEntry, ui32)
		else asgn(op, ap, DelayReply, ui32)
		else asgn(op, ap, NumWords, ui32)
		else asgn(op, ap, PreventZoomIn, ui8)
		else asgnrr(op, ap, EndConverAbort)
		else asgnrr(op, ap, EndConversation)
		else if (strcmp(op->name, "EntryList") == 0)
			ap->EntryList = copy_EntryList(op);
		else if (strcmp(op->name, "ReplyList") == 0)
			ap->ReplyList = copy_ReplyList(op);
		else if (strcmp(op->name, "StartingList") == 0)
			ap->StartingList = copy_StartingList(op);
		else
		{
			fprintf(stderr, "%s: Unknown Property <%s> in DLG resource!\n",
				MyName, op->name);
			return 0;
		}
	}
	return ap;
}
