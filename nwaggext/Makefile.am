bin_PROGRAMS = nwaggext

nwaggext_SOURCES = nwaggext.c agg1ext.c

man_MANS = nwaggext.1

EXTRA_DIST = $(man_MANS) nwaggext.1.in

LDADD = ../libnw/libnw.la

INCLUDES = -I$(top_srcdir)/include

AM_CFLAGS = -Wall
