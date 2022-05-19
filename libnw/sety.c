/* A Bison parser, made from /home/mshannon/OK/libnw/libnw/sety.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	token_integer	257
# define	token_real	258
# define	token_string	259
# define	token_GeneralHead	260
# define	token_Name	261
# define	token_UnlocalizedName	262
# define	token_Type	263
# define	token_Version	264
# define	token_Interior	265
# define	token_HasHeightTransition	266
# define	token_EnvMap	267
# define	token_Transition	268
# define	token_DisplayName	269
# define	token_Border	270
# define	token_Default	271
# define	token_Floor	272
# define	token_GrassHead	273
# define	token_Grass	274
# define	token_Density	275
# define	token_Height	276
# define	token_AmbientRed	277
# define	token_AmbientGreen	278
# define	token_AmbientBlue	279
# define	token_DiffuseRed	280
# define	token_DiffuseGreen	281
# define	token_DiffuseBlue	282
# define	token_TerrainTypesHead	283
# define	token_Count	284
# define	token_TerrainHead	285
# define	token_StrRef	286
# define	token_CrosserTypesHead	287
# define	token_Crosser	288
# define	token_CrosserHead	289
# define	token_PRulesHead	290
# define	token_PRuleHead	291
# define	token_Placed	292
# define	token_PlacedHeight	293
# define	token_Adjacent	294
# define	token_AdjacentHeight	295
# define	token_Changed	296
# define	token_ChangedHeight	297
# define	token_SRulesHead	298
# define	token_TilesHead	299
# define	token_TileHead	300
# define	token_Model	301
# define	token_WalkMesh	302
# define	token_TopLeft	303
# define	token_TopLeftHeight	304
# define	token_TopRight	305
# define	token_TopRightHeight	306
# define	token_BottomLeft	307
# define	token_BottomLeftHeight	308
# define	token_BottomRight	309
# define	token_BottomRightHeight	310
# define	token_Top	311
# define	token_Right	312
# define	token_Bottom	313
# define	token_Left	314
# define	token_MainLight1	315
# define	token_MainLight2	316
# define	token_SourceLight1	317
# define	token_SourceLight2	318
# define	token_AnimLoop1	319
# define	token_AnimLoop2	320
# define	token_AnimLoop3	321
# define	token_Doors	322
# define	token_Sounds	323
# define	token_PathNode	324
# define	token_Orientation	325
# define	token_VisibilityNode	326
# define	token_VisibilityOrientation	327
# define	token_DoorVisibilityNode	328
# define	token_DoorVisibilityOrientation	329
# define	token_ImageMap2D	330
# define	token_DoorHead	331
# define	token_X	332
# define	token_Y	333
# define	token_Z	334
# define	token_GroupsHead	335
# define	token_GroupHead	336
# define	token_TileRef	337
# define	token_Rows	338
# define	token_Columns	339

#line 1 "sety.y"


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


#line 99 "sety.y"
#ifndef YYSTYPE
typedef union {
	int integer;
	double real;
	char* string;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 1
#endif



#define	YYFINAL		317
#define	YYFLAG		-32768
#define	YYNTBASE	87

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 339 ? yytranslate[x] : 143)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    86,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     3,     6,    13,    16,    17,    19,    22,    26,
      30,    34,    38,    42,    46,    50,    54,    58,    62,    66,
      70,    73,    74,    76,    79,    83,    87,    91,    95,    99,
     103,   107,   111,   115,   118,   121,   125,   126,   128,   131,
     132,   133,   137,   138,   140,   143,   147,   151,   152,   155,
     158,   162,   163,   165,   168,   169,   170,   174,   175,   177,
     180,   184,   188,   191,   194,   198,   199,   201,   204,   205,
     206,   210,   211,   213,   216,   220,   224,   228,   232,   236,
     240,   241,   243,   246,   250,   253,   256,   260,   261,   263,
     266,   267,   268,   272,   273,   277,   278,   280,   283,   287,
     291,   295,   299,   303,   307,   311,   315,   319,   323,   327,
     330,   334,   337,   341,   344,   348,   351,   355,   359,   363,
     367,   371,   375,   379,   383,   387,   391,   395,   399,   403,
     407,   411,   415,   418,   419,   421,   424,   428,   432,   436,
     440,   444,   447,   450,   454,   455,   457,   460,   461,   465,
     466,   468,   471,   475,   479,   483,   487,   491,   493
};
static const short yyrhs[] =
{
      88,    89,     0,    90,    93,     0,    96,   104,   112,   120,
     123,   134,     0,     6,    91,     0,     0,    92,     0,    92,
      91,     0,     7,    86,     5,     0,     9,    86,     5,     0,
      10,    86,     5,     0,    11,    86,     3,     0,    12,    86,
       3,     0,    13,    86,     5,     0,    14,    86,     3,     0,
      15,    86,     3,     0,     8,    86,     5,     0,    16,    86,
       5,     0,    17,    86,     5,     0,    18,    86,     5,     0,
      19,    94,     0,     0,    95,     0,    95,    94,     0,    20,
      86,     3,     0,    21,    86,   142,     0,    22,    86,   142,
       0,    23,    86,   142,     0,    24,    86,   142,     0,    25,
      86,   142,     0,    26,    86,   142,     0,    27,    86,   142,
       0,    28,    86,   142,     0,    97,    99,     0,    29,    98,
       0,    30,    86,     3,     0,     0,   100,     0,   100,    99,
       0,     0,     0,    31,   101,   102,     0,     0,   103,     0,
     103,   102,     0,     7,    86,     5,     0,    32,    86,     3,
       0,     0,   105,   107,     0,    33,   106,     0,    30,    86,
       3,     0,     0,   108,     0,   108,   107,     0,     0,     0,
      35,   109,   110,     0,     0,   111,     0,   111,   110,     0,
       7,    86,     5,     0,    32,    86,     3,     0,   113,   115,
       0,    36,   114,     0,    30,    86,     3,     0,     0,   116,
       0,   116,   115,     0,     0,     0,    37,   117,   118,     0,
       0,   119,     0,   119,   118,     0,    38,    86,     5,     0,
      39,    86,     3,     0,    40,    86,     5,     0,    41,    86,
       3,     0,    42,    86,     5,     0,    43,    86,     3,     0,
       0,   121,     0,    44,   122,     0,    30,    86,     3,     0,
     124,   126,     0,    45,   125,     0,    30,    86,     3,     0,
       0,   127,     0,   127,   126,     0,     0,     0,    46,   128,
     130,     0,     0,    77,   129,   132,     0,     0,   131,     0,
     131,   130,     0,    47,    86,     5,     0,    48,    86,     5,
       0,    49,    86,     5,     0,    50,    86,     3,     0,    51,
      86,     5,     0,    52,    86,     3,     0,    53,    86,     5,
       0,    54,    86,     3,     0,    55,    86,     5,     0,    56,
      86,     3,     0,    57,    86,     5,     0,    57,    86,     0,
      58,    86,     5,     0,    58,    86,     0,    59,    86,     5,
       0,    59,    86,     0,    60,    86,     5,     0,    60,    86,
       0,    61,    86,     3,     0,    62,    86,     3,     0,    63,
      86,     3,     0,    64,    86,     3,     0,    65,    86,     3,
       0,    66,    86,     3,     0,    67,    86,     3,     0,    68,
      86,     3,     0,    69,    86,     3,     0,    70,    86,     5,
       0,    71,    86,     3,     0,    72,    86,     5,     0,    73,
      86,     3,     0,    74,    86,     5,     0,    75,    86,     3,
       0,    76,    86,     5,     0,    76,    86,     0,     0,   133,
       0,   133,   132,     0,     9,    86,     3,     0,    78,    86,
     142,     0,    79,    86,   142,     0,    80,    86,   142,     0,
      71,    86,   142,     0,   135,   137,     0,    81,   136,     0,
      30,    86,     3,     0,     0,   138,     0,   138,   137,     0,
       0,    82,   139,   140,     0,     0,   141,     0,   141,   140,
       0,     7,    86,     5,     0,    32,    86,     3,     0,    84,
      86,     3,     0,    85,    86,     3,     0,    83,    86,     3,
       0,     3,     0,     4,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   215,   219,   223,   227,   231,   232,   233,   237,   241,
     245,   249,   253,   257,   261,   265,   269,   273,   277,   281,
     288,   292,   293,   294,   298,   302,   306,   310,   314,   318,
     322,   326,   330,   337,   341,   345,   364,   365,   366,   370,
     371,   371,   375,   376,   377,   381,   385,   392,   393,   397,
     401,   420,   421,   422,   426,   427,   427,   431,   432,   433,
     437,   441,   448,   452,   456,   475,   476,   477,   481,   482,
     482,   486,   487,   488,   492,   496,   500,   504,   508,   512,
     519,   520,   524,   528,   547,   551,   555,   574,   575,   576,
     580,   581,   581,   582,   582,   597,   598,   599,   603,   607,
     611,   615,   619,   623,   627,   631,   635,   639,   643,   647,
     648,   652,   653,   657,   658,   662,   663,   667,   671,   675,
     679,   683,   687,   691,   707,   723,   727,   731,   735,   739,
     743,   747,   751,   758,   759,   760,   764,   768,   772,   776,
     780,   787,   791,   795,   814,   815,   816,   820,   820,   824,
     825,   826,   830,   834,   838,   842,   846,   861,   865
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "token_integer", "token_real", 
  "token_string", "token_GeneralHead", "token_Name", 
  "token_UnlocalizedName", "token_Type", "token_Version", 
  "token_Interior", "token_HasHeightTransition", "token_EnvMap", 
  "token_Transition", "token_DisplayName", "token_Border", 
  "token_Default", "token_Floor", "token_GrassHead", "token_Grass", 
  "token_Density", "token_Height", "token_AmbientRed", 
  "token_AmbientGreen", "token_AmbientBlue", "token_DiffuseRed", 
  "token_DiffuseGreen", "token_DiffuseBlue", "token_TerrainTypesHead", 
  "token_Count", "token_TerrainHead", "token_StrRef", 
  "token_CrosserTypesHead", "token_Crosser", "token_CrosserHead", 
  "token_PRulesHead", "token_PRuleHead", "token_Placed", 
  "token_PlacedHeight", "token_Adjacent", "token_AdjacentHeight", 
  "token_Changed", "token_ChangedHeight", "token_SRulesHead", 
  "token_TilesHead", "token_TileHead", "token_Model", "token_WalkMesh", 
  "token_TopLeft", "token_TopLeftHeight", "token_TopRight", 
  "token_TopRightHeight", "token_BottomLeft", "token_BottomLeftHeight", 
  "token_BottomRight", "token_BottomRightHeight", "token_Top", 
  "token_Right", "token_Bottom", "token_Left", "token_MainLight1", 
  "token_MainLight2", "token_SourceLight1", "token_SourceLight2", 
  "token_AnimLoop1", "token_AnimLoop2", "token_AnimLoop3", "token_Doors", 
  "token_Sounds", "token_PathNode", "token_Orientation", 
  "token_VisibilityNode", "token_VisibilityOrientation", 
  "token_DoorVisibilityNode", "token_DoorVisibilityOrientation", 
  "token_ImageMap2D", "token_DoorHead", "token_X", "token_Y", "token_Z", 
  "token_GroupsHead", "token_GroupHead", "token_TileRef", "token_Rows", 
  "token_Columns", "'='", "setfile", "fixedblocks", "variableblocks", 
  "generalblock", "generalspecs", "generalspec", "grassblock", 
  "grassspecs", "grassspec", "terrains", "terraintypeblock", 
  "terraintypespec", "terrainblocks", "terrainblock", "@1", 
  "terrainspecs", "terrainspec", "crossers", "crossertypeblock", 
  "crossertypespec", "crosserblocks", "crosserblock", "@2", 
  "crosserspecs", "crosserspec", "prules", "prulesblock", "prulesspec", 
  "pruleblocks", "pruleblock", "@3", "prulespecs", "prulespec", "srules", 
  "srulesblock", "srulesspec", "tiles", "tilesblock", "tilesspec", 
  "tileblocks", "tileblock", "@4", "@5", "tilespecs", "tilespec", 
  "doorspecs", "doorspec", "groups", "groupsblock", "groupsspec", 
  "groupblocks", "groupblock", "@6", "groupspecs", "groupspec", "numeric", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    87,    88,    89,    90,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    96,    97,    98,    99,    99,    99,   100,
     101,   100,   102,   102,   102,   103,   103,   104,   104,   105,
     106,   107,   107,   107,   108,   109,   108,   110,   110,   110,
     111,   111,   112,   113,   114,   115,   115,   115,   116,   117,
     116,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     120,   120,   121,   122,   123,   124,   125,   126,   126,   126,
     127,   128,   127,   129,   127,   130,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132,   132,   132,   133,   133,   133,   133,
     133,   134,   135,   136,   137,   137,   137,   139,   138,   140,
     140,   140,   141,   141,   141,   141,   141,   142,   142
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     2,     2,     6,     2,     0,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     0,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     0,     1,     2,     0,
       0,     3,     0,     1,     2,     3,     3,     0,     2,     2,
       3,     0,     1,     2,     0,     0,     3,     0,     1,     2,
       3,     3,     2,     2,     3,     0,     1,     2,     0,     0,
       3,     0,     1,     2,     3,     3,     3,     3,     3,     3,
       0,     1,     2,     3,     2,     2,     3,     0,     1,     2,
       0,     0,     3,     0,     3,     0,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     0,     1,     2,     3,     3,     3,     3,
       3,     2,     2,     3,     0,     1,     2,     0,     3,     0,
       1,     2,     3,     3,     3,     3,     3,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     0,     1,
      47,    36,    21,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,    34,     0,
       0,    51,    40,    33,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,    21,     8,    16,     9,    10,
      11,    12,    13,    14,    15,    17,    18,    19,     0,     0,
      49,     0,    80,    65,    55,    48,    51,    42,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    35,
       0,     0,    63,     0,     0,    81,    69,    62,    65,    57,
      53,     0,     0,    41,    42,    24,   157,   158,    25,    26,
      27,    28,    29,    30,    31,    32,    50,     0,     0,    82,
       0,     0,    87,    71,    67,     0,     0,    56,    57,     0,
       0,    44,    64,     0,     0,    85,     0,     3,   144,    91,
      93,    84,    87,     0,     0,     0,     0,     0,     0,    70,
      71,     0,     0,    59,    45,    46,    83,     0,     0,   142,
     147,   141,   144,    95,   133,    89,     0,     0,     0,     0,
       0,     0,    73,    60,    61,    86,     0,   149,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      95,     0,     0,     0,     0,     0,    94,   133,    74,    75,
      76,    77,    78,    79,   143,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   111,   113,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,    97,     0,     0,     0,     0,     0,   135,     0,
       0,     0,     0,     0,   151,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   110,   112,   114,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   136,   140,   137,   138,   139,
     152,   153,   156,   154,   155,     0,     0,     0
};

static const short yydefgoto[] =
{
     315,     2,    19,     3,    16,    17,    23,    54,    55,    20,
      21,    38,    43,    44,    77,   103,   104,    40,    41,    70,
      75,    76,    99,   127,   128,    72,    73,    92,    97,    98,
     123,   149,   150,    94,    95,   119,   121,   122,   135,   141,
     142,   163,   164,   209,   210,   216,   217,   137,   138,   159,
     161,   162,   177,   230,   231,   108
};

static const short yypact[] =
{
      28,     5,     8,    14,   -48,   -47,   -36,   -35,   -34,   -33,
     -32,   -31,   -30,   -29,   -28,   -27,-32768,     5,    30,-32768,
      29,    32,    21,-32768,    56,    59,    60,    61,    64,    65,
      66,    69,    70,    71,    75,    76,-32768,   -17,-32768,    44,
      46,    40,-32768,-32768,    32,    31,    33,    34,    35,    36,
      37,    38,    41,    42,-32768,    21,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   113,    43,
  -32768,    88,    81,    89,-32768,-32768,    40,     3,-32768,   127,
      27,    27,    27,    27,    27,    27,    27,    27,-32768,-32768,
     128,    47,-32768,   102,    90,-32768,-32768,-32768,    89,     4,
  -32768,    48,    50,-32768,     3,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,   134,    52,-32768,
     109,    62,   -37,   -14,-32768,    54,    55,-32768,     4,   137,
     141,-32768,-32768,   142,    63,-32768,   116,-32768,    68,-32768,
  -32768,-32768,   -37,    67,    72,    73,    74,    77,    78,-32768,
     -14,   143,   144,-32768,-32768,-32768,-32768,   148,    79,-32768,
  -32768,-32768,    68,    39,    -1,-32768,   147,   151,   150,   153,
     152,   158,-32768,-32768,-32768,-32768,   159,     0,-32768,    80,
      82,    83,    84,    85,    86,    87,    91,    92,    93,    94,
      95,    96,   101,   103,   104,   105,   106,   107,   108,   110,
     111,   112,   114,   115,   117,   118,   119,   120,   121,-32768,
      39,   122,   123,   124,   125,   126,-32768,    -1,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   129,   130,   131,   132,   133,
  -32768,     0,   162,   169,   170,   173,   183,   192,   194,   199,
     208,   211,   215,   216,   217,   218,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,-32768,   237,    27,    27,    27,    27,-32768,   238,
     239,   241,   242,   243,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,   247,   248,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,-32768,-32768,   240,-32768,-32768,   178,-32768,-32768,
  -32768,-32768,   205,-32768,-32768,   146,-32768,-32768,-32768,-32768,
     175,-32768,-32768,   135,-32768,-32768,-32768,-32768,   154,-32768,
  -32768,   136,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   138,
  -32768,-32768,-32768,    45,-32768,    49,-32768,-32768,-32768,-32768,
      97,-32768,-32768,    22,-32768,   -81
};


#define	YYLAST		286


static const short yytable[] =
{
     109,   110,   111,   112,   113,   114,   115,   225,   211,   139,
     101,   125,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   143,   144,   145,   146,   147,   148,
     106,   107,   226,    22,     1,   102,   126,    18,    24,    25,
     140,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      37,    56,    39,    42,    57,    58,    59,    60,    61,    68,
     212,    62,    63,    64,    69,    74,    65,   213,   214,   215,
      66,    67,    71,   227,   228,   229,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    89,    79,    91,    80,
      81,    82,    83,    84,    85,    93,    96,    86,    87,    90,
     105,   116,   118,   117,   129,   120,   130,   132,   133,   134,
     151,   152,   154,   136,   155,   156,   158,   174,   173,   157,
     160,   175,   218,   166,   219,   220,   221,   222,   167,   168,
     169,   223,   224,   170,   171,   176,   232,   275,   233,   234,
     235,   236,   237,   238,   276,   277,   278,   239,   240,   241,
     242,   243,   244,   306,   307,   308,   309,   245,   279,   246,
     247,   248,   249,   250,   251,   280,   252,   253,   254,   281,
     255,   256,   282,   257,   258,   259,   260,   261,   263,   264,
     265,   266,   267,   283,   284,   269,   270,   271,   272,   273,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    88,   299,   298,   301,   300,   303,   302,
     305,   304,   311,   310,   312,   313,   314,   316,   317,    78,
     131,   100,   124,   274,     0,   262,     0,    36,     0,   178,
       0,     0,     0,   153,     0,     0,   268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,     0,   172
};

static const short yycheck[] =
{
      81,    82,    83,    84,    85,    86,    87,     7,     9,    46,
       7,     7,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    38,    39,    40,    41,    42,    43,
       3,     4,    32,    19,     6,    32,    32,    29,    86,    86,
      77,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      30,     5,    33,    31,     5,     5,     5,     3,     3,    86,
      71,     5,     3,     3,    30,    35,     5,    78,    79,    80,
       5,     5,    36,    83,    84,    85,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     3,    86,    30,    86,
      86,    86,    86,    86,    86,    44,    37,    86,    86,    86,
       3,     3,    30,    86,    86,    45,    86,     3,    86,    30,
      86,    86,     5,    81,     3,     3,    30,     3,     5,    86,
      82,     3,     5,    86,     3,     5,     3,     5,    86,    86,
      86,     3,     3,    86,    86,    86,    86,     5,    86,    86,
      86,    86,    86,    86,     5,     5,     3,    86,    86,    86,
      86,    86,    86,   264,   265,   266,   267,    86,     5,    86,
      86,    86,    86,    86,    86,     3,    86,    86,    86,     5,
      86,    86,     3,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,     5,     3,    86,    86,    86,    86,    86,
       5,     5,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,    55,     3,     5,     3,     5,     3,     5,
       3,     5,     3,     5,     3,     3,     3,     0,     0,    44,
     104,    76,    98,   231,    -1,   210,    -1,    17,    -1,   162,
      -1,    -1,    -1,   128,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,   150
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison/bison.simple"

/* Skeleton output parser for bison,

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
   Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser when
   the %semantic_parser declaration is not specified in the grammar.
   It was written by Richard Stallman by simplifying the hairy parser
   used when %semantic_parser is specified.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
# if YYLSP_NEEDED
  YYLTYPE yyls;
# endif
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# if YYLSP_NEEDED
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
      + 2 * YYSTACK_GAP_MAX)
# else
#  define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)
# endif

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif


#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).

   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
   first token.  By default, to implement support for ranges, extend
   its range to the last symbol.  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
   Current.last_line   = Rhs[N].last_line;	\
   Current.last_column = Rhs[N].last_column;
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#if YYPURE
# if YYLSP_NEEDED
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, &yylloc, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval, &yylloc)
#  endif
# else /* !YYLSP_NEEDED */
#  ifdef YYLEX_PARAM
#   define YYLEX		yylex (&yylval, YYLEX_PARAM)
#  else
#   define YYLEX		yylex (&yylval)
#  endif
# endif /* !YYLSP_NEEDED */
#else /* !YYPURE */
# define YYLEX			yylex ()
#endif /* !YYPURE */


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

