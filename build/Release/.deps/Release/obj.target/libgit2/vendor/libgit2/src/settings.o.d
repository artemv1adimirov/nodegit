cmd_Release/obj.target/libgit2/vendor/libgit2/src/settings.o := cc '-DNODE_GYP_MODULE_NAME=libgit2' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DGIT_THREADS' '-DGIT_SSH' '-DGIT_SSH_MEMORY_CREDENTIALS' '-DSRC_UTIL_H_' '-DGIT_SECURE_TRANSPORT' '-DGIT_USE_STAT_MTIMESPEC' '-DGIT_CURL' '-DGIT_SHA1_OPENSSL' '-DHTTP_PARSER_STRICT=0' -I/Users/artemvladimirov/.node-gyp/8.2.1/include/node -I/Users/artemvladimirov/.node-gyp/8.2.1/src -I/Users/artemvladimirov/.node-gyp/8.2.1/deps/uv/include -I/Users/artemvladimirov/.node-gyp/8.2.1/deps/v8/include -I../vendor/libgit2/include -I../vendor/libgit2/src -I../vendor/libgit2/deps/zlib -I../vendor/http_parser -I../vendor/openssl/openssl/include -I../vendor/libssh2/include  -Os -gdwarf-2 -mmacosx-version-min=10.7 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Wno-missing-field-initializers -Wno-unused-variable -Wno-deprecated-declarations -Wno-uninitialized -fno-strict-aliasing -MMD -MF ./Release/.deps/Release/obj.target/libgit2/vendor/libgit2/src/settings.o.d.raw   -c -o Release/obj.target/libgit2/vendor/libgit2/src/settings.o ../vendor/libgit2/src/settings.c
Release/obj.target/libgit2/vendor/libgit2/src/settings.o: \
  ../vendor/libgit2/src/settings.c ../vendor/libgit2/include/git2.h \
  ../vendor/libgit2/include/git2/annotated_commit.h \
  ../vendor/libgit2/include/git2/common.h \
  ../vendor/libgit2/include/git2/repository.h \
  ../vendor/libgit2/include/git2/types.h \
  ../vendor/libgit2/include/git2/oid.h \
  ../vendor/libgit2/include/git2/buffer.h \
  ../vendor/libgit2/include/git2/attr.h \
  ../vendor/libgit2/include/git2/blob.h \
  ../vendor/libgit2/include/git2/object.h \
  ../vendor/libgit2/include/git2/blame.h \
  ../vendor/libgit2/include/git2/branch.h \
  ../vendor/libgit2/include/git2/checkout.h \
  ../vendor/libgit2/include/git2/diff.h \
  ../vendor/libgit2/include/git2/tree.h \
  ../vendor/libgit2/include/git2/refs.h \
  ../vendor/libgit2/include/git2/strarray.h \
  ../vendor/libgit2/include/git2/cherrypick.h \
  ../vendor/libgit2/include/git2/merge.h \
  ../vendor/libgit2/include/git2/oidarray.h \
  ../vendor/libgit2/include/git2/index.h \
  ../vendor/libgit2/include/git2/indexer.h \
  ../vendor/libgit2/include/git2/clone.h \
  ../vendor/libgit2/include/git2/remote.h \
  ../vendor/libgit2/include/git2/refspec.h \
  ../vendor/libgit2/include/git2/net.h \
  ../vendor/libgit2/include/git2/transport.h \
  ../vendor/libgit2/include/git2/pack.h \
  ../vendor/libgit2/include/git2/proxy.h \
  ../vendor/libgit2/include/git2/commit.h \
  ../vendor/libgit2/include/git2/config.h \
  ../vendor/libgit2/include/git2/describe.h \
  ../vendor/libgit2/include/git2/errors.h \
  ../vendor/libgit2/include/git2/filter.h \
  ../vendor/libgit2/include/git2/global.h \
  ../vendor/libgit2/include/git2/graph.h \
  ../vendor/libgit2/include/git2/ignore.h \
  ../vendor/libgit2/include/git2/message.h \
  ../vendor/libgit2/include/git2/notes.h \
  ../vendor/libgit2/include/git2/odb.h \
  ../vendor/libgit2/include/git2/odb_backend.h \
  ../vendor/libgit2/include/git2/patch.h \
  ../vendor/libgit2/include/git2/pathspec.h \
  ../vendor/libgit2/include/git2/rebase.h \
  ../vendor/libgit2/include/git2/refdb.h \
  ../vendor/libgit2/include/git2/reflog.h \
  ../vendor/libgit2/include/git2/reset.h \
  ../vendor/libgit2/include/git2/revert.h \
  ../vendor/libgit2/include/git2/revparse.h \
  ../vendor/libgit2/include/git2/revwalk.h \
  ../vendor/libgit2/include/git2/signature.h \
  ../vendor/libgit2/include/git2/stash.h \
  ../vendor/libgit2/include/git2/status.h \
  ../vendor/libgit2/include/git2/submodule.h \
  ../vendor/libgit2/include/git2/tag.h \
  ../vendor/libgit2/include/git2/transaction.h \
  ../vendor/libgit2/include/git2/version.h \
  ../vendor/libgit2/src/common.h ../vendor/libgit2/src/cc-compat.h \
  ../vendor/libgit2/src/thread-utils.h \
  ../vendor/libgit2/src/unix/pthread.h ../vendor/libgit2/src/integer.h \
  ../vendor/libgit2/src/util.h ../vendor/libgit2/src/buffer.h \
  ../vendor/libgit2/src/strnlen.h ../vendor/libgit2/src/sysdir.h \
  ../vendor/libgit2/src/posix.h ../vendor/libgit2/src/fnmatch.h \
  ../vendor/libgit2/src/unix/posix.h ../vendor/libgit2/src/cache.h \
  ../vendor/libgit2/src/oidmap.h ../vendor/libgit2/src/khash.h \
  ../vendor/libgit2/src/global.h ../vendor/libgit2/src/mwindow.h \
  ../vendor/libgit2/src/map.h ../vendor/libgit2/src/vector.h \
  ../vendor/libgit2/src/hash.h ../vendor/libgit2/src/hash/hash_openssl.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/sha.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/e_os2.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/opensslconf.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/./archs/darwin64-x86_64-cc/opensslconf.h \
  ../vendor/libgit2/src/object.h ../vendor/libgit2/src/repository.h \
  ../vendor/libgit2/src/array.h ../vendor/libgit2/src/refs.h \
  ../vendor/libgit2/src/strmap.h ../vendor/libgit2/src/oid.h \
  ../vendor/libgit2/src/attrcache.h ../vendor/libgit2/src/attr_file.h \
  ../vendor/libgit2/src/pool.h ../vendor/libgit2/src/fileops.h \
  ../vendor/libgit2/src/path.h ../vendor/libgit2/src/submodule.h \
  ../vendor/libgit2/src/diff_driver.h ../vendor/libgit2/src/odb.h \
  ../vendor/libgit2/src/filter.h \
  ../vendor/libgit2/src/transports/smart.h \
  ../vendor/libgit2/src/netops.h ../vendor/libgit2/src/stream.h \
  ../vendor/libgit2/include/git2/sys/stream.h \
  ../vendor/libgit2/src/push.h ../vendor/libgit2/src/refspec.h \
  ../vendor/libgit2/include/git2/sys/transport.h
