%{
/*
Dumb MinGW won't work unless this is at the very beginning of the file.
*/
#include	<config.h>
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include	<memory.h>
# endif
# define        __NO_INLINE__
# include	<string.h>
#endif
%}

%option prefix="nwset_" outfile="lex.yy.c"

%%

%{

#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
#endif
#include	"rgb.h"
#include	"set.h"

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

#include	"sety.h"

%}

%{

	/* comments: ignored */

%}

^;[^\n\r]*[\r\n]+			;

%{

	/* line terminators: ignored */

%}

\n							;
\r							;

%{

	/* token delimiters, returned as tokens */

%}

=							return '=';

%{

	/*
	boring headers - annoyingly, NWN doesn't care which case the names are in!
	*/

%}

^\[[gG][eE][nN][eE][rR][aA][lL]]						return token_GeneralHead;
^\[[gG][rR][aA][sS][sS]]								return token_GrassHead;
^\[[tT][eE][rR][rR][aA][iI][nN]\ [tT][yY][pP][eE][sS]]	return token_TerrainTypesHead;
^\[[cC][rR][oO][sS][sS][eE][rR]\ [tT][yY][pP][eE][sS]]	return token_CrosserTypesHead;
^\[[pP][rR][iI][mM][aA][rR][yY]\ [rR][uU][lL][eE][sS]]	return token_PRulesHead;
^\[[sS][eE][cC][oO][nN][dD][aA][rR][yY]\ [rR][uU][lL][eE][sS]]	return token_SRulesHead;
^\[[tT][iI][lL][eE][sS]]								return token_TilesHead;
^\[[gG][rR][oO][uU][pP][sS]]							return token_GroupsHead;

%{

	/*
	headers with indicies embedded - these may need to be in either case as well
	*/

%}

\[TERRAIN[0-9]+]			{
								nwset_lval.integer = atoi(&nwset_text[8]);
								return token_TerrainHead;
							}

\[CROSSER[0-9]+]			{
								nwset_lval.integer = atoi(&nwset_text[8]);
								return token_CrosserHead;
							}

\[PRIMARY\ RULE[0-9]+]		{
								nwset_lval.integer = atoi(&nwset_text[13]);
								return token_PRuleHead;
							}

\[TILE[0-9]+]				{
								nwset_lval.integer = atoi(&nwset_text[5]);
								return token_TileHead;
							}

\[TILE[0-9]+DOOR[0-9]+]		{
								char* cp = 1 + strchr(&nwset_text[0], 'R');
								nwset_lval.integer = atoi(cp);
								return token_DoorHead;
							}

\[GROUP[0-9]+]				{
								nwset_lval.integer = atoi(&nwset_text[6]);
								return token_GroupHead;
							}

%{

	/* boring barewords */

%}

^Adjacent/=					return token_Adjacent;
^AdjacentHeight/=			return token_AdjacentHeight;
^AmbientBlue/=				return token_AmbientBlue;
^AmbientGreen/=				return token_AmbientGreen;
^AmbientRed/=				return token_AmbientRed;
^AnimLoop1/=				return token_AnimLoop1;
^AnimLoop2/=				return token_AnimLoop2;
^AnimLoop3/=				return token_AnimLoop3;
^Border/=					return token_Border;
^Bottom/=					return token_Bottom;
^BottomLeft/=				return token_BottomLeft;
^BottomLeftHeight/=			return token_BottomLeftHeight;
^BottomRight/=				return token_BottomRight;
^BottomRightHeight/=		return token_BottomRightHeight;
^Changed/=					return token_Changed;
^ChangedHeight/=			return token_ChangedHeight;
^Columns/=					return token_Columns;
^Count/=					return token_Count;
^Default/=					return token_Default;
^Density/=					return token_Density;
^DiffuseBlue/=				return token_DiffuseBlue;
^DiffuseGreen/=				return token_DiffuseGreen;
^DiffuseRed/=				return token_DiffuseRed;
^DisplayName/=				return token_DisplayName;
^Doors/=					return token_Doors;
^DoorVisibilityNode/=			return token_DoorVisibilityNode;
^DoorVisibilityOrientation/=	return token_DoorVisibilityOrientation;
^EnvMap/=					return token_EnvMap;
^Floor/=					return token_Floor;
^Grass/=					return token_Grass;
^HasHeightTransition/=		return token_HasHeightTransition;
^Height/=					return token_Height;
^ImageMap2D/=				return token_ImageMap2D;
^Interior/=					return token_Interior;
^Left/=						return token_Left;
^MainLight1/=				return token_MainLight1;
^MainLight2/=				return token_MainLight2;
^Model/=					return token_Model;
^Name/=						return token_Name;
^Orientation/=				return token_Orientation;
^PathNode/=					return token_PathNode;
^Placed/=					return token_Placed;
^PlacedHeight/=				return token_PlacedHeight;
^Right/=					return token_Right;
^Rows/=						return token_Rows;
^Sounds/=					return token_Sounds;
^SourceLight1/=				return token_SourceLight1;
^SourceLight2/=				return token_SourceLight2;
^StrRef/=					return token_StrRef;
^Top/=						return token_Top;
^TopLeft/=					return token_TopLeft;
^TopLeftHeight/=			return token_TopLeftHeight;
^TopRight/=					return token_TopRight;
^TopRightHeight/=			return token_TopRightHeight;
^Transition/=				return token_Transition;
^Type/=						return token_Type;
^UnlocalizedName/=			return token_UnlocalizedName;
^Version/=					return token_Version;
^VisibilityNode/=			return token_VisibilityNode;
^VisibilityOrientation/=	return token_VisibilityOrientation;
^WalkMesh/=					return token_WalkMesh;
^X/=						return token_X;
^Y/=						return token_Y;
^Z/=						return token_Z;

%{

	/* "complex" tokens */

%}

^Tile[0-9]+/=				{
								nwset_lval.integer = atoi(&nwset_text[4]);
								return token_TileRef;
							}

-{0,1}[0-9]+\.[0-9]+		{
								nwset_lval.real = atof(&nwset_text[0]);
								return token_real;
							}

-{0,1}[0-9]+				{
								nwset_lval.integer = atoi(&nwset_text[0]);
								return token_integer;
							}

[-\/.,a-zA-Z0-9_\ ]+			{
								nwset_lval.string = strdup(&nwset_text[0]);
								return token_string;
							}