#ifdef YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif
#endif

#line 315 "/usr/share/bison/bison.simple"


/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif

/* YY_DECL_VARIABLES -- depending whether we use a pure parser,
   variables are global, or local to YYPARSE.  */

#define YY_DECL_NON_LSP_VARIABLES			\
/* The lookahead symbol.  */				\
int yychar;						\
							\
/* The semantic value of the lookahead symbol. */	\
YYSTYPE yylval;						\
							\
/* Number of parse errors so far.  */			\
int yynerrs;

#if YYLSP_NEEDED
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES			\
						\
/* Location data for the lookahead symbol.  */	\
YYLTYPE yylloc;
#else
# define YY_DECL_VARIABLES			\
YY_DECL_NON_LSP_VARIABLES
#endif


/* If nonreentrant, generate the variables here. */

#if !YYPURE
YY_DECL_VARIABLES
#endif  /* !YYPURE */

int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  /* If reentrant, generate the variables here. */
#if YYPURE
  YY_DECL_VARIABLES
#endif  /* !YYPURE */

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack. */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;

#if YYLSP_NEEDED
  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
#endif

#if YYLSP_NEEDED
# define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
# define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  YYSIZE_T yystacksize = YYINITDEPTH;


  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
#if YYLSP_NEEDED
  YYLTYPE yyloc;
