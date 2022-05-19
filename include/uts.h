#include	"v.h"

#define	UTS_SIGNATURE	"UTS "
#define	UTS_VERSION		"V3.2"

struct nwn_uts_sound
{
	int Code;
	char Sound[16];
};

struct nwn_uts
{
	float Elevation;
	float MaxDistance;
	float MinDistance;
	float RandomRangeX;
	float RandomRangeY;
	float PitchVariation;
	unsigned long Interval;
	unsigned long IntervalVrtn;
	unsigned long Hours;
	unsigned char Active;
	unsigned char Continuous;
	unsigned char Looping;
	unsigned char Positional;
	unsigned char RandomPosition;
	unsigned char Random;
	unsigned char Priority;
	unsigned char Times;
	unsigned char Volume;
	unsigned char VolumeVrtn;
	unsigned char PaletteID;
	char TemplateResRef[16];
	char* Tag;
	char* Comment;
	struct v* LocName;	//locstrs
	struct v* Sounds;	//struct nwn_uts_sound
};
