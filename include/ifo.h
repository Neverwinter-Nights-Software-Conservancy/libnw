#include	"v.h"
#include	"object.h"

#define	IFO_SIGNATURE	"IFO "
#define	IFO_VERSION		"V3.2"

struct nwn_ifo_eventqueue_eventdata_stack
{
	int Code;
	long BasePointer;
	long StackPointer;
	long TotalSize;
	struct v* Stack;	//struct nwn_object
};

struct nwn_ifo_eventqueue_eventdata
{
	int contCode;
	long CodeSize;
	struct { int len; char* data; } Code;
	long InstructionPtr;
	long SecondaryPtr;
	char* Name;
	long StackSize;
	struct nwn_ifo_eventqueue_eventdata_stack Stack;
};

struct nwn_ifo_eventqueue
{
	int Code;
	unsigned long Day;
	unsigned long Time;
	unsigned long ObjectId;
	unsigned long CallerId;
	unsigned long EventId;
	struct nwn_ifo_eventqueue_eventdata EventData;
};

struct nwn_ifo_vartable
{
	int Code;
	char* Name;
	struct nwn_object* tv;	//type & value
};

struct nwn_ifo_modid
{
	int len;
	char* data;
};

struct nwn_ifo_area
{
	int Code;
	char Area_Name[16];
	unsigned long ObjectId;
};

struct nwn_ifo_hak
{
	int Code;
	char* Mod_Hak;
};

struct nwn_ifo
{
	struct nwn_ifo_modid Mod_ID;
	char* Mod_MinGameVer;
	long Mod_Creator_ID;
	unsigned long Mod_Version;
	unsigned short Expansion_Pack;
	struct nwn_object_locstr Mod_Name;
	char* Mod_Tag;
	char* Mod_Hak;
	struct nwn_object_locstr Mod_Description;
	unsigned char Mod_IsSaveGame;
	unsigned char Mod_IsNWMFile;
	char Mod_NWMResName[16];
	unsigned long long Mod_Effect_NxtId;
	unsigned long Mod_NextCharId0;
	unsigned long Mod_NextCharId1;
	unsigned long Mod_NextObjId0;
	unsigned long Mod_NextObjId1;
	char Mod_Entry_Area[16];
	float Mod_Entry_X;
	float Mod_Entry_Y;
	float Mod_Entry_Z;
	float Mod_Entry_Dir_X;
	float Mod_Entry_Dir_Y;
	float Mod_Entry_Dir_Z;
	struct v* Mod_Expan_List;	//?
	unsigned char Mod_DawnHour;
	unsigned char Mod_DuskHour;
	unsigned char Mod_MinPerHour;
	unsigned char Mod_StartMonth;
	unsigned char Mod_StartDay;
	unsigned char Mod_StartHour;
	unsigned long Mod_StartYear;
	unsigned long Mod_Transition;
	unsigned short Mod_StartMinute;
	unsigned short Mod_StartSecond;
	unsigned short Mod_StartMiliSec;
	unsigned char Mod_XPScale;
	struct v* Creature_List;	//?
	char Mod_OnHeartbeat[16];
	char Mod_OnModLoad[16];
	char Mod_OnModStart[16];
	char Mod_OnClientEntr[16];
	char Mod_OnClientLeav[16];
	char Mod_OnActvtItem[16];
	char Mod_OnAcquirItem[16];
	char Mod_OnUsrDefined[16];
	char Mod_OnUnAqreItem[16];
	char Mod_OnPlrDeath[16];
	char Mod_OnPlrDying[16];
	char Mod_OnPlrLvlUp[16];
	char Mod_OnSpawnBtnDn[16];
	char Mod_OnPlrRest[16];
	char Mod_StartMovie[16];
	char Mod_OnCutsnAbort[16];
	struct v* Mod_CutSceneList;	//?
	struct v* Mod_GVar_List;	//?
	struct v* Mod_Area_list;	//struct nwn_ifo_area*
	struct v* Mod_HakList;	//struct nwn_ifo_hak*
	struct v* Mod_Tokens;	//?
	struct v* VarTable;	//struct nwn_ifo_vartable
	struct v* EventQueue;	//?
	struct v* Mod_PlayerList;	//?
	struct v* Mod_TURDList;	//?
};

// convert a plist to a struct nwn_ifo
extern struct nwn_ifo* plist2ifo(struct v* pp);
