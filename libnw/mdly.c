/* A Bison parser, made from /home/mshannon/OK/libnw/libnw/mdly.y
   by GNU bison 1.35.  */

#define YYBISON 1  /* Identify Bison output.  */

# define	token_integer	257
# define	token_real	258
# define	token_string	259
# define	token_aabb	260
# define	token_affectdynamic	261
# define	token_alpha	262
# define	token_ambientonly	263
# define	token_ambient	264
# define	token_beginmodelgeom	265
# define	token_bitmap	266
# define	token_classification	267
# define	token_color	268
# define	token_diffuse	269
# define	token_donemodel	270
# define	token_dummy	271
# define	token_endmodelgeom	272
# define	token_endnode	273
# define	token_faces	274
# define	token_fadingLight	275
# define	token_filedependancy	276
# define	token_flareradius	277
# define	token_isdynamic	278
# define	token_lightpriority	279
# define	token_model	280
# define	token_multiplier	281
# define	token_newmodel	282
# define	token_node	283
# define	token_orientation	284
# define	token_parent	285
# define	token_position	286
# define	token_radius	287
# define	token_rotatetexture	288
# define	token_scale	289
# define	token_setanimationscale	290
# define	token_setfillumcolor	291
# define	token_setsupermodel	292
# define	token_shadow	293
# define	token_shininess	294
# define	token_specular	295
# define	token_tilefade	296
# define	token_tile	297
# define	token_transparencyhint	298
# define	token_trimesh	299
# define	token_tverts	300
# define	token_verts	301

#line 1 "mdly.y"


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
#include	"mdl.h"

/*
The following idiocy is due to the incapability of automake/ylwrap to cope
with multiple grammars and lexers in the same directory.
*/

#define	yymaxdepth	nwmdl_maxdepth
#define	yyparse	nwmdl_parse
#define	yylex	nwmdl_lex
#define	yyerror	nwmdl_error
#define	yylval	nwmdl_lval
#define	yychar	nwmdl_char
#define	yydebug	nwmdl_debug
#define	yypact	nwmdl_pact
#define	yyr1	nwmdl_r1
#define	yyr2	nwmdl_r2
#define	yydef	nwmdl_def
#define	yychk	nwmdl_chk
#define	yypgo	nwmdl_pgo
#define	yyact	nwmdl_act
#define	yyexca	nwmdl_exca
#define	yyerrflag	nwmdl_errflag
#define	yynerrs	nwmdl_nerrs
#define	yyps	nwmdl_ps
#define	yypv	nwmdl_pv
#define	yys	nwmdl_s
#define	yy_yys	nwmdl_yys
#define	yystate	nwmdl_state
#define	yytmp	nwmdl_tmp
#define	yyv	nwmdl_v
#define	yy_yyv	nwmdl_yyv
#define	yyval	nwmdl_val
#define	yylloc	nwmdl_lloc
#define	yyreds	nwmdl_reds
#define	yytoks	nwmdl_toks
#define	yylhs	nwmdl_yylhs
#define	yylen	nwmdl_yylen
#define	yydefred	nwmdl_yydefred
#define	yydgoto	nwmdl_yydgoto
#define	yysindex	nwmdl_yysindex
#define	yyrindex	nwmdl_yyrindex
#define	yygindex	nwmdl_yygindex
#define	yytable	nwmdl_yytable
#define	yycheck	nwmdl_yycheck
#define	yyname	nwmdl_yyname
#define	yyrule	nwmdl_yyrule

extern int yylex();
extern void yyerror(char* s);
extern void nwmdl__scan_bytes(char*, int);
extern int nwmdl_parse(void);

static struct nwn_mdl* cur_Mdl;
static struct nwn_mdl_node* cur_Node;

int nw_parse_mdl(char* setfile1, int setleng1, struct nwn_mdl* mp)
{
	cur_Mdl = mp;
	nwmdl__scan_bytes(setfile1, setleng1);
	return nwmdl_parse();
}


#line 80 "mdly.y"
#ifndef YYSTYPE
typedef union {
	int integer;
	double real;
	char* string;
	struct xyz xyz;
	struct xyzw xyzw;
	struct rgb rgb;
	int face[8];
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
#ifndef YYDEBUG
# define YYDEBUG 1
#endif



#define	YYFINAL		136
#define	YYFLAG		-32768
#define	YYNTBASE	48

/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
#define YYTRANSLATE(x) ((unsigned)(x) <= 301 ? yytranslate[x] : 77)

/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
static const char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      46,    47
};

