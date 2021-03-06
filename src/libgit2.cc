// This is a generated file, modify: generate/templates/templates/class_content.cc

#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/nodegit.h"
#include "../include/lock_master.h"
#include "../include/functions/copy.h"
#include "../include/libgit2.h"
#include "nodegit_wrapper.cc"
#include "../include/async_libgit2_queue_worker.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitLibgit2::InitializeComponent(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;

    v8::Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "features", Features);
         Nan::SetMethod(object, "init", Init);
         Nan::SetMethod(object, "opts", Opts);
         Nan::SetMethod(object, "shutdown", Shutdown);
         Nan::SetMethod(object, "version", Version);
  
    Nan::Set(target, Nan::New<String>("Libgit2").ToLocalChecked(), object);
  }

  
/*
   * @return Number  result    */
NAN_METHOD(GitLibgit2::Features) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

    int result = git_libgit2_features(
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @return Number  result    */
NAN_METHOD(GitLibgit2::Init) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

    int result = git_libgit2_init(
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param Number option
     * @return Number  result    */
NAN_METHOD(GitLibgit2::Opts) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number option is required.");
  }

// start convert_from_v8 block
  int from_option;
  from_option = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

    int result = git_libgit2_opts(
  from_option
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
   * @return Number  result    */
NAN_METHOD(GitLibgit2::Shutdown) {
  Nan::EscapableHandleScope scope;

 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false);

    int result = git_libgit2_shutdown(
    );

 
    v8::Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
    return info.GetReturnValue().Set(scope.Escape(to));
  }
}
   
/*
 * @param Number major
   * @param Number minor
   * @param Number rev
     */
NAN_METHOD(GitLibgit2::Version) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number major is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number minor is required.");
  }

  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number rev is required.");
  }

// start convert_from_v8 block
  int * from_major = NULL;
  *from_major = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  int * from_minor = NULL;
  *from_minor = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  int * from_rev = NULL;
  *from_rev = (int)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
 
  giterr_clear();

  {
    LockMaster lockMaster(/*asyncAction: */false        ,    from_major
        ,    from_minor
        ,    from_rev
);

git_libgit2_version(
  from_major
,  from_minor
,  from_rev
    );

     return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }
}
     