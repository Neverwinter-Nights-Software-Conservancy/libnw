#include	<stdio.h>

/**
 * returns a FILE* to an open file whose name is relname, relative to
 * nw_inp_dir, with mode mode, and, if *absname is non-0, stores the full
 * pathname in *absname.  On any failure, returns 0.
 */
extern FILE* nwnfopen(char* relname, char* mode, char** absname);
