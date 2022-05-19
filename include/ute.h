#include	"v.h"
#include	"object.h"

#define	UTE_SIGNATURE	"UTE "
#define	UTE_VERSION		"V3.2"

struct nwn_ute_creaturelist
{
	int Code;
	char ResRef[16];
	float CR;
	long Appearance;
	unsigned char SingleSpawn;
};

struct nwn_ute
{
	char TemplateResRef[16];
	char OnEntered[16];
	char OnExit[16];
	char OnExhausted[16];
	char OnHeartbeat[16];
	char OnUserDefined[16];
	struct nwn_object_locstr LocalizedName;
	struct v* CreatureList;	//struct nwn_ute_creaturelist*
	char* Tag;
	char* Comment;
	long Difficulty;
	long DifficultyIndex;
	unsigned long Faction;
	long MaxCreatures;
	long RecCreatures;
	long Respawns;
	long SpawnOption;
	long ResetTime;
	unsigned char Active;
	unsigned char PlayerOnly;
	unsigned char Reset;
	unsigned char PaletteID;
};

extern struct nwn_ute* plist2ute(struct v* pp);
