#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)
struct nwn_tlk_head
{
	char signature[4];
	char version[4];
	unsigned long unk00;
	unsigned long c_strs;	/* count */
	unsigned long o_strs;	/* offset */
};
#pragma pack()

#define	TLK_SIGNATURE	"TLK "
#define	TLK_VERSION		"V3.0"

#pragma pack(1)
struct nwn_tlk_ent
{
	unsigned long flags;
	char wavref[16];
	unsigned long unk0;	/* unused */
	unsigned long unk1;	/* unused */
	unsigned long offset;	/* actual offset is head.o_strs + ent.offset */
	unsigned long length;
	float wavdur;
};
#pragma pack()

/* the only flag that seems to matter */
#define	TLK_FLAG_PRESENT	0x01

/**
 * using get_strref_ent(), returns the string denoted by strref \a i.
 * On any error, returns 0.
 */
extern char* get_strref_str(int i);

/**
 * using nwnfopen() to read "dialog.tlk", fetches the \a ith nwn_tlk_ent
 * structure and returns it.  On any error, returns 0.
 */
extern struct nwn_tlk_ent* get_strref_ent(int i);

/**
 * returns the number of strref entries in "dialog.tlk".
 */
extern int get_n_strrefs(void);

#ifdef __cplusplus
}
#endif
