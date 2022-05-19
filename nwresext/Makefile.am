bin_PROGRAMS = nwresext

nwresext_SOURCES = nwresext.c

man_MANS = nwresext.1

EXTRA_DIST = $(man_MANS) nwresext.1.in

LDADD = ../libnw/libnw.la

INCLUDES = -I$(top_srcdir)/include

AM_CFLAGS = -Wall
