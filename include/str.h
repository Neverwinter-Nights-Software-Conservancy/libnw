#include	"v.h"

/**
 * given a binary resource image \a resc which is ascii text (i.e., 2DA,
 * INI, TXT, etc.), and whose size is \a size, return a vector whose elements
 * are char* containing each line without its line delimiter(s).  On any
 * failure, returns 0.
 */
extern struct v* str2arr(const char*, int);
