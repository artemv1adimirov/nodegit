// This is a generated file, modify: generate/templates/templates/class_header.h

#ifndef GITRESET_H
#define GITRESET_H
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

#include "../include/repository.h"
#include "../include/object.h"
#include "../include/checkout_options.h"
#include "../include/strarray.h"
#include "../include/annotated_commit.h"

using namespace node;
using namespace v8;


class GitReset : public
  Nan::ObjectWrap
{
   public:
    static void InitializeComponent (v8::Local<v8::Object> target);

                  

  private:
                  
    struct ResetBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_object * target;
      git_reset_t reset_type;
      git_checkout_options * checkout_opts;
    };
    class ResetWorker : public Nan::AsyncWorker {
      public:
        ResetWorker(
            ResetBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~ResetWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        ResetBaton *baton;
    };

    static NAN_METHOD(Reset);

    struct DefaultBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_object * target;
      git_strarray * pathspecs;
    };
    class DefaultWorker : public Nan::AsyncWorker {
      public:
        DefaultWorker(
            DefaultBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DefaultWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DefaultBaton *baton;
    };

    static NAN_METHOD(Default);

    struct FromAnnotatedBaton {
      int error_code;
      const git_error* error;
      git_repository * repo;
      git_annotated_commit * commit;
      git_reset_t reset_type;
      const git_checkout_options * checkout_opts;
    };
    class FromAnnotatedWorker : public Nan::AsyncWorker {
      public:
        FromAnnotatedWorker(
            FromAnnotatedBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FromAnnotatedWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FromAnnotatedBaton *baton;
    };

    static NAN_METHOD(FromAnnotated);
};

#endif
