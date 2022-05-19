/*! \file agg.h
	\brief Manipulating aggregate files (HAK, MOD, ERF).

	These are the various structures and routines for manipulating MODules,
	HAK packs, and Exported Resource Files.
*/

#ifdef __cplusplus
extern "C" {
#endif

#include	"v.h"

#pragma pack(1)
/*! \struct nwn_agg agg.h <libnw/agg.h>
	\brief basic file header for aggregate files.
*/
struct nwn_agg
{
	char			signature[4];	/**< "HAK ", "MOD ", or "ERF " */
	char			version[4];	/**< could depend on nwn_agg::signature */
	unsigned long	hasdesc;	/**< LanguageCount: # of strings in Localized Strings Table */
	unsigned long	desclen;	/**< LocalizedStringSize: size in bytes of the Localized Strings Table */
	unsigned long	rescnt;	/**< EntryCount: how many resources are present */
	unsigned long	descoff;	/**< OffsetToLocalizedString: offset of Localized String Table */
	unsigned long	tocoff;	/**< OffsetToKeyList: offset of table of contents block */
	unsigned long	locoff;	/**< OffsetToResourceList: offset of locations block */
	unsigned long	buildyear;	/**< BuildYear: offset from 1900 */
	unsigned long	buildday;	/**< BuildDay: day of year; Jan 1 -> 0 */
	unsigned long	descstrref;	/**< DescriptionStrRef: STRREF for file description */
};
#pragma pack()

#pragma pack(1)
/*! \struct nwn_agg_desc agg.h <libnw/agg.h>
	\brief localized string used for the description of an aggregate file.
*/
struct nwn_agg_desc
{
	unsigned long len;	/**< StringSize: length of description text */
	unsigned long lang;	/**< LanguageID: language code for text */
	char* desc;			/**< String: the text itself */
};
#pragma pack()

/* language IDs */
enum LanguageID
{
	English = 0,
	French = 1,
	German = 2,
	Italian = 3,
	Spanish = 4,
	Polish = 5,
	Korean = 128,
	ChineseTrad = 129,
	ChineseSimp = 130,
	Japanese = 131,
};

enum LanguageGender
{
	M_English = 0,
	F_English = 1,
	M_French = 2,
	F_French = 3,
	M_German = 4,
	F_German = 5,
	M_Italian = 6,
	F_Italian = 7,
	M_Spanish = 8,
	F_Spanish = 9,
	M_Polish = 10,
	F_Polish = 11,
	M_Korean = 256,
	F_Korean = 257,
	M_ChineseTrad = 258,
	F_ChineseTrad = 259,
	M_ChineseSimp = 260,
	F_ChineseSimp = 261,
	M_Japanese = 262,
	F_Japanese = 263,
};

#pragma pack(1)
/*! \struct nwn_agg_resc agg.h <libnw/agg.h>
	\brief table of contents entry for an aggregate file.
*/
struct nwn_agg_resc
{
	char name[16];			/**< ResRef: the name of this resource */
	unsigned long index;	/**< ResID: index into nwn_agg_toc::szofs */
	unsigned short type;	/**< ResType: the resource type */
	unsigned short unused;	/**< Unused: unused */
};
#pragma pack()

#pragma pack(1)
/*! \struct nwn_agg_so agg.h <libnw/agg.h>
	\brief size and offset of a resource in an aggregate file.
*/
struct nwn_agg_so
{
	unsigned long off;	/**< OffsetToResource: absolute file offset */
	unsigned long siz;	/**< ResourceSize: length in bytes */
};
#pragma pack()

/*! \struct nwn_agg_toc agg.h <libnw/agg.h>
	\brief aggregate file table of contents.
*/
struct nwn_agg_toc
{
	struct nwn_agg* head;	/**< the intact header */
	struct v* descs;		/**< (struct nwn_agg_desc*) may be 0 or more */
	struct v* rescs;		/**< (struct nwn_agg_resc*) */
	struct v* szofs;		/**< (struct nwn_agg_so*) */
};

/** deprecated:
 * do not use.
 */
extern void agg1dump(char* fname, long off, int dump);

/**
 * load the table of contents of the aggregate in file \a fname (at offset
 * \a off) and return it.  In case of any failure, returns 0.
 */
extern struct nwn_agg_toc* agg_toc_load(const char* fname, long off);

/**
 * free all memory used by nwn_agg_toc* \a tp.
 */
extern void agg_toc_delete(struct nwn_agg_toc* tp);

/**
 * given \a argv (with the same semantics as the argv argument to main),
 * create an aggregate file (whose name is \a argv[0]) consisting of files
 * named in \a argv[1..] (\a argv is terminated by a 0).  Valid values for
 * \a type include 0: MOD; 1: HAK; 2: ERF.  On any failure, return 0.
 */
extern int agg_create(char** argv, int type);

/**
 * given an aggregate file named \a aggname, extract the resource named
 * \a resname.  The integer pointed to by \a size is set to the number of
 * bytes read.  Returns the address of the binary resource.  In case of
 * failure, 0 is returned, and \a *size is set to 0.
 */
extern void* agg_res_load(char* aggname, char* resname, int* size);

#ifdef __cplusplus
}
#endif

