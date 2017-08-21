# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := libgit2
DEFS_Debug := \
	'-DNODE_GYP_MODULE_NAME=libgit2' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_DARWIN_USE_64_BIT_INODE=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DGIT_THREADS' \
	'-DGIT_SSH' \
	'-DGIT_SSH_MEMORY_CREDENTIALS' \
	'-DSRC_UTIL_H_' \
	'-DGIT_SECURE_TRANSPORT' \
	'-DGIT_USE_STAT_MTIMESPEC' \
	'-DGIT_CURL' \
	'-DGIT_SHA1_OPENSSL' \
	'-DHTTP_PARSER_STRICT=0' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-O0 \
	-gdwarf-2 \
	-mmacosx-version-min=10.7 \
	-arch x86_64 \
	-Wall \
	-Wendif-labels \
	-W \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-Wno-unused-variable \
	-Wno-deprecated-declarations \
	-Wno-uninitialized

# Flags passed to only C files.
CFLAGS_C_Debug := \
	-fno-strict-aliasing

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-std=gnu++0x \
	-stdlib=libc++ \
	-fno-rtti \
	-fno-exceptions \
	-fno-threadsafe-statics \
	-fno-strict-aliasing

# Flags passed to only ObjC files.
CFLAGS_OBJC_Debug :=

# Flags passed to only ObjC++ files.
CFLAGS_OBJCC_Debug :=

INCS_Debug := \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/include/node \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/src \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/deps/uv/include \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/deps/v8/include \
	-I$(srcdir)/vendor/libgit2/include \
	-I$(srcdir)/vendor/libgit2/src \
	-I$(srcdir)/vendor/libgit2/deps/zlib \
	-I$(srcdir)/vendor/http_parser \
	-I$(srcdir)/vendor/openssl/openssl/include \
	-I$(srcdir)/vendor/libssh2/include

DEFS_Release := \
	'-DNODE_GYP_MODULE_NAME=libgit2' \
	'-DUSING_UV_SHARED=1' \
	'-DUSING_V8_SHARED=1' \
	'-DV8_DEPRECATION_WARNINGS=1' \
	'-D_DARWIN_USE_64_BIT_INODE=1' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DGIT_THREADS' \
	'-DGIT_SSH' \
	'-DGIT_SSH_MEMORY_CREDENTIALS' \
	'-DSRC_UTIL_H_' \
	'-DGIT_SECURE_TRANSPORT' \
	'-DGIT_USE_STAT_MTIMESPEC' \
	'-DGIT_CURL' \
	'-DGIT_SHA1_OPENSSL' \
	'-DHTTP_PARSER_STRICT=0'

# Flags passed to all source files.
CFLAGS_Release := \
	-Os \
	-gdwarf-2 \
	-mmacosx-version-min=10.7 \
	-arch x86_64 \
	-Wall \
	-Wendif-labels \
	-W \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-Wno-unused-variable \
	-Wno-deprecated-declarations \
	-Wno-uninitialized

# Flags passed to only C files.
CFLAGS_C_Release := \
	-fno-strict-aliasing

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-std=gnu++0x \
	-stdlib=libc++ \
	-fno-rtti \
	-fno-exceptions \
	-fno-threadsafe-statics \
	-fno-strict-aliasing

# Flags passed to only ObjC files.
CFLAGS_OBJC_Release :=

# Flags passed to only ObjC++ files.
CFLAGS_OBJCC_Release :=

INCS_Release := \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/include/node \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/src \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/deps/uv/include \
	-I/Users/artemvladimirov/.node-gyp/8.2.1/deps/v8/include \
	-I$(srcdir)/vendor/libgit2/include \
	-I$(srcdir)/vendor/libgit2/src \
	-I$(srcdir)/vendor/libgit2/deps/zlib \
	-I$(srcdir)/vendor/http_parser \
	-I$(srcdir)/vendor/openssl/openssl/include \
	-I$(srcdir)/vendor/libssh2/include

