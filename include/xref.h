struct xref
{
	char*		name;
	struct v*	refers_to;
	struct v*	referd_by;
};
extern struct v* xrefs;

extern int find_xref(char* name);
extern int add_xref(char* name);
extern void refers_to(char* referer, char* referee);
extern void show_xref();

/* flags for each reference */
#define REQ_TGA_OR_DDS	0x01
#define	OPT_TXI			0x02
#define	REQ_ASIS		0x03

