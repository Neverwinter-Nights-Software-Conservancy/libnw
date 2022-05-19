lib_LTLIBRARIES = libnw.la

libnw_la_SOURCES = bif_toc.c dump.c key.c restyp.c str2arr.c version.c v.c \
	agg_toc.c agg_create.c sety.y setl.l nwnfopen.c strref.c gamedir.c \
	make_2da.c bendian.c global.c plist.c agg_load.c plist2are.c mdly.y \
	mdll.l plist2ifo.c plist2utd.c plist2ute.c plist2utp.c plist2utc.c \
	plist2dlg.c plist2gic.c plist2utt.c exmem.c

AM_YFLAGS = -d -t

AM_LFLAGS = -d -s

INCLUDES = -I$(top_srcdir)/include

man_MANS = agg_toc_load.3 agg_toc_del.3 agg_create.3 bif_toc_load.3 \
	get_game_dir.3 read_key.3

EXTRA_DIST = $(man_MANS) sety.h mdly.h agg_toc_load.3.in agg_toc_del.3.in \
	agg_create.3.in bif_toc_load.3.in get_game_dir.3.in read_key.3.in

AM_CFLAGS = -Wall
