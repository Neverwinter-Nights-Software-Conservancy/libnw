#define	GIC_SIGNATURE	"GIC "
#define	GIC_VERSION		"V3.2"

struct nwn_gic_placeable
{
	int Code;
	char* Comment;
};

struct nwn_gic_waypoint
{
	int Code;
	char* Comment;
};

struct nwn_gic_trigger
{
	int Code;
	char* Comment;
};

struct nwn_gic_store
{
	int Code;
	char* Comment;
};

struct nwn_gic_sound
{
	int Code;
	unsigned char PlayInToolset;
	char* Comment;
};

struct nwn_gic_list
{
	int Code;
	char* Comment;
};

struct nwn_gic_encounter
{
	int Code;
};

struct nwn_gic_door
{
	int Code;
	char* Comment;
};

struct nwn_gic_creature
{
	int Code;
	char* Comment;
};

struct nwn_gic
{
	struct v* Creature_List;	//?
	struct v* Door_List;	//?
	struct v* Encounter_List;	//?
	struct v* List;	//?
	struct v* SoundList;	//?
	struct v* StoreList;	//?
	struct v* TriggerList;	//?
	struct v* WaypointList;	//?
	struct v* Placeable_List;	//?
};

extern struct nwn_gic* plist2gic(struct v* pp);
