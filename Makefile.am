VERSION = @VERSION@
SUBDIRS = src
man_MANS = man/jp2a.1
bashcompdir = @bashcompdir@
dist_bashcomp_DATA = completion/bash/jp2a
EXTRA_DIST = tests/??*.txt tests/??*.html tests/??*.jpg tests/run-tests.sh tests/Makefile include/??*.h man/jp2a.1 LICENSES

test: check

check: all
	$(MAKE) -C tests check
