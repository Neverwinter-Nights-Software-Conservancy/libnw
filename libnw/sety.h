#ifndef BISON_Y_TAB_H
# define BISON_Y_TAB_H

#ifndef YYSTYPE
typedef union {
	int integer;
	double real;
	char* string;
} yystype;
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif
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


extern YYSTYPE yylval;

#endif /* not BISON_Y_TAB_H */