OBJS := \
	$(obj).target/$(TARGET)/vendor/libgit2/src/annotated_commit.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/apply.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/attr_file.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/attr.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/attrcache.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/blame_git.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/blame.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/blob.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/branch.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/buf_text.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/buffer.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/cache.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/checkout.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/cherrypick.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/clone.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/commit_list.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/commit.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/config_cache.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/config_file.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/config.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/crlf.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/curl_stream.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/date.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/delta.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_driver.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_file.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_generate.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_parse.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_print.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_stats.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_tform.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff_xdiff.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/diff.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/errors.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/fetch.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/fetchhead.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/filebuf.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/fileops.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/filter.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/fnmatch.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/global.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/graph.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/hash.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/hash/sha1dc/sha1.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/hash/sha1dc/ubc_check.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/hashsig.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/ident.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/idxmap.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/ignore.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/index.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/indexer.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/iterator.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/merge_driver.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/merge_file.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/merge.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/message.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/mwindow.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/netops.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/notes.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/object_api.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/object.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/odb_loose.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/odb_mempack.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/odb_pack.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/odb.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/offmap.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/oid.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/oidarray.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/oidmap.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/openssl_stream.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/pack-objects.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/pack.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/patch_generate.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/patch_parse.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/patch.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/path.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/pathspec.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/pool.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/posix.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/pqueue.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/proxy.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/push.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/rebase.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/refdb_fs.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/refdb.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/reflog.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/refs.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/refspec.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/remote.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/repository.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/reset.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/revert.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/revparse.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/revwalk.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/settings.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/sha1_lookup.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/signature.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/socket_stream.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/sortedcache.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/stash.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/status.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/strmap.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/submodule.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/sysdir.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/tag.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/thread-utils.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/trace.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transaction.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transport.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/auth.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/cred_helpers.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/cred.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/git.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/http.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/local.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/smart_pkt.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/smart_protocol.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/smart.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/transports/ssh.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/tree-cache.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/tree.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/tsort.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/util.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/varint.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/vector.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/worktree.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/xdiff/xdiffi.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/xdiff/xemit.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/xdiff/xhistogram.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/xdiff/xmerge.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/xdiff/xpatience.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/xdiff/xprepare.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/xdiff/xutils.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/zstream.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/stransport_stream.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/tls_stream.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/unix/map.o \
	$(obj).target/$(TARGET)/vendor/libgit2/src/unix/realpath.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))
$(OBJS): GYP_OBJCFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE)) $(CFLAGS_OBJC_$(BUILDTYPE))
$(OBJS): GYP_OBJCXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE)) $(CFLAGS_OBJCC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.c FORCE_DO_CMD
	@$(call do_cmd,cc,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-mmacosx-version-min=10.7 \
	-arch x86_64 \
	-L$(builddir) \
	-stdlib=libc++

LIBTOOLFLAGS_Debug :=

LDFLAGS_Release := \
	-mmacosx-version-min=10.7 \
	-arch x86_64 \
	-L$(builddir) \
	-stdlib=libc++

LIBTOOLFLAGS_Release :=

LIBS := \
	-lpthread

$(builddir)/git2.a: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(builddir)/git2.a: LIBS := $(LIBS)
$(builddir)/git2.a: GYP_LIBTOOLFLAGS := $(LIBTOOLFLAGS_$(BUILDTYPE))
$(builddir)/git2.a: TOOLSET := $(TOOLSET)
$(builddir)/git2.a: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,alink)

all_deps += $(builddir)/git2.a
# Add target alias
.PHONY: libgit2
libgit2: $(builddir)/git2.a

# Add target alias to "all" target.
.PHONY: all
all: libgit2

# Add target alias
.PHONY: libgit2
libgit2: $(builddir)/git2.a

# Short alias for building this static library.
.PHONY: git2.a
git2.a: $(builddir)/git2.a

# Add static library to "all" target.
.PHONY: all
all: $(builddir)/git2.a
