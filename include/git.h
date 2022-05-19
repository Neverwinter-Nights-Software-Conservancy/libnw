#include	"v.h"

#define	GIT_SIGNATURE	"GIT "
#define	GIT_VERSION		"V3.2"

struct nwn_git_areaproperties
{
	int AmbientSndDay;
	int AmbientSndNight;
	int AmbientSndDayVol;
	int AmbientSndNitVol;
	int EnvAudio;
	int MusicBattle;
	int MusicDay;
	int MusicNight;
	int MusicDelay;
};

struct nwn_git
{
	struct nwn_git_areaproperties AreaProperties;
	struct v* Creature_List;	//struct nwn_utc?
	struct v* Door_List;	//struct nwn_uti?
	struct v* Encounter_List;	//?
	struct v* SoundList;	//struct nwn_uts?
	struct v* StoreList;	//?
	struct v* TriggerList;	//?
	struct v* WaypointList;	//?
	struct v* Placeable_List;	//struct nwn_utp?
	struct v* VarTable;	//?
	unsigned char CurrentWeather;
	unsigned char WeatherStarted;
	struct v* List;	//?
	struct v* AreaEffectList;	//?
};
