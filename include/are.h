#ifndef __LIBNW_ARE_H__
#define __LIBNW_ARE_H__

#include	"v.h"
#include	"object.h"

#define	ARE_SIGNATURE	"ARE "
#define	ARE_VERSION		"V3.2"

/* interesting things stored in an ARE resource */
struct nwn_are
{
	int ID;
	int Creator_ID;
	unsigned Version;
	char* Tag;
	struct nwn_object_locstr Name;
	char ResRef[16];
	char* Comments;
	struct v* Expansion_List;
	unsigned Flags;

	int ModSpotCheck;
	int ModListenCheck;

	unsigned MoonAmbientColor;
	unsigned MoonDiffuseColor;
	unsigned char MoonFogAmount;
	unsigned MoonFogColor;
	unsigned char MoonShadows;

	unsigned SunAmbientColor;
	unsigned SunDiffuseColor;
	unsigned char SunFogAmount;
	unsigned SunFogColor;
	unsigned char SunShadows;

	unsigned char IsNight;
	unsigned char LightingScheme;
	unsigned char ShadowOpacity;
	unsigned char DayNightCycle;

	int ChanceRain;
	int ChanceSnow;
	int ChanceLightning;
	int WindPower;

	unsigned short LoadScreenID;
	unsigned char PlayerVsPlayer;
	unsigned char NoRest;

	int Width;
	int Height;

	char OnEnter[16];
	char OnExit[16];
	char OnHeartbeat[16];
	char OnUserDefined[16];

	char Tileset[16];
	struct v* Tile_List;	/* (struct nwn_are_tile*) */
};

struct nwn_are_tile
{
	int Code;
	
	int Tile_ID;
	int Tile_Orientation;
	int Tile_Height;

	unsigned char Tile_MainLight1;
	unsigned char Tile_MainLight2;

	unsigned char Tile_SrcLight1;
	unsigned char Tile_SrcLight2;

	unsigned char Tile_AnimLoop1;
	unsigned char Tile_AnimLoop2;
	unsigned char Tile_AnimLoop3;
};

/**
 * convert plist \a pp to an nwn_are structure and return it.  On any failure,
 * returns 0.
 */
extern struct nwn_are* plist2are(struct v* pp);

#endif
