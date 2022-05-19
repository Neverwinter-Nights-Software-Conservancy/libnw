#include	"v.h"

#pragma pack(1)
struct nw_key
{
	char			signature[4];
	char			version[4];
	unsigned long	nfnam;		// BifCount
	unsigned long	nrsc;		// KeyCount
	unsigned long	offfnam;	// OffsetToFileTable
	unsigned long	offrsc;		// OffsetToKeyTable
	unsigned long	unkn01;		// BuildYear
	unsigned long	unkn02;		// BuildDay
	unsigned char	reserved[32];
};
#pragma pack()

#define	KEY_SIGNATURE	"KEY "
#define	KEY_VERSION		"V1  "

#pragma pack(1)
struct nw_key_fnam
{
	unsigned long	FileSize;
	unsigned long	FilenameOffset;
	unsigned short	FilenameSize;
	unsigned short	Drives;
};
#pragma pack()

#pragma pack(1)
struct nw_key_rsc
{
	char			name[16];
	unsigned short	type;
	unsigned long	resid;
};
#pragma pack()

/* these are maintained by libnw; touch at your peril */
extern struct v* nw_key_rsc_v;
extern struct v* nw_key_rsc_fnames_v;

/**
 * reads the tables of contents from files chitin.key and patch.key, merging
 * them appropriately.  Returns 0 on any failure.
 *
 * FIXME: does not (yet) read the override directory.
 */
extern int read_key(char* dirname);

/**
 * prints (on stdout) the contents of nw_key_rsc_v (the table of contents
 * extracted from files chitin.key and patch.key).  Useless unless read_key()
 * has successfully loaded the TOCs from these files.
 */
extern void print_key_rscs(void);

/* comparison functions for vsort() */

/**
 * compares nw_key_rsc entries by name, suitable for use by qsort(), vsort(),
 * bsearch(), and vbsearch().
 */
extern int cmp_key_rsc_name(const void* a, const void* b);

/**
 * compares nw_key_rsc entries by BIF file order, suitable for use by qsort(),
 * vsort(), bsearch(), and vbsearch().
 */
extern int cmp_key_rsc_bif(const void* a, const void* b);
