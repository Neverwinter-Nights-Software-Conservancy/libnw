#ifdef __cplusplus
extern "C" {
#endif

/*
 * Symbolic constants for each resref type
 */

#define	RR_RES	0x0000
#define	RR_BMP	0x0001
#define	RR_MVE	0x0002	// not in doc
#define	RR_TGA	0x0003
#define	RR_WAV	0x0004

#define	RR_PLT	0x0006
#define	RR_INI	0x0007
#define	RR_MP3	0x0008	// not in doc

#define	RR_TXT	0x000A

#define	RR_MDL	0x07D2

#define	RR_NSS	0x07D9
#define	RR_NCS	0x07DA
#define	RR_MOD	0x07DB
#define	RR_ARE	0x07DC
#define	RR_SET	0x07DD
#define	RR_IFO	0x07DE
#define	RR_BIC	0x07DF
#define	RR_WOK	0x07E0
#define	RR_2DA	0x07E1
#define	RR_TLK	0x07E2	// not in doc

#define	RR_TXI	0x07E6
#define	RR_GIT	0x07E7

#define	RR_UTI	0x07E9
#define	RR_BTI	0x07EA	// not in doc
#define	RR_UTC	0x07EB

#define	RR_DLG	0x07ED
#define	RR_ITP	0x07EE

#define	RR_UTT	0x07F0
#define	RR_DDS	0x07F1

#define	RR_UTS	0x07F3
#define	RR_LTR	0x07F4
#define	RR_GFF	0x07F5
#define	RR_FAC	0x07F6
#define	RR_BTE	0x07F7	// not in doc
#define	RR_UTE	0x07F8
#define	RR_BTD	0x07F9	// not in doc
#define	RR_UTD	0x07FA
#define	RR_BTP	0x07FB	// not in doc
#define	RR_UTP	0x07FC
#define	RR_DFT	0x07FD
#define	RR_GIC	0x07FE
#define	RR_GUI	0x07FF
#define	RR_CSS	0x0800	// not in doc
#define	RR_CCS	0x0801	// not in doc
#define	RR_BTM	0x0802	// not in doc
#define	RR_UTM	0x0803
#define	RR_DWK	0x0804
#define	RR_PWK	0x0805
#define	RR_BTG	0x0806	// not in doc
#define	RR_UTG	0x0807	// not in doc
#define	RR_JRL	0x0808
#define	RR_SAV	0x0809	// not in doc
#define	RR_UTW	0x080A
#define	RR_4PC	0x080B	// not in doc
#define	RR_SSF	0x080C

#define	RR_NDB	0x0810
#define	RR_PTM	0x0811
#define	RR_PTT	0x0812

#define	RR_1DA	0x270C	// not in doc

/**
 * given a resource type \a typ, returns a pointer to the 3-character
 * extension, or "???" if none appropriate.
 */
extern const char* typ2ext(unsigned short typ);

/**
 * given a 3-character extension \a ext, returns the appropriate resource
 * type, or 0 if none appropriate.
 */
extern unsigned short ext2typ(const char* ext);

#ifdef __cplusplus
}
#endif
