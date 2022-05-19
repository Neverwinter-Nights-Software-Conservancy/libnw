#define	BIC_SIGNATURE	"BIC "
#define	BIC_VERSION		"V3.2"

struct nwn_bic_knownspell
{
	int Code;
	unsigned short Spell;
};

struct nwn_bic_memospell
{
	int Code;
	unsigned short Spell;
	unsigned char Ready;
	unsigned char SpellMetaMagic;
};

struct nwn_bic_classlist
{
	int Code;
	long Class;
	short ClassLevel;
	unsigned char School;
	struct v* KnownList0;	//struct nwn_bic_knownspell
	struct v* KnownList1;	//struct nwn_bic_knownspell
	struct v* MemorizedList0;	//struct nwn_bic_memospell
	struct v* MemorizedList1;	//struct nwn_bic_memospell
};

struct nwn_bic_lvlstatlist
{
	int Code;
	unsigned char LvlStatHitDie;
	unsigned char LvlStatClass;
	struct v* KnownList0;	//struct nwn_bic_knownspell
	struct v* KnownList1;	//struct nwn_bic_knownspell
	unsigned short SkillPoints;
	struct v* SkillList;	//struct nwn_bic_memospell
	struct v* FeatList;	//struct nwn_bic_memospell
};

struct nwn_bic_combatinfo
{
	unsigned char NumAttacks;
	char OnHandAttackMod;
	char OnHandDamageMod;
	char OffHandAttackMod;
	char OffHandDamageMod;
	unsigned char SpellResistance;
	unsigned char ArcaneSpellFail;
	unsigned char ArmorCheckPen;
	unsigned char UnarmedDamDice;
	unsigned char UnarmedDamDie;
	unsigned char OnHandCritRng;
	unsigned char OnHandCritMult;
	unsigned char OffHandWeaponEq;
	unsigned char OffHandCritRng;
	unsigned char OffHandCritMult;
	unsigned long LeftEquip;
	unsigned long RightEquip;
	char* LeftString;
	char* RightString;
	unsigned char DamageDice;
	unsigned char DamageDie;
	struct v* AttackList;	//?
	struct v* DamageList;	//?
};

struct nwn_bic_combatrounddata
{
};

//really UTI?  see member comments at end
struct nwn_bic_equipitemlist
{
	long BaseItem;
	struct v* Description;	//locstrs
	struct v* DescIdentified;	//locstrs
	struct v* LocalizedName;	//locstrs
	struct v* PropertiesList;	//struct nwn_uti_properties*
	char* Tag;
	char TemplateResRef[16];
	unsigned long Cost;
	unsigned long AddCost;
	unsigned short StackSize;
	unsigned char ArmorPart_Belt;
	unsigned char ArmorPart_LBicep;
	unsigned char ArmorPart_LFArm;
	unsigned char ArmorPart_LFoot;
	unsigned char ArmorPart_LHand;
	unsigned char ArmorPart_LShin;
	unsigned char ArmorPart_LShoul;
	unsigned char ArmorPart_LThigh;
	unsigned char ArmorPart_Neck;
	unsigned char ArmorPart_Pelvis;
	unsigned char ArmorPart_RBicep;
	unsigned char ArmorPart_RFArm;
	unsigned char ArmorPart_RFoot;
	unsigned char ArmorPart_RHand;
	unsigned char ArmorPart_RShin;
	unsigned char ArmorPart_RShoul;
	unsigned char ArmorPart_RThigh;
	unsigned char ArmorPart_Torso;
	unsigned char Charges;
	unsigned char Cloth1Color;
	unsigned char Cloth2Color;
	unsigned char Identified;
	unsigned char Leather1Color;
	unsigned char Leather2Color;
	unsigned char Metal1Color;
	unsigned char Metal2Color;
	unsigned char Plot;
	unsigned char Stolen;
	unsigned long ObjectId;	//not in UTI
	unsigned char Dropable;	//not in UTI
	unsigned char Pickpocketable;	//not in UTI
	float XPosition;	//not in UTI
	float YPosition;	//not in UTI
	float ZPosition;	//not in UTI
	float XOrientation;	//not in UTI
	float YOrientation;	//not in UTI
	float ZOrientation;	//not in UTI
	//char* Comment;	//in UTI, not here
	//unsigned char ModelPart1;	//in UTI, not here
	//unsigned char ModelPart2;	//in UTI, not here
	//unsigned char ModelPart3;	//in UTI, not here
	//unsigned char PaletteID;	//in UTI, not here
};

