%{

#include	<config.h>
#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include	<memory.h>
# endif
# include	<string.h>
#endif
#include	"rgb.h"
#include	"set.h"
#include	"v.h"

/*
The following idiocy is due to the incapability of automake/ylwrap to cope
with multiple grammars and lexers in the same directory.
*/

#define	yymaxdepth	nwset_maxdepth
#define	yyparse	nwset_parse
#define	yylex	nwset_lex
#define	yyerror	nwset_error
#define	yylval	nwset_lval
#define	yychar	nwset_char
#define	yydebug	nwset_debug
#define	yypact	nwset_pact
#define	yyr1	nwset_r1
#define	yyr2	nwset_r2
#define	yydef	nwset_def
#define	yychk	nwset_chk
#define	yypgo	nwset_pgo
#define	yyact	nwset_act
#define	yyexca	nwset_exca
#define	yyerrflag	nwset_errflag
#define	yynerrs	nwset_nerrs
#define	yyps	nwset_ps
#define	yypv	nwset_pv
#define	yys	nwset_s
#define	yy_yys	nwset_yys
#define	yystate	nwset_state
#define	yytmp	nwset_tmp
#define	yyv	nwset_v
#define	yy_yyv	nwset_yyv
#define	yyval	nwset_val
#define	yylloc	nwset_lloc
#define	yyreds	nwset_reds
#define	yytoks	nwset_toks
#define	yylhs	nwset_yylhs
#define	yylen	nwset_yylen
#define	yydefred	nwset_yydefred
#define	yydgoto	nwset_yydgoto
#define	yysindex	nwset_yysindex
#define	yyrindex	nwset_yyrindex
#define	yygindex	nwset_yygindex
#define	yytable	nwset_yytable
#define	yycheck	nwset_yycheck
#define	yyname	nwset_yyname
#define	yyrule	nwset_yyrule

extern int yylex();
extern void yyerror(char* s);
extern void nwset__scan_bytes(char*, int);
extern int nwset_parse(void);

static struct nwn_set* cur_Set;
static struct nwn_set_crosser* cur_Crosser;
static struct nwn_set_terrain* cur_Terrain;
static struct nwn_set_rule* cur_PRule;
/* static struct nwn_set_rule* cur_SRule; */
static struct nwn_set_tile* cur_Tile;
static struct nwn_set_tile_door* cur_Door;
static struct nwn_set_group* cur_Group;

static int which_tile(struct v* vp, struct nwn_set_tile* tp)
{
	int i;
	int len = vlen(vp);

	for (i = 0; i < len; ++i)
		if (vsubig(vp, i) == tp)
			return i;
	return -1;
}


int nw_parse_set(char* setfile1, int setleng1, struct nwn_set* sp)
{
	cur_Set = sp;
	nwset__scan_bytes(setfile1, setleng1);
	return nwset_parse();
}

%}

%union {
	int integer;
	double real;
	char* string;
};

/* fundamental value types */
%token <integer> token_integer
%token <real> token_real
%token <string> token_string

/* specific "words" ("keywords") */
%token token_GeneralHead
%token token_Name
%token token_UnlocalizedName
%token token_Type
%token token_Version
%token token_Interior
%token token_HasHeightTransition
%token token_EnvMap
%token token_Transition
%token token_DisplayName
%token token_Border
%token token_Default
%token token_Floor

%token token_GrassHead
%token token_Grass
%token token_Density
%token token_Height
%token token_AmbientRed
%token token_AmbientGreen
%token token_AmbientBlue
%token token_DiffuseRed
%token token_DiffuseGreen
%token token_DiffuseBlue

%token token_TerrainTypesHead
%token token_Count

%token <integer> token_TerrainHead
%token token_StrRef

%token token_CrosserTypesHead
%token token_Crosser

%token <integer> token_CrosserHead

%token token_PRulesHead

%token <integer> token_PRuleHead

%token token_Placed
%token token_PlacedHeight
%token token_Adjacent
%token token_AdjacentHeight
%token token_Changed
%token token_ChangedHeight

%token token_SRulesHead

%token token_TilesHead

%token <integer> token_TileHead

%token token_Model
%token token_WalkMesh
%token token_TopLeft
%token token_TopLeftHeight
%token token_TopRight
%token token_TopRightHeight
%token token_BottomLeft
%token token_BottomLeftHeight
%token token_BottomRight
%token token_BottomRightHeight
%token token_Top
%token token_Right
%token token_Bottom
%token token_Left
%token token_MainLight1
%token token_MainLight2
%token token_SourceLight1
%token token_SourceLight2
%token token_AnimLoop1
%token token_AnimLoop2
%token token_AnimLoop3
%token token_Doors
%token token_Sounds
%token token_PathNode
%token token_Orientation
%token token_VisibilityNode
%token token_VisibilityOrientation
%token token_DoorVisibilityNode
%token token_DoorVisibilityOrientation
%token token_ImageMap2D

