# This file is generated by gyp; do not edit.

export builddir_name ?= ./build/vendor/.
.PHONY: all
all:
	$(MAKE) -C .. zlib libssh2 libgit2
