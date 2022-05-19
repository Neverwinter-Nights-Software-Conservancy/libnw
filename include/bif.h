#pragma pack(1)
struct nw_bif_head
{
	char			signature[4];
	char			version[4];
	unsigned long	varcnt;
	unsigned long	fixcnt;
	unsigned long	varoff;
};
#pragma pack()

#define	NW_BIF_SIGNATURE	"BIFF"
#define	NW_BIF_VERSION		"V1  "

#pragma pack(1)
struct nw_bif_ent
{
	unsigned long	resid;
	unsigned long	off;
	unsigned long	len;
	unsigned long	restyp;
};
#pragma pack()

/**
 * Uses nwnfopen() to read file \a relpath, extracts the table of contents,
 * and returns a pointer to it, setting \a *nents to the number of entries
 * found.  On failure, 0 is returned, and \a *nents is set to 0.
 */
extern struct nw_bif_ent* bif_toc_load(char* relpath, unsigned long* nents);
