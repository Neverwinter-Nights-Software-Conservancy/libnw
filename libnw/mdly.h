#ifndef BISON_Y_TAB_H
# define BISON_Y_TAB_H

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


extern YYSTYPE yylval;

#endif /* not BISON_Y_TAB_H */
