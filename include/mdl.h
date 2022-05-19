#include	"v.h"
#include	"rgb.h"
#include	"xyz.h"

// Warning: these are incomplete, and many of the "double"s are apparently
//	used as booleans (so they should be "char" instead).  Do not depend
//	on the order of any structure members, as they *will* change.

struct nwn_mdl_aabb
{
	double unkn[7];
};

enum nwn_mdl_node_type
{
	// these 9 are in order of population in NWN-supplied models
	dummy, trimesh, emitter, light, aabb, animmesh, danglymesh, reference, skin,
};

struct nwn_mdl_node_dummy
{
	struct xyz position;
	struct xyzw orientation;
};

struct nwn_mdl_node_trimesh
{
	struct xyz position;
	struct xyzw orientation;
	struct rgb ambient;
	struct rgb diffuse;
	struct rgb specular;
	double shininess;
	double shadow;
	double transparencyhint;
	char bitmap[16];
	struct v* verts;	//struct xyz
	struct v* tverts;	//struct xyz
	struct v* faces;	//struct v*	//int
};

struct nwn_mdl_node_emitter
{
	struct xyz position;
	struct xyzw orientation;
	double p2p;
	double p2p_sel;
	double affectedByWind;
	double m_isTinted;
	double bounce;
	double random;
	double inherit;
	double inheritvel;
	double inherit_local;
	double splat;
	double inherit_part;
	double renderorder;
	double spawntype;
	char* update;
	char* render;
	char* blend;
	char* texture;
	double xgrid;
	double ygrid;
	double loop;
	double deadspace;
	double twosidedtex;
	double blastRadius;
	double blastLength;
	struct rgb colorStart;
	struct rgb colorEnd;
	double alphaStart;
	double alphaEnd;
	double sizeStart;
	double sizeEnd;
	double sizeStart_y;
	double sizeEnd_y;
	double frameStart;
	double frameEnd;
	double birthrate;
	double lifeExp;
	double mass;
	double spread;
	double particle_rot;
	double velocity;
	double randvel;
	double fps;
	double xsize;
	double ysize;
	double bounce_co;
	double blurlength;
	double lightningDelay;
	double lightningRadius;
	double lightningScale;
	double p2p_bezier2;
	double p2p_bezier3;
	double combinetime;
	double drag;
	double grav;
	double threshold;
};

struct nwn_mdl_node_light
{
	struct xyz position;
	struct xyzw orientation;
	double ambientonly;
	double shadow;
	double isdynamic;
	double affectdynamic;
	double lightpriority;
	double fadingLight;
	double flareradius;
	double radius;
	double multiplier;
	struct rgb color;
};

struct nwn_mdl_node_aabb
{
	struct xyz position;
	struct xyzw orientation;
	struct rgb ambient;
	struct rgb diffuse;
	struct rgb specular;
	double shininess;
	double shadow;
	double transparencyhint;
	char bitmap[16];
	struct v* verts;	//struct xyz
	struct v* tverts;	//struct xyz
	struct v* faces;	//struct v*	//int
	struct v* aabb;	//struct nwn_mdl_aabb
};

struct nwn_mdl_node_animmesh
{
	struct xyz position;
	struct xyzw orientation;
	struct rgb ambient;
	struct rgb diffuse;
	struct rgb specular;
	double shininess;
	char bitmap[16];
	struct v* verts;	//struct xyz
	struct v* tverts;	//struct xyz
	struct v* faces;	//struct v*	//int
	double sampleperiod;
};

struct nwn_mdl_node_danglymesh
{
	struct xyz position;
	struct xyzw orientation;
	struct rgb ambient;
	struct rgb diffuse;
	struct rgb specular;
	double shininess;
	double tilefade;
	char bitmap[16];
	struct v* verts;	//struct xyz
	struct v* tverts;	//struct xyz
	struct v* faces;	//struct v*	//int
	double displacement;
	double period;
	double tightness;
	struct v* constraints;	//int
	double alpha;
	double scale;
	struct rgb setfillumcolor;
};

struct nwn_mdl_node_reference
{
	struct xyz position;
	struct xyzw orientation;
	struct rgb wirecolor;
	char refModel[16];
	double reattachable;
};

struct nwn_mdl_node_skin_weight
{
	char* nodename;
	double weight;
};

struct nwn_mdl_node_skin
{
	struct rgb ambient;
	struct rgb diffuse;
	struct rgb specular;
	double shininess;
	char bitmap[16];
	struct v* verts;	//struct xyz
	struct v* tverts;	//struct xyz
	struct v* faces;	//struct v*	//int
	struct v* weights;	//struct nwn_mdl_node_skin_weight
};

struct nwn_mdl_node
{
	enum nwn_mdl_node_type type;
	char* name;
	struct nwn_mdl_node* parent;
	union
	{
		struct nwn_mdl_node_dummy* dummy;
		struct nwn_mdl_node_trimesh* trimesh;
		struct nwn_mdl_node_emitter* emitter;
		struct nwn_mdl_node_light* light;
		struct nwn_mdl_node_aabb* aabb;
		struct nwn_mdl_node_animmesh* animmesh;
		struct nwn_mdl_node_danglymesh* danglymesh;
		struct nwn_mdl_node_reference* reference;
		struct nwn_mdl_node_skin* skin;
	}
	node;
};

struct nwn_mdl
{
	char* filedependancy;
	char* newmodel;
	char* supermodel1;
	char* supermodel2;
	double animationscale;
	struct v* nodes;	//struct nwn_mdl_node
};

extern int nwmdl_debug;	/* equivalent to yydebug */

/**
 * given the *ASCII* MDL resource \a res (of length \a len bytes), parses it,
 * storing the information in nwn_mdl* \a mp.  On failure, returns 0.
 */
extern int nw_parse_mdl(char* res, int len, struct nwn_mdl* mp);
