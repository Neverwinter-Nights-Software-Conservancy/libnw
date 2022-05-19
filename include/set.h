#ifndef	__LIBNW_SET_H__
#define	__LIBNW_SET_H__

/*
** set.h: generally, the structure of a SET file as it might be manipulated
**	in memory.
*/

#include	"v.h"
#include	"rgb.h"

/* torc is short for "terrain or crosser" */
struct nwn_set_torc
{
	char* Name;	/* this appears to be case-insensitive! */
	int StrRef;
};

struct nwn_set_general
{
	char* Name;
	char* Type;
	char* Version;
	int Interior;
	int HasHeightTransition;
	char* EnvMap;	/* refers to a TGA */
	int Transition;
	int DisplayName;	/* a StrRef */
	char* UnlocalizedName;
	char* Border;
	char* Default;
	char* Floor;
};

struct nwn_set_grass
{
	int Grass;
	double Density;
	double Height;
	struct rgb Ambient;
	struct rgb Diffuse;
};

struct nwn_set_terrain
{
	char* Name;
	int StrRef;
};

struct nwn_set_crosser
{
	char* Name;
	int StrRef;
};

struct nwn_set_rule
{
	char* Placed;
	int PlacedHeight;
	char* Adjacent;
	int AdjacentHeight;
	char* Changed;
	int ChangedHeight;
};

struct nwn_set_tile_door
{
	int Type;
	double X;
	double Y;
	double Z;
	double Orientation;
};

struct nwn_set_tile_sound
{
};

struct nwn_set_tile
{
	char* Model;	/* refers to both a TGA and a WOK ? */
	char* WalkMesh;
	char* TopLeft;
	int TopLeftHeight;
	char* TopRight;
	int TopRightHeight;
	char* BottomLeft;
	int BottomLeftHeight;
	char* BottomRight;
	int BottomRightHeight;
	char* Top;
	char* Right;
	char* Bottom;
	char* Left;
	int MainLight1;
	int MainLight2;
	int SourceLight1;
	int SourceLight2;
	int AnimLoop1;
	int AnimLoop2;
	int AnimLoop3;
	struct v* Doors;	/* really struct nwn_set_tile_door */
	struct v* Sounds;	/* really struct nwn_set_tile_sound */
	char* PathNode;
	int Orientation;
	char* VisibilityNode;
	int VisibilityOrientation;
	char* DoorVisibilityNode;
	int DoorVisibilityOrientation;
	char* ImageMap2D;	/* refers to a TGA */
};

struct nwn_set_group
{
	char* Name;
	int StrRef;
	int Rows;
	int Columns;
	struct v* Tiles;	/* really struct nwn_set_tile */
};

struct nwn_set
{
	struct nwn_set_general General;
	struct nwn_set_grass Grass;
	struct v* Terrains;			/* really struct nwn_set_terrain */
	struct v* Crossers;			/* really struct nwn_set_crosser */
	struct v* PrimaryRules;		/* really struct nwn_set_rule */
	struct v* SecondaryRules;	/* really struct nwn_set_rule */
	struct v* Tiles;			/* really struct nwn_set_tile */
	struct v* Groups;			/* really struct nwn_set_group */
};

extern int nwset_debug;	/* equivalent to yydebug */

/**
 * given the binary SET resource \a res (of length \a len bytes), parses it,
 * storing the information in nwn_set* \a sp.  On failure, returns 0.
 */
extern int nw_parse_set(char* res, int len, struct nwn_set* sp);

#endif
