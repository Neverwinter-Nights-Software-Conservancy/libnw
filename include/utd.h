#include	"v.h"
#include	"object.h"

#define	UTD_SIGNATURE	"UTD "
#define	UTD_VERSION		"V3.2"

struct nwn_utd
{
	struct nwn_object_locstr LocName;
	char* KeyName;
	char* Tag;
	char* LinkedTo;
	char* Comment;
	short HP;
	short CurrentHP;
	struct nwn_object_locstr Description;
	char Conversation[16];
	char OnClick[16];
	char OnClosed[16];
	char OnDamaged[16];
	char OnDeath[16];
	char OnDisarm[16];
	char OnFailToOpen[16];
	char OnHeartbeat[16];
	char OnLock[16];
	char OnMeleeAttacked[16];
	char OnOpen[16];
	char OnSpellCastAt[16];
	char OnTrapTriggered[16];
	char OnUnlock[16];
	char OnUserDefined[16];
	char Portrait[16];
	char TemplateResRef[16];
	unsigned long Faction;
	unsigned long Appearance;
	unsigned short PortraitId;
	unsigned short LoadScreenID;
	unsigned char Hardness;
	unsigned char Fort;
	unsigned char Ref;
	unsigned char Will;
	unsigned char GenericType;
	unsigned char Lockable;
	unsigned char Locked;
	unsigned char AnimationState;
	unsigned char CloseLockDC;
	unsigned char DisarmDC;
	unsigned char OpenLockDC;
	unsigned char TrapDetectDC;
	unsigned char PaletteID;
	unsigned char LinkedToFlags;
	unsigned char KeyRequired;
	unsigned char Interruptable;
	unsigned char TrapDetectable;
	unsigned char TrapOneShot;
	unsigned char TrapType;
	unsigned char TrapDisarmable;
	unsigned char TrapFlag;
	unsigned char AutoRemoveKey;
	unsigned char Plot;
};

extern struct nwn_utd* plist2utd(struct v* pp);
