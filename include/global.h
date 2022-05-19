/**
 * used by all internal libnw routines when printing error messages; this
 * should be set in main() to argv[0] as the 1st executable statement by
 * any libnw client applications.
 */
extern char* MyName;

/** deprecated
 * do not use.
 */
extern char* nw_inp_out;

/**
 * used by nwnfopen() as the root directory of the game.  This should be
 * set by calling get_gamedir(), and optionally when parsing options (for
 * consistency, use "-g") using getopt().
 */
extern char* nw_inp_dir;

/**
 * used by some routines to blather as they perform their function.  This
 * should be set when parsing options (for consistency, use "-v") using
 * getopt().
 */
extern int vflag;
