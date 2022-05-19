bin_PROGRAMS = itpdis

itpdis_SOURCES = main.c

man_MANS = itpdis.1

EXTRA_DIST = $(man_MANS) itpdis.1.in

LDADD = ../libnw/libnw.la

INCLUDES = -I$(top_srcdir)/include

AM_CFLAGS = -Wall
