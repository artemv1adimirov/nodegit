// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITBRANCH_H
#define GITBRANCH_H
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

#include "../include/buf.h"
#include "../include/reference.h"
#include "../include/repository.h"
#include "../include/commit.h"
#include "../include/annotated_commit.h"
#include "../include/branch_iterator.h"
#include "../include/buf.h"

using namespace node;
using namespace v8;


class GitBranch : public
  Nan::ObjectWrap
{
   public:
    static void InitializeComponent (v8::Local<v8::Object> target);

                                                       

  private:
                                                       
    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * branch_name;
      const git_commit * target;
      int force;
    };
    class CreateWorker : public Nan::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateBaton *baton;
    };

    static NAN_METHOD(Create);

    struct CreateFromAnnotatedBaton {
      int error_code;
      const git_error* error;
      git_reference * ref_out;
      git_repository * repository;
      const char * branch_name;
      const git_annotated_commit * commit;
      int force;
    };
    class CreateFromAnnotatedWorker : public Nan::AsyncWorker {
      public:
        CreateFromAnnotatedWorker(
            CreateFromAnnotatedBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateFromAnnotatedWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateFromAnnotatedBaton *baton;
    };

    static NAN_METHOD(CreateFromAnnotated);

    static NAN_METHOD(Delete);

    static NAN_METHOD(IsHead);

    struct IteratorNewBaton {
      int error_code;
      const git_error* error;
      git_branch_iterator * out;
      git_repository * repo;
      git_branch_t list_flags;
    };
    class IteratorNewWorker : public Nan::AsyncWorker {
      public:
        IteratorNewWorker(
            IteratorNewBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~IteratorNewWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        IteratorNewBaton *baton;
    };

    static NAN_METHOD(IteratorNew);

    struct LookupBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_repository * repo;
      const char * branch_name;
      git_branch_t branch_type;
    };
    class LookupWorker : public Nan::AsyncWorker {
      public:
        LookupWorker(
            LookupBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~LookupWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        LookupBaton *baton;
    };

    static NAN_METHOD(Lookup);

    struct MoveBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      git_reference * branch;
      const char * new_branch_name;
      int force;
    };
    class MoveWorker : public Nan::AsyncWorker {
      public:
        MoveWorker(
            MoveBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~MoveWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        MoveBaton *baton;
    };

    static NAN_METHOD(Move);

    struct NameBaton {
      int error_code;
      const git_error* error;
      const char * out;
      const git_reference * ref;
    };
    class NameWorker : public Nan::AsyncWorker {
      public:
        NameWorker(
            NameBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~NameWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        NameBaton *baton;
    };

    static NAN_METHOD(Name);

    struct SetUpstreamBaton {
      int error_code;
      const git_error* error;
      git_reference * branch;
      const char * upstream_name;
    };
    class SetUpstreamWorker : public Nan::AsyncWorker {
      public:
        SetUpstreamWorker(
            SetUpstreamBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SetUpstreamWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SetUpstreamBaton *baton;
    };

    static NAN_METHOD(SetUpstream);

    struct RemoteNameBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      git_repository * repo;
      const char * canonical_branch_name;
    };
    class RemoteNameWorker : public Nan::AsyncWorker {
      public:
        RemoteNameWorker(
            RemoteNameBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~RemoteNameWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        RemoteNameBaton *baton;
    };

    static NAN_METHOD(RemoteName);

    struct UpstreamBaton {
      int error_code;
      const git_error* error;
      git_reference * out;
      const git_reference * branch;
    };
    class UpstreamWorker : public Nan::AsyncWorker {
      public:
        UpstreamWorker(
            UpstreamBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~UpstreamWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        UpstreamBaton *baton;
    };

    static NAN_METHOD(Upstream);
};

#endif
