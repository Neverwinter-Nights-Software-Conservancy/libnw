#include	<config.h>
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include	<memory.h>
# endif
# include	<string.h>
#endif
#include	"restyp.h"

struct restyp2ext
{
	unsigned short typ;
	char* ext;
};

static const struct restyp2ext r2e[] =
{
	{ RR_1DA, "1da" },	// not in doc
	{ RR_2DA, "2da" },
	{ RR_4PC, "4pc" },	// not in doc
	{ RR_ARE, "are" },	/* area */
	{ RR_BIC, "bic" },	/* (player) character */
	{ RR_BMP, "bmp" },	/* windows BMP pixmap */
	{ RR_BTD, "btd" },	// not in doc
	{ RR_BTE, "bte" },	// not in doc
	{ RR_BTG, "btg" },	// not in doc
	{ RR_BTI, "bti" },	// not in doc
	{ RR_BTM, "btm" },	// not in doc
	{ RR_BTP, "btp" },	// not in doc
	{ RR_CCS, "ccs" },	// not in doc
	{ RR_CSS, "css" },	// not in doc
	{ RR_DDS, "dds" },	/* compressed texture data */
	{ RR_DFT, "dft" },
	{ RR_DLG, "dlg" },	/* dialog tree */
	{ RR_DWK, "dwk" },	/* door walk mesh */
	{ RR_FAC, "fac" },	/* faction data */
	{ RR_GFF, "gff" },	/* generic file format */
	{ RR_GIC, "gic" },
	{ RR_GIT, "git" },
	{ RR_GUI, "gui" },	/* graphical user interface */
	{ RR_IFO, "ifo" },	/* module info */
	{ RR_INI, "ini" },	/* generic initialization text */
	{ RR_ITP, "itp" },	/* template palette */
	{ RR_JRL, "jrl" },	/* journal data ? */
	{ RR_LTR, "ltr" },
	{ RR_MDL, "mdl" },	/* model data */
	{ RR_MOD, "mod" },	/* module */
	{ RR_MP3, "mp3" },	/* MP3-format audio */
	{ RR_MVE, "mve" },	// not in doc
	{ RR_NCS, "ncs" },	/* nwscript compiled */
	{ RR_NDB, "ndb" },	/* nwscript debugging */
	{ RR_NSS, "nss" },	/* nwscript source */
	{ RR_PLT, "plt" },
	{ RR_PTM, "ptm" },	/* plot manager / plot instance */
	{ RR_PTT, "ptt" },	/* plot template */
	{ RR_PWK, "pwk" },	/* placeable walkmesh */
	{ RR_RES, "res" },	// not in doc
	{ RR_SAV, "sav" },	/* save file */
	{ RR_SET, "set" },	/* tile set */
	{ RR_SSF, "ssf" },	/* sound set */
	{ RR_TGA, "tga" },	/* targa pixmap */
	{ RR_TLK, "tlk" },	/* generic string vector */
	{ RR_TXI, "txi" },
	{ RR_TXT, "txt" },	/* generic text */
	{ RR_UTC, "utc" },	/* creature */
	{ RR_UTD, "utd" },	/* door */
	{ RR_UTE, "ute" },	/* encounter */
	{ RR_UTG, "utg" },	// not in doc
	{ RR_UTI, "uti" },	/* item */
	{ RR_UTM, "utm" },	/* merchant */
	{ RR_UTP, "utp" },	/* placeable */
	{ RR_UTS, "uts" },	/* sounds */
	{ RR_UTT, "utt" },	/* trap */
	{ RR_UTW, "utw" },	/* waypoint */
	{ RR_WAV, "wav" },	/* audio (WAV) */
	{ RR_WOK, "wok" },	/* walkmesh */
};
static const int nr2e = sizeof r2e / sizeof r2e[0];

const char* typ2ext(unsigned short typ)
{
	int i;

	for (i = 0; i < nr2e; ++i)
	{
		if (typ == r2e[i].typ)
			return r2e[i].ext;
	}
	return "???";
}

unsigned short ext2typ(const char* ext)
{
	int i;

	for (i = 0; i < nr2e; ++i)
	{
		if (strcmp(ext, r2e[i].ext) == 0)
			return r2e[i].typ;
	}
	return -1;
}
