#!/bin/sh

# Makefile requires this to exist
touch README

# generate libtool scripts
libtoolize --automake -c &&

	# generate m4 scripts
	aclocal &&

	# generate Makefile.in
	automake --gnu --include-deps -a -c &&

	# generate config.h.in
	autoheader &&

	# generate configure
	autoconf &&

	# generate Makefile
	./configure "$@" &&

	# generate the product
	make