#endif

  /* When reducing, the number of symbols on the RHS of the reduced
     rule. */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
#if YYLSP_NEEDED
  yylsp = yyls;
#endif
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  */
# if YYLSP_NEEDED
	YYLTYPE *yyls1 = yyls;
	/* This used to be a conditional around just the two extra args,
	   but that might be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
# else
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);
# endif
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
# if YYLSP_NEEDED
	YYSTACK_RELOCATE (yyls);
# endif
# undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
#if YYLSP_NEEDED
      yylsp = yyls + yysize - 1;
#endif

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

#if YYDEBUG
     /* We have to keep this `#if YYDEBUG', since we use variables
	which are defined only if `YYDEBUG' is set.  */
      if (yydebug)
	{
	  YYFPRINTF (stderr, "Next token is %d (%s",
		     yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise
	     meaning of a token, for further debugging info.  */
# ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
# endif
	  YYFPRINTF (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to the semantic value of
     the lookahead token.  This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

#if YYLSP_NEEDED
  /* Similarly for the default location.  Let the user run additional
     commands if for instance locations are ranges.  */
  yyloc = yylsp[1-yylen];
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
#endif

#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif

  switch (yyn) {

case 8:
#line 238 "sety.y"
{
		cur_Set->General.Name = strdup(yyvsp[0].string);
	}
    break;
case 9:
#line 242 "sety.y"
{
		cur_Set->General.Type = strdup(yyvsp[0].string);
	}
    break;
case 10:
#line 246 "sety.y"
{
		cur_Set->General.Version = strdup(yyvsp[0].string);
	}
    break;
case 11:
#line 250 "sety.y"
{
		cur_Set->General.Interior = yyvsp[0].integer;
	}
    break;
case 12:
#line 254 "sety.y"
{
		cur_Set->General.HasHeightTransition = yyvsp[0].integer;
	}
    break;
case 13:
#line 258 "sety.y"
{
		cur_Set->General.EnvMap = strdup(yyvsp[0].string);
	}
    break;
case 14:
#line 262 "sety.y"
{
		cur_Set->General.Transition = yyvsp[0].integer;
	}
    break;
case 15:
#line 266 "sety.y"
{
		cur_Set->General.DisplayName = yyvsp[0].integer;
	}
    break;
case 16:
#line 270 "sety.y"
{
		cur_Set->General.UnlocalizedName = strdup(yyvsp[0].string);
	}
    break;
case 17:
#line 274 "sety.y"
{
		cur_Set->General.Border = strdup(yyvsp[0].string);
	}
    break;
case 18:
#line 278 "sety.y"
{
		cur_Set->General.Default = strdup(yyvsp[0].string);
	}
    break;
case 19:
#line 282 "sety.y"
{
		cur_Set->General.Floor = strdup(yyvsp[0].string);
	}
    break;
case 24:
#line 299 "sety.y"
{
		cur_Set->Grass.Grass = yyvsp[0].integer;
	}
    break;
case 25:
#line 303 "sety.y"
{
		cur_Set->Grass.Density = yyvsp[0].real;
	}
    break;
case 26:
#line 307 "sety.y"
{
		cur_Set->Grass.Height = yyvsp[0].real;
	}
    break;
case 27:
#line 311 "sety.y"
{
		cur_Set->Grass.Ambient.r = yyvsp[0].real;
	}
    break;
case 28:
#line 315 "sety.y"
{
		cur_Set->Grass.Ambient.g = yyvsp[0].real;
	}
    break;
case 29:
#line 319 "sety.y"
{
		cur_Set->Grass.Ambient.b = yyvsp[0].real;
	}
    break;
case 30:
#line 323 "sety.y"
{
		cur_Set->Grass.Diffuse.r = yyvsp[0].real;
	}
    break;
case 31:
#line 327 "sety.y"
{
		cur_Set->Grass.Diffuse.g = yyvsp[0].real;
	}
    break;
case 32:
#line 331 "sety.y"
{
		cur_Set->Grass.Diffuse.b = yyvsp[0].real;
	}
    break;
case 35:
#line 346 "sety.y"
{
		int i;

		cur_Set->Terrains = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 40:
#line 371 "sety.y"
{ cur_Terrain = vsubig(cur_Set->Terrains, yyvsp[0].integer); }
    break;
case 45:
#line 382 "sety.y"
{
		cur_Terrain->Name = strdup(yyvsp[0].string);
	}
    break;
case 46:
#line 386 "sety.y"
{
		cur_Terrain->StrRef = yyvsp[0].integer;
	}
    break;
case 50:
#line 402 "sety.y"
{
		int i;

		cur_Set->Crossers = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 55:
#line 427 "sety.y"
{ cur_Crosser = vsubig(cur_Set->Crossers, yyvsp[0].integer); }
    break;
case 60:
#line 438 "sety.y"
{
		cur_Crosser->Name = strdup(yyvsp[0].string);
	}
    break;
case 61:
#line 442 "sety.y"
{
		cur_Crosser->StrRef = yyvsp[0].integer;
	}
    break;
case 64:
#line 457 "sety.y"
{
		int i;

		cur_Set->PrimaryRules = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 69:
#line 482 "sety.y"
{ cur_PRule = vsubig(cur_Set->PrimaryRules, yyvsp[0].integer); }
    break;
case 74:
#line 493 "sety.y"
{
		cur_PRule->Placed = strdup(yyvsp[0].string);
	}
    break;
case 75:
#line 497 "sety.y"
{
		cur_PRule->PlacedHeight = yyvsp[0].integer;
	}
    break;
case 76:
#line 501 "sety.y"
{
		cur_PRule->Adjacent = strdup(yyvsp[0].string);
	}
    break;
case 77:
#line 505 "sety.y"
{
		cur_PRule->AdjacentHeight = yyvsp[0].integer;
	}
    break;
case 78:
#line 509 "sety.y"
{
		cur_PRule->Changed = strdup(yyvsp[0].string);
	}
    break;
case 79:
#line 513 "sety.y"
{
		cur_PRule->ChangedHeight = yyvsp[0].integer;
	}
    break;
case 83:
#line 529 "sety.y"
{
		int i;

		cur_Set->SecondaryRules = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 86:
#line 556 "sety.y"
{
		int i;

		cur_Set->Tiles = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 91:
#line 581 "sety.y"
{ cur_Tile = vsubig(cur_Set->Tiles, yyvsp[0].integer); }
    break;
case 93:
#line 583 "sety.y"
{
		if (vlen(cur_Tile->Doors) <= yyvsp[0].integer)
		{
			int i = which_tile(cur_Set->Tiles, cur_Tile);

			fprintf(stderr, "Error: Tile%d <Model=%s>: Doors=%d; Door%d found!\n",
				i, cur_Tile->Model, vlen(cur_Tile->Doors), yyvsp[0].integer);
			return 1;
		}
		cur_Door = vsubig(cur_Tile->Doors, yyvsp[0].integer);
	}
    break;
case 98:
#line 604 "sety.y"
{
		cur_Tile->Model = strdup(yyvsp[0].string);
	}
    break;
case 99:
#line 608 "sety.y"
{
		cur_Tile->WalkMesh = strdup(yyvsp[0].string);
	}
    break;
case 100:
#line 612 "sety.y"
{
		cur_Tile->TopLeft = strdup(yyvsp[0].string);
	}
    break;
case 101:
#line 616 "sety.y"
{
		cur_Tile->TopLeftHeight = yyvsp[0].integer;
	}
    break;
case 102:
#line 620 "sety.y"
{
		cur_Tile->TopRight = strdup(yyvsp[0].string);
	}
    break;
case 103:
#line 624 "sety.y"
{
		cur_Tile->TopRightHeight = yyvsp[0].integer;
	}
    break;
case 104:
#line 628 "sety.y"
{
		cur_Tile->BottomLeft = strdup(yyvsp[0].string);
	}
    break;
case 105:
#line 632 "sety.y"
{
		cur_Tile->BottomLeftHeight = yyvsp[0].integer;
	}
    break;
case 106:
#line 636 "sety.y"
{
		cur_Tile->BottomRight = strdup(yyvsp[0].string);
	}
    break;
case 107:
#line 640 "sety.y"
{
		cur_Tile->BottomRightHeight = yyvsp[0].integer;
	}
    break;
case 108:
#line 644 "sety.y"
{
		cur_Tile->Top = strdup(yyvsp[0].string);
	}
    break;
case 110:
#line 649 "sety.y"
{
		cur_Tile->Right = strdup(yyvsp[0].string);
	}
    break;
case 112:
#line 654 "sety.y"
{
		cur_Tile->Bottom = strdup(yyvsp[0].string);
	}
    break;
case 114:
#line 659 "sety.y"
{
		cur_Tile->Left = strdup(yyvsp[0].string);
	}
    break;
case 116:
#line 664 "sety.y"
{
		cur_Tile->MainLight1 = yyvsp[0].integer;
	}
    break;
case 117:
#line 668 "sety.y"
{
		cur_Tile->MainLight2 = yyvsp[0].integer;
	}
    break;
case 118:
#line 672 "sety.y"
{
		cur_Tile->SourceLight1 = yyvsp[0].integer;
	}
    break;
case 119:
#line 676 "sety.y"
{
		cur_Tile->SourceLight2 = yyvsp[0].integer;
	}
    break;
case 120:
#line 680 "sety.y"
{
		cur_Tile->AnimLoop1 = yyvsp[0].integer;
	}
    break;
case 121:
#line 684 "sety.y"
{
		cur_Tile->AnimLoop2 = yyvsp[0].integer;
	}
    break;
case 122:
#line 688 "sety.y"
{
		cur_Tile->AnimLoop3 = yyvsp[0].integer;
	}
    break;
case 123:
#line 692 "sety.y"
{
		int i;

		cur_Tile->Doors = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 124:
#line 708 "sety.y"
{
		int i;

		cur_Tile->Sounds = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 125:
#line 724 "sety.y"
{
		cur_Tile->PathNode = strdup(yyvsp[0].string);
	}
    break;
case 126:
#line 728 "sety.y"
{
		cur_Tile->Orientation = yyvsp[0].integer;
	}
    break;
case 127:
#line 732 "sety.y"
{
		cur_Tile->VisibilityNode = strdup(yyvsp[0].string);
	}
    break;
case 128:
#line 736 "sety.y"
{
		cur_Tile->VisibilityOrientation = yyvsp[0].integer;
	}
    break;
case 129:
#line 740 "sety.y"
{
		cur_Tile->DoorVisibilityNode = strdup(yyvsp[0].string);
	}
    break;
case 130:
#line 744 "sety.y"
{
		cur_Tile->DoorVisibilityOrientation = yyvsp[0].integer;
	}
    break;
case 131:
#line 748 "sety.y"
{
		cur_Tile->ImageMap2D = strdup(yyvsp[0].string);
	}
    break;
case 132:
#line 752 "sety.y"
{
		cur_Tile->ImageMap2D = 0;
	}
    break;
case 136:
#line 765 "sety.y"
{
		cur_Door->Type = yyvsp[0].integer;
	}
    break;
case 137:
#line 769 "sety.y"
{
		cur_Door->X = yyvsp[0].real;
	}
    break;
case 138:
#line 773 "sety.y"
{
		cur_Door->Y = yyvsp[0].real;
	}
    break;
case 139:
#line 777 "sety.y"
{
		cur_Door->Z = yyvsp[0].real;
	}
    break;
case 140:
#line 781 "sety.y"
{
		cur_Door->Orientation = yyvsp[0].real;
	}
    break;
case 143:
#line 796 "sety.y"
{
		int i;

		cur_Set->Groups = vnew(yyvsp[0].integer);
		for (i = 0; i < yyvsp[0].integer; ++i)
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
    break;
case 147:
#line 820 "sety.y"
{ cur_Group = vsubig(cur_Set->Groups, yyvsp[0].integer); }
    break;
case 152:
#line 831 "sety.y"
{
		cur_Group->Name = strdup(yyvsp[0].string);
	}
    break;
case 153:
#line 835 "sety.y"
{
		cur_Group->StrRef = yyvsp[0].integer;
	}
    break;
case 154:
#line 839 "sety.y"
{
		cur_Group->Rows = yyvsp[0].integer;
	}
    break;
case 155:
#line 843 "sety.y"
{
		cur_Group->Columns = yyvsp[0].integer;
	}
    break;
case 156:
#line 847 "sety.y"
{
		if (!cur_Group->Tiles)
		{
			int i;

			cur_Group->Tiles = vnew(cur_Group->Rows * cur_Group->Columns);
			for (i = cur_Group->Rows * cur_Group->Columns; i >= 0; --i)
				vapp(cur_Group->Tiles, 0);
		}
		vsubip(cur_Group->Tiles, yyvsp[-2].integer, vsubig(cur_Set->Tiles, yyvsp[0].integer));
	}
    break;
case 157:
#line 862 "sety.y"
{
		yyval.real = yyvsp[0].integer;
	}
    break;
case 158:
#line 866 "sety.y"
{
		yyval.real = yyvsp[0].real;
	}
    break;
}

#line 705 "/usr/share/bison/bison.simple"


  yyvsp -= yylen;
  yyssp -= yylen;
#if YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;
#if YYLSP_NEEDED
  *++yylsp = yyloc;
#endif

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[YYTRANSLATE (yychar)]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[YYTRANSLATE (yychar)]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* defined (YYERROR_VERBOSE) */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*--------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action |
`--------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;
      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;


/*-------------------------------------------------------------------.
| yyerrdefault -- current state does not do anything special for the |
| error token.                                                       |
`-------------------------------------------------------------------*/
yyerrdefault:
#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */

  /* If its default is to accept any token, ok.  Otherwise pop it.  */
  yyn = yydefact[yystate];
  if (yyn)
    goto yydefault;
#endif


/*---------------------------------------------------------------.
| yyerrpop -- pop the current state because it cannot handle the |
| error token                                                    |
`---------------------------------------------------------------*/
yyerrpop:
  if (yyssp == yyss)
    YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#if YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "Error: state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

/*--------------.
| yyerrhandle.  |
`--------------*/
yyerrhandle:
  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;
#if YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

/*---------------------------------------------.
| yyoverflowab -- parser overflow comes here.  |
`---------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}
#line 871 "sety.y"


void nwset_error(char* s)
{
	fprintf(stderr, "%s\n", s);
}

int nwset_wrap(void)
{
	return 1;
}
