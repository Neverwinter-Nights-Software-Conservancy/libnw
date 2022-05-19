#include	"v.h"
#include	"object.h"

#define	UTT_SIGNATURE	"UTT "
#define	UTT_VERSION		"V3.2"

struct nwn_utt
{
	long Type;
	char* Tag;
	char* Comment;
	struct nwn_object_locstr LocalizedName;
	char* KeyName;
	float HighlightHeight;
	unsigned long Faction;
	char* LinkedTo;
	unsigned short PortraitId;
	unsigned short LoadScreenID;
	unsigned char LinkedToFlags;
	unsigned char Cursor;
	unsigned char DisarmDC;
	unsigned char TrapDetectDC;
	unsigned char TrapOneShot;
	unsigned char TrapDetectable;
	unsigned char TrapType;
	unsigned char TrapFlag;
	unsigned char TrapDisarmable;
	unsigned char AutoRemoveKey;
	unsigned char PaletteID;
	char OnClick[16];
	char OnDisarm[16];
	char OnTrapTriggered[16];
	char ScriptHeartbeat[16];
	char ScriptOnEnter[16];
	char ScriptOnExit[16];
	char ScriptUserDefine[16];
	char TemplateResRef[16];
};

extern struct nwn_utt* plist2utt(struct v* pp);
