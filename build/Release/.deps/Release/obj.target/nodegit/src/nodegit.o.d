cmd_Release/obj.target/nodegit/src/nodegit.o := c++ '-DNODE_GYP_MODULE_NAME=nodegit' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/Users/artemvladimirov/.node-gyp/8.2.1/include/node -I/Users/artemvladimirov/.node-gyp/8.2.1/src -I/Users/artemvladimirov/.node-gyp/8.2.1/deps/uv/include -I/Users/artemvladimirov/.node-gyp/8.2.1/deps/v8/include -I../vendor/libv8-convert -I../vendor/libssh2/include -I../vendor/openssl/openssl/include -I../node_modules/nan -I../vendor/libgit2/include  -Os -gdwarf-2 -mmacosx-version-min=10.7 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -Wno-unused-variable -Wint-conversions -Wmissing-field-initializers -Wno-c++11-extensions -std=gnu++0x -stdlib=libc++ -fno-rtti -fno-threadsafe-statics -fno-strict-aliasing -MMD -MF ./Release/.deps/Release/obj.target/nodegit/src/nodegit.o.d.raw   -c -o Release/obj.target/nodegit/src/nodegit.o ../src/nodegit.cc
Release/obj.target/nodegit/src/nodegit.o: ../src/nodegit.cc \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/node.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/v8.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/v8-version.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/v8config.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/node_version.h \
  ../vendor/libgit2/include/git2.h \
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
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/crypto.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/e_os2.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/opensslconf.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/./archs/darwin64-x86_64-cc/opensslconf.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/stack.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/safestack.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/opensslv.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/ossl_typ.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/symhacks.h \
  ../src/../include/init_ssh2.h ../src/../include/lock_master.h \
  ../src/../include/nodegit.h ../src/../include/thread_pool.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-errno.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-version.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-unix.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-threadpool.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-darwin.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/pthread-barrier.h \
  ../src/../include/wrapper.h ../node_modules/nan/nan.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/node_buffer.h \
  /Users/artemvladimirov/.node-gyp/8.2.1/include/node/node_object_wrap.h \
  ../node_modules/nan/nan_callbacks.h \
  ../node_modules/nan/nan_callbacks_12_inl.h \
  ../node_modules/nan/nan_maybe_43_inl.h \
  ../node_modules/nan/nan_converters.h \
  ../node_modules/nan/nan_converters_43_inl.h \
  ../node_modules/nan/nan_new.h \
  ../node_modules/nan/nan_implementation_12_inl.h \
  ../node_modules/nan/nan_persistent_12_inl.h \
  ../node_modules/nan/nan_weak.h ../node_modules/nan/nan_object_wrap.h \
  ../node_modules/nan/nan_private.h \
  ../node_modules/nan/nan_typedarray_contents.h \
  ../node_modules/nan/nan_json.h ../src/../include/promise_completion.h \
  ../src/../include/async_baton.h ../src/../include/functions/copy.h \
  ../src/../include/annotated_commit.h \
  ../src/../include/nodegit_wrapper.h \
  ../src/../include/../include/typedefs.h \
  ../src/../include/../include/repository.h \
  ../vendor/libgit2/include/git2/sys/repository.h \
  ../src/../include/../include/config.h \
  ../src/../include/../include/git_buf_converter.h \
  ../src/../include/../include/buf.h \
  ../src/../include/../include/transaction.h \
  ../src/../include/../include/oid.h \
  ../src/../include/../include/reference.h \
  ../src/../include/../include/strarray.h \
  ../src/../include/../include/str_array_converter.h \
  ../src/../include/../include/object.h \
  ../src/../include/../include/index.h \
  ../src/../include/../include/index_entry.h \
  ../src/../include/callback_wrapper.h \
  ../src/../include/../include/index_time.h \
  ../src/../include/../include/tree.h \
  ../src/../include/../include/tree_update.h \
  ../src/../include/../include/tree_entry.h \
  ../src/../include/../include/repository_init_options.h \
  ../src/../include/../include/odb.h \
  ../src/../include/../include/odb_expand_id.h \
  ../src/../include/../include/odb_object.h \
  ../src/../include/../include/refdb.h \
  ../src/../include/../include/annotated_commit.h \
  ../src/../include/attr.h ../src/../include/blame.h \
  ../src/../include/../include/blame_options.h \
  ../src/../include/../include/blame_hunk.h \
  ../src/../include/../include/signature.h \
  ../src/../include/../include/time.h \
  ../vendor/libgit2/include/git2/sys/time.h ../src/../include/blob.h \
  ../src/../include/../include/writestream.h ../src/../include/branch.h \
  ../src/../include/../include/commit.h \
  ../src/../include/../include/branch_iterator.h \
  ../src/../include/cert.h ../src/../include/cert_hostkey.h \
  ../src/../include/cert_x509.h ../src/../include/checkout.h \
  ../src/../include/../include/checkout_options.h \
  ../src/../include/../include/diff_file.h \
  ../src/../include/cherrypick.h \
  ../src/../include/../include/cherrypick_options.h \
  ../src/../include/../include/merge_options.h ../src/../include/clone.h \
  ../src/../include/../include/clone_options.h \
  ../src/../include/../include/fetch_options.h \
  ../src/../include/../include/remote_callbacks.h \
  ../src/../include/../include/cred.h \
  ../src/../include/../include/transfer_progress.h \
  ../src/../include/../include/proxy_options.h \
  ../src/../include/config_entry.h ../src/../include/cred_default.h \
  ../src/../include/cred_username.h \
  ../src/../include/cred_userpass_payload.h \
  ../vendor/libgit2/include/git2/cred_helpers.h \
  ../src/../include/cvar_map.h \
  ../src/../include/describe_format_options.h \
  ../src/../include/describe_options.h \
  ../src/../include/describe_result.h ../src/../include/diff.h \
  ../vendor/libgit2/include/git2/sys/diff.h \
  ../src/../include/../include/diff_options.h \
  ../src/../include/../include/diff.h \
  ../src/../include/../include/diff_delta.h \
  ../src/../include/../include/diff_binary.h \
  ../src/../include/../include/diff_binary_file.h \
  ../src/../include/../include/diff_hunk.h \
  ../src/../include/../include/diff_line.h \
  ../src/../include/../include/diff_find_options.h \
  ../src/../include/../include/diff_perfdata.h \
  ../src/../include/diff_stats.h ../src/../include/error.h \
  ../src/../include/fetch.h ../src/../include/filter.h \
  ../vendor/libgit2/include/git2/sys/filter.h \
  ../src/../include/../include/filter_source.h \
  ../src/../include/filter_list.h ../src/../include/giterr.h \
  ../src/../include/graph.h ../src/../include/hashsig.h \
  ../vendor/libgit2/include/git2/sys/hashsig.h \
  ../src/../include/ignore.h ../src/../include/index_conflict_iterator.h \
  ../src/../include/indexer.h ../src/../include/libgit2.h \
  ../src/../include/mempack.h ../src/../include/merge.h \
  ../src/../include/../include/oidarray.h \
  ../src/../include/../include/merge_file_input.h \
  ../src/../include/merge_driver_source.h \
  ../src/../include/merge_file_options.h \
  ../src/../include/merge_file_result.h ../src/../include/merge_result.h \
  ../src/../include/message.h ../src/../include/note.h \
  ../src/../include/../include/note_iterator.h \
  ../src/../include/oid_shorten.h ../src/../include/openssl.h \
  ../vendor/libgit2/include/git2/sys/openssl.h \
  ../src/../include/packbuilder.h ../src/../include/../include/revwalk.h \
  ../src/../include/../include/functions/copy.h \
  ../src/../include/patch.h \
  ../src/../include/../include/convenient_patch.h \
  ../src/../include/../include/convenient_hunk.h \
  ../src/../include/pathspec.h \
  ../src/../include/../include/pathspec_match_list.h \
  ../src/../include/proxy.h ../src/../include/push.h \
  ../src/../include/../include/push_options.h \
  ../src/../include/push_update.h ../src/../include/rebase.h \
  ../src/../include/../include/rebase_options.h \
  ../src/../include/../include/rebase_operation.h \
  ../src/../include/reflog.h ../src/../include/../include/reflog_entry.h \
  ../src/../include/refspec.h ../src/../include/remote.h \
  ../src/../include/../include/remote_head.h \
  ../src/../include/../include/functions/free.h \
  ../src/../include/reset.h ../src/../include/revert.h \
  ../src/../include/../include/revert_options.h \
  ../src/../include/revparse.h ../src/../include/smart.h \
  ../src/../include/stash.h \
  ../src/../include/../include/stash_apply_options.h \
  ../src/../include/status.h ../src/../include/../include/status_list.h \
  ../src/../include/../include/status_options.h \
  ../src/../include/../include/status_entry.h \
  ../src/../include/submodule.h \
  ../src/../include/../include/submodule_update_options.h \
  ../src/../include/tag.h ../src/../include/trace.h \
  ../src/../include/transport.h \
  ../vendor/libgit2/include/git2/sys/transport.h \
  ../src/../include/treebuilder.h ../src/../include/filter_registry.h