#if YYDEBUG
static const short yyprhs[] =
{
       0,     0,     5,     6,     8,    11,    14,    17,    21,    24,
      27,    33,    34,    36,    39,    41,    43,    45,    49,    53,
      54,    56,    59,    62,    65,    68,    72,    76,    77,    79,
      82,    85,    88,    91,    94,    97,   100,   103,   106,   109,
     112,   113,   118,   119,   124,   125,   130,   131,   133,   136,
     137,   139,   142,   143,   145,   148,   152,   156,   157,   159,
     162,   165,   168,   171,   174,   177,   180,   183,   186,   189,
     192,   201,   205,   210,   214,   216
};
static const short yyrhs[] =
{
      49,    51,    16,     5,     0,     0,    50,     0,    49,    50,
       0,    22,     5,     0,    28,     5,     0,    38,     5,     5,
       0,    13,    26,     0,    36,     4,     0,    11,     5,    52,
      18,     5,     0,     0,    53,     0,    52,    53,     0,    54,
       0,    58,     0,    68,     0,    55,    56,    19,     0,    29,
      17,     5,     0,     0,    57,     0,    56,    57,     0,    31,
       5,     0,    32,    73,     0,    30,    74,     0,    59,    60,
      19,     0,    29,    45,     5,     0,     0,    61,     0,    60,
      61,     0,    31,     5,     0,    32,    73,     0,    30,    74,
       0,    10,    75,     0,    15,    75,     0,    41,    75,     0,
      40,    76,     0,    39,    76,     0,    44,    76,     0,    12,
       5,     0,     0,    47,    76,    62,    65,     0,     0,    46,
      76,    63,    66,     0,     0,    20,    76,    64,    67,     0,
       0,    73,     0,    65,    73,     0,     0,    73,     0,    66,
      73,     0,     0,    72,     0,    67,    72,     0,    69,    70,
      19,     0,    29,     6,     5,     0,     0,    71,     0,    70,
      71,     0,    31,     5,     0,    10,    75,     0,    15,    75,
       0,    41,    75,     0,    40,    76,     0,    39,    76,     0,
      44,    76,     0,    12,     5,     0,    32,    73,     0,    30,
      74,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       0,    76,    76,    76,     0,    76,    76,    76,    76,     0,
      76,    76,    76,     0,     3,     0,     4,     0
};

#endif

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
static const short yyrline[] =
{
       0,   149,   153,   154,   155,   159,   163,   167,   172,   173,
     180,   184,   185,   186,   190,   191,   192,   196,   200,   209,
     210,   211,   215,   219,   223,   230,   234,   242,   243,   244,
     248,   252,   256,   260,   264,   268,   272,   276,   280,   284,
     288,   288,   289,   289,   290,   290,   294,   295,   301,   310,
     311,   317,   326,   327,   333,   342,   346,   354,   355,   356,
     360,   364,   368,   372,   376,   380,   384,   388,   392,   396,
     403,   410,   417,   424,   431,   435
};
#endif


#if (YYDEBUG) || defined YYERROR_VERBOSE

/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
static const char *const yytname[] =
{
  "$", "error", "$undefined.", "token_integer", "token_real", 
  "token_string", "token_aabb", "token_affectdynamic", "token_alpha", 
  "token_ambientonly", "token_ambient", "token_beginmodelgeom", 
  "token_bitmap", "token_classification", "token_color", "token_diffuse", 
  "token_donemodel", "token_dummy", "token_endmodelgeom", "token_endnode", 
  "token_faces", "token_fadingLight", "token_filedependancy", 
  "token_flareradius", "token_isdynamic", "token_lightpriority", 
  "token_model", "token_multiplier", "token_newmodel", "token_node", 
  "token_orientation", "token_parent", "token_position", "token_radius", 
  "token_rotatetexture", "token_scale", "token_setanimationscale", 
  "token_setfillumcolor", "token_setsupermodel", "token_shadow", 
  "token_shininess", "token_specular", "token_tilefade", "token_tile", 
  "token_transparencyhint", "token_trimesh", "token_tverts", 
  "token_verts", "mdlfile", "mdlhead_stmts", "mdlhead_stmt", "model", 
  "mdlnodes", "mdlnode", "dummynode", "dummynodestart", 
  "dummynodecontents", "dummynodeelement", "trimeshnode", 
  "trimeshnodestart", "trimeshnodecontents", "trimeshnodeelement", "@1", 
  "@2", "@3", "trimeshverts", "trimeshtverts", "trimeshfaces", "aabbnode", 
  "aabbnodestart", "aabbnodecontents", "aabbnodeelement", "face", "xyz", 
  "xyzw", "rgb", "numeric", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
static const short yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      51,    52,    52,    52,    53,    53,    53,    54,    55,    56,
      56,    56,    57,    57,    57,    58,    59,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    61,    63,    61,    64,    61,    65,    65,    65,    66,
      66,    66,    67,    67,    67,    68,    69,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    73,    74,    75,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
static const short yyr2[] =
{
       0,     4,     0,     1,     2,     2,     2,     3,     2,     2,
       5,     0,     1,     2,     1,     1,     1,     3,     3,     0,
       1,     2,     2,     2,     2,     3,     3,     0,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     4,     0,     4,     0,     4,     0,     1,     2,     0,
       1,     2,     0,     1,     2,     3,     3,     0,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       8,     3,     4,     3,     1,     1
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error. */
static const short yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     3,     8,     5,
       6,     9,     0,     0,     4,     0,     7,    11,     0,     0,
       0,    12,    14,    19,    15,    27,    16,    57,     1,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    56,    18,    26,    10,
      74,    75,    24,     0,    22,    23,     0,    17,    21,    33,
       0,    39,    34,    44,    32,    30,    31,    37,    36,    35,
      38,    42,    40,    25,    29,    61,    67,    62,    69,    60,
      68,    65,    64,    63,    66,    55,    59,     0,     0,     0,
      52,    49,    46,     0,    71,    73,     0,    45,    53,    43,
      50,    41,    47,    72,     0,    54,    51,    48,     0,     0,
       0,     0,     0,    70,     0,     0,     0
};

static const short yydefgoto[] =
{
     134,     6,     7,    15,    20,    21,    22,    23,    37,    38,
      24,    25,    52,    53,   112,   111,   110,   121,   119,   117,
      26,    27,    64,    65,   118,    75,    72,    79,    76
};

static const short yypact[] =
{
     115,   -20,    19,    27,    33,    39,   108,-32768,-32768,-32768,
  -32768,-32768,    40,    42,-32768,    22,-32768,    25,    43,     4,
       1,-32768,-32768,   -29,-32768,    71,-32768,   117,-32768,    50,
      52,    54,    58,-32768,    31,    61,    31,    57,-32768,    31,
      64,    31,    31,    31,    67,    31,    31,    31,    31,    31,
      31,    31,    21,-32768,    31,    72,    31,    31,    77,    31,
      31,    31,    31,    31,    94,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,    31,-32768,-32768,    31,-32768,-32768,-32768,
      31,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,-32768,-32768,-32768,-32768,    31,    31,    31,
      81,    31,    31,    31,-32768,-32768,    82,    81,-32768,    31,
  -32768,    31,-32768,-32768,    87,-32768,-32768,-32768,    89,    90,
      91,    92,    93,-32768,    97,    98,-32768
};

static const short yypgoto[] =
{
  -32768,-32768,    99,-32768,-32768,    79,-32768,-32768,-32768,    63,
  -32768,-32768,-32768,    55,-32768,-32768,-32768,-32768,-32768,-32768,
  -32768,-32768,-32768,    44,    -3,   -41,   -32,     2,   -34
};


#define	YYLAST		161


static const short yytable[] =
{
      73,    34,    35,    36,    86,    80,     8,    80,    83,    73,
      29,    84,    87,    88,    80,    90,    91,    92,   100,    32,
      80,    30,    80,    73,     9,    98,   101,   102,    80,   104,
      19,    39,    10,    40,    70,    71,    41,    11,    18,   107,
      93,    42,   108,    82,    12,    16,   109,    17,    28,    31,
      89,    43,    44,    45,    19,    66,    95,    67,    97,    68,
      46,    47,    48,    69,   103,    49,    74,    50,    51,    81,
     120,   122,    85,   113,   114,   115,    77,    96,   126,   123,
     127,    39,    99,    40,   116,   124,    41,    34,    35,    36,
     128,    42,   129,   130,   131,   132,   133,   135,   136,    33,
      78,    43,    44,    45,    54,    14,    55,    94,   106,    56,
      46,    47,    48,   105,   125,    49,     0,    50,    51,    13,
       0,     1,     0,     0,    57,    58,    59,    54,     1,    55,
       2,     0,    56,    60,    61,    62,     3,     2,    63,     0,
       0,     0,     0,     3,     4,     0,     5,    57,    58,    59,
       0,     4,     0,     5,     0,     0,    60,    61,    62,     0,
       0,    63
};

static const short yycheck[] =
{
      34,    30,    31,    32,    45,    39,    26,    41,    42,    43,
       6,    43,    46,    47,    48,    49,    50,    51,    59,    18,
      54,    17,    56,    57,     5,    57,    60,    61,    62,    63,
      29,    10,     5,    12,     3,     4,    15,     4,    16,    73,
      19,    20,    76,    41,     5,     5,    80,     5,     5,    45,
      48,    30,    31,    32,    29,     5,    54,     5,    56,     5,
      39,    40,    41,     5,    62,    44,     5,    46,    47,     5,
     111,   112,     5,   107,   108,   109,    19,     5,   119,   113,
     121,    10,     5,    12,     3,     3,    15,    30,    31,    32,
       3,    20,     3,     3,     3,     3,     3,     0,     0,    20,
      37,    30,    31,    32,    10,     6,    12,    52,    64,    15,
      39,    40,    41,    19,   117,    44,    -1,    46,    47,    11,
      -1,    13,    -1,    -1,    30,    31,    32,    10,    13,    12,
      22,    -1,    15,    39,    40,    41,    28,    22,    44,    -1,
      -1,    -1,    -1,    28,    36,    -1,    38,    30,    31,    32,
      -1,    36,    -1,    38,    -1,    -1,    39,    40,    41,    -1,
      -1,    44
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

case 5:
#line 160 "mdly.y"
{
		cur_Mdl->filedependancy = yyvsp[0].string;
	}
    break;
case 6:
#line 164 "mdly.y"
{
		cur_Mdl->newmodel = yyvsp[0].string;
	}
    break;
case 7:
#line 168 "mdly.y"
{
		cur_Mdl->supermodel1 = yyvsp[-1].string;
		cur_Mdl->supermodel2 = yyvsp[0].string;
	}
    break;
case 9:
#line 174 "mdly.y"
{
		cur_Mdl->animationscale = yyvsp[0].real;
	}
    break;
case 18:
#line 201 "mdly.y"
{
		// allocate cur_Node here
		cur_Node->type = dummy;
		cur_Node->name = yyvsp[0].string;
	}
    break;
case 22:
#line 216 "mdly.y"
{
		cur_Node->parent = yyvsp[0].string;
	}
    break;
case 23:
#line 220 "mdly.y"
{
		cur_Node->node.dummy->position = yyvsp[0].xyz;
	}
    break;
case 24:
#line 224 "mdly.y"
{
		cur_Node->node.dummy->orientation = yyvsp[0].xyzw;
	}
    break;
case 26:
#line 235 "mdly.y"
{
		cur_Node->type = trimesh;
		cur_Node->name = yyvsp[0].string;
	}
    break;
case 30:
#line 249 "mdly.y"
{
		cur_Node->parent = yyvsp[0].string;
	}
    break;
case 31:
#line 253 "mdly.y"
{
		cur_Node->node.trimesh->position = yyvsp[0].xyz;
	}
    break;
case 32:
#line 257 "mdly.y"
{
		cur_Node->node.trimesh->orientation = yyvsp[0].xyzw;
	}
    break;
case 33:
#line 261 "mdly.y"
{
		cur_Node->node.trimesh->ambient = yyvsp[0].rgb;
	}
    break;
case 34:
#line 265 "mdly.y"
{
		cur_Node->node.trimesh->diffuse = yyvsp[0].rgb;
	}
    break;
case 35:
#line 269 "mdly.y"
{
		cur_Node->node.trimesh->specular = yyvsp[0].rgb;
	}
    break;
case 36:
#line 273 "mdly.y"
{
		cur_Node->node.trimesh->shininess = yyvsp[0].real;
	}
    break;
case 37:
#line 277 "mdly.y"
{
		cur_Node->node.trimesh->shadow = yyvsp[0].real;
	}
    break;
case 38:
#line 281 "mdly.y"
{
		cur_Node->node.trimesh->transparencyhint = yyvsp[0].real;
	}
    break;
case 39:
#line 285 "mdly.y"
{
		strncpy(cur_Node->node.trimesh->bitmap, yyvsp[0].string, sizeof cur_Node->node.trimesh->bitmap);
	}
    break;
case 40:
#line 288 "mdly.y"
{ cur_Node->node.trimesh->verts = vnew(yyvsp[0].real); }
    break;
case 42:
#line 289 "mdly.y"
{ cur_Node->node.trimesh->tverts = vnew(yyvsp[0].real); }
    break;
case 44:
#line 290 "mdly.y"
{ cur_Node->node.trimesh->faces = vnew(yyvsp[0].real); }
    break;
case 47:
#line 296 "mdly.y"
{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = yyvsp[0].xyz;
		vapp(cur_Node->node.trimesh->verts, vp);
	}
    break;
case 48:
#line 302 "mdly.y"
{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = yyvsp[0].xyz;
		vapp(cur_Node->node.trimesh->verts, vp);
	}
    break;
case 50:
#line 312 "mdly.y"
{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = yyvsp[0].xyz;
		vapp(cur_Node->node.trimesh->tverts, vp);
	}
    break;
case 51:
#line 318 "mdly.y"
{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = yyvsp[0].xyz;
		vapp(cur_Node->node.trimesh->tverts, vp);
	}
    break;
case 53:
#line 328 "mdly.y"
{
		int* vp = malloc(sizeof yyvsp[0].face);
		memcpy(vp, yyvsp[0].face, sizeof yyvsp[0].face);
		vapp(cur_Node->node.trimesh->faces, vp);
	}
    break;
case 54:
#line 334 "mdly.y"
{
		int* vp = malloc(sizeof yyvsp[0].face);
		memcpy(vp, yyvsp[0].face, sizeof yyvsp[0].face);
		vapp(cur_Node->node.trimesh->faces, vp);
	}
    break;
case 56:
#line 347 "mdly.y"
{
		cur_Node->type = aabb;
		cur_Node->name = yyvsp[0].string;
	}
    break;
case 60:
#line 361 "mdly.y"
{
		cur_Node->parent = yyvsp[0].string;
	}
    break;
case 61:
#line 365 "mdly.y"
{
		cur_Node->node.aabb->ambient = yyvsp[0].rgb;
	}
    break;
case 62:
#line 369 "mdly.y"
{
		cur_Node->node.aabb->diffuse = yyvsp[0].rgb;
	}
    break;
case 63:
#line 373 "mdly.y"
{
		cur_Node->node.aabb->specular = yyvsp[0].rgb;
	}
    break;
case 64:
#line 377 "mdly.y"
{
		cur_Node->node.aabb->shininess = yyvsp[0].real;
	}
    break;
case 65:
#line 381 "mdly.y"
{
		cur_Node->node.aabb->shadow = yyvsp[0].real;
	}
    break;
case 66:
#line 385 "mdly.y"
{
		cur_Node->node.aabb->transparencyhint = yyvsp[0].real;
	}
    break;
case 67:
#line 389 "mdly.y"
{
		strncpy(cur_Node->node.aabb->bitmap, yyvsp[0].string, sizeof cur_Node->node.aabb->bitmap);
	}
    break;
case 68:
#line 393 "mdly.y"
{
		cur_Node->node.aabb->position = yyvsp[0].xyz;
	}
    break;
case 69:
#line 397 "mdly.y"
{
		cur_Node->node.aabb->orientation = yyvsp[0].xyzw;
	}
    break;
case 70:
#line 404 "mdly.y"
{
		yyval.face[0] = yyvsp[-7].integer; yyval.face[1] = yyvsp[-6].integer; yyval.face[2] = yyvsp[-5].integer; yyval.face[3] = yyvsp[-4].integer;
		yyval.face[4] = yyvsp[-3].integer; yyval.face[5] = yyvsp[-2].integer; yyval.face[6] = yyvsp[-1].integer; yyval.face[7] = yyvsp[0].integer;
	}
    break;
case 71:
#line 411 "mdly.y"
{
		yyval.xyz.x = yyvsp[-2].real; yyval.xyz.y = yyvsp[-1].real; yyval.xyz.z = yyvsp[0].real;
	}
    break;
case 72:
#line 418 "mdly.y"
{
		yyval.xyzw.x = yyvsp[-3].real; yyval.xyzw.y = yyvsp[-2].real; yyval.xyzw.z = yyvsp[-1].real; yyval.xyzw.w = yyvsp[0].real;
	}
    break;
case 73:
#line 425 "mdly.y"
{
		yyval.rgb.r = yyvsp[-2].real; yyval.rgb.g = yyvsp[-1].real; yyval.rgb.b = yyvsp[0].real;
	}
    break;
case 74:
#line 432 "mdly.y"
{
		yyval.real = yyvsp[0].integer;
	}
    break;
case 75:
#line 436 "mdly.y"
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
#line 441 "mdly.y"


void nwmdl_error(char* s)
{
	fprintf(stderr, "%s\n", s);
}

int nwmdl_wrap(void)
{
	return 1;
}
