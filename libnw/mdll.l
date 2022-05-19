%{
/*
Dumb MinGW won't work unless this is at the very beginning of the file.
*/
#include        <config.h>
#if HAVE_STRING_H
# if !STDC_HEADERS && HAVE_MEMORY_H
#  include      <memory.h>
# endif
# define        __NO_INLINE__
# include       <string.h>
#endif
%}

%option prefix="nwmdl_" outfile="lex.yy.c"

%%

%{

#include	<stdio.h>
#if STDC_HEADERS || HAVE_STDLIB_H
#include	<stdlib.h>
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

#include	"mdly.h"

%}

%{

	/* comments: ignored */

%}

^[ \t]*#[^\n\r]*[\r\n]+			;

%{

	/* line terminators: ignored */

%}

\n							;
\r							;

%{

	/* boring barewords */

%}

aabb				return token_aabb;
affectdynamic		return token_affectdynamic;
alpha				return token_alpha;
ambientonly			return token_ambientonly;
ambient				return token_ambient;
beginmodelgeom		return token_beginmodelgeom;
bitmap				return token_bitmap;
classification		return token_classification;
color				return token_color;
diffuse				return token_diffuse;
donemodel			return token_donemodel;
dummy				return token_dummy;
endmodelgeom		return token_endmodelgeom;
endnode				return token_endnode;
faces				return token_faces;
fadingLight			return token_fadingLight;
filedependancy		return token_filedependancy;
flareradius			return token_flareradius;
isdynamic			return token_isdynamic;
lightpriority		return token_lightpriority;
model				return token_model;
multiplier			return token_multiplier;
newmodel			return token_newmodel;
node				return token_node;
orientation			return token_orientation;
parent				return token_parent;
position			return token_position;
radius				return token_radius;
rotatetexture		return token_rotatetexture;
scale				return token_scale;
setanimationscale	return token_setanimationscale;
setfillumcolor		return token_setfillumcolor;
setsupermodel		return token_setsupermodel;
shadow				return token_shadow;
shininess			return token_shininess;
specular			return token_specular;
tilefade			return token_tilefade;
tile				return token_tile;
transparencyhint	return token_transparencyhint;
trimesh				return token_trimesh;
tverts				return token_tverts;
verts				return token_verts;

%{

	/* "complex" tokens */

%}

-{0,1}[0-9]+\.[0-9]+		{
								nwmdl_lval.real = atof(&nwmdl_text[0]);
								return token_real;
							}

-{0,1}[0-9]+				{
								nwmdl_lval.integer = atoi(&nwmdl_text[0]);
								return token_integer;
							}

[-\/.,a-zA-Z0-9_\ ]+			{
								nwmdl_lval.string = strdup(&nwmdl_text[0]);
								return token_string;
							}
