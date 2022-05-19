#include	"v.h"

/**
 * creates a vector of vectors of char* from the binary 2da resource res
 * (which has size len).
 */
extern struct v* bin22da(void* res, int len);

/**
 * frees all storage allocated to r, assuming r was created by bin22da().
 */
extern void free_2da(struct v* r);
