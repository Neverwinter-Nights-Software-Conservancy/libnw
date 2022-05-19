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
#include	"str.h"

char* substr(const char* s, int b, int n)
{
	char* r = malloc(n + 1);

	if (!r)
	{
		fprintf(stderr, "%s: substr(): Can't allocate %d for substr!\n",
			MyName, n + 1);
		return r;
	}
	if (n)
		memcpy(r, &s[b], n);
	r[n] = '\0';
	return r;
}

struct v* str2arr(const char* str, int len)
{
	struct v* r = 0;
	int i;
	int lines = 0;
	int b;
	int e;
	int ctr = 0;

	/* count up newlines */
	for (i = 0; i < len; ++i)
	{
		if (str[i] == '\n')
			++lines;
	}

	/* last line have one? */
	if (str[i - 1] != '\n')
		++lines;

	/* ok, we know how many lines */
	r = vnew(lines);

	/* now extract 'em */
	for (i = 0, b = 0, e = 0; i < len; ++i, ++e)
	{
		if (str[i] == '\n')
		{
			char* line;

			/* EOL */
			if (str[i - 1] == '\r')
				--e;
			/* allocate room for the copy */
			line = substr(str, b, e - b);
			if (!line)
			{
				fprintf(stderr, "%s: str2arr(): Can't allocate %d for line!\n",
					MyName, (e - b) + 1);
				//FIXME: return 0, but free r
				return r;
			}
			vapp(r, line);
			/* adjust counters */
			b = i + 1;
			e = i;
			++ctr;
		}
	}

	/* did we get the last line? */
	if (b < len)
	{
		char* line = substr(str, b, len - b);

		if (!line)
		{
			fprintf(stderr, "%s: str2arr(): Can't allocate %d for line!\n",
				MyName, (len - b) + 1);
			//FIXME: return 0, but free r
			return r;
		}
		vapp(r, line);
	}
	return r;
}
