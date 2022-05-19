#define	UTW_SIGNATURE	"UTW "
#define	UTW_VERSION		"V3.2"

struct nwn_utw
{
	char* Comment;
	struct v* Description;	//locstrs
	char* LinkedTo;
	char TemplateResRef[16];
	struct v* LocalizedName;	//locstrs
	char* Tag;
	unsigned char HasMapNote;
	unsigned char PaletteID;
	unsigned char Appearance;
	unsigned char MapNoteEnabled;
	struct v* MapNote;	//locstrs
};