%token <integer> token_DoorHead

%token token_X
%token token_Y
%token token_Z

%token token_GroupsHead

%token <integer> token_GroupHead

%token <integer> token_TileRef

%token token_Rows
%token token_Columns

%type <real> numeric

%%

setfile
	: fixedblocks variableblocks
	;
	
fixedblocks
	: generalblock grassblock
	;

variableblocks
	: terrains crossers prules srules tiles groups
	;

generalblock
	: token_GeneralHead generalspecs
	;

generalspecs
	: /* empty */
	| generalspec
	| generalspec generalspecs
	;

generalspec
	: token_Name '=' token_string =
	{
		cur_Set->General.Name = strdup($3);
	}
	| token_Type '=' token_string =
	{
		cur_Set->General.Type = strdup($3);
	}
	| token_Version '=' token_string =
	{
		cur_Set->General.Version = strdup($3);
	}
	| token_Interior '=' token_integer =
	{
		cur_Set->General.Interior = $3;
	}
	| token_HasHeightTransition '=' token_integer =
	{
		cur_Set->General.HasHeightTransition = $3;
	}
	| token_EnvMap '=' token_string =
	{
		cur_Set->General.EnvMap = strdup($3);
	}
	| token_Transition '=' token_integer =
	{
		cur_Set->General.Transition = $3;
	}
	| token_DisplayName '=' token_integer =
	{
		cur_Set->General.DisplayName = $3;
	}
	| token_UnlocalizedName '=' token_string =
	{
		cur_Set->General.UnlocalizedName = strdup($3);
	}
	| token_Border '=' token_string =
	{
		cur_Set->General.Border = strdup($3);
	}
	| token_Default '=' token_string =
	{
		cur_Set->General.Default = strdup($3);
	}
	| token_Floor '=' token_string =
	{
		cur_Set->General.Floor = strdup($3);
	}
	;

grassblock
	: token_GrassHead grassspecs
	;

grassspecs
	: /* empty */
	| grassspec
	| grassspec grassspecs
	;

grassspec
	: token_Grass '=' token_integer =
	{
		cur_Set->Grass.Grass = $3;
	}
	| token_Density '=' numeric =
	{
		cur_Set->Grass.Density = $3;
	}
	| token_Height '=' numeric =
	{
		cur_Set->Grass.Height = $3;
	}
	| token_AmbientRed '=' numeric =
	{
		cur_Set->Grass.Ambient.r = $3;
	}
	| token_AmbientGreen '=' numeric =
	{
		cur_Set->Grass.Ambient.g = $3;
	}
	| token_AmbientBlue '=' numeric =
	{
		cur_Set->Grass.Ambient.b = $3;
	}
	| token_DiffuseRed '=' numeric =
	{
		cur_Set->Grass.Diffuse.r = $3;
	}
	| token_DiffuseGreen '=' numeric =
	{
		cur_Set->Grass.Diffuse.g = $3;
	}
	| token_DiffuseBlue '=' numeric =
	{
		cur_Set->Grass.Diffuse.b = $3;
	}
	;

terrains
	: terraintypeblock terrainblocks
	;

terraintypeblock
	: token_TerrainTypesHead terraintypespec
	;

terraintypespec
	: token_Count '=' token_integer =
	{
		int i;

		cur_Set->Terrains = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_terrain));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a terrain!\n");
				abort();
			}
			vapp(cur_Set->Terrains, p);
		}
	}
	;

terrainblocks
	: /* empty */
	| terrainblock
	| terrainblock terrainblocks
	;

terrainblock
	: /* empty */
	| token_TerrainHead { cur_Terrain = vsubig(cur_Set->Terrains, $1); } terrainspecs
	;

terrainspecs
	: /* empty */
	| terrainspec
	| terrainspec terrainspecs
	;

terrainspec
	: token_Name '=' token_string =
	{
		cur_Terrain->Name = strdup($3);
	}
	| token_StrRef '=' token_integer =
	{
		cur_Terrain->StrRef = $3;
	}
	;

crossers
	: /* empty */
	| crossertypeblock crosserblocks
	;

crossertypeblock
	: token_CrosserTypesHead crossertypespec
	;

crossertypespec
	: token_Count '=' token_integer =
	{
		int i;

		cur_Set->Crossers = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_crosser));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a crosser!\n");
				abort();
			}
			vapp(cur_Set->Crossers, p);
		}
	}
	;

crosserblocks
	: /* empty */
	| crosserblock
	| crosserblock crosserblocks
	;

crosserblock
	: /* empty */
	| token_CrosserHead { cur_Crosser = vsubig(cur_Set->Crossers, $1); } crosserspecs
	;

