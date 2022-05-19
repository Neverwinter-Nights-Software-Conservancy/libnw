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

%}

%union {
	int integer;
	double real;
	char* string;
	struct xyz xyz;
	struct xyzw xyzw;
	struct rgb rgb;
	int face[8];
};

/* fundamental value types */
%token <integer> token_integer
%token <real> token_real
%token <string> token_string

/* specific "words" ("keywords") */
%token token_aabb
%token token_affectdynamic
%token token_alpha
%token token_ambientonly
%token token_ambient
%token token_beginmodelgeom
%token token_bitmap
%token token_classification
%token token_color
%token token_diffuse
%token token_donemodel
%token token_dummy
%token token_endmodelgeom
%token token_endnode
%token token_faces
%token token_fadingLight
%token token_filedependancy
%token token_flareradius
%token token_isdynamic
%token token_lightpriority
%token token_model
%token token_multiplier
%token token_newmodel
%token token_node
%token token_orientation
%token token_parent
%token token_position
%token token_radius
%token token_rotatetexture
%token token_scale
%token token_setanimationscale
%token token_setfillumcolor
%token token_setsupermodel
%token token_shadow
%token token_shininess
%token token_specular
%token token_tilefade
%token token_tile
%token token_transparencyhint
%token token_trimesh
%token token_tverts
%token token_verts

%type <real> numeric

%type <xyz> xyz
%type <xyzw> xyzw
%type <rgb> rgb
%type <face> face

%%

mdlfile
	: mdlhead_stmts model token_donemodel token_string
	;
	
mdlhead_stmts
	: /* empty */
	| mdlhead_stmt
	| mdlhead_stmts mdlhead_stmt
	;

mdlhead_stmt
	: token_filedependancy token_string =
	{
		cur_Mdl->filedependancy = $2;
	}
	| token_newmodel token_string =
	{
		cur_Mdl->newmodel = $2;
	}
	| token_setsupermodel token_string token_string =
	{
		cur_Mdl->supermodel1 = $2;
		cur_Mdl->supermodel2 = $3;
	}
	| token_classification token_model
	| token_setanimationscale token_real =
	{
		cur_Mdl->animationscale = $2;
	}
	;

model
	: token_beginmodelgeom token_string mdlnodes token_endmodelgeom token_string
	;

mdlnodes
	: /* empty */
	| mdlnode
	| mdlnodes mdlnode
	;

mdlnode
	: dummynode
	| trimeshnode
	| aabbnode
	;

dummynode
	: dummynodestart dummynodecontents token_endnode
	;

dummynodestart
	: token_node token_dummy token_string =
	{
		// allocate cur_Node here
		cur_Node->type = dummy;
		cur_Node->name = $3;
	}
	;

dummynodecontents
	: /* empty */
	| dummynodeelement
	| dummynodecontents dummynodeelement
	;

dummynodeelement
	: token_parent token_string =
	{
		cur_Node->parent = $2;
	}
	| token_position xyz =
	{
		cur_Node->node.dummy->position = $2;
	}
	| token_orientation xyzw =
	{
		cur_Node->node.dummy->orientation = $2;
	}
	;

trimeshnode
	: trimeshnodestart trimeshnodecontents token_endnode
	;

trimeshnodestart
	: token_node token_trimesh token_string =
	{
		cur_Node->type = trimesh;
		cur_Node->name = $3;
	}
	;

trimeshnodecontents
	: /* empty */
	| trimeshnodeelement
	| trimeshnodecontents trimeshnodeelement
	;

trimeshnodeelement
	: token_parent token_string =
	{
		cur_Node->parent = $2;
	}
	| token_position xyz =
	{
		cur_Node->node.trimesh->position = $2;
	}
	| token_orientation xyzw =
	{
		cur_Node->node.trimesh->orientation = $2;
	}
	| token_ambient rgb =
	{
		cur_Node->node.trimesh->ambient = $2;
	}
	| token_diffuse rgb =
	{
		cur_Node->node.trimesh->diffuse = $2;
	}
	| token_specular rgb =
	{
		cur_Node->node.trimesh->specular = $2;
	}
	| token_shininess numeric =
	{
		cur_Node->node.trimesh->shininess = $2;
	}
	| token_shadow numeric =
	{
		cur_Node->node.trimesh->shadow = $2;
	}
	| token_transparencyhint numeric =
	{
		cur_Node->node.trimesh->transparencyhint = $2;
	}
	| token_bitmap token_string =
	{
		strncpy(cur_Node->node.trimesh->bitmap, $2, sizeof cur_Node->node.trimesh->bitmap);
	}
	| token_verts numeric { cur_Node->node.trimesh->verts = vnew($2); } trimeshverts
	| token_tverts numeric { cur_Node->node.trimesh->tverts = vnew($2); } trimeshtverts
	| token_faces numeric { cur_Node->node.trimesh->faces = vnew($2); } trimeshfaces
	;

trimeshverts
	: /* empty */
	| xyz =
	{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = $1;
		vapp(cur_Node->node.trimesh->verts, vp);
	}
	| trimeshverts xyz =
	{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = $2;
		vapp(cur_Node->node.trimesh->verts, vp);
	}
	;

trimeshtverts
	: /* empty */
	| xyz =
	{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = $1;
		vapp(cur_Node->node.trimesh->tverts, vp);
	}
	| trimeshtverts xyz =
	{
		struct xyz* vp = malloc(sizeof *vp);
		*vp = $2;
		vapp(cur_Node->node.trimesh->tverts, vp);
	}
	;

trimeshfaces
	: /* empty */
	| face =
	{
		int* vp = malloc(sizeof $1);
		memcpy(vp, $1, sizeof $1);
		vapp(cur_Node->node.trimesh->faces, vp);
	}
	| trimeshfaces face =
	{
		int* vp = malloc(sizeof $2);
		memcpy(vp, $2, sizeof $2);
		vapp(cur_Node->node.trimesh->faces, vp);
	}
	;

aabbnode
	: aabbnodestart aabbnodecontents token_endnode
	;

aabbnodestart
	: token_node token_aabb token_string =
	{
		cur_Node->type = aabb;
		cur_Node->name = $3;
	}
	;

aabbnodecontents
	: /* empty */
	| aabbnodeelement
	| aabbnodecontents aabbnodeelement
	;

aabbnodeelement
	: token_parent token_string =
	{
		cur_Node->parent = $2;
	}
	| token_ambient rgb =
	{
		cur_Node->node.aabb->ambient = $2;
	}
	| token_diffuse rgb =
	{
		cur_Node->node.aabb->diffuse = $2;
	}
	| token_specular rgb =
	{
		cur_Node->node.aabb->specular = $2;
	}
	| token_shininess numeric =
	{
		cur_Node->node.aabb->shininess = $2;
	}
	| token_shadow numeric =
	{
		cur_Node->node.aabb->shadow = $2;
	}
	| token_transparencyhint numeric =
	{
		cur_Node->node.aabb->transparencyhint = $2;
	}
	| token_bitmap token_string =
	{
		strncpy(cur_Node->node.aabb->bitmap, $2, sizeof cur_Node->node.aabb->bitmap);
	}
	| token_position xyz =
	{
		cur_Node->node.aabb->position = $2;
	}
	| token_orientation xyzw =
	{
		cur_Node->node.aabb->orientation = $2;
	}
	;

face
	: token_integer token_integer token_integer token_integer token_integer token_integer token_integer token_integer =
	{
		$$[0] = $1; $$[1] = $2; $$[2] = $3; $$[3] = $4;
		$$[4] = $5; $$[5] = $6; $$[6] = $7; $$[7] = $8;
	}
	;
xyz
	: numeric numeric numeric =
	{
		$$.x = $1; $$.y = $2; $$.z = $3;
	}
	;

xyzw
	: numeric numeric numeric numeric =
	{
		$$.x = $1; $$.y = $2; $$.z = $3; $$.w = $4;
	}
	;

rgb
	: numeric numeric numeric =
	{
		$$.r = $1; $$.g = $2; $$.b = $3;
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

void nwmdl_error(char* s)
{
	fprintf(stderr, "%s\n", s);
}

int nwmdl_wrap(void)
{
	return 1;
}
