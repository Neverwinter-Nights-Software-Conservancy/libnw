bin_PROGRAMS = nwareamap

nwareamap_SOURCES = main.c

man_MANS = nwareamap.1

EXTRA_DIST = $(man_MANS) nwareamap.1.in

LDADD = ../libnw/libnw.la

INCLUDES = -I$(top_srcdir)/include

AM_CFLAGS = -Wall