crosserspecs
	: /* empty */
	| crosserspec
	| crosserspec crosserspecs
	;

crosserspec
	: token_Name '=' token_string =
	{
		cur_Crosser->Name = strdup($3);
	}
	| token_StrRef '=' token_integer =
	{
		cur_Crosser->StrRef = $3;
	}
	;

prules
	: prulesblock pruleblocks
	;

prulesblock
	: token_PRulesHead prulesspec
	;

prulesspec
	: token_Count '=' token_integer
	{
		int i;

		cur_Set->PrimaryRules = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_rule));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a primary rule!\n");
				abort();
			}
			vapp(cur_Set->PrimaryRules, p);
		}
	}
	;

pruleblocks
	: /* empty */
	| pruleblock
	| pruleblock pruleblocks
	;

pruleblock
	: /* empty */
	| token_PRuleHead { cur_PRule = vsubig(cur_Set->PrimaryRules, $1); } prulespecs
	;

prulespecs
	: /* empty */
	| prulespec
	| prulespec prulespecs
	;

prulespec
	: token_Placed '=' token_string =
	{
		cur_PRule->Placed = strdup($3);
	}
	| token_PlacedHeight '=' token_integer =
	{
		cur_PRule->PlacedHeight = $3;
	}
	| token_Adjacent '=' token_string =
	{
		cur_PRule->Adjacent = strdup($3);
	}
	| token_AdjacentHeight '=' token_integer =
	{
		cur_PRule->AdjacentHeight = $3;
	}
	| token_Changed '=' token_string =
	{
		cur_PRule->Changed = strdup($3);
	}
	| token_ChangedHeight '=' token_integer =
	{
		cur_PRule->ChangedHeight = $3;
	}
	;

srules
	: /* empty */
	| srulesblock
	;

srulesblock
	: token_SRulesHead srulesspec
	;

srulesspec
	: token_Count '=' token_integer =
	{
		int i;

		cur_Set->SecondaryRules = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_rule));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a secondary rule!\n");
				abort();
			}
			vapp(cur_Set->SecondaryRules, p);
		}
	}
	;

tiles
	: tilesblock tileblocks
	;

tilesblock
	: token_TilesHead tilesspec
	;

tilesspec
	: token_Count '=' token_integer
	{
		int i;

		cur_Set->Tiles = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_tile));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a tile!\n");
				abort();
			}
			vapp(cur_Set->Tiles, p);
		}
	}
	;

tileblocks
	: /* empty */
	| tileblock
	| tileblock tileblocks
	;

tileblock
	: /* empty */
	| token_TileHead { cur_Tile = vsubig(cur_Set->Tiles, $1); } tilespecs
	| token_DoorHead
	{
		if (vlen(cur_Tile->Doors) <= $1)
		{
			int i = which_tile(cur_Set->Tiles, cur_Tile);

			fprintf(stderr, "Error: Tile%d <Model=%s>: Doors=%d; Door%d found!\n",
				i, cur_Tile->Model, vlen(cur_Tile->Doors), $1);
			return 1;
		}
		cur_Door = vsubig(cur_Tile->Doors, $1);
	} doorspecs
	;

tilespecs
	: /* empty */
	| tilespec
	| tilespec tilespecs
	;

