#include	"v.h"
#include	"object.h"

#define	UTP_SIGNATURE	"UTP "
#define	UTP_VERSION		"V3.2"

struct nwn_utp_itemlist
{
	int Code;
	char InventoryRes[16];
	unsigned short Repos_PosX;
	unsigned short Repos_Posy;
};

struct nwn_utp
{
	char* Tag;
	struct nwn_object_locstr LocName;
	struct nwn_object_locstr Description;
	char TemplateResRef[16];
	unsigned char AutoRemoveKey;
	unsigned char CloseLockDC;
	char Conversation[16];
	unsigned char Interruptable;
	unsigned long Faction;
	unsigned char Plot;
	unsigned char KeyRequired;
	unsigned char Lockable;
	unsigned char Locked;
	unsigned char OpenLockDC;
	unsigned short PortraitId;
	unsigned char TrapDetectable;
	unsigned char TrapDetectDC;
	unsigned char TrapDisarmable;
	unsigned char DisarmDC;
	unsigned char TrapFlag;
	unsigned char TrapOneShot;
	unsigned char TrapType;
	char* KeyName;
	unsigned char AnimationState;
	unsigned long Appearance;
	short HP;
	short CurrentHP;
	unsigned char Hardness;
	unsigned char Fort;
	unsigned char Ref;
	unsigned char Will;
	char OnClosed[16];
	char OnDamaged[16];
	char OnDeath[16];
	char OnDisarm[16];
	char OnHeartbeat[16];
	char OnLock[16];
	char OnMeleeAttacked[16];
	char OnOpen[16];
	char OnSpellCastAt[16];
	char OnTrapTriggered[16];
	char OnUnlock[16];
	char OnUserDefined[16];
	unsigned char HasInventory;
	unsigned char BodyBag;
	unsigned char Static;
	unsigned char Type;
	unsigned char Useable;
	char OnInvDisturbed[16];
	char OnUsed[16];
	unsigned char PaletteID;
	char* Comment;
	struct v* ItemList;	//struct nwn_utp_itemlist*
	char Portrait[16];
};

extern struct nwn_utp* plist2utp(struct v* pp);
