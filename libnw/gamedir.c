#include	<config.h>
#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#include	"gamedir.h"

char* get_game_dir(void)
{
	char* gp = getenv("NWN_GAME_DIR");

	/* is it in the environment? */
	if (!gp)
		return gp;

	/* yes, does it have a value? */
	if (!*gp)
		return 0;

	/* we got a winna! */
	return gp;
}