tilespec
	: token_Model '=' token_string =
	{
		cur_Tile->Model = strdup($3);
	}
	| token_WalkMesh '=' token_string =
	{
		cur_Tile->WalkMesh = strdup($3);
	}
	| token_TopLeft '=' token_string =
	{
		cur_Tile->TopLeft = strdup($3);
	}
	| token_TopLeftHeight '=' token_integer =
	{
		cur_Tile->TopLeftHeight = $3;
	}
	| token_TopRight '=' token_string =
	{
		cur_Tile->TopRight = strdup($3);
	}
	| token_TopRightHeight '=' token_integer =
	{
		cur_Tile->TopRightHeight = $3;
	}
	| token_BottomLeft '=' token_string =
	{
		cur_Tile->BottomLeft = strdup($3);
	}
	| token_BottomLeftHeight '=' token_integer =
	{
		cur_Tile->BottomLeftHeight = $3;
	}
	| token_BottomRight '=' token_string =
	{
		cur_Tile->BottomRight = strdup($3);
	}
	| token_BottomRightHeight '=' token_integer =
	{
		cur_Tile->BottomRightHeight = $3;
	}
	| token_Top '=' token_string =
	{
		cur_Tile->Top = strdup($3);
	}
	| token_Top '=' /* can be empty */
	| token_Right '=' token_string =
	{
		cur_Tile->Right = strdup($3);
	}
	| token_Right '=' /* can be empty */
	| token_Bottom '=' token_string =
	{
		cur_Tile->Bottom = strdup($3);
	}
	| token_Bottom '=' /* can be empty */
	| token_Left '=' token_string =
	{
		cur_Tile->Left = strdup($3);
	}
	| token_Left '=' /* can be empty */
	| token_MainLight1 '=' token_integer =
	{
		cur_Tile->MainLight1 = $3;
	}
	| token_MainLight2 '=' token_integer =
	{
		cur_Tile->MainLight2 = $3;
	}
	| token_SourceLight1 '=' token_integer =
	{
		cur_Tile->SourceLight1 = $3;
	}
	| token_SourceLight2 '=' token_integer =
	{
		cur_Tile->SourceLight2 = $3;
	}
	| token_AnimLoop1 '=' token_integer =
	{
		cur_Tile->AnimLoop1 = $3;
	}
	| token_AnimLoop2 '=' token_integer =
	{
		cur_Tile->AnimLoop2 = $3;
	}
	| token_AnimLoop3 '=' token_integer =
	{
		cur_Tile->AnimLoop3 = $3;
	}
	| token_Doors '=' token_integer =
	{
		int i;

		cur_Tile->Doors = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_tile_door));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a door!\n");
				abort();
			}
			vapp(cur_Tile->Doors, p);
		}
	}
	| token_Sounds '=' token_integer =
	{
		int i;

		cur_Tile->Sounds = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_tile_sound));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a sound!\n");
				abort();
			}
			vapp(cur_Tile->Sounds, p);
		}
	}
	| token_PathNode '=' token_string =
	{
		cur_Tile->PathNode = strdup($3);
	}
	| token_Orientation '=' token_integer =
	{
		cur_Tile->Orientation = $3;
	}
	| token_VisibilityNode '=' token_string =
	{
		cur_Tile->VisibilityNode = strdup($3);
	}
	| token_VisibilityOrientation '=' token_integer =
	{
		cur_Tile->VisibilityOrientation = $3;
	}
	| token_DoorVisibilityNode '=' token_string =
	{
		cur_Tile->DoorVisibilityNode = strdup($3);
	}
	| token_DoorVisibilityOrientation '=' token_integer =
	{
		cur_Tile->DoorVisibilityOrientation = $3;
	}
	| token_ImageMap2D '=' token_string =
	{
		cur_Tile->ImageMap2D = strdup($3);
	}
	| token_ImageMap2D '=' /* empty */ =
	{
		cur_Tile->ImageMap2D = 0;
	}
	;

doorspecs
	: /* empty */
	| doorspec
	| doorspec doorspecs
	;

doorspec
	: token_Type '=' token_integer =
	{
		cur_Door->Type = $3;
	}
	| token_X '=' numeric =
	{
		cur_Door->X = $3;
	}
	| token_Y '=' numeric =
	{
		cur_Door->Y = $3;
	}
	| token_Z '=' numeric =
	{
		cur_Door->Z = $3;
	}
	| token_Orientation '=' numeric =
	{
		cur_Door->Orientation = $3;
	}
	;

groups
	: groupsblock groupblocks
	;

groupsblock
	: token_GroupsHead groupsspec
	;

groupsspec
	: token_Count '=' token_integer =
	{
		int i;

		cur_Set->Groups = vnew($3);
		for (i = 0; i < $3; ++i)
		{
			void* p = malloc(sizeof (struct nwn_set_group));
			if (!p)
			{
				fprintf(stderr, "Can't allocate a group!\n");
				abort();
			}
			vapp(cur_Set->Groups, p);
		}
	}
	;

groupblocks
	: /* empty */
	| groupblock
	| groupblock groupblocks
	;

groupblock
	: token_GroupHead { cur_Group = vsubig(cur_Set->Groups, $1); } groupspecs
	;

groupspecs
	: /* empty */
	| groupspec
	| groupspec groupspecs
	;

groupspec
	: token_Name '=' token_string =
	{
		cur_Group->Name = strdup($3);
	}
	| token_StrRef '=' token_integer =
	{
		cur_Group->StrRef = $3;
	}
	| token_Rows '=' token_integer =
	{
		cur_Group->Rows = $3;
	}
	| token_Columns '=' token_integer =
	{
		cur_Group->Columns = $3;
	}
	| token_TileRef '=' token_integer =
	{
		if (!cur_Group->Tiles)
		{
			int i;

			cur_Group->Tiles = vnew(cur_Group->Rows * cur_Group->Columns);
			for (i = cur_Group->Rows * cur_Group->Columns; i >= 0; --i)
				vapp(cur_Group->Tiles, 0);
		}
		vsubip(cur_Group->Tiles, $1, vsubig(cur_Set->Tiles, $3));
	}
	;

numeric
	: token_integer
	{
		$$ = $1;
	}
	| token_real =
	{
		$$ = $1;
	}
	;

%%

void nwset_error(char* s)
{
	fprintf(stderr, "%s\n", s);
}

int nwset_wrap(void)
{
	return 1;
}
