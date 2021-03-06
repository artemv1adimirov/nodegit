// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITCONFIG_H
#define GITCONFIG_H
#include <nan.h>
#include <string>
#include <queue>
#include <utility>

#include "async_baton.h"
#include "nodegit_wrapper.h"
#include "promise_completion.h"

extern "C" {
#include <git2.h>
}

#include "../include/typedefs.h"

#include "../include/git_buf_converter.h"
#include "../include/buf.h"
#include "../include/transaction.h"
// Forward declaration.
struct git_config {
};

using namespace node;
using namespace v8;

class GitConfig;

struct GitConfigTraits {
  typedef GitConfig cppClass;
  typedef git_config cType;

  static const bool isDuplicable = false;
  static void duplicate(git_config **dest, git_config *src) {
     Nan::ThrowError("duplicate called on GitConfig which cannot be duplicated");
   }

  static const bool isFreeable = true;
  static void free(git_config *raw) {
    ::git_config_free(raw); // :: to avoid calling this free recursively
   }
};

class GitConfig : public
  NodeGitWrapper<GitConfigTraits>
{
    // grant full access to base class
    friend class NodeGitWrapper<GitConfigTraits>;
   public:
    static void InitializeComponent (v8::Local<v8::Object> target);

                                    

  private:
    GitConfig()
      : NodeGitWrapper<GitConfigTraits>(
           "A new GitConfig cannot be instantiated."
       )
    {}
    GitConfig(git_config *raw, bool selfFreeing, v8::Local<v8::Object> owner = v8::Local<v8::Object>())
      : NodeGitWrapper<GitConfigTraits>(raw, selfFreeing, owner)
    {}
    ~GitConfig();
                                    
    struct FindProgramdataBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
    };
    class FindProgramdataWorker : public Nan::AsyncWorker {
      public:
        FindProgramdataWorker(
            FindProgramdataBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FindProgramdataWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FindProgramdataBaton *baton;
    };

    static NAN_METHOD(FindProgramdata);

    struct GetStringBufBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_config * cfg;
      const char * name;
    };
    class GetStringBufWorker : public Nan::AsyncWorker {
      public:
        GetStringBufWorker(
            GetStringBufBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GetStringBufWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GetStringBufBaton *baton;
    };

    static NAN_METHOD(GetStringBuf);

    static NAN_METHOD(Lock);

    struct OpenDefaultBaton {
      int error_code;
      const git_error* error;
      git_config * out;
    };
    class OpenDefaultWorker : public Nan::AsyncWorker {
      public:
        OpenDefaultWorker(
            OpenDefaultBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OpenDefaultWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OpenDefaultBaton *baton;
    };

    static NAN_METHOD(OpenDefault);

    static NAN_METHOD(SetInt64);

    static NAN_METHOD(SetMultivar);

    struct SetStringBaton {
      int error_code;
      const git_error* error;
      git_config * cfg;
      const char * name;
      const char * value;
    };
    class SetStringWorker : public Nan::AsyncWorker {
      public:
        SetStringWorker(
            SetStringBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SetStringWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SetStringBaton *baton;
    };

    static NAN_METHOD(SetString);

    struct SnapshotBaton {
      int error_code;
      const git_error* error;
      git_config * out;
      git_config * config;
    };
    class SnapshotWorker : public Nan::AsyncWorker {
      public:
        SnapshotWorker(
            SnapshotBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SnapshotWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SnapshotBaton *baton;
    };

    static NAN_METHOD(Snapshot);
};

#endif
