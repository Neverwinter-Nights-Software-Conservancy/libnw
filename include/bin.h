/** deprecated
 * do not use.
 */
extern void dump_all(int argc, char** argv);

/**
 * extract binary resource \a name with resource type \a restyp from the
 * game-supplied files, returning it and setting \a *length to its size
 * in bytes.  On failure, return 0, and set \a *length to 0.
 */
extern void* ext_bin(char* name, unsigned long restyp, int* length);

/**
 * extract binary resource \a name (including extension) from the game-supplied
 * files, returning it, and setting \a *length to its size in bytes.
 * On failure, return 0, and set \a *length to 0.
 */
extern void* ext_file(char* name, int* length);