//really UTI?
struct nwn_bic_itemlist
{
	unsigned long ObjectID;
	long BaseItem;
	char* Tag;
	char TemplateResRef[16];
	unsigned char Identified;
	struct v* Description;
	struct v* DescIdentified;
	struct v* LocalizedName;
	unsigned short StackSize;
	unsigned char Stolen;
	unsigned char Dropable;
	unsigned char Pickpocketable;
	unsigned char ModelPart1;
	unsigned char ModelPart2;
	unsigned char ModelPart3;
	unsigned char Charges;
	unsigned long Cost;
	unsigned long AddCost;
	unsigned char Plot;
	struct v* PropertiesList;	//struct nwn_uti_properties
	float XPosition;
	float YPosition;
	float ZPosition;
	float XOrientation;
	float YOrientation;
	float ZOrientation;
	unsigned short Repos_PosX;
	unsigned short Repos_Posy;
};

struct nwn_bic
{
	char* Mod_CommntyName;
	unsigned char Mod_IsPrimaryPlr;
	unsigned long ObjectId;
	struct v* FirstName;	//locstrs
	struct v* LastName;	//locstrs
	struct v* Description;	//locstrs
	unsigned char IsPC;
	unsigned char IsDM;
	char* Tag;
	char Conversation[16];
	unsigned char Interruptable;
	long Age;
	unsigned char Gender;
	unsigned char Race;
	char* Subrace;
	unsigned char StartingPackage;
	char* Diety;
	unsigned char MClassLevUpIn;
	short willbonus;
	short fortbonus;
	short refbonus;
	unsigned long Gold;
	char RefSaveThrow;
	char WillSaveThrow;
	char FortSaveThrow;
	short ArmorClass;
	unsigned char Str;
	unsigned char Dex;
	unsigned char Int;
	unsigned char Wis;
	unsigned char Con;
	unsigned char Cha;
	unsigned char NaturalAC;
	unsigned short SoundSetFile;
	unsigned char Plot;
	unsigned char Disarmable;
	unsigned char BodyBag;
	short HitPoints;
	short CurrentHitPoints;
	short MaxHitPoints;
	short PregameCurrent;
	unsigned long Experience;
	unsigned char MovementRate;
	char Portrait[16];
	unsigned char GoodEvil;
	unsigned char LawfulChaotic;
	unsigned char Color_Skin;
	unsigned char Color_Hair;
	unsigned char Color_Tattoo1;
	unsigned char Color_Tattoo2;
	long Phenotype;
	unsigned short Appearance_Type;
	unsigned char Appearance_Head;
	unsigned char Tail;
	unsigned char Wings;
	unsigned short FactionID;
	float ChallengeRating;
	unsigned char BodyPart_Neck;
	unsigned char BodyPart_Torso;
	unsigned char BodyPart_Belt;
	unsigned char BodyPart_Pelvis;
	unsigned char BodyPart_LShoul;
	unsigned char BodyPart_LBicep;
	unsigned char BodyPart_LFArm;
	unsigned char BodyPart_LHand;
	unsigned char BodyPart_LThigh;
	unsigned char BodyPart_LShin;
	unsigned char BodyPart_LFoot;
	unsigned char BodyPart_RShoul;
	unsigned char BodyPart_RBicep;
	unsigned char BodyPart_RFArm;
	unsigned char BodyPart_RHand;
	unsigned char BodyPart_RThigh;
	unsigned char BodyPart_RShin;
	unsigned char ArmorPart_RFoot;	//<giggle>
	struct v* ClassList;	//struct nwn_bic_classlist
	struct v* LvlStatList;	//struct nwn_bic_lvlstatlist
	long FamiliarType;
	char* FamiliarName;
	unsigned short SkillPoints;
	struct v* SkillList;	//?
	struct v* FeatList;	//?
	struct nwn_bic_combatinfo CombatInfo;
	unsigned char DetectMode;
	unsigned char StealthMode;
	unsigned long MasterID;
	long CreatureSize;
	unsigned char IsDestroyable;
	unsigned char IsRaiseable;
	unsigned char DearSelectable;
	char TemplateResRef[16];
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
	struct v* Equip_ItemList;	//struct nwn_bic_equipitemlist
	struct v* ItemList;	//struct nwn_bic_itemlist
	struct v* PerceptionList;	//?
	struct nwn_bic_combatrounddata CombatRoundData;
	unsigned long AreaId;
	unsigned long SitObject;
	unsigned char AmbientAnimState;
	unsigned char PM_IsPolymorphed;
	unsigned char Listening;
	float XPosition;
	float YPosition;
	float ZPosition;
	float XOrientation;
	float YOrientation;
	float ZOrientation;
	struct v* AssociateList;	//?
	struct v* QBList;	//?
};
