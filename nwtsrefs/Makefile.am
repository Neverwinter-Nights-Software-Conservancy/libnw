bin_PROGRAMS = nwtsrefs

nwtsrefs_SOURCES = main.c xref.c

man_MANS = nwtsrefs.1

LDADD = ../libnw/libnw.la

INCLUDES = -I$(top_srcdir)/include

EXTRA_DIST = $(man_MANS) nwtsrefs.1.in

AM_CFLAGS = -Wall