../vendor/libgit2/src/settings.c:
../vendor/libgit2/include/git2.h:
../vendor/libgit2/include/git2/annotated_commit.h:
../vendor/libgit2/include/git2/common.h:
../vendor/libgit2/include/git2/repository.h:
../vendor/libgit2/include/git2/types.h:
../vendor/libgit2/include/git2/oid.h:
../vendor/libgit2/include/git2/buffer.h:
../vendor/libgit2/include/git2/attr.h:
../vendor/libgit2/include/git2/blob.h:
../vendor/libgit2/include/git2/object.h:
../vendor/libgit2/include/git2/blame.h:
../vendor/libgit2/include/git2/branch.h:
../vendor/libgit2/include/git2/checkout.h:
../vendor/libgit2/include/git2/diff.h:
../vendor/libgit2/include/git2/tree.h:
../vendor/libgit2/include/git2/refs.h:
../vendor/libgit2/include/git2/strarray.h:
../vendor/libgit2/include/git2/cherrypick.h:
../vendor/libgit2/include/git2/merge.h:
../vendor/libgit2/include/git2/oidarray.h:
../vendor/libgit2/include/git2/index.h:
../vendor/libgit2/include/git2/indexer.h:
../vendor/libgit2/include/git2/clone.h:
../vendor/libgit2/include/git2/remote.h:
../vendor/libgit2/include/git2/refspec.h:
../vendor/libgit2/include/git2/net.h:
../vendor/libgit2/include/git2/transport.h:
../vendor/libgit2/include/git2/pack.h:
../vendor/libgit2/include/git2/proxy.h:
../vendor/libgit2/include/git2/commit.h:
../vendor/libgit2/include/git2/config.h:
../vendor/libgit2/include/git2/describe.h:
../vendor/libgit2/include/git2/errors.h:
../vendor/libgit2/include/git2/filter.h:
../vendor/libgit2/include/git2/global.h:
../vendor/libgit2/include/git2/graph.h:
../vendor/libgit2/include/git2/ignore.h:
../vendor/libgit2/include/git2/message.h:
../vendor/libgit2/include/git2/notes.h:
../vendor/libgit2/include/git2/odb.h:
../vendor/libgit2/include/git2/odb_backend.h:
../vendor/libgit2/include/git2/patch.h:
../vendor/libgit2/include/git2/pathspec.h:
../vendor/libgit2/include/git2/rebase.h:
../vendor/libgit2/include/git2/refdb.h:
../vendor/libgit2/include/git2/reflog.h:
../vendor/libgit2/include/git2/reset.h:
../vendor/libgit2/include/git2/revert.h:
../vendor/libgit2/include/git2/revparse.h:
../vendor/libgit2/include/git2/revwalk.h:
../vendor/libgit2/include/git2/signature.h:
../vendor/libgit2/include/git2/stash.h:
../vendor/libgit2/include/git2/status.h:
../vendor/libgit2/include/git2/submodule.h:
../vendor/libgit2/include/git2/tag.h:
../vendor/libgit2/include/git2/transaction.h:
../vendor/libgit2/include/git2/version.h:
../vendor/libgit2/src/common.h:
../vendor/libgit2/src/cc-compat.h:
../vendor/libgit2/src/thread-utils.h:
../vendor/libgit2/src/unix/pthread.h:
../vendor/libgit2/src/integer.h:
../vendor/libgit2/src/util.h:
../vendor/libgit2/src/buffer.h:
../vendor/libgit2/src/strnlen.h:
../vendor/libgit2/src/sysdir.h:
../vendor/libgit2/src/posix.h:
../vendor/libgit2/src/fnmatch.h:
../vendor/libgit2/src/unix/posix.h:
../vendor/libgit2/src/cache.h:
../vendor/libgit2/src/oidmap.h:
../vendor/libgit2/src/khash.h:
../vendor/libgit2/src/global.h:
../vendor/libgit2/src/mwindow.h:
../vendor/libgit2/src/map.h:
../vendor/libgit2/src/vector.h:
../vendor/libgit2/src/hash.h:
../vendor/libgit2/src/hash/hash_openssl.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/sha.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/e_os2.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/opensslconf.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/./archs/darwin64-x86_64-cc/opensslconf.h:
../vendor/libgit2/src/object.h:
../vendor/libgit2/src/repository.h:
../vendor/libgit2/src/array.h:
../vendor/libgit2/src/refs.h:
../vendor/libgit2/src/strmap.h:
../vendor/libgit2/src/oid.h:
../vendor/libgit2/src/attrcache.h:
../vendor/libgit2/src/attr_file.h:
../vendor/libgit2/src/pool.h:
../vendor/libgit2/src/fileops.h:
../vendor/libgit2/src/path.h:
../vendor/libgit2/src/submodule.h:
../vendor/libgit2/src/diff_driver.h:
../vendor/libgit2/src/odb.h:
../vendor/libgit2/src/filter.h:
../vendor/libgit2/src/transports/smart.h:
../vendor/libgit2/src/netops.h:
../vendor/libgit2/src/stream.h:
../vendor/libgit2/include/git2/sys/stream.h:
../vendor/libgit2/src/push.h:
../vendor/libgit2/src/refspec.h:
../vendor/libgit2/include/git2/sys/transport.h:
