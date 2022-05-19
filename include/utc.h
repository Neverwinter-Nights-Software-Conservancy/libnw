#include	"v.h"
#include	"object.h"

#define	UTC_SIGNATURE	"UTC "
#define	UTC_VERSION		"V3.2"

struct nwn_utc_template
{
	int Code;
	unsigned short TemplateID;
};

struct nwn_utc_skill
{
	int Code;
	unsigned char Rank;
};

struct nwn_utc_feat
{
	int Code;
	unsigned short Feat;
};

struct nwn_utc_specability
{
	int Code;
	unsigned short Spell;
	unsigned char SpellFlags;
	unsigned char SpellCasterLevel;
};

struct nwn_utc_class_memo
{
	int Code;
	unsigned short Spell;
	unsigned char SpellMetaMagic;
	unsigned char SpellFlags;
};

struct nwn_utc_class_known
{
	int Code;
	unsigned short Spell;
	unsigned char SpellMetaMagic;
	unsigned char SpellFlags;
};

struct nwn_utc_class
{
	int Code;
	int Class;
	short ClassLevel;
	struct v* MemorizedList0;	//struct nwn_utc_class_memo
	struct v* MemorizedList1;	//struct nwn_utc_class_memo
	struct v* MemorizedList2;	//struct nwn_utc_class_memo
	struct v* MemorizedList3;	//struct nwn_utc_class_memo
	struct v* MemorizedList4;	//struct nwn_utc_class_memo
	struct v* MemorizedList5;	//struct nwn_utc_class_memo
	struct v* MemorizedList6;	//struct nwn_utc_class_memo
	struct v* MemorizedList7;	//struct nwn_utc_class_memo
	struct v* MemorizedList8;	//struct nwn_utc_class_memo
	struct v* MemorizedList9;	//struct nwn_utc_class_memo
	struct v* KnownList0;	//struct nwn_utc_class_known
	struct v* KnownList1;	//struct nwn_utc_class_known
	struct v* KnownList2;	//struct nwn_utc_class_known
	struct v* KnownList3;	//struct nwn_utc_class_known
	struct v* KnownList4;	//struct nwn_utc_class_known
	struct v* KnownList5;	//struct nwn_utc_class_known
	struct v* KnownList6;	//struct nwn_utc_class_known
	struct v* KnownList7;	//struct nwn_utc_class_known
	struct v* KnownList8;	//struct nwn_utc_class_known
	struct v* KnownList9;	//struct nwn_utc_class_known
};

struct nwn_utc_eqitem
{
	int Code;
	char EquippedRes[16];
	unsigned char Dropable;
	unsigned char Pickpocketable;
};

struct nwn_utc_item
{
	int Code;
	char InventoryRes[16];
	unsigned short Repos_PosX;
	unsigned short Repos_Posy;
	unsigned char Dropable;
	unsigned char Pickpocketable;
};

struct nwn_utc
{
	char TemplateResRef[16];
	char Conversation[16];
	char ScriptHeartbeat[16];
	char ScriptOnNotice[16];
	char ScriptSpellAt[16];
	char ScriptAttacked[16];
	char ScriptDamaged[16];
	char ScriptDisturbed[16];
	char ScriptEndRound[16];
	char ScriptDialogue[16];
	char ScriptSpawn[16];
	char ScriptRested[16];
	char ScriptDeath[16];
	char ScriptUserDefine[16];
	char ScriptOnBlocked[16];
	struct v* SkillList;	//struct nwn_utc_skill
	struct v* FeatList;	//struct nwn_utc_feat
	struct v* TemplateList;	//?
	struct v* SpecAbilityList;	//struct nwn_utc_specability
	struct v* ClassList;	//struct nwn_utc_class
	struct v* Equip_ItemList;	//struct nwn_utc_eqitem
	struct v* ItemList;	//struct nwn_utc_item
	struct nwn_object_locstr FirstName;
	struct nwn_object_locstr LastName;
	struct nwn_object_locstr Description;
	char* Tag;
	char* Subrace;
	char* Deity;
	char* Comment;
	float ChallengeRating;
	long CRAdjust;
	long Phenotype;
	long WalkRate;
	unsigned short PortraitId;
	unsigned short FactionID;
	unsigned short Appearance_Type;
	unsigned short SoundSetFile;
	short HitPoints;
	short CurrentHitPoints;
	short MaxHitPoints;
	short refbonus;
	short willbonus;
	short fortbonus;
	unsigned char IsPC;
	unsigned char IsImmortal;
	unsigned char Disarmable;
	unsigned char Race;
	unsigned char Gender;
	unsigned char Wings;
	unsigned char Tail;
	unsigned char Plot;
	unsigned char Interruptable;
	unsigned char NoPermDeath;
	unsigned char BodyBag;
	unsigned char Str;
	unsigned char Dex;
	unsigned char Con;
	unsigned char Int;
	unsigned char Wis;
	unsigned char Cha;
	unsigned char NaturalAC;
	unsigned char LawfulChaotic;
	unsigned char GoodEvil;
	unsigned char PerceptionRange;
	unsigned char PaletteID;
	unsigned char Appearance_Head;
	unsigned char ArmorPart_RFoot;	//should be BodyPart_RFoot!
	unsigned char BodyPart_Belt;
	unsigned char BodyPart_LBicep;
	unsigned char BodyPart_LFArm;
	unsigned char BodyPart_LFoot;
	unsigned char BodyPart_LHand;
	unsigned char BodyPart_LShin;
	unsigned char BodyPart_LShoul;
	unsigned char BodyPart_LThigh;
	unsigned char BodyPart_Neck;
	unsigned char BodyPart_Pelvis;
	unsigned char BodyPart_RBicep;
	unsigned char BodyPart_RFArm;
	unsigned char BodyPart_RHand;
	unsigned char BodyPart_RShin;
	unsigned char BodyPart_RShoul;
	unsigned char BodyPart_RThigh;
	unsigned char BodyPart_Torso;
	unsigned char Color_Hair;
	unsigned char Color_Skin;
	unsigned char Color_Tattoo1;
	unsigned char Color_Tattoo2;
};

extern struct nwn_utc* plist2utc(struct v* pp);
