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
#include	"nwnfopen.h"

FILE* nwnfopen(char* relname, char* mode, char** absname)
{
	char* labsname;
	FILE* fp;

	labsname = malloc(1 + strlen(nw_inp_dir) + 1 + strlen(relname));
	if (!labsname)
	{
		fprintf(stderr, "%s: nwnfopen(): can't allocate mem for filename!\n",
			MyName);
		return 0;
	}

	sprintf(labsname, "%s/%s", nw_inp_dir, relname);
	if (absname)
		*absname = labsname;
	fp = fopen(labsname, mode);
	return fp;
}