../src/nodegit.cc:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/node.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/v8.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/v8-version.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/v8config.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/node_version.h:
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
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/crypto.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/e_os2.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/opensslconf.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/./archs/darwin64-x86_64-cc/opensslconf.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/stack.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/safestack.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/opensslv.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/ossl_typ.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/openssl/symhacks.h:
../src/../include/init_ssh2.h:
../src/../include/lock_master.h:
../src/../include/nodegit.h:
../src/../include/thread_pool.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-errno.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-version.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-unix.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-threadpool.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/uv-darwin.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/pthread-barrier.h:
../src/../include/wrapper.h:
../node_modules/nan/nan.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/node_buffer.h:
/Users/artemvladimirov/.node-gyp/8.2.1/include/node/node_object_wrap.h:
../node_modules/nan/nan_callbacks.h:
../node_modules/nan/nan_callbacks_12_inl.h:
../node_modules/nan/nan_maybe_43_inl.h:
../node_modules/nan/nan_converters.h:
../node_modules/nan/nan_converters_43_inl.h:
../node_modules/nan/nan_new.h:
../node_modules/nan/nan_implementation_12_inl.h:
../node_modules/nan/nan_persistent_12_inl.h:
../node_modules/nan/nan_weak.h:
../node_modules/nan/nan_object_wrap.h:
../node_modules/nan/nan_private.h:
../node_modules/nan/nan_typedarray_contents.h:
../node_modules/nan/nan_json.h:
../src/../include/promise_completion.h:
../src/../include/async_baton.h:
../src/../include/functions/copy.h:
../src/../include/annotated_commit.h:
../src/../include/nodegit_wrapper.h:
../src/../include/../include/typedefs.h:
../src/../include/../include/repository.h:
../vendor/libgit2/include/git2/sys/repository.h:
../src/../include/../include/config.h:
../src/../include/../include/git_buf_converter.h:
../src/../include/../include/buf.h:
../src/../include/../include/transaction.h:
../src/../include/../include/oid.h:
../src/../include/../include/reference.h:
../src/../include/../include/strarray.h:
../src/../include/../include/str_array_converter.h:
../src/../include/../include/object.h:
../src/../include/../include/index.h:
../src/../include/../include/index_entry.h:
../src/../include/callback_wrapper.h:
../src/../include/../include/index_time.h:
../src/../include/../include/tree.h:
../src/../include/../include/tree_update.h:
../src/../include/../include/tree_entry.h:
../src/../include/../include/repository_init_options.h:
../src/../include/../include/odb.h:
../src/../include/../include/odb_expand_id.h:
../src/../include/../include/odb_object.h:
../src/../include/../include/refdb.h:
../src/../include/../include/annotated_commit.h:
../src/../include/attr.h:
../src/../include/blame.h:
../src/../include/../include/blame_options.h:
../src/../include/../include/blame_hunk.h:
../src/../include/../include/signature.h:
../src/../include/../include/time.h:
../vendor/libgit2/include/git2/sys/time.h:
../src/../include/blob.h:
../src/../include/../include/writestream.h:
../src/../include/branch.h:
../src/../include/../include/commit.h:
../src/../include/../include/branch_iterator.h:
../src/../include/cert.h:
../src/../include/cert_hostkey.h:
../src/../include/cert_x509.h:
../src/../include/checkout.h:
../src/../include/../include/checkout_options.h:
../src/../include/../include/diff_file.h:
../src/../include/cherrypick.h:
../src/../include/../include/cherrypick_options.h:
../src/../include/../include/merge_options.h:
../src/../include/clone.h:
../src/../include/../include/clone_options.h:
../src/../include/../include/fetch_options.h:
../src/../include/../include/remote_callbacks.h:
../src/../include/../include/cred.h:
../src/../include/../include/transfer_progress.h:
../src/../include/../include/proxy_options.h:
../src/../include/config_entry.h:
../src/../include/cred_default.h:
../src/../include/cred_username.h:
../src/../include/cred_userpass_payload.h:
../vendor/libgit2/include/git2/cred_helpers.h:
../src/../include/cvar_map.h:
../src/../include/describe_format_options.h:
../src/../include/describe_options.h:
../src/../include/describe_result.h:
../src/../include/diff.h:
../vendor/libgit2/include/git2/sys/diff.h:
../src/../include/../include/diff_options.h:
../src/../include/../include/diff.h:
../src/../include/../include/diff_delta.h:
../src/../include/../include/diff_binary.h:
../src/../include/../include/diff_binary_file.h:
../src/../include/../include/diff_hunk.h:
../src/../include/../include/diff_line.h:
../src/../include/../include/diff_find_options.h:
../src/../include/../include/diff_perfdata.h:
../src/../include/diff_stats.h:
../src/../include/error.h:
../src/../include/fetch.h:
../src/../include/filter.h:
../vendor/libgit2/include/git2/sys/filter.h:
../src/../include/../include/filter_source.h:
../src/../include/filter_list.h:
../src/../include/giterr.h:
../src/../include/graph.h:
../src/../include/hashsig.h:
../vendor/libgit2/include/git2/sys/hashsig.h:
../src/../include/ignore.h:
../src/../include/index_conflict_iterator.h:
../src/../include/indexer.h:
../src/../include/libgit2.h:
../src/../include/mempack.h:
../src/../include/merge.h:
../src/../include/../include/oidarray.h:
../src/../include/../include/merge_file_input.h:
../src/../include/merge_driver_source.h:
../src/../include/merge_file_options.h:
../src/../include/merge_file_result.h:
../src/../include/merge_result.h:
../src/../include/message.h:
../src/../include/note.h:
../src/../include/../include/note_iterator.h:
../src/../include/oid_shorten.h:
../src/../include/openssl.h:
../vendor/libgit2/include/git2/sys/openssl.h:
../src/../include/packbuilder.h:
../src/../include/../include/revwalk.h:
../src/../include/../include/functions/copy.h:
../src/../include/patch.h:
../src/../include/../include/convenient_patch.h:
../src/../include/../include/convenient_hunk.h:
../src/../include/pathspec.h:
../src/../include/../include/pathspec_match_list.h:
../src/../include/proxy.h:
../src/../include/push.h:
../src/../include/../include/push_options.h:
../src/../include/push_update.h:
../src/../include/rebase.h:
../src/../include/../include/rebase_options.h:
../src/../include/../include/rebase_operation.h:
../src/../include/reflog.h:
../src/../include/../include/reflog_entry.h:
../src/../include/refspec.h:
../src/../include/remote.h:
../src/../include/../include/remote_head.h:
../src/../include/../include/functions/free.h:
../src/../include/reset.h:
../src/../include/revert.h:
../src/../include/../include/revert_options.h:
../src/../include/revparse.h:
../src/../include/smart.h:
../src/../include/stash.h:
../src/../include/../include/stash_apply_options.h:
../src/../include/status.h:
../src/../include/../include/status_list.h:
../src/../include/../include/status_options.h:
../src/../include/../include/status_entry.h:
../src/../include/submodule.h:
../src/../include/../include/submodule_update_options.h:
../src/../include/tag.h:
../src/../include/trace.h:
../src/../include/transport.h:
../vendor/libgit2/include/git2/sys/transport.h:
../src/../include/treebuilder.h:
../src/../include/filter_registry.h:
