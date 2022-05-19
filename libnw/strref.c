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
#include	"tlk.h"
#include	"nwnfopen.h"
#if WORDS_BIGENDIAN
#include	"bendian.h"
#endif

static FILE* strfp = 0;
static struct nwn_tlk_head head;
static int head_valid = 0;
static struct nwn_tlk_ent* ents = 0;

struct nwn_tlk_ent* get_strref_ent(int i)
{
	if (!strfp)
	{
		strfp = nwnfopen("dialog.tlk", "rb", 0);
		if (!strfp)
		{
			fprintf(stderr, "%s: Can't open <dialog.tlk> for reading!\n", MyName);
			return 0;
		}
		if (!head_valid)
		{
			if (fread(&head, sizeof head, 1, strfp) != 1)
			{
				fprintf(stderr, "%s: Can't read <dialog.tlk> header!\n", MyName);
				fclose(strfp);
				strfp = 0;
				return 0;
			}
			if (strncmp(head.signature, TLK_SIGNATURE, sizeof head.signature) ||
				strncmp(head.version, TLK_VERSION, sizeof head.version))
			{
				fprintf(stderr, "%s: Signature (%-.4s) or Version (%-.4s) mismatch in <dialog.tlk>!\n",
					MyName, head.signature, head.version);
				fclose(strfp);
				strfp = 0;
				return 0;
			}
#if WORDS_BIGENDIAN
			be2leul(&head.c_strs);
			be2leul(&head.o_strs);
#endif
			head_valid = 1;
		}

		if (!ents)
		{
			ents = (struct nwn_tlk_ent*) malloc(head.c_strs * sizeof *ents);
			if (!ents)
			{
				fprintf(stderr, "%s: Can't allocate %ld STRREF entries!\n",
					MyName, head.c_strs);
				fclose(strfp);
				strfp = 0;
				return 0;
			}

			if (fread(ents, sizeof *ents, head.c_strs, strfp) != head.c_strs)
			{
				fprintf(stderr, "%s: Can't read %ld STRREF entries from <dialog.tlk>!\n",
					MyName, head.c_strs);
				free(ents);
				ents = 0;
				fclose(strfp);
				strfp = 0;
				return 0;
			}
#if WORDS_BIGENDIAN
			{
				int j;

				for (j = 0; j < head.c_strs; ++j)
				{
					be2leul(&ents[j].flags);
					be2leul(&ents[j].offset);
					be2leul(&ents[j].length);
				}
			}
#endif
		}
	}
	if (i < 0 || i >= head.c_strs)
	{
		fprintf(stderr, "%s: Invalid STRREF index (%d)!\n", MyName, i);
		return 0;
	}
	return &ents[i];
}

char* get_strref_str(int i)
{
	struct nwn_tlk_ent* tp;
	char* cp;

	tp = get_strref_ent(i);
	if (!tp)
		return 0;
	cp = malloc(1 + tp->length);
	if (!cp)
	{
		fprintf(stderr, "%s: Can't allocate %ld chars for STRREF #%d!\n",
			MyName, tp->length, i);
		return cp;
	}
	if (tp->length)
	{
		fseek(strfp, head.o_strs + tp->offset, SEEK_SET);
		if (fread(cp, tp->length, 1, strfp) != 1)
		{
			fprintf(stderr, "%s: Can't read %ld chars for STRREF #%d!\n",
				MyName, tp->length, i);
			free(cp);
			return 0;
		}
	}
	cp[tp->length] = '\0';
	return cp;
}

int get_n_strrefs(void)
{
	(void) get_strref_ent(0);	// load 'em up, if we can
	return head.c_strs;
}

void end_strref(void)
{
	if (strfp)
		fclose(strfp);
}
